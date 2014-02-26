#include "TProxyApp.h"
#include "ProxyGlobalData.h"
#include "ProxyRenderdef.h"
#include "TBaseObject.h"

USING_NS_CC;

bool TProxyApp::applicationDidFinishLaunching(){
    Director* director = Director::getInstance();
    EGLView* glView = EGLView::getInstance();
    director->setOpenGLView(glView);
    Size FrameSize = glView->getFrameSize();
    glView->setDesignResolutionSize(FrameSize.width,FrameSize.height,ResolutionPolicy::NO_BORDER);
    director->setDisplayStats(false);
    director->setAnimationInterval(1.0/60);
    SetFilePath(std::string("..\\resource\\"));
    
    Scene* scene = Scene::create();
    TBaseObject * worklayer = new TBaseObject;
    if(worklayer && worklayer->initWithColor(Color4B(0,100,100,255))){
	SetWorkScene((ObjectHandle)worklayer);
	worklayer->setScale(0.35f);
	worklayer->autorelease();
	scene->addChild(worklayer);
    }
    scene->setPositionX(-300);
    scene->setPositionY(200);
    director->runWithScene(scene);
    return true;
}

void TProxyApp::applicationDidEnterBackground(){
    Director::getInstance()->stopAnimation();
}

void TProxyApp::applicationWillEnterForeground(){
    Director::getInstance()->startAnimation();
}
