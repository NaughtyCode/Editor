#include "TApp.h"
#include "TFrame.h"

bool TApp::OnInit()
{
    if(wxApp::OnInit()){
	wxInitAllImageHandlers();
	TFrame* frame = new TFrame(0,wxT("ÓÎÏ·±à¼­Æ÷"));
	frame->Show(true);
	frame->Center();
	frame->SetStatusText(wxT("×´Ì¬À¸"));
	return true;
    }
    return false;
}

TApp& wxGetApp()
{
    return *static_cast<TApp*>(wxApp::GetInstance());
}

wxAppConsole *wxCreateApp()
{
    wxAppConsole::CheckBuildOptions(WX_BUILD_OPTIONS_SIGNATURE,"EditorDLL");
    return new TApp;
}
