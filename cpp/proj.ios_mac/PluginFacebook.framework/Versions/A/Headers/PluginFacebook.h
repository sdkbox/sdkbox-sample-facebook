/****************************************************************************

 Copyright (c) 2014-2016 SDKBOX Inc

 ****************************************************************************/
#ifndef _PLUGIN_FACKBOOK_H_
#define _PLUGIN_FACKBOOK_H_

#include <vector>
#include <map>
#include <string>

namespace sdkbox
{
    class Json;

    const std::string FB_PERM_READ_PUBLIC_PROFILE("public_profile");
    const std::string FB_PERM_READ_EMAIL("email");
    const std::string FB_PERM_READ_USER_FRIENDS("user_friends");
    const std::string FB_PERM_PUBLISH_POST("publish_actions");
    const std::string FB_API_ME_FRIENDS_TAG("__fb_me_friends__");
    const std::string FB_API_ME_FRIENDS_PATH("me/friends");


    const std::string kRI_ExcludeFromList("ExcludeFromListIds");
    const std::string kRI_PictureSize("PictureSize");
    const std::string kRI_PaginationLimit("PaginationLimit");
    const std::string kRI_ResponseFields("ResponseFields");


    enum FBShareType
    {
        FB_NONE  = 0,
        FB_LINK  = 1,
        FB_PHOTO = 2
    };
    
    static const int FBSDKLoginBehaviorNative = 0;
    static const int FBSDKLoginBehaviorBrowser = 1;
    static const int FBSDKLoginBehaviorSystemAccount = 2;

    typedef std::map<std::string, std::string> FBAPIParam;

    struct FBShareInfo
    {
        FBShareInfo()
        : type(FB_NONE), link(""), title("")
        , text(""), image("")
        {}

        FBShareType type;
        std::string link;
        std::string title;
        std::string text;
        std::string image;
    };

    class FBGraphUser
    {

    public:

        // konstants for Graph User
        static const std::string kGU_USERID;
        static const std::string kGU_NAME;
        static const std::string kGU_FIRST_NAME;
        static const std::string kGU_LAST_NAME;
        static const std::string kGU_EMAIL;
        static const std::string kGU_PICTURE_URL;
        static const std::string kGU_PICTURE_IS_SILHOUETTE;
        static const std::string kGU_SCORE;
        static const std::string kGU_INSTALLED;

        static const std::string kGU_STR_TRUE;
        static const std::string kGU_STR_FALSE;

        FBGraphUser();
        explicit FBGraphUser( const sdkbox::Json& json );
        explicit FBGraphUser( const std::string& json );

        // FB user id
        // @deprecated use getUserId()
        std::string uid;

        // FB user name ( normally firstName + lastName )
        // @deprecated use getUserName()
        std::string name;

        // User first name
        // @deprecated use getFirstName()
        std::string firstName;

        // User last name
        // @deprecated use getLastName()
        std::string lastName;

        // @deprecated use isAppInstalled()
        bool        isInstalled;

        std::string getUserId() const;
        std::string getName() const;
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getEmail() const;
        std::string getPictureURL() const;
        bool        isAppInstalled() const;
        bool        isPictureSilhouette() const;
        bool        asBoolean( const std::string& ) const;

        const std::string getField( const std::string& field ) const;
        void setField( const std::string& field, const std::string& value );

        /**
         * the bool value will be converted to 'true' (kGU_STR_TRUE) or 'false' (kGU_STR_FALSE)
         */
        void setField( const std::string& field, bool value );

        Json toJSON() const;
        std::string toJSONString() const;

        std::map<std::string, std::string> getFields() const;

    private:

        std::map<std::string, std::string>  _fields;

        void __initFromJSON( const Json& json );

    };

    struct FBInvitableUsersCursor {
        std::string next_url;
        std::string prev_url;
        std::string next_cursor;
        std::string prev_cursor;

