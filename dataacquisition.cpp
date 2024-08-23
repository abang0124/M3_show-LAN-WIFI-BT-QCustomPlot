#include "dataacquisition.h"
#include <QFile>
#include <QFileInfo>
#include <QTextStream>

//#include <QThread>

#define BAT_ARRAY_LEN 20
#define ECG_DIFF_THRESHOLD  50000  //ECG相邻数据的差值
void DataAcquisition::ECGDataProcessedTrans()
{
    for(quint8 z=0;z<12;z++)
    {
       int length = ecg_real_data_processed_array[z].length();
       //qDebug()<<"length = "<<length;
       for(int num = 0;num<length;num++)
       {
           ecg_processed_data_trans_array[z]<<ecg_real_data_processed_array[z].takeFirst();
       }
    }
    ECGDataRevProcessedFlag = false; //该位置false
    //qDebug()<<"transfer data to m3showcontroller length = "<<ecg_processed_data_trans_array[11].length();
    //发送信号给m3showcontroller类接收数据
   // qDebug()<<"ECGDataRevProcessedFlag = false";
    emit LeadsShowData2M3DataControl(ecg_processed_data_trans_array);
}

void DataAcquisition::AcordingLeasTypeTransECGData() //将数据存储下来并传递给显示部分
{
    ecgcount++;
    if(ecgcount == LEAD3COUNT)
    {
        ecgcount = 0;
        for(int i = 0;i<12;i++)
        {
             ecg_real_data_processed_array[i] <<(int)(ecg_real_data_array_for_show[i].takeFirst()*100);
        }
        //qDebug()<<"ecg_real_data_processed_array[11].length() = "<<ecg_real_data_processed_array[11].length();
        //qDebug()<<"ECGDataRevProcessedFlag = "<<ECGDataRevProcessedFlag;
    }
    else//每5个数据取1一个数据
    {
        for(int i = 0;i<12;i++)
        {
            ecg_real_data_array_for_show[i].takeFirst();
        }
    }
    if(ECGDataRevProcessedFlag) //如果m3showcontroller类收到了数据
    {
        if(ecg_real_data_processed_array[11].length() >= 50) //存储的数值长度大于等于50时
        {
            ECGDataProcessedTrans();
            //qDebug()<<"ecg data transted";
        }
    }
}
/*不要在子线程类的构造函数中构造该对象用到的所有东西，因为这些东西都属于创造该子线程的主线程
 * Qt中子线程的构造函数相当于时在主线程中创建的所以在此构造函数中的QTimer 和 QSerialPort都属于创造该子线
的主线程，所以无法在该子线程中操作这些对象
*/
DataAcquisition::DataAcquisition(QObject *parent) : QObject(parent) //构造函数初始化串口，并且打开串口
{
//    ecgcount = 0;//初始化ecgcount的变量为0
//    recordECGFlag = false;
//    leadsShowType = 0; //单个页面导联显示类型 0为3个导联 1为6个导联 2为12个导联
//    //threeLeadOr12Leadshow = true; //判断当前的显示界面是3导联显示还是12导联显示 true 3导联显示 false 12导联显示
//    acqusitionPort = new QSerialPort(this); //初始化采集模块用到的串口
//    ecgDataProc = new ECGDataProcess();
//    SerialPortInit();   //串口的初始化
//    if (!acqusitionPort->open(QIODevice::ReadWrite))
//    {
//        QMessageBox::about(NULL, "错误",
//                           "串口无法打开！可能串口已经被占用！");//打开串口
//    }
//    tm = new QTimer();
//    tm->setInterval(30);
//    tm->setTimerType(Qt::PreciseTimer);
//    connect(tm,SIGNAL(timeout()),this,SLOT(dataAcq())); //定时器信号
//    ECGDataRevProcessedFlag = true;
//    QByteArray data = "ECGstart\r\n";
//    acqusitionPort->write(data); //心电图开始测量

//    //测试串口读到的ECG数据，将数据存储到文件中
//    filestream = new QTextStream();
//    //创造新的电池类
//    bat = new Battery();
//    batTimer = new QTimer();
//    batTimer->setInterval(1000); //间隔1s
//    connect(batTimer,SIGNAL(timeout()),this,SLOT(readBatVal())); //定时器信号
//    batTimer->start();

}


void DataAcquisition::onDataAcquisitionThreadCreat()  //该函数中所有的对象都是在子线程中运行的
{

    ecgcount = 0;//初始化ecgcount的变量为0
    recordECGFlag = false;
    leadsShowType = 0; //单个页面导联显示类型 0为3个导联 1为6个导联 2为12个导联
    //byteArrayLeftLength = 0;//开始剩余数据的长度为0
    //threeLeadOr12Leadshow = true; //判断当前的显示界面是3导联显示还是12导联显示 true 3导联显示 false 12导联显示
    LP_type = 3;
    HP_type = 4;
    AC_type = 2;
    filterFirstFlag = true;
    acqusitionPort = new QSerialPort(this); //初始化采集模块用到的串口
    //dataSocket = new QTcpSocket(this); //初始化数据传输模块
    ecgDataProc = new ECGDataProcess();
    ts = new QTcpServer;
    ts->listen(QHostAddress::Any,NET_PORT);
    connect(ts,&QTcpServer::newConnection,this,[=]{
        dataSocket = ts->nextPendingConnection();
        connect(dataSocket,&QTcpSocket::readyRead,this,[=]{
            socketReadBuf = dataSocket->readAll();
            str = QString(socketReadBuf);
            if(str == "Start")
            {
                netConnectedFlag = true;
            }
            else if(str == "Stop")
            {
                netConnectedFlag = false;
            }
        });
        connect(dataSocket,&QTcpSocket::disconnected,this,[=]{
            netConnectedFlag = false;
        });
    });
    netmanage = new QNetworkConfigurationManager(this);
//    if(netmanage->isOnline()==true)
//    {
//        dataSocket->connectToHost(QHostAddress(NET_ADDRESS),NET_PORT);
//        qDebug()<<"net connected in first";
//        //netConnectedFlag = true;
//    }
    connect(netmanage,&QNetworkConfigurationManager::onlineStateChanged,this,[=](bool value){
        if(value)
        {
            //qDebug()<<"net connected";
            //dataSocket->connectToHost(QHostAddress(NET_ADDRESS),NET_PORT);

        }
        else {
            qDebug()<<"net disconnected";
            netConnectedFlag = false;
        }
    });
//    connect(dataSocket,&QTcpSocket::connected,this,[=]{
//        //netConnectedFlag = true;
//    });
//    connect(dataSocket,&QTcpSocket::disconnected,this,[=]{
//        netConnectedFlag = false;
//    });
//    connect(dataSocket,&QTcpSocket::readyRead,this,[=]{
//        socketReadBuf = dataSocket->readAll();
//        str = QString(socketReadBuf);
//        if(str == "Start")
//        {
//            netConnectedFlag = true;
//        }
//        else if(str == "Stop")
//        {
//            netConnectedFlag = false;
//        }
//    });
    //SerialPortInit();   //串口的初始化
    //QString address = "192.168.1.100";
//    dataSocket->connectToHost(QHostAddress("192.168.1.100"),8899);
//    if (!acqusitionPort->open(QIODevice::ReadWrite))
//    {
//        QMessageBox::about(NULL, "错误",
//                           "串口无法打开！可能串口已经被占用！");//打开串口
//    }
//    tm = new QTimer();
//    tm->setInterval(30);
//    tm->setTimerType(Qt::PreciseTimer);
//    connect(tm,SIGNAL(timeout()),this,SLOT(dataAcq())); //定时器信号
    //ECGDataRevProcessedFlag = true;
    //QByteArray data = "ECGstart\r\n";
    //acqusitionPort->write(data); //心电图开始测量

    //测试串口读到的ECG数据，将数据存储到文件中
    filestream = new QTextStream();
    orifilestream = new QTextStream();
    btServer = new BluetoothServer();
    //创造新的电池类
    bat = new Battery();
    batTimer = new QTimer();
    batTimer->setInterval(1000); //间隔1s
    connect(batTimer,SIGNAL(timeout()),this,SLOT(readBatVal())); //定时器信号
    batTimer->start();
    //qDebug()<<"dataAcquisition thread is "<<QThread::currentThreadId();
}


