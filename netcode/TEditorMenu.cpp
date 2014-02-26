#include "TEditorMenu.h"


TEditorMenu::TEditorMenu(TFrame* parent):
                    MenuParent(parent),
                    FileMenu(0),
                    HelpMenu(0),
                    MenuBar(0)
{
    FileMenu = new wxMenu;
    FileMenu->Append(TFRAME_COMPARE, wxT("&����"),wxT("��������Ŀ"));
    FileMenu->AppendSeparator();
    FileMenu->Append(TFRAME_QUIT, wxT("�˳�\tAlt-X"), wxT("�˳�"));
    
    HelpMenu = new wxMenu;
    HelpMenu->Append(TFRAME_ABOUT, wxT("&����\tF1"), wxT("���ڶԻ���"));
    
    MenuBar = new wxMenuBar();
    MenuBar->Append(FileMenu, wxT("&�ļ�"));
    MenuBar->Append(HelpMenu, wxT("&����"));
    MenuParent->SetMenuBar(MenuBar);
}

TEditorMenu::~TEditorMenu()
{
    
}
