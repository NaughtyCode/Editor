#include "Adapter.h"
#include "ProxyInteractive.h"
#include "TAdapterManager.h"
#include "ControlMain.h"
#include "TAdapterTask.h"

static bool EngineMessageProcessFlag=true;

void LocalProcessEditorMessage(const std::string& message)
{
    ProxyEditorMessageProcessor(message);
}

void LocalEditorMessageProcessor()
{
    TMessageContainer& EditorMessageContainer = GetEditorMessageContainer();
    std::string message;
    EditorMessageContainer.PopMessage(0, message);
    if (message.size()){
        LocalProcessEditorMessage(message);
    }
}

void LocalPushEngineMessage(int key, const char* message)
{
    TMessageContainer& EngineMessageContainer = GetEngineMessageContainer();
    EngineMessageContainer.PushMessage(key, std::string(message));
}

void LocalEngineMessageProcess()
{
    TMessageContainer& EngineMessageContainer = GetEngineMessageContainer();
    std::string message;
    while(true){
        EngineMessageContainer.PopMessage(0,message);
        if(message.size()>0){
            EditorEngineMessageProcess(message.c_str());
        }
    }
}

void LocalStartEditorRender(const std::string& message)
{
    std::ostringstream newmessagebuffer;
    newmessagebuffer << message << " " << (int)&LocalEditorMessageProcessor << " " << (int)&LocalPushEngineMessage;
    ProxyStartRender(newmessagebuffer.str());
}

void AdapterProxyStartRender(const std::string& message)
{
    boost::thread_group& GroupThread = GetGroupThread();
    GroupThread.add_thread(new boost::thread(LocalStartEditorRender,message));
    if(EngineMessageProcessFlag){
        EngineMessageProcessFlag=false;
        GroupThread.add_thread(new boost::thread(LocalEngineMessageProcess));
    }
}

void AdapterPushEditorMessage(int key,const std::string& message)
{
    PushEditorMessage(key,message);
}
