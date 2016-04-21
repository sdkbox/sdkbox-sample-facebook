#ifndef __PluginFacebookJS_h__
#define __PluginFacebookJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_PluginFacebook_class;
extern JSObject *jsb_sdkbox_PluginFacebook_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JS::HandleObject global);
void register_all_PluginFacebookJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JSObject* global);
void register_all_PluginFacebookJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginFacebookJS_PluginFacebook_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginFacebookJS_PluginFacebook_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getSDKVersion(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_isLoggedIn(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_isLoggedIn(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getUserID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getUserID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_setAppURLSchemeSuffix(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_logout(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_logout(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_setAppId(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_setAppId(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_fetchFriends(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_fetchFriends(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_login(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_login(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFacebookJS_PluginFacebook_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFacebookJS_PluginFacebook_getAccessToken(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

