#ifndef TLEFTPANEL_H
#define TLEFTPANEL_H

#include "ControlHeaders.h"

class TLeftPanel:public QDockWidget
{
public:
    TLeftPanel(const QString& title, QWidget* parent);
    virtual ~TLeftPanel();
    void closeEvent(QCloseEvent * event);
    
private:
    
};

#endif