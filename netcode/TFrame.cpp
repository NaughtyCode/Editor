#include "TFrame.h"
#include "WxEditor.h"

const int ID_TOOLBAR = 500;

static const long TOOLBAR_STYLE = wxTB_FLAT | wxTB_DOCKABLE | wxTB_TEXT;

enum
{
    
    IDM_VIEW_TOOLBARSHOW = 200,
    
    //�ļ��˵���
    IDM_FILE_SAVE,
    IDM_FILE_OPEN,
    
    //�༭�˵���
    IDM_EDIT_UNDO,
    IDM_EDIT_COPY,
    IDM_EDIT_PASTE,
    IDM_EDIT_CUT,
    IDM_EDIT_DELETE,
    
    //��ͼ�˵���
    IDM_VIEWMENU_CALLBACK1,
    IDM_VIEWMENU_CALLBACK2,
    IDM_VIEWMENU_CALLBACK3,
    IDM_VIEW_COLOUR,
    IDM_VIEWMENU_STOPRENDER,
    IDM_VIEWMENU_STARTRENDER,
    IDM_VIEWMENU_CHANGERESOLUTION,
    IDM_VIEWMENU_PROPERTY,
    IDM_TOOLBAR_OTHER_1,
    IDM_TOOLBAR_OTHER_2,
    IDM_TOOLBAR_OTHER_3,
    
    // ���߲˵���
    IDM_TOOLMENU_CREATEMAP,
    IDM_TOOLMENU_CHANGELIGHT,
    IDM_TOOLMENU_CALLBACK1,
    IDM_TOOLMENU_CALLBACK2,
    IDM_TOOLMENU_CALLBACK3,
    IDM_TOOLMENU_CALLBACK4,
    IDM_TOOLMENU_CALLBACK5,
    IDM_TOOLMENU_CALLBACK6,
    IDM_TOOLMENU_CALLBACK7,

    ID_COMBO = 1000
};

BEGIN_EVENT_TABLE(TFrame, wxFrame)
    EVT_SIZE(TFrame::OnSize)
	EVT_CLOSE(TFrame::OnClose)
    
    EVT_MENU(IDM_FILE_OPEN, TFrame::OnFileOpen)
    EVT_MENU(IDM_FILE_SAVE, TFrame::OnFileSave)
    EVT_MENU(wxID_EXIT, TFrame::OnQuit)
    
    EVT_MENU(IDM_EDIT_UNDO,   TFrame::OnUndo)
    EVT_MENU(IDM_EDIT_COPY,   TFrame::OnCopy)
    EVT_MENU(IDM_EDIT_PASTE,  TFrame::OnPaste)
    EVT_MENU(IDM_EDIT_CUT,    TFrame::OnCut)
    EVT_MENU(IDM_EDIT_DELETE, TFrame::OnDelete)
    
    EVT_MENU(wxID_HELP, TFrame::OnAbout)
    EVT_MENU(IDM_VIEW_TOOLBARSHOW, TFrame::OnShowToolbar)
    
    EVT_MENU_RANGE(IDM_VIEWMENU_STOPRENDER, IDM_VIEWMENU_PROPERTY, TFrame::OnStopRender)
    
    
    EVT_MENU(IDM_TOOLMENU_CREATEMAP, TFrame::OnCreateMap)
    EVT_MENU(IDM_TOOLMENU_CHANGELIGHT, TFrame::OnDeletePrint)
    EVT_MENU(IDM_TOOLMENU_CALLBACK1, TFrame::OnInsertPrint)
    EVT_MENU(IDM_TOOLMENU_CALLBACK2, TFrame::OnToggleHelp)
    EVT_MENU(IDM_TOOLMENU_CALLBACK3, TFrame::OnToggleSearch)
    EVT_MENU_RANGE(IDM_TOOLMENU_CALLBACK4, IDM_TOOLMENU_CALLBACK6,TFrame::OnToggleRadioBtn)
    EVT_MENU(IDM_TOOLMENU_CALLBACK7, TFrame::OnChangeToolTip)

    EVT_MENU_RANGE(IDM_VIEWMENU_CALLBACK1, IDM_VIEWMENU_CALLBACK3,TFrame::OnToolbarStyle)
    EVT_MENU(IDM_VIEW_COLOUR, TFrame::OnBackgroundColour)
    
    EVT_MENU(wxID_ANY, TFrame::OnToolLeftClick)

    EVT_COMBOBOX(ID_COMBO, TFrame::OnCombo)

    EVT_TOOL_RCLICKED(wxID_ANY, TFrame::OnToolRightClick)

    EVT_TOOL_DROPDOWN(wxID_ANY, TFrame::OnToolDropdown)
    
    EVT_UPDATE_UI(wxID_COPY, TFrame::OnUpdateCopyAndCut)
    EVT_UPDATE_UI(wxID_CUT, TFrame::OnUpdateCopyAndCut)

    EVT_UPDATE_UI_RANGE(IDM_TOOLMENU_CALLBACK4,IDM_TOOLMENU_CALLBACK6,TFrame::OnUpdateToggleRadioBtn)
