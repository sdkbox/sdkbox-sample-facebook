#ifndef __PLUGIN_FACEBOOK_WRAPPER_H__
#define __PLUGIN_FACEBOOK_WRAPPER_H__

#include "CocosMacros.h"
#include "PluginFacebook.h"

namespace sdkbox {

#define TAG "Facebook"
#define VERSION "4.12.0"

class FacebookWrapper {
public:

    virtual void init() = 0;
    virtual void setListener(FacebookListener* listener) = 0;
    virtual FacebookListener* getListener() = 0;
    virtual void removeListener() = 0;

    /**
     * Login with public profile only
     */
    virtual void login( ) = 0;

    /**
     * login with a collection of read permissions.
     */
    virtual void login( const std::vector<std::string>& permissions ) = 0;

    /**
     *
     * Use any combination of:
     *   + sdkbox::FB_PERM_READ_PUBLIC_PROFILE
     *   + sdkbox::FB_PERM_READ_EMAIL
     *   + sdkbox::FB_PERM_READ_USER_FRIENDS
     *
     * or any other valid permission.
     *
     */
    virtual void requestReadPermissions(const std::vector<std::string>& permissions) = 0;

    /**
     *
     * Use any combination of:
     *   + sdkbox::FB_PERM_PUBLISH_POST
     *
     * or any other valid publish permission. Publish permissions start with 'publish_', 'manage_' but
     * there some other valid permissions as well.
     */
    virtual void requestPublishPermissions(const std::vector<std::string>& permissions) = 0;
    virtual void logout() = 0;
    virtual bool isLoggedIn() = 0;
    virtual std::string getUserID() = 0;
    virtual std::string getAccessToken() = 0;
    virtual std::vector<std::string> getPermissionList() = 0;
    virtual void share(const FBShareInfo& info) = 0;
    virtual void dialog(const FBShareInfo& info) = 0;
    virtual std::string getSDKVersion() = 0;
    virtual void api(const std::string& path, const std::string& method, const FBAPIParam& params, const std::string& tag) = 0;
    virtual void fetchFriends() = 0;
    virtual std::vector<FBGraphUser> getFriends() = 0;
    virtual bool canPresent(const sdkbox::FBShareInfo &info) = 0;

    /**
     * The parameters are:
     *   + kRI_ExcludeFromList :    an [optional] comma separated string with FB-ids to avoid on the resulting list.
     *   + kRI_PictureSize :        an [optional] string (integer representation) with the expected users' picture size
     *   + kRI_PaginationLimit :    an [optional] string (integer representation) with the limit of friends returned per page.
     *   + kRI_kRI_ResponseFields : an [optional] comma separated string with the fields per FBInvitableUserInfo. Values are basic profile values.
     *
     * some more to come.
     *
     * definition is in PluginFacebook.h
     *
     */
    virtual void requestInvitableFriends( const FBAPIParam& ) = 0;
    virtual void inviteFriendsWithInviteIds( const std::vector<std::string>& invite_ids, const std::string& title, const std::string& invite_text ) = 0;
    virtual void inviteFriends( const std::string& app_link_url, const std::string& preview_image_url ) = 0;

    virtual int getShareType() = 0;
    virtual void setShareType(const FBShareType& type) = 0;
    virtual void setAppId(const std::string& appid) = 0;
    virtual void setAppURLSchemeSuffix(const std::string& appURLSchemeSuffix) = 0;
    
    static FacebookWrapper* getInstance();
};

class FacebookWrapperDisabled : public FacebookWrapper {
    void init() {}
    void setListener(FacebookListener* listener) {}
    FacebookListener* getListener() { return NULL; }
    void removeListener() {}
    void login( ) {}
    void login( const std::vector<std::string>& permissions ) {}
    void requestReadPermissions(const std::vector<std::string>& permissions) {}
    void requestPublishPermissions(const std::vector<std::string>& permissions) {}
    void logout() {}
    bool isLoggedIn() { return false; }
    std::string getUserID() { return ""; }
    std::string getAccessToken() { return ""; }
    std::vector<std::string> getPermissionList() { return std::vector<std::string>(); }
    void share(const FBShareInfo& info) {}
    void dialog(const FBShareInfo& info) {}
    std::string getSDKVersion() { return ""; }
    void api(const std::string& path, const std::string& method, const FBAPIParam& params, const std::string& tag) {}
    void fetchFriends() {}
    std::vector<FBGraphUser> getFriends() { return std::vector<FBGraphUser>(); }
    bool canPresent(const sdkbox::FBShareInfo &info) { return false; }
    void requestInvitableFriends( const FBAPIParam& ) {}
    void inviteFriendsWithInviteIds( const std::vector<std::string>& invite_ids, const std::string& title, const std::string& invite_text ) {}
    void inviteFriends( const std::string& app_link_url, const std::string& preview_image_url ) {}
    int getShareType() { return -1; }
    void setShareType(const FBShareType& type) {}
    void setAppId(const std::string& appid) {}
    void setAppURLSchemeSuffix(const std::string& appURLSchemeSuffix) {}

private:
    static FacebookWrapper* _instance;
    
};

class FacebookWrapperEnabled : public FacebookWrapper {
public:
    FacebookWrapperEnabled();
    ~FacebookWrapperEnabled();
    
    void init();
    void setListener(FacebookListener* listener);
    FacebookListener* getListener();
    void removeListener();
    void login( );
    void login( const std::vector<std::string>& permissions );
    void requestReadPermissions(const std::vector<std::string>& permissions);
    void requestPublishPermissions(const std::vector<std::string>& permissions);
    void logout();
    bool isLoggedIn();
    std::string getUserID();
    std::string getAccessToken();
    std::vector<std::string> getPermissionList();
    void share(const FBShareInfo& info);
    void dialog(const FBShareInfo& info);
    std::string getSDKVersion();
    void api(const std::string& path, const std::string& method, const FBAPIParam& params, const std::string& tag);
    void fetchFriends();
    std::vector<FBGraphUser> getFriends();
    bool canPresent(const sdkbox::FBShareInfo &info);
    void requestInvitableFriends( const FBAPIParam& );
    void inviteFriendsWithInviteIds( const std::vector<std::string>& invite_ids, const std::string& title, const std::string& invite_text );
    void inviteFriends( const std::string& app_link_url, const std::string& preview_image_url );
    
    int getShareType();
    void setShareType(const FBShareType& type);
    void setAppId(const std::string& appid);
    void setAppURLSchemeSuffix(const std::string& appURLSchemeSuffix);
protected:
    bool nativeInit(bool debug);
    std::string getAppId();
    std::string nativeSDKVersion();
    
    FacebookListener* _listener;
    
    FBShareType _shareType;
    
};

} // namespace

#endif
