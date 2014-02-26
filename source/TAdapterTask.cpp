#include "TAdapterTask.h"
#include "TAdapterManager.h"
#include "ControlMain.h"

static boost::thread_group GroupThread;

static TMessageContainer EditorMessageContainer;
static TMessageContainer EngineMessageContainer;

boost::thread_group & GetGroupThread()
{
    return GroupThread;
}

void PushEditorMessage(int key,const std::string& message)
{
    EditorMessageContainer.PushMessage(key,message);
}

TMessageContainer& GetEditorMessageContainer()
{
    return EditorMessageContainer;
}

TMessageContainer& GetEngineMessageContainer()
{
    return EngineMessageContainer;
}
