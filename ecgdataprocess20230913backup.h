#ifndef ECGDATAPROCESS_H
#define ECGDATAPROCESS_H

#include <QObject>
#include <QByteArray>
#include <QList>
#include <QtMath>
//ecg_R_dist_test文件中相关的内容
// 寻找心电峰值的个数
#define CARDINAL_PEAK_MAX  50  //[原为45]【2020.7.16修改】
//  最大的参数个数
//#define MAX_PARA_COUNT_3SEC 45
#define SAMPLE_RATE  1000 //Hz
#define CALC_BASIC_COUNT 10000


class ECGDataProcess : public QObject
{
    Q_OBJECT
public:
    explicit ECGDataProcess(QObject *parent = nullptr);


    /*//////////////////////////////////////////////////////////////////////////////////////////*/
    //ecg_R_dist_test 计算R波


    typedef struct _ecgpre{
        ///峰值的位置
        unsigned short int PeakPos;
        /// 高宽比
        float EcgRate;
    }EcgPre;
    ///极值
    typedef struct _extrevalue{
        /// 最大值
        unsigned short int UMax;
        /// 最小值
        unsigned short int UMin;
    }ExtreValue;

    const unsigned short int MIN_HEARTBEAT_3SEC = 1;

    const unsigned short int MAX_HEARTBEAT_3SEC = 50;   //[原为45]【2020.7.16修改】



    /*static*/ EcgPre ecgarray[5000];  // 心电周期 对应结构体   2023.2.24 看看需不需要修改

    /*static*/ unsigned short int ecgPeakList[CARDINAL_PEAK_MAX];

    /////////////////////////////////////////////////  可以不用这个，之后调用之前定义即可
    /*static*/ unsigned short int EcgQualtifyPeakPosList[CARDINAL_PEAK_MAX];  // 有这个的时候 ，可以直接引用，不用再求
    ///////////////////////////////////////////////////////////
    /// 预备参数的个数 高宽比，默认最大得前2个为标准值

    const static unsigned short int PPRE_PARA_CNT  = 2;   // 2020.7.20修改 【之前为1】


    /*static*/unsigned short int DiffPeakList[CARDINAL_PEAK_MAX];

    /*static*/unsigned short int DiffTmp[CARDINAL_PEAK_MAX];


    ExtreValue GetMaxMinValueU16(unsigned short int* FBuffer,unsigned short int DataSize);

    unsigned short int GetMinU16(unsigned short int* DataArray,unsigned short int dasize);

    unsigned short int GetMaxU16(unsigned short int* DataArray,unsigned short int dasize) ;

    unsigned long int GetSumU16(unsigned short int* DataArray,unsigned short int dasize);

    unsigned short int GetAvgU16(unsigned short int* DataArray,unsigned short int dasize);

    unsigned short int GetMaxPos32(unsigned short int* DataArray,unsigned short int dasize);

    unsigned short int GetMinPos32(unsigned short int* DataArray,unsigned short int dasize);

    void SelectSortAsc(unsigned short int* PeakPosList,unsigned short int PeakCnt);

    unsigned short int GetCardinalCylce(float* fcardinal,EcgPre* ecgarray);

    void DataSortDesc(EcgPre* ecgpre,unsigned short int ecgcnt);

    unsigned short int SimpleFilterPeak(EcgPre* ecgarray,unsigned short int ecgarraycount,unsigned short int* ecgPeakList);

    void GetDiff(unsigned short int* DataArray,unsigned short int dasize,unsigned short int* difflist);

    unsigned short int FilterPeakList(unsigned short int* ecgPeakList,unsigned short int PeakCnt,unsigned short int* EcgQualtifyPeakPosList);

    unsigned short int GetAPeakList(float* fcardinal,unsigned short int* EcgQualtifyPeakPosList);



 /*//////////////////////////////////////////////////////////////////////////////////////////*/
    //心电算法
    unsigned short int M3_HeartRateCAL(float* fcardinal);  //心率的计算函数
 /*//////////////////////////////////////////////////////////////////////////////////////////*/
    //滤波算法

    //*****************************************************************************************//
    // [HP系数——baseline——remove]


    //[0.67HZ]
    const float HP_B4[1*2] ={0.997899550986083,	-0.997899550986083};
    const float HP_A4[1*2] ={1,	-0.995799101972166};


    // [0.3HZ]
    const float HP_B3[1*2] ={ 0.999058409353407,	-0.999058409353407};
    const float HP_A3[1*2] ={1,	-0.998116818706813};

    // [0.15HZ]
    const float HP_B2[1*2] ={ 0.999528983028615,	-0.999528983028615};
    const float HP_A2[1*2] ={1,	-0.9990579660572293};

    // [0.05HZ]
    const float HP_B1[1*2] ={0.999842945036165	,-0.999842945036165};
    const float HP_A1[1*2] ={1,	-0.999685890072330};


    // [LP系数——EMG_INTERFERENCE——remove]
    // [25hz]
    const float EMG_LP_B1_25[1*5] ={ 3.37021427078699e-5,	0.000134808570831479,	0.000202212856247219,	0.000134808570831479	,3.37021427078699e-5};
    const float EMG_LP_A1_25[1*5] ={1,	-3.58148511622656,	4.82981988052487,	-2.90533122156861,	0.657535691553627};

    // [40hz]
    const float EMG_LP_B2_40[1*5] ={ 0.000198954964308856,	0.000795819857235425,	0.00119372978585314,	0.000795819857235425,	0.000198954964308856};
    const float EMG_LP_A2_40[1*5]  ={1,	-3.32936382540801,	4.20392729255682, 	-2.38120484264011,	0.509824654920240};

    // [150hz]
    const float EMG_LP_B3_150[1*5]={ 0.0225944933337710,	 0.0903779733350839,	0.135566960002626,	0.0903779733350839,	0.0225944933337710};
    const float EMG_LP_A3_150[1*5] ={1,	-1.42149329277518,	1.13146308127693, 	-0.412386486080503, 	0.0639285909190893};

    // [SP系数——POWERLINE_INTERFERENCE——remove]
    //  50HZ
    const float SP_B_50[1*3] ={0.999206698062585,	-1.90060539473331,	0.999206698062585};
    const float SP_A_50[1*3] ={1,	-1.90060539473330,	0.998413396125167};
    //  60HZ
    const float SP_B_60[1*3] ={0.999207039206297,	-1.85807970197826,	0.999207039206297};
    const float SP_A_60[1*3] ={1,	-1.85807970197826,	0.998414078412593};


    float f_data_in_lp[12*12]={0.0};//滤波算法用到的一个数组
    float f_data_in_hp[12*12]={0.0};//滤波算法用到的一个数组

    //*****************************************************************************************//

    void filter(float*fcardinal, unsigned short int len,float *fcardinal_filter, const float *filter_B, const float *filter_A, unsigned short int order_filter);

    void filter_pro(float *fcardinal, unsigned short int len,float *fcardinal_filter, const float *filter_B, const float *filter_A, unsigned short int order_filter,float *f_data,unsigned short int sign);

    void bandstop_filter(float  *fcardinal,unsigned short int len, float *fcardinal_filter, const float *filter_B, const float *filter_A);

    void HPforbaseline_remove(float *fcardinal, unsigned short int len,  unsigned short int BL_type,float *fcardinal_filter,float *f_data,unsigned short int sign);

    void  HPforbaseline_remove_12L(float *fcardinal_12L,unsigned short int fcardinal_length,  unsigned short int BL_type,float*fcardinal_filter_12L,float *f_12Ldata,unsigned short int sign);

    void EMG_interference_remove(float *fcardinal,unsigned short int len, unsigned short int EMG_type,float*fcardinal_filter,float *f_data,unsigned short int sign);

    void EMG_interference_remove_12L(float *fcardinal_12L,unsigned short int fcardinal_length, unsigned short int EMG_type,float*fcardinal_filter_12L,float *f_12Ldata,unsigned short int sign);

    void Power_line_interference_remove(float  *fcardinal,unsigned short int len,unsigned short int AC_type, float *fcardinal_filter);

    void Power_line_interference_remove_12L(float *fcardinal_12L,unsigned short int fcardinal_length, unsigned short int AC_type,float*fcardinal_filter_12L);


signals:

public slots:


};

#endif // ECGDATAPROCESS_H
