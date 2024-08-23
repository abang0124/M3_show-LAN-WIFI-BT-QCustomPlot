#ifndef DATAACQUISITION_H
#define DATAACQUISITION_H

#include <QObject> //数据采集类，通过串口与采集模块进行通信 采集模块为STM32F405
#include <QSerialPort> //串口通信相关的类
#include <QMessageBox> //提示框类
#include <QTimer>
#include <QDebug>
#include <QList>
#include <ecgdataprocess.h> //心电数据处理类，获取心率和心电图的滤波等
#include <QDateTime>
#include <stdlib.h> //打开设备驱动节点，使用标准库函数
#include <fcntl.h> //Qt下使用linux的open，read，write等函数
#include <battery.h> //将电池类头文件加入
#include <QDir>
#include <QTcpSocket>
#include <QHostAddress>
#include <QNetworkConfigurationManager>  //检测网线是否插入

#include <QTcpServer> //将M3定义为数据的服务器
#include <QBluetoothLocalDevice>  //蓝牙设备本地类
#include <QBluetoothDeviceInfo>   //蓝牙设备信息类
#include <QBluetoothUuid>         //蓝牙设备UUID类
#include <bluetoothserver.h>      //自己编写的蓝牙服务类

#define I   0
#define II  1
#define III 2
#define aVR 3
#define aVL 4
#define aVF 5
#define V1  6
#define V2  7
#define V3  8
#define V4  9
#define V5  10
#define V6  11
#define LEAD3COUNT     5 //每次显示3个导联的界面  每隔25个数据取一个值 降低CPU的显示压力
#define LEAD12COUNT    5 //显示12导联的界面      每隔30个数据取一个值 降低CPU的显示压力
#define FILTER_LEN     50//修改此数据的时候，注意！！！！！！ ecg_real_data_array_after_LP_filter ecg_real_data_array_after_HP_filter ecg_real_data_array_after_AC_filter 这几个数组的长度  100//100//1000个点，速率太慢。调整为100个点   1000 //要滤波的数据的长度
#define FILTER_LEN_MAX 125 //根据滤波数组长度为1500计算出来的 125*12=1500
#define FILTER_ARRAY_LEN (FILTER_LEN_MAX*12) //滤波数组的长度
#define HR_CAL_COUNT_LEN   2000  //心率计算的 间隔  HR_CAL_COUNT_LEN相当于每隔HR_CAL_COUNT_LEN这么个点数计算一次心率
#define NET_PORT        9999
#define NET_ADDRESS     "192.168.1.100"

/*
 * 数据采集类
 * 主要功能是对接M3上的数据采集模块(STM32F405)通过串口接受采集模块传上来的心电，血氧，血压的数据
 * 将协议的内容进行解析，并且对采集模块发送指令，控制采集模块的采集，将采集上来的数据进行处理，心电数据交给
 * 心电算法的模块进行处理，并将处理过的数据交给界面显示出来，血氧和血压模块得到相应的数据，将数据交给显示模块
 * 将数据显示出来
*/


class DataAcquisition : public QObject
{
    Q_OBJECT
private:
    void ECGDataProcessedTrans(void);//ECG心电数据处理并且发送
    void AcordingLeasTypeTransECGData(void);
public:
    explicit DataAcquisition(QObject *parent = nullptr);
    ECGDataProcess *ecgDataProc; //数据处理类
    QTimer *tm;
    QSerialPort *acqusitionPort; //采集端口
    void SerialPortInit();//串口初始化。初始化串口相关的内容，波特率之类的

    //void startDataAcq();  //开启数据采集
    void AcqDataAnalyse(QByteArray buf);
    void getECGdata(int i,QByteArray *buf);
    void ecgDataFilter(); //对心电数据进行滤波
    void recordECGDataAfterFilter2File(int length);//将滤波后的心电数据存入文件当中

    void ECGDataAbrutProcess(int ); //ECG突兀数值的判断
    BluetoothServer *btServer;  //定义蓝牙的服务器对象指针
//    bool BluetoothOpen();  //蓝牙打开
//    void BluetoothClosed(); //蓝牙关闭

    float baseLineArray[12] = {500.0,-61100.0,-61500.0,30020.0,31300.0,-61500.0,-45100.0,-43500.0,-43770.0,-44770.0,-43670.0,-44670.0};

