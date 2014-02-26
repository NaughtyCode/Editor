#ifndef EDITORTOENGINEMESSAGE_H
#define EDITORTOENGINEMESSAGE_H

#include "ProxyRenderdef.h"

void ProcessEditorMessage(const std::string& message,const int command);

void ProxyStopRender(const std::string& message);
void ProxySwitchFPS(const std::string& message);

void ProxyKeyPressEvent(const std::string& message);
void ProxyKeyReleaseEvent(const std::string& message);
void ProxyLeaveEvent(const std::string& message);
void ProxyEnterEvent(const std::string& message);
void ProxyMouseDoubleClickEvent(const std::string& message);
void ProxyMouseMoveEvent(const std::string& message);
void ProxyMousePressEvent(const std::string& message);
void ProxyMouseReleaseEvent(const std::string& message);
void ProxyMoveEvent(const std::string& message);

void ProxyScreenScaleEvent(const std::string& message);
void ProxyScreenSizeEvent(const std::string& message);

void ProxyScreenPositionXEvent(const std::string& message);
void ProxyScreenPositionXEvent(const std::string& message);

#endif