        FBInvitableUsersCursor( const sdkbox::Json& json );
        FBInvitableUsersCursor( );
    };


    /**
     * FBInvitableFriendsInfo is returned as a result of a call to the FB plugin's method:
     * <code>requestInvitableFriends</code>.
     *
     * The idea is that with this information you can build a custom invitation dialog for your
     * FB contacts. Next to the name, there's an invitation token (FBGraphUser).
     * After the user makes the selection of people to invite, a call to the method
     * <code>inviteFriendsWithInviteIds</code> with an array of the desired invitation tokens
     * will invoke a FB dialog with invitation which will eventually send the invitations.
     *
     */
    class FBInvitableFriendsInfo {

    private:
        std::vector<FBGraphUser>    _invitableUsersInfo;
        FBInvitableUsersCursor      _cursorInfo;

        // the originally returned string for the FB graph call.
        std::string                 _originalJSONString;

    public:
        FBInvitableFriendsInfo( const std::string& json );
        FBInvitableFriendsInfo* init();

        typedef std::vector<FBGraphUser>::iterator iterator;
        typedef std::vector<FBGraphUser>::const_iterator const_iterator;

        size_t getNumInvitationTokens() const {
            return _invitableUsersInfo.size();
        }

        iterator begin() { return _invitableUsersInfo.begin(); }
        const_iterator begin() const { return _invitableUsersInfo.begin(); }
        iterator end() { return _invitableUsersInfo.end(); }
        const_iterator end() const { return _invitableUsersInfo.end(); }

        const std::string& getOriginalString() const {
            return _originalJSONString;
        }

        /**
         * Request this url to get the next invitable friends document info.
         * Maybe empty.
         */
        const std::string& getNextURL() const {
            return _cursorInfo.next_url;
        }

        /**
         * Request this url to get the prev invitable friends document info.
         * Maybe empty;
         */
        const std::string& getPrevURL() const {
            return _cursorInfo.prev_url;
        }

        /**
         * Use this string to build the NextURL.
         */
        const std::string& getNextCursor() const {
            return _cursorInfo.next_cursor;
        }

        /**
         * Use this string to build the PrevURL.
         */
        const std::string& getPrevCursor() const {
            return _cursorInfo.prev_cursor;
        }
    };

    class FacebookListener
    {
    public:
        virtual void onLogin(bool isLogin, const std::string& msg) = 0;
        virtual void onSharedSuccess(const std::string& message) = 0;
        virtual void onSharedFailed(const std::string& message) = 0;
        virtual void onSharedCancel() = 0;
        virtual void onAPI(const std::string& key, const std::string& jsonData) = 0;
        virtual void onPermission(bool isLogin, const std::string& msg) = 0;
        virtual void onFetchFriends(bool ok, const std::string& msg) = 0;
        virtual void onRequestInvitableFriends( const FBInvitableFriendsInfo& friends ) = 0;
        virtual void onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg )= 0;
        virtual void onInviteFriendsResult( bool result, const std::string& msg )= 0;

