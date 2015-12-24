
#include "HelloWorldScene.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    auto winsize = Director::getInstance()->getWinSize();
    auto background = Sprite::create("HelloWorld.png");
    auto size = background->getContentSize();
    background->setPosition(Vec2(size.width / 2, winsize.height - size.height / 2));
    addChild(background);

    return true;
}
