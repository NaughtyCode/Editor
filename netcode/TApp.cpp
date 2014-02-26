#include "TApp.h"
#include "TFrame.h"

bool TApp::OnInit()
{
    if(wxApp::OnInit()){
	wxInitAllImageHandlers();
	TFrame* frame = new TFrame(0,wxT("��Ϸ�༭��"));
	frame->Show(true);
	frame->Center();
	frame->SetStatusText(wxT("״̬��"));
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
