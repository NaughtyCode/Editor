#ifndef TBOTTOMPANEL_H
#define TBOTTOMPANEL_H

#include "ControlHeaders.h"

class TBottomPanel:public QDockWidget
{
public:
    TBottomPanel(const QString& title, QWidget* parent);
    virtual ~TBottomPanel();
    void closeEvent(QCloseEvent * event);
    
private:
    
};

#endif