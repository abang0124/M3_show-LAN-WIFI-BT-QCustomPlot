#ifndef M3SHOWCONTROLLER_H
#define M3SHOWCONTROLLER_H

#include <QObject>
#include <QDateTime>
#include <QDebug>
#include <QList>
#include <QtMath> //使用Qt中的数学运行库
#include <QTimer> //使用定时器更新数据
#include <QSerialPort> //使用串口
#include <QTextStream> //使用数字流
#include <QThread>     //使用线程类
#include <QMessageBox>
#include <QTime>   //时间类
#include <QDate>   //日期类
#include <QQmlListProperty> //QML中的数组类使用该类将C++中的类list的数据传递给QML作为数组使用

#include <algorithm> //利用标准库求列表中的最小值

#include <QFile>
#include <QFileInfo>
#include <QTextStream>


#include "dataacquisition.h" //数据采集类
#include "audiothread.h"  //使用多线程播放报警声
#include "screencapture.h" //屏幕截屏头文件
#include "dbus_connman.h"  //网络连接的管理
//M3 界面的数据控制类，管理M3的数据和其他的类与界面的数据交换与显示
/*
1 添加时间的显示time c++中对应的变量为m_time
2 电池的电量信息

*/

#define LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST  50   //要求平均值的LIST的长度

class M3ShowController : public QObject
{
    Q_OBJECT
public:
    explicit M3ShowController(QObject *parent = nullptr);
    QTimer *tm;

    QTimer *testTimer;
    qreal index = 0.0;
    QSerialPort *sampleSerialPort; //采集模块用到的串口
    DBusConnman *dbusConn;
    quint8 btOpenStatus ;//蓝牙打开标志位

    DataAcquisition *dataAcquisition;

    //基线初步计算完成的标志位
    bool baseLineCalOvered = false;

    //AudioThread *audioAlarm;       //报警声音类
    void serialPortInit(void);//串口初始化函数
    Q_INVOKABLE int sPO2DataCount(void);
    Q_INVOKABLE QList<int> getSPO2Data(void);
    Q_INVOKABLE void clearSPO2Data(void);




    Q_INVOKABLE void transmitNIBPStartSignal(void);
    Q_INVOKABLE void transmitNIBPStopSignal(void);
   // Q_INVOKABLE QList<qreal> getECGShowArray(int i);
    Q_INVOKABLE QList<int> getECG1leadShowArray(int i); //1导联专用
    Q_INVOKABLE QList<int> getECGShowArray(int i); //3导联专用
    Q_INVOKABLE QList<int> getECG6ShowArray(int i); //6导联专用
    Q_INVOKABLE QList<int> getECG12ShowArray(int i); //12导联专用
    Q_INVOKABLE void ecg3or12changed(bool);
    Q_INVOKABLE void warnSetBackToDefalut(void);
    Q_INVOKABLE void clearECGData(void);
    Q_INVOKABLE void showOverAndClear(void); //显示结束并且可以清零

    Q_INVOKABLE void setGetECGDataTimerFlagTrue(void);//设置标志位为真
    Q_INVOKABLE void setGetECGDataTimerFlagFalse(void);//设置标志位为假
    //Q_INVOKABLE void setLeadsShowType(int i);//设置导联要显示的类型 //i = 0 一个页面3导联显示 i=1一个页面6导联显示   i=2一个页面12导联显示
    Q_INVOKABLE void alarmPlay(int level);    //播放声音，供QML使用

    //报警声音关闭
    Q_INVOKABLE void alarmSoundVolume(int value); //设置报警声音的大小

    //等待主界面加载完成 开始控制串口接收数据
    Q_INVOKABLE void uiLoadCompleted(void);   //UI界面加载完成

    //屏幕截屏指令接口函数
    //Q_INVOKABLE void screenShot();//对页面的屏幕截屏函数

    //网络传输2选1
    Q_INVOKABLE bool enableWifi(void); //打开无线
    Q_INVOKABLE bool enableLan(void);  //打开有线
    Q_INVOKABLE void enableBluetooth(void); //打开蓝牙
    Q_INVOKABLE void setLanIPAdddress(void); //设置有线网络的IP 网关，子网掩码的地址
    Q_INVOKABLE void connectWifi(QString wifiName,QString passCode); //连接wifi，并传递wifi密码
    Q_INVOKABLE void disconnectWifi(QString wifiName);  //断开已经连接的wifi wifiName是要断开的wifi的名字
    Q_INVOKABLE void scanWifi(void);                //扫描无线网络

    Q_INVOKABLE QString readBtName(void);
    Q_INVOKABLE void writeBtName(QString);

    //标题栏的数据
    Q_PROPERTY(QString time READ time WRITE setTime NOTIFY timeChanged) //系统的时间参数
    Q_PROPERTY(QString date MEMBER m_date NOTIFY dateChanged)           //系统的日期参数
    Q_PROPERTY(unsigned int batValue READ batValue WRITE setBatValue NOTIFY batValueChanged)//电池电量的数据
    Q_PROPERTY(bool chargeFlag READ chargeFlag WRITE setChargeFlag NOTIFY chargeFlagChanged)//充电图标有变化



    QString time(void) const; //时间的读取方法
    void setTime(QString tm); //时间的设置当法
    unsigned int batValue() const; //电池电量的读取方法
    void setBatValue(unsigned int val);//电池电量的设置方法
    bool chargeFlag(void) const;//电池充电图标的读取
    void setChargeFlag(bool show);//写入电池的充电图标状态



    //心率框的数据
    Q_PROPERTY(QString heartRate READ heartRate WRITE setHeartRate NOTIFY heartRateChanged) //心率参数


    QString heartRate(void);
    void setHeartRate(QString);

    //血压框的数据 //暂时先添加血压值 不添加历史记录值
    Q_PROPERTY(QString bPValue READ bPValue WRITE setBPValue NOTIFY bPValueChanged)         //血压参数

    QString bPValue(void);
    void setBPValue(QString bpValue);

