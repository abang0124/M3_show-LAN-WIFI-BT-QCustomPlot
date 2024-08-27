#include "qmlplot.h"
#include "qcustomplot.h"
#include <QElapsedTimer> //测试某段代码的运行时间
#include <QDebug>
#define X_MAX  460
//#define X_OFFSET 45
#define Y_MAX  30
#define X_LENGTH_25MS_12LEADS 400
#define X_LENGTH_50MS_12LEADS 200
CustomPlotItem::CustomPlotItem( QQuickItem* parent ) : QQuickPaintedItem( parent )
    , m_CustomPlot( nullptr ), m_timerId( 0 )
{
    setFlag( QQuickItem::ItemHasContents, true );
    setAcceptedMouseButtons( Qt::AllButtons );


    //connect( this, &QQuickPaintedItem::widthChanged, this, &CustomPlotItem::updateCustomPlotSize );
   // connect( this, &QQuickPaintedItem::heightChanged, this, &CustomPlotItem::updateCustomPlotSize );
}

CustomPlotItem::~CustomPlotItem()
{
    initFlag = false;
    delete m_CustomPlot;
    m_CustomPlot = nullptr;
    if(m_timerId != 0) {
        killTimer(m_timerId);
    }
}



void CustomPlotItem::initCustomPlot_12Lead(quint8 gaintype ,quint8 speedtype) //12导联显示调用此函数 //携带gaintype和speedtype信息
{
    //gaintype 影响Y值，speedtype影响X值

    if(gaintype == 0) //10mm/mv
    {
        y_range = 6024;

    }
    else if(gaintype == 1)//20mm/mv
    {
        //y_range = 30;
        y_range = 3012;

    }
    else if(gaintype == 2) //5mm/mv
    {
        y_range = 12048;

    }

    if(speedtype == 0) //25mm/ms  每条曲线2s的数据 400个点
    {
        x_offset = 45;
        x_range = (X_LENGTH_25MS_12LEADS+x_offset)*2;

    }
    else if(speedtype == 1)//50mm/ms     这个得调
    {
        x_offset = 24;
        x_range = (X_LENGTH_50MS_12LEADS+x_offset)*2;

    }

    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();
    for(int i = 0;i<12;i++)
    {
        m_CustomPlot->addGraph(); //每1个Graph就是一条线
        m_CustomPlot->graph(i)->setAdaptiveSampling(true);
        m_CustomPlot->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
        pen.setWidth(1);
        pen.setColor(Qt::green);
        m_CustomPlot->graph(i)->setPen(pen);
    }
//    pen.setWidth(1);
//    pen.setColor(Qt::red);
//    m_CustomPlot->graph(4)->setPen(pen);
    m_CustomPlot->addGraph();
    m_CustomPlot->graph(12)->setAdaptiveSampling(true);

    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, x_range);//画12导联曲线
    //m_CustomPlot->xAxis->setRange( 0, 400);//画12导联曲线
    m_CustomPlot->yAxis->setRange( 0, y_range);
    //m_CustomPlot->yAxis->setRange( 0, 400);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    rect2 = new QCPItemRect(m_CustomPlot);
    rect1->setBrush(*brush);
    rect2->setBrush(*brush);
    firstFlag = true;
    initFlag = true;

}
//三导联显示初始化 gaintype代表增益类型 ，speedtype 代表速度类型
void CustomPlotItem::initCustomPlot_3Lead(quint8 gaintype, quint8 speedtype)
{
    //gaintype 影响Y值，speedtype影响X值

    if(gaintype == 0) //10mm/mv
    {
        y_range = 6024;

    }
    else if(gaintype == 1)//20mm/mv
    {
        y_range = 3012;

    }
    else if(gaintype == 2) //5mm/mv
    {
        y_range = 12048;

    }

    if(speedtype == 0) //25mm/ms  每条曲线2s的数据 400个点
    {
        x_range = 800;

    }
    else if(speedtype == 1)//50mm/ms     这个得调
    {
        x_range = 400;

    }

    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();
    for(int i = 0;i<3;i++)
    {
        m_CustomPlot->addGraph(); //每1个Graph就是一条线
        m_CustomPlot->graph(i)->setAdaptiveSampling(true);
        m_CustomPlot->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
        pen.setWidth(1);
        pen.setColor(Qt::green);
        m_CustomPlot->graph(i)->setPen(pen);
    }

    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, x_range);//画3导联曲线
    //m_CustomPlot->xAxis->setRange( 0, 400);//画3导联曲线
    m_CustomPlot->yAxis->setRange( 0, y_range);
    //m_CustomPlot->yAxis->setRange( 0, 400);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    //rect2 = new QCPItemRect(m_CustomPlot);
    rect1->setBrush(*brush);
    //rect2->setBrush(*brush);
    firstFlag = true;
    initFlag = true;
}



