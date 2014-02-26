#ifndef ADAPTER_H
#define ADAPTER_H

#include "AdapterHeaders.h"

void AdapterPushEditorMessage(int key,const std::string& message);
void AdapterProxyStartRender(const std::string& message);

#endif