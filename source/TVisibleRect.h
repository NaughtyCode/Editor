#ifndef TVISIBLERECT_H
#define TVISIBLERECT_H

#include "ProxyHeaders.h"

USING_NS_CC;

class TVisibleRect
{
public:
    static Rect getRectInfo();
    static Point left();
    static Point right();
    static Point top();
    static Point bottom();
    static Point center();
    static Point leftTop();
    static Point rightTop();
    static Point leftBottom();
    static Point rightBottom();
    
private:
    static void LazyInit();
    static Rect RectInfo;
};

#endif