    quint8 ecgcount;
    bool ECGDataAbrutFlag = false;  //为真，检测到心电图有突兀的值，为假则没有突兀的值，为滤掉心电途中的突兀值的标志位
    QList<float> *M3_ecg_real_data;      //ecg的真实，小数数据由M3_ecg_data除以AD基数而来
    QList<int>   M3_ecg_data;           //串口收到的AD采集值的数据
    QList<quint16>   M3_BP_sys_data;        //存储收缩压
    QList<quint16>   M3_BP_dia_data;         //存储舒张压
    QList<quint8>   M3_SPO2_Sta_data;       //存储血氧的状态信息
    QList<quint8>   M3_SPO2_PI_data;        //存储血氧PI灌注指数
    QList<quint8>   M3_SPO2_data;           //存储血氧值
    QList<quint8>   M3_SPO2_pulse_rata;     //存储血氧脉率值
    QList<quint8>   M3_SPO2_pulse_column;   //存储血氧脉搏柱
    QList<quint8>   M3_SPO2_waves;          //存储血氧容积波
    QList<float> ecg_real_data_array[12];   //存储所有滤波完成后的数据，用于显示，计算心率等
    QList<float> ecg_real_data_list_before_filter[12]; //用于存储从采集模块采集上来的最原始的数据，未经过滤波
    QList<float> ecg_real_data_list_before_filter_temp[12]; //用于存储从采集模块采集上来的最原始的数据，未经过滤波,用于临时存储，筛选是否为突兀值
    QList<float> ecg_real_data_list_after_filter_store_tofile[12]; //用于存储经过滤波后的数据，此列表用来临时存储需要保存时候的数据
    QList<float> ecg_real_data_array_for_show[12];     //用于存储滤波后需要传递给显示需要的数据列表
//    QList<float> ecg_real_data_arrat_after_LP_filter[12]; //用于存储经过LP滤波后的数据
//    QList<float> ecg_real_data_arrat_after_HP_filter[12]; //用于存储经过HP滤波后的数据
    float ecg_real_data_array_before_filter[FILTER_LEN_MAX*12]; //用于存储经过HP滤波后的数据
    float ecg_real_data_array_after_LP_filter[FILTER_LEN_MAX*12]; //用于存储经过LP滤波后的数据
    float ecg_real_data_array_after_HP_filter[FILTER_LEN_MAX*12]; //用于存储经过HP滤波后的数据
    float ecg_real_data_array_after_AC_filter[FILTER_LEN_MAX*12]; //用于存储经过LP滤波后的数据
    //QList<float> ecg_real_data_list_after_AC_filter[12]; //用于存储经过AC滤波后的数据
    bool filterFirstFlag;//用于标记是否第一次滤波 =true 是第一次滤波 =false 不是第一次滤波

    QList<int> ecg_real_data_processed_array[12];   //存储将原有的数据除以(3导联显示界面为5，12导联显示界面为5)之后的数据
    QList<int> ecg_processed_data_trans_array[12];  //存储ecg处理完的将要发送给页面的数据
    QList<qint32> ecg_ori_data_array[12];   //存储原始数值
    QList<quint32> batValList;  //存储读取电池电量的值，用于计算平均值
    bool ECGDataRevProcessedFlag;

    //bool threeLeadOr12Leadshow;  //判断当前的显示界面是3导联显示还是12导联显示 true 3导联显示 false 12导联显示
    quint8 leadsShowType;//判断当前导联单个页面显示的类型，0是3导联显示 1是6导联显示 2是12导联显示
    //测试串口读到的ECG数据，将数据存储到文件中
    bool recordECGFlag;
    QFile *ecgfile ;
    QFile *oriecgfile;
    QTextStream *filestream;
    QTextStream *orifilestream;  //原始数据的数据流，测试用 测试高通滤波数据
    QTcpSocket *dataSocket;      //TCP客户端，通过此套接字向电脑上传数据。将串口传过来的数据通过网口直接转发给电脑，目前是通过网线往电脑传


    //电池电量的驱动文件
    Battery *bat;
    QTimer *batTimer; //定时读取电池电量
    quint32 batAveragePre = 0 ;//用于存储电池电量上一次的值，与本次只做比较，分为两种状态。如果为充电状态，则以高值为准，如果是放电状态，则以低值为准

    //滤波类型的选择
    quint8 LP_type;  //低通滤波 =0 25Hz  =1 40Hz  =2 150Hz  =3关闭
    quint8 HP_type;  //高通滤波 =0 0.05Hz =1 0.15Hz =2 0.3Hz =3 0.67Hz  =4关闭
    quint8 AC_type;  //电源滤波 =0 50Hz  =1 60Hz =2关闭
    //quint8 batTimerCount = 0;//定时器计数，开始定时器时间间隔比较小，后续时间见间隔变大

