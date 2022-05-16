#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QTime>
#include<QGraphicsEllipseItem>
#include<QGraphicsItem>
#include<QColorDialog>
#include<QFontDialog>
#include<QKeyEvent>


template <class T>
void  SetBrushColor(T*item)
{
    QColor color=item->brush().color();
    color=QColorDialog::getColor(color,NULL,"选择填充颜色");
    if(color.isValid())
    {
        item->setBrush(QBrush(color));
    }


}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //创建状态栏图标
    LabViewCoord=new QLabel("视图坐标: ");
    LabViewCoord->setMinimumWidth(150);
    LabSceneCoord=new QLabel("场景坐标: ");
    LabSceneCoord->setMinimumWidth(150);
    LabGItemCoord=new QLabel("图形项坐标: ");
    LabGItemCoord->setMinimumWidth(150);
    LabGItemInfo=new QLabel("图形项信息: ");
    LabGItemInfo->setMinimumWidth(150);
    LabItemScale=new QLabel("图形缩放比例: ");
    LabItemScale->setMinimumWidth(150);
    LabViewScale=new QLabel("视图缩放比例: ");
    LabViewScale->setMinimumWidth(150);
    //加入状态栏
    ui->statusBar->addWidget(LabViewCoord);
    ui->statusBar->addWidget(LabSceneCoord);
    ui->statusBar->addWidget(LabGItemCoord);
    ui->statusBar->addWidget(LabGItemInfo);
    ui->statusBar->addWidget(LabItemScale);
    ui->statusBar->addWidget(LabViewScale);





    scene= new QGraphicsScene(-ui->graphicsView->width()/2,-ui->graphicsView->height()/2,
                              ui->graphicsView->width()-9,ui->graphicsView->height()-9);//创建场景和视图等高等宽


    ui->graphicsView->setScene(scene);//于视图关联
    ui->graphicsView->setCursor(Qt::CrossCursor);
    ui->graphicsView->setMouseTracking(true);//接受鼠标移动事件
    ui->graphicsView->setDragMode(QGraphicsView::RubberBandDrag);//托动形成框







    //信号与槽连接
    connect(ui->graphicsView,SIGNAL(viewResize(QResizeEvent*)),this,SLOT(on_resizeView()));
    connect(ui->graphicsView,SIGNAL(mouseMovePoint(QPoint)),this,SLOT(On_mouseMovePoint(QPoint)));
    connect(ui->graphicsView,SIGNAL(mouseClicked(QPoint)),this,SLOT(On_mouseClicked(QPoint)));
    connect(ui->graphicsView,SIGNAL(mouseDoubleClick(QPoint)),this,SLOT(On_mouseDoubleClick(QPoint)));
    connect(ui->graphicsView,SIGNAL(keyPress(QKeyEvent*)),this,SLOT(On_keyPress(QKeyEvent*)));

    //建立随机树种子
    qsrand(QTime::currentTime().second());

}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::On_mouseMovePoint(QPoint point)
{
//鼠标移动事件，point是视图坐标,物理坐标
    LabViewCoord->setText(QString::asprintf("视图坐标: %d,%d",point.x(),point.y()));
    //场景坐标
    QPointF pointScene=ui->graphicsView->mapToScene(point);
    LabSceneCoord->setText(QString::asprintf("场景坐标:%.0f,%.0f",pointScene.x(),pointScene.y()));
    //缩放比例
    LabViewScale->setText(QString::asprintf("视图缩放比例: %.0f%%",viewScale*100));

}

