#ifndef GLOBALSETTING_H
#define GLOBALSETTING_H

#include "ControlHeaders.h"

const std::string GetEditorResourcePath(const std::string& filename);

void SetEditorResourcePath(const std::string& pathname);

const std::string GetGameResourcePath(const std::string& filename);

void SetGameResourcePath(const std::string& pathname);

#endif