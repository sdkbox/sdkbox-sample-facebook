#include "SpriteExJS.hpp"
#include "cocos2d_specifics.hpp"
#include "SpriteEx.h"

template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
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

        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));
        
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;    
}
JSClass  *jsb_SpriteEx_class;
JSObject *jsb_SpriteEx_prototype;

bool js_SpriteExJS_SpriteEx_updateWithUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    JS::RootedObject obj(cx, args.thisv().toObjectOrNull());
    js_proxy_t *proxy = jsb_get_js_proxy(obj);
    SpriteEx* cobj = (SpriteEx *)(proxy ? proxy->ptr : NULL);
    JSB_PRECONDITION2( cobj, cx, false, "js_SpriteExJS_SpriteEx_updateWithUrl : Invalid Native Object");
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_SpriteExJS_SpriteEx_updateWithUrl : Error processing arguments");
        cobj->updateWithUrl(arg0);
        args.rval().setUndefined();
        return true;
    }

    JS_ReportError(cx, "js_SpriteExJS_SpriteEx_updateWithUrl : wrong number of arguments: %d, was expecting %d", argc, 1);
    return false;
}
bool js_SpriteExJS_SpriteEx_createWithUrl(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_SpriteExJS_SpriteEx_createWithUrl : Error processing arguments");
        SpriteEx* ret = SpriteEx::createWithUrl(arg0);
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<SpriteEx>(cx, (SpriteEx*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_SpriteExJS_SpriteEx_createWithUrl : wrong number of arguments");
    return false;
}

bool js_SpriteExJS_SpriteEx_create(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        SpriteEx* ret = SpriteEx::create();
        jsval jsret = JSVAL_NULL;
        do {
        if (ret) {
            js_proxy_t *jsProxy = js_get_or_create_proxy<SpriteEx>(cx, (SpriteEx*)ret);
            jsret = OBJECT_TO_JSVAL(jsProxy->obj);
        } else {
            jsret = JSVAL_NULL;
        }
    } while (0);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_SpriteExJS_SpriteEx_create : wrong number of arguments");
    return false;
}


extern JSObject *jsb_cocos2d_Sprite_prototype;

void js_SpriteEx_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (SpriteEx)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;
    jsproxy = jsb_get_js_proxy(obj);
    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        SpriteEx *nobj = static_cast<SpriteEx *>(nproxy->ptr);
        if (nobj)
            delete nobj;
        
        jsb_remove_proxy(nproxy, jsproxy);
    }
}
void js_register_SpriteExJS_SpriteEx(JSContext *cx, JS::HandleObject global) {
    jsb_SpriteEx_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_SpriteEx_class->name = "SpriteEx";
    jsb_SpriteEx_class->addProperty = JS_PropertyStub;
    jsb_SpriteEx_class->delProperty = JS_DeletePropertyStub;
    jsb_SpriteEx_class->getProperty = JS_PropertyStub;
    jsb_SpriteEx_class->setProperty = JS_StrictPropertyStub;
    jsb_SpriteEx_class->enumerate = JS_EnumerateStub;
    jsb_SpriteEx_class->resolve = JS_ResolveStub;
    jsb_SpriteEx_class->convert = JS_ConvertStub;
    jsb_SpriteEx_class->finalize = js_SpriteEx_finalize;
    jsb_SpriteEx_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FN("updateWithUrl", js_SpriteExJS_SpriteEx_updateWithUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("createWithUrl", js_SpriteExJS_SpriteEx_createWithUrl, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("create", js_SpriteExJS_SpriteEx_create, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_SpriteEx_prototype = JS_InitClass(
        cx, global,
        JS::RootedObject(cx, jsb_cocos2d_Sprite_prototype),
        jsb_SpriteEx_class,
        dummy_constructor<SpriteEx>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27 
//  JS_SetPropertyAttributes(cx, global, "SpriteEx", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<SpriteEx> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_SpriteEx_class;
        p->proto = jsb_SpriteEx_prototype;
        p->parentProto = jsb_cocos2d_Sprite_prototype;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}

void register_all_SpriteExJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkbox", &ns);

    js_register_SpriteExJS_SpriteEx(cx, ns);
}

