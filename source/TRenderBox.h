#ifndef RENDERBOX_H
#define RENDERBOX_H

#include "ControlHeaders.h"

class TRenderBox:public QWidget
{
public:
    TRenderBox(TRenderBox * parent);
    ~TRenderBox();
    void ClearRenderBox();
    void StartRender();
    void StopRender();
    void RestartRender();
    bool IsRender();
    
    void actionEvent(QActionEvent * event);
    void changeEvent(QEvent * event);
    void closeEvent(QCloseEvent * event);
    void contextMenuEvent(QContextMenuEvent * event);
    void dragEnterEvent(QDragEnterEvent * event);
    void dragLeaveEvent(QDragLeaveEvent * event);
    void dragMoveEvent(QDragMoveEvent * event);
    void dropEvent(QDropEvent * event);
    void enterEvent(QEvent * event);
    void focusInEvent(QFocusEvent * event);
    void focusOutEvent(QFocusEvent * event);
    void hideEvent(QHideEvent * event);
    void inputMethodEvent(QInputMethodEvent * event);
    void keyPressEvent(QKeyEvent * event);
    void keyReleaseEvent(QKeyEvent * event);
    void leaveEvent(QEvent * event);
    void mouseDoubleClickEvent(QMouseEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
    void mouseReleaseEvent(QMouseEvent * event);
    void moveEvent(QMoveEvent * event);
    bool nativeEvent(const QByteArray & eventType, void * message, long * result);
    void paintEvent(QPaintEvent * event);
    void resizeEvent(QResizeEvent * event);
    void showEvent(QShowEvent * event);
    void tabletEvent(QTabletEvent * event);
    void wheelEvent(QWheelEvent * event);
    
    void repaint(int x, int y, int w, int h);
    void repaint(const QRect &);
    void repaint(const QRegion &);
    
private:
    QCursor *Cursor;
    bool RenderFlag;
};

#endif