#ifndef __PluginFacebookJS_h__
#define __PluginFacebookJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JS::HandleObject global);
void register_all_PluginFacebookJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFacebookJS_PluginFacebook(JSContext *cx, JSObject* global);
void register_all_PluginFacebookJS(JSContext* cx, JSObject* obj);
#endif
#endif

