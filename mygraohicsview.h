#ifndef MYGRAOHICSVIEW_H
#define MYGRAOHICSVIEW_H

#include<QGraphicsView>
class MyGraohicsView : public QGraphicsView
{
    Q_OBJECT
protected:
    void mouseMoveEvent(QMouseEvent *event)Q_DECL_OVERRIDE;//鼠标移动事件
    void mousePressEvent(QMouseEvent *event)Q_DECL_OVERRIDE;//鼠标摁住
    void mouseDoubleClickEvent(QMouseEvent *event)Q_DECL_OVERRIDE;//鼠标双击
    void keyPressEvent(QKeyEvent *event)Q_DECL_OVERRIDE;//按键事件
    void resizeEvent(QResizeEvent *event)Q_DECL_OVERRIDE;//窗口重绘
public:
    explicit MyGraohicsView(QWidget *parent = nullptr);

signals:
    void mouseMovePoint(QPoint point);
    void mouseDoubleClick(QPoint point);
    void keyPress(QKeyEvent*event);
    void mouseClicked(QPoint point);
    void viewResize(QResizeEvent*event);

public slots:
};

#endif // MYGRAOHICSVIEW_H
