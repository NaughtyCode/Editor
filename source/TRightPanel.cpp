#include "TRightPanel.h"

TRightPanel::TRightPanel(const QString& title, QWidget* parent) :QDockWidget(title,parent)
{
    
}

TRightPanel::~TRightPanel()
{
    
}

void TRightPanel::closeEvent(QCloseEvent * event)
{
    printf("TRightPanel::closeEvent\n");
}