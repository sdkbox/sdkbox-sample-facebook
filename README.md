
# Getting Started

##Setup

simply run 
```bash
./setup
```

or perform following steps

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

Here is the folder structure should be look like after installation

~~~
+-- sdkbox-cocos2d-x-binary
+-- sdkbox-sample-facebook
| +-- cpp
| +-- lua
| \-- js
~~~

## Note
>You have to create your own application and testing accounts in order to try out facebook functionality. because any app with posting functionality has to pass facebook's review and testing accounts is invite only

## FAQ

1. fbauth2 is missing from your Info.plist under LSApplicationQueriesSchemes and is required for iOS 9.0

https://developers.facebook.com/docs/ios/ios9


## About invite friends

1. Create "App Links Hosting API" [https://developers.facebook.com/quickstarts/?platform=app-links-host](https://developers.facebook.com/quickstarts/?platform=app-links-host)
2. Add your test friend to your "Testers" group
3. "Friend" check the invitation with **Facebook Native App* on his/her **Mobile Device (iPhone/Android)**

