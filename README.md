
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

2017-11-15:
[https://developers.facebook.com/quickstarts/?platform=app-links-host](https://developers.facebook.com/quickstarts/?platform=app-links-host) is offline.

https://developers.facebook.com/docs/applinks/hosting-api/
> With the release of the Facebook SDK version 4.28.0, App Links Hosting is deprecated. It will be supported until February 5, 2018.



# hosting-api

1. Get `APP_ACCESS_TOKEN` (App Token) in https://developers.facebook.com/tools/access_token/
2. Create links

```
curl https://graph.facebook.com/app/app_link_hosts \
-F access_token="APP_ACCESS_TOKEN" \
-F name="iOS App Link Object Example" \
-F ios=' [
    {
      "url" : "sharesample://story/1234",
      "app_store_id" : 12345,
      "app_name" : "ShareSample",
    },
  ]' \
-F web=' {
    "should_fallback" : false,
  }'
```

3. Query link

```
curl -G https://graph.facebook.com/{YOUR_LINK_ID} \
-d access_token="APP_ACCESS_TOKEN" \
-d fields=canonical_url \
-d pretty=true


#
#{
#   "canonical_url": "https://fb.me/611591085677879",
#   "id": "611591085677879"
#}

# or
curl -G https://graph.facebook.com \
-d access_token="APP_ACCESS_TOKEN" \
-d fields=app_links \
-d ids=https://fb.me/{YOUR_LINK_ID} \
-d pretty=true
```

4. Update link

```
curl https://graph.facebook.com/{YOUR_LINK_ID} \
-F access_token="APP_ACCESS_TOKEN" \
-F name="FB App Link Object Example" \
-F ios=' [
    {
      "url" : "sharesample://story/1234",
      "app_store_id" : 12345,
      "app_name" : "ShareSample",
    },
  ]' \
-F web=' {
    "should_fallback" : false,
}'
```



**注意**:
如果一个 applink 里面同时设置了 ios 和 Android，用 Safari 测试，只会打开 Google Play ，需要在 FB 应用里面测试验证一下。


