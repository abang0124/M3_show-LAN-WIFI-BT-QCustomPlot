#include <QThread>
#include "m3showcontroller.h"
//#include "dataacquisition.h" //数据采集类
M3ShowController::M3ShowController(QObject *parent) : QObject(parent)
{


    //qDebug()<<"The Main Thread is "<<QThread::currentThreadId();
    QThread *dataAcquisitionThread = new QThread();
    //DataAcquisition *dataAcquisition = new DataAcquisition(); //完成串口的初始化，并打开了串口 //不能指定父对象
    dataAcquisition = new DataAcquisition(); //完成串口的初始化，并打开了串口 //不能指定父对象
    dataAcquisition->moveToThread(dataAcquisitionThread); //将串口的数据采集放入一个单独的线程中
    connect(dataAcquisitionThread,SIGNAL(started()),dataAcquisition,SLOT(onDataAcquisitionThreadCreat()));//利用线程start信号，创建在该线程中可以使用的对象
    //connect(this,SIGNAL(starDataAcquSignal()),dataAcquisition,SLOT(startDataAcq()));
    dataAcquisitionThread->start();//开启线程
    //emit starDataAcquSignal();
    //dataAcquisition->startDataAcq(); //开启串口的读取


    QThread *audioThead = new QThread();//报警声音线程
    AudioThread *audioAlarm = new AudioThread();//报警声音实际类  AudioThread *audioAlarm;       //报警声音类
    audioAlarm->moveToThread(audioThead); //将报警声音类实际添加到一个线程中
    connect(audioThead,SIGNAL(started()),audioAlarm,SLOT(onCreatAudioThread()));//利用线程start信号，创建在该线程中可以使用的对象
    audioThead->start();//开启线程

    //m_netTransFlag = dbusConn->getCurrentServiceType();

    getECGDataTimerRunningFlag = false;//定时获取ECG数据显示的定时器开关设置为不启动

    //界面加载完成，title显示时间信息
    m_date = QDate::currentDate().toString("yy-MM-dd");
    m_time = QTime::currentTime().toString("hh:mm:ss");
    emit timeChanged();//发送时间变更信号 1S更新一次
    //以下信息皆为测试用的信息
    qDebug()<<"M3ShowController build"<<endl;
    tm = new QTimer(this);
    tm->setInterval(1000);//目前是定时屏幕上的时间显示
    //testTimer = new QTimer(this);
    //testTimer->setInterval(200);
    m_hearRate = 88;
    tm->start();
    //阈值设置界面
    m_WideOrNarrowThresHoldPage = true; //默认是设置窄阈值
    m_WideOrNarrowThresHoldChoice = true; //默认是选中窄阈值
//  血氧的阈值
//    窄阈值
    m_spo2ThresHoldValue = 92;     //血氧阈值低于95时报警
    m_spo2ThresHoldLevel = 0;      //血氧的报警级别为0 高      1 中   2  低
//    宽阈值
    m_spo2ThresHoldValueWide = 92;     //血氧阈值低于95时报警
    m_spo2ThresHoldLevelWide = 0;      //血氧的报警级别为0 高      1 中   2  低
//血压的阈值
//    窄阈值
    m_bpSYSThresHoldValueH = 160;
    m_bpSYSThresHoldValueL = 90;
    m_bpDIAThresHoldValueH = 90;
    m_bpDIAThresHoldValueL = 60;
    m_bpSYSThresHoldLevel = 1 ; //报警级别为0 高      1 中   2  低
    m_bpDIAThresHoldLevel = 1 ; //报警级别为0 高      1 中   2  低
//宽阈值
    m_bpSYSThresHoldValueHWide = 120;
    m_bpSYSThresHoldValueLWide = 70;
    m_bpDIAThresHoldValueHWide = 70;
    m_bpDIAThresHoldValueLWide = 50;
    m_bpSYSThresHoldLevelWide = 0 ; //报警级别为0 高      1 中   2  低
    m_bpDIAThresHoldLevelWide = 0 ; //报警级别为0 高      1 中   2  低
//心率的阈值
//    窄阈值
    m_hrFastValue = 120;
    m_hrFastLevel = 0; //报警级别为0 高      1 中   2  低
    m_hrSlowValue = 50;
    m_hrSlowLevel = 0; //报警级别为0 高      1 中   2  低
//    宽阈值
    m_hrFastValueWide = 150;
    m_hrFastLevelWide = 1; //报警级别为0 高      1 中   2  低
    m_hrSlowValueWide = 80;
    m_hrSlowLevelWide = 1; //报警级别为0 高      1 中   2  低

    //3导联显示界面，根据界面当中的定时器，每个定时器周期上传的心电数据
    lead3_show_count = 15;
    //6导联显示界面，根据界面当中的定时器，每个定时器周期上传的心电数据
    lead6_show_count = 15;
    //12导联显示界面，根据界面当中的定时器，每个定时器周期上传的心电数据
    lead12_show_count = 50;
    m_leadsType = 0;//默认是12导联 =0 12导联      =1   3导联
    //单个页面导联显示的类型
    m_leadsShowType = 0;
    m_speedType = 0; //速度类型
    m_gainType = 0;  //增益类型

    //滤波类型
    m_lpSelectIndex = 3; //默认关闭
    m_hpSelectIndex = 4; //默认关闭
    m_acSelectIndex = 2; //默认关闭


    //导联脱落数据
    m_leadsOffRA = false; //导联未脱落
    m_leadsOffLA = false; //导联未脱落
    m_leadsOffLL = false; //导联未脱落
    m_leadsOffRL = false; //导联未脱落
    m_leadsOffV1 = false; //导联未脱落
    m_leadsOffV2 = false; //导联未脱落
    m_leadsOffV3 = false; //导联未脱落
    m_leadsOffV4 = false; //导联未脱落
    m_leadsOffV5 = false; //导联未脱落
    m_leadsOffV6 = false; //导联未脱落

    //导联基线的初始值
    //820,-69160,-69880,36490,36920,-69520,-45410,-47090,-46743,-47035,-46909,-47609
    m_leadIBaseLine = 820;
    m_leadIIBaseLine = -69160;
    m_leadIIIBaseLine = -69880;
    m_leadaVRBaseLine = 36490;
    m_leadaVLBaseLine = 36920;
    m_leadaVFBaseLine = -69520;
    m_leadV1BaseLine = -45410; //V1
    m_leadV2BaseLine = -47090;
    m_leadV3BaseLine = -46743;
    m_leadV4BaseLine = -47035;
    m_leadV5BaseLine = -46909;
    m_leadV6BaseLine = -47609;
    //心电图暂停显示标志位 =true 心电图暂停显示   =false 心电图继续显示
    m_ecgShowStopFlag = false;
    //报警是打开的还是关闭的标志位
    m_warnCloseFlag = false;//默认报警是打开的




    connect(tm,SIGNAL(timeout()),this,SLOT(time_upadate_slot())); //定时更新时间


    connect(this,SIGNAL(autoMeasureNIBPFlagChanged()),this,SLOT(onMeasureNIBPFlagChanged())); //血压的测量模式，手动or自动
    connect(this,SIGNAL(autoMeasureMinuteChanged()),this,SLOT(onMeasureMinuteChanged()));  //血压自动测量时间间隔
    connect(this,SIGNAL(NIBPStartSignal()),dataAcquisition,SLOT(onRecNIBPStartSignal()));//发送血压测量指令
    connect(this,SIGNAL(NIBPStopSignal()),dataAcquisition,SLOT(onRecNIBPStopSignal()));//发送血压测量指令


    connect(dataAcquisition,&DataAcquisition::NIBPData2M3DataControl,this,&M3ShowController::onRecNIBPDataFromDataAcq);   //血压数据的显示
    connect(dataAcquisition,&DataAcquisition::SPO2Data2M3DataControl,this,&M3ShowController::onRecSPO2DataFromDataAcq);   //血氧数据的显示与曲线的更新
    connect(dataAcquisition,&DataAcquisition::HeartRate2M3DataControl,this,&M3ShowController::onRecHeartRateFromDataAcq); //心率值的显示
    connect(dataAcquisition,&DataAcquisition::LeadsShowData2M3DataControl,this,&M3ShowController::onRecLeadsShowDataFromDataAcq);//心电图的显示数据
    //connect(this,&M3ShowController::ecg3or12ChangedSignal,dataAcquisition,&DataAcquisition::onECG3or12Changed);
    connect(this,&M3ShowController::recordECGFlagChanged,this,&M3ShowController::onRecordECGFlagChanged);//心电记录标志位改变的信号与槽
    connect(this,&M3ShowController::recordECGFlagChangeSignal,dataAcquisition,&DataAcquisition::onRecordECGFlagChangeSignal); //携带心电记录标志位的信号与槽 QML数据类与数据采集类
    connect(this,&M3ShowController::patientTypeChanged,this,&M3ShowController::onPatientTypeChanged); //当显示页面上的病人类型发生改变时
    connect(this,&M3ShowController::patientTypeChangedSignal,dataAcquisition,&DataAcquisition::onRecPatientTypeChanged);//数据采集类在病人类型发生改变时，做相应的处理
    connect(this,&M3ShowController::ECGDataProcessedSignal,dataAcquisition,&DataAcquisition::onRcvECGDataProcessedSignal);//心电数据发送与接收同步的信号
    connect(this,&M3ShowController::leadsShowTypeChanged,dataAcquisition,&DataAcquisition::onRecLeadsShowTypeChangedSignal);//心电界面显示单个页面显示的导联数量
    connect(this,&M3ShowController::lpSelectIndexChanged,dataAcquisition,&DataAcquisition::onRecLP_typeChanged);//lp滤波选择发生变化时
    connect(this,&M3ShowController::hpSelectIndexChanged,dataAcquisition,&DataAcquisition::onRecHP_typeChanged);//hp滤波选择发生变化时
    connect(this,&M3ShowController::acSelectIndexChanged,dataAcquisition,&DataAcquisition::onRecAC_typeChanged);//hp滤波选择发生变化时
    connect(dataAcquisition,&DataAcquisition::batValSignal,this,&M3ShowController::onRecBatValSignal);
    connect(this,&M3ShowController::warnAlarmSignal,audioAlarm,&AudioThread::AlarmSoundPlay);//测试声音用的函数
    connect(dataAcquisition,&DataAcquisition::leadOffSignal2M3DataControl,this,&M3ShowController::onRecLeadsOffSignalFromDataAcq);//心电图的显示数据
    connect(this,&M3ShowController::setAlarmSoundVolume,audioAlarm,&AudioThread::setSoundVolume);//设置声音的大小
    connect(this,&M3ShowController::dateAandTimeChange,this,&M3ShowController::onDataAndTimeChanged);//设置时间
    connect(this,&M3ShowController::sendUILoadCompleted2dataAcq,dataAcquisition,&DataAcquisition::onRecUILoadCompleted);//界面加载完成后，将信号传递给数据采集类，数据采集类开始初始化串口，准备接收数据
    connect(this,&M3ShowController::bluetoothOpenSig,dataAcquisition,&DataAcquisition::onRecM3DataShowCtlBtOpenSig);//控制蓝牙的开与关
//    connect(dataAcquisition,&DataAcquisition::BtOpenSuccessed,this,&M3ShowController::btOpenSuccessed); //蓝牙打开成功 更新标题栏 蓝牙的状态 设置界面更新显示的内容
//    connect(dataAcquisition,&DataAcquisition::BtOpenFailed,this,&M3ShowController::btOpenFailed); //蓝牙打开失败 //更新设置页面的内容
    connect(dataAcquisition,&DataAcquisition::BtClientConnected,this,&M3ShowController::btConnected); //蓝牙连接成功 更新标题栏
    connect(dataAcquisition,&DataAcquisition::BtClientDisconnected,this,&M3ShowController::btDisconnected); //蓝牙断开连接 更新标题栏
    connect(dataAcquisition,&DataAcquisition::bluetoothOpenResult,this,&M3ShowController::onRecBluetoothOpenResult); //蓝牙打开成功与否

//    dbusConn = new DBusConnman(this); //dbus connman 网络管理
//    m_netTransFlag = dbusConn->getCurrentServiceType();
//    qDebug()<<"m_netTransFlag = "<<m_netTransFlag;
//    if(m_netTransFlag == 1)
//    {
//        getLANMessages();//获取有线网络相关的信息
//    }
//    else if(m_netTransFlag == 2)
//    {
//        dbusConn->getLanAndWLanInformation();
//        m_connectedWIFIName = dbusConn->connectedWIFIName;
//        m_wlanIPAddress = dbusConn->WLanIPAddress;
//        m_wlanMacAddress = dbusConn->WLanMacAddress;
//    }

//    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::netTransFlagChangeRev); //网络传输模式的改变
//    connect(dbusConn,&DBusConnman::service_changed,this,&M3ShowController::onDBusServiceChanged);   //用于接收DBusConnman类中的service_changed中的信号
//    connect(dbusConn,&DBusConnman::canGetIPAddressSig,this,&M3ShowController::onRecCanGetIPAddress); //用于收到网络状态信息，更新现有网络连接的地址
//    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::onNetTransFlagChanged); //将网络传输模式改变传递给dbu
//    qDebug()<<"timer completed+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
//    qDebug()<<"the m_netTransFlag = "<<m_netTransFlag;
//    emit netTransFlagChanged();//发送网络变化信号



    emit leadsShowTypeChanged(m_leadsShowType);//发送单个页面导联显示类型
    emit lpSelectIndexChanged(m_lpSelectIndex); //主要是发给数据采集类
    emit hpSelectIndexChanged(m_hpSelectIndex); //主要是发给数据采集类
    emit acSelectIndexChanged(m_acSelectIndex); //主要是发给数据采集类

    testTimer = new QTimer(this);
    testTimer->setInterval(600);  //延时500ms连接dbus的connman管理网络
    testTimer->setSingleShot(true);
    connect(testTimer,SIGNAL(timeout()),this,SLOT(onTestTimer())); //测试函数
    testTimer->start();
    //emit warnAlarmSignal(0);
}