    Q_PROPERTY(bool autoMeasureNIBPFlag READ getNIBPAutoFlag WRITE setNIBPAutoFlag NOTIFY autoMeasureNIBPFlagChanged)
    Q_PROPERTY(int autoMeasureNIBPMinut READ getAutoMeasureMinute WRITE setAutoMeasureMinute NOTIFY autoMeasureMinuteChanged) //自动测量的间隔时间(单位是分钟)

    bool getNIBPAutoFlag(void);
    void setNIBPAutoFlag(bool);
    int getAutoMeasureMinute(void);
    void setAutoMeasureMinute(int);

    //Q_PROPERTY(QString bPValue MEMBER )
    //血氧框的数据
    Q_PROPERTY(QString spo2Num READ spo2Num WRITE setSpo2Num NOTIFY spo2NumChanged)     //血氧值
    Q_PROPERTY(QString piNum READ piNum WRITE setpiNum NOTIFY piNumChanged)     //pI值
    Q_PROPERTY(quint8 columHeight MEMBER m_columHeight NOTIFY columHeightChanged) //脉搏柱的高度值

    QString spo2Num(void);
    void setSpo2Num(QString spo2txt);
    QString piNum(void);
    void setpiNum(QString piNumtxt);
    //数据属性
    //心电图的数据属性
    //Q_PROPERTY(QQmlListProperty<float> leadIArray READ leadIArray)           //导联I的数据容器类 在QML中只能在当前的类中可访问

    //QQmlListProperty<float> leadIArray(); //构造函数



    //底部按键栏
    Q_PROPERTY(bool recordECGFlag READ getRecordECGFlag WRITE setRecordECGFlag NOTIFY recordECGFlagChanged) //底部按键栏的心电记录按钮
    bool getRecordECGFlag(void);
    void setRecordECGFlag(bool);
    bool m_recordECGFlag = false;



    //滤波选择页面
    Q_PROPERTY(quint8 lpSelectIndex READ getLPSelectIndex WRITE setLPSelectIndex NOTIFY lpSelectIndexChanged)
    quint8 getLPSelectIndex(void);
    void setLPSelectIndex(quint8);
    quint8 m_lpSelectIndex = 3; //0 25Hz           1  40Hz           2  150Hz         3 不滤波


    Q_PROPERTY(quint8 hpSelectIndex READ getHPSelectIndex WRITE setHPSelectIndex NOTIFY hpSelectIndexChanged)
    quint8 getHPSelectIndex(void);
    void setHPSelectIndex(quint8);
    quint8 m_hpSelectIndex = 4; //0 0.05Hz         1  1.15Hz        2  0.3Hz     3  0.67Hz     4 不滤波


    Q_PROPERTY(quint8 acSelectIndex READ getACSelectIndex WRITE setACSelectIndex NOTIFY acSelectIndexChanged)
    quint8 getACSelectIndex(void);
    void setACSelectIndex(quint8);
    quint8 m_acSelectIndex = 2;  //0  50Hz        1 60Hz       2或3 不滤波

    //病人类型对话框
    Q_PROPERTY(quint8 patientType READ getPatientType WRITE setPatientType NOTIFY patientTypeChanged)
    quint8 getPatientType(void);
    void setPatientType(quint8);
    quint8 m_patientType = 0;    //0 成人          1 儿童        后续还可以在添加其它类型

    //报警阈值设置界面
    //确定现在设置的是宽阈值还是窄阈值 窄阈值 = true 宽阈值 = false
    Q_PROPERTY(bool wideOrNarrowThresHoldPage READ getWideOrNarrowThresHoldPage WRITE setWideOrNarrowThresHoldPage NOTIFY wideOrNarrowThresHoldPageChanged)//确定现在设置的是宽阈值还是窄阈值 宽阈值=0窄阈值=1
    bool getWideOrNarrowThresHoldPage(void);
    void setWideOrNarrowThresHoldPage(bool);
    bool m_WideOrNarrowThresHoldPage;
    //确定当前是窄阈值被选中还是宽阈值被选中 窄阈值 = true 宽阈值 = false
    Q_PROPERTY(bool wideOrNarrowThresHoldChoice READ getWideOrNarrowThresHoldChoice WRITE setWideOrNarrowThresHoldChoice NOTIFY wideOrNarrowThresHoldChoiceChanged)//确定现在选中的是宽阈值还是窄阈值 宽阈值=0窄阈值=1
    bool getWideOrNarrowThresHoldChoice(void);
    void setWideOrNarrowThresHoldChoice(bool);
    bool m_WideOrNarrowThresHoldChoice;


    //窄阈值
    //血氧阈值的值
    Q_PROPERTY(quint8 spo2ThresHoldValue READ getSPO2ThresHoldValue WRITE setSPO2ThresHoldValue NOTIFY spo2ThresHoldValueChanged)
    quint8 m_spo2ThresHoldValue;
    quint8 getSPO2ThresHoldValue(void);
    void setSPO2ThresHoldValue(quint8);

    //血氧阈值的报警级别
    Q_PROPERTY(quint8 spo2ThresHoldLevel READ getSPO2ThresHoldLevel WRITE setSPO2ThresHoldLevel NOTIFY spo2ThresHoldLevelChanged)
    quint8 m_spo2ThresHoldLevel;          //报警级别   0  高       1   中       2 低
    quint8 getSPO2ThresHoldLevel(void);
    void setSPO2ThresHoldLevel(quint8);

    //血压阈值的值

    //收缩压的阈值
    Q_PROPERTY(quint8 bpSYSThresHoldValueH READ getBPSYSThresHoldValueH WRITE setBPSYSThresHoldValueH NOTIFY bpSYSThresHoldValueHChanged) //收缩压的阈值
    quint8 m_bpSYSThresHoldValueH;
    quint8 getBPSYSThresHoldValueH(void);
    void setBPSYSThresHoldValueH(quint8);

