LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2djs_shared

LOCAL_MODULE_FILENAME := libcocos2djs

LOCAL_ARM_MODE := arm

LOCAL_SRC_FILES := ../../Classes/AppDelegate.cpp ../../Classes/ide-support/SimpleConfigParser.cpp ../../Classes/ide-support/RuntimeJsImpl.cpp hellojavascript/main.cpp ../../Classes/PluginFacebookJS.cpp ../../Classes/PluginFacebookJS.hpp ../../Classes/PluginFacebookJSHelper.cpp ../../Classes/PluginFacebookJSHelper.h ../../Classes/SDKBoxJSHelper.cpp ../../Classes/SDKBoxJSHelper.h ../../Classes/SpriteEx.cpp ../../Classes/SpriteExJS.cpp

LOCAL_CPPFLAGS := -DSDKBOX_ENABLED
LOCAL_LDLIBS := -landroid -llog
LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes
LOCAL_WHOLE_STATIC_LIBRARIES := PluginFacebook sdkbox

LOCAL_STATIC_LIBRARIES := cocos2d_js_static
LOCAL_STATIC_LIBRARIES += cocos2d_simulator_static

include $(BUILD_SHARED_LIBRARY)
$(call import-add-path, $(LOCAL_PATH))


$(call import-module,scripting/js-bindings/proj.android/prebuilt-mk)
$(call import-module,tools/simulator/libsimulator/proj.android/prebuilt-mk)
$(call import-module, ./sdkbox)
$(call import-module, ./pluginfacebook)