void DataAcquisition::SerialPortInit()
{
    acqusitionPort->setPortName("ttyS3"); //打开串口ttyS3
    acqusitionPort->setBaudRate(921600);
    acqusitionPort->setParity(QSerialPort::NoParity);
    acqusitionPort->setDataBits(QSerialPort::Data8);
    acqusitionPort->setStopBits(QSerialPort::OneStop);
    acqusitionPort->setFlowControl(QSerialPort::NoFlowControl);
    //connect(acqusitionPort, SIGNAL(readyRead()),this, SLOT(serialport_recive_data()));
}

void DataAcquisition::startDataAcq() //线程任务函数//尝试数据采集方式：1定时器定时采集 2串口对象的readyRead信号//线程的入口函数
{

    tm = new QTimer(this);
    tm->setInterval(30);
    tm->setTimerType(Qt::PreciseTimer);
    connect(tm,SIGNAL(timeout()),this,SLOT(dataAcq())); //定时器信号
    tm->start();

    //filestream->setDevice(ecgfile);
    //connect(acqusitionPort,SIGNAL(readyRead()),this,SLOT(dataAcq())); //串口readyRead 信号
}

void DataAcquisition::onRecLP_typeChanged(quint8 value)
{
    LP_type = value;  //低通滤波 =0 25Hz  =1 40Hz  =2 150Hz  =3关闭
    filterFirstFlag = true; //滤波类型的变化，每次都是第一次
    //ecg_real_data_list_before_filter->clear();
    //qDebug()<<"LP_type = "<<LP_type<<endl;
}

void DataAcquisition::onRecHP_typeChanged(quint8 value)
{
    HP_type = value;  //高通滤波 =0 0.05Hz =1 0.15Hz =2 0.3Hz =3 0.67Hz  =4关闭
    filterFirstFlag = true;  //滤波类型的变化，每次都是第一次
    //ecg_real_data_list_before_filter->clear();
    //qDebug()<<"HP_type = "<<HP_type<<endl;
}

void DataAcquisition::onRecAC_typeChanged(quint8 value)
{
    AC_type = value;  //电源滤波 =0 50Hz  =1 60Hz =2关闭

    //qDebug()<<"AC_type = "<<AC_type<<endl;
}

void DataAcquisition::calculate_HR_and_emitSignal(int lead) //计算心率并发送心率值信号
{
    //if(ecg_real_data_array[lead].length()>=20001)  //计算心率
    if(ecg_real_data_array[lead].length()>=(ecgDataProc->hearRateBufLength+1))  //计算心率
    {
        //int moreThanlegth = ecg_real_data_array[lead].length()-20000;
        int moreThanlegth = ecg_real_data_array[lead].length()-ecgDataProc->hearRateBufLength;
        for(int i=0;i<moreThanlegth;i++)
        {
            ecg_real_data_array[lead].takeFirst(); //如果list的长度等于20001时，执行takeFirst数据长度还是20000。然后将数据传递给心率计算函数
        }

        if(hr_calculate_flag == false)  //相当于每间隔 HR_CAL_COUNT_LEN长度计算一次心率
        {
            hr_calculate_count++;
            if(hr_calculate_count == HR_CAL_COUNT_LEN)
            {
                hr_calculate_flag = true;
                hr_calculate_count = 0;
            }
        }
        if(lead == 11) //算心率
        {
            if(hr_calculate_flag == true)
            {
                //qDebug()<<"ecg_real_data_array[I].length() = "<<ecg_real_data_array[I].length();
                emit HeartRate2M3DataControl(ecgDataProc->M3_process((float*)(&(ecg_real_data_array[I][0])),PatientType));//查找程序卡死原因，暂时将求心率这一块关掉
                //emit HeartRate2M3DataControl(63);
                hr_calculate_flag = false;
            }
        }
    }
    else{

        emit HeartRate2M3DataControl(9999);//9999代表无心率
    }
}

void DataAcquisition::onRecUILoadCompleted() //接收到界面加载完成的信号
{
    SerialPortInit();   //串口的初始化
    qDebug()<<"UI load completed";
    //dataSocket->connectToHost(QHostAddress("192.168.1.100"),8899);
    if (!acqusitionPort->open(QIODevice::ReadWrite))
    {
        QMessageBox::about(NULL, "错误",
                           "串口无法打开！可能串口已经被占用！");//打开串口
    }
    startDataAcq(); //打开定时器，开始定时从串口读数据
    ECGDataRevProcessedFlag = true;
    QByteArray data = "ECGstart\r\n";
    acqusitionPort->write(data); //心电图开始测量
}


/**
 * 从串口接受到的数据，首先存到ecg_real_data_list_before_filter这个列表中 该列表是一个列表数组，每个数组项代表一个导联
 * 然后将数据存储到ecg_real_data_array_before_filter这个数组中 该数组是将列表数组ecg_real_data_list_before_filter按照每个导联长度为FILTER_LEN从1到12的顺序存进去
 * 然后利用12导联的函数进行滤波
 *
 *
 *
 *
*/

