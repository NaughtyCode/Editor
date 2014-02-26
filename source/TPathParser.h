#ifndef TPATHPARSER_H
#define TPATHPARSER_H

#include "ControlHeaders.h"

class TPathParser
{
public:
    TPathParser();
    virtual ~TPathParser();
    void GeneratePathInfo(const std::string& rootpath);
    void DumpFilePathName();
    
private:
    const char* GetBoolText(bool b);
    TVectorString ResourcePathData;
};

#endif