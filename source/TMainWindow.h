#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "uimainframe.h"
#include "TRenderBox.h"
#include "TPhoneSetting.h"
#include "TPathParser.h"
#include "TLeftPanel.h"
#include "TRightPanel.h"
#include "TBottomPanel.h"

class TPhoneSetting;
class TRenderBox;
class TPathParser;
class TLeftPanel;
class TRightPanel;
class TBottomPanel;



class TMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TMainWindow(QWidget *parent = 0);
    ~TMainWindow();
    
public slots:
    void MessageProcess();
    void StartRender();
    void RestartRender();
    void StopRender();
    void ShowPhoneSetting();
    
public:
    void closeEvent(QCloseEvent *event);
    virtual void resizeEvent(QResizeEvent * event);
    void SetWindowIcon(const QString& filename);
    void SetWindowTitle(const char* Title);
    TRenderBox * GetRenderWindow() const;
    void CreateAllDockWidgets();
    void CreateToolBar();
    void CreateRenderBox();
    void ClearRenderBox();
    
private:
    QAction* OpenAction;
    QAction* CopyAction;
    QAction* CutAction;
    QAction* SaveAction;
    QAction* PlayAction;
    QAction* RestartAction;
    QAction* StopAction;
    QAction* ToolAction;
    QAction* MobileAction;
    QAction* HelpAction;
    
private:
    TLeftPanel*     LeftPanel;
    TRightPanel*    RightPanel;
    TBottomPanel*   BottomPanel;
    TRenderBox*     RenderBox;
    TPhoneSetting*  PhoneSetting;
    TPathParser     PathParser;
    
private:
    Ui::MainWindow* ui;
};

#endif
