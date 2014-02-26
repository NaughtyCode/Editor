#ifndef  TRENDERMAIN_H
#define  TRENDERMAIN_H

#include "ProxyHeaders.h"

class  TProxyApp: private cocos2d::Application
{
public:
    bool applicationDidFinishLaunching();
    void applicationDidEnterBackground();
    void applicationWillEnterForeground();
};

#endif