    Q_PROPERTY(quint8 bpSYSThresHoldValueL READ getBPSYSThresHoldValueL WRITE setBPSYSThresHoldValueL NOTIFY bpSYSThresHoldValueLChanged) //收缩压的阈值
    quint8 m_bpSYSThresHoldValueL;
    quint8 getBPSYSThresHoldValueL(void);
    void setBPSYSThresHoldValueL(quint8);
    //舒张压的阈值
    Q_PROPERTY(quint8 bpDIAThresHoldValueH READ getBPDIAThresHoldValueH WRITE setBPDIAThresHoldValueH NOTIFY bpDIAThresHoldValueHChanged) //舒张压的阈值
    quint8 m_bpDIAThresHoldValueH;
    quint8 getBPDIAThresHoldValueH(void);
    void setBPDIAThresHoldValueH(quint8);

    Q_PROPERTY(quint8 bpDIAThresHoldValueL READ getBPDIAThresHoldValueL WRITE setBPDIAThresHoldValueL NOTIFY bpDIAThresHoldValueLChanged) //舒张压的阈值
    quint8 m_bpDIAThresHoldValueL;
    quint8 getBPDIAThresHoldValueL(void);
    void setBPDIAThresHoldValueL(quint8);





    //高于收缩压的阈值的报警级别
    Q_PROPERTY(quint8 bpSYSThresHoldLevel READ getBPSYSThresHoldLevel WRITE setBPSYSThresHoldLevel NOTIFY bpSYSThresHoldLevelChanged) //高于收缩压的阈值报警级别
    quint8 m_bpSYSThresHoldLevel;        //报警级别   0  高       1   中       2 低
    quint8 getBPSYSThresHoldLevel(void);
    void setBPSYSThresHoldLevel(quint8);
    //低于舒张压的报警级别
    Q_PROPERTY(quint8 bpDIAThresHoldLevel READ getBPDIAThresHoldLevel WRITE setBPDIAThresHoldLevel NOTIFY bpDIAThresHoldLevelChanged) //低于舒张压的阈值报警级别
    quint8 m_bpDIAThresHoldLevel;        //报警级别   0  高       1   中       2 低
    quint8 getBPDIAThresHoldLevel(void);
    void setBPDIAThresHoldLevel(quint8);

    //心率
    //心率过速的阈值
    Q_PROPERTY(quint8 hrFastValue READ getHRFastValue WRITE setHRFastValue NOTIFY hrFastValueChanged) //心率过速的阈值
    quint8 m_hrFastValue;
    quint8 getHRFastValue(void);
    void setHRFastValue(quint8);
    //高于心率过速的报警级别
    Q_PROPERTY(quint8 hrFastLevel READ getHRFastLevel WRITE setHRFastLevel NOTIFY hrFastLevelChanged) //心率过速的阈值
    quint8 m_hrFastLevel;                 //报警级别   0  高       1   中       2 低
    quint8 getHRFastLevel(void);
    void setHRFastLevel(quint8);
    //心动过缓的阈值
    Q_PROPERTY(quint8 hrSlowValue READ getHRSlowValue WRITE setHRSlowValue NOTIFY hrSlowValueChanged) //心率过速的阈值
    quint8 m_hrSlowValue;
    quint8 getHRSlowValue(void);
    void setHRSlowValue(quint8);
    //低于心动过缓的报警
    Q_PROPERTY(quint8 hrSlowLevel READ getHRSlowLevel WRITE setHRSlowLevel NOTIFY hrSlowLevelChanged) //心率过速的阈值
    quint8 m_hrSlowLevel;                 //报警级别   0  高       1   中       2 低
    quint8 getHRSlowLevel(void);
    void setHRSlowLevel(quint8);


    //宽阈值
    //血氧阈值的值
    Q_PROPERTY(quint8 spo2ThresHoldValueWide READ getSPO2ThresHoldValueWide WRITE setSPO2ThresHoldValueWide NOTIFY spo2ThresHoldValueChangedWide)
    quint8 m_spo2ThresHoldValueWide;
    quint8 getSPO2ThresHoldValueWide(void);
    void setSPO2ThresHoldValueWide(quint8);

    //血氧阈值的报警级别
    Q_PROPERTY(quint8 spo2ThresHoldLevelWide READ getSPO2ThresHoldLevelWide WRITE setSPO2ThresHoldLevelWide NOTIFY spo2ThresHoldLevelChangedWide)
    quint8 m_spo2ThresHoldLevelWide;          //报警级别   0  高       1   中       2 低
    quint8 getSPO2ThresHoldLevelWide(void);
    void setSPO2ThresHoldLevelWide(quint8);

    //血压阈值的值

    //收缩压的阈值
    Q_PROPERTY(quint8 bpSYSThresHoldValueHWide READ getBPSYSThresHoldValueHWide WRITE setBPSYSThresHoldValueHWide NOTIFY bpSYSThresHoldValueHChangedWide) //收缩压的阈值
    quint8 m_bpSYSThresHoldValueHWide;
    quint8 getBPSYSThresHoldValueHWide(void);
    void setBPSYSThresHoldValueHWide(quint8);

    Q_PROPERTY(quint8 bpSYSThresHoldValueLWide READ getBPSYSThresHoldValueLWide WRITE setBPSYSThresHoldValueLWide NOTIFY bpSYSThresHoldValueLChangedWide) //收缩压的阈值
    quint8 m_bpSYSThresHoldValueLWide;
    quint8 getBPSYSThresHoldValueLWide(void);
    void setBPSYSThresHoldValueLWide(quint8);




    //舒张压的阈值
    Q_PROPERTY(quint8 bpDIAThresHoldValueHWide READ getBPDIAThresHoldValueHWide WRITE setBPDIAThresHoldValueHWide NOTIFY bpDIAThresHoldValueHChangedWide) //舒张压的阈值
    quint8 m_bpDIAThresHoldValueHWide;
    quint8 getBPDIAThresHoldValueHWide(void);
    void setBPDIAThresHoldValueHWide(quint8);

