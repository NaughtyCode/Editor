#ifndef TRIGHTPANEL_H
#define TRIGHTPANEL_H

#include "ControlHeaders.h"

class TRightPanel:public QDockWidget
{
public:
    TRightPanel(const QString& title, QWidget* parent=0);
    virtual ~TRightPanel();
    void closeEvent(QCloseEvent * event);
    
private:
    
};

#endif