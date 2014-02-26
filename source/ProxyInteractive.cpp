#include "AgreementInterfaceDef.h"
#include "ProxyMessage.h"
#include "ProxyInteractive.h"
#include "ProxyHeaders.h"
#include "TProxyApp.h"
#include "ProxyGlobalData.h"

class TProxyApp;

void PROXYAPI ProxyEditorMessageProcessor(const std::string& message){
    if(message.size()>0){
	std::istringstream messagebuffer(message);
	int command;
	messagebuffer>>command;
	if(command>0){
	    ProcessEditorMessage(message,command);
	}
    }
}

void PROXYAPI ProxyStartRender(const std::string& message)
{
    std::istringstream messagebuffer(message);
    int processeditormessagecallback,pushenginemessagecallback,handle,width,height;
    messagebuffer >> handle >> width >> height >> processeditormessagecallback >> pushenginemessagecallback;
    if (width <= 0 || height <= 0 || handle == 0 || processeditormessagecallback == 0 || pushenginemessagecallback == 0){
    }else{
	SetPushEngineMessage((FAdapterPushEngineMessageType)pushenginemessagecallback);
	TProxyApp app;
	cocos2d::EGLView View((HWND)handle);
	cocos2d::Director::getInstance()->SetExternelCallBack((FEngineRenderInnerCallBackType)processeditormessagecallback);
	View.init("Editor",(float)width,(float)height);
	cocos2d::Application::getInstance()->run();
    }
}