void M3ShowController::onTestTimer() //测试用的周期函数
{
    dbusConn = new DBusConnman(this); //dbus connman 网络管理
    m_netTransFlag = dbusConn->getCurrentServiceType();
    qDebug()<<"m_netTransFlag = "<<m_netTransFlag;
    if(m_netTransFlag == 1)
    {
        getLANMessages();//获取有线网络相关的信息
//        connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::netTransFlagChangeRev); //网络传输模式的改变
//        connect(dbusConn,&DBusConnman::service_changed,this,&M3ShowController::onDBusServiceChanged);   //用于接收DBusConnman类中的service_changed中的信号
//        connect(dbusConn,&DBusConnman::canGetIPAddressSig,this,&M3ShowController::onRecCanGetIPAddress); //用于收到网络状态信息，更新现有网络连接的地址
//        connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::onNetTransFlagChanged); //将网络传输模式改变传递给dbu
        //qDebug()<<"timer completed+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        //qDebug()<<"the m_netTransFlag = "<<m_netTransFlag;
        emit netTransFlagChanged();//发送网络变化信号
    }
    else if(m_netTransFlag == 2)
    {
        dbusConn->getLanAndWLanInformation();
        getWLANMessages(); //获取无线网络相关的信息，网卡地址.IP地址
        m_connectedWIFIName = dbusConn->connectedWIFIName;
        m_wlanIPAddress = dbusConn->WLanIPAddress;
        m_wlanMacAddress = dbusConn->WLanMacAddress;
//        connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::netTransFlagChangeRev); //网络传输模式的改变
//        connect(dbusConn,&DBusConnman::service_changed,this,&M3ShowController::onDBusServiceChanged);   //用于接收DBusConnman类中的service_changed中的信号
//        connect(dbusConn,&DBusConnman::canGetIPAddressSig,this,&M3ShowController::onRecCanGetIPAddress); //用于收到网络状态信息，更新现有网络连接的地址
//        connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::onNetTransFlagChanged); //将网络传输模式改变传递给dbu
        //qDebug()<<"timer completed+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
        //qDebug()<<"the m_netTransFlag = "<<m_netTransFlag;
        emit netTransFlagChanged();//发送网络变化信号
    }

//    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::netTransFlagChangeRev); //网络传输模式的改变
//    connect(dbusConn,&DBusConnman::service_changed,this,&M3ShowController::onDBusServiceChanged);   //用于接收DBusConnman类中的service_changed中的信号
//    connect(dbusConn,&DBusConnman::canGetIPAddressSig,this,&M3ShowController::onRecCanGetIPAddress); //用于收到网络状态信息，更新现有网络连接的地址
//    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::onNetTransFlagChanged); //将网络传输模式改变传递给dbu
//    //qDebug()<<"timer completed+++++++++++++++++++++++++++++++++++++++++++++++++++++++";
//    //qDebug()<<"the m_netTransFlag = "<<m_netTransFlag;
//    emit netTransFlagChanged();//发送网络变化信号

    else if(m_netTransFlag == 3) //如果当前数据传输类型为蓝牙传输
    {
        emit bluetoothOpenSig(true); //那么打开蓝牙  通过信号与槽，在子线程槽函数中创建对象，对象属于槽函数
       // bool res = bt_open();
        //bool res = dataAcquisition->BluetoothOpen();
        //qDebug()<<"The Bluetooyh open result is "<<res;
        emit netTransFlagChanged();//发送网络变化信号
    }

    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::netTransFlagChangeRev); //网络传输模式的改变
    connect(dbusConn,&DBusConnman::service_changed,this,&M3ShowController::onDBusServiceChanged);   //用于接收DBusConnman类中的service_changed中的信号
    connect(dbusConn,&DBusConnman::canGetIPAddressSig,this,&M3ShowController::onRecCanGetIPAddress); //用于收到网络状态信息，更新现有网络连接的地址
    connect(this,&M3ShowController::netTransFlagChanged,this,&M3ShowController::onNetTransFlagChanged); //将网络传输模式改变传递给dbu


    //        uintindex++;
//        if(uintindex>250)
//        {

//            uintindex = 0;
//        }
//        listSPO2<< 25*qSin(uintindex)+25;
//        m_hearRate=uintindex;

//        emit test_signal();
    //warnMessage2MainPage(1,m_hrFastLevel);
//    warnMessage2MainPage(2,0);
//    warnMessage2MainPage(3,1);
//    warnMessage2MainPage(5,0);
//    warnMessage2MainPage(12,0);
//    warnMessage2MainPage(21,2);
//    warnMessage2MainPage(22,2);
//    warnMessage2MainPage(23,2);
//    warnMessage2MainPage(31,2);
    //warnAlarmSignal(0);
//    emit warnMessage2MainPage(2,1);//发送心动过缓报警和报警级别
//    emit warnMessage2MainPage(3,1);//发送血氧过低报警和报警级别
//    emit warnMessage2MainPage(4,1);//发送血压过高报警和报警级别

           //qDebug()<<"onTestTimer"<<endl;
}