void MainWindow::On_mouseDoubleClick(QPoint point)
{
    //鼠标双击 根据选中的图形,调用对应的对话框

    QPointF PointScene=ui->graphicsView->mapToScene(point);//转换到场景坐标
    //获得图形项
    QGraphicsItem*GraphicsItem=scene->itemAt(PointScene,ui->graphicsView->transform());//光标下的图形项
    if(GraphicsItem==NULL)
        return;
    switch (GraphicsItem->type())
    {
    case QGraphicsRectItem::Type://矩形框
    {
        //有局部变量要用{}
        QGraphicsRectItem*item=dynamic_cast< QGraphicsRectItem*>(GraphicsItem);
        if(item==NULL)
            return;
        //模板函数根据类型生成不同的函数
        SetBrushColor(item);
        break;
    }

    case QGraphicsEllipseItem:: Type ://椭圆
    {
        QGraphicsEllipseItem*item=dynamic_cast< QGraphicsEllipseItem*>(GraphicsItem);
        if(item==NULL)
            return;
        //模板函数根据类型生成不同的函数
        SetBrushColor(item);
        break;
    }

    case QGraphicsPolygonItem::Type://梯形和三角形
    {
        QGraphicsPolygonItem*item=dynamic_cast< QGraphicsPolygonItem*>(GraphicsItem);
        if(item==NULL)
            return;
        //模板函数根据类型生成不同的函数
        SetBrushColor(item);
        break;


    }


    case QGraphicsLineItem::Type://直线

    {
        QGraphicsLineItem*item=dynamic_cast< QGraphicsLineItem*>(GraphicsItem);
        if(item==NULL)
            return;
        //设置笔的颜色
        QPen pen=item->pen();
        QColor color=item->pen().color();
        //调用颜色对话框
        color=QColorDialog::getColor(color,this,"选择线条颜色");
        if(color.isValid())
        {
            pen.setColor(color);
            item->setPen(pen);
        }

        break;



    }
    case QGraphicsTextItem::Type://文字
    {
        QGraphicsTextItem*item=dynamic_cast< QGraphicsTextItem*>(GraphicsItem);
        if(item==NULL)
            return;
        QFont font=item->font();
        //调用字体对话框
        bool ok=false;
        font=QFontDialog::getFont(&ok,font,this,"设置字体");
        if(ok)
        {

            item->setFont(font);
            break;
        }

    }


    }


}

void MainWindow::On_keyPress(QKeyEvent *event)
{

    //按键事件
    //只对一个图形响应
    if(scene->selectedItems().count()!=1)
        return ;
    QGraphicsItem*item=scene->selectedItems().at(0);
    if(event->key()==Qt::Key_Delete)//删除
    {
        scene->removeItem(item);
    }
    else  if(event->key()==Qt::Key_Space)//顺时针旋转90
    {
        item->setRotation(item->rotation()+90);
    }
    else if(event->key()==Qt::Key_PageUp)//放大
    {
        item->setData(itemScale,0.1+item->scale());
        item->setScale(0.1+item->scale());
        //显示缩放比例
        bool ok;
        LabItemScale->setText(QString::asprintf("图形缩放比例:%.0f%%",
                                        item->data(itemScale).toFloat(&ok)*100));
    }
    else if(event->key()==Qt::Key_PageDown)//缩小
    {
        item->setData(itemScale,item->scale()-0.1);
        item->setScale(item->scale()-0.1);
        //显示缩放比例
        bool ok;
        LabItemScale->setText(QString::asprintf("图形缩放比例:%.0f%%",
                                                item->data(itemScale).toFloat(&ok)*100));
    }
    else if(event->key()==Qt::Key_Left)
    {
        item->setX(item->x()-1);
    }
    else if(event->key()==Qt::Key_Right)
    {
        item->setX(item->x()+1);
    }
    else if(event->key()==Qt::Key_Up)
    {
        item->setY(item->y()-1);
    }
    else if(event->key()==Qt::Key_Down)
    {
        item->setY(item->y()+1);
    }





}

void MainWindow::On_mouseClicked(QPoint point)
{
    //鼠标单击事件
    QPointF PointScene=ui->graphicsView->mapToScene(point);//转换到场景坐标
    //获得图形项
   QGraphicsItem*item=scene->itemAt(PointScene,ui->graphicsView->transform());//光标下的图形项
   if(item!=NULL)
   {

       QPointF PointItem=item->mapFromScene(PointScene);//由场景坐标转换到图形局部坐标
       LabGItemCoord->setText(QString::asprintf("图形项局部坐标: %.0f,%.0f",PointItem.x(),PointItem.y()));
       LabGItemInfo->setText(QString::asprintf("图形项信息:")
                             +item->data(ItemDesciption).toString()
                             +QString::asprintf(" 图形Id:")
                             +item->data(ItemId).toString()
                             );
       bool ok;
       LabItemScale->setText(QString::asprintf("图形缩放比例:%.0f%%",item->data(itemScale).toFloat(&ok)*100));

   }


}

