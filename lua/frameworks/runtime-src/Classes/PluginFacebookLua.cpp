#include "PluginFacebookLua.hpp"
#include "PluginFacebook/PluginFacebook.h"
#include "tolua_fix.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginFacebookLua_PluginFacebook_getPermissionList(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_getPermissionList'", nullptr);
            return 0;
        }
        std::vector<std::string> ret = sdkbox::PluginFacebook::getPermissionList();
        ccvector_std_string_to_luaval(tolua_S, ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:getPermissionList",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_getPermissionList'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_getSDKVersion(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_getSDKVersion'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginFacebook::getSDKVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:getSDKVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_getSDKVersion'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_isLoggedIn(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_isLoggedIn'", nullptr);
            return 0;
        }
        bool ret = sdkbox::PluginFacebook::isLoggedIn();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:isLoggedIn",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_isLoggedIn'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_getUserID(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_getUserID'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginFacebook::getUserID();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:getUserID",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_getUserID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_init(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_init'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::init();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_setAppURLSchemeSuffix(lua_State* tolua_S)
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
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFacebook:setAppURLSchemeSuffix");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_setAppURLSchemeSuffix'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::setAppURLSchemeSuffix(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:setAppURLSchemeSuffix",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_setAppURLSchemeSuffix'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_logout(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_logout'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::logout();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:logout",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_logout'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_requestPublishPermissions(lua_State* tolua_S)
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
        std::vector<std::string> arg0;
        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "sdkbox.PluginFacebook:requestPublishPermissions");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_requestPublishPermissions'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::requestPublishPermissions(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:requestPublishPermissions",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_requestPublishPermissions'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_requestReadPermissions(lua_State* tolua_S)
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
        std::vector<std::string> arg0;
        ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "sdkbox.PluginFacebook:requestReadPermissions");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_requestReadPermissions'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::requestReadPermissions(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:requestReadPermissions",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_requestReadPermissions'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_setAppId(lua_State* tolua_S)
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
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFacebook:setAppId");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_setAppId'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::setAppId(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:setAppId",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_setAppId'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_fetchFriends(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_fetchFriends'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::fetchFriends();
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:fetchFriends",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_fetchFriends'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_login(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;
#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.PluginFacebook",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S)-1;

    do 
    {
        if (argc == 1)
        {
            std::vector<std::string> arg0;
            ok &= luaval_to_std_vector_string(tolua_S, 2, &arg0, "sdkbox.PluginFacebook:login");
            if (!ok) { break; }
            sdkbox::PluginFacebook::login(arg0);
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    do 
    {
        if (argc == 0)
        {
            sdkbox::PluginFacebook::login();
            lua_settop(tolua_S, 1);
            return 1;
        }
    } while (0);
    ok  = true;
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d", "sdkbox.PluginFacebook:login",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_login'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_inviteFriends(lua_State* tolua_S)
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

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.PluginFacebook:inviteFriends");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.PluginFacebook:inviteFriends");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_inviteFriends'", nullptr);
            return 0;
        }
        sdkbox::PluginFacebook::inviteFriends(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:inviteFriends",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_inviteFriends'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFacebookLua_PluginFacebook_getAccessToken(lua_State* tolua_S)
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
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFacebookLua_PluginFacebook_getAccessToken'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::PluginFacebook::getAccessToken();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.PluginFacebook:getAccessToken",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFacebookLua_PluginFacebook_getAccessToken'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginFacebookLua_PluginFacebook_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (PluginFacebook)");
    return 0;
}

int lua_register_PluginFacebookLua_PluginFacebook(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.PluginFacebook");
    tolua_cclass(tolua_S,"PluginFacebook","sdkbox.PluginFacebook","",nullptr);

    tolua_beginmodule(tolua_S,"PluginFacebook");
        tolua_function(tolua_S,"getPermissionList", lua_PluginFacebookLua_PluginFacebook_getPermissionList);
        tolua_function(tolua_S,"getSDKVersion", lua_PluginFacebookLua_PluginFacebook_getSDKVersion);
        tolua_function(tolua_S,"isLoggedIn", lua_PluginFacebookLua_PluginFacebook_isLoggedIn);
        tolua_function(tolua_S,"getUserID", lua_PluginFacebookLua_PluginFacebook_getUserID);
        tolua_function(tolua_S,"init", lua_PluginFacebookLua_PluginFacebook_init);
        tolua_function(tolua_S,"setAppURLSchemeSuffix", lua_PluginFacebookLua_PluginFacebook_setAppURLSchemeSuffix);
        tolua_function(tolua_S,"logout", lua_PluginFacebookLua_PluginFacebook_logout);
        tolua_function(tolua_S,"requestPublishPermissions", lua_PluginFacebookLua_PluginFacebook_requestPublishPermissions);
        tolua_function(tolua_S,"requestReadPermissions", lua_PluginFacebookLua_PluginFacebook_requestReadPermissions);
        tolua_function(tolua_S,"setAppId", lua_PluginFacebookLua_PluginFacebook_setAppId);
        tolua_function(tolua_S,"fetchFriends", lua_PluginFacebookLua_PluginFacebook_fetchFriends);
        tolua_function(tolua_S,"login", lua_PluginFacebookLua_PluginFacebook_login);
        tolua_function(tolua_S,"inviteFriends", lua_PluginFacebookLua_PluginFacebook_inviteFriends);
        tolua_function(tolua_S,"getAccessToken", lua_PluginFacebookLua_PluginFacebook_getAccessToken);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::PluginFacebook).name();
    g_luaType[typeName] = "sdkbox.PluginFacebook";
    g_typeCast["PluginFacebook"] = "sdkbox.PluginFacebook";
    return 1;
}
TOLUA_API int register_all_PluginFacebookLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);
	
	tolua_module(tolua_S,"sdkbox",0);
	tolua_beginmodule(tolua_S,"sdkbox");

	lua_register_PluginFacebookLua_PluginFacebook(tolua_S);

	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

