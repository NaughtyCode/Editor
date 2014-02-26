#include "TFileSelector.h"

TFileSelector::TFileSelector():wxComboCtrl()
{
    Init();
}

TFileSelector::TFileSelector(wxWindow *parent,
                wxWindowID id,
                const wxString& value,
                const wxPoint& pos,
                const wxSize& size,
                long style,
                const wxValidator& validator,
                const wxString& name):wxComboCtrl()
{
    this->Init();
    this->Create(parent,id,value,pos,size,style | wxCC_STD_BUTTON,validator,name);
    wxMemoryDC dc;
    wxBitmap bmp(12,16);
    dc.SelectObject(bmp);
    wxColour magic(255,0,255);
    wxBrush magicBrush(magic);
    dc.SetBrush( magicBrush );
    dc.SetPen( *wxTRANSPARENT_PEN );
    dc.DrawRectangle(0,0,bmp.GetWidth(),bmp.GetHeight());
    wxString str = wxT("dummy");
    int w,h;
    dc.GetTextExtent(str, &w, &h, 0, 0);
    dc.DrawText(str, (bmp.GetWidth()-w)/2, (bmp.GetHeight()-h)/2);
    dc.SelectObject( wxNullBitmap );
    wxMask *mask = new wxMask( bmp, magic );
    bmp.SetMask( mask );
    this->SetButtonBitmaps(bmp,true);
}

void TFileSelector::OnButtonClick()
{
    wxFileDialog dlg(this,wxT("选择文件"),wxEmptyString,this->GetValue(),wxT("所有文件 (*.*)|*.*"),wxFD_OPEN);
    if(dlg.ShowModal()==wxID_OK){
        this->SetValue(dlg.GetPath());
    }
}

void TFileSelector::DoSetPopupControl(wxComboPopup* WXUNUSED(popup)){
    
}

void TFileSelector::Init(){
    
}