void MainWindow::on_actRestore_triggered()
{
    //取消所有变换
    //旋转
    //选中的图形项个数
    int GraphicsCount=scene->selectedItems().count();


    if(GraphicsCount>0)
    {

        for(int i=0;i<GraphicsCount;i++)
        {
            QGraphicsItem*item=scene->selectedItems().at(i);
            item->setData(itemScale,1.0);
            item->setScale(1.0);
            item->setRotation(0);
        }


    }
    else
    {
        //取消所有变换
        ui->graphicsView->resetTransform();
        viewScale=1.0;
        LabViewScale->setText(QString::asprintf("视图缩放比例: %.0f%%",viewScale*100));
    }



}

void MainWindow::on_actItem_Ellipse_triggered()
{
    //添加一个椭圆
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(-50,-30,100,60);
    //设置属性
    item->setFlags( QGraphicsItem::ItemIsSelectable|
                    QGraphicsItem::ItemIsMovable|
                    QGraphicsItem::ItemIsFocusScope);
    //设置填充颜色
    item->setBrush(QBrush(Qt::white));
    //设置z轴或者说叠放顺序
    item->setZValue(frontZ++);
    //设置初始位置
    item->setPos(-50+(qrand())%100,-50+(qrand()%100));
    //设置自定义数据
    //设置键值对
    item->setData(ItemId,seqNum++);
    item->setData(ItemDesciption,"椭圆");
    item->setData(itemScale,1.0);
    scene->addItem(item);
    scene->clearSelection();
    //设置选中
    item->setSelected(true);

}

void MainWindow::on_actItem_Rect_triggered()
{


    //添加一个矩形
    QGraphicsRectItem *item=new QGraphicsRectItem(-50,-30,100,60);
    //设置属性
    item->setFlags( QGraphicsItem::ItemIsSelectable|
                    QGraphicsItem::ItemIsMovable|
                    QGraphicsItem::ItemIsFocusScope);
    //设置填充颜色
    item->setBrush(QBrush(Qt::white));
    //设置z轴或者说叠放顺序
    item->setZValue(frontZ++);
    //设置初始位置
    item->setPos(-50+(qrand())%100,-50+(qrand()%100));
    //设置自定义数据
    //设置键值对
    item->setData(ItemId,seqNum++);
    item->setData(ItemDesciption,"矩形");
    item->setData(itemScale,1.0);
    scene->addItem(item);
    scene->clearSelection();
    //设置选中
    item->setSelected(true);

}

void MainWindow::on_actItem_Line_triggered()
{
    //添加一个直线
    QGraphicsLineItem *item=new QGraphicsLineItem(0,0,60,0);
    //设置属性
    item->setFlags( QGraphicsItem::ItemIsSelectable|
                    QGraphicsItem::ItemIsMovable|
                    QGraphicsItem::ItemIsFocusScope);
    //设置z轴或者说叠放顺序
    item->setZValue(frontZ++);
    //设置初始位置
    item->setPos(-50+(qrand())%100,-50+(qrand()%100));
    //设置自定义数据
    //设置键值对
    item->setData(ItemId,seqNum++);
    item->setData(ItemDesciption,"直线");
    item->setData(itemScale,1.0);
    scene->addItem(item);
    scene->clearSelection();
    //设置选中
    item->setSelected(true);


}

