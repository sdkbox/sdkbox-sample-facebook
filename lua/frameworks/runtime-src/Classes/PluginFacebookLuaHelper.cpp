
#include "PluginFacebookLuaHelper.h"
#include "PluginFacebook/PluginFacebook.h"
#include "CCLuaEngine.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"

static const std::string FBGraphUser_ID          ("uid");
static const std::string FBGraphUser_NAME        ("name");
static const std::string FBGraphUser_FIRST_NAME  ("firstName");
static const std::string FBGraphUser_LAST_NAME   ("lastName");
static const std::string FBGraphUser_INSTALLED   ("isInstalled");

static LuaValue FBGraphUserToLua( const sdkbox::FBGraphUser& u ) {
    LuaValueDict d;

    for( std::pair<std::string, std::string> _p : u.getFields() ) {
        d.insert( std::make_pair(_p.first, LuaValue::stringValue(_p.second) ) );
    }

    return LuaValue::dictValue(d);
}

static LuaValue FBUserListToLua(const sdkbox::FBInvitableFriendsInfo& l) {
    LuaValueArray array;

    for (sdkbox::FBInvitableFriendsInfo::const_iterator it = l.begin(); it != l.end(); it++) {
        LuaValue v = FBGraphUserToLua(*it);
        array.push_back(v);
    }

    return LuaValue::arrayValue(array);
}

class FacebookListenerLua : public sdkbox::FacebookListener {
public:
    FacebookListenerLua(): mLuaHandler(0) {

    }
    ~FacebookListenerLua() {
        resetHandler();
    }

    void setHandler(int luaHandler) {
        if (mLuaHandler == luaHandler) {
            return;
        }
        resetHandler();
        mLuaHandler = luaHandler;
    }

    void resetHandler() {
        if (0 == mLuaHandler) {
            return;
        }

        LUAENGINE->removeScriptHandler(mLuaHandler);
        mLuaHandler = 0;
    }