QString M3ShowController::time() const  //读取时间参数
{
    return m_time;
}

void M3ShowController::setTime(QString tr) //设置时间参数
{
    m_time = tr;
    emit timeChanged();
}

unsigned int M3ShowController::batValue() const
{
    return m_batValue;            //读取电池电量
}

void M3ShowController::setBatValue(unsigned int val) //设置电池电量
{
    m_batValue = val;
    emit batValueChanged();
}

bool M3ShowController::chargeFlag() const //读取电池的充电状态
{
    return m_chargeFlag;
}

void M3ShowController::setChargeFlag(bool show) //写入电池的充电状态
{
    m_chargeFlag = show;
    emit chargeFlagChanged();
}

QString M3ShowController::heartRate()
{
    return QString::number(m_hearRate);      //读取心率值
}

void M3ShowController::setHeartRate(QString heartRate)
{
    m_hearRate = heartRate.toUInt();        //写入心率值
}

QString M3ShowController::bPValue()
{
    return QString::number(m_bpValue_sys)+"/"+QString::number(m_bpValue_dia); //读取血压值
}

void M3ShowController::setBPValue(QString bpValue)      //写入血压值
{

    QStringList strl = bpValue.split("/");
    m_bpValue_sys = strl[0].toUInt(); //收缩压
    m_bpValue_dia = strl[1].toUInt(); //舒张压
}

bool M3ShowController::getNIBPAutoFlag()
{
    return m_NIBP_AutoMeasureFlag;
}

void M3ShowController::setNIBPAutoFlag(bool flag)
{
    m_NIBP_AutoMeasureFlag = flag;
    emit autoMeasureNIBPFlagChanged();
}

int M3ShowController::getAutoMeasureMinute()  //QML获取自动测量的时间间隔值
{
    return m_AutoMeasureNIBPMinut;
}

void M3ShowController::setAutoMeasureMinute(int value)
{
    m_AutoMeasureNIBPMinut = value;
    emit autoMeasureMinuteChanged();
}


QString M3ShowController::spo2Num()
{
    return QString::number(m_spo2Num);
}

void M3ShowController::setSpo2Num(QString spo2txt)
{
    m_spo2Num = spo2txt.toUInt();
    qDebug()<<"血氧值发生变化"<<m_spo2Num<<endl;
}

QString M3ShowController::piNum()
{
    return ("PI:"+QString("%1").arg(m_piNum)+"%");
}

void M3ShowController::setpiNum(QString piNumtxt)
{
    m_piNum = piNumtxt.toFloat();
}

bool M3ShowController::getRecordECGFlag()
{
    return m_recordECGFlag;
}

void M3ShowController::setRecordECGFlag(bool value)
{
    m_recordECGFlag = value;
    emit recordECGFlagChanged();  //发出心电记录标志位改变的信号
}




quint8 M3ShowController::getLPSelectIndex()
{
    return m_lpSelectIndex;
}

void M3ShowController::setLPSelectIndex(quint8 value)
{
    m_lpSelectIndex = value;
    emit lpSelectIndexChanged(value);
}

quint8 M3ShowController::getHPSelectIndex()
{
    return m_hpSelectIndex;
}

void M3ShowController::setHPSelectIndex(quint8 value)
{
    m_hpSelectIndex = value;
    emit hpSelectIndexChanged(value);
}

quint8 M3ShowController::getACSelectIndex()
{
    return m_acSelectIndex;
}

void M3ShowController::setACSelectIndex(quint8 value)
{
    m_acSelectIndex = value;
    emit acSelectIndexChanged(value);
}

quint8 M3ShowController::getPatientType(void)
{
    return m_patientType;
}

void M3ShowController::setPatientType(quint8 value)
{
    m_patientType = value;
    emit patientTypeChanged();
}

bool M3ShowController::getWideOrNarrowThresHoldPage()
{
    return m_WideOrNarrowThresHoldPage;
}

void M3ShowController::setWideOrNarrowThresHoldPage(bool value)
{
    m_WideOrNarrowThresHoldPage = value;
    emit wideOrNarrowThresHoldPageChanged();//发送当前设置的是宽阈值还是窄阈值
}

bool M3ShowController::getWideOrNarrowThresHoldChoice()
{
    return m_WideOrNarrowThresHoldChoice;
}

void M3ShowController::setWideOrNarrowThresHoldChoice(bool value)
{
    m_WideOrNarrowThresHoldChoice = value;
    emit wideOrNarrowThresHoldChoiceChanged();//发送当前是宽阈值被选中还是窄阈值被选中的信号
}

quint8 M3ShowController::getSPO2ThresHoldValue(void)
{
    return m_spo2ThresHoldValue;
}

void M3ShowController::setSPO2ThresHoldValue(quint8 value)
{
    m_spo2ThresHoldValue = value;
    emit spo2ThresHoldValueChanged();          //发送血氧阈值变化的信号
}

quint8 M3ShowController::getSPO2ThresHoldLevel()
{
    return m_spo2ThresHoldLevel;
}

void M3ShowController::setSPO2ThresHoldLevel(quint8 value)
{
    m_spo2ThresHoldLevel = value;
    emit spo2ThresHoldLevelChanged();

}

quint8 M3ShowController::getBPSYSThresHoldValueH()
{
    return m_bpSYSThresHoldValueH;
}

void M3ShowController::setBPSYSThresHoldValueH(quint8 value)
{
    m_bpSYSThresHoldValueH = value;
    emit bpSYSThresHoldValueHChanged();
}

quint8 M3ShowController::getBPSYSThresHoldValueL()
{
    return m_bpSYSThresHoldValueL;
}

void M3ShowController::setBPSYSThresHoldValueL(quint8 value)
{
    m_bpSYSThresHoldValueL = value;
    emit bpSYSThresHoldValueLChanged();
}







quint8 M3ShowController::getBPDIAThresHoldValueH()
{
    return m_bpDIAThresHoldValueH;
}

void M3ShowController::setBPDIAThresHoldValueH(quint8 value)
{
    m_bpDIAThresHoldValueH = value;
    emit bpDIAThresHoldValueHChanged();
}

quint8 M3ShowController::getBPDIAThresHoldValueL()
{
    return m_bpDIAThresHoldValueL;
}

void M3ShowController::setBPDIAThresHoldValueL(quint8 value)
{
    m_bpDIAThresHoldValueL = value;
    emit bpDIAThresHoldValueLChanged();
}







quint8 M3ShowController::getBPSYSThresHoldLevel()
{
    return m_bpSYSThresHoldLevel;
}

void M3ShowController::setBPSYSThresHoldLevel(quint8 value)
{
    m_bpSYSThresHoldLevel = value;
    emit bpSYSThresHoldLevelChanged();
}

quint8 M3ShowController::getBPDIAThresHoldLevel()
{
    return m_bpDIAThresHoldLevel;
}

void M3ShowController::setBPDIAThresHoldLevel(quint8 value)
{
    m_bpDIAThresHoldLevel = value;
    emit bpDIAThresHoldLevelChanged();
}

quint8 M3ShowController::getHRFastValue()
{
    return m_hrFastValue;
}

void M3ShowController::setHRFastValue(quint8 value)
{
    m_hrFastValue = value;
    emit hrFastValueChanged();
}

quint8 M3ShowController::getHRFastLevel()
{
    return m_hrFastLevel;
}

void M3ShowController::setHRFastLevel(quint8 value)
{
    m_hrFastLevel = value;
    emit hrFastLevelChanged();
}

quint8 M3ShowController::getHRSlowValue()
{
    return m_hrSlowValue;
}

void M3ShowController::setHRSlowValue(quint8 value)
{
    m_hrSlowValue = value;
    emit hrSlowValueChanged();
}

quint8 M3ShowController::getHRSlowLevel()
{
    return m_hrSlowLevel;
}

void M3ShowController::setHRSlowLevel(quint8 value)
{
    m_hrSlowLevel = value;
    emit hrSlowLevelChanged();
}



//宽阈值

quint8 M3ShowController::getSPO2ThresHoldValueWide(void)
{
    return m_spo2ThresHoldValueWide;
}

void M3ShowController::setSPO2ThresHoldValueWide(quint8 value)
{
    m_spo2ThresHoldValueWide = value;
    emit spo2ThresHoldValueChangedWide();          //发送血氧阈值变化的信号
}

quint8 M3ShowController::getSPO2ThresHoldLevelWide()
{
    return m_spo2ThresHoldLevelWide;
}

void M3ShowController::setSPO2ThresHoldLevelWide(quint8 value)
{
    m_spo2ThresHoldLevelWide = value;
    emit spo2ThresHoldLevelChangedWide();

}

quint8 M3ShowController::getBPSYSThresHoldValueHWide()
{
    return m_bpSYSThresHoldValueHWide;
}

void M3ShowController::setBPSYSThresHoldValueHWide(quint8 value)
{
    m_bpSYSThresHoldValueHWide = value;
    emit bpSYSThresHoldValueHChangedWide();
}

quint8 M3ShowController::getBPSYSThresHoldValueLWide()
{
    return m_bpSYSThresHoldValueLWide;
}

void M3ShowController::setBPSYSThresHoldValueLWide(quint8 value)
{
    m_bpSYSThresHoldValueLWide = value;
    emit bpSYSThresHoldValueLChangedWide();
}



quint8 M3ShowController::getBPDIAThresHoldValueHWide()
{
    return m_bpDIAThresHoldValueHWide;
}