void MainWindow::on_actItem_Polygon_triggered()
{


    //添加梯形
       QGraphicsPolygonItem   *item=new QGraphicsPolygonItem;
       QPolygonF   points;
       points.append(QPointF(-40,0));
       points.append(QPointF(-60,40));
       points.append(QPointF(60,40));
       points.append(QPointF(40,0));



       item->setPolygon(points);
       item->setPos(-50+(qrand() % 100),-50+(qrand() % 100));

       item->setFlags(QGraphicsItem::ItemIsMovable
                      | QGraphicsItem::ItemIsSelectable
                      | QGraphicsItem::ItemIsFocusable);
       item->setBrush(QBrush(Qt::white));
       item->setZValue(++frontZ);

       item->setData(ItemId,seqNum++);
       item->setData(ItemDesciption,"梯形");
       item->setData(itemScale,1.0);

       scene->addItem(item);
       scene->clearSelection();
       item->setSelected(true);
}

void MainWindow::on_actItem_Triangle_triggered()
{
    //添加三角形
       QGraphicsPolygonItem   *item=new QGraphicsPolygonItem;
       QPolygonF   points;
       points.append(QPointF(0,-40));
       points.append(QPointF(60,40));
       points.append(QPointF(0,40));
       item->setPolygon(points);
       item->setPos(-50+(qrand() % 100),-50+(qrand() % 100));

       item->setFlags(QGraphicsItem::ItemIsMovable
                      | QGraphicsItem::ItemIsSelectable
                      | QGraphicsItem::ItemIsFocusable);
       item->setBrush(QBrush(Qt::white));
       item->setZValue(++frontZ);

       item->setData(ItemId,seqNum++);
       item->setData(ItemDesciption,"三角形");
       item->setData(itemScale,1.0);

       scene->addItem(item);
       scene->clearSelection();
       item->setSelected(true);
}

void MainWindow::on_actItem_Circle_triggered()
{
    //添加一个圆形
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(-50,-30,60,60);
    //设置属性
    item->setFlags( QGraphicsItem::ItemIsSelectable|
                    QGraphicsItem::ItemIsMovable|
                    QGraphicsItem::ItemIsFocusScope);
    //设置填充颜色
    item->setBrush(QBrush(Qt::white));
    //设置z轴或者说叠放顺序
    item->setZValue(frontZ++);
    //设置初始位置
    item->setPos(-50+(qrand())%100,-50+(qrand()%100));
    //设置自定义数据
    //设置键值对
    item->setData(ItemId,seqNum++);
    item->setData(ItemDesciption,"圆形");
    item->setData(itemScale,1.0);
    scene->addItem(item);
    scene->clearSelection();
    //设置选中
    item->setSelected(true);
}

void MainWindow::on_actItem_Text_triggered()
{

    //添加一个圆形
    QGraphicsTextItem *item=new QGraphicsTextItem("新建文字");
    //设置属性
    item->setFlags( QGraphicsItem::ItemIsSelectable|
                    QGraphicsItem::ItemIsMovable|
                    QGraphicsItem::ItemIsFocusScope);

   item->setDefaultTextColor(Qt::black);

    //设置z轴或者说叠放顺序
    item->setZValue(frontZ++);
    //设置初始位置
    item->setPos(-50+(qrand())%100,-50+(qrand()%100));
    //设置自定义数据
    //设置键值对
    item->setData(ItemId,seqNum++);
    item->setData(ItemDesciption,"文字");
    item->setData(itemScale,1.0);
    scene->addItem(item);
    scene->clearSelection();
    //设置选中
    item->setSelected(true);


}

void MainWindow::on_actZoomIn_triggered()
{
    //放大
    //选中的图形项
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount>0)
    {

        for(int i=0;i<GraphicsCount;i++)
        {
            QGraphicsItem*item=scene->selectedItems().at(i);
            item->setData(itemScale,0.1+item->scale());
            item->setScale(0.1+item->scale());
            //显示缩放比例
            bool ok;
            LabItemScale->setText(QString::asprintf("图形缩放比例:%.0f%%",
                                                    item->data(itemScale).toFloat(&ok)*100));
        }

    }
    else
    {
        viewScale+=0.1;
        ui->graphicsView->scale(viewScale,viewScale);
        LabViewScale->setText(QString::asprintf("视图缩放比例: %.0f%%",viewScale*100));
    }

}

