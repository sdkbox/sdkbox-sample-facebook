#include "SpriteEx.h"
#include "picojson.h"
#include "network/HttpRequest.h"
#include "network/HttpClient.h"

USING_NS_CC;

SpriteEx* SpriteEx::createWithUrl(const std::string& url) {
    SpriteEx* sprite = new SpriteEx();
    sprite->autorelease();
    sprite->init();
    sprite->updateWithUrl(url);
    return sprite;
}
SpriteEx* SpriteEx::create() {
    SpriteEx* sprite = new SpriteEx();
    sprite->autorelease();
    sprite->init();
    return sprite;
}

void SpriteEx::updateWithUrl(const std::string& url) {
    network::HttpRequest* request = new network::HttpRequest();
    request->setUrl(url.data());
    request->setRequestType(network::HttpRequest::Type::GET);
    request->setResponseCallback([=](network::HttpClient* client, network::HttpResponse* response) {
        CCLOG("success=%s", response->isSucceed() ? "yes":"no");

        std::vector<char> *buffer = response->getResponseData();
        Image img;
        img.initWithImageData(reinterpret_cast<unsigned char*>(&(buffer->front())), buffer->size());

        if (0)
        {
            // save image file to device.
            std::string path = FileUtils::getInstance()->getWritablePath()+"p.png";
            CCLOG("save image path = %s", path.data());
            bool ret = img.saveToFile(path);
            CCLOG("save file %s", ret ? "success" : "failure");

            this->initWithFile(path);
        } else {

            // create sprite with texture
            Texture2D *texture = new Texture2D();
            texture->autorelease();
            texture->initWithImage(&img);

            this->initWithTexture(texture);
        }
    });
    network::HttpClient::getInstance()->send(request);
    request->release();
}