void M3ShowController::setBPDIAThresHoldValueHWide(quint8 value)
{
    m_bpDIAThresHoldValueHWide = value;
    emit bpDIAThresHoldValueHChangedWide();
}

quint8 M3ShowController::getBPDIAThresHoldValueLWide()
{
    return m_bpDIAThresHoldValueLWide;
}

void M3ShowController::setBPDIAThresHoldValueLWide(quint8 value)
{
    m_bpDIAThresHoldValueLWide = value;
    emit bpDIAThresHoldValueLChangedWide();
}



quint8 M3ShowController::getBPSYSThresHoldLevelWide()
{
    return m_bpSYSThresHoldLevelWide;
}

void M3ShowController::setBPSYSThresHoldLevelWide(quint8 value)
{
    m_bpSYSThresHoldLevelWide = value;
    emit bpSYSThresHoldLevelChangedWide();
}

quint8 M3ShowController::getBPDIAThresHoldLevelWide()
{
    return m_bpDIAThresHoldLevelWide;
}

void M3ShowController::setBPDIAThresHoldLevelWide(quint8 value)
{
    m_bpDIAThresHoldLevelWide = value;
    emit bpDIAThresHoldLevelChangedWide();
}

quint8 M3ShowController::getHRFastValueWide()
{
    return m_hrFastValueWide;
}

void M3ShowController::setHRFastValueWide(quint8 value)
{
    m_hrFastValueWide = value;
    emit hrFastValueChangedWide();
}

quint8 M3ShowController::getHRFastLevelWide()
{
    return m_hrFastLevelWide;
}

void M3ShowController::setHRFastLevelWide(quint8 value)
{
    m_hrFastLevelWide = value;
    emit hrFastLevelChangedWide();
}

quint8 M3ShowController::getHRSlowValueWide()
{
    return m_hrSlowValueWide;
}

void M3ShowController::setHRSlowValueWide(quint8 value)
{
    m_hrSlowValueWide = value;
    emit hrSlowValueChangedWide();
}

quint8 M3ShowController::getHRSlowLevelWide()
{
    return m_hrSlowLevelWide;
}

void M3ShowController::setHRSlowLevelWide(quint8 value)
{
    m_hrSlowLevelWide = value;
    emit hrSlowLevelChangedWide();
}

quint8 M3ShowController::getLeadsShowType()
{
    return m_leadsShowType;
}

void M3ShowController::setLeadsShowType(quint8 value)
{
    m_leadsShowType = value;
    emit leadsShowTypeChanged(value);
}

QMap<QString, QVariant> M3ShowController::getWifiServiceMap()
{
    return m_wifiServiceMap;
}

void M3ShowController::setWifiServiceMap(const QMap<QString, QVariant> wifiSerMap)
{
    m_wifiServiceMap = wifiSerMap;
}

bool M3ShowController::bt_open()
{
    //btOpenStatus = 2;
    emit bluetoothOpenSig(true);
}

void M3ShowController::turnECGData2OtherList1leads(int i, int len)
{

    for(int j = 0; j < len;j++)
    {
        for(int z = 0;z<12;z++)
        {
            if(z!=i)
            {
                transToECGshowArray[z] <<leadsShowArray[z].takeFirst();
            }
        }

    }


//    if(i==0) //第1页面
//    {
//        for(int j = 0;j <len;j++)
//        {
//            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
//            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
//            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
//            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
//            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
//            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
//            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
//            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
//            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
//            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
//            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
//        }
//    }
//    else if(i==1) //第2页面
//    {
//        for(int j = 0;j <len;j++)
//        {
//            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
//            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
//            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
//            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
//            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
//            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
//            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
//            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
//            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
//        }

//    }
//    else if(i==6) //第3页面
//    {
//        for(int j = 0;j <len;j++)
//        {
//            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
//            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
//            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
//            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
//            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
//            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
//            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
//            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
//            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
//        }

//    }
//    else if(i==9) //第4页面
//    {
//        for(int j = 0;j <len;j++)
//        {
//            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
//            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
//            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
//            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
//            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
//            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
//            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
//            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
//            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
//        }

//    }

}

void M3ShowController::turnECGData2OtherList3leads(int i,int len) //针对3导联显示不显示其他的导联也要将数据转存
{
    if(i==0) //第1页面
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
        }
    }
    else if(i==3) //第2页面
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
        }

    }
    else if(i==6) //第3页面
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
        }

    }
    else if(i==9) //第4页面
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
        }

    }

}

void M3ShowController::turnECGData2OtherList6leads(int i,int len) //针对6导联显示不显示其他的导联也要将数据转存
{
    if(i==0) //第1页面 I II III aVR aVL aVF
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[6] << leadsShowArray[6].takeFirst();
            transToECGshowArray[7] << leadsShowArray[7].takeFirst();
            transToECGshowArray[8] << leadsShowArray[8].takeFirst();
            transToECGshowArray[9] << leadsShowArray[9].takeFirst();
            transToECGshowArray[10] << leadsShowArray[10].takeFirst();
            transToECGshowArray[11] << leadsShowArray[11].takeFirst();
        }
    }
    else if(i==6) //第2页面 V1 V2 V3 V4 V5 V6
    {
        for(int j = 0;j <len;j++)
        {
            transToECGshowArray[0] << leadsShowArray[0].takeFirst();
            transToECGshowArray[1] << leadsShowArray[1].takeFirst();
            transToECGshowArray[2] << leadsShowArray[2].takeFirst();
            transToECGshowArray[3] << leadsShowArray[3].takeFirst();
            transToECGshowArray[4] << leadsShowArray[4].takeFirst();
            transToECGshowArray[5] << leadsShowArray[5].takeFirst();
        }

    }
}



