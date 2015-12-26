#!/bin/bash
PROJECT_NAME=facebook_cpp
CONFIGURATION=Debug

# choose language
cd cpp
pwd

# build
xcodebuild -target ${PROJECT_NAME}-mobile \
        -configuration ${CONFIGURATION} \
            -project proj.ios_mac/${PROJECT_NAME}.xcodeproj

# install and run .app on device
ios-deploy --noninteractive --debug \
        --bundle proj.ios_mac/build/${CONFIGURATION}-iphoneos/${PROJECT_NAME}-mobile.app


