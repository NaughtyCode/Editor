#include "TAdapterManager.h"
#include "ControlMain.h"

void TMessageContainer::PushMessage(const int key,const std::string& message)
{
    Mutex.lock();
    Data[key] = message;
    Mutex.unlock();
}

void TMessageContainer::PopMessage(const int key,std::string& message)
{
    Mutex.lock();
    StringMap_t::iterator it;
    it = Data.find(key);
    if(it!=Data.end()){
        message=it->second;
        Data.erase(key);
    }else{
        message="";
    }
    Mutex.unlock();
}
