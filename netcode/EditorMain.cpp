#include "EditorMain.h"

using namespace tbb;
using namespace std;

class Editor{
public:
    Editor(){}
    void operator() () const{
        EnterWxEditor();
    }
};

class RenderWork{
private:
    char m_Buffer[BUFFERSIZE];
    int  m_Render;
    int  m_CommandHead;
    int  m_Handle;
    
public:
    RenderWork(){
        m_CommandHead=-1;
        memset(m_Buffer,0,BUFFERSIZE);
    }
    
    void GetCommandHeader(){
        memcpy(&m_CommandHead,m_Buffer,sizeof(int));
    }
    
    bool Render(){
        if (m_Render){
            if(RenderFrame())return true;
            else{
                return false;
            }
        }
        return true;
    }
    
    void operator()(){
        m_Render = 0;
        while(true){
            ReceiveEditorCommand(m_Buffer,BUFFERSIZE);
            GetCommandHeader();
            if(m_CommandHead==1 && m_Render==0){
                memcpy(&m_Handle,m_Buffer+sizeof(int),sizeof(int));
                CreateRender(m_Handle);
                m_Render=1;
            }
            if(m_CommandHead==2){
                DestroyRender();
                m_Render=0;
            }
            if(m_CommandHead==5){
                break;
            }
            this->Render();
        }
        DestroyRender();
    }
};

void ExecWorker() {
    task_group TaskGroup;
    TaskGroup.run(Editor());
    TaskGroup.run(RenderWork());
    TaskGroup.wait();
}

int main()
{
    ExecWorker();
    return 0;
}
