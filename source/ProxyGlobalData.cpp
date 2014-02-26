#include "ProxyGlobalData.h"
#include "ProxyRenderdef.h"

static FAdapterPushEngineMessageType  PushEngineMessageCallBack = 0;
static ObjectHandle                   WorkScene=0;
static ObjectHandle                   RootScene=0;
static ObjectHandle                   SelectedObject=0;
static bool                           IsCaptured=false;
static float                          MouseX=0;
static float                          MouseY=0;
static float                          DeltaMouseX=0;
static float                          DeltaMouseY=0;

void ResetAllGlobalData(){
    PushEngineMessageCallBack = 0;
    WorkScene=0;
    RootScene=0;
    SelectedObject=0;
    IsCaptured=false;
    MouseX=0;
    MouseY=0;
    DeltaMouseX=0;
    DeltaMouseY=0;
}

void SetFilePath(const std::string& path){
    std::vector<std::string> resourcepath;
    resourcepath.push_back(path);
    cocos2d::FileUtils::getInstance()->setSearchPaths(resourcepath);
}

ObjectHandle GetWorkScene(){
    return WorkScene;
}

void SetWorkScene(ObjectHandle workscene){
    WorkScene=workscene;
}

ObjectHandle GetRootScene(){
    return RootScene;
}

void SetRootScene(ObjectHandle rootscene){
    RootScene = rootscene;
}

ObjectHandle GetSelectedObject()
{
    return SelectedObject;
}

void SetSelectedObject(ObjectHandle obj)
{
    SelectedObject=obj;
}

bool IsCapture()
{
    return IsCaptured;
}

void SetCapture(bool capture)
{
    IsCaptured = capture;
}

void GetMousePos(float& x,float& y)
{
   x = MouseX;
   y = MouseY;
}

void GetDeltaMousePos(float& x,float& y){
    x = DeltaMouseX;
    y = DeltaMouseY;
}

void SetMousePos(float x,float y)
{
    DeltaMouseX = x-MouseX;
    DeltaMouseY = MouseY-y;
    MouseX = x;
    MouseY = y;
}

float GetMouseX()
{
   return MouseX;
}

float GetMouseY()
{
   return MouseY;
}

FAdapterPushEngineMessageType GetPushEngineMessage()
{
    return PushEngineMessageCallBack;
}

void SetPushEngineMessage(FAdapterPushEngineMessageType callback)
{
    PushEngineMessageCallBack=callback;
}

void PushEngineMessage(int key,const char* message)
{
    if(PushEngineMessageCallBack!=0){
        PushEngineMessageCallBack(key,message);
    }else{
        printf("调用引擎命令推送函数失败\n");
    }
}