void M3ShowController::onRecLeadsShowDataFromDataAcq(QList<int> ecg_real_data_processed_array[12] )
{
    int length = ecg_real_data_processed_array[11].length();
    //qDebug()<<"m3showcontroller recive length is"<<length<<endl;





    for(int i=0;i<length;i++)
    {
        for(quint32 num=0;num<12;num++)
        {
            leadsShowArray[num]<<ecg_real_data_processed_array[num].takeFirst(); //将所有的数据都转存到leadsShowArray
        }
    }


    length=leadsShowArray[11].length();
//    for(int l = 0;l <length;l++)
//    {
//        qDebug()<<leadsShowArray[0][l]<<"\t"<<leadsShowArray[1][l]<<"\t"<<leadsShowArray[2][l]<<endl;
//    }
    //qDebug()<<"leadsShowArray[11].length iis"<<length<<endl;
    //在这里求取每个导联序列中的最小值，然后根据最小值算导联序列的基线，供心电图显示页面使用
//*************************************实现动态基线**********************************************************//
    for(quint8 num=0;num<12;num++)
    {
        leadsMinBaseLineNumList[num]<<*std::min_element(leadsShowArray[num].begin(),leadsShowArray[num].end());//求取该列表项中的最小值
        leadsMaxBaseLineNumList[num]<<*std::max_element(leadsShowArray[num].begin(),leadsShowArray[num].end());//求取该列表项中的最大值
    }
    if(leadsMinBaseLineNumList[11].length() == LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST) //当list的数据长度达到了指定的长度，开始算平均值
    {

        for(quint8 num=0;num<12;num++)
        {
            //leadsBaseLineNum[num] = *std::accumulate(leadsShowArray[num].begin(),leadsShowArray[num].end(),)/LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST;
            qint64 minsum = 0,maxsum = 0;
            for(int i = 0;i<LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST;i++)
            {

                minsum+=leadsMinBaseLineNumList[num][i];
                maxsum+=leadsMaxBaseLineNumList[num][i];
            }
            leadsBaseLineNum[num] = (minsum/100)/LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST;

            leadsMaxLineNum[num] = (maxsum/100)/LENGTH_LEADS_MIN_BASE_LINE_NUM_LIST;
            leadsMinBaseLineNumList[num].takeFirst();
            leadsMaxBaseLineNumList[num].takeFirst();
        }
        //leadsBaseLineNum[4] = leadsBaseLineNum[4]+1400; //aVL +1400
        //leadsBaseLineNum[7] = leadsBaseLineNum[7]+(-400);    //V2 +(-400)
//        for(int i = 0;i<12;i++)
//        {
//            qDebug()<<"leadsBaseLineNum["<<i<<"] = "<<leadsBaseLineNum[i];
//        }
//        for(int i = 0;i<12;i++)
//        {
//            qDebug()<<"leadsMaxLineNum["<<i<<"] = "<<leadsMaxLineNum[i];
//        }
        //基线
        m_leadIBaseLine   = leadsBaseLineNum[0] ;
        m_leadIIBaseLine  = leadsBaseLineNum[1] ;
        m_leadIIIBaseLine = leadsBaseLineNum[2] ;
        m_leadaVRBaseLine = leadsBaseLineNum[3] ;
        m_leadaVLBaseLine = leadsBaseLineNum[4] ;
        m_leadaVFBaseLine = leadsBaseLineNum[5] ;
        m_leadV1BaseLine  = leadsBaseLineNum[6] ;
        m_leadV2BaseLine  = leadsBaseLineNum[7] ;
        m_leadV3BaseLine  = leadsBaseLineNum[8] ;
        m_leadV4BaseLine  = leadsBaseLineNum[9] ;
        m_leadV5BaseLine  = leadsBaseLineNum[10];
        m_leadV6BaseLine  = leadsBaseLineNum[11];

        //上限
        m_leadIMaxLine   = leadsMaxLineNum[0];
        m_leadIIMaxLine  = leadsMaxLineNum[1];
        m_leadIIIMaxLine = leadsMaxLineNum[2];
        m_leadaVRMaxLine = leadsMaxLineNum[3];
        m_leadaVLMaxLine = leadsMaxLineNum[4];
        m_leadaVFMaxLine = leadsMaxLineNum[5];
        m_leadV1MaxLine  = leadsMaxLineNum[6];
        m_leadV2MaxLine  = leadsMaxLineNum[7];
        m_leadV3MaxLine  = leadsMaxLineNum[8];
        m_leadV4MaxLine  = leadsMaxLineNum[9];
        m_leadV5MaxLine  = leadsMaxLineNum[10];
        m_leadV6MaxLine  = leadsMaxLineNum[11];

        //中间值
//        m_leadIMidLine   = (leadsMaxLineNum[0] - leadsBaseLineNum[0])/2 + leadsBaseLineNum[0] ;
//        m_leadIIMidLine  = (leadsMaxLineNum[1] - leadsBaseLineNum[1])/2 + leadsBaseLineNum[1] ;
//        m_leadIIIMidLine = (leadsMaxLineNum[2] - leadsBaseLineNum[2])/2 + leadsBaseLineNum[2] ;
//        m_leadaVRMidLine = (leadsMaxLineNum[3] - leadsBaseLineNum[3])/2 + leadsBaseLineNum[3] ;
//        m_leadaVLMidLine = (leadsMaxLineNum[4] - leadsBaseLineNum[4])/2 + leadsBaseLineNum[4] ;
//        m_leadaVFMidLine = (leadsMaxLineNum[5] - leadsBaseLineNum[5])/2 + leadsBaseLineNum[5] ;
//        m_leadV1MidLine  = (leadsMaxLineNum[6] - leadsBaseLineNum[6])/2 + leadsBaseLineNum[6] ;
//        m_leadV2MidLine  = (leadsMaxLineNum[7] - leadsBaseLineNum[7])/2 + leadsBaseLineNum[7] ;
//        m_leadV3MidLine  = (leadsMaxLineNum[8] - leadsBaseLineNum[8])/2 + leadsBaseLineNum[8] ;
//        m_leadV4MidLine  = (leadsMaxLineNum[9] - leadsBaseLineNum[9])/2 + leadsBaseLineNum[9] ;
//        m_leadV5MidLine  = (leadsMaxLineNum[10] -leadsBaseLineNum[10])/2 + leadsBaseLineNum[10];
//        m_leadV6MidLine  = (leadsMaxLineNum[11] -leadsBaseLineNum[11])/2 + leadsBaseLineNum[11];



//        qDebug()<<"leadsBaseLineNum[0] = "<<leadsBaseLineNum[0];
//        qDebug()<<"leadsMaxLineNum[0] = "<<leadsMaxLineNum[0];
//        qDebug()<<"leadsBaseLineNum[1] = "<<leadsBaseLineNum[1];
//        qDebug()<<"leadsMaxLineNum[1] = "<<leadsMaxLineNum[1];
//        qDebug()<<"midLine[0] = "<<leadsMaxLineNum[0]-leadsBaseLineNum[0];
//        qDebug()<<"midLine[1] = "<<leadsMaxLineNum[1]-leadsBaseLineNum[1];
        //qDebug()<<"m_leadIBaseLine = "<<m_leadIBaseLine;
        if(baseLineCalOvered == false)
        {
            baseLineCalOvered = true;
        }
    }
//***************************************************************************************************************//


    emit ECGDataProcessedSignal();//发送心电数据处理完成。将同步的标志位置为真
    //qDebug()<<"The sync siganl is emitted";//同步信号已发出


    if(getECGDataTimerRunningFlag == false)  //定时获取ECG数据的定时器开关未打开 //修改为QCustomPlot显示心电图后该变量永为false使用信号更新心电图，不再是以前的使用QML中的定时器更新
    {
        //qDebug()<<"the length is "<<length;
        if((length>50)&&(length<500))
        {
            if(m_ecgShowStopFlag == false)  //心电图显示未暂停
            {
                if(baseLineCalOvered) //如果基线初次计算完成
                {
                    emit list_ECG_data_show_changed();//通知界面显示程序可以更新显示了,如果是ECG显示界面，则会有打开对应界面的定时器开关，定时获取当前ECG数据，如果不是，则没有定时器打开，数据长度会越来越长
                }
            }
        }
        else if(length>=500)
        {
            for(int k=0;k<12;k++)   //将存储的数据全部清零
            {
                leadsShowArray[k].clear();
            }
            //qDebug()<<"leadsShowArray Cleared";
        }

    }
}

void M3ShowController::onRecBluetoothOpenResult(bool result,QString btMacAddress) //接受蓝牙打开结果的槽函数
{
    if(result) //打开成功
    {
        m_lanIPAddress = "";
        m_lanMacAddress = "";
        m_lanNetGate = "";
        m_lanNetMask = "";
        m_wlanIPAddress = "";
        m_wlanMacAddress = "";
        m_BtMacAddress = btMacAddress;//蓝牙的mac地址
        emit netChangedAndIPAddressGeted();
        emit btOpenResult(true); //发送蓝牙打开成功的信号
    }
    else{      //打开失败
        emit btOpenResult(false); //发送蓝牙打开失败的信号
    }
}



