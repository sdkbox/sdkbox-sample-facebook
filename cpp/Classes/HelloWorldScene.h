#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "PluginFacebook/PluginFacebook.h"

class SpriteEx;
class HelloWorld : public cocos2d::Layer, sdkbox::FacebookListener
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

    void onLoginClick(cocos2d::Ref* sender);
    void onCheckStatus(cocos2d::Ref* sender);
    void onGetMyInfo(cocos2d::Ref* sender);
    void onGetMyFriends(cocos2d::Ref* sender);
    void onCaptureScreen(cocos2d::Ref* sender);
    void onShareLink(cocos2d::Ref* sender);
    void onSharePhoto(cocos2d::Ref* sender);
    void onDialogLink(cocos2d::Ref* sender);
    void onDialogPhoto(cocos2d::Ref* sender);
    void onRequestReadPermission(cocos2d::Ref* sender);
    void onRequestPublishPermission(cocos2d::Ref* sender);
    void onInviteFriends(cocos2d::Ref* sender);

private:
    void createTestMenu();

    //Facebook callback
    void onLogin(bool isLogin, const std::string& msg);
    void onSharedSuccess(const std::string& message);
    void onSharedFailed(const std::string& message);
    void onSharedCancel();
    void onAPI(const std::string& key, const std::string& jsonData);
    void onPermission(bool isLogin, const std::string& msg);
    void onFetchFriends(bool ok, const std::string& msg);
    void onRequestInvitableFriends( const sdkbox::FBInvitableFriendsInfo& friends );
    void onInviteFriendsWithInviteIdsResult( bool result, const std::string& msg );
    void onInviteFriendsResult( bool result, const std::string& msg );
    void onGetUserInfo( const sdkbox::FBGraphUser& userInfo );
    
    void afterCaptureScreen(bool, const std::string& outputFilename);

    std::string _captureFilename;
    cocos2d::MenuItemLabel* _loginItem;
    SpriteEx* _iconSprite;
};

#endif // __HELLOWORLD_SCENE_H__
