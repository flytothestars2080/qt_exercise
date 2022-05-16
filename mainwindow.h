#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
#include<QLabel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:

    static const int ItemId=1;//图形项自定义数据,Id的key
    static const int ItemDesciption=2;//图形项自定义数据，图形类型的key
    static const int itemScale=3;//图形项缩放比例
    int seqNum=0;//图形项编号
    int backZ=0;//图形项的叠放顺序 ，z轴方向最后面图形的数值，
    int frontZ=0;//图形项的叠放顺序，z轴方向最前面图形的数值，
    float viewScale=1.0;//视图缩放比例
    QGraphicsScene *scene;//场景
    QLabel *LabViewCoord ;//视图坐标
    QLabel*LabSceneCoord;//场景坐标
    QLabel*LabGItemCoord;//图形项坐标
    QLabel*LabGItemInfo;//图形项信息
    QLabel*LabViewScale;
    QLabel*LabItemScale;//当前选中项的缩放比例


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void On_mouseMovePoint(QPoint point);
    void On_mouseDoubleClick(QPoint point);
    void On_keyPress(QKeyEvent*event);
    void On_mouseClicked(QPoint point);
    void on_actRestore_triggered();

    void on_actItem_Ellipse_triggered();

    void on_actItem_Rect_triggered();

    void on_actItem_Line_triggered();

    void on_actItem_Polygon_triggered();

    void on_actItem_Triangle_triggered();

    void on_actItem_Circle_triggered();

    void on_actItem_Text_triggered();

    void on_actZoomIn_triggered();

    void on_actZoomOut_triggered();

    void on_actRotateLeft_triggered();

    void on_actRotateRight_triggered();

    void on_actRestoreStatusBar_triggered();

    void on_actEdit_Front_triggered();

    void on_actEdit_Back_triggered();

    void on_actGroup_triggered();

    void on_actGroupBreak_triggered();

    void on_actEdit_Delete_triggered();


    void on_action_clear_triggered();
    void on_resizeView();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