//if(lead == 11)
 void DataAcquisition::ecgDataFilter() //形参为通道
 {
     //肌电滤波  LP选择
          /*
           EMG_interference_remove中的第一个参数是输入的数组
                                     第二个参数是数组的长度
                                     第三个参数是滤波的类型 LP滤波  =0 是25Hz，  =1是40Hz，=3是150Hz，=4是关闭
                                     第四个参数是滤波后的数组
                                     第五个是普通数组 自己定义一个长度的数组即可
                                     第6个是第几次滤波 第一次滤波填写0,第一次以后填写1即可
     **/

     //if(ecg_real_data_list_before_filter[11].length() == FILTER_LEN)
     if((ecg_real_data_list_before_filter[11].length() >= FILTER_LEN)&&(ecg_real_data_list_before_filter[11].length() <= FILTER_LEN_MAX))
     {

         int length = ecg_real_data_list_before_filter[11].length();
         for(int lead =0 ;lead<12;lead++)
         {
             //for(int i = 0;i < FILTER_LEN;i++)
             for(int i = 0;i < length;i++)
             {
                 //ecg_real_data_array_before_filter[lead*FILTER_LEN+i] = ecg_real_data_list_before_filter[lead][i];
                 ecg_real_data_array_before_filter[lead*length+i] = ecg_real_data_list_before_filter[lead][i];
             }
             ecg_real_data_list_before_filter[lead].clear();
         }
         if(filterFirstFlag == true) //如果是第一次进行数据滤波
         {
//             ecgDataProc->EMG_interference_remove_12L(ecg_real_data_array_before_filter,FILTER_LEN,LP_type,ecg_real_data_array_after_LP_filter,ecgDataProc->f_data_in_lp,0); //进行LP滤波
//             ecgDataProc->HPforbaseline_remove_12L(ecg_real_data_array_after_LP_filter,FILTER_LEN,HP_type,ecg_real_data_array_after_HP_filter,ecgDataProc->f_data_in_hp,0);  //进行HP滤波
//             ecgDataProc->Power_line_interference_remove_12L(ecg_real_data_array_after_HP_filter,FILTER_LEN,AC_type,ecg_real_data_array_after_AC_filter);  //进行AC滤波
             ecgDataProc->EMG_interference_remove_12L(ecg_real_data_array_before_filter,length,LP_type,ecg_real_data_array_after_LP_filter,ecgDataProc->f_data_in_lp,0); //进行LP滤波
             ecgDataProc->HPforbaseline_remove_12L(ecg_real_data_array_after_LP_filter,length,HP_type,ecg_real_data_array_after_HP_filter,ecgDataProc->f_data_in_hp,0);  //进行HP滤波
             ecgDataProc->Power_line_interference_remove_12L(ecg_real_data_array_after_HP_filter,length,AC_type,ecg_real_data_array_after_AC_filter);  //进行AC滤波

             filterFirstFlag = false;
         }
         else
         {
//             ecgDataProc->EMG_interference_remove_12L(ecg_real_data_array_before_filter,FILTER_LEN,LP_type,ecg_real_data_array_after_LP_filter,ecgDataProc->f_data_in_lp,1); //进行LP滤波
//             ecgDataProc->HPforbaseline_remove_12L(ecg_real_data_array_after_LP_filter,FILTER_LEN,HP_type,ecg_real_data_array_after_HP_filter,ecgDataProc->f_data_in_hp,1);  //进行HP滤波
//             ecgDataProc->Power_line_interference_remove_12L(ecg_real_data_array_after_HP_filter,FILTER_LEN,AC_type,ecg_real_data_array_after_AC_filter);  //进行AC滤波
             ecgDataProc->EMG_interference_remove_12L(ecg_real_data_array_before_filter,length,LP_type,ecg_real_data_array_after_LP_filter,ecgDataProc->f_data_in_lp,1); //进行LP滤波
             ecgDataProc->HPforbaseline_remove_12L(ecg_real_data_array_after_LP_filter,length,HP_type,ecg_real_data_array_after_HP_filter,ecgDataProc->f_data_in_hp,1);  //进行HP滤波
             ecgDataProc->Power_line_interference_remove_12L(ecg_real_data_array_after_HP_filter,length,AC_type,ecg_real_data_array_after_AC_filter);  //进行AC滤波

         }

         for(int lead =0 ;lead<12;lead++) //判断逻辑可能有问题 最后一组数据和前面几组的数据可能不一样
         {
             //for(int i = 0;i < FILTER_LEN;i++)
             for(int i = 0;i < length;i++)
             {
//                 ecg_real_data_array[lead]<<ecg_real_data_array_after_AC_filter[lead*FILTER_LEN+i]; //将滤波完成后的数据再存入ecg_real_data_array列表中ecg_real_data_array 用来计算心率
//                 ecg_real_data_array_for_show[lead]<<ecg_real_data_array_after_AC_filter[lead*FILTER_LEN+i]; //ecg_real_data_array_for_show 用于传递给显示
                 //将基线加去的值再减回来
//                 ecg_real_data_array[lead]<<(ecg_real_data_array_after_AC_filter[lead*FILTER_LEN+i]-baseLineArray[lead]); //将滤波完成后的数据再存入ecg_real_data_array列表中ecg_real_data_array 用来计算心率
//                 ecg_real_data_array_for_show[lead]<<(ecg_real_data_array_after_AC_filter[lead*FILTER_LEN+i]-baseLineArray[lead]); //ecg_real_data_array_for_show 用于传递给显示
                 ecg_real_data_array[lead]<<(ecg_real_data_array_after_AC_filter[lead*length+i]-baseLineArray[lead]); //将滤波完成后的数据再存入ecg_real_data_array列表中ecg_real_data_array 用来计算心率
                 ecg_real_data_array_for_show[lead]<<(ecg_real_data_array_after_AC_filter[lead*length+i]-baseLineArray[lead]); //ecg_real_data_array_for_show 用于传递给显示


                 calculate_HR_and_emitSignal(lead);//用I导联计算心率

                 if(lead == 11)
                 {
                    AcordingLeasTypeTransECGData(); //将数据存储下来并传递给显示部分
                 }
             }

         }
         if(recordECGFlag == true)  //根据实际情况，查看是否需要将滤波后的数据记录到文件中
         {
             recordECGDataAfterFilter2File(length);
         }
         //AcordingLeasTypeTransECGData(); //将数据存储下来并传递给显示部分
     }
     else if(ecg_real_data_list_before_filter[11].length() > FILTER_LEN_MAX) //测试程序崩溃是不是在此处
     {
          qDebug()<<"too much data";
          int length = ecg_real_data_list_before_filter[11].length() - FILTER_LEN_MAX +25;
          for(int lead = 0;lead<12;lead++ )
          {
              for (int i = 0; i< length;i++) {
                  ecg_real_data_list_before_filter[lead].takeFirst();
              }
          }
     }
 }

 void DataAcquisition::recordECGDataAfterFilter2File(int length)  //将滤波后的数据存储到文件当中
 {

     for(int lead =0 ;lead<12;lead++)
     {
         for(int i = 0;i < length;i++)
         {
             ecg_real_data_list_after_filter_store_tofile[lead]<<ecg_real_data_array_after_AC_filter[lead*length+i]; //将滤波完成后的数据再存入ecg_real_data_array列表中
             //ecg_real_data_list_after_filter_store_tofile[lead]<<ecg_real_data_array_for_show[lead][i]; //将滤波完成后的数据再存入ecg_real_data_array列表中
         }

     }

     int len = ecg_real_data_list_after_filter_store_tofile[11].length();

     for(int count = 0;count<len;count++)
     {
         for(int j =0;j<12;j++)
         {
             if(j!=11)
             {
                 *filestream<< QString("%1").arg(ecg_real_data_list_after_filter_store_tofile[j].takeFirst())<<'\t';

             }
             else{
                 *filestream<< QString("%1").arg(ecg_real_data_list_after_filter_store_tofile[j].takeFirst())<<endl;;
             }
         }
     }

 }

 void DataAcquisition::ECGDataAbrutProcess(int j)
 {
     if(ecg_real_data_list_before_filter_temp[j].length()==0) //第一次取值
     {
         int length = ecg_real_data_list_before_filter[j].length();//整个list的长度
         if(length == 2) //如果数据长度为2
         {
             for(int tempValue = 0;tempValue<11;tempValue++)
             {
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeFirst(); //取第一个值
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeFirst(); //取第二个值

             }
         }
         else if(length > 2)//如果数据长度大于2
         {
             for(int tempValue = 0;tempValue<11;tempValue++)
             {
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeAt(length-3); //去倒数第3个值，list 的长度-1
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeAt(length-3); //取倒数第二个值
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeLast(); //取最后一个值
             }
         }
     }
     else{
         int length = ecg_real_data_list_before_filter_temp[j].length();
         if(length == 5) //数据长度等于5 开始处理异常值
         {
             for(int temp_count = 0;temp_count<12;temp_count++)
             {
                 if((qAbs(ecg_real_data_list_before_filter_temp[temp_count][0]-ecg_real_data_list_before_filter_temp[temp_count][1])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][0]-ecg_real_data_list_before_filter_temp[temp_count][2])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][0]-ecg_real_data_list_before_filter_temp[temp_count][3])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][0]-ecg_real_data_list_before_filter_temp[temp_count][4])>ECG_DIFF_THRESHOLD)
                         )//判读第一种情况 ，第一个值为最大值，后面的值均为小值
                 {
                     for (int remove_count = 0;remove_count<12;remove_count++) {
                        ecg_real_data_list_before_filter_temp[remove_count].takeFirst();
                     }
                     break;
                 }
                 else if((qAbs(ecg_real_data_list_before_filter_temp[temp_count][1]-ecg_real_data_list_before_filter_temp[temp_count][0])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][1]-ecg_real_data_list_before_filter_temp[temp_count][2])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][1]-ecg_real_data_list_before_filter_temp[temp_count][3])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][1]-ecg_real_data_list_before_filter_temp[temp_count][4])>ECG_DIFF_THRESHOLD)
                         ) //第二种情况，第2个值为异常值
                 {
                     for (int remove_count = 0;remove_count<12;remove_count++) {
                        ecg_real_data_list_before_filter_temp[remove_count].takeAt(1);
                     }
                     break;
                 }
                 else if((qAbs(ecg_real_data_list_before_filter_temp[temp_count][2]-ecg_real_data_list_before_filter_temp[temp_count][1])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][2]-ecg_real_data_list_before_filter_temp[temp_count][0])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][2]-ecg_real_data_list_before_filter_temp[temp_count][3])>ECG_DIFF_THRESHOLD)
                         &&(qAbs(ecg_real_data_list_before_filter_temp[temp_count][2]-ecg_real_data_list_before_filter_temp[temp_count][4])>ECG_DIFF_THRESHOLD)
                         ) //第三种,第3个值为异常值
                 {
                     for (int remove_count = 0;remove_count<12;remove_count++) {
                        ecg_real_data_list_before_filter_temp[remove_count].takeAt(2);
                     }
                     break;
                 }
             }
             int temp_length = ecg_real_data_list_before_filter_temp[j].length();
             for (int i_count = 0;i_count < temp_length;i_count++)
             {

                 for (int z = 0;z < 12;z++)
                 {
                     ecg_real_data_list_before_filter[z]<<ecg_real_data_list_before_filter_temp[z].takeFirst();
                 }

             }
             for (int z = 0;z < 12;z++) //清空临时的链表数组
             {
                 ecg_real_data_list_before_filter_temp[z].clear();
             }
             ECGDataAbrutFlag = false;     //异常数据清理完毕
         }
         else if(length < 5)  //数据长度小于5，继续存储数值
         {
             for(int tempValue = 0;tempValue<11;tempValue++)
             {
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeLast(); //取最后一个值
             }
         }

     }
     int length = ecg_real_data_list_before_filter[j].length();//整个list的长度
     if(length >= 3)
     {
         if(ecg_real_data_list_before_filter_temp[j].length()==0) //如果等于0,那就取最后两个的值
         {
             for(int tempValue = 0;tempValue<11;tempValue++)
             {
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeAt(length-3); //去倒数第3个值，list 的长度-1
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeAt(length-3); //取倒数第二个值
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeLast(); //取最后一个值
             }
         }
         else if((ecg_real_data_list_before_filter_temp[j].length()>0)&&(ecg_real_data_list_before_filter_temp[j].length()<5))
         {
             for(int tempValue = 0;tempValue<11;tempValue++)
             {
                 ecg_real_data_list_before_filter_temp[tempValue]<<ecg_real_data_list_before_filter[tempValue].takeLast(); //取最后一个值
             }
             if(ecg_real_data_list_before_filter_temp[j].length() == 4)  //如果数据长度等于4 ,开始判断是无效的值还是加了偏移量的值
             {

             }
         }
     }
 }

 bool DataAcquisition::BluetoothOpen() //打开蓝牙
 {
     //qDebug()<<"in BluetoothOpen function the threadID is "<<QThread::currentThreadId();
     if(btServer->startServer())//如果成功开启
     {
         connect(btServer,&BluetoothServer::clientConnectedSig,this,&DataAcquisition::BtClientConnected);  //有客户端接入成功的信号 信号传信号
         connect(btServer,&BluetoothServer::clientDisconnectedSig,this,&DataAcquisition::BtClientDisconnected); //客户端断开的信号 信号传信号
         connect(btServer,&BluetoothServer::bluetoothStartTranDataFlag,this,&DataAcquisition::onRecBtServerTransDataSig);   //接收现在是否使用蓝牙传输数据
         connect(this,&DataAcquisition::BtTransData,btServer,&BluetoothServer::sendMessage);  //蓝牙传输数据。解决多线程报错的问题
         return true;
     }
     else{

         return false;
     }

 }

 void DataAcquisition::BluetoothClosed() //关闭蓝牙
 {

     btServer->clientDisconnected();
     disconnect(btServer,&BluetoothServer::clientConnectedSig,this,&DataAcquisition::BtClientConnected);//有客户端接入成功的信号  信号传信号
     disconnect(btServer,&BluetoothServer::clientDisconnectedSig,this,&DataAcquisition::BtClientDisconnected); //客户端断开的信号 信号传信号
     disconnect(btServer,&BluetoothServer::bluetoothStartTranDataFlag,this,&DataAcquisition::onRecBtServerTransDataSig);   //接收现在是否使用蓝牙传输数据
     disconnect(this,&DataAcquisition::BtTransData,btServer,&BluetoothServer::sendMessage);  //蓝牙传输数据。解决多线程报错的问题
     //qDebug()<<"Close Bluetooth  3";
     btServer->stopServer(); //停止蓝牙服务器

 }

