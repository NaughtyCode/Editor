#include "ProxyRenderdef.h"
#include "TVisibleRect.h"
#include "TBaseObject.h"
#include "ProxyGlobalData.h"

USING_NS_CC;

void TBaseObject::onEnter()
{
    LayerColor::onEnter();
    
    MenuItemImage* item = MenuItemImage::create("GameRes//interface//playnormal.png","GameRes//interface//playselected.png",CC_CALLBACK_1(TBaseObject::ProxyLeftDown, this));
    Menu* menu = Menu::create(item,NULL,NULL,NULL);
    menu->setPosition(Point::ZERO);
    item->setPosition(Point(TVisibleRect::center().x, TVisibleRect::center().y + item->getContentSize().height / 2));
    this->addChild(menu,9999);
    
    Size s = Director::getInstance()->getWinSize();
    
    SpriteA = Sprite::create("GameRes//character//ant1.png");
    SpriteB = Sprite::create("GameRes//character//ant2.png");
    SpriteC = Sprite::create("GameRes//character//ant1.png");
    SpriteD = Sprite::create("GameRes//character//ant2.png");
    
    SpriteA->setPosition(Point(100, s.height /2 ));
    SpriteB->setPosition(Point(380, s.height /2 ));
    this->addChild(SpriteA);
    this->addChild(SpriteB);
    
    SpriteA->setScale(0.6f);
    SpriteB->setScale(0.6f);
    
    SpriteC->setScale(0.5f);
    SpriteD->setScale(0.5f);
    
    SpriteA->addChild(SpriteC);
    SpriteB->addChild(SpriteD);
}

void TBaseObject::onExit()
{
    LayerColor::onExit();
}

void TBaseObject::ProxyLeftDown(Object* sender)
{
    SetSelectedObject((ObjectHandle)SpriteC);
    PushEngineMessage(0,"ProxyLeftDown");
}

void TBaseObject::ProxyLeftUp(Object* sender)
{
    
}