QList<int> M3ShowController::getECGShowArray(int i) //3导联显示专用
{

    if(leadsShowArray[i].length()>0)
    {
        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点

        //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
        if(leadsShowArray[i].length()<=100)   //整个数据长度小于 ，每次传4个值
        {
            int length = leadsShowArray[i].length();
            if (length >60)
            {
                for(int j=0;j<4;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList3leads(i,4);
            }
            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
            else{                           //数据长度小于4
                for(int j=0;j<2;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList3leads(i,2);
            }
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>100)&&(leadsShowArray[i].length()<=200))   //整个数据长度小于 ，每次传4个值
        {
            for(int j=0;j<8;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList3leads(i,8);
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>200)&&((leadsShowArray[i].length()<=500)))
        {
            for(int j=0;j<50;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList3leads(i,50);
            return transToECGshowArray[i];
        }
        else if(leadsShowArray[i].length()>500)
        {
            for(int j=0;j<60;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList3leads(i,60);

            return transToECGshowArray[i];
        }
    }

    else if(leadsShowArray[i].length() == 0)
    {
        qDebug()<<"there is no more data";
    }
}





QList<int> M3ShowController::getECG1leadShowArray(int i) //单导联显示专用
{

    if(leadsShowArray[i].length()>0)
    {
        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点

        //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
        if(leadsShowArray[i].length()<=100)   //整个数据长度小于 ，每次传4个值
        {
            int length = leadsShowArray[i].length();
            if (length >60)
            {
                for(int j=0;j<4;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList1leads(i,4);
            }
            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
            else{                           //数据长度小于4
                for(int j=0;j<2;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList1leads(i,2);
            }
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>100)&&(leadsShowArray[i].length()<=200))   //整个数据长度小于 ，每次传4个值
        {
            for(int j=0;j<8;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList1leads(i,8);
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>200)&&((leadsShowArray[i].length()<=500)))
        {
            for(int j=0;j<50;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList1leads(i,50);

            return transToECGshowArray[i];
        }
        else if(leadsShowArray[i].length()>500)
        {
            for(int j=0;j<60;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList1leads(i,60);

            return transToECGshowArray[i];
        }
    }
    else if(leadsShowArray[i].length() == 0)
    {
        qDebug()<<"there is no more data";
    }

}





QList<int> M3ShowController::getECG6ShowArray(int i) //6导联显示专用
{

    if(leadsShowArray[i].length()>0)
    {
        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点

        //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
        if(leadsShowArray[i].length()<=100)   //整个数据长度小于 ，每次传4个值
        {
            int length = leadsShowArray[i].length();
            if (length >60)
            {
                for(int j=0;j<4;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList6leads(i,4);
            }
            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
            else{                           //数据长度小于4
                for(int j=0;j<2;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
                turnECGData2OtherList6leads(i,2);
            }
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>100)&&(leadsShowArray[i].length()<=200))   //整个数据长度小于 ，每次传4个值
        {
            for(int j=0;j<35;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList6leads(i,35);
            return transToECGshowArray[i];
        }

        else if((leadsShowArray[i].length()>200)&&((leadsShowArray[i].length()<=500)))
        {
            for(int j=0;j<50;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList6leads(i,50);

            return transToECGshowArray[i];
        }
        else if(leadsShowArray[i].length()>500)
        {
            for(int j=0;j<100;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            turnECGData2OtherList6leads(i,100);

            return transToECGshowArray[i];
        }
    }
    else if(leadsShowArray[i].length() == 0)
    {
        qDebug()<<"there is no more data";
    }

}


QList<int> M3ShowController::getECG12ShowArray(int i) //12导联专用的取心电数据的方法
{

    if(leadsShowArray[i].length()>0)
    {
        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点

        //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
        if(leadsShowArray[i].length()<=100)   //整个数据长度小于 ，每次传4个值
        {
            int length = leadsShowArray[i].length();
            if (length >60)
            {
                for(int j=0;j<4;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
            }
            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
            else{                           //数据长度小于4
                for(int j=0;j<2;j++)
                {
                    transToECGshowArray[i] << leadsShowArray[i].takeFirst();
                }
            }
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>100)&&(leadsShowArray[i].length()<=200))   //整个数据长度小于 ，每次传4个值
        {
            for(int j=0;j<15;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            return transToECGshowArray[i];
        }
        else if((leadsShowArray[i].length()>200)&&((leadsShowArray[i].length()<=400)))
        {
            for(int j=0;j<50;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }

            return transToECGshowArray[i];
        }
        else if(leadsShowArray[i].length()>400)
        {
            for(int j=0;j<100;j++)
            {
                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
            }
            return transToECGshowArray[i];
        }

    }
    else if(leadsShowArray[i].length() == 0)
    {
        qDebug()<<"there is no more data";
    }

}

//QList<int> M3ShowController::getECG6ShowArray(int i) //6导联显示专用
//{

//    if(leadsShowArray[i].length()>0)
//    {
//        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点
//        if(i == 0)
//        {
//            qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
//           // qDebug()<<"transToECGshowArray["<<i<<"].length = "<<transToECGshowArray[i].length();
//            //此段代码动态调整要传数据的长度，避免无数据可传的情况发生
//            if(leadsShowArray[i].length()<100)
//            {
//                //lead6_show_count = 15;
//                lead6_show_count = 4;
//            }
//            else if((leadsShowArray[i].length()>=100)&&(leadsShowArray[i].length()<200))
//            {
//                lead6_show_count = 20;
//            }
//            else if(leadsShowArray[i].length()>=200)
//            {
//                lead6_show_count = 23;
//            }
//        }
//        if(leadsShowArray[i].length()<lead6_show_count)
//        {
//            int length = leadsShowArray[i].length();
//            for(int j=0;j<length ;j++)
//            {
//                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
//            }
//            turnECGData2OtherList6leads(i,length);
//            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();

//            return transToECGshowArray[i];
//            //qDebug()<<"error";
//        }
//        else if(leadsShowArray[i].length()>=lead6_show_count)
//        {
//            for(int j=0;j<lead6_show_count;j++)
//            {
//                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
//            }
//            turnECGData2OtherList6leads(i,lead6_show_count);
//            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();

//            return transToECGshowArray[i];
//        }
//    }
//    else if(leadsShowArray[i].length() == 0)
//    {
//        qDebug()<<"there is no more data";
//    }
//}




//QList<int> M3ShowController::getECG12ShowArray(int i) //12导联专用的取心电数据的方法
//{

//    if(leadsShowArray[i].length()>0)
//    {


//        if(i == 0)
//        {
//            qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
//           // qDebug()<<"transToECGshowArray["<<i<<"].length = "<<transToECGshowArray[i].length();
//            //此段代码动态调整要传数据的长度，避免无数据可传的情况发生
//            if(leadsShowArray[i].length()<=150)
//            {
//                //lead12_show_count = 25;
//                lead12_show_count = 10;
//            }
//            else if((leadsShowArray[i].length()>150)&&(leadsShowArray[i].length()<=500))
//            {
//                lead12_show_count = 35;
//            }
//            else if(leadsShowArray[i].length()>500)
//            {
//                lead12_show_count = 75;
//            }
//        }



//        //quint8 tranlenth = 15; //3导联每行显示10s的数据10000个点/5 = 2000个点 1s200个    1000ms200个   5ms1个点  50ms要取10个点
//        if(leadsShowArray[i].length()<lead12_show_count)
//        {
//            int length = leadsShowArray[i].length();
//            for(int j=0;j<length ;j++)
//            {
//                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
//            }
//            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
//            return transToECGshowArray[i];
//            //qDebug()<<"error";
//        }
//        else if(leadsShowArray[i].length()>=lead12_show_count)
//        {
//            for(int j=0;j<lead12_show_count;j++)
//            {
//                transToECGshowArray[i] << leadsShowArray[i].takeFirst();
//            }
//            //qDebug()<<"leadsShowArray["<<i<<"].length = "<<leadsShowArray[i].length();
//            return transToECGshowArray[i];
//        }
//    }
//    else if(leadsShowArray[i].length() == 0)
//    {
//        qDebug()<<"there is no more data";
//    }
//}

void M3ShowController::showOverAndClear()  //向QML提供的transToECGshowArray数组，然后由QML调用此函数清空数组
{
    for(int i=0;i<12;i++)
    {
        if(transToECGshowArray[i].length()>0)
        {
            transToECGshowArray[i].clear();
        }
    }
    //emit ECGDataProcessedSignal();//发送心电数据处理完成
}

void M3ShowController::setGetECGDataTimerFlagTrue() //定时器开关打开后，设置此标注位为真
{
    getECGDataTimerRunningFlag = true;
}

void M3ShowController::setGetECGDataTimerFlagFalse()
{
    getECGDataTimerRunningFlag = false;
    qDebug()<<"Recive QML Signal";
}

void M3ShowController::alarmPlay(int level) //播放报警声音，level为报警声音的等级 0为最高级。1为中级，2为低级  //3为关闭声音
{
    emit warnAlarmSignal(level); //将信号发送给声音线程
}

void M3ShowController::alarmSoundVolume(int value) //设置报警声音的大小
{
    emit setAlarmSoundVolume(value);
}

void M3ShowController::uiLoadCompleted() //UI界面加载完成，控制串口接收数据
{
    emit sendUILoadCompleted2dataAcq();  //将UI加载完成的信号发送给数据采集类，数据采集类受到此信号，初始化串口
}

bool M3ShowController::enableWifi() //打开无线
{

    if(m_netTransFlag == 1)
    {
        if((dbusConn->enableLAN(false))&&(dbusConn->enableWLAN(true)))  //有线变无线
        {
            return true;
        }
        else{
            return false;
        }
    }
    else if(m_netTransFlag == 2)
    {
        return true;
    }
    else if(m_netTransFlag ==3)   //蓝牙变无线
    {
        if(dbusConn->enableWLAN(true))
        {
            dataAcquisition->BluetoothClosed();
            return true;
        }
        else{
            return false;
        }
    }
}

bool M3ShowController::enableLan()  //打开有线
{
    //dbusConn->enableLAN();
    if(m_netTransFlag == 1)
    {
        return true;
    }
    else if(m_netTransFlag == 2) //无线变有线
    {
        if((dbusConn->enableWLAN(false))&&(dbusConn->enableLAN(true)))
        {
            return true;
        }
        else{
            return false;
        }
    }
    else if(m_netTransFlag ==3) //蓝牙变有线
    {
        if((dbusConn->enableLAN(true)))
        {
            dataAcquisition->BluetoothClosed();
            return true;
        }
        else{
            return false;
        }
    }
}

void M3ShowController::enableBluetooth() //打开蓝牙
{
    if(m_netTransFlag == 1)  //有线变蓝牙
    {

        if(dbusConn->enableLAN(false))
        {
            emit bluetoothOpenSig(true); //那么打开蓝牙  通过信号与槽，在子线程槽函数中创建对象，对象属于槽函数
        }
        else
        {
            emit btOpenResult(false);//蓝牙打开失败
        }
    }
    else if(m_netTransFlag == 2) //无线变蓝牙
    {
        if(dbusConn->enableWLAN(false))
        {
            emit bluetoothOpenSig(true); //那么打开蓝牙  通过信号与槽，在子线程槽函数中创建对象，对象属于槽函数
        }
        else
        {
            emit btOpenResult(false);//蓝牙打开失败
        }
    }
    else if(m_netTransFlag ==3)
    {
       emit btOpenResult(true);
    }
}

void M3ShowController::setLanIPAdddress()
{
    dbusConn->setLanIPAddress("192.168.1.102");
}

void M3ShowController::connectWifi(QString wifiName,QString passCode)
{

    dbusConn->setWIFIPassCode(passCode); //将密码传递给dbus net.connman的代理类，必须先传递密码
    dbusConn->connect_wifi(wifiName);
}

void M3ShowController::disconnectWifi(QString wifiName)
{
    dbusConn->disconnect_wifi(wifiName);
    //qDebug()<<"wifi Name is "<<wifiName;
}

void M3ShowController::scanWifi()
{
    dbusConn->scan_wifi();  //调用dbus_connman类中的scan_wifi函数
}

QString M3ShowController::readBtName() //读取蓝牙的名字
{
    QString bluetoothFile = QString("/demo/bluetooth");
    QString bluetoothName = "HUASI-M2";
    QFile *file = new QFile(bluetoothFile);

    bool ret = file->open(QIODevice::ReadOnly|QIODevice::Text);
    if(ret)
    {
        QTextStream in(file);
        while(!in.atEnd())
        {
            bluetoothName = in.readLine();
            break;
        }
        return bluetoothName;
    }
    else{
        return bluetoothName;
    }

}

void M3ShowController::writeBtName(QString bluetoothName) //编写蓝牙名字
{
    QString bluetoothFile = QString("/demo/bluetooth");
    QFile *file = new QFile(bluetoothFile);

    bool ret = file->open(QIODevice::WriteOnly|QIODevice::Text);
    if(ret)
    {
        file->write(bluetoothName.toUtf8());
        file->flush();
        file->close();
        qDebug()<<"write OK";
    }
    else{
        qDebug()<<"write error";
    }
}



void M3ShowController::ecg3or12changed(bool value)  //12导联的显示模式 2*6或者3*4变化了
{

    emit ecg3or12ChangedSignal(value);

}

void M3ShowController::warnSetBackToDefalut() //报警相关的值恢复到默认值
{
    //阈值设置界面
    m_WideOrNarrowThresHoldPage = true; //默认是设置窄阈值
    m_WideOrNarrowThresHoldChoice = true; //默认是选中窄阈值
//  血氧的阈值
//    窄阈值
    m_spo2ThresHoldValue = 90;     //血氧阈值低于95时报警
    m_spo2ThresHoldLevel = 0;      //血氧的报警级别为0 高      1 中   2  低
//    宽阈值
    m_spo2ThresHoldValueWide = 95;     //血氧阈值低于95时报警
    m_spo2ThresHoldLevelWide = 0;      //血氧的报警级别为0 高      1 中   2  低
//血压的阈值
//    窄阈值
    m_bpSYSThresHoldValueH = 140;
    m_bpSYSThresHoldValueL = 90;
    m_bpDIAThresHoldValueH = 90;
    m_bpDIAThresHoldValueL = 60;
    m_bpSYSThresHoldLevel = 1 ; //报警级别为0 高      1 中   2  低
    m_bpDIAThresHoldLevel = 1 ; //报警级别为0 高      1 中   2  低
//宽阈值
    m_bpSYSThresHoldValueHWide = 120;
    m_bpDIAThresHoldValueLWide = 70;
    m_bpSYSThresHoldValueHWide = 70;
    m_bpDIAThresHoldValueLWide = 50;
    m_bpSYSThresHoldLevelWide = 1 ; //报警级别为0 高      1 中   2  低
    m_bpDIAThresHoldLevelWide = 1 ; //报警级别为0 高      1 中   2  低
//心率的阈值
//    窄阈值
    m_hrFastValue = 100;
    m_hrFastLevel = 2; //报警级别为0 高      1 中   2  低
    m_hrSlowValue = 60;
    m_hrSlowLevel = 2; //报警级别为0 高      1 中   2  低
//    宽阈值
    m_hrFastValueWide = 95;
    m_hrFastLevelWide = 2; //报警级别为0 高      1 中   2  低
    m_hrSlowValueWide = 65;
    m_hrSlowLevelWide = 2; //报警级别为0 高      1 中   2  低
}

void M3ShowController::clearECGData() //导联界面显示加载完成，会调用此函数
{
    for(quint32 num=0;num<12;num++)
    {
        leadsShowArray[num].clear(); //将所有的数据都清除
    }
}




void M3ShowController::time_upadate_slot()//更新屏幕上的时间的显示
{

    m_date = QDate::currentDate().toString("yy-MM-dd");
    m_time = QTime::currentTime().toString("hh:mm:ss");
    emit timeChanged();//发送时间变更信号 1S更新一次
}





//void M3ShowController::serialport_recive_data()  //串口数据接收函数
//{
//    QByteArray buf = sampleSerialPort->readAll(); //将读到的数据存入buf中
//}
//槽函数
void M3ShowController::onRecNIBPDataFromDataAcq(QList<quint16> *NIBPSYSData, QList<quint16> *NIBPDIAData) //接收到数据测量的数据，将数据显示在屏幕上 //发送血压值
{
    qDebug()<<"the list length at start is "<<NIBPDIAData->length()<<endl;
    m_bpValue_sys = NIBPSYSData->takeFirst();
    m_bpValue_dia = NIBPDIAData->takeFirst();
    if(m_WideOrNarrowThresHoldChoice == true)//窄阈值
    {
        if((m_bpValue_sys>m_bpSYSThresHoldValueH)||(m_bpValue_dia>m_bpDIAThresHoldValueH))//收缩压大于收缩压范围 舒张压大于舒张压范围
        {
            emit warnMessage2MainPage(4,m_bpSYSThresHoldLevel);
        }
        else{
            emit warnMessage2MainPage(13,0); //发送血压正常信号
        }
        if((m_bpValue_dia<m_bpDIAThresHoldValueL)||(m_bpValue_sys<m_bpSYSThresHoldValueL)) //收缩压小于收缩压范围  舒张压小于舒张压范围
        {
            emit warnMessage2MainPage(5,m_bpDIAThresHoldLevel);
        }
        else {
            emit warnMessage2MainPage(13,0);   //发送血压正常信号
        }
    }
    else if(m_WideOrNarrowThresHoldChoice == false)//宽阈值
    {
        if((m_bpValue_sys>m_bpSYSThresHoldValueHWide)||(m_bpValue_dia>m_bpDIAThresHoldValueHWide))//收缩压大于收缩压范围 舒张压大于舒张压范围
        {
            emit warnMessage2MainPage(4,m_bpSYSThresHoldLevelWide);
        }
        else{
            emit warnMessage2MainPage(13,0);   //发送血压正常信号
        }
        if((m_bpValue_dia<m_bpDIAThresHoldValueLWide)||(m_bpValue_sys<m_bpSYSThresHoldValueLWide)) //收缩压小于收缩压范围  舒张压小于舒张压范围
        {
            emit warnMessage2MainPage(5,m_bpDIAThresHoldLevelWide);
        }
        else {
            emit warnMessage2MainPage(13,0);   //发送血压正常信号
        }

    }
    emit bPValueChanged();

}

void M3ShowController::onRecSPO2DataFromDataAcq(QList<quint8> *PI, QList<quint8> *data, QList<quint8> *rata, QList<quint8> *column, QList<quint8> *waves,QList<quint8> *state)//发送血氧值
{
    //串口收到的数据传输到界面
    m_piNum =(PI->takeFirst())*0.1;//PI值
    //m_piNum =(PI->first())*0.1;//PI值
    m_spo2Num = data->takeFirst(); //血氧值
    listSPO2<< waves->takeFirst(); //容积波
    rata->takeFirst(); //脉率值暂时用不到
    m_columHeight = (130*(column->takeFirst())/15); //脉搏柱
    spo2State = state->takeFirst();
    //第一位是状态位bit0:1 手指插入标志 1是手指未，0是手指插入
    //bit1:1 探头脱落标志 1探头脱落，0是探头正常
    //bit2:1 测量干扰提示 1测量有干扰 0是测量无干扰
    //bit3:1 脉搏音 bit7~bit4 未定义
    if((spo2State&0x01) == 1)//检测手指未插入
    {
        emit warnMessage2MainPage(22,2);  //发送手指未插入警告
    }
    else if(((spo2State>>1)&0x01) == 1) //检测到血氧探头脱落
    {
        emit warnMessage2MainPage(23,2);  //探头脱落警告
    }
    else  //其他状态都归为正常
    {
        //emit warnMessage2MainPage(32,2);  //发送血氧状态正常指令
        emit warnMessage2MainPage(41,2);  //发送血氧状态正常指令
    }
    if(m_spo2Num == 0)
    {
        emit warnMessage2MainPage(12,0); //发送血氧正常信号
    }
    else
    {
        if(m_WideOrNarrowThresHoldChoice == true) //如果当前是窄阈值
        {
            if(m_spo2Num < m_spo2ThresHoldValue)
            {
                emit warnMessage2MainPage(3,m_spo2ThresHoldLevel);
            }
            else
            {
                emit warnMessage2MainPage(12,0); //发送血氧正常信号
            }

        }
        else if(m_WideOrNarrowThresHoldChoice == false) //如果当前时宽阈值
        {
            if(m_spo2Num < m_spo2ThresHoldValueWide)
            {
                emit warnMessage2MainPage(3,m_spo2ThresHoldLevelWide);
            }
            else
            {
                emit warnMessage2MainPage(12,0); //发送血氧正常信号
            }

        }
    }
    if(listSPO2.length()>50) //解决返回显示心电图和血氧曲线页面卡顿的问题
    {
        listSPO2.clear();
    }
    else if((listSPO2.length()>0)&&(listSPO2.length()<=50))
    {
        emit spo2NumChanged(); //发送血样数值变化信号


    }
}

void M3ShowController::onRecHeartRateFromDataAcq(quint16 heartRate) //发送心率值
{
    m_hearRate = heartRate;
    if(m_hearRate == 9999)
    {
        emit warnMessage2MainPage(11,0);//发送心率正常信号
    }
    else
    {
        if(m_WideOrNarrowThresHoldChoice == true) //窄阈值
        {
            if(m_hearRate< m_hrSlowValue) //小于设置阈值最小值，心动过缓
            {
                emit warnMessage2MainPage(2,m_hrSlowLevel);//发送心动过缓报警和报警级别
            }
            else if((m_hearRate>=m_hrSlowValue)&&(m_hearRate< m_hrFastValue)) //正常范围之内
            {
                emit warnMessage2MainPage(11,0);//发送心率正常信号
            }
            else if(m_hearRate> m_hrFastValue) //大于最大值，心动过速
            {
                emit warnMessage2MainPage(1,m_hrFastLevel);//发送心动速报警和报警级别
            }
        }
        else if(m_WideOrNarrowThresHoldChoice == false) //宽阈值
        {
            if(m_hearRate< m_hrSlowValueWide) //小于设置阈值最小值，心动过缓
            {

                emit warnMessage2MainPage(2,m_hrSlowLevelWide);//发送心动过缓报警和报警级别
            }
            else if((m_hearRate>=m_hrSlowValueWide)&&(m_hearRate< m_hrFastValueWide)) //正常范围之内
            {
                emit warnMessage2MainPage(11,0);//发送心率正常信号
            }
            else if(m_hearRate> m_hrFastValueWide) //大于最大值，心动过速
            {
                emit warnMessage2MainPage(1,m_hrFastLevelWide);//发送心动过缓报警和报警级别
            }
        }
    }
    emit heartRateChanged();
}



void M3ShowController::onMeasureNIBPFlagChanged()
{
    qDebug()<<"MeasureNIBPFlagChanged"<<endl;
}

void M3ShowController::onMeasureMinuteChanged()
{
    qDebug()<<"minute = "<<m_AutoMeasureNIBPMinut<<endl;
}

void M3ShowController::onRecordECGFlagChanged()
{
    emit recordECGFlagChangeSignal(m_recordECGFlag);//将携带心电标志位的值的信号发送出去
}

void M3ShowController::onPatientTypeChanged()    //当病人的类型发生改变时
{
    emit patientTypeChangedSignal(m_patientType);
}

void M3ShowController::onRecBatValSignal(int val,int val2)//收到数据采集类的电池电量的信号
{
    emit batValSendSig(val,val2);//传递电池的电量

}

void M3ShowController::onRecLeadsOffSignalFromDataAcq(int leadsOffData)
{
    if(m_leadsType == 0)//如果当前是12导联显示界面
    {
        emit warnMessage2MainPage(leadsOffData,2); //将导联脱落数据传递给界面现显示
    }
    else if(m_leadsType == 1) //如果当前是3导联显示界面
    {
        //                     RL导联                                      RA导联                                      LA导联                                      LL导联
        if((leadsOffData == 34)||(leadsOffData == 52)||(leadsOffData == 25)||(leadsOffData == 44)||(leadsOffData == 26)||(leadsOffData == 45)||(leadsOffData == 27)||(leadsOffData == 46))
        {
            emit warnMessage2MainPage(leadsOffData,2);
        }
    }
}

void M3ShowController::onDataAndTimeChanged()
{
   // qDebug()<<"要设置的系统时间为："<<m_dateAndTime;
    QStringList strList;
    strList = m_dateAndTime.split(" ");
    qDebug()<<strList.length();
    cmd = "date -s "+strList[0];
    system(cmd.toLatin1().data());
    cmd = "date -s "+strList[1];
    system(cmd.toLatin1().data());
    cmd = "hwclock -w";
    system(cmd.toLatin1().data());
    qDebug()<<"the time is set over";
    cmd = "sync";
    system(cmd.toLatin1().data());
}

void M3ShowController::netTransFlagChangeRev() //网络传输模式的改变 有线 无线 蓝牙
{
    qDebug()<<"the net TransFlag is changed "<<m_netTransFlag;
    for (int i = 0;i<dbusConn->services_list.size();i++)
    {
        qDebug()<<dbusConn->services_list[i].objmap.value("name").toString();
    }
}

void M3ShowController::onDBusServiceChanged(int type)//用于接受dbus_connman类的service_changed信号
{
    //更新wifi列表的内容
    QString _type; //网络类型
    QString name;
    int connecState = 0;
    for(int i = 0;i<dbusConn->services_list.size();i++)
    {
       // qDebug()<<dbusConn->services_list[i].objmap.value("Name").toString()<<"       "<<dbusConn->services_list[i].objmap.value("State").toString();

        _type = dbusConn->services_list[i].objmap.value("Type").toString();
        //显示当前的名字
        //qDebug()<<"current name is "<<_type;
        if(_type == "ethernet") //当前连接是有线连接
        {
            //有线网络切换成功
            qDebug()<<"Lan net switched sucessed";
        }
        else if(_type == "wifi")//当前连接是无线连接
        {
            //qDebug()<<"wifi SSID list changed";
            name = dbusConn->services_list[i].objmap.value("Name").toString();
            //qDebug()<<dbusConn->services_list[i].objmap.value("Name").toString()<<"-------------"<<dbusConn->services_list[i].objmap.value("State").toString();
            if((dbusConn->services_list[i].objmap.value("State").toString() == "online")||(dbusConn->services_list[i].objmap.value("State").toString() == "ready")||(dbusConn->services_list[i].objmap.value("State").toString() == "association"))
            {
                connecState = 1;  //已连接
                //qDebug()<<"in assosiation";
                m_connectedWIFIName = dbusConn->services_list[i].objmap.value("Name").toString();
                emit connectedWIFINameChanged();
            }
            else {
                connecState = 0;
                //qDebug()<<"not in assosiation";
            }
            m_wifiServiceMap.insert(name,connecState);
        }

    }

    emit serviceChangeCompleted();

}

void M3ShowController::onRecCanGetIPAddress()//获取有线网络相关的信息，网卡地址.IP地址.子网掩码.网关
{
    dbusConn->getLanAndWLanInformation();
    if(m_netTransFlag == 1) //如果当前为有线传输
    {
        m_BtMacAddress = "";
        getLANMessages();//获取有线网络相关的信息，网卡地址.IP地址.子网掩码.网关

    }
    else if(m_netTransFlag == 2) //如果当前为无线传输
    {
        m_lanIPAddress = "";
        m_lanMacAddress = "";
        m_lanNetGate = "";
        m_lanNetMask = "";
        m_wlanIPAddress = dbusConn->WLanIPAddress;
        m_wlanMacAddress = dbusConn->WLanMacAddress;
        m_BtMacAddress = "";
        if(m_wlanIPAddress == "") //如果没获取到IP地址
        {
            getWLANMessages(); //获取无线网络相关的信息，网卡地址.IP地址
        }
        //qDebug()<<"m_wlanIPAddress = "<<dbusConn->WLanIPAddress;
        //qDebug()<<"m_wlanMacAddress = "<<dbusConn->WLanMacAddress;
    }
    else if(m_netTransFlag == 3) //如果当前为蓝牙传输
    {
        m_lanIPAddress = "";
        m_lanMacAddress = "";
        m_lanNetGate = "";
        m_lanNetMask = "";
        m_wlanIPAddress = "";
        m_wlanMacAddress = "";
    }
    emit netChangedAndIPAddressGeted();
}

void M3ShowController::onNetTransFlagChanged()
{
    qDebug()<<"net Trans Changed";
    dbusConn->netConnectType = m_netTransFlag;
}

//void M3ShowController::btOpenSuccessed()
//{
//    btOpenStatus = 1; //蓝牙打开成功
//    qDebug()<<"m3ShowController btOpenSuccessed";

//}

//void M3ShowController::btOpenFailed()
//{
//    btOpenStatus = 0; //蓝牙打开失败
//    qDebug()<<"m3ShowController btOpenFailed";
//}


int M3ShowController::sPO2DataCount(void)
{
      return listSPO2.count();//返回血氧值的剩余个数
}
QList<int> M3ShowController::getSPO2Data(void)
{
    return listSPO2;//返回第一个值
}

void M3ShowController::clearSPO2Data()
{
    listSPO2.clear();
}


void M3ShowController::transmitNIBPStartSignal() //将界面开始测量血压的信号 传递给数据采集类
{
    emit NIBPStartSignal(); //发送血压测量信号

}

void M3ShowController::transmitNIBPStopSignal()
{
    emit NIBPStopSignal(); //发送血压停止测量的信号
}

void M3ShowController::getLANMessages() //获取有线网络相关的信息，网卡地址.IP地址.子网掩码.网关
{
    QFile *file = new QFile("/demo/ifconfig.data");
    if(file->exists()) //如果文件存在
    {
        if(file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream out(file);
            QString str ;
            QStringList strList,subStrList;
            str = out.readLine();
            while(!out.atEnd())
            {
                if(str.contains("eth"))
                {
                    strList = str.split(" ");
                    for(int i = 0;i < strList.size();i++)
                    {
                        if(strList[i].contains("HWaddr"))
                        {
                            m_lanMacAddress = strList[i+1];
                        }
                    }
                    str = out.readLine();
                    strList = str.split(" ");
                    for(int i = 0;i < strList.size();i++)
                    {
                        if(strList[i].contains("HWaddr"))
                        {
                            m_lanMacAddress = strList[i+1];
                        }
                        else if(strList[i].contains("addr:"))
                        {
                            subStrList = strList[i].split(":");
                            m_lanIPAddress = subStrList[1];
                        }
                        else if(strList[i].contains("Bcast:"))
                        {
                            subStrList = strList[i].split(":");
                            m_lanNetGate = subStrList[1];
                        }
                        else if(strList[i].contains("Mask:"))
                        {
                            subStrList = strList[i].split(":");
                            m_lanNetMask = subStrList[1];
                        }
                    }
                }
                str = out.readLine();
            }
        }
        else {//如果文件不能打开
            m_lanIPAddress = "";
            m_lanMacAddress = "";
            m_lanNetGate = "";
            m_lanNetMask = "";
        }

    }
}





void M3ShowController::getWLANMessages() //获取无线网络相关的信息，网卡地址.IP地址
{
    QFile *file = new QFile("/demo/wlanifconfig.data");
    if(file->exists()) //如果文件存在
    {
        if(file->open(QIODevice::ReadOnly | QIODevice::Text))
        {
            QTextStream out(file);
            QString str ;
            QStringList strList,subStrList;
            str = out.readLine();
            while(!out.atEnd())
            {
                if(str.contains("wlan"))
                {
                    strList = str.split(" ");
                    for(int i = 0;i < strList.size();i++)
                    {
                        if(strList[i].contains("HWaddr"))
                        {
                            m_wlanMacAddress = strList[i+1];
                        }
                    }
                    str = out.readLine();
                    strList = str.split(" ");
                    for(int i = 0;i < strList.size();i++)
                    {
                        if(strList[i].contains("HWaddr"))
                        {
                            m_wlanMacAddress = strList[i+1];
                        }
                        else if(strList[i].contains("addr:"))
                        {
                            subStrList = strList[i].split(":");
                            m_wlanIPAddress = subStrList[1];
                        }
                    }
                }
                str = out.readLine();
            }

        }
        else {//如果文件不能打开
            m_wlanIPAddress = "";
            m_wlanMacAddress = "";
        }
    }
}















