#include "TMainWindow.h"
#include "GlobalSetting.h"

TMainWindow::TMainWindow(QWidget *parent):
                        QMainWindow(parent),
                        ui(new Ui::MainWindow),
                        RenderBox(0),
                        PhoneSetting(0),
                        LeftPanel(0),
                        RightPanel(0),
                        BottomPanel(0)
{
    ui->setupUi(this);
    
    this->setIconSize(QSize(56,56));
    
    std::string rootpath = GetGameResourcePath(std::string(""));
    PathParser.GeneratePathInfo(rootpath);
    
    std::string filename="logo.ico";
    this->SetWindowIcon(QString(GetEditorResourcePath(filename).c_str()));
    this->SetWindowTitle("Editor");
    
    this->CreateRenderBox();
    
    this->CreateToolBar();
    
    this->CreateAllDockWidgets();
    
    QDesktopWidget *desktop=QApplication::desktop();
    int w=desktop->width();
    int h=desktop->height();
	this->move((w - this->width()) / 2, (h - this->height()) / 2);
}

TMainWindow::~TMainWindow(){
    if(PhoneSetting!=0)delete PhoneSetting;
    if(RenderBox!=0)delete RenderBox;
    if(ui!=0)delete ui;
    exit(0);
}

TRenderBox* TMainWindow::GetRenderWindow() const{
    return RenderBox;
}

void TMainWindow::resizeEvent(QResizeEvent * event){
}

void TMainWindow::closeEvent(QCloseEvent *event)
{
    QMainWindow::closeEvent(event);
}

void TMainWindow::SetWindowIcon(const QString& filename){
    QPixmap pixmap(filename);
    QIcon icon(pixmap);
    QApplication::setWindowIcon(icon);
}

void TMainWindow::SetWindowTitle(const char* Title){
    HWND hWnd = (HWND)this->winId();
    if(hWnd){
        QString qtitle(Title);
        this->setWindowTitle(qtitle);
    }
}

void TMainWindow::CreateAllDockWidgets()
{
    LeftPanel = new TLeftPanel(tr("Resource Viewer"), this);
    LeftPanel->setAllowedAreas(Qt::LeftDockWidgetArea);
    this->addDockWidget(Qt::LeftDockWidgetArea,LeftPanel);
    
    LeftPanel->setMinimumWidth(200);
    LeftPanel->setMaximumWidth(3000);
    
    RightPanel = new TRightPanel(tr("Object Viewer"), this);
    RightPanel->setAllowedAreas(Qt::RightDockWidgetArea);
    this->addDockWidget(Qt::RightDockWidgetArea,RightPanel);
    
    RightPanel->setMinimumWidth(200);
    RightPanel->setMaximumWidth(3000);
    
    BottomPanel = new TBottomPanel(tr("Tool Viewer"), this);
    BottomPanel->setAllowedAreas(Qt::BottomDockWidgetArea);
    this->addDockWidget(Qt::BottomDockWidgetArea,BottomPanel);
    
    BottomPanel->setMinimumHeight(100);
    BottomPanel->setMaximumHeight(3000);
    
}

void TMainWindow::CreateToolBar()
{
    std::string filename;
    OpenAction = new QAction("Open", this);
    filename="Open.png";
    OpenAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(OpenAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    QToolBar *toolBar = addToolBar(tr("Open"));
    toolBar->addAction(OpenAction);
    
    SaveAction = new QAction("Save", this);
    filename="Save.png";
    SaveAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(SaveAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    toolBar->addAction(SaveAction);
    
    CopyAction = new QAction("Copy", this);
    filename="Copy.png";
    CopyAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(CopyAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    toolBar->addAction(CopyAction);
    
    CutAction = new QAction("Cut", this);
    filename="Cut.png";
    CutAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(CutAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    toolBar->addAction(CutAction);
    
    PlayAction = new QAction("Play", this);
    filename="Play.png";
    PlayAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(PlayAction, SIGNAL(triggered()), this, SLOT(StartRender()));
    toolBar->addAction(PlayAction);
    
    RestartAction = new QAction("Replay", this);
    filename="Replay.png";
    RestartAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(RestartAction, SIGNAL(triggered()), this, SLOT(RestartRender()));
    toolBar->addAction(RestartAction);
    
    StopAction = new QAction("Stop", this);
    filename="Stop.png";
    StopAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(StopAction, SIGNAL(triggered()), this, SLOT(StopRender()));
    toolBar->addAction(StopAction);
    
    ToolAction = new QAction("Tool", this);
    filename="Tool.png";
    ToolAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(ToolAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    toolBar->addAction(ToolAction);
    
    MobileAction = new QAction("Mobile", this);
    filename="Mobile.png";
    MobileAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(MobileAction, SIGNAL(triggered()), this, SLOT(ShowPhoneSetting()));
    toolBar->addAction(MobileAction);
    
    HelpAction = new QAction("Help", this);
    filename="Help.png";
    HelpAction->setIcon(QIcon(QString(GetEditorResourcePath(filename).c_str())));
    QObject::connect(HelpAction, SIGNAL(triggered()), this, SLOT(MessageProcess()));
    toolBar->addAction(HelpAction);
}

void TMainWindow::CreateRenderBox()
{
    RenderBox = new TRenderBox((TRenderBox *)ui->centralwidget);
    RenderBox->setAttribute(Qt::WA_UpdatesDisabled, true);
    RenderBox->resize(1920,1080);
    RenderBox->move(0,0);
}

void TMainWindow::StartRender(){
    RenderBox->StartRender();
}

void TMainWindow::StopRender(){
    RenderBox->StopRender();
}

void TMainWindow::RestartRender(){
    RenderBox->RestartRender();
}

void TMainWindow::ClearRenderBox()
{
    RenderBox->ClearRenderBox();
}

void TMainWindow::MessageProcess(){
}

void TMainWindow::ShowPhoneSetting()
{
    if(PhoneSetting==0){
        PhoneSetting = new TPhoneSetting;
    }
    PhoneSetting->show();
}