END_EVENT_TABLE()

void TFrame::RecreateToolbar()
{
    wxToolBarBase *toolBar = GetToolBar();
    long style = toolBar ? toolBar->GetWindowStyle() : TOOLBAR_STYLE;

    if (toolBar && m_searchTool && m_searchTool->GetToolBar() == NULL)
    {
        toolBar->AddTool(m_searchTool);
    }
    m_searchTool = NULL;

    delete toolBar;

    SetToolBar(NULL);

    style &= ~(wxTB_HORIZONTAL | wxTB_VERTICAL | wxTB_BOTTOM | wxTB_RIGHT | wxTB_HORZ_LAYOUT);
    switch( m_toolbarPosition )
    {
        case TOOLBAR_LEFT:
            style |= wxTB_LEFT;
            break;
        case TOOLBAR_TOP:
            style |= wxTB_TOP;
            break;
        case TOOLBAR_RIGHT:
            style |= wxTB_RIGHT;
            break;
        case TOOLBAR_BOTTOM:
        style |= wxTB_BOTTOM;
        break;
    }

    if ( m_showTooltips )
        style &= ~wxTB_NO_TOOLTIPS;
    else
        style |= wxTB_NO_TOOLTIPS;

    if ( style & wxTB_TEXT && !(style & wxTB_NOICONS) && m_horzText )
        style |= wxTB_HORZ_LAYOUT;

    toolBar = CreateToolBar(style, ID_TOOLBAR);
    PopulateToolbar(toolBar);
}

void TFrame::PopulateToolbar(wxToolBarBase* toolBar)
{
    int w = 64;
    int h = 64;
    
    toolBar->SetToolBitmapSize(wxSize(w, h));
    
    wxBitmap NEW(wxT("Resource\\Editor\\New.png"), wxBITMAP_TYPE_PNG);
    wxBitmap NEWEX(NEW.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_NEW, wxT("�½�"), NEWEX);
    
    wxBitmap OPEN(wxT("Resource\\Editor\\Open.png"), wxBITMAP_TYPE_PNG);
    wxBitmap OPENEX(OPEN.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_OPEN,  wxT("��"),   OPENEX);
    
    wxBitmap SAVE(wxT("Resource\\Editor\\Save.png"), wxBITMAP_TYPE_PNG);
    wxBitmap SAVEEX(SAVE.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_SAVE,  wxT("����"),   SAVEEX);
    
    wxBitmap COPY(wxT("Resource\\Editor\\Copy.png"), wxBITMAP_TYPE_PNG);
    wxBitmap COPYEX(COPY.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_COPY,  wxT("����"),   COPYEX);
    
    wxBitmap CUT(wxT("Resource\\Editor\\Cut.png"), wxBITMAP_TYPE_PNG);
    wxBitmap CUTEX(CUT.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_CUT,   wxT("����"),   CUTEX);
    
    wxBitmap PASTE(wxT("Resource\\Editor\\Paint.png"), wxBITMAP_TYPE_PNG);
    wxBitmap PASTEEX(PASTE.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_PASTE, wxT("ճ��"),   PASTEEX);
    
    wxBitmap PRINT(wxT("Resource\\Editor\\tool.png"), wxBITMAP_TYPE_PNG);
    wxBitmap PRINTEX(PRINT.ConvertToImage().Scale(w, h));
    toolBar->AddTool(wxID_PRINT, wxT("������"), PRINTEX);
	
    if ( !toolBar->IsVertical() )
    {
        wxComboBox *combo = new wxComboBox(toolBar, ID_COMBO, wxEmptyString, wxDefaultPosition, wxSize(100,-1) );
        combo->Append(wxT("Direct3D 9"));
        combo->Append(wxT("Direct3D 10"));
        combo->Append(wxT("Direct3D 11"));
        combo->Append(wxT("OpenGL 2.0"));
        combo->Append(wxT("OpenGL 3.2"));
        toolBar->AddControl(combo, wxT(""));
    }
    
    toolBar->Realize();
    toolBar->SetRows(toolBar->IsVertical() ? toolBar->GetToolsCount() / m_rows: m_rows);
}