    void onLogin(bool isLogin, const std::string& error)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onLogin")));
        dict.insert(std::make_pair("isLoggedIn", LuaValue::booleanValue(isLogin)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(error)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onSharedSuccess(const std::string& message)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onSharedSuccess")));
        dict.insert(std::make_pair("data", LuaValue::stringValue(message)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onSharedFailed(const std::string& message)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onSharedFailed")));
        dict.insert(std::make_pair("data", LuaValue::stringValue(message)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onSharedCancel()
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onSharedCancel")));
        dict.insert(std::make_pair("data", LuaValue::stringValue("{}")));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onAPI(const std::string& tag, const std::string& jsonData)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onAPI")));
        dict.insert(std::make_pair("tag", LuaValue::stringValue(tag)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(jsonData)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onPermission(bool isLogin, const std::string& error)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onPermission")));
        dict.insert(std::make_pair("ok", LuaValue::booleanValue(isLogin)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(error)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onFetchFriends(bool ok, const std::string& msg)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onFetchFriends")));
        dict.insert(std::make_pair("ok", LuaValue::booleanValue(ok)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(msg)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onInviteFriendsResult(bool ok, const std::string& msg)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onInviteFriendsResult")));
        dict.insert(std::make_pair("ok", LuaValue::booleanValue(ok)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(msg)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onInviteFriendsWithInviteIdsResult(bool ok, const std::string& msg)
    {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onInviteFriendsWithInviteIdsResult")));
        dict.insert(std::make_pair("ok", LuaValue::booleanValue(ok)));
        dict.insert(std::make_pair("data", LuaValue::stringValue(msg)));
        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onRequestInvitableFriends(const sdkbox::FBInvitableFriendsInfo& invitable_friends_and_pagination ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onRequestInvitableFriends")));
        dict.insert(std::make_pair("users", FBUserListToLua(invitable_friends_and_pagination)));

        LuaValueDict urls;
        urls.insert(std::make_pair("next_cursor", LuaValue::stringValue(invitable_friends_and_pagination.getNextCursor())));
        urls.insert(std::make_pair("prev_cursor", LuaValue::stringValue(invitable_friends_and_pagination.getPrevCursor())));
        urls.insert(std::make_pair("next_url", LuaValue::stringValue(invitable_friends_and_pagination.getNextURL())));
        urls.insert(std::make_pair("prev_url", LuaValue::stringValue(invitable_friends_and_pagination.getPrevURL())));
        dict.insert(std::make_pair("urls", LuaValue::dictValue(urls)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
    void onGetUserInfo( const sdkbox::FBGraphUser& user ) {
        LuaStack* stack = LUAENGINE->getLuaStack();

        LuaValueDict dict;
        dict.insert(std::make_pair("name", LuaValue::stringValue("onGetUserInfo")));
        dict.insert(std::make_pair("data", FBGraphUserToLua(user)));

        stack->pushLuaValueDict(dict);
        stack->executeFunctionByHandler(mLuaHandler, 1);
    }
private:
    int mLuaHandler;
};

static sdkbox::FBShareInfo luaValueMap_to_FBShareInfo(const LuaValueDict &dict)
{
    sdkbox::FBShareInfo info;

    if (dict.find("title") != dict.end())
    {
        info.title = dict.find("title")->second.stringValue();
    }
    if (dict.find("link") != dict.end())
    {
        info.link = dict.find("link")->second.stringValue();
    }
    if (dict.find("text") != dict.end())
    {
        info.text = dict.find("text")->second.stringValue();
    }
    if (dict.find("image") != dict.end())
    {
        info.image = dict.find("image")->second.stringValue();
    }
    if (dict.find("type") != dict.end())
    {
        std::string type = dict.find("type")->second.stringValue();
        if (type.compare("link") == 0)
        {
            info.type = sdkbox::FB_LINK;
        }
        else if (type.compare("photo") == 0)
        {
            info.type = sdkbox::FB_PHOTO;
        }
    }

    return info;
}

static sdkbox::FBAPIParam luaValueMap_to_APIParam(const LuaValueDict &dict)
{
    sdkbox::FBAPIParam param;
    for (LuaValueDictIterator it = dict.begin(); it != dict.end(); it++)
    {
        param[it->first] = it->second.stringValue();
    }
    return param;
}

int lua_PluginFacebookLua_PluginFacebook_setListener(lua_State* tolua_S) {
    int argc = 0;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
#if COCOS2D_DEBUG >= 1
        if (!toluafix_isfunction(tolua_S, 2 , "LUA_FUNCTION",0,&tolua_err))
        {
            goto tolua_lerror;
        }
#endif
        LUA_FUNCTION handler = (  toluafix_ref_function(tolua_S,2,0));
        FacebookListenerLua* lis = static_cast<FacebookListenerLua*> (sdkbox::PluginFacebook::getListener());
        if (nullptr == lis) {
            lis = new FacebookListenerLua();
        }
        lis->setHandler(handler);
        sdkbox::PluginFacebook::setListener(lis);

        return 0;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook::setListener",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_setListener'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_dialog(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        LuaValueDict arg0;
        ok &= luaval_to_ccluavaluemap(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_dialog'", nullptr);
            return 0;
        }

        sdkbox::FBShareInfo info = luaValueMap_to_FBShareInfo(arg0);
        sdkbox::PluginFacebook::dialog(info);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:dialog",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_dialog'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_share(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        LuaValueDict arg0;
        ok &= luaval_to_ccluavaluemap(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_share'", nullptr);
            return 0;
        }

        sdkbox::FBShareInfo info = luaValueMap_to_FBShareInfo(arg0);
        sdkbox::PluginFacebook::share(info);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:share",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_share'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_api(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 4)
    {
        std::string path;
        ok &= luaval_to_std_string(tolua_S, 2, &path);
        std::string method;
        ok &= luaval_to_std_string(tolua_S, 3, &method);
        LuaValueDict arg0;
        ok &= luaval_to_ccluavaluemap(tolua_S, 4, &arg0);
        std::string tag;
        ok &= luaval_to_std_string(tolua_S, 5, &tag);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_api'", nullptr);
            return 0;
        }

        sdkbox::FBAPIParam params = luaValueMap_to_APIParam(arg0);
        sdkbox::PluginFacebook::api(path, method, params, tag);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:api",argc, 4);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_api'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFacebookLua_PluginFacebook_requestInvitableFriends(lua_State* tolua_S) {
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0) {
        sdkbox::FBAPIParam params;
        sdkbox::PluginFacebook::requestInvitableFriends(params);
        lua_settop(tolua_S, 1);
        return 1;
    } else if (argc == 1) {
        LuaValueDict arg0;
        ok &= luaval_to_ccluavaluemap(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_api'", nullptr);
            return 0;
        }

        sdkbox::FBAPIParam params = luaValueMap_to_APIParam(arg0);
        sdkbox::PluginFacebook::requestInvitableFriends(params);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:requestInvitableFriends",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_requestInvitableFriends'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFacebookLua_PluginFacebook_getFriends(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_getFriends'", nullptr);
            return 0;
        }
        std::vector<sdkbox::FBGraphUser> ret = sdkbox::PluginFacebook::getFriends();
        LuaStack* stack = LUAENGINE->getLuaStack();
        LuaValueArray array;
        for (std::vector<sdkbox::FBGraphUser>::iterator it = ret.begin(); it != ret.end(); it++)
        {
            LuaValueDict dict;
            dict[FBGraphUser_ID]         = LuaValue::stringValue(it->uid);
            dict[FBGraphUser_NAME]       = LuaValue::stringValue(it->name);
            dict[FBGraphUser_FIRST_NAME] = LuaValue::stringValue(it->firstName);
            dict[FBGraphUser_LAST_NAME]  = LuaValue::stringValue(it->lastName);
            dict[FBGraphUser_INSTALLED]  = LuaValue::booleanValue(it->isInstalled);

            array.push_back(LuaValue::dictValue(dict));
        }

        stack->pushLuaValueArray(array);

        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:getFriends",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_getFriends'.",&tolua_err);
#endif
    return 0;
}

int lua_PluginFacebookLua_PluginFacebook_canPresentWithFBApp(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        LuaValueDict arg0;
        ok &= luaval_to_ccluavaluemap(tolua_S, 2, &arg0);
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_canPresentWithFBApp'", nullptr);
            return 0;
        }

        sdkbox::FBShareInfo info = luaValueMap_to_FBShareInfo(arg0);
        bool canPresent =sdkbox::PluginFacebook::canPresentWithFBApp(info);

        LuaStack* stack = LUAENGINE->getLuaStack();
        stack->pushLuaValue(LuaValue::booleanValue(canPresent));

        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:dialog",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_dialog'.",&tolua_err);
#endif
    return 0;
}

int extern_PluginFacebook(lua_State* L) {
    if (nullptr == L) {
        return 0;
    }

    lua_pushstring(L, "sdkbox.PluginFacebook");
    lua_rawget(L, LUA_REGISTRYINDEX);
    if (lua_istable(L,-1))
    {
        tolua_function(L,"setListener", lua_PluginFacebookLua_PluginFacebook_setListener);
        tolua_function(L,"share", lua_PluginFacebookLua_PluginFacebook_share);
        tolua_function(L,"dialog", lua_PluginFacebookLua_PluginFacebook_dialog);
        tolua_function(L,"getFriends", lua_PluginFacebookLua_PluginFacebook_getFriends);
        tolua_function(L, "canPresentWithFBApp", lua_PluginFacebookLua_PluginFacebook_canPresentWithFBApp);
        tolua_function(L, "api", lua_PluginFacebookLua_PluginFacebook_api);
        tolua_function(L, "requestInvitableFriends", lua_PluginFacebookLua_PluginFacebook_requestInvitableFriends);
    }
    lua_pop(L, 1);

    return 1;
}

TOLUA_API int register_all_PluginFacebookLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");

    extern_PluginFacebook(L);

    tolua_endmodule(L);
    return 1;
}


