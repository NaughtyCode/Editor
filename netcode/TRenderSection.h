#ifndef TRENDERSECTION_H
#define TRENDERSECTION_H

#include "WxEditor.h"

class TRenderSection : public wxPanel
{
public:
    TRenderSection(const wxFrame* parent);
    ~TRenderSection();
    void OnSize(wxSizeEvent& event);
    void OnSizing(wxSizeEvent& event);
    void OnIdle( wxIdleEvent& event);
    
    //keyboard event
    void KeyDown(wxKeyEvent& event);
    void KeyUp(wxKeyEvent& event);
    
    //mouse event
    void LeftDown(wxMouseEvent& event);
    void LeftUp(wxMouseEvent& event);
    void MiddleDown(wxMouseEvent& event);
    void MiddleUp(wxMouseEvent& event);
    void RightDown(wxMouseEvent& event);
    void RightUp(wxMouseEvent& event);
    void RightDoubleClick(wxMouseEvent& event);
    void MiddleDoubleClick(wxMouseEvent& event);
    void LeftDoubleClick(wxMouseEvent& event);
    void Leave(wxMouseEvent& event);
    void Enter(wxMouseEvent& event);
    void MouseWheel(wxMouseEvent& event);
    
private:
    DECLARE_EVENT_TABLE()
};

#endif