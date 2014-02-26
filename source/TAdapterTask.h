#ifndef TADAPTERTASK_H
#define TADAPTERTASK_H

#include "AdapterHeaders.h"
#include "TAdapterManager.h"

void PushEditorMessage(int key,const std::string& message);
boost::thread_group& GetGroupThread();

TMessageContainer& GetEditorMessageContainer();
TMessageContainer& GetEngineMessageContainer();


#endif
