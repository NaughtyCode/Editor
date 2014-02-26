#ifndef WXEDITOR_H
#define WXEDITOR_H

#ifdef WUSEWXWIDGET

#include <wx/wxprec.h>
#include <wx/wx.h>
#include <wx/image.h>
#include <wx/combo.h>
#include <wx/odcombo.h>
#include <wx/frame.h>
#include <wx/listctrl.h>
#include <wx/treectrl.h>
#include <wx/toolbar.h>
#include <wx/log.h>
#include <wx/image.h>
#include <wx/filedlg.h>
#include <wx/colordlg.h>
#include <wx/srchctrl.h>
#include <wx/toolbar.h>
#include <wx/log.h>
#include <wx/filedlg.h>
#include <wx/colordlg.h>
#include <wx/srchctrl.h>

#endif

#ifdef WXEDITOR_EXPORTS
#define WXEDITORAPI __declspec(dllexport) 
#else
#define WXEDITORAPI __declspec(dllimport) 
#endif

#include "TEditorServer.h"

WXEDITORAPI void EnterWxEditor();

WXEDITORAPI int GetRenderBoxHandle();

#endif