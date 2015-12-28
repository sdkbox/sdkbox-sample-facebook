#!/bin/bash
PROJECT_NAME=facebook_lua
CONFIGURATION=Debug

# choose language
cd lua
pwd

# build
xcodebuild -target ${PROJECT_NAME}-mobile \
        -configuration ${CONFIGURATION} \
            -project frameworks/runtime-src/proj.ios_mac/${PROJECT_NAME}.xcodeproj

# install and run .app on device
ios-deploy --noninteractive --debug \
        --bundle frameworks/runtime-src/proj.ios_mac/build/${CONFIGURATION}-iphoneos/${PROJECT_NAME}-mobile.app


