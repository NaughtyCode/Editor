#include "TEditorMenu.h"


TEditorMenu::TEditorMenu(TFrame* parent):
                    MenuParent(parent),
                    FileMenu(0),
                    HelpMenu(0),
                    MenuBar(0)
{
    FileMenu = new wxMenu;
    FileMenu->Append(TFRAME_COMPARE, wxT("&创建"),wxT("创建新项目"));
    FileMenu->AppendSeparator();
    FileMenu->Append(TFRAME_QUIT, wxT("退出\tAlt-X"), wxT("退出"));
    
    HelpMenu = new wxMenu;
    HelpMenu->Append(TFRAME_ABOUT, wxT("&关于\tF1"), wxT("关于对话框"));
    
    MenuBar = new wxMenuBar();
    MenuBar->Append(FileMenu, wxT("&文件"));
    MenuBar->Append(HelpMenu, wxT("&帮助"));
    MenuParent->SetMenuBar(MenuBar);
}

TEditorMenu::~TEditorMenu()
{
    
}
