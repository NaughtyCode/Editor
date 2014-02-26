#include "GlobalSetting.h"
#include "TMainWindow.h"
#include "ControlMain.h"

static TMainWindow* MainWindow=0;

void CreateControl()
{
    int argc=1;
    char* argv[]={"Editor"};
    QApplication Editor(argc, argv);
    std::string pathname("..\\resource\\editor\\");
    SetEditorResourcePath(pathname);
    pathname="..\\resource\\GameRes\\";
    SetGameResourcePath(pathname);
    if(MainWindow==0){
        MainWindow = new TMainWindow;
    }
    MainWindow->show();
    Editor.exec();
}

void ReleaseControl()
{
    
}

void EditorEngineMessageProcess(const char* message)
{
    std::string command(message);
    if(MainWindow==0 || command.size()<=0){return;}
    if(command==std::string("clearrenderbox")){
        MainWindow->ClearRenderBox();
    }
}
