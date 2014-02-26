#include "TScriptInterface.h"

#include <Python.h>

void SCRIPT_API CreateParser(){
    Py_Initialize();
    printf("python %s\n",Py_GetVersion());
}

void SCRIPT_API ExecString(const char * code){
    
    
}

void SCRIPT_API ReleaseParser(){
    Py_Finalize();
}