void CustomPlotItem::initCustomPlot_Only3Lead(quint8 gaintype, quint8 speedtype)
{
    //gaintype 影响Y值，speedtype影响X值

    if(gaintype == 0) //10mm/mv
    {
        y_range = 6024;

    }
    else if(gaintype == 1)//20mm/mv
    {
        y_range = 3012;

    }
    else if(gaintype == 2) //5mm/mv
    {
        y_range = 12048;

    }

    if(speedtype == 0) //25mm/ms  每条曲线2s的数据 400个点
    {
        //x_range = 800;
        x_range = 851;

    }
    else if(speedtype == 1)//50mm/ms     这个得调
    {
        //x_range = 400;
        x_range = 425;

    }

    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();
    for(int i = 0;i<3;i++)
    {
        m_CustomPlot->addGraph(); //每1个Graph就是一条线
        m_CustomPlot->graph(i)->setAdaptiveSampling(true);
        m_CustomPlot->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
        pen.setWidth(1);
        pen.setColor(Qt::green);
        m_CustomPlot->graph(i)->setPen(pen);
    }

    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, x_range);//画3导联曲线
    //m_CustomPlot->xAxis->setRange( 0, 400);//画3导联曲线
    m_CustomPlot->yAxis->setRange( 0, y_range);
    //m_CustomPlot->yAxis->setRange( 0, 400);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    //rect2 = new QCPItemRect(m_CustomPlot);
    rect1->setBrush(*brush);
    //rect2->setBrush(*brush);
    firstFlag = true;
    initFlag = true;
}





void CustomPlotItem::initCustomPlot_6Lead(quint8 gaintype, quint8 speedtype)
{
    //gaintype 影响Y值，speedtype影响X值

    if(gaintype == 0) //10mm/mv
    {
        y_range = 6024;

    }
    else if(gaintype == 1)//20mm/mv
    {
        y_range = 3012;

    }
    else if(gaintype == 2) //5mm/mv
    {
        y_range = 12048;

    }

    if(speedtype == 0) //25mm/ms  每条曲线2s的数据 400个点
    {
        x_range = 800;

    }
    else if(speedtype == 1)//50mm/ms     这个得调
    {
        x_range = 400;

    }

    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();
    for(int i = 0;i<6;i++)
    {
        m_CustomPlot->addGraph(); //每1个Graph就是一条线
        m_CustomPlot->graph(i)->setAdaptiveSampling(true);
        m_CustomPlot->graph(i)->setLineStyle(QCPGraph::LineStyle::lsLine);
        //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
        pen.setWidth(1);
        pen.setColor(Qt::green);
        m_CustomPlot->graph(i)->setPen(pen);
    }

    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, x_range);//画3导联曲线
    //m_CustomPlot->xAxis->setRange( 0, 400);//画3导联曲线
    m_CustomPlot->yAxis->setRange( 0, y_range);
    //m_CustomPlot->yAxis->setRange( 0, 400);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    //rect2 = new QCPItemRect(m_CustomPlot);
    rect1->setBrush(*brush);
    //rect2->setBrush(*brush);
    firstFlag = true;
    initFlag = true;
}