TFrame::TFrame(wxFrame* parent,const wxString& title):wxFrame(parent,wxID_ANY,title,wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE|wxCLIP_CHILDREN|wxNO_FULL_REPAINT_ON_RESIZE)
{
    wxBoxSizer* mainsizer;
    mainsizer = new wxBoxSizer(wxVERTICAL);
    
    wxPanel* container = new wxPanel(this, wxID_ANY);
    
    container->SetSizer(mainsizer);
    
    m_smallToolbar = true;
    m_horzText = false;
    m_useCustomDisabled = false;
    m_showTooltips = true;
    m_searchTool = NULL;

    m_rows = 1;
    CreateStatusBar();
    
    wxIcon icon;
    icon.CopyFromBitmap(wxImage(wxT("Resource\\Editor\\Editor.ico")));
    this->SetIcon(icon);
    RenderSection = new TRenderSection((wxFrame *)container);
    RenderSection->SetSize(wxSize(1024,800));
    
    m_LogWin = new wxTextCtrl(container, 105, wxEmptyString, wxPoint(0, 900), wxSize(600, 60), wxTE_MULTILINE);
    wxLogTextCtrl* logger = new wxLogTextCtrl(m_LogWin);
    m_LogOld = logger->SetActiveTarget(logger);
    logger->DisableTimestamp();
    
    wxMenu *FileMenu = new wxMenu;
    FileMenu->Append(IDM_FILE_OPEN, wxT("��\tCtrl-O"));
    FileMenu->Append(IDM_FILE_SAVE,wxT("&����\tCtrl-S"),wxT("����"));
    FileMenu->AppendSeparator();
    FileMenu->Append(wxID_EXIT, wxT("�˳�"), wxT("�˳��༭��") );
    
    wxMenu *EditMenu = new wxMenu;
    EditMenu->Append(IDM_EDIT_UNDO,   wxT("����\tCtrl-Z"));
    EditMenu->Append(IDM_EDIT_COPY,   wxT("����\tCtrl-C"));
    EditMenu->Append(IDM_EDIT_PASTE,  wxT("ճ��\tCtrl-P"));
    EditMenu->Append(IDM_EDIT_CUT,    wxT("����\tCtrl-X"));
    EditMenu->Append(IDM_EDIT_DELETE, wxT("ɾ��\tCtrl-D"));
    
    wxMenu *ViewMenu = new wxMenu;
    ViewMenu->AppendSeparator();
    ViewMenu->AppendCheckItem(IDM_VIEW_TOOLBARSHOW, wxT("��ʾ������"));
    ViewMenu->Append(IDM_VIEW_COLOUR,               wxT("ѡ�񱳾���ɫ"));
    ViewMenu->Append(IDM_VIEWMENU_STARTRENDER,      wxT("�������"));
    ViewMenu->Append(IDM_VIEWMENU_STOPRENDER,       wxT("ֹͣ��Ⱦ"));
    ViewMenu->Append(IDM_VIEWMENU_CHANGERESOLUTION, wxT("�޸ķֱ���"));
    ViewMenu->Append(IDM_VIEWMENU_PROPERTY,         wxT("��������"));
    ViewMenu->Append(IDM_VIEWMENU_CALLBACK1,        wxT("��ͼ�����˵�"));
    ViewMenu->Append(IDM_VIEWMENU_CALLBACK2,        wxT("��ͼ�����˵�"));
    ViewMenu->Append(IDM_VIEWMENU_CALLBACK3,        wxT("��ͼ�����˵�"));
    ViewMenu->AppendSeparator();
    
    wxMenu *ToolMenu = new wxMenu;
    ToolMenu->AppendSeparator();
    ToolMenu->Append(IDM_TOOLMENU_CREATEMAP,   wxT("&������ͼ"));
    ToolMenu->Append(IDM_TOOLMENU_CHANGELIGHT, wxT("&�޸Ĺ���"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK1,   wxT("���߱����˵�"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK2,   wxT("���߱����˵�"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK3,   wxT("���߱����˵�"));
    ToolMenu->AppendSeparator();
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK4,   wxT("���߱����˵�"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK5,   wxT("���߱����˵�"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK6,   wxT("���߱����˵�"));
    ToolMenu->Append(IDM_TOOLMENU_CALLBACK7,   wxT("���߱����˵�"));
    ToolMenu->AppendSeparator();
    
    wxMenu* HelpMenu = new wxMenu;
    HelpMenu->Append(wxID_HELP, wxT("&����"),  wxT("��Ϸ�༭����Ϣ"));
    
    wxMenuBar* menuBar = new wxMenuBar(wxMB_DOCKABLE);
    menuBar->Append(FileMenu, wxT("&�ļ�"));
    menuBar->Append(EditMenu, wxT("&�༭"));
    menuBar->Append(ViewMenu, wxT("&��ͼ"));
    menuBar->Append(ToolMenu, wxT("&����"));
    menuBar->Append(HelpMenu, wxT("&����"));
    
    this->SetMenuBar(menuBar);
    m_toolbarPosition = TOOLBAR_TOP;
    RecreateToolbar();
    mainsizer->Add(RenderSection,9, wxEXPAND,3);
    mainsizer->Add(m_LogWin, 1, wxEXPAND,3);
    
    this->SetSize(1440,900);
    this->Fit();
    this->Center();
}

TFrame::~TFrame()
{
    if ( m_searchTool && !m_searchTool->GetToolBar() )
    {
        GetToolBar()->AddTool(m_searchTool);
    }
}

void TFrame::LayoutChildren()
{
}

void TFrame::OnSize(wxSizeEvent& event)
{
    event.Skip();
    int dummycommand=0;
    SendEditorCommand(&dummycommand,sizeof(int));
}

void TFrame::OnShowToolbar(wxCommandEvent& WXUNUSED(event))
{
    wxToolBar *tbar = GetToolBar();
    if (!tbar ){
        RecreateToolbar();
    }
    else{
        delete tbar;
    }
    printf("OnShowToolbar\n");
}

void TFrame::OnFileSave(wxCommandEvent& WXUNUSED(event))
{
    printf("����\n");
}

void TFrame::OnCreateMap(wxCommandEvent& event)
{
    int Buffer[2]={1,(int)RenderSection->GetHWND()};
    SendEditorCommand((void*)Buffer,sizeof(int)*2);
}

void TFrame::OnStopRender(wxCommandEvent& event)
{
    int Buffer=2;
    SendEditorCommand(&Buffer,sizeof(int));
}

void TFrame::OnQuit(wxCommandEvent& WXUNUSED(event))
{
    Close(true);
}

void TFrame::OnAbout(wxCommandEvent& event)
{
    (void)wxMessageBox(wxT("3D��Ϸ�༭��"), wxT("����"));
}

void TFrame::OnToolLeftClick(wxCommandEvent& event)
{
    
}

void TFrame::OnToolRightClick(wxCommandEvent& event)
{
}

void TFrame::OnCombo(wxCommandEvent& event)
{
    wxLogStatus(wxT("��Ⱦ����:%s"), event.GetString().c_str());
}

void TFrame::DoEnablePrint()
{
}

void TFrame::DoDeletePrint()
{
}

void TFrame::DoToggleHelp()
{
    
}

void TFrame::OnToggleSearch(wxCommandEvent& WXUNUSED(event))
{
    printf("OnToggleSearch\n");
}

void TFrame::OnUpdateCopyAndCut(wxUpdateUIEvent& event)
{
}

void TFrame::OnUpdateToggleHorzText(wxUpdateUIEvent& event)
{
    printf("OnUpdateToggleHorzText\n");
}

void TFrame::OnChangeToolTip(wxCommandEvent& WXUNUSED(event))
{
    GetToolBar()->SetToolShortHelp(wxID_NEW, wxT("New toolbar button"));
}

void TFrame::OnToolbarStyle(wxCommandEvent& event)
{
    printf("OnToolbarStyle\n");
}

void TFrame::OnBackgroundColour(wxCommandEvent& WXUNUSED(event))
{
    wxColour col = wxGetColourFromUser(this,GetToolBar()->GetBackgroundColour(),"ѡ�񱳾���ɫ");
}

void TFrame::OnFileOpen(wxCommandEvent& WXUNUSED(event))
{
    m_pathBmp = wxLoadFileSelector("Editor File", "");
}

void TFrame::OnInsertPrint(wxCommandEvent& WXUNUSED(event))
{
}

void TFrame::OnToggleRadioBtn(wxCommandEvent& event)
{
    printf("OnToggleRadioBtn\n");
}

void TFrame::OnToolDropdown(wxCommandEvent& event)
{
    event.Skip();
}

//�༭���˵��ص�
void TFrame::OnUndo(wxCommandEvent& event)
{
    printf("OnUndo\n");
}

void TFrame::OnCopy(wxCommandEvent& event)
{
    printf("OnCopy\n");
}

void TFrame::OnPaste(wxCommandEvent& event)
{
    printf("OnPaste\n");
}

void TFrame::OnCut(wxCommandEvent& event)
{
    printf("OnCut\n");
}

void TFrame::OnDelete(wxCommandEvent& event)
{
    printf("OnDelete\n");
}

void TFrame::OnClose(wxCloseEvent& event)
{
    printf("Send Quit Message!!!\n");
    int Buffer=5;
    SendEditorCommand(&Buffer,sizeof(int));
    wxFrame::OnCloseWindow(event);
}
