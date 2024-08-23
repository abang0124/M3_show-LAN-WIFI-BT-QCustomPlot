#ifndef QMLPLOT_H
#define QMLPLOT_H

#include <QtQuick>
class QCustomPlot;
class QCPAbstractPlottable;
class QCPItemRect;

class CustomPlotItem : public QQuickPaintedItem
{
    Q_OBJECT

public:
    CustomPlotItem( QQuickItem* parent = 0 );
    virtual ~CustomPlotItem();

    void paint( QPainter* painter );

    QElapsedTimer mtimer;

    //Q_INVOKABLE void initCustomPlot();  //在QML中这个函数可用
    Q_INVOKABLE void initCustomPlot_12Lead(quint8 gaintype ,quint8 speedtype); //12导联显示调用此函数 //携带gaintype和speedtype信息
    Q_INVOKABLE void initCustomPlot_3Lead(quint8 gaintype ,quint8 speedtype); //3导联显示调用此函数 //携带gaintype和speedtype信息
    Q_INVOKABLE void initCustomPlot_Only3Lead(quint8 gaintype, quint8 speedtype); //只显示3导联
    Q_INVOKABLE void initCustomPlot_6Lead(quint8 gaintype ,quint8 speedtype); //6导联显示调用此函数 //携带gaintype和speedtype信息
    Q_INVOKABLE void initCustomPlot_1Lead(quint8 gaintype ,quint8 speedtype); //单导联显示调用此函数 //携带gaintype和speedtype信息
    Q_INVOKABLE void initCustomPlot_SPO2(); //血氧显示调用此函数 //携带gaintype和speedtype信息

    Q_INVOKABLE void update12LeadsShow(QList<int>, QList<int>, QList<int>, QList<int>, QList<int>, QList<int>, QList<int>, QList<int>, QList<int>, QList<int> listV4, QList<int> listV5, QList<int> listV6);//更新和显示12导联
    Q_INVOKABLE void update3LeadsShow(QList<int>, QList<int>, QList<int>);//更新和显示3导联
    Q_INVOKABLE void update6LeadsShow(QList<int>, QList<int>, QList<int>,QList<int>, QList<int>, QList<int>);//更新和显示6导联
    Q_INVOKABLE void update1LeadsShow(QList<int>);//更新和显示单导联
    Q_INVOKABLE void updateSPO2Show(QList<int>);//更新和显示血氧
    Q_INVOKABLE void ecg_Y_BaseLine12(QList<int> YBaseLineArray); //将Y轴的基准线值传递过来
    Q_INVOKABLE void ecg_Y_BaseLine3(QList<int> YBaseLineArray); //将Y轴的基准线值传递过来

    Q_INVOKABLE void ecg_Y_BaseLine6(QList<int> YBaseLineArray); //将Y轴的基准线值传递过来
    Q_INVOKABLE void ecg_Y_BaseLine1(QList<int> YBaseLineArray); //将Y轴的基准线值传递过来

    quint16 x_range,y_range;
protected:
//    void routeMouseEvents( QMouseEvent* event );
//    void routeWheelEvents( QWheelEvent* event );

    //virtual void mousePressEvent( QMouseEvent* event );
   // virtual void mouseReleaseEvent( QMouseEvent* event );
    //virtual void mouseMoveEvent( QMouseEvent* event );
    //virtual void mouseDoubleClickEvent( QMouseEvent* event );
    //virtual void wheelEvent( QWheelEvent *event );

    qint32 yBaseLineArray[12] = {0};
    qint32 yleadMAXAndMINDiffArray[12] = {0};
    qint32 yBaseLineArray3[3] = {0};
    qint32 yleadMAXAndMINDiffArray3[3] = {0};

    qint32 yBaseLineArray6[6] = {0};
    qint32 yleadMAXAndMINDiffArray6[6] = {0};
    qint32 yBaseLineArray1 = {0};
    qint32 yleadMAXAndMINDiffArray1 = {0};


private:
    QCustomPlot*         m_CustomPlot;
    int                  m_timerId;
    bool                 firstFlag = false;
    bool                 initFlag = false;
    quint8               x_offset;
    QPen pen;
    QCPItemRect *rect1,*rect2;
private slots:
    void graphClicked( QCPAbstractPlottable* plottable );
    void onCustomReplot();
    void updateCustomPlotSize();
    void removeGraphData(quint8 leadnum,quint16 pos); //删除

};

#endif // QMLPLOT_H