void CustomPlotItem::initCustomPlot_1Lead(quint8 gaintype, quint8 speedtype)
{
    //gaintype 影响Y值，speedtype影响X值

    if(gaintype == 0) //10mm/mv
    {
        y_range = 6024;

    }
    else if(gaintype == 1)//20mm/mv
    {
        y_range = 3012;

    }
    else if(gaintype == 2) //5mm/mv
    {
        y_range = 12048;

    }

    if(speedtype == 0) //25mm/ms  每条曲线2s的数据 400个点
    {
        x_range = 800;

    }
    else if(speedtype == 1)//50mm/ms     这个得调
    {
        x_range = 400;

    }

    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();

    m_CustomPlot->addGraph(); //每1个Graph就是一条线
    m_CustomPlot->graph(0)->setAdaptiveSampling(true);
    m_CustomPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);
    //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
    pen.setWidth(1);
    pen.setColor(Qt::green);
    m_CustomPlot->graph(0)->setPen(pen);


    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, x_range);//画3导联曲线
    //m_CustomPlot->xAxis->setRange( 0, 400);//画3导联曲线
    m_CustomPlot->yAxis->setRange( 0, y_range);
    //m_CustomPlot->yAxis->setRange( 0, 400);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    //rect2 = new QCPItemRect(m_CustomPlot);
    rect1->setBrush(*brush);
    //rect2->setBrush(*brush);
    firstFlag = true;
    initFlag = true;
}

void CustomPlotItem::initCustomPlot_SPO2()
{


    m_CustomPlot = new QCustomPlot();
    updateCustomPlotSize();

    m_CustomPlot->addGraph(); //每1个Graph就是一条线
    m_CustomPlot->graph(0)->setAdaptiveSampling(true);
    m_CustomPlot->graph(0)->setLineStyle(QCPGraph::LineStyle::lsLine);
    //m_CustomPlot->graph(i)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ScatterShape::ssCircle));
    pen.setWidth(2);
    pen.setColor("#05DFDE");
    m_CustomPlot->graph(0)->setPen(pen);


    QBrush *brush = new QBrush("black");
    m_CustomPlot->yAxis->setVisible(false);
    m_CustomPlot->xAxis->setVisible(false);
    m_CustomPlot->setBackground(*brush);
    m_CustomPlot->xAxis->setRange( 0, 400);
    m_CustomPlot->yAxis->setRange( 0, 310);
    connect( m_CustomPlot, &QCustomPlot::afterReplot, this, &CustomPlotItem::onCustomReplot );
    m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
    rect1 = new QCPItemRect(m_CustomPlot);
    //brush->setColor("green");
    rect1->setBrush(*brush);
    firstFlag = true;
    initFlag = true;
}

