#ifndef PROXYGLOBALDATA_H
#define PROXYGLOBALDATA_H

#include "ProxyHeaders.h"
#include"AgreementInterfaceDef.h"
#include "ProxyRenderdef.h"

void ResetAllGlobalData();

void SetFilePath(const std::string& path);

ObjectHandle GetWorkScene();
void SetWorkScene(ObjectHandle workscene);

ObjectHandle GetRootScene();
void SetRootScene(ObjectHandle workscene);

ObjectHandle GetSelectedObject();
void SetSelectedObject(ObjectHandle obj);

bool IsCapture();
void SetCapture(bool capture);

void GetMousePos(float& x,float& y);

void GetDeltaMousePos(float& x,float& y);

float GetMouseX();

float GetMouseY();

void SetMousePos(float x,float y);

FAdapterPushEngineMessageType GetPushEngineMessage();
void SetPushEngineMessage(FAdapterPushEngineMessageType callback);

void PushEngineMessage(int key,const char* message);

#endif