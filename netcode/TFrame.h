#ifndef TFRAME_H
#define TFRAME_H

#include "WxEditor.h"
#include "TRenderSection.h"
#include "TEditorMenu.h"

class TEditorMenu;
class TRenderSection;

enum Positions
{
    TOOLBAR_LEFT,
    TOOLBAR_TOP,
    TOOLBAR_RIGHT,
    TOOLBAR_BOTTOM
};

enum
{
    TFRAME_COMPARE = wxID_HIGHEST,
    TFRAME_QUIT    = wxID_EXIT,
    TFRAME_ABOUT   = wxID_ABOUT
};

class TFrame: public wxFrame
{
public:
    TFrame(wxFrame *parent,const wxString& title = wxT("游戏编辑器"));
    virtual ~TFrame();
    
    void PopulateToolbar(wxToolBarBase* toolBar);
    void RecreateToolbar();
    
    void OnFileOpen(wxCommandEvent& event);
    void OnFileSave(wxCommandEvent& event);
    void OnQuit(wxCommandEvent& event);
    
    void OnUndo(wxCommandEvent& event);
    void OnCopy(wxCommandEvent& event);
    void OnPaste(wxCommandEvent& event);
    void OnCut(wxCommandEvent& event);
    void OnDelete(wxCommandEvent& event);
    
    void OnAbout(wxCommandEvent& event);
    void OnSize(wxSizeEvent& event);
	void OnClose(wxCloseEvent& event);
    void OnShowToolbar(wxCommandEvent& event);
    void OnStopRender(wxCommandEvent& event);
    void OnCreateMap(wxCommandEvent& WXUNUSED(event));
    void OnDeletePrint(wxCommandEvent& WXUNUSED(event)){}
    void OnInsertPrint(wxCommandEvent& event);
    void OnChangeToolTip(wxCommandEvent& event);
    void OnToggleHelp(wxCommandEvent& WXUNUSED(event)) {}
    void OnToggleSearch(wxCommandEvent& event);
    void OnToggleRadioBtn(wxCommandEvent& event);
    void OnToolbarStyle(wxCommandEvent& event);
    void OnBackgroundColour(wxCommandEvent& event);
    void OnToolLeftClick(wxCommandEvent& event);
    void OnToolRightClick(wxCommandEvent& event);
    void OnToolDropdown(wxCommandEvent& event);
    void OnCombo(wxCommandEvent& event);
    void OnUpdateCopyAndCut(wxUpdateUIEvent& event);
    void OnUpdateToggleHorzText(wxUpdateUIEvent& event);
    void OnUpdateToggleRadioBtn(wxUpdateUIEvent& event){}
    
private:
    void DoEnablePrint();
    void DoDeletePrint();
    void DoToggleHelp();
    
    void LayoutChildren();

    bool                m_smallToolbar;
    bool                m_horzText;
    bool                m_useCustomDisabled;
    bool                m_showTooltips;
    size_t              m_rows;
    Positions           m_toolbarPosition;
    wxPanel*            m_panel;
    wxToolBar*          m_tbar;
    wxString            m_pathBmp;
    wxToolBarToolBase*  m_searchTool;
    TRenderSection* RenderSection;
    
    //日志记录
    wxTextCtrl*     m_LogWin;
    wxLog*          m_LogOld;
    
private:
    DECLARE_EVENT_TABLE()
};

#endif