void CustomPlotItem::update12LeadsShow(QList<int> listI, QList<int> listII, QList<int> listIII, QList<int> listaVR, QList<int> listaVL, QList<int> listaVF, QList<int> listV1, QList<int> listV2, QList<int> listV3, QList<int> listV4, QList<int> listV5, QList<int> listV6)//更新和显示12导联
{
   //m_CustomPlot->graph(0)->addData()
    static quint16 count;
    if(initFlag)
    {
        count = 0;
        initFlag = false;
    }
    qint32 listLength = listI.length();
    //qDebug()<<"listI.length() = "<<listI.length();

    for(int i = 0;i<listLength;i++)
    {

        if(firstFlag)
        {
            if(listI[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(count+x_offset,y_range/6*5);
            }
            else {
                m_CustomPlot->graph(0)->addData(count+x_offset,listI[i]*0.01-yBaseLineArray[0]);
            }
            //m_CustomPlot->graph(0)->addData(count+x_offset,listI[i]*0.01-yBaseLineArray[0]);
            m_CustomPlot->graph(1)->addData(count+x_offset,listII[i]*0.01-yBaseLineArray[1]);
            m_CustomPlot->graph(2)->addData(count+x_offset,listIII[i]*0.01-yBaseLineArray[2]);
            m_CustomPlot->graph(3)->addData(count+x_offset,listaVR[i]*0.01-yBaseLineArray[3]);
            m_CustomPlot->graph(4)->addData(count+x_offset,listaVL[i]*0.01-yBaseLineArray[4]);
            m_CustomPlot->graph(5)->addData(count+x_offset,listaVF[i]*0.01-yBaseLineArray[5]);
            m_CustomPlot->graph(6)->addData(count+x_range/2+x_offset,listV1[i]*0.01-yBaseLineArray[6]);
            m_CustomPlot->graph(7)->addData(count+x_range/2+x_offset,listV2[i]*0.01-yBaseLineArray[7]);
            m_CustomPlot->graph(8)->addData(count+x_range/2+x_offset,listV3[i]*0.01-yBaseLineArray[8]);
            m_CustomPlot->graph(9)->addData(count+x_range/2+x_offset,listV4[i]*0.01-yBaseLineArray[9]);
            m_CustomPlot->graph(10)->addData(count+x_range/2+x_offset,listV5[i]*0.01-yBaseLineArray[10]);
            m_CustomPlot->graph(11)->addData(count+x_range/2+x_offset,listV6[i]*0.01-yBaseLineArray[11]);


            count++;
            if(count%5 == 0)
            {
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
            }
            if(count>(x_range/2-x_offset)) //如果收到的值大于X轴的显示范围
            {
                count = 0;
                firstFlag = false;
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
                //qDebug()<<"in not remove data ";

            }
        }
        else {
            //qDebug()<<"count = "<<count;
            this->removeGraphData(0,count+x_offset);
            this->removeGraphData(1,count+x_offset);
            this->removeGraphData(2,count+x_offset);
            this->removeGraphData(3,count+x_offset);
            this->removeGraphData(4,count+x_offset);
            this->removeGraphData(5,count+x_offset);

            this->removeGraphData(6,count+x_range/2+x_offset);
            this->removeGraphData(7,count+x_range/2+x_offset);
            this->removeGraphData(8,count+x_range/2+x_offset);
            this->removeGraphData(9,count+x_range/2+x_offset);
            this->removeGraphData(10,count+x_range/2+x_offset);
            this->removeGraphData(11,count+x_range/2+x_offset);

            if(listI[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(count+x_offset,y_range/6*5);
            }
            else {
                m_CustomPlot->graph(0)->addData(count+x_offset,listI[i]*0.01-yBaseLineArray[0]);
            }
            m_CustomPlot->graph(1)->addData(count+x_offset,listII[i]*0.01-yBaseLineArray[1]);
            m_CustomPlot->graph(2)->addData(count+x_offset,listIII[i]*0.01-yBaseLineArray[2]);
            m_CustomPlot->graph(3)->addData(count+x_offset,listaVR[i]*0.01-yBaseLineArray[3]);
            m_CustomPlot->graph(4)->addData(count+x_offset,listaVL[i]*0.01-yBaseLineArray[4]);
            m_CustomPlot->graph(5)->addData(count+x_offset,listaVF[i]*0.01-yBaseLineArray[5]);
            m_CustomPlot->graph(6)->addData(count+x_range/2+x_offset,listV1[i]*0.01-yBaseLineArray[6]);
            m_CustomPlot->graph(7)->addData(count+x_range/2+x_offset,listV2[i]*0.01-yBaseLineArray[7]);
            m_CustomPlot->graph(8)->addData(count+x_range/2+x_offset,listV3[i]*0.01-yBaseLineArray[8]);
            m_CustomPlot->graph(9)->addData(count+x_range/2+x_offset,listV4[i]*0.01-yBaseLineArray[9]);
            m_CustomPlot->graph(10)->addData(count+x_range/2+x_offset,listV5[i]*0.01-yBaseLineArray[10]);
            m_CustomPlot->graph(11)->addData(count+x_range/2+x_offset,listV6[i]*0.01-yBaseLineArray[11]);

            rect1->topLeft->setCoords(count+x_offset+1,y_range);
            rect1->bottomRight->setCoords(count+x_offset+5,0);
            rect2->topLeft->setCoords(count+x_range/2+x_offset+1,y_range);
            rect2->bottomRight->setCoords(count+x_range/2+x_offset+5,0);
            count++;
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
            if(count>(x_range/2-x_offset)) //如果收到的值大于X轴的显示范围
            {
                count = 0;
                firstFlag = false;

            }
        }
    }
    //qDebug()<<"the length1 is "<<listI.length();
    //qDebug()<<"test num"<<m_CustomPlot->xAxis->range().size();
    //qDebug()<<"in this function"<<endl;
}

void CustomPlotItem::update3LeadsShow(QList<int> listfirst, QList<int> listsecond, QList<int> listthree)
{
    static quint16 countThree;
    if(initFlag)
    {
        countThree = 0;
        initFlag = false;
    }
    qint32 listLength = listfirst.length();

    for(int i = 0;i<listLength;i++)
    {
        if(firstFlag)
        {
            if(listfirst[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countThree,y_range/3*2);
            }
            else {
                m_CustomPlot->graph(0)->addData(countThree,listfirst[i]*0.01-yBaseLineArray3[0]);
            }
            //m_CustomPlot->graph(0)->addData(countThree,listfirst[i]*0.01-yBaseLineArray3[0]);
            m_CustomPlot->graph(1)->addData(countThree,listsecond[i]*0.01-yBaseLineArray3[1]);
            m_CustomPlot->graph(2)->addData(countThree,listthree[i]*0.01-yBaseLineArray3[2]);


            countThree++;
            if(countThree%5 == 0)
            {
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
            }
            if(countThree>x_range) //如果收到的值大于X轴的显示范围
            {
                //qDebug()<<"countThree = "<<countThree;
                countThree = 0;
                firstFlag = false;
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
                //qDebug()<<"in not remove data ";

            }
        }
        else{
            //qDebug()<<"count = "<<countThree;
            this->removeGraphData(0,countThree);
            this->removeGraphData(1,countThree);
            this->removeGraphData(2,countThree);

            if(listfirst[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countThree,y_range/3*2);
            }
            else {
                m_CustomPlot->graph(0)->addData(countThree,listfirst[i]*0.01-yBaseLineArray3[0]);
                //m_CustomPlot->graph(0)->addData(countThree,listsecond[i]*0.01-yBaseLineArray3[1]+600);
            }
            m_CustomPlot->graph(1)->addData(countThree,listsecond[i]*0.01-yBaseLineArray3[1]);
            //m_CustomPlot->graph(1)->addData(countThree,listfirst[i]*0.01-yBaseLineArray3[0]-600);
            m_CustomPlot->graph(2)->addData(countThree,listthree[i]*0.01-yBaseLineArray3[2]);

            rect1->topLeft->setCoords(countThree+1,y_range);
            rect1->bottomRight->setCoords(countThree+5,0);
            countThree++;
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
            if(countThree>x_range) //如果收到的值大于X轴的显示范围
            {
                countThree = 0;
                firstFlag = false;

            }

        }
    }
}

void CustomPlotItem::update6LeadsShow(QList<int> list1, QList<int> list2, QList<int> list3, QList<int> list4, QList<int> list5, QList<int> list6)
{
    static quint16 countSix;
    if(initFlag)
    {
        countSix = 0;
        initFlag = false;
    }
    qint32 listLength = list1.length();

    for(int i = 0;i<listLength;i++)
    {
        if(firstFlag)
        {
            if(list1[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countSix,y_range/6*5);
            }
            else {
                m_CustomPlot->graph(0)->addData(countSix,list1[i]*0.01-yBaseLineArray6[0]);
            }
            //m_CustomPlot->graph(0)->addData(countSix,list1[i]*0.01-yBaseLineArray6[0]);
            m_CustomPlot->graph(1)->addData(countSix,list2[i]*0.01-yBaseLineArray6[1]);
            m_CustomPlot->graph(2)->addData(countSix,list3[i]*0.01-yBaseLineArray6[2]);
            m_CustomPlot->graph(3)->addData(countSix,list4[i]*0.01-yBaseLineArray6[3]);
            m_CustomPlot->graph(4)->addData(countSix,list5[i]*0.01-yBaseLineArray6[4]);
            m_CustomPlot->graph(5)->addData(countSix,list6[i]*0.01-yBaseLineArray6[5]);


            countSix++;
            if(countSix%5 == 0)
            {
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
            }
            if(countSix>x_range) //如果收到的值大于X轴的显示范围
            {
                countSix = 0;
                firstFlag = false;
                //qDebug()<<"in not remove data ";

            }
        }
        else{
            this->removeGraphData(0,countSix);
            this->removeGraphData(1,countSix);
            this->removeGraphData(2,countSix);
            this->removeGraphData(3,countSix);
            this->removeGraphData(4,countSix);
            this->removeGraphData(5,countSix);

            if(list1[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countSix,y_range/6*5);
            }
            else {
                m_CustomPlot->graph(0)->addData(countSix,list1[i]*0.01-yBaseLineArray6[0]);
            }
            m_CustomPlot->graph(1)->addData(countSix,list2[i]*0.01-yBaseLineArray6[1]);
            m_CustomPlot->graph(2)->addData(countSix,list3[i]*0.01-yBaseLineArray6[2]);
            m_CustomPlot->graph(3)->addData(countSix,list4[i]*0.01-yBaseLineArray6[3]);
            m_CustomPlot->graph(4)->addData(countSix,list5[i]*0.01-yBaseLineArray6[4]);
            m_CustomPlot->graph(5)->addData(countSix,list6[i]*0.01-yBaseLineArray6[5]);

            rect1->topLeft->setCoords(countSix+1,y_range);
            rect1->bottomRight->setCoords(countSix+5,0);
            countSix++;
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
            if(countSix>x_range) //如果收到的值大于X轴的显示范围
            {
                countSix = 0;
                firstFlag = false;

            }
        }
    }
}

void CustomPlotItem::update1LeadsShow(QList<int> listOne)
{
    static quint16 countOne;
    if(initFlag)
    {
        countOne = 0;
        initFlag = false;
    }
    qint32 listLength = listOne.length();
    //qDebug()<<"listLength = "<<listLength;

    for(int i = 0;i<listLength;i++)
    {
        if(firstFlag)
        {
            if(listOne[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countOne,y_range);
            }
            else {
                m_CustomPlot->graph(0)->addData(countOne,listOne[i]*0.01-yBaseLineArray1);
            };


            countOne++;
            if(countOne%5 == 0)
            {
                m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
            }
            if(countOne>x_range) //如果收到的值大于X轴的显示范围
            {
                countOne = 0;
                firstFlag = false;
                //qDebug()<<"in not remove data ";

            }
        }
        else{
            //qDebug()<<"countOne = "<<countOne;
            this->removeGraphData(0,countOne);

            if(listOne[i]*0.01 == 0)
            {
                m_CustomPlot->graph(0)->addData(countOne,y_range);
            }
            else {
                m_CustomPlot->graph(0)->addData(countOne,listOne[i]*0.01-yBaseLineArray1);
            }

            rect1->topLeft->setCoords(countOne+1,y_range);
            rect1->bottomRight->setCoords(countOne+5,0);
            countOne++;
            //if(countOne%5 == 0)
            //{
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
            //}
            if(countOne>x_range) //如果收到的值大于X轴的显示范围
            {
                countOne = 0;
                firstFlag = false;

            }
        }
    }
}

void CustomPlotItem::updateSPO2Show(QList<int> SPO2DataList)
{
    static quint16 countSPO2;
    if(initFlag)
    {
        countSPO2 = 0;
        initFlag = false;
    }
    qint32 listLength = SPO2DataList.length();
    //qDebug()<<"listLength = "<<listLength;


    for(int i = 0;i<listLength;i++)
    {
        if(firstFlag)
        {
            m_CustomPlot->graph(0)->addData(countSPO2,SPO2DataList[i]+10);
            countSPO2++;
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpImmediateRefresh);
            if(countSPO2>400)
            {
                firstFlag = false;
                countSPO2 = 0;
            }
        }
        else {
            //qDebug()<<"countSPO2 = "<<countSPO2;
            this->removeGraphData(0,countSPO2);
            m_CustomPlot->graph(0)->addData(countSPO2,SPO2DataList[i]+10);
            rect1->topLeft->setCoords(countSPO2+1,310);
            rect1->bottomRight->setCoords(countSPO2+5,0);
            countSPO2++;
            m_CustomPlot->replot(QCustomPlot::RefreshPriority::rpQueuedReplot);
            if(countSPO2>400)
            {
                firstFlag = false;
                countSPO2 = 0;
            }
        }
    }
}

void CustomPlotItem::ecg_Y_BaseLine12(QList<int> YBaseLineArray)
{
//    for(int i = 0; i<YBaseLineArray.length();i++)
//    {
//        yBaseLineArray[i] = YBaseLineArray[i]; //将基线存储在yBaseLineArray的数组中
//    }
    if(YBaseLineArray.length()==24) //如果数据长度是24位 前12位为最小值，后12位为最大值
    {

        for(int i = 0;i<12;i++)
        {
            yleadMAXAndMINDiffArray[i] = YBaseLineArray[i+12] - YBaseLineArray[i];
            yBaseLineArray[i] = YBaseLineArray[i]; //将基线存储在yBaseLineArray的数组中
        }
//        for(int i= 0;i<12;i++)
//        {
//            qDebug()<<"yleadMAXAndMINDiffArray["<<i<<"] =  "<< yleadMAXAndMINDiffArray[i];
//        }

        if( yleadMAXAndMINDiffArray[0] > y_range/6) //判断I导联是否超过间隔值
        {
             yBaseLineArray[0] = yBaseLineArray[0]-(y_range - yleadMAXAndMINDiffArray[0])+50;
        }
        else
        {
             yBaseLineArray[0] =  yBaseLineArray[0]-y_range/6*5;
        }

        if( yleadMAXAndMINDiffArray[1] > y_range/6*2) //判断II导联是否超过间隔值
        {
             yBaseLineArray[1] = yBaseLineArray[1]-(y_range - yleadMAXAndMINDiffArray[1]);
        }
        else
        {
             yBaseLineArray[1] =  yBaseLineArray[1]-y_range/6*4;
        }

        //yBaseLineArray[1] =  yBaseLineArray[1]-y_range/6*4+20;
        yBaseLineArray[2] =  yBaseLineArray[2]-y_range/6*3;//本该乘以3由于该数据的特殊，所以乘以2
        yBaseLineArray[3] =  yBaseLineArray[3]-y_range/12*3;
        yBaseLineArray[4] =  yBaseLineArray[4]-y_range/6*1;
        yBaseLineArray[5] =  yBaseLineArray[5]-7;


        if( yleadMAXAndMINDiffArray[6] > y_range/6) //判断V1导联是否超过间隔值
        {
             yBaseLineArray[6] = yBaseLineArray[6]-(y_range - yleadMAXAndMINDiffArray[6]);
        }
        else
        {
             yBaseLineArray[6] =  yBaseLineArray[6]-y_range/6*5;
        }

        yBaseLineArray[7] =  yBaseLineArray[7]-y_range/6*4;
        yBaseLineArray[8] =  yBaseLineArray[8]-y_range/6*3;
        yBaseLineArray[9] =  yBaseLineArray[9]-y_range/6*2;
        yBaseLineArray[10] =  yBaseLineArray[10]-y_range/6*1;
        yBaseLineArray[11] =  yBaseLineArray[11]-7;
//        for(int i= 0;i<12;i++)
//        {
//            qDebug()<<"yBaseLineArray["<<i<<"] =  "<< yBaseLineArray[i];
//        }
    }
}

void CustomPlotItem::ecg_Y_BaseLine3(QList<int> YBaseLineArray)
{
    if(YBaseLineArray.length()==6)
    {
        for(int i = 0;i<3;i++)
        {
            yBaseLineArray3[i] = YBaseLineArray[i];
            yleadMAXAndMINDiffArray3[i] = YBaseLineArray[i+3]-YBaseLineArray[i];
        }

        if( yleadMAXAndMINDiffArray3[0] > y_range/3) //判断I导联是否超过间隔值
        {
             yBaseLineArray3[0] = yBaseLineArray3[0]-(y_range - yleadMAXAndMINDiffArray3[0])+50;
        }
        else
        {
             yBaseLineArray3[0] = yBaseLineArray3[0]-y_range/3*2;
        }

        if( yleadMAXAndMINDiffArray3[1] > y_range/3*2) //判断II导联是否超过间隔值
        {
             yBaseLineArray3[1] = yBaseLineArray3[1]-(y_range - yleadMAXAndMINDiffArray3[1]);
        }
        else
        {
             yBaseLineArray3[1] =  yBaseLineArray3[1]-y_range/3*1;
        }

    }
}

void CustomPlotItem::ecg_Y_BaseLine6(QList<int> YBaseLineArray)
{
    if(YBaseLineArray.length()==12)
    {
        for(int i = 0;i<6;i++)
        {
            yBaseLineArray6[i] = YBaseLineArray[i];
            yleadMAXAndMINDiffArray6[i] = YBaseLineArray[i+6]-YBaseLineArray[i];
        }

        if( yleadMAXAndMINDiffArray6[0] > y_range/6) //判断I导联是否超过间隔值
        {
             yBaseLineArray6[0] = yBaseLineArray6[0]-(y_range - yleadMAXAndMINDiffArray6[0])+50;
        }
        else
        {
             yBaseLineArray6[0] = yBaseLineArray6[0]-y_range/6*5;
        }

        if( yleadMAXAndMINDiffArray6[1] > y_range/6*2) //判断II导联是否超过间隔值
        {
             yBaseLineArray6[1] = yBaseLineArray6[1]-(y_range - yleadMAXAndMINDiffArray6[1]);
        }
        else
        {
             yBaseLineArray6[1] =  yBaseLineArray6[1]-y_range/6*4;
        }
        yBaseLineArray6[2] =  yBaseLineArray6[2]-y_range/6*3;//本该乘以3由于该数据的特殊，所以乘以2
        yBaseLineArray6[3] =  yBaseLineArray6[3]-y_range/12*3;
        yBaseLineArray6[4] =  yBaseLineArray6[4]-y_range/6*1;
        yBaseLineArray6[5] =  yBaseLineArray6[5]-7;
    }
}

void CustomPlotItem::ecg_Y_BaseLine1(QList<int> YBaseLineArray)
{
    if(YBaseLineArray.length()==2)
    {

        yBaseLineArray1 = YBaseLineArray[0];
        yleadMAXAndMINDiffArray1 = YBaseLineArray[1]-YBaseLineArray[0];


//        if( yleadMAXAndMINDiffArray1 > y_range) //判断I导联是否超过间隔值
//        {
//             yBaseLineArray1 = yBaseLineArray1-(y_range - yleadMAXAndMINDiffArray6[0])+50;
//        }
//        else
//        {
//             yBaseLineArray1 = yBaseLineArray1;
//        }

//        if( yleadMAXAndMINDiffArray6[1] > y_range/6*5) //判断II导联是否超过间隔值
//        {
//             yBaseLineArray6[1] = yBaseLineArray6[1]-(y_range - yleadMAXAndMINDiffArray6[1]);
//        }
//        else
//        {
//             yBaseLineArray3[1] =  yBaseLineArray3[1]-y_range/6*4;
//        }

    }
}


void CustomPlotItem::paint( QPainter* painter )
{
    if (m_CustomPlot)
    {
        QPixmap    picture(boundingRect().size().toSize());

        //qDebug()<<"This is "<<boundingRect().size().toSize()<<endl;
        QCPPainter qcpPainter( &picture );

        m_CustomPlot->toPainter( &qcpPainter );
        //setRenderTarget(QQuickPaintedItem::FramebufferObject);
        //qDebug()<<"QPoint =  "<<QPoint();
        painter->drawPixmap( QPoint(), picture );
    }
}


void CustomPlotItem::graphClicked( QCPAbstractPlottable* plottable )
{
    qDebug() << Q_FUNC_INFO << QString( "Clicked on graph '%1 " ).arg( plottable->name() );
}

//void CustomPlotItem::routeMouseEvents( QMouseEvent* event )
//{
//    if (m_CustomPlot)
//    {
//        QMouseEvent* newEvent = new QMouseEvent( event->type(), event->localPos(), event->button(), event->buttons(), event->modifiers() );
//        QCoreApplication::postEvent( m_CustomPlot, newEvent );
//    }
//}

//void CustomPlotItem::routeWheelEvents( QWheelEvent* event )
//{
//    if (m_CustomPlot)
//    {
//        QWheelEvent* newEvent = new QWheelEvent( event->pos(), event->delta(), event->buttons(), event->modifiers(), event->orientation() );
//        QCoreApplication::postEvent( m_CustomPlot, newEvent );
//    }
//}

void CustomPlotItem::updateCustomPlotSize()
{
    if (m_CustomPlot)
    {
        m_CustomPlot->setGeometry(0, 0, (int)width(), (int)height());
        m_CustomPlot->setViewport(QRect(0, 0, (int)width(), (int)height()));
    }
}

void CustomPlotItem::removeGraphData(quint8 leadnum,quint16 pos)
{
    for(quint8 i =0;i<10;i++)
    {
        //m_CustomPlot->graph(leadnum)->data()->;
        m_CustomPlot->graph(leadnum)->data()->remove(pos+i);
    }
}

void CustomPlotItem::onCustomReplot()
{
   // qDebug() << Q_FUNC_INFO;
    update();
}