        virtual void onGetUserInfo( const FBGraphUser& userInfo ) = 0;
        virtual void onRequestGiftResult(bool result, const std::string& msg) {}
        virtual void onSendGiftResult(bool result, const std::string& msg) {}
    };

    class PluginFacebook
    {

    public:

        /*!
         * initialize the plugin instance.
         */
        static void init();

        /**
         * Set listener to listen for facebook events
         */
        static void setListener(FacebookListener* listener);

        /**
         * Get the listener
         */
        static FacebookListener* getListener();

        /**
         * Remove the listener, and can't listen to events anymore
         */
        static void removeListener();

        /**
         * @brief login
         *
         */
        static void setLoginBehavior(int loginBehavior);

        /**
         * @brief log in
         *
         * This method calls login with a single permission: sdkbox::FB_PERM_READ_PUBLIC_PROFILE
         */
        static void login();

        static void login( std::vector<std::string>& permissions );

        /**
         * @brief log in with specific read permissions, conflict with publish permissions
         * https://developers.facebook.com/docs/facebook-login/permissions
         *
         * @param read permissions
         */
        static void requestReadPermissions(const std::vector<std::string>& permissions);

        /**
         * @brief log in with specific public permissions
         * https://developers.facebook.com/docs/facebook-login/permissions
         *
         * @param publish permissions
         */
        static void requestPublishPermissions(const std::vector<std::string>& permissions);

        /**
         * @brief log out
         */
        static void logout();

        /**
         * @brief Check whether the user logined or not
         */
        static bool isLoggedIn();

        /**
         * @brief get UserID
         */
        static std::string getUserID();

        /**
         * @brief get AccessToken
         */
        static std::string getAccessToken();

        /**
         * @brief get permissoin list
         */
        static std::vector<std::string> getPermissionList();

        /**
         * @brief share
         *
         * @param info share information
         */
        static void share(const FBShareInfo& info);

        /**
         * @brief open a dialog of Facebook app or WebDialog (dialog with photo only avaible with native Facebook app)
         *
         * @param info share information
         */
        static void dialog(const FBShareInfo& info);

        /**
         * @brief return the version of Facebook SDK
         */
        static std::string getSDKVersion();

        /**
         * @brief use Facebook Open Graph api
         * https://developers.facebook.com/docs/ios/graph
         *
         * @param path path of Open Graph api
         * @param method HttpMethod ["GET","POST","DELETE"]
         * @param params request parameters
         * @param cb callback of request
         */
        static void api(const std::string& path, const std::string& method, const FBAPIParam& params, const std::string& tag);

        /**
         * @brief fetch friends data from Facebook
         *
         * This data only reflects your friends that are using the app.
         * The number of friends defaults to 25.
         */
        static void fetchFriends();

        /**
         * @brief get friends info
         */
        static std::vector<FBGraphUser> getFriends();

        /**
         * @brief check whether can present Facebook App
         */
        static bool canPresentWithFBApp(const FBShareInfo& info);

        /**
         * Get a vector of invitable friends info which can be used to build a custom friends invite dialog.
         *
         * The default set will be limited to 25 friends.
         * The order in which FB sorts the friends, and which ones returns vary between calls.
         * The returned invitation tokens are not supposed to be long-term stored and may vary between
         * calls for the same friends.
         *
         * The application must have a canvas configuration for this API call to work.
         *
         */
        static void requestInvitableFriends( const FBAPIParam& );

        /**
         * Invite friends based on the result obtained from a call to <code>requestInvitableFriends</code>
         */
        static void inviteFriendsWithInviteIds( const std::vector<std::string>& invite_ids, const std::string& title, const std::string& invite_text );

        /**
         * Use the default FB dialog to invite friends.
         */
        static void inviteFriends( const std::string& app_link_url, const std::string& preview_image_url );

        /**
         * Set the Facebook App ID to be used by the FB SDK.
         */
        static void setAppId(const std::string& appId);

        /**
         * Set the app url scheme suffix used by the FB SDK.
         */
        static void setAppURLSchemeSuffix(const std::string& appURLSchemeSuffix);

        /**
         * Ask friends for a gift
         */
        static void requestGift(const std::vector<std::string>& invite_ids, const std::string& object_id, const std::string& message, const std::string& title = "", const std::string& additional_data = "");

        /**
         * Send friend a gift
         */
        static void sendGift(const std::vector<std::string>& friend_ids, const std::string& object_id, const std::string& title, const std::string& message, const std::string& additional_data = "");

        /**
         * Log event
         */
        static void logEvent(const std::string& eventName);

        /**
         * Log event with value
         */
        static void logEvent(const std::string& eventName, float valueToSum);

        /**
         * Log purchase event
         */
        static void logPurchase(float mount, const std::string& currency);
    };
}

#endif
