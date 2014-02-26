#include "TBottomPanel.h"

TBottomPanel::TBottomPanel(const QString& title, QWidget* parent):QDockWidget(title,parent)
{
    
}

TBottomPanel::~TBottomPanel()
{
    
}

void TBottomPanel::closeEvent(QCloseEvent * event)
{
    printf("TBottomPanel::closeEvent\n");
}