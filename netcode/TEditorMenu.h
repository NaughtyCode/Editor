#ifndef TEDITORMENU_H
#define TEDITORMENU_H

#include "TFrame.h"

class TFrame;

class TEditorMenu
{
public:
    TEditorMenu(TFrame* parent);
    ~TEditorMenu();
    
private:
    TFrame*         MenuParent;
    wxMenu*         FileMenu;
    wxMenu*         HelpMenu;
    wxMenuBar*      MenuBar;
};

#endif
