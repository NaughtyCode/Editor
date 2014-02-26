#ifndef EDITORSERVER
#define EDITORSERVER

#ifdef EDITORNET_EXPORTS
#define EDITORNETAPI __declspec(dllexport) 
#else
#define EDITORNETAPI __declspec(dllimport) 
#endif

#include <iostream>
#include <cassert>

EDITORNETAPI int SendEditorCommand(void* buffer,int size);
EDITORNETAPI int ReceiveEditorCommand(void* buffer,int size);

#endif