void MainWindow::on_actZoomOut_triggered()
{
    //缩小
    //选中的图形项个数
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount>0)
    {
        for(int i=0;i<GraphicsCount;i++)
        {
        QGraphicsItem*item=scene->selectedItems().at(i);
        item->setData(itemScale,item->scale()-0.1);
        item->setScale(item->scale()-0.1);
        bool ok;
        LabItemScale->setText(QString::asprintf("图形缩放比例:%.0f%%",
                                                item->data(itemScale).toFloat(&ok)*100));
        }

    }
    else
    {
        viewScale-=0.1;
        ui->graphicsView->scale(viewScale,viewScale);
        LabViewScale->setText(QString::asprintf("视图缩放比例: %.0f%%",viewScale*100));
    }

}

void MainWindow::on_actRotateLeft_triggered()
{
    //旋转
    //选中的图形项个数
    int GraphicsCount=scene->selectedItems().count();


    if(GraphicsCount>0)
    {
        for(int i=0;i<GraphicsCount;i++)
        {
        QGraphicsItem*item=scene->selectedItems().at(i);
        item->setRotation(-30+item->rotation());
        }
    }
    else
    {
        ui->graphicsView->rotate(-30);
    }
}

void MainWindow::on_actRotateRight_triggered()
{
    //旋转
    //选中的图形项个数
    int GraphicsCount=scene->selectedItems().count();


    if(GraphicsCount>0)
    {
        for(int i=0;i<GraphicsCount;i++)
        {
        QGraphicsItem*item=scene->selectedItems().at(i);
        item->setRotation(30+item->rotation());
        }
    }
    else
    {
        ui->graphicsView->rotate(30);
    }

}

void MainWindow::on_actRestoreStatusBar_triggered()
{
    this->addToolBar(Qt::TopToolBarArea,ui->mainToolBar);
    this->addToolBar(Qt::LeftToolBarArea,ui->toolBar);
}

void MainWindow::on_actEdit_Front_triggered()
{
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount>0)
    {
         QGraphicsItem*item=scene->selectedItems().at(0);
         item->setZValue(frontZ++);//将选中的第一个图形设置到最前面
    }

}

void MainWindow::on_actEdit_Back_triggered()
{
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount>0)
    {
         QGraphicsItem*item=scene->selectedItems().at(0);
         item->setZValue(this->backZ--);//将选中的第一个图形设置到最后后面
    }

}

void MainWindow::on_actGroup_triggered()
{
    //形成一个组合
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount>1)
    {

        QGraphicsItemGroup*group=new  QGraphicsItemGroup;
        scene->addItem(group);
        for(int i=0;i<GraphicsCount;i++)
        {
            QGraphicsItem*item=scene->selectedItems().at(0);
            item->setSelected(false);//清除选中虚线框注意这里会减少选中list里的item
            item->clearFocus();
            group->addToGroup(item);//添加进组
        }
        //设置属性
        group->setFlags( QGraphicsItem::ItemIsSelectable|
                        QGraphicsItem::ItemIsMovable|
                        QGraphicsItem::ItemIsFocusScope);

        group->setZValue(frontZ++);//组前置显示
        scene->clearSelection();
        group->setSelected(true);


    }

}

void MainWindow::on_actGroupBreak_triggered()
{
    int GraphicsCount=scene->selectedItems().count();
    if(GraphicsCount==1)
    {

          QGraphicsItemGroup*group=dynamic_cast<QGraphicsItemGroup*> (scene->selectedItems().at(0));
          if(group==NULL)//不是图形项就直接返回
              return ;
          scene->destroyItemGroup(group);
    }
}

void MainWindow::on_actEdit_Delete_triggered()
{
    int GraphicsCount=scene->selectedItems().count();


    if(GraphicsCount>0)
    {
        for(int i=0;i<GraphicsCount;i++)
        {
        QGraphicsItem*item=scene->selectedItems().at(0);
        scene->removeItem(item);
        delete item;
        }
    }

}



void MainWindow::on_action_clear_triggered()
{
    scene->clear();
}

void MainWindow::on_resizeView()
{



     scene->setSceneRect(-ui->graphicsView->width()/2,
                             -ui->graphicsView->height()/2,ui->graphicsView->width()-9,ui->graphicsView->height()-9);


}
