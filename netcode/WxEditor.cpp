#include "WxEditor.h"
#include "TApp.h"


static wxAppInitializer wxTheAppInitializer((wxAppInitializerFunction)wxCreateApp);
static int WxEditorArgc = 1;
static wchar_t * WxEditorArgv[] = { L"WxEditor" };

static int RenderBoxHandle = 0;

WXEDITORAPI void EnterWxEditor()
{
    wxDISABLE_DEBUG_SUPPORT();
    wxEntry(WxEditorArgc,WxEditorArgv);
}

WXEDITORAPI int GetRenderBoxHandle()
{
    return RenderBoxHandle;
}
