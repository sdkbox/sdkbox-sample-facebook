
var HelloWorldLayer = cc.Layer.extend({
    sprite:null,
    ctor:function () {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);
        return true;
    },

    createTestMenu:function() {
        cc.MenuItemFont.setFontName("sans");
        cc.MenuItemFont.setFontSize(40);

        if (typeof sdkbox === "undefined") {
            cc.log("sdkbox undefined");
            return true;
        }

        var self = this;
        var size = cc.winSize;
        var coinsLabel = cc.Label.createWithSystemFont("Hello Js", "Arial", 32);
        coinsLabel.setColor(cc.color(255, 0, 0, 128));
        coinsLabel.setPosition(size.width/2, 80);
        self.addChild(coinsLabel);
        self.coinsLabel = coinsLabel;
        var showText = function(msg) {
          cc.log(msg);
          console.log(msg);
          self.coinsLabel.setString(msg);
        }
        self.showText = showText;

        self.menu = new cc.Menu();
        self.menu.y = 20
        self.addChild(self.menu)

        self.iconSprite = sdkbox.SpriteEx.create()
        self.iconSprite.setPosition(size.width / 2, size.height / 2);
        self.addChild(self.iconSprite);

        self.invitableFBUserID = "";
        sdkbox.PluginFacebook.init();
        sdkbox.PluginFacebook.setListener({
            onLogin: function(isLogin, msg) {
              if(isLogin){
                self.showText("login successful");

              }
              else {
                self.showText("login failed");
              }
            },
            onAPI: function(tag, data) {
              cc.log("============");
              cc.log("tag=%s", tag);
              cc.log("data=%s", data);
              if (tag == "me") {
                var obj = JSON.parse(data);
                self.showText(obj.name + " || " + obj.email);
                                          
                console.log("picture:" + obj.picture.data.url);
//                console.log(">>" + data);
                                          
              } else if (tag == "/me/friendlists") {
                var obj = JSON.parse(data);
                var friends = obj.data;
                for (var i = 0; i < friends.length; i++) {
                  cc.log("id %s", friends[i].id);
                }
              } else if (tag == "__fetch_picture_tag__") {
                var obj = JSON.parse(data);
                var url = obj.data.url;
                cc.log("get friend's profile picture=%s", url);
                self.iconSprite.updateWithUrl(url);
              }
            },
            onSharedSuccess: function(data) {
              self.showText("share successful");
            },
            onSharedFailed: function(data) {
              self.showText("share failed");
            },
            onSharedCancel: function() {
              self.showText("share canceled");
            },
            onPermission: function(isLogin, msg) {
              if(isLogin) {
                self.showText("request permission successful");
              }
              else {
                self.showText("request permission failed");
              }
            },
            onFetchFriends: function(ok, msg) {
              self.showText(ok + ":"+msg, "onFetchFriends");

              self.menu.removeAllChildren();
              self.menu.cleanup();
              var friends = sdkbox.PluginFacebook.getFriends();
              for (var i = 0; i < friends.length; i++) {
                var friend = friends[i];
                cc.log("-----------");
                cc.log(">> uid=%s", friend.uid);
                cc.log(">> name=%s", friend.name);
                cc.log(">> first name=%s", friend.firstName);
                cc.log(">> last name=%s", friend.lastName);
                cc.log(">> is installed=%s", friend.isInstalled);

                // self.invitableFBUserID = friend.uid;

                var foo = ( function() {
                    var uid = friend.uid;
                    return {
                        onClick: function () {
                            var params = new Object();
                            params.redirect = "false";
                            params.type = "small";
                            sdkbox.PluginFacebook.api(uid+"/picture", "GET", params, "__fetch_picture_tag__");
                        }
                    };
                } () );

                // create menu
                var label = cc.Label.createWithSystemFont(friend.name, "sans", 20);
                var item = new cc.MenuItemLabel(label, foo.onClick);
                self.menu.addChild(item);

                if (friends.length <= 0) {
                  self.showText("You don't have any friend on this app", "onFetchFriends");
                }
              }
              self.menu.alignItemsHorizontally();
            },
            onRequestInvitableFriends: function(friendsData) {
                self.showText(JSON.stringify(friendsData));

                var friends = friendsData["data"];
                if (friends.length > 0) {
                    self.invitableFBUserID = friends["uid"];
                }
            },
            onInviteFriendsWithInviteIdsResult: function (result, description) {
              self.showText("onInviteFriendsWithInviteIdsResult result=" + (result?"ok":"error") + " " + description);
            },
            onInviteFriendsResult: function (result, description) {
              self.showText("onInviteFriendsResult result=" + (result?"ok":"error") + " " + description);
            }

        });

        var btnLogin = new cc.MenuItemFont("Login", function(){
          sdkbox.PluginFacebook.login();
        }, this);

        var btnLogout = new cc.MenuItemFont("Logout", function(){
          sdkbox.PluginFacebook.logout();
        }, this);

        var btnCheck = new cc.MenuItemFont("Check", function(){
          cc.log("==============")
          cc.log("isLogin: " + sdkbox.PluginFacebook.isLoggedIn());
          cc.log("userid: " + sdkbox.PluginFacebook.getUserID());
          cc.log("permissions: ");
          var perms = sdkbox.PluginFacebook.getPermissionList();
          for (var i = 0; i < perms.length; i++) {
            cc.log("===> " + perms[i]);
          }
          cc.log("==============")
        }, this);

        var btnReadPerm = new cc.MenuItemFont("Read Perm", function(){
          sdkbox.PluginFacebook.requestReadPermissions(["public_profile", "email"]);
        }, this);

        var btnWritePerm = new cc.MenuItemFont("Write Perm", function(){
          sdkbox.PluginFacebook.requestPublishPermissions(["publish_actions"]);
        }, this);

        var btnShareLink = new cc.MenuItemFont("Share Link", function(){
          var info = new Object();
          info.type  = "link";
          info.link  = "http://www.cocos2d-x.org";
          info.title = "cocos2d-x";
          info.text  = "Best Game Engine";
          info.image = "http://cocos2d-x.org/images/logo.png";
          sdkbox.PluginFacebook.share(info);
        }, this);

        var btnDialogLink = new cc.MenuItemFont("Dialog Link", function(){
          var info = new Object();
          info.type  = "link";
          info.link  = "http://www.cocos2d-x.org";
          info.title = "cocos2d-x";
          info.text  = "Best Game Engine";
          info.image = "http://cocos2d-x.org/images/logo.png";
          sdkbox.PluginFacebook.dialog(info);
        }, this);

        var btnInvite = new cc.MenuItemFont("Invite", function () {
          sdkbox.PluginFacebook.inviteFriends(
            // "https://fb.me/322164761287181",
            "https://fb.me/402104969959826",
            "http://www.cocos2d-x.org/attachments/801/cocos2dx_portrait.png");
        }, this);

        var btnMyInfo = new cc.MenuItemFont("My Info", function () {
          var params = new Object();
          params.fields = "name,email,picture.width(500).height(500)"; // picture.type(large)
          sdkbox.PluginFacebook.api("me", "GET", params, "me");
        });

        var btnFetchFriends = new cc.MenuItemFont("Fetch friends", function () {
         cc.log("friends info");
//          var params = new Object();
//          params.fields = "id,name";
//          sdkbox.PluginFacebook.api("/me/friendlists", "GET", params, "/me/friendlists");
          sdkbox.PluginFacebook.fetchFriends();
        });

        var self = this;
        self.captureFilename = jsb.fileUtils.getWritablePath() + "screen.png";
        var btnCaptureScreen = new cc.MenuItemFont("Capture screen", function(name) {
          var ss = new cc.RenderTexture( cc.winSize.width, cc.winSize.height );

          ss.begin();
          self.visit();
          ss.end();

          ss.saveToFile("screen.png");
        });

        var btnSharePhoto = new cc.MenuItemFont("Share photo", function() {
          if (jsb.fileUtils.isFileExist(self.captureFilename) == false) {
            cc.log("capture screen first");
          }

          var params = new Object();
          params.type  = "photo";
          params.title = "My Photo";
          params.image = self.captureFilename;

          cc.log("Share photo path = %s", params.image);

          sdkbox.PluginFacebook.share(params);
        });

        var btnDialogPhoto = new cc.MenuItemFont("Dialog photo", function() {
          if (jsb.fileUtils.isFileExist(self.captureFilename) == false) {
            cc.log("capture screen first");
          }

          var params = new Object();
          params.type  = "photo";
          params.title = "My Photo";
          params.image = self.captureFilename;

          cc.log("Dialog photo path = %s", params.image);

          sdkbox.PluginFacebook.dialog(params);
        });

        var btnRequestInvitableFriends = new cc.MenuItemFont("requestInvitableFriends", function () {
          self.showText("RequestInvitableFriends");
          sdkbox.PluginFacebook.requestInvitableFriends({});
        });

        var btnInviteFriendsWithInviteIds = new cc.MenuItemFont("nviteFriendsWithInviteIds", function () {
            var vec = [];
            vec.push(self.invitableFBUserID);
            sdkbox.PluginFacebook.inviteFriendsWithInviteIds(vec, "Invitation title", "Invitation text up to 60 chars.");
        });

        var menu = new cc.Menu(btnLogin, btnLogout, btnCheck, btnReadPerm, btnWritePerm, btnShareLink,
                               btnDialogLink, btnInvite, btnMyInfo, btnFetchFriends,
                               btnCaptureScreen, btnSharePhoto, btnDialogPhoto,
                               btnRequestInvitableFriends, btnInviteFriendsWithInviteIds);
        var winsize = cc.winSize;
        menu.x = winsize.width/2;
        menu.y = winsize.height/2;
        menu.alignItemsVerticallyWithPadding(10);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter:function () {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});

