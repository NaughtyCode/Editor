#ifndef TADAPTERMANAGER_H
#define TADAPTERMANAGER_H

#include "AdapterHeaders.h"

class TMessageContainer
{
public:
    boost::mutex Mutex;
    typedef std::map<int,std::string> StringMap_t;
    StringMap_t Data;
    
public:
    void PushMessage(const int key,const std::string& message);
    void PopMessage(const int key,std::string& message);
    
};

#endif