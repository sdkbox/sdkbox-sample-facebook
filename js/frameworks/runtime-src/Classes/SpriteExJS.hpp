#include "base/ccConfig.h"
#ifndef __SpriteExJS_h__
#define __SpriteExJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"

extern JSClass  *jsb_SpriteEx_class;
extern JSObject *jsb_SpriteEx_prototype;

bool js_SpriteExJS_SpriteEx_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_SpriteExJS_SpriteEx_finalize(JSContext *cx, JSObject *obj);
void js_register_SpriteExJS_SpriteEx(JSContext *cx, JS::HandleObject global);
void register_all_SpriteExJS(JSContext* cx, JS::HandleObject obj);
bool js_SpriteExJS_SpriteEx_updateWithUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_SpriteExJS_SpriteEx_createWithUrl(JSContext *cx, uint32_t argc, jsval *vp);
bool js_SpriteExJS_SpriteEx_create(JSContext *cx, uint32_t argc, jsval *vp);

#endif // __SpriteExJS_h__
