#include "TLeftPanel.h"

TLeftPanel::TLeftPanel(const QString& title, QWidget* parent):QDockWidget(title,parent)
{
    
}

TLeftPanel::~TLeftPanel()
{
    
}

void TLeftPanel::closeEvent(QCloseEvent * event)
{
    printf("TLeftPanel::closeEvent\n");
}