    quint8 PatientType = 0; //=0 成人模式   =1 儿童模式

    quint16 hr_calculate_count = 0;//心率计算计数
    bool hr_calculate_flag = true;  //心率计算标志位


    //int byteArrayLeftLength = 0;//心电数据在不足一帧的长度时，剩余数据的长度
    QByteArray leftDataArray ; //剩余数据存放的ByteArray
    QNetworkConfigurationManager *netmanage;
    bool netConnectedFlag = false;
    QByteArray socketReadBuf;
    QTcpServer *ts; //
    QString str;
//蓝牙传输相关的变量
    bool btTransDataFlag = false;  //使用蓝牙传输数据的标志位 默认为false
    //QBluetoothLocalDevice *localBluetoothDevice; //本地蓝牙设备
   // QList<QBluetoothHostInfo> localAdapters;

signals:
    void NIBPData2M3DataControl(QList<quint16>*,QList<quint16>*);
    void SPO2Data2M3DataControl(QList<quint8>*,QList<quint8>*,QList<quint8>*,QList<quint8>*,QList<quint8>*,QList<quint8>*);
    void HeartRate2M3DataControl(quint16); //传递心率的数值
    void LeadsShowData2M3DataControl(QList<int>[12]); //传递心电显示曲线的数据
    void batValSignal(int,int);
    void leadOffSignal2M3DataControl(int); //将导联脱落相关的信息(哪个导联，以及该导联的状态(脱落和未脱落))发送给数据控制类，int代表导联脱落的类型

    //蓝牙相关的信号
//    void BtClientConnected(const QString &name); //蓝牙已连接信号
//    void BtClientDisconnected(const QString &name);//蓝牙已断开信号
    void BtClientConnected(); //蓝牙已连接信号
    void BtClientDisconnected();//蓝牙已断开信号
    void BtTransData(const QByteArray buf);
//    void BtOpenSuccessed(); //蓝牙打开成功
//    void BtOpenFailed();    //蓝牙打开失败
    void bluetoothOpenResult(bool,QString);//蓝牙打开结果的信号 并传递蓝牙的mac地址

public slots:
    void dataAcq();       //数据采集,读取串口数据
    void onRecNIBPStartSignal(); //血压开始测量
    void onRecNIBPStopSignal();  //血压停止测量
    //void onECG3or12Changed(bool);
    void onRecordECGFlagChangeSignal(bool); //心电记录标志位改变在数据采集类的槽函数，处理数据
    void onRecPatientTypeChanged(quint8 patientType);//数据采集类在病人类型发生改变时，做相应的处理
    void onRcvECGDataProcessedSignal(void);          //接受来自数据处理类数据处理完毕的信号，实现心电数据发送与接受的同步的功能
    //void onRecNIBPDataFromDataAcqtest(QList<quint16>,QList<quint16>);
    void onRecLeadsShowTypeChangedSignal(quint8);
    void readBatVal(void);
    void onDataAcquisitionThreadCreat(void);//在该函数中添加该线程用到的所有对象
    void startDataAcq();  //开启数据采集

    void onRecLP_typeChanged(quint8); //LP滤波类型有变化   //低通滤波 =0 25Hz  =1 40Hz  =2 150Hz  =3关闭
    void onRecHP_typeChanged(quint8); //HP滤波类型有变化   //高通滤波 =0 0.05Hz =1 0.15Hz =2 0.3Hz =3 0.67Hz  =4关闭
    void onRecAC_typeChanged(quint8); //AC滤波类型有变化   //电源滤波 =0 50Hz  =1 60Hz =2关闭
    void calculate_HR_and_emitSignal(int);//计算心率并发送心率信号
    void onRecUILoadCompleted(void);  //接收到UI界面加载完成的信号

    //蓝牙相关的槽函数
    void onRecBtServerTransDataSig(bool); //用来接受使用蓝牙传输数据的标志位
    void onRecM3DataShowCtlBtOpenSig(bool); //用来接受蓝牙开或者关的信号
    bool BluetoothOpen();  //蓝牙打开
    void BluetoothClosed(); //蓝牙关闭
//    void onRecBtServerBtOpenSuccess(); //用来接收蓝牙打开成功的信号
//    void onRecBtServerBtOpenFailed(); //用来接收蓝牙打开成功的信号



};

#endif // DATAACQUISITION_H
