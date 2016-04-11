
# How to run sdkbox samples

Steps:

~~~bash
mkdir samples
cd samples

# must clone this repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-cocos2d-x-binary.git

# clone sample repo
git clone --depth 1 https://github.com/sdkbox/sdkbox-sample-facebook.git

# run sample with specified language and platform
# eg: cpp and ios
./sdkbox-cocos2d-x-binary/run_sample.sh facebook cpp ios
# javascript and android
./sdkbox-cocos2d-x-binary/run_sample.sh facebook js android

# <optional> if exists "download-depends.sh" in sample repo, execute it
# ./sdkbox-sample-facebook/download-depends.sh

~~~

Memo:

1.  Sample repo and cocos2dx repo must be in same level directory

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-facebook
| +-- cpp
| +-- lua
| \-- js
~~~

## Notice
You have to create your own application in order to try out facebook functionality, because any app with posting functionality
has to pass facebook's review but you can out any testing functionality if you created your own facebook app

## FAQ

1. fbauth2 is missing from your Info.plist under LSApplicationQueriesSchemes and is required for iOS 9.0

https://developers.facebook.com/docs/ios/ios9
