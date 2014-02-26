#include "SpriteFrameOp.h"
#include "ProxyMessage.h"
#include "ProxyInteractive.h"
#include "ProxyHeaders.h"
#include "TProxyApp.h"
#include "ProxyGlobalData.h"
#include "CommandDefinition.h"
#include "TBaseObject.h"



void ProxyStopRender(const std::string& message)
{
    cocos2d::Director::getInstance()->end();
    ResetAllGlobalData();
}

void ProxySwitchFPS(const std::string& message)
{
    bool isshowstates = cocos2d::Director::getInstance()->isDisplayStats();
    cocos2d::Director::getInstance()->setDisplayStats(!isshowstates);
}

void ProxyKeyPressEvent(const std::string& message)
{
    
}

void ProxyKeyReleaseEvent(const std::string& message)
{
    
}

void ProxyLeaveEvent(const std::string& message)
{
    
}

void ProxyEnterEvent(const std::string& message)
{
    
}

void ProxyMouseDoubleClickEvent(const std::string& message)
{
    ProxyMousePressEvent(message);
}

void ProxyMouseMoveEvent(const std::string& message)
{
    cocos2d::EGLView* glView = cocos2d::EGLView::getInstance();
    if(nullptr == glView) return;
    long Id=0;
    float MouseX,MouseY;
    int button;
    std::istringstream messagebuffer(message);
    int command;
    messagebuffer>>command>>MouseX>>MouseY>>button;
    SetMousePos(MouseX,MouseY);
    
    SriteFrameOperate();
    
    MouseX/= glView->getFrameZoomFactor();
    MouseY/= glView->getFrameZoomFactor();
    if (IsCapture())
    {
        if (glView->getViewPortRect().equals(cocos2d::Rect::ZERO)||glView->getViewPortRect().containsPoint(cocos2d::Point(MouseX,glView->getFrameSize().height-MouseY)))
        {
            glView->handleTouchesMove(1,&Id, &MouseX, &MouseY);
        }
    }
    cocos2d::EventMouse event(cocos2d::EventMouse::MouseEventType::MOUSE_MOVE);
    event.setCursorPosition(MouseX,glView->getViewPortRect().size.height-MouseY);
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}

void ProxyMousePressEvent(const std::string& message)
{
    SetCapture(true);
    std::istringstream messagebuffer(message);
    int command;
    long Id=0;
    int button;
    float MouseX,MouseY;
    messagebuffer>>command>>MouseX>>MouseY>>button;
    SetMousePos(MouseX,MouseY);
    cocos2d::EGLView* glView = cocos2d::EGLView::getInstance();
    if(glView==nullptr)return;
    if (glView->getViewPortRect().equals(cocos2d::Rect::ZERO)||glView->getViewPortRect().containsPoint(cocos2d::Point(MouseX,MouseY)))
    {
        glView->handleTouchesBegin(1,&Id,&MouseX,&MouseY);
    }
    cocos2d::EventMouse event(cocos2d::EventMouse::MouseEventType::MOUSE_DOWN);
    event.setCursorPosition(MouseX, glView->getViewPortRect().size.height-MouseY);
    event.setMouseButton(button);
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}

void ProxyMouseReleaseEvent(const std::string& message)
{
    SetCapture(false);
    
    std::istringstream messagebuffer(message);
    int command;
    long Id=0;
    int button;
    float MouseX, MouseY;
    messagebuffer>>command>>MouseX>>MouseY>>button;
    SetMousePos(MouseX,MouseY);
    cocos2d::EGLView* glView = cocos2d::EGLView::getInstance();
    if(glView==nullptr)return;
    if (glView->getViewPortRect().equals(cocos2d::Rect::ZERO) || glView->getViewPortRect().containsPoint(cocos2d::Point(MouseX,MouseY)))
    {
        glView->handleTouchesEnd(1, &Id,&MouseX,&MouseY);
    }
    cocos2d::EventMouse event(cocos2d::EventMouse::MouseEventType::MOUSE_UP);
    event.setCursorPosition(MouseX, glView->getViewPortRect().size.height-MouseY);
    event.setMouseButton(button);
    cocos2d::Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}

void ProxyMoveEvent(const std::string& message){}

void ProxyScreenScaleEvent(const std::string& message)
{
    int command;
    float scale;
    std::istringstream messagebuffer(message);
    messagebuffer>>command>>scale;
    TBaseObject* handle =(TBaseObject*)GetWorkScene();
    if(handle!=0 && scale!=0.0f){
        handle->setScale(scale);
    }
}

void ProxyScreenSizeEvent(const std::string& message)
{
    int command;
    int width,height;
    std::istringstream messagebuffer(message);
    messagebuffer>>command>>width>>height;
    TBaseObject* handle =(TBaseObject*)GetWorkScene();
    if(handle!=0 && width!=0 && height!=0){
    }
}

void ProxyScreenPositionXEvent(const std::string& message)
{
    int command,X;
    std::istringstream messagebuffer(message);
    messagebuffer>>command>>X;
    TBaseObject* handle =(TBaseObject*)GetWorkScene();
    if(handle!=0 && X!=0){
        handle->setPositionX(X);
    }
}

void ProxyScreenPositionYEvent(const std::string& message)
{
    int command,Y;
    std::istringstream messagebuffer(message);
    messagebuffer>>command>>Y;
    TBaseObject* handle =(TBaseObject*)GetWorkScene();
    if(handle!=0 && Y!=0){
        handle->setPositionY(Y);
    }
}

void ProcessEditorMessage(const std::string& message,const int command)
{
    switch(command)
    {
        case SYS_STOPRENDER:
            ProxyStopRender(message);
            break;
        case SYS_SWITCHFPS:
            ProxySwitchFPS(message);
            break;
        case SYS_KEYPRESSEVENT:
            ProxyKeyPressEvent(message);
            break;
        case SYS_KEYRELEASEEVENT:
            ProxyKeyReleaseEvent(message);
            break;
        case SYS_ENTEREVENT:
            ProxyLeaveEvent(message);
            break;
        case SYS_LEAVEEVENT:
            ProxyEnterEvent(message);
            break;
        case SYS_MOUSEDOUBLECLICKEVENT:
            ProxyMouseDoubleClickEvent(message);
            break;
        case SYS_MOUSEMOVEEVENT:
            ProxyMouseMoveEvent(message);
            break;
        case SYS_MOUSEPRESSEVENT:
            ProxyMousePressEvent(message);
            break;
        case SYS_MOUSERELEASEEVENT:
            ProxyMouseReleaseEvent(message);
            break;
        case SYS_MOVEEVENT:
            ProxyMoveEvent(message);
            break;
        case SYS_CANCEL:
            break;
        case SYS_PHONESCREENSCALE:
            ProxyScreenScaleEvent(message);
            break;
        case SYS_PHONESCREENSIZE:
            ProxyScreenSizeEvent(message);
            break;
        case SYS_PHONESCREENPOSITIONX:
            ProxyScreenPositionXEvent(message);
            break;
        case SYS_PHONESCREENPOSITIONY:
            ProxyScreenPositionYEvent(message);
            break;
        default:
            break;
    }
}
