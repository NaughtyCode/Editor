#ifndef TFILESELECTOR_H
#define TFILESELECTOR_H

#include "WxEditor.h"

class TFileSelector:public wxComboCtrl
{
public:
    TFileSelector();
    TFileSelector(wxWindow *parent,
    wxWindowID id = wxID_ANY,
    const wxString& value = wxEmptyString,
    const wxPoint& pos = wxDefaultPosition,
    const wxSize& size = wxDefaultSize,
    long style = 0,
    const wxValidator& validator = wxDefaultValidator,
    const wxString& name = wxComboBoxNameStr);
    virtual void OnButtonClick();
    virtual void DoSetPopupControl(wxComboPopup* WXUNUSED(popup));
private:
    void Init();
};


#endif