    Q_PROPERTY(quint8 bpDIAThresHoldValueLWide READ getBPDIAThresHoldValueLWide WRITE setBPDIAThresHoldValueLWide NOTIFY bpDIAThresHoldValueLChangedWide) //舒张压的阈值
    quint8 m_bpDIAThresHoldValueLWide;
    quint8 getBPDIAThresHoldValueLWide(void);
    void setBPDIAThresHoldValueLWide(quint8);






    //高于收缩压的阈值的报警级别
    Q_PROPERTY(quint8 bpSYSThresHoldLevelWide READ getBPSYSThresHoldLevelWide WRITE setBPSYSThresHoldLevelWide NOTIFY bpSYSThresHoldLevelChangedWide) //高于收缩压的阈值报警级别
    quint8 m_bpSYSThresHoldLevelWide;        //报警级别   0  高       1   中       2 低
    quint8 getBPSYSThresHoldLevelWide(void);
    void setBPSYSThresHoldLevelWide(quint8);
    //低于舒张压的报警级别
    Q_PROPERTY(quint8 bpDIAThresHoldLevelWide READ getBPDIAThresHoldLevelWide WRITE setBPDIAThresHoldLevelWide NOTIFY bpDIAThresHoldLevelChangedWide) //低于舒张压的阈值报警级别
    quint8 m_bpDIAThresHoldLevelWide;        //报警级别   0  高       1   中       2 低
    quint8 getBPDIAThresHoldLevelWide(void);
    void setBPDIAThresHoldLevelWide(quint8);

    //心率
    //心率过速的阈值
    Q_PROPERTY(quint8 hrFastValueWide READ getHRFastValueWide WRITE setHRFastValueWide NOTIFY hrFastValueChangedWide) //心率过速的阈值
    quint8 m_hrFastValueWide;
    quint8 getHRFastValueWide(void);
    void setHRFastValueWide(quint8);
    //高于心率过速的报警级别
    Q_PROPERTY(quint8 hrFastLevelWide READ getHRFastLevelWide WRITE setHRFastLevelWide NOTIFY hrFastLevelChangedWide) //心率过速的阈值
    quint8 m_hrFastLevelWide;                 //报警级别   0  高       1   中       2 低
    quint8 getHRFastLevelWide(void);
    void setHRFastLevelWide(quint8);
    //心动过缓的阈值
    Q_PROPERTY(quint8 hrSlowValueWide READ getHRSlowValueWide WRITE setHRSlowValueWide NOTIFY hrSlowValueChangedWide) //心率过速的阈值
    quint8 m_hrSlowValueWide;
    quint8 getHRSlowValueWide(void);
    void setHRSlowValueWide(quint8);
    //低于心动过缓的报警
    Q_PROPERTY(quint8 hrSlowLevelWide READ getHRSlowLevelWide WRITE setHRSlowLevelWide NOTIFY hrSlowLevelChangedWide) //心率过速的阈值
    quint8 m_hrSlowLevelWide;                 //报警级别   0  高       1   中       2 低
    quint8 getHRSlowLevelWide(void);
    void setHRSlowLevelWide(quint8);


    //导联显示类型 i = 0 一个页面3导联显示 i=1一个页面6导联显示   i=2一个页面12导联显示
    Q_PROPERTY(quint8 leadsShowType READ getLeadsShowType WRITE setLeadsShowType NOTIFY leadsShowTypeChanged)
    quint8 m_leadsShowType;
    quint8 getLeadsShowType(void);
    void setLeadsShowType(quint8);


    //导联增益类型

