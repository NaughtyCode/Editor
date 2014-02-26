#include "TRenderSection.h"

TRenderSection::TRenderSection(const wxFrame* parent) :wxPanel((wxPanel*)parent)
{
    
}

TRenderSection::~TRenderSection()
{
    
}

void TRenderSection::OnSize(wxSizeEvent& event)
{
    
}

void TRenderSection::OnSizing(wxSizeEvent& event)
{
    
}

void TRenderSection::OnIdle( wxIdleEvent& event)
{
    
}

void TRenderSection::KeyDown(wxKeyEvent& event)
{
	printf("%d\n", event.GetKeyCode());
}

void TRenderSection::KeyUp(wxKeyEvent& event)
{
    
}

void TRenderSection::LeftDown(wxMouseEvent& event)
{
    printf("LeftDown\n");
}

void TRenderSection::LeftUp(wxMouseEvent& event)
{
    int buff=3;
    SendEditorCommand(&buff,sizeof(int));
}

void TRenderSection::MiddleDown(wxMouseEvent& event)
{
    
}

void TRenderSection::MiddleUp(wxMouseEvent& event)
{
    
}

void TRenderSection::RightDown(wxMouseEvent& event)
{
    
}

void TRenderSection::RightUp(wxMouseEvent& event)
{
    
}

void TRenderSection::RightDoubleClick(wxMouseEvent& event)
{
    
}

void TRenderSection::MiddleDoubleClick(wxMouseEvent& event)
{
    
}

void TRenderSection::LeftDoubleClick(wxMouseEvent& event)
{
    
}

void TRenderSection::Leave(wxMouseEvent& event)
{
	int dummycommand=0;
	SendEditorCommand(&dummycommand,sizeof(int));
}

void TRenderSection::Enter(wxMouseEvent& event)
{
	int dummycommand=0;
	SendEditorCommand(&dummycommand,sizeof(int));
}

void TRenderSection::MouseWheel(wxMouseEvent& event)
{
    printf("MouseWheel\n");
}

BEGIN_EVENT_TABLE(TRenderSection,wxPanel)
    EVT_IDLE(TRenderSection::OnIdle)
    EVT_SIZE(TRenderSection::OnSize)
    EVT_SIZING(TRenderSection::OnSizing)
    
    //keyboard event
    EVT_KEY_DOWN(TRenderSection::KeyDown)
    EVT_KEY_UP(TRenderSection::KeyUp)
    
    //mouse event
    EVT_LEFT_DOWN(TRenderSection::LeftDown) 
    EVT_LEFT_UP(TRenderSection::LeftUp)
    EVT_MIDDLE_DOWN(TRenderSection::MiddleDown)
    EVT_MIDDLE_UP(TRenderSection::MiddleUp)  
    EVT_RIGHT_DOWN(TRenderSection::RightDown)  
    EVT_RIGHT_UP(TRenderSection::RightUp) 
    EVT_LEFT_DCLICK(TRenderSection::LeftDoubleClick)   
    EVT_MIDDLE_DCLICK(TRenderSection::MiddleDoubleClick)
    EVT_RIGHT_DCLICK(TRenderSection::RightDoubleClick)   
    EVT_LEAVE_WINDOW(TRenderSection::Leave)   
    EVT_ENTER_WINDOW(TRenderSection::Enter)   
    EVT_MOUSEWHEEL(TRenderSection::MouseWheel)
    
END_EVENT_TABLE()
