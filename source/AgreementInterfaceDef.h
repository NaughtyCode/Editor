#ifndef AGREEMENTINTERFACEDEF_H
#define AGREEMENTINTERFACEDEF_H

#include<string>


void typedef (*FEditorMessageProcessorType)(const std::string& message);
void typedef (*FPushEditorMessageType)(const std::string& message);

void typedef (*FEditorMessageProcessorType)(const std::string& message);
void typedef (*FProxyStartRenderType)(const std::string& message);
void typedef (*FEngineRenderInnerCallBackType)();

void typedef (*FAdapterProcessEditorMessageType)();
void typedef (*FAdapterPushEditorMessageType)(int key,const std::string& message);
void typedef (*FAdapterProcessEngineMessageType)();
void typedef (*FAdapterPushEngineMessageType)(int key,const char* message);
void typedef (*FAdapterProxyStartRenderType)(const std::string& message);


const char * GetProxyName();
const char * GetAdapterName();

const char * GetEditorEditorMessageProcessorName();
const char * GetEditorPushEditorMessageName();

const char * GetProxyEditorMessageProcessorName();
const char * GetProxyProxyStartRenderName();
const char * GetProxyEngineRenderInnerCallBackName();

const char * GetProxyAdapterProcessEditorMessageName();
const char * GetAdapterPushEditorMessageName();
const char * GetAdapterProcessEngineMessageName();
const char * GetAdapterPushEngineMessageName();
const char * GetAdapterProxyStartRenderName();

#endif