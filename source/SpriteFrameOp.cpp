#include "SpriteFrameOp.h"
#include "ProxyRenderdef.h"
#include "TVisibleRect.h"
#include "TBaseObject.h"
#include "ProxyGlobalData.h"

USING_NS_CC;

void SriteFrameOperate()
{
    Sprite* frame = (Sprite*)GetSelectedObject();
    if(frame==0)return;
    Point p = frame->getPosition();
    float deltamousex;
    float deltamousey;
    GetDeltaMousePos(deltamousex,deltamousey);
    frame->setPosition(Point(p.x+deltamousex,p.y+deltamousey));
}
