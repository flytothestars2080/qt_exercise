#include "mygraohicsview.h"
#include<QMouseEvent>


void MyGraohicsView::mouseMoveEvent(QMouseEvent *event)
{
//鼠标移动事件
    QPoint point=event->pos();//返回相对MyGraohicsView于的视图坐标
    emit mouseMovePoint(point);
    QGraphicsView::mouseMoveEvent(event);
}

void MyGraohicsView::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton)
    {
        QPoint point=event->pos();//返回视图坐标
        emit mouseClicked( point);
        QGraphicsView::mousePressEvent(event);
    }
}

void MyGraohicsView::mouseDoubleClickEvent(QMouseEvent *event)
{

    if(event->button()==Qt::LeftButton)
    {
        QPoint point=event->pos();
        emit mouseDoubleClick(point);
        QGraphicsView::mouseDoubleClickEvent(event);
    }

}

void MyGraohicsView::keyPressEvent(QKeyEvent *event)
{
    emit  keyPress(event);
    QGraphicsView::keyPressEvent(event);
}

void MyGraohicsView::resizeEvent(QResizeEvent *event)
{

     QGraphicsView::resizeEvent(event);
       emit  viewResize(event);
}



MyGraohicsView::MyGraohicsView(QWidget *parent) : QGraphicsView(parent)
{

}
