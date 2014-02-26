#ifndef  TSCRIPTINTERFACE_H
#define  TSCRIPTINTERFACE_H

#include "ScriptHeaders.h"

void SCRIPT_API CreateParser();
void SCRIPT_API ExecString(const char * code);
void SCRIPT_API ReleaseParser();

#endif