void DataAcquisition::onRecBtServerTransDataSig(bool flag) //用来接受使用蓝牙传输数据的标志位
{
     btTransDataFlag = flag;
}

void DataAcquisition::onRecM3DataShowCtlBtOpenSig(bool status) //M3DataControl类用来打开活着关闭蓝牙的信号的槽函数
{
    //qDebug()<<"dataAcqClass onRecM3DataShowCtlBtOpenSig thread ID"<<QThread::currentThreadId();

    if(status)
    {
       //BluetoothOpen();  //打开蓝牙
        emit bluetoothOpenResult(BluetoothOpen(),btServer->btMacAddress);//发送蓝牙打开结果的信号
    }
    else{
        BluetoothClosed(); //关闭蓝牙
    }
}

//void DataAcquisition::onRecBtServerBtOpenSuccess()
//{
//    emit BtOpenSuccessed();
//    qDebug()<<"Sucess";
//}

//void DataAcquisition::onRecBtServerBtOpenFailed()
//{
//    emit BtOpenFailed();
//    qDebug()<<"Failed";
//}



/*
*   AD 的基数data_list=ecg_data1'*1000*2.5/(2^24-1)*1.25*1000    data_list=ecg_data1'*1000*5/(2^24-1)*0.625*1000
*   AD 的分辨率是24位的，所以是2^24-1,参考电压的范围是-2.5V~2.5V，因为1V=1000mV，所以ecg_data1'*1000*5/(2^24-1)是采集到实际mV值，0.625是修正系数
*   最后的1000是为了算法需要  1000*5/(2^24-1)*0.625*1000 = 5000*625/16777215 = 3125000/16777215
*/
/*
20230724 使用生理信号模拟器 测得的AD采集到的值 data_list=ecg_data1'*1000*1.25/(2^24-1)*1000 该算式加了修正系数
在原来的基础上除以2.5
最后得到的值为1.25*1000*1000/16777215 =1250000/16777215

***/
void DataAcquisition::AcqDataAnalyse(QByteArray buf) //对采集到的数据进行分析，将心电数据转换成需要的形式，心电数据，血压数据和血氧数据分离开来,采用新的方法要不然心电显示会有异常,大竖线
{
    float tmpECGData = 0;//用于临时存储心电数据
    int startFlagCount = 0;
    int endFlagCount = 0;
    bool startFlag = false;
    int dataLength = 0;
    leftDataArray.clear(); //每次进入清理该ByteArray容器
    for (int i = 0;i<buf.length();i++)  //整个大循环中寻找有用的数据，心电数据，血氧数据，血压数据，导联脱落数据
    {
        if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(startFlag == false))//先判断开始位 第一次寻找帧头
        {
            startFlag = true;
            startFlagCount = i+3; //存储的是帧头后面的第一个值的位置，用于判断是什么类型的数据 buf[startFlagCount] = 0x01 心电数据 =0X02 血氧数据 =0X03 血压数据 =0X04 导联脱落数据
        }

        else if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(startFlag))//如果第一次寻找帧头已结束
        {
            endFlagCount = i;
            dataLength = endFlagCount-startFlagCount;
            if((buf[startFlagCount] == '\x01')&&(dataLength == 49))//心电数据 49 = 48 + 1 有效数据长度为48
            {
                for(int j = 0;j<12;j++)
                {
                    ecg_real_data_list_before_filter[j] <<((buf[startFlagCount+1+j*4]<<24|(buf[startFlagCount+2+j*4]&0x00FF)<<16|buf[startFlagCount+3+j*4]<<8|buf[startFlagCount+4+j*4])*1250000.0/16777215);

                    //ecg_real_data_array[j] <<((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
//                    tempECGData=((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
//                    if(ecg_real_data_list_before_filter[j].length()>0)
//                    {
//                        if(qAbs(ecg_real_data_list_before_filter[j].last() - tempECGData)>ECG_DIFF_THRESHOLD) //如果出现一个突兀的数值
//                        {
//                                ECGDataAbrutFlag = true;
//                        }
//                        else {
//                            break;
//                        }
//                    }
//                    ecg_real_data_list_before_filter[j]<<tempECGData;
                    //ecg_real_data_list_before_filter[j]<<(((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215)+baseLineArray[j]);
                    if(recordECGFlag == true)
                    {
                        if(j!=11)
                        {
                            *orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<'\t';

                            //*orifilestream<<QString::number(buf[startFlagCount+1+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+2+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+3+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+4+j*4],16)<<'\t';

                        }
                        else{
                            *orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<endl;

                            //*orifilestream<<QString::number(buf[startFlagCount+1+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+2+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+3+j*4],16)<<QString(" ")<<QString::number(buf[startFlagCount+4+j*4],16)<<endl;


                        }
                    }
                    ecg_real_data_list_before_filter[j].last() = ecg_real_data_list_before_filter[j].last()+baseLineArray[j];
                    if(j == 11)
                    {
//                        if(ECGDataAbrutFlag) //如果数据有突兀值标志位
//                        {
//                            ECGDataAbrutProcess(j)
//                        }
//                        else
//                        {
                            ecgDataFilter(); //滤波算法 滤波并计算心率 然后发送心率值
//                        }
                    }


                }
            }
            else if ((buf[startFlagCount] == '\x02')&&(dataLength == 7)) //血氧数据 7 = 6+1 有效数据长度为6
            {

                //第一位是状态位bit0:1 手指插入标志 1是手指未，0是手指插入
                //bit1:1 探头脱落标志 1探头脱落，0是探头正常
                //bit2:1 测量干扰提示 1测量有干扰 0是测量无干扰
                //bit3:1 脉搏音 bit7~bit4 未定义
                M3_SPO2_Sta_data<<buf[startFlagCount+1];         //存储血氧的状态信息
                M3_SPO2_PI_data<<buf[startFlagCount+2];        //存储血氧PI灌注指数 单位0.1%
                M3_SPO2_data<<buf[startFlagCount+3];           //存储血氧值
                M3_SPO2_pulse_rata<<buf[startFlagCount+4];     //存储血氧脉率值
                M3_SPO2_pulse_column<<buf[startFlagCount+5];   //存储血氧脉搏柱
                M3_SPO2_waves<<buf[startFlagCount+6];          //存储血氧容积波
                //qDebug()<<"the length M3_SPO2_PI_data = "<<M3_SPO2_PI_data.length();
                emit SPO2Data2M3DataControl(&M3_SPO2_PI_data,&M3_SPO2_data,&M3_SPO2_pulse_rata,&M3_SPO2_pulse_column,&M3_SPO2_waves,&M3_SPO2_Sta_data);
            }
            else if ((buf[startFlagCount] == '\x03')&&(dataLength == 13)) //血压数据 13 = 12+1 有效数据长度为12
            //else if (buf[startFlagCount] == '\x03') //血压数据 13 = 12+1 有效数据长度为12
            {
                //quint16 sys;
                //quint16 dia;
                M3_BP_sys_data << ((0<<8)|(buf[startFlagCount+2]&0x00FF));//buf[i+1]&0x00ff是因为当最高位为1是，buf前面多出一个字节，这样转换的值高位就会变为0xFF，例如0x93就会变为0xff93
                M3_BP_dia_data << (buf[startFlagCount+3]<<8 | (buf[startFlagCount+4]&0x00FF));
                if(M3_BP_dia_data<M3_BP_sys_data)
                {
                    emit NIBPData2M3DataControl(&M3_BP_sys_data,&M3_BP_dia_data);
                }
                qDebug()<<"dataLength = "<<dataLength;
                qDebug()<<"sys = "<<M3_BP_sys_data<<"dia = "<<M3_BP_dia_data;
                qDebug()<<"recived the BP result";
            }
            else if((buf[startFlagCount] == '\x04')&&(dataLength == 3)) //导联脱落数据 3 = 2+1 有效数据长度为3
            {
                //i+=4;
                quint8 statusP = buf[startFlagCount+1];
                quint8 statusN = buf[startFlagCount+2];
                if(statusP&0x80) //8
                {
                    //qDebug()<<"V6 lead off "<<endl;
                    //emit leadOffSignal2M3DataControl();
                    emit leadOffSignal2M3DataControl(33);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(52);
                }


                if(statusP&0x40)//7
                {
                    //qDebug()<<"V5 lead off "<<endl;
                    emit leadOffSignal2M3DataControl(32);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(51);
                }


                if(statusP&0x20)//6
                {
                    //qDebug()<<"V4 lead off "<<endl;
                    emit leadOffSignal2M3DataControl(31);

                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(50);
                }


                if(statusP&0x10)//5
                {
                    //qDebug()<<"V3 lead off "<<endl;
                    emit leadOffSignal2M3DataControl(30);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(49);
                }


                if(statusP&0x08)//4
                {
                    //qDebug()<<"V2 lead off "<<endl;
                    emit leadOffSignal2M3DataControl(29);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(48);
                }


                if(statusP&0x04)//3
                {
                    //qDebug()<<"V1 lead off "<<endl;
                    emit leadOffSignal2M3DataControl(28);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(47);
                }


                if(statusP&0x02)//2
                {
                    //qDebug()<<"LL lead off "<<endl;
                    emit leadOffSignal2M3DataControl(27);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(46);
                }



                if(statusN&0x02)//1
                {
                    //qDebug()<<"LA lead off "<<endl;
                    emit leadOffSignal2M3DataControl(26);
                }
                else
                {
                    //leadOffSignal2M3DataControl
                    emit leadOffSignal2M3DataControl(45);
                }


                if(statusN&0x01)//1
                {
                    //qDebug()<<"RA lead off "<<endl;
                    emit leadOffSignal2M3DataControl(25);
                }
                else
                {
                    emit leadOffSignal2M3DataControl(44);
                }
    //            if(statusN&0x04)//第三通道的负输入 //会误报  暂时屏蔽掉该报警20230911
    //            {
    //                emit leadOffSignal2M3DataControl(34); //RL导联脱落
    //                qDebug()<<"RL lead off "<<endl;
    //            }
    //            else {
    //                emit leadOffSignal2M3DataControl(52);//RL未脱落
    //            }
            }
            else //不符合要求的数据
            {

            }

            startFlagCount = endFlagCount+3; //标记下一次的起始位置
            if(startFlagCount>buf.length()) //如果startFlagCount比总的数据长度还大，那么已经接近数据结束
            {
                int ii = endFlagCount;
                for(ii = endFlagCount;ii<buf.length();ii++)
                {
                    leftDataArray.append(buf[ii]);
                }
                break;
            }

        }
        if(i == (buf.length()-1)) //如果是最后一个值判断剩下的一帧数据是不是一整帧的数据
        {
            if(((buf.length()-1)-startFlagCount)>=0)  //将所有剩下的数据全部移动到leftDataArray中交给下一次循环判断
            {
                int ii = startFlagCount - 3;
                for(ii = endFlagCount;ii<buf.length();ii++)
                {
                    leftDataArray.append(buf[ii]);
                }
            }
            else
            {
                break;
            }
        }
    }
}

//void DataAcquisition::AcqDataAnalyse(QByteArray buf) //对采集到的数据进行分析，将心电数据转换成需要的形式，心电数据，血压数据和血氧数据分离开来
//{

//    //计算心率是不是太频繁，如果太频繁浪费时间，可以想办法将心率计算不要太频繁！！！！！！！！！！！！！！！！！
//    //<<"Recive length is "<<buf.length();
//    float tempECGData = 0;//用于临时存储心电数据
//    for(int i = 0;i<buf.length();)
//    {

//        if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(buf[i+3]=='\x01'))    //处理ECG数据 判断帧头
//        {
//            if((buf.length()-i)<52)//判断剩余帧的长度  帧头4字节+12导联*4字节 =52个字节
//            {
//                //
//                //qDebug()<<"<52";
//                int len = (buf.length()-i);
//                //leftDataArray.clear();//byteArray清0
//                for(int leftLenth = 0;leftLenth<len;leftLenth++)
//                {
//                    leftDataArray.append(buf[i+leftLenth]);
//                }
//                i=buf.length();
//                break;
//            }
//            else if((buf.length()-i) == 52) //当剩余长度等于52的时候，可以判断最后的数据正好为一帧的心电数据
//            {
//               // qDebug()<<"=52";
//                //byteArrayLeftLength = 0;//心电数据剩余长度为0
//               // leftDataArray.clear();//byteArray清0
//                i+=4;//进入处理实际数据的阶段

