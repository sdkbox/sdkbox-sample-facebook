
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
        printf = cc.log;
        var showText = function(msg) {
          printf(msg);
          self.coinsLabel.setString(msg);
        }
        self.showText = showText;

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
              cc.log(tag);
              cc.log(data);
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
            "https://fb.me/322164761287181",
            "http://www.cocos2d-x.org/attachments/801/cocos2dx_portrait.png");
        }, this);

        var menu = new cc.Menu(btnLogin, btnLogout, btnCheck, btnReadPerm, btnWritePerm, btnShareLink, btnDialogLink, btnInvite);
        var winsize = cc.winSize;
        menu.x = winsize.width/2;
        menu.y = winsize.height/2;
        menu.alignItemsVerticallyWithPadding(20);
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

