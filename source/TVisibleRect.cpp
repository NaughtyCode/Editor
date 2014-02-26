#include "TVisibleRect.h"

Rect TVisibleRect::RectInfo;

void TVisibleRect::LazyInit()
{
    if (RectInfo.size.width==0.0f && RectInfo.size.height==0.0f)
    {
        auto glView     = EGLView::getInstance();
        RectInfo.origin = glView->getVisibleOrigin();
        RectInfo.size   = glView->getVisibleSize();
    }
}

Rect TVisibleRect::getRectInfo()
{
    LazyInit();
    return Rect(RectInfo.origin.x,RectInfo.origin.y,RectInfo.size.width,RectInfo.size.height);
}

Point TVisibleRect::left()
{
    LazyInit();
    return Point(RectInfo.origin.x,RectInfo.origin.y+RectInfo.size.height/2);
}

Point TVisibleRect::right()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width,RectInfo.origin.y+RectInfo.size.height/2);
}

Point TVisibleRect::top()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width/2,RectInfo.origin.y+RectInfo.size.height);
}

Point TVisibleRect::bottom()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width/2,RectInfo.origin.y);
}

Point TVisibleRect::center()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width/2,RectInfo.origin.y+RectInfo.size.height/2);
}

Point TVisibleRect::leftTop()
{
    LazyInit();
    return Point(RectInfo.origin.x,RectInfo.origin.y+RectInfo.size.height);
}

Point TVisibleRect::rightTop()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width,RectInfo.origin.y+RectInfo.size.height);
}

Point TVisibleRect::leftBottom()
{
    LazyInit();
    return RectInfo.origin;
}

Point TVisibleRect::rightBottom()
{
    LazyInit();
    return Point(RectInfo.origin.x+RectInfo.size.width,RectInfo.origin.y);
}