//                for(int j = 0;j<12;j++)
//                {
//                    ecg_real_data_list_before_filter[j] <<((buf[i]<<24|buf[i+1]<<16|buf[i+2]<<8|buf[i+3])*3125000/16777215);

//                    //ecg_real_data_array[j] <<((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
// //                    tempECGData=((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
// //                    if(ecg_real_data_list_before_filter[j].length()>0)
// //                    {
// //                        if(qAbs(ecg_real_data_list_before_filter[j].last() - tempECGData)>ECG_DIFF_THRESHOLD) //如果出现一个突兀的数值
// //                        {
// //                                ECGDataAbrutFlag = true;
// //                        }
// //                        else {
// //                            break;
// //                        }
// //                    }
// //                    ecg_real_data_list_before_filter[j]<<tempECGData;
//                    //ecg_real_data_list_before_filter[j]<<(((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215)+baseLineArray[j]);
//                    if(recordECGFlag == true)
//                    {
//                        if(j!=11)
//                        {
//                            //*orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<'\t';
//                            //*orifilestream<<QString::number(buf[i],16)<<QString::number(buf[i+1],16)<<QString::number(buf[i+2],16)<<QString::number(buf[i+3],16)<<'\t';
//                            *orifilestream<<QString::number(buf[i],16)<<QString(" ")<<QString::number(buf[i+1],16)<<QString(" ")<<QString::number(buf[i+2],16)<<QString(" ")<<QString::number(buf[i+3],16)<<'\t';

//                        }
//                        else{
//                            //*orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<endl;
//                            //*orifilestream<<QString::number(buf[i],16)<<QString::number(buf[i+1],16)<<QString::number(buf[i+2],16)<<QString::number(buf[i+3],16)<<endl;
//                            *orifilestream<<QString::number(buf[i],16)<<QString(" ")<<QString::number(buf[i+1],16)<<QString(" ")<<QString::number(buf[i+2],16)<<QString(" ")<<QString::number(buf[i+3],16)<<endl;


//                        }
//                    }
//                    ecg_real_data_list_before_filter[j].last() = ecg_real_data_list_before_filter[j].last()+baseLineArray[j];
//                    if(j == 11)
//                    {
// //                        if(ECGDataAbrutFlag) //如果数据有突兀值标志位
// //                        {
// //                            ECGDataAbrutProcess(j)
// //                        }
// //                        else
// //                        {
//                            ecgDataFilter(); //滤波算法 滤波并计算心率 然后发送心率值
// //                        }
//                    }

//                    i+=4;
//                }
//            }
//            else if(((buf.length()-i) > 52)) //当剩余的数据长度大于52时
//            {
//                //qDebug()<<">52";
//                if((buf[i+52]=='\xFE')&&(buf[i+53]=='\xFE')&&(buf[i+54]=='\xFE')) //判断是否是一帧完整的心电数据包
//                {
//                    //byteArrayLeftLength = 0;//心电数据剩余长度为0
//                    //leftDataArray.clear(); //byteArray清0
//                    i+=4;//进入处理实际数据的阶段

//                    for(int j = 0;j<12;j++)
//                    {

//                        ecg_real_data_list_before_filter[j] <<((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
//                        //ecg_real_data_list_before_filter[j]<<(((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215)+baseLineArray[j]);
// //                        tempECGData=((buf[i]<<24|(buf[i+1]&0x00FF)<<16|buf[i+2]<<8|buf[i+3])*1250000.0/16777215);
// //                        if(ecg_real_data_list_before_filter[j].length()>0)
// //                        {
// //                            if(qAbs(ecg_real_data_list_before_filter[j].last() - tempECGData)>ECG_DIFF_THRESHOLD) //如果出现一个突兀的数值
// //                            {
// //                                    ECGDataAbrutFlag = true;
// //                            }
// //                            else {
// //                                break;
// //                            }
// //                        }
// //                        ecg_real_data_list_before_filter[j]<<tempECGData;
//                        if(recordECGFlag == true)
//                        {
//                            if(j!=11)
//                            {
//                                //*orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<'\t';
//                                //*orifilestream<<QString("%1").arg(buf[i],0,16,)<<QString("%1").arg(buf[i+1],0,16)<<QString("%1").arg(buf[i+2],0,16)<<QString("%1").arg(buf[i+3],0,16)<<'\t';
//                                //*orifilestream<<QString::number(buf[i],16)<<QString::number(buf[i+1],16)<<QString::number(buf[i+2],16)<<QString::number(buf[i+3],16)<<'\t';
//                                *orifilestream<<QString::number(buf[i],16)<<QString(" ")<<QString::number(buf[i+1],16)<<QString(" ")<<QString::number(buf[i+2],16)<<QString(" ")<<QString::number(buf[i+3],16)<<'\t';

//                            }
//                            else{
//                                //*orifilestream<<QString("%1").arg(ecg_real_data_list_before_filter[j].last())<<endl;
//                                //*orifilestream<<QString::number(buf[i],16)<<QString::number(buf[i+1],16)<<QString::number(buf[i+2],16)<<QString::number(buf[i+3],16)<<endl;
//                                *orifilestream<<QString::number(buf[i],16)<<QString(" ")<<QString::number(buf[i+1],16)<<QString(" ")<<QString::number(buf[i+2],16)<<QString(" ")<<QString::number(buf[i+3],16)<<endl;

//                            }
//                        }
//                        ecg_real_data_list_before_filter[j].last() = ecg_real_data_list_before_filter[j].last()+baseLineArray[j];
//                        //此处添加滤波算法
//                        if(j == 11)
//                        {
//                            ecgDataFilter(); //滤波算法 滤波并计算心率 然后发送心率值
// //                            if(ECGDataAbrutFlag) //如果数据有突兀值标志位
// //                            {
// //                                ECGDataAbrutProcess(j);
// //                            }
// //                            else
// //                            {
// //                                ecgDataFilter(); //滤波算法 滤波并计算心率 然后发送心率值
// //                            }
//                        }

//                        i+=4;
//                    }
//                }
//                else //如果开始是0xFE,0xFE,0xFE,0x01,心电数据长度为52个字节，52字节后不是以0xFE，0xFE,0xFE,开头,这是一帧坏包，如果不对i进行处理，会使程序卡死
//                {

//                    i+=1;
//                }
//            }
//            else
//            {
//                break;
//            }

