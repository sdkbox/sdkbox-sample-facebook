#include "cocos2d.h"
#include <string>

class SpriteEx : public cocos2d::Sprite
{
public:
    static SpriteEx* createWithUrl(const std::string& url) ;
    static SpriteEx* create();
    void updateWithUrl(const std::string& url);
};