    Q_PROPERTY(quint8 gainType MEMBER m_gainType NOTIFY gainTypeChanged)
    quint8 m_gainType;
    //导联速度类型
    Q_PROPERTY(quint8 speedType MEMBER m_speedType NOTIFY speedTypeChanged)
    quint8 m_speedType;
    //导联的类型 3导联还是12导联
    Q_PROPERTY(quint8 leadsType MEMBER m_leadsType NOTIFY leadsTypeChange) //=0 为12导联  =1为3导联
    quint8 m_leadsType;
    //导联脱落类型
    Q_PROPERTY(bool leadsOffRA MEMBER m_leadsOffRA NOTIFY leadsOffRAChange) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffRA;
    Q_PROPERTY(bool leadsOffLA MEMBER m_leadsOffLA NOTIFY leadsOffLAChange) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffLA;
    Q_PROPERTY(bool leadsOffLL MEMBER m_leadsOffLL NOTIFY leadsOffLLChange) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffLL;
    Q_PROPERTY(bool leadsOffRL MEMBER m_leadsOffRL NOTIFY leadsOffRLChange) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffRL;
    Q_PROPERTY(bool leadsOffV1 MEMBER m_leadsOffV1 NOTIFY leadsOffV1Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV1;
    Q_PROPERTY(bool leadsOffV2 MEMBER m_leadsOffV2 NOTIFY leadsOffV2Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV2;
    Q_PROPERTY(bool leadsOffV3 MEMBER m_leadsOffV3 NOTIFY leadsOffV3Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV3;
    Q_PROPERTY(bool leadsOffV4 MEMBER m_leadsOffV4 NOTIFY leadsOffV4Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV4;
    Q_PROPERTY(bool leadsOffV5 MEMBER m_leadsOffV5 NOTIFY leadsOffV5Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV5;
    Q_PROPERTY(bool leadsOffV6 MEMBER m_leadsOffV6 NOTIFY leadsOffV6Change) //=true 该导联脱落 =false 该导联正常
    quint8 m_leadsOffV6;


    quint8 spo2State;//血氧的状态信息


    Q_PROPERTY(int leadIBaseLine MEMBER m_leadIBaseLine NOTIFY leadIBaseLineChanged) //导联I基准线的值
    int m_leadIBaseLine;
    Q_PROPERTY(int leadIIBaseLine MEMBER m_leadIIBaseLine NOTIFY leadIIBaseLineChanged) //导联II基准线的值
    int m_leadIIBaseLine;
    Q_PROPERTY(int leadIIIBaseLine MEMBER m_leadIIIBaseLine NOTIFY leadIIIBaseLineChanged) //导联III基准线的值
    int m_leadIIIBaseLine;
    Q_PROPERTY(int leadaVRBaseLine MEMBER m_leadaVRBaseLine NOTIFY leadaVRBaseLineChanged) //导联aVR基准线的值
    int m_leadaVRBaseLine;
    Q_PROPERTY(int leadaVLBaseLine MEMBER m_leadaVLBaseLine NOTIFY leadaVLBaseLineChanged) //导联aVL基准线的值
    int m_leadaVLBaseLine;
    Q_PROPERTY(int leadaVFBaseLine MEMBER m_leadaVFBaseLine NOTIFY leadaVFBaseLineChanged) //导联aVF基准线的值
    int m_leadaVFBaseLine;
    Q_PROPERTY(int leadV1BaseLine MEMBER m_leadV1BaseLine NOTIFY leadV1BaseLineChanged) //导联V1基准线的值
    int m_leadV1BaseLine;
    Q_PROPERTY(int leadV2BaseLine MEMBER m_leadV2BaseLine NOTIFY leadV2BaseLineChanged) //导联V2基准线的值
    int m_leadV2BaseLine;
    Q_PROPERTY(int leadV3BaseLine MEMBER m_leadV3BaseLine NOTIFY leadV3BaseLineChanged) //导联V3基准线的值
    int m_leadV3BaseLine;
    Q_PROPERTY(int leadV4BaseLine MEMBER m_leadV4BaseLine NOTIFY leadV4BaseLineChanged) //导联V4基准线的值
    int m_leadV4BaseLine;
    Q_PROPERTY(int leadV5BaseLine MEMBER m_leadV5BaseLine NOTIFY leadV5BaseLineChanged) //导联V5基准线的值
    int m_leadV5BaseLine;
    Q_PROPERTY(int leadV6BaseLine MEMBER m_leadV6BaseLine NOTIFY leadV6BaseLineChanged) //导联V6基准线的值
    int m_leadV6BaseLine;


    Q_PROPERTY(int leadIMaxLine MEMBER m_leadIMaxLine NOTIFY leadIMaxLineChanged) //导联I最高线的值
    int m_leadIMaxLine;
    Q_PROPERTY(int leadIIMaxLine MEMBER m_leadIIMaxLine NOTIFY leadIIMaxLineChanged) //导联II最高线的值
    int m_leadIIMaxLine;
    Q_PROPERTY(int leadIIIMaxLine MEMBER m_leadIIIMaxLine NOTIFY leadIIIMaxLineChanged) //导联III最高线的值
    int m_leadIIIMaxLine;
    Q_PROPERTY(int leadaVRMaxLine MEMBER m_leadaVRMaxLine NOTIFY leadaVRMaxLineChanged) //导联aVR最高线的值
    int m_leadaVRMaxLine;
    Q_PROPERTY(int leadaVLMaxLine MEMBER m_leadaVLMaxLine NOTIFY leadaVLMaxLineChanged) //导联aVL最高线的值
    int m_leadaVLMaxLine;
    Q_PROPERTY(int leadaVFMaxLine MEMBER m_leadaVFMaxLine NOTIFY leadaVFMaxLineChanged) //导联aVF最高线的值
    int m_leadaVFMaxLine;
    Q_PROPERTY(int leadV1MaxLine MEMBER m_leadV1MaxLine NOTIFY leadV1MaxLineChanged) //导联V1最高线的值
    int m_leadV1MaxLine;
    Q_PROPERTY(int leadV2MaxLine MEMBER m_leadV2MaxLine NOTIFY leadV2MaxLineChanged) //导联V2最高线的值
    int m_leadV2MaxLine;
    Q_PROPERTY(int leadV3MaxLine MEMBER m_leadV3MaxLine NOTIFY leadV3MaxLineChanged) //导联V3最高线的值
    int m_leadV3MaxLine;
    Q_PROPERTY(int leadV4MaxLine MEMBER m_leadV4MaxLine NOTIFY leadV4MaxLineChanged) //导联V4最高线的值
    int m_leadV4MaxLine;
    Q_PROPERTY(int leadV5MaxLine MEMBER m_leadV5MaxLine NOTIFY leadV5MaxLineChanged) //导联V5最高线的值
    int m_leadV5MaxLine;
    Q_PROPERTY(int leadV6MaxLine MEMBER m_leadV6MaxLine NOTIFY leadV6MaxLineChanged) //导联V6最高线的值
    int m_leadV6MaxLine;


//    Q_PROPERTY(int leadIMidLine MEMBER m_leadIMidLine NOTIFY leadIMidLineChanged) //导联I中间值线的值
//    int m_leadIMidLine;
//    Q_PROPERTY(int leadIIMidLine MEMBER m_leadIIMidLine NOTIFY leadIIMidLineChanged) //导联II中间值线的值
//    int m_leadIIMidLine;
//    Q_PROPERTY(int leadIIIMidLine MEMBER m_leadIIIMidLine NOTIFY leadIIIMidLineChanged) //导联III中间值线的值
//    int m_leadIIIMidLine;
//    Q_PROPERTY(int leadaVRMidLine MEMBER m_leadaVRMidLine NOTIFY leadaVRMidLineChanged) //导联aVR中间值线的值
//    int m_leadaVRMidLine;
//    Q_PROPERTY(int leadaVLMidLine MEMBER m_leadaVLMidLine NOTIFY leadaVLMidLineChanged) //导联aVL中间值线的值
//    int m_leadaVLMidLine;
//    Q_PROPERTY(int leadaVFMidLine MEMBER m_leadaVFMidLine NOTIFY leadaVFMidLineChanged) //导联aVF中间值线的值
//    int m_leadaVFMidLine;
//    Q_PROPERTY(int leadV1MidLine MEMBER m_leadV1MidLine NOTIFY leadV1MidLineChanged) //导联V1中间值线的值
//    int m_leadV1MidLine;
//    Q_PROPERTY(int leadV2MidLine MEMBER m_leadV2MidLine NOTIFY leadV2MidLineChanged) //导联V2中间值线的值
//    int m_leadV2MidLine;
//    Q_PROPERTY(int leadV3MidLine MEMBER m_leadV3MidLine NOTIFY leadV3MidLineChanged) //导联V3中间值线的值
//    int m_leadV3MidLine;
//    Q_PROPERTY(int leadV4MidLine MEMBER m_leadV4MidLine NOTIFY leadV4MidLineChanged) //导联V4中间值线的值
//    int m_leadV4MidLine;
//    Q_PROPERTY(int leadV5MidLine MEMBER m_leadV5MidLine NOTIFY leadV5MidLineChanged) //导联V5中间值线的值
//    int m_leadV5MidLine;
//    Q_PROPERTY(int leadV6MidLine MEMBER m_leadV6MidLine NOTIFY leadV6MidLineChanged) //导联V6中间值线的值
//    int m_leadV6MidLine;



    QList<int> leadsMinBaseLineNumList[12]; //用来存储每次获取得到最小值
    QList<int> leadsMaxBaseLineNumList[12]; //用来存储每次获取得到最大值
    //QList<int> leadsMidBaseLineNumList[12]; //用来存储每次计算得到中间值 mid = (max-min)/2+min

    int leadsBaseLineNum[12] = {};
    int leadsMaxLineNum[12] = {};
    //int leadsMidLineNum[12] = {};


    Q_PROPERTY(bool ecgShowStopFlag MEMBER m_ecgShowStopFlag NOTIFY ecgShowStopFlagChanged) //心电显示暂停标志位 =true 心电图显示暂停显示  =false 心电图重新开始显示
    bool m_ecgShowStopFlag;

//
    Q_PROPERTY(QString dateAndTime MEMBER m_dateAndTime NOTIFY dateAandTimeChange)
    QString m_dateAndTime;


    Q_PROPERTY(bool warnCloseFlag MEMBER m_warnCloseFlag NOTIFY warnCloseFlagChanged)  // warnCloseFlag  代表报警关闭与否的标志位 =true 报警关闭 =false 报警打开
    bool m_warnCloseFlag;



    //网络状态信息
    Q_PROPERTY(quint8 netTransFlag MEMBER m_netTransFlag NOTIFY netTransFlagChanged)    //网络传输模式的变化 =1 有线传输  =2 wifi传输  =3 蓝牙传输
    quint8 m_netTransFlag;
    //网络相关的参数
    //有线
    Q_PROPERTY(QString lanMacAddress MEMBER m_lanMacAddress NOTIFY lanMacAddressChanged)    //有线网络的mac地址
    QString m_lanMacAddress;
    Q_PROPERTY(QString lanIPAddress MEMBER m_lanIPAddress NOTIFY lanIPAddressChanged)    //有线网络的IP地址
    QString m_lanIPAddress;
    Q_PROPERTY(QString lanNetMask MEMBER m_lanNetMask NOTIFY lanNetMaskChanged)    //有线网络的子网掩码
    QString m_lanNetMask;
    Q_PROPERTY(QString lanNetGate MEMBER m_lanNetGate NOTIFY lanNetGateChanged)    //有线网络的网关
    QString m_lanNetGate;
    //无线
    Q_PROPERTY(QString wlanMacAddress MEMBER m_wlanMacAddress NOTIFY wlanMacAddressChanged)    //有线网络的mac地址
    QString m_wlanMacAddress;
    Q_PROPERTY(QString wlanIPAddress MEMBER m_wlanIPAddress NOTIFY wlanIPAddressChanged)    //有线网络的IP地址
    QString m_wlanIPAddress;

    Q_PROPERTY(QString connectedWIFIName MEMBER m_connectedWIFIName NOTIFY connectedWIFINameChanged)    //无线网络的WIFI名字
    QString m_connectedWIFIName;


    Q_PROPERTY(QMap wifiServiceMap READ getWifiServiceMap WRITE setWifiServiceMap NOTIFY WifiServiceMapChanged)
    QMap<QString,QVariant> m_wifiServiceMap;
    QMap<QString,QVariant> getWifiServiceMap(void);
    void setWifiServiceMap(const QMap<QString,QVariant>);

    //蓝牙
    Q_PROPERTY(QString btMacAddress MEMBER m_BtMacAddress NOTIFY btMacAddressChanged)    //有线网络的mac地址
    QString m_BtMacAddress;
    //蓝牙相关的操作函数
    bool bt_open(void);

signals:


    //发送心电采集信号 ，打开该线程的定时器，定时采集信号
    void starDataAcquSignal();

    //标题栏的信号
    void timeChanged();      //时间的变更信号
    void dateChanged();      //日期变更信号
    void batValueChanged();   //电池电量信息的变化信号S
    void chargeFlagChanged(); //充电状态的变化信号


    //心率框的信号
    void heartRateChanged(); //心率值变化的信号
    //血压框的信号
    void bPValueChanged();   //血压值变化的信号
    //血氧框的信号
    void spo2NumChanged(); //血氧值变化信号
    void piNumChanged();   //血氧PI值的变化信号
    void columHeightChanged(); //血氧脉搏柱的高度变化信号


    void list_SPO2_data_changed(); //血氧曲线值的变化信号
    void test_signal();

    void NIBPStartSignal(void); //血压开始测量信号
    void NIBPStopSignal(void);  //血压停止测量信号

    void testsignal(QList<quint16>,QList<quint16>);
    void list_ECG_data_show_changed(void);  //心电图数据变化信号

     void ecg3or12ChangedSignal(bool);   //心电图的显示界面变化

     //血压设置相关的界面的信号
     void autoMeasureNIBPFlagChanged(void); //自动测量还是手动测量变化
     void autoMeasureMinuteChanged(void);       //自动测量的间隔值发生变化

     //底部按键栏相关的信号
     void recordECGFlagChanged (void);
     void recordECGFlagChangeSignal(bool);

     //滤波页面相关的信号
     void lpSelectIndexChanged(quint8); //低通滤波 =0 25Hz  =1 40Hz  =2 150Hz  =3关闭
     void hpSelectIndexChanged(quint8); //高通滤波 =0 0.05Hz =1 0.15Hz =2 0.3Hz =3 0.67Hz  =4关闭
     void acSelectIndexChanged(quint8); //电源滤波 =0 50Hz  =1 60Hz =2关闭

     //病人类型选择对话框的信号
     void patientTypeChanged(void);
     void patientTypeChangedSignal(quint8);//发送给数据采集类携带病人类型的信号

     //阈值设置相关的信号
     void wideOrNarrowThresHoldPageChanged(void);//设置的是宽阈值还是窄阈值
     void wideOrNarrowThresHoldChoiceChanged(void);//当前选中的是宽阈值还是窄阈值

     //阈值设置相关的信号
     void spo2ThresHoldValueChanged();
     void spo2ThresHoldLevelChanged();
     void bpSYSThresHoldValueHChanged();
     void bpDIAThresHoldValueHChanged();
     void bpSYSThresHoldValueLChanged();
     void bpDIAThresHoldValueLChanged();


     void bpSYSThresHoldLevelChanged();
     void bpDIAThresHoldLevelChanged();


     void hrFastValueChanged();
     void hrFastLevelChanged();
     void hrSlowValueChanged();
     void hrSlowLevelChanged();

     //宽阈值
     void spo2ThresHoldValueChangedWide();
     void spo2ThresHoldLevelChangedWide();
     void bpSYSThresHoldValueHChangedWide();
     void bpDIAThresHoldValueHChangedWide();
     void bpSYSThresHoldValueLChangedWide();
     void bpDIAThresHoldValueLChangedWide();

     void bpSYSThresHoldLevelChangedWide();
     void bpDIAThresHoldLevelChangedWide();
     void hrFastValueChangedWide();
     void hrFastLevelChangedWide();
     void hrSlowValueChangedWide();
     void hrSlowLevelChangedWide();



     //心电数据发送与接收同步的信号
     void ECGDataProcessedSignal();


     //界面显示导联类型发生变化的信号
     void leadsShowTypeChanged(quint8);
     //电池电量信号
     void batValSendSig(int,int);
     //增益选择变化信号
     void gainTypeChanged();
     //速度选择变化信号
     void speedTypeChanged();
     //导联类型变化信号
     void leadsTypeChange();


     //发送报警信号给显示界面
     void warnMessage2MainPage(int warnType,int warnLevel);//warnType就是报警类型 warnLevel 是报警级别
     //报警声音类的相关信号
     void warnAlarmSignal(int level); //level报警等级 =0 高  =1 中 =2 低

     //导联脱落信号变化
     void leadsOffRAChange(void);
     void leadsOffLAChange(void);
     void leadsOffLLChange(void);
     void leadsOffV1Change(void);
     void leadsOffV2Change(void);
     void leadsOffV3Change(void);
     void leadsOffV4Change(void);
     void leadsOffV5Change(void);
     void leadsOffV6Change(void);
     void leadsOffRLChange(void);


//导联基线值的变化信号
     void leadIBaseLineChanged(void);
     void leadIIBaseLineChanged(void);
     void leadIIIBaseLineChanged(void);
     void leadaVRBaseLineChanged(void);
     void leadaVLBaseLineChanged(void);
     void leadaVFBaseLineChanged(void);
     void leadV1BaseLineChanged(void);
     void leadV2BaseLineChanged(void);
     void leadV3BaseLineChanged(void);
     void leadV4BaseLineChanged(void);
     void leadV5BaseLineChanged(void);
     void leadV6BaseLineChanged(void);

     void leadIMaxLineChanged(void);
     void leadIIMaxLineChanged(void);
     void leadIIIMaxLineChanged(void);
     void leadaVRMaxLineChanged(void);
     void leadaVLMaxLineChanged(void);
     void leadaVFMaxLineChanged(void);
     void leadV1MaxLineChanged(void);
     void leadV2MaxLineChanged(void);
     void leadV3MaxLineChanged(void);
     void leadV4MaxLineChanged(void);
     void leadV5MaxLineChanged(void);
     void leadV6MaxLineChanged(void);


//     void leadIMidLineChanged(void);
//     void leadIIMidLineChanged(void);
//     void leadIIIMidLineChanged(void);
//     void leadaVRMidLineChanged(void);
//     void leadaVLMidLineChanged(void);
//     void leadaVFMidLineChanged(void);
//     void leadV1MidLineChanged(void);
//     void leadV2MidLineChanged(void);
//     void leadV3MidLineChanged(void);
//     void leadV4MidLineChanged(void);
//     void leadV5MidLineChanged(void);
//     void leadV6MidLineChanged(void);


//设置声音的大小
     void setAlarmSoundVolume(int value);

//心电图显示暂停标志位发生变化的信号
     void ecgShowStopFlagChanged(void);
//要设置的时间发生了变化
     void dateAandTimeChange(void);
//报警关闭的标志位发生了变化
     void warnCloseFlagChanged(void);
//将UI加载完成的信号发送给数据采集类，数据采集类受到此信号，初始化串口
     void sendUILoadCompleted2dataAcq(void);


//网络传输方式变化的信号
     void netTransFlagChanged(void);
//网络信息相关的信号
     void lanMacAddressChanged(void);
     void lanIPAddressChanged(void);
     void lanNetMaskChanged(void);
     void lanNetGateChanged(void);
     void wlanMacAddressChanged(void);
     void wlanIPAddressChanged(void);
     void WifiServiceMapChanged(void);
     void serviceChangeCompleted(void);
     void btMacAddressChanged(void);
//网络模式切换后IP地址的完成的信号
     void netChangedAndIPAddressGeted(void);
     void connectedWIFINameChanged(void); //连接的网络的WIFI名字发生变化
     //void netStateGetCompleted(void); //网络状态获取完成

// 蓝牙相关的信号
     void bluetoothOpenSig(bool);   //蓝牙的开和关信号
     void btConnected(void); //蓝牙连接信号
     void btDisconnected(void);//蓝牙断开连接信号
     void btOpenResult(bool);//蓝牙打开是否成功的信号
     //void btOpenSuccessed(void);//蓝牙打开成功
     //void btOpenFailed(void);//蓝牙打开失败

//     //关于阈值 默认值相关的信号
//     //阈值设置相关的信号
//     void default_wideOrNarrowThresHoldPageChanged(void);//设置的是宽阈值还是窄阈值
//     void default_wideOrNarrowThresHoldChoiceChanged(void);//当前选中的是宽阈值还是窄阈值

//     //阈值设置相关的信号
//     void default_spo2ThresHoldValueChanged();
//     void default_spo2ThresHoldLevelChanged();
//     void default_bpSYSThresHoldValueChanged();
//     void default_bpDIAThresHoldValueChanged();
//     void default_bpSYSThresHoldLevelChanged();
//     void default_bpDIAThresHoldLevelChanged();
//     void default_hrFastValueChanged();
//     void default_hrFastLevelChanged();
//     void default_hrSlowValueChanged();
//     void default_hrSlowLevelChanged();

//     //宽阈值
//     void default_spo2ThresHoldValueChangedWide();
//     void default_spo2ThresHoldLevelChangedWide();
//     void default_bpSYSThresHoldValueChangedWide();
//     void default_bpDIAThresHoldValueChangedWide();
//     void default_bpSYSThresHoldLevelChangedWide();
//     void default_bpDIAThresHoldLevelChangedWide();
//     void default_hrFastValueChangedWide();
//     void default_hrFastLevelChangedWide();
//     void default_hrSlowValueChangedWide();
//     void default_hrSlowLevelChangedWide();



private:
    QString m_time;         //时间信息
    QString m_date;         //日期信息
    unsigned int m_batValue;  //电池电量信息
    bool m_chargeFlag;        //充电标志显示与否

    unsigned int m_hearRate;  //心率值

    unsigned int m_bpValue_sys ; //血压值收缩压
    unsigned int m_bpValue_dia ; //血压值舒张压

    quint8 m_spo2Num;
    float m_piNum;
    quint8 m_columHeight;

    bool m_NIBP_AutoMeasureFlag = false;  //血压自动测量还是手动测量的标志位
    int  m_AutoMeasureNIBPMinut = 10;       //血压自动测量的间隔时间(单位是分钟)

    bool getECGDataTimerRunningFlag;  //定时获取ECG数据的定时开关状态设置为关

    quint8 lead3_show_count = 15;
    quint8 lead1_show_count = 15;
    quint8 lead12_show_count ;
    quint8 lead6_show_count ;

    QString cmd; //使用system 设置时间相关的命令

    //以下是显示曲线需要用到的数值
    //心电曲线数据的值与数据

//    QList<float> listI;
//    QList<float> listII;
//    QList<float> listIII;
//    QList<float> listaVR;
//    QList<float> listaVL;
//    QList<float> listaVF;
//    QList<float> listV1;
//    QList<float> listV2;
//    QList<float> listV3;
//    QList<float> listV4;
//    QList<float> listV5;
//    QList<float> listV6;
    QList<int> leadsShowArray[12];//12导联的数据，解说采集类传过来的值，为显示的1级缓冲
    QList<int> transToECGshowArray[12];//传递给界面心电图显示的数据 显示,将12导联的数据*100，转换为整型传递给QML中，再由QML处理为原数据
    //血氧曲线的值与数据
    QList<int> listSPO2;
    //Q_INVOKABLE QList<qreal> getECGData(int i);
    void turnECGData2OtherList1leads(int i,int len);
    void turnECGData2OtherList3leads(int i,int len);
    void turnECGData2OtherList6leads(int i,int len);

    void getLANMessages(void); //获取有线网络相关的信息，网卡地址.IP地址.子网掩码.网关
    void getWLANMessages(void); //获取无线网络相关的信息，网卡地址.IP地址




public:
    unsigned int uintindex;
public slots:
    void time_upadate_slot();
    void onTestTimer();
 //   void serialport_recive_data(void);
    void onRecNIBPDataFromDataAcq(QList<quint16> *NIBPSYSData,QList<quint16> *NIBPDIAData);//接收从数据采集类得到的血压测量的数据
   // M3_SPO2_PI_data,M3_SPO2_data,M3_SPO2_pulse_rata,M3_SPO2_pulse_column,M3_SPO2_waves
    void onRecSPO2DataFromDataAcq(QList<quint8> *PI,QList<quint8> *data,QList<quint8> *rata,QList<quint8> *column,QList<quint8> *waves,QList<quint8> *state);
    void onRecHeartRateFromDataAcq(quint16 heartRate);
    void onRecLeadsShowDataFromDataAcq(QList<int>[12]);       //接收来自数据采集类的ecg曲线数据
    void onMeasureNIBPFlagChanged(void);                        //血压自动测量标志发生了改变
    void onMeasureMinuteChanged(void);

    void onRecordECGFlagChanged(void);            //心电记录标志位改变的槽函数 处理函数
    void onPatientTypeChanged(void);              //当病人类型发生改变时
    void onRecBatValSignal(int val,int val2);     //数据采集类传递过来的数据，val为电池电量，val2为电池的充电状态
    void onRecLeadsOffSignalFromDataAcq(int leadsOffData); //处理数据采集类传递过来的导联脱落数据
    void onDataAndTimeChanged(void); //系统时间发生改变
    void netTransFlagChangeRev(void); //网络传输模式的改变

    void onDBusServiceChanged(int type);  //用于接受dbus_connman类的service_changed信号

    void onRecCanGetIPAddress();//用于接受网络状态变更完成的信号，同时完成当前网络状态的IP 地址的变化
    void onNetTransFlagChanged();//用于接受网络传输类型发生改变



    //蓝牙相关的槽函数
    void onRecBluetoothOpenResult(bool,QString); //接受蓝牙打开结果的槽函数
//    void btOpenSuccessed(void);//蓝牙打开成功
//    void btOpenFailed(void);//蓝牙打开失败



};

#endif // M3SHOWCONTROLLER_H