//        }
//        else if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(buf[i+3]=='\x02'))      //处理血氧数据
//        {
//            i+=4; //进入处理实际数据的阶段
//            //第一位是状态位bit0:1 手指插入标志 1是手指未，0是手指插入
//            //bit1:1 探头脱落标志 1探头脱落，0是探头正常
//            //bit2:1 测量干扰提示 1测量有干扰 0是测量无干扰
//            //bit3:1 脉搏音 bit7~bit4 未定义
//            M3_SPO2_Sta_data<<buf[i];         //存储血氧的状态信息
//            M3_SPO2_PI_data<<buf[i+1];        //存储血氧PI灌注指数 单位0.1%
//            M3_SPO2_data<<buf[i+2];           //存储血氧值
//            M3_SPO2_pulse_rata<<buf[i+3];     //存储血氧脉率值
//            M3_SPO2_pulse_column<<buf[i+4];   //存储血氧脉搏柱
//            M3_SPO2_waves<<buf[i+5];          //存储血氧容积波
//            i+=6;
//            emit SPO2Data2M3DataControl(&M3_SPO2_PI_data,&M3_SPO2_data,&M3_SPO2_pulse_rata,&M3_SPO2_pulse_column,&M3_SPO2_waves,&M3_SPO2_Sta_data);
//        }
//        else if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(buf[i+3]=='\x03'))    //处理血压数据
//        {
//            i+=4; //进入处理实际数据的阶段
//            //quint16 sys;
//            //quint16 dia;
//            M3_BP_sys_data << ((0<<8)|(buf[i+1]&0x00FF));//buf[i+1]&0x00ff是因为当最高位为1是，buf前面多出一个字节，这样转换的值高位就会变为0xFF，例如0x93就会变为0xff93
//            M3_BP_dia_data << (buf[i+2]<<8 | (buf[i+3]&0x00FF));
//            i+=12;
//            emit NIBPData2M3DataControl(&M3_BP_sys_data,&M3_BP_dia_data);
//        }
//        else if((buf[i]=='\xFE')&&(buf[i+1]=='\xFE')&&(buf[i+2]=='\xFE')&&(buf[i+3]=='\x04'))    //处理导联脱落数据
//        {

//            i+=4;
//            quint8 statusP = buf[i];
//            quint8 statusN = buf[i+1];
//            if(statusP&0x80) //8
//            {
//                //qDebug()<<"V6 lead off "<<endl;
//                //emit leadOffSignal2M3DataControl();
//                emit leadOffSignal2M3DataControl(33);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(52);
//            }


//            if(statusP&0x40)//7
//            {
//                //qDebug()<<"V5 lead off "<<endl;
//                emit leadOffSignal2M3DataControl(32);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(51);
//            }


//            if(statusP&0x20)//6
//            {
//                //qDebug()<<"V4 lead off "<<endl;
//                emit leadOffSignal2M3DataControl(31);

//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(50);
//            }


//            if(statusP&0x10)//5
//            {
//                //qDebug()<<"V3 lead off "<<endl;
//                emit leadOffSignal2M3DataControl(30);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(49);
//            }


//            if(statusP&0x08)//4
//            {
//                //qDebug()<<"V2 lead off "<<endl;
//                emit leadOffSignal2M3DataControl(29);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(48);
//            }


//            if(statusP&0x04)//3
//            {
//                //qDebug()<<"V1 lead off "<<endl;
//                emit leadOffSignal2M3DataControl(28);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(47);
//            }


//            if(statusP&0x02)//2
//            {
//                //qDebug()<<"LL lead off "<<endl;
//                emit leadOffSignal2M3DataControl(27);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(46);
//            }



//            if(statusN&0x02)//1
//            {
//                //qDebug()<<"LA lead off "<<endl;
//                emit leadOffSignal2M3DataControl(26);
//            }
//            else
//            {
//                //leadOffSignal2M3DataControl
//                emit leadOffSignal2M3DataControl(45);
//            }


//            if(statusN&0x01)//1
//            {
//                //qDebug()<<"RA lead off "<<endl;
//                emit leadOffSignal2M3DataControl(25);
//            }
//            else
//            {
//                emit leadOffSignal2M3DataControl(44);
//            }
// //            if(statusN&0x04)//第三通道的负输入 //会误报  暂时屏蔽掉该报警20230911
// //            {
// //                emit leadOffSignal2M3DataControl(34); //RL导联脱落
// //                qDebug()<<"RL lead off "<<endl;
// //            }
// //            else {
// //                emit leadOffSignal2M3DataControl(52);//RL未脱落
// //            }
//            i+=2;
//        }
//        else
//        {
//            i++;
//        }
//    }
//    //测试用，测试每10ms，收到的心电数据是多少帧 结果10ms的时候收到的数据大概是50~80之间，说明数据处理花了比较多的时间
//    //由于心率算法的要求传入的数组是指针的形式（20230706）故想办法将QList<float>转换为float数组，而且要求传入数组的长度必须是10000，10s的心电数据
//    //QList是连续的内存块，可以实现数据的强转，但是要注意指针是否转的正确
//    //    if(ecg_real_data_array[I].length()==10000)
//    //    {
//    //        emit HeartRate2M3DataControl(ecgDataProc->M3_HeartRateCAL((float*)(&(ecg_real_data_array[I][0]))));
//    //    }
//    //    else{

//    //        emit HeartRate2M3DataControl(1); //心率未算出来之前，心率框显示的值是1
//    //    }
//}





void DataAcquisition::getECGdata(int i,QByteArray *buf) //处理得到心电数据
{
    i+=4;//进入处理实际数据的阶段

    for(int j = 0;j<12;j++)
    {
        //ecg_real_data_array[j] <<((buf[i]<<24|buf[i+1]<<16|buf[i+2]<<8|buf[i+3])*3125000/16777215);

        ecg_real_data_array[j] <<((*(buf[i])<<24|(*(buf[i+1])&0x00FF)<<16|*(buf[i+2])<<8|*(buf[i+3]))*3125000.0/16777215);

        if(ecg_real_data_array[j].length()==10001)
        {
            ecg_real_data_array[j].takeFirst(); //如果list的长度等于10001时，执行takeFirst数据长度还是10000。然后将数据传递给心率计算函数
            /*
        //打印原始实际数据用到的
        if(j!=11)
        {
            *filestream<< QString("%1").arg(ecg_real_data_array[j].takeFirst())<<endl;

        }
        else{
           // *filestream<< QString("%1").arg(ecg_real_data_array[j].takeFirst())<<endl;
        }
*/
        }

        i+=4;
    }
}



void DataAcquisition::dataAcq()//槽函数,读取串口的数据
{
    QByteArray buf = acqusitionPort->readAll();
    QByteArray bufAll;
    //dataSocket->write(buf);//将读取到的数据，全部通过网线传递给电脑
    //AcqDataAnalyse(buf);
    //qDebug()<<"read data";
//    if(buf.length()>0)
//    {
//        qDebug()<<"revive length is "<<buf.length();
//        qDebug()<<buf.toHex()<<endl;
//    }
    if(netConnectedFlag)  //使用有线和wifi传输数据
    {
        dataSocket->write(buf);//将读取到的数据，全部通过网线传递给电脑
    }

    if(btTransDataFlag)   //使用蓝牙传输数据
    {
        emit BtTransData(buf);
    }


    if(leftDataArray.length() == 0)
    {
        AcqDataAnalyse(buf);
    }
    else
    {
        int leftLen = leftDataArray.length();
        for(int i =0;i<leftLen;i++)
        {
            bufAll.append(leftDataArray[i]);
        }
        leftDataArray.clear();
        for(int z = 0;z<buf.length();z++)
        {
            bufAll.append(buf[z]);
        }
        AcqDataAnalyse(bufAll);
    }

}

void DataAcquisition::onRecNIBPStartSignal()
{
    QByteArray data = "BPstart\r\n";
    acqusitionPort->write(data); //血压开始测量

}

void DataAcquisition::onRecNIBPStopSignal()
{
    QByteArray data = "BPstop\r\n";
    acqusitionPort->write(data); //血压停止测量
    //qDebug()<<"BPStop Transmitted";
}

//void DataAcquisition::onECG3or12Changed(bool value) //12导联的显示模式 2*6还是3*4 value = ture 3*4
//{

////    this->threeLeadOr12Leadshow = value; //true 3*4显示 false 2*6显示
////    qDebug()<<"threeLeadOr12Leadshow = "<<this->threeLeadOr12Leadshow<<endl;
//}

void DataAcquisition::onRecordECGFlagChangeSignal(bool value)
{
    //
    QString cmd;
    recordECGFlag = value;
    if(value == true) //开始记录心电数据
    {
        //打开一个以当前时间命名的文件，将心电数据存入该文件中
        QString filePath = "/media/usb0/data";
        bool ret;
        QString timestring = QDateTime::currentDateTime().toString("yy-MM-dd hh-mm-ss");
        QString oridataString;
        //oridataString = "/test/data/ori"+timestring;//存储在核心板上
        //timestring = "/test/data/"+timestring;//存储在核心板上
        oridataString = filePath+"/ori"+timestring;//存储在核心板上
        timestring =  filePath+"/"+timestring;//存储在核心板上

        //timestring = filePath+"/ECG"+timestring; //存储在U盘上
//        QDir dir(filePath);

//        if( !dir.exists() )
//        {
//            if( dir.mkpath(filePath) )
//            {
//                qDebug()<<"create dir:"<<filePath;
//            }
//        }
//        else{
//             qDebug()<<filePath<<"exist;";
//        }

        oriecgfile = new QFile(oridataString);
        ret = oriecgfile->open(QIODevice::ReadWrite|QIODevice::Text);
        if(ret == true)
        {
            qDebug()<<"ori open file sucess";
        }
        else {
            qDebug()<<"ori open file failed";
        }


        ecgfile = new QFile(timestring);

        ret = ecgfile->open(QIODevice::ReadWrite|QIODevice::Text);
        if(ret == true)
        {
            qDebug()<<"open file sucess";
        }
        else {
            qDebug()<<"open file failed";
        }
        filestream->setDevice(ecgfile);

        //存储原始数据

        orifilestream ->setDevice(oriecgfile);
    }
    else             //结束记录心电数据
    {
        //关掉打开的文件
        filestream->flush();
        ecgfile->close();

        orifilestream->flush();
        oriecgfile->close();

        cmd = "sync";
        system(cmd.toLatin1().data());
    }
}

void DataAcquisition::onRecPatientTypeChanged(quint8 patientType)
{
    PatientType = patientType;
    if(patientType == 0) //当病人类型为成人时
    {

        //切换血压的成人模式
        QByteArray data = "BPAdult\r\n";
        acqusitionPort->write(data); //血压切换为成人模式

    }
    else if(patientType == 1) //当病人类型为儿童时
    {
        //切换血压的儿童模式
        QByteArray data = "BPChild\r\n";
        acqusitionPort->write(data); //血压切换为儿童模式
    }
}

void DataAcquisition::onRcvECGDataProcessedSignal()
{

        for(int i = 0;i<12;i++)
        {
            if(ecg_processed_data_trans_array[i].length()>0)
            {
                ecg_processed_data_trans_array[i].clear();
            }
        }
        ECGDataRevProcessedFlag = true; //将标志位置为真，此时就可以继续传数据了
        //qDebug()<<"ECGDataRevProcessedFlag1111 = "<<ECGDataRevProcessedFlag;
        //qDebug()<<"flag = true"<<endl;
}

void DataAcquisition::onRecLeadsShowTypeChangedSignal(quint8 value)
{
    leadsShowType = value;
}


// 电池变化范围的新方案
void DataAcquisition::readBatVal()//电池的电压变化范围时144mv~1419mv 差值为1275  //20240220最新算法 百分百电压设置为1419-20 = 1219mv 所以电池的电压变化范围是144mv ~ 1219mv
{
    int batVall[2];
    quint32 batAverage = 0;//电池电量的平均值
    bat->readBatteryValue();
    batVall[0] = bat->batVal[0]; //充电电压值
    batVall[1] = bat->batVal[1]; //充电状态位
    if (batVall[0]<0)
    {
        qDebug()<<"read BatVal failed"<<endl;
    }
    else
    {
        //qDebug()<<"the BatVal is"<<batVall[0]<<endl;
        if(batVall[1] == 1)//如果当前的状态为充电状态
        {
//            if(batVall[0] <= 1740)
//            {
//                batVall[0] = batVall[0] - 40; //充电状态需要人为的减去0.04V 对应的AD读值是17.05
//            }
//            else{
//                batVall[0] = batVall[0];
//            }
            if(batVall[0] < 256)
            {
                batVall[0]=256;
            }
            batVall[0] = batVall[0] - 255;  //243=12.75*20
            //batVall[0] = batVall[0] - 215;  //243=10.75*20
        }
        batValList.append(batVall[0]);
        if(batValList.length()<BAT_ARRAY_LEN)
        {
//            for(quint8 i = 0;i<batValList.length();i++)
//            {
//                batAverage +=batValList[i];
//            }
//            batAverage = batAverage/batValList.length();
//            batAverage = (batVall[0]-144)/12.75;
            batAverage = 999;

        }
        else if(batValList.length() == BAT_ARRAY_LEN)//当长度为BAT_ARRAY_LEN 时，开始计算平均值
        {
            for(quint8 i = 0;i<BAT_ARRAY_LEN;i++)
            {
                batAverage +=batValList[i];
            }
            batAverage = batAverage/BAT_ARRAY_LEN;
            //qDebug()<<"the BatAverage is"<<batAverage<<endl;
            if(batAverage<145)
            {
                batAverage = 145;
            }
            batAverage = (batAverage-144)/10.56;
            batValList.takeFirst();
            if(batAveragePre == 0) //如果计算的值为第一次
            {
                batAveragePre = batAverage;
            }
            if(batVall[1] == 1) //如果当前状态为充电状态
            {
                if(batAveragePre > batAverage) //如果前一次的测量值大于当前值
                {
                     batAverage = batAveragePre;
                }
                else {
                    batAveragePre = batAverage;
                }

            }
            else if(batVall[1] == 0) //如果当前状态为放电状态
            {

                if(batAverage >batAveragePre) //如果当前值大于前一次的值
                {
                    batAverage = batAveragePre;
                }
                else {
                     batAveragePre = batAverage;
                }
            }
        }

        if((batAverage>=100)&&(batAverage!=999)) //999是个特殊值，表示电池电压测量还不稳定
        {
            batAverage = 100;
        }
        else if(batAverage<=0)
        {
            batAverage = 1;
        }
        else{
            batAverage = batAverage;
        }
        emit batValSignal(batAverage,batVall[1]);
    }
}




// //电池变化范围的老方案
//void DataAcquisition::readBatVal()//电池的电压变化范围时1520mv~1800mv
//{
//    int batVall[2];
//    quint32 batAverage = 0;//电池电量的平均值
//    bat->readBatteryValue();
//    batVall[0] = bat->batVal[0]; //充电电压值
//    batVall[1] = bat->batVal[1]; //充电状态位
//    if (batVall[0]<0)
//    {
//        qDebug()<<"read BatVal failed"<<endl;
//    }
//    else
//    {
//        //qDebug()<<"the BatVal is"<<batVall[0]<<endl;
//        if(batVall[1] == 1)//如果当前的状态为充电状态
//        {
//            if(batVall[0] <= 1740)
//            {
//                batVall[0] = batVall[0] - 40; //充电状态需要人为的减去0.04V 对应的AD读值是17.05
//            }
//            else{
//                batVall[0] = batVall[0];
//            }
//        }
//        batValList.append(batVall[0]);
//        if(batValList.length()<BAT_ARRAY_LEN)
//        {
//            for(quint8 i = 0;i<batValList.length();i++)
//            {
//                batAverage +=batValList[i];
//            }
//            batAverage = batAverage/batValList.length();
//            batAverage = (batVall[0]-1520)*10/27;

//        }
//        else if(batValList.length() == BAT_ARRAY_LEN)//当长度为10时，开始计算平均值
//        {
//            for(quint8 i = 0;i<BAT_ARRAY_LEN;i++)
//            {
//                batAverage +=batValList[i];
//            }
//            batAverage = batAverage/BAT_ARRAY_LEN;
//            batAverage = (batAverage-1520)*10/27;
//            batValList.takeFirst();
//        }

//        if(batAverage>=100)
//        {
//            batAverage = 100;
//        }
//        else if(batAverage<=0)
//        {
//            batAverage = 1;
//        }
//        else{
//            batAverage = batAverage;
//        }
//        emit batValSignal(batAverage,batVall[1]);
//    }
//}






