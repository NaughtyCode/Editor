#ifndef TBASELAYER_H
#define TBASELAYER_H

#include "ProxyHeaders.h"

class TBaseObject : public cocos2d::LayerColor
{
public:
    virtual void onEnter();
    virtual void onExit();
    virtual void ProxyLeftDown(Object* sender);
    virtual void ProxyLeftUp(Object* sender);
    
private:
    cocos2d::Sprite* SpriteA;
    cocos2d::Sprite* SpriteB;
    cocos2d::Sprite* SpriteC;
    cocos2d::Sprite* SpriteD;
};

#endif