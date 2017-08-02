#include "PluginFacebookJS.hpp"
#include "PluginFacebook/PluginFacebook.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 52
#elif MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS_ReportErrorUTF8(cx, "Constructor for the requested class is not available, please refer to the API reference.");
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_PluginFacebook_class;
#if MOZJS_MAJOR_VERSION < 33
JSObject *jsb_sdkbox_PluginFacebook_prototype;
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getSDKVersion(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getSDKVersion();
        JS::RootedValue jsret(cx);
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_getSDKVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getSDKVersion();
        jsval jsret;
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_isLoggedIn(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::PluginFacebook::isLoggedIn();
        JS::RootedValue jsret(cx);
        jsret = JS::BooleanValue(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_isLoggedIn : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_isLoggedIn(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::PluginFacebook::isLoggedIn();
        jsval jsret;
        jsret = JS::BooleanValue(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getUserID(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getUserID();
        JS::RootedValue jsret(cx);
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_getUserID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getUserID();
        jsval jsret;
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_requestGift(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 3) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_requestGift : Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_requestGift : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_requestGift(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 3) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        ok &= jsval_to_std_vector_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_vector_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= jsval_to_std_vector_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        ok &= jsval_to_std_string(cx, argv[4], &arg4);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::requestGift(arg0, arg1, arg2, arg3, arg4);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_init(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFacebook::init();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFacebook::init();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix : Error processing arguments");
        sdkbox::PluginFacebook::setAppURLSchemeSuffix(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::setAppURLSchemeSuffix(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
bool js_PluginFacebookJS_PluginFacebook_logEvent(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    do {
        if (argc == 2) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            double arg1;
            ok &= sdkbox::js_to_number(cx, args.get(1), &arg1);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::logEvent(arg0, arg1);
            return true;
        }
    } while (0);

    do {
        if (argc == 1) {
            std::string arg0;
            ok &= jsval_to_std_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::logEvent(arg0);
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_logEvent : wrong number of arguments");
    return false;
}
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_logout(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFacebook::logout();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_logout : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_logout(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFacebook::logout();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_sendGift(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_sendGift : Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3);
        args.rval().setUndefined();
        return true;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        ok &= jsval_to_std_string(cx, args.get(2), &arg2);
        ok &= jsval_to_std_string(cx, args.get(3), &arg3);
        ok &= jsval_to_std_string(cx, args.get(4), &arg4);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_sendGift : Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3, arg4);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_sendGift : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_sendGift(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 4) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        ok &= jsval_to_std_vector_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    if (argc == 5) {
        std::vector<std::string> arg0;
        std::string arg1;
        std::string arg2;
        std::string arg3;
        std::string arg4;
        ok &= jsval_to_std_vector_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        ok &= jsval_to_std_string(cx, argv[2], &arg2);
        ok &= jsval_to_std_string(cx, argv[3], &arg3);
        ok &= jsval_to_std_string(cx, argv[4], &arg4);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::sendGift(arg0, arg1, arg2, arg3, arg4);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_setAppId(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_setAppId : Error processing arguments");
        sdkbox::PluginFacebook::setAppId(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_setAppId : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_setAppId(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::setAppId(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_fetchFriends(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        sdkbox::PluginFacebook::fetchFriends();
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_fetchFriends : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_fetchFriends(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        sdkbox::PluginFacebook::fetchFriends();
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_logPurchase(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        double arg0;
        std::string arg1;
        ok &= sdkbox::js_to_number(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFacebookJS_PluginFacebook_logPurchase : Error processing arguments");
        sdkbox::PluginFacebook::logPurchase(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_logPurchase : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_logPurchase(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        double arg0;
        std::string arg1;
        ok &= sdkbox::js_to_number(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::PluginFacebook::logPurchase(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
bool js_PluginFacebookJS_PluginFacebook_login(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;

    do {
        if (argc == 1) {
            std::vector<std::string> arg0;
            ok &= jsval_to_std_vector_string(cx, args.get(0), &arg0);
            if (!ok) { ok = true; break; }
            sdkbox::PluginFacebook::login(arg0);
            return true;
        }
    } while (0);

    do {
        if (argc == 0) {
            sdkbox::PluginFacebook::login();
            return true;
        }
    } while (0);
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_login : wrong number of arguments");
    return false;
}
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getAccessToken(JSContext *cx, uint32_t argc, JS::Value *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getAccessToken();
        JS::RootedValue jsret(cx);
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        args.rval().set(jsret);
        return true;
    }
    JS_ReportErrorUTF8(cx, "js_PluginFacebookJS_PluginFacebook_getAccessToken : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::PluginFacebook::getAccessToken();
        jsval jsret;
        sdkbox::c_string_to_jsval(cx, ret.c_str(), &jsret, ret.size());
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginFacebookJS_PluginFacebook_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (PluginFacebook)", obj);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JS::HandleObject global) {
    static JSClass PluginAgeCheq_class = {
        "PluginFacebook",
        JSCLASS_HAS_PRIVATE,
        nullptr
    };
    jsb_sdkbox_PluginFacebook_class = &PluginAgeCheq_class;

#if MOZJS_MAJOR_VERSION < 52
    jsb_sdkbox_PluginFacebook_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginFacebook_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFacebook_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFacebook_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFacebook_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFacebook_class->finalize = js_PluginFacebookJS_PluginFacebook_finalize;
    jsb_sdkbox_PluginFacebook_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);
#endif

    static JSPropertySpec properties[] = {
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getSDKVersion", js_PluginFacebookJS_PluginFacebook_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isLoggedIn", js_PluginFacebookJS_PluginFacebook_isLoggedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserID", js_PluginFacebookJS_PluginFacebook_getUserID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("requestGift", js_PluginFacebookJS_PluginFacebook_requestGift, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFacebookJS_PluginFacebook_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppURLSchemeSuffix", js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFacebookJS_PluginFacebook_logEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logout", js_PluginFacebookJS_PluginFacebook_logout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendGift", js_PluginFacebookJS_PluginFacebook_sendGift, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppId", js_PluginFacebookJS_PluginFacebook_setAppId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fetchFriends", js_PluginFacebookJS_PluginFacebook_fetchFriends, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPurchase", js_PluginFacebookJS_PluginFacebook_logPurchase, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("login", js_PluginFacebookJS_PluginFacebook_login, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAccessToken", js_PluginFacebookJS_PluginFacebook_getAccessToken, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    JS::RootedObject parent_proto(cx, nullptr);
    JSObject* objProto = JS_InitClass(
        cx, global,
        parent_proto,
        jsb_sdkbox_PluginFacebook_class,
        dummy_constructor<sdkbox::PluginFacebook>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);

    JS::RootedObject proto(cx, objProto);
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
#if MOZJS_MAJOR_VERSION >= 52
    jsb_register_class<sdkbox::PluginFacebook>(cx, jsb_sdkbox_PluginFacebook_class, proto);
#else
    jsb_register_class<sdkbox::PluginFacebook>(cx, jsb_sdkbox_PluginFacebook_class, proto, JS::NullPtr());
#endif
#else
    TypeTest<sdkbox::PluginFacebook> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginFacebook_class;
        p->proto = objProto;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif

    // add the proto and JSClass to the type->js info hash table
    JS::RootedValue className(cx);
    JSString* jsstr = JS_NewStringCopyZ(cx, "PluginFacebook");
    className = JS::StringValue(jsstr);
    JS_SetProperty(cx, proto, "_className", className);
    JS_SetProperty(cx, proto, "__nativeObj", JS::TrueHandleValue);
    JS_SetProperty(cx, proto, "__is_ref", JS::FalseHandleValue);
}
#else
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginFacebook_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginFacebook_class->name = "PluginFacebook";
    jsb_sdkbox_PluginFacebook_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_PluginFacebook_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFacebook_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFacebook_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFacebook_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFacebook_class->finalize = js_PluginFacebookJS_PluginFacebook_finalize;
    jsb_sdkbox_PluginFacebook_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getSDKVersion", js_PluginFacebookJS_PluginFacebook_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isLoggedIn", js_PluginFacebookJS_PluginFacebook_isLoggedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserID", js_PluginFacebookJS_PluginFacebook_getUserID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("requestGift", js_PluginFacebookJS_PluginFacebook_requestGift, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFacebookJS_PluginFacebook_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppURLSchemeSuffix", js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFacebookJS_PluginFacebook_logEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logout", js_PluginFacebookJS_PluginFacebook_logout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendGift", js_PluginFacebookJS_PluginFacebook_sendGift, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppId", js_PluginFacebookJS_PluginFacebook_setAppId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fetchFriends", js_PluginFacebookJS_PluginFacebook_fetchFriends, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPurchase", js_PluginFacebookJS_PluginFacebook_logPurchase, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("login", js_PluginFacebookJS_PluginFacebook_login, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAccessToken", js_PluginFacebookJS_PluginFacebook_getAccessToken, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginFacebook_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginFacebook_class,
        dummy_constructor<sdkbox::PluginFacebook>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "PluginFacebook", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginFacebook> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_PluginFacebook_class;
        p->proto = jsb_sdkbox_PluginFacebook_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JSObject *global) {
    jsb_sdkbox_PluginFacebook_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_PluginFacebook_class->name = "PluginFacebook";
    jsb_sdkbox_PluginFacebook_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_PluginFacebook_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_PluginFacebook_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_PluginFacebook_class->resolve = JS_ResolveStub;
    jsb_sdkbox_PluginFacebook_class->convert = JS_ConvertStub;
    jsb_sdkbox_PluginFacebook_class->finalize = js_PluginFacebookJS_PluginFacebook_finalize;
    jsb_sdkbox_PluginFacebook_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("getSDKVersion", js_PluginFacebookJS_PluginFacebook_getSDKVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("isLoggedIn", js_PluginFacebookJS_PluginFacebook_isLoggedIn, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getUserID", js_PluginFacebookJS_PluginFacebook_getUserID, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("requestGift", js_PluginFacebookJS_PluginFacebook_requestGift, 3, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFacebookJS_PluginFacebook_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppURLSchemeSuffix", js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFacebookJS_PluginFacebook_logEvent, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logout", js_PluginFacebookJS_PluginFacebook_logout, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("sendGift", js_PluginFacebookJS_PluginFacebook_sendGift, 4, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setAppId", js_PluginFacebookJS_PluginFacebook_setAppId, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("fetchFriends", js_PluginFacebookJS_PluginFacebook_fetchFriends, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logPurchase", js_PluginFacebookJS_PluginFacebook_logPurchase, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("login", js_PluginFacebookJS_PluginFacebook_login, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getAccessToken", js_PluginFacebookJS_PluginFacebook_getAccessToken, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_PluginFacebook_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_PluginFacebook_class,
        dummy_constructor<sdkbox::PluginFacebook>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "PluginFacebook", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::PluginFacebook> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_PluginFacebook_class;
        p->proto = jsb_sdkbox_PluginFacebook_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginFacebookJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_PluginFacebookJS_PluginFacebook(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginFacebookJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginFacebookJS_PluginFacebook(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginFacebookJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkbox", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkbox", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginFacebookJS_PluginFacebook(cx, obj);

    sdkbox::setProjectType("js");
}
#endif