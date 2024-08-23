#include "ecgdataprocess.h"
#include "QDebug"
ECGDataProcess::ECGDataProcess(QObject *parent) : QObject(parent)
{

}


///
/// 函数功能：
///     获取数据的最大、最小值
///
/// 输入参数：
///     Fbuffer  : 查询的数组
///     DataSize : 数组的尺寸
///
/// 输出参数：
///     输出最大、最小值
///
ECGDataProcess::ExtreValue ECGDataProcess::GetMaxMinValueU16(unsigned short *FBuffer, unsigned short DataSize)
{
    unsigned short int UMax = FBuffer[0],UMin = FBuffer[0];
    unsigned short int index = 0;
    ExtreValue ev;
    for (index = 1; index < DataSize; index++){
        if (FBuffer[index] > UMax){
            UMax = FBuffer[index];
        }
        else{
            if (FBuffer[index] < UMin){
                UMin = FBuffer[index];
            }
        }
    }
    ev.UMax = UMax;
    ev.UMin = UMin;
    return ev;
}

///
/// 函数功能：
///     求数组最下值
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
///  输出：
///      数组的最小值
///

unsigned short ECGDataProcess::GetMinU16(unsigned short *DataArray, unsigned short dasize)
{
    unsigned short int Minvalue = DataArray[0];
    unsigned short int index = 1;
    for(index = 1;index < dasize;index++){
        if(Minvalue > DataArray[index]){
            Minvalue = DataArray[index];
        }
    }
    return Minvalue;
}
///
/// 函数功能：
///     求数组最大值
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
///  输出：
///      数组的最大值
///
unsigned short ECGDataProcess::GetMaxU16(unsigned short *DataArray, unsigned short dasize)
{
    unsigned short int Maxvalue = DataArray[0];
    unsigned short int index = 1;
    for(index = 1;index < dasize;index++) {
        if(Maxvalue < DataArray[index]){
            Maxvalue = DataArray[index];
        }
    }
    return Maxvalue;
}

///
/// 函数功能：
///     求数组的和
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
/// 输出：
///     和
///

unsigned long ECGDataProcess::GetSumU16(unsigned short *DataArray, unsigned short dasize)
{
    unsigned long int Sum = 0;
    unsigned short int index = 0;
    for(index = 0;index < dasize;index++){
        Sum += DataArray[index];
    }
    return Sum;
}
///
/// 函数功能：
///     求数组的平均值
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
/// 输出：
///     平均值
///
unsigned short ECGDataProcess::GetAvgU16(unsigned short *DataArray, unsigned short dasize)
{
    return (unsigned short int)( GetSumU16(DataArray,dasize) / dasize);
}
///
/// 函数功能：
///     求最大值的位置
///
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
/// 输出：
///    峰值的位置
///
unsigned short ECGDataProcess::GetMaxPos32(unsigned short *DataArray, unsigned short dasize)
{
    int  MaxValue = DataArray[0];
    unsigned short int PeakPos = 0;
    unsigned short int index = 1;
    for (index = 1; index < dasize;index++ ){
        if(MaxValue  < DataArray[index]){
            PeakPos = index;
            MaxValue = DataArray[index];
        }
    }
    return PeakPos;
}

///
/// 函数功能：
///     求最小值的位置
///
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
/// 输出：
///    最小值的位置
///

unsigned short ECGDataProcess::GetMinPos32(unsigned short *DataArray, unsigned short dasize)
{
    int  MinValue = DataArray[0];
        unsigned short int VolayPos = 0;
        unsigned short int index = 1;
        for (index = 1; index < dasize;index++ ){
            if(MinValue  > DataArray[index]){
                VolayPos = index;
                MinValue = DataArray[index];
            }
        }
        return VolayPos;
}


///
/// 函数功能：
///     数据排序，选择排序 升序
/// 输入：
///     所有的心电谷峰谷
///     数量
///

void ECGDataProcess::SelectSortAsc(unsigned short *PeakPosList, unsigned short PeakCnt)
{
    unsigned short int outindex =0, innerindex = 0,minindex = 0,value = 0;
    for(outindex = 0;outindex < PeakCnt - 1;outindex++){
        minindex = outindex;
        for(innerindex = outindex + 1;innerindex< PeakCnt;innerindex ++){
            if(PeakPosList[innerindex] < PeakPosList[minindex]){
                minindex = innerindex;
            }
        }
        if(minindex != outindex){
            value = PeakPosList[outindex];
            PeakPosList[outindex] = PeakPosList[minindex];
            PeakPosList[minindex] = value;
        }
    }
}
///3.1.1
/// 函数功能：
///     挑选心电数据的周期数据(所有的谷峰谷)
/// 输入参数：
///      fcardinal      : 3s的心电数据
///      ecgarray       : 本次所有的谷峰谷的信息
/// 输出参数：
///      所有的符合条件的记录
unsigned short ECGDataProcess::GetCardinalCylce(float *fcardinal, ECGDataProcess::EcgPre *ecgarray)
{
    float ecgratio = 0.0;	                        // 高宽比
        short int firstecgvol = 0;                       // 波形里面第一个谷值找到  // 谷值有负值
        short int PreVolayPos = 0;
        float PreVolayValue = 0.0;    // 前面一个谷值的位置， 谷值 // 谷值有负值
        short int PeakPos = 0 ;
        float PeakValue = 0.0;           // 前面一个峰值的位置，峰值  // 峰值可能也有负值
        unsigned short int index = 0;
        unsigned short int ecgarraycount = 0;
        unsigned short int findpeak = 0;  /// 1 --  寻找波峰，0-- 找到波峰
        for(index = 1;index < CALC_BASIC_COUNT - 1;index++){
            if(firstecgvol != 0){
                if((fcardinal[index] >=fcardinal[index + 1]) && (fcardinal[index] >= fcardinal[index -1]) && findpeak){
                    ///定位峰值以及位置
                    PeakPos = index;
                    PeakValue = fcardinal[index];
                    findpeak = 0;
                    //printf(" **\n ");


                }
                else{ ///定位后面谷值以及位置   【这块与12导联的不太一样，看看后期需不需要修改2023.2.27记录  if (ecgarraycount<1000)   //2020.10.30修改  加了一个】
                    if(fcardinal[index] <= fcardinal[index + 1] && fcardinal[index] <=fcardinal[index - 1] && (!findpeak)){
                        /// index(ecgratio > 50) &&
                        //排除部分高宽比计算问题
                        if(((PeakPos - PreVolayPos)*1.0f/(index - PeakPos)) <= 20 && ((index - PeakPos)*1.0f/(PeakPos - PreVolayPos)) <= 20 && (index - PeakPos) >=2 && (PeakPos - PreVolayPos) >=2 && (index - PreVolayPos) <= 200){
                            ecgratio = (pow((float)(PeakValue - (PreVolayValue + fcardinal[index])/2),2.0f) / (float)(index - PreVolayPos));
                            if((index -  PreVolayPos >= 10))    // 【原来， index -  PreVolayPos >=2  】 2023.2.28修改
                            {
                                ecgarray[ecgarraycount].EcgRate = ecgratio;
                                ecgarray[ecgarraycount].PeakPos = PeakPos;
                                ecgarraycount++;
                                //printf(" **\n ");
                                //printf("	PreVolayPos =%d", 	PreVolayPos );
                                //printf("	PeakPos =%d", 	PeakPos );
                                //printf("	index =%d", 	index );
                                   // printf("ecgratio111=%d", ((PeakPos - PreVolayPos)*1.0f/(index - PeakPos)) >20  );
                                    //printf(" ecgratio=%f", ecgratio);
                                    //printf(" ecgarraycount=%d ", PeakPos);
                                    //printf(" \n ");
                            }
                            /// 定位下一个峰值，预备前面的谷值、位置。
                            PreVolayPos = index;
                            PreVolayValue = fcardinal[index];
                            findpeak = 1;
                            //printf(" **\n ");
                        }
                        else{
                            PreVolayPos = index;
                            PreVolayValue = fcardinal[index];
                            findpeak = 1;
                        }
                    }
                }
            }
            else{   ///定位起始点,谷值
                if((fcardinal[index] <= fcardinal[index - 1])&&(fcardinal[index] <= fcardinal[index + 1])){
                    PreVolayPos = index;
                    PreVolayValue = fcardinal[index];
                    firstecgvol = 1;
                    findpeak = 1;
                    //printf(" **\n ");
                }
            } /// end if
        } /// end for
        return ecgarraycount;
        //printf(" **\n ");
}



/// /// 3.1.2.1
/// 函数功能：
///     数据排序，选择排序
/// 输入：
///     ecgpre     : 所有的心电谷峰谷
///     ecgcnt     : 记录
void ECGDataProcess::DataSortDesc(ECGDataProcess::EcgPre *ecgpre, unsigned short ecgcnt)
{

    EcgPre ecgk;
        unsigned short int outindex =0, innerindex = 0,maxindex = 0;
        for(outindex = 0;outindex < ecgcnt - 1;outindex++){
            maxindex = outindex;
            for(innerindex = outindex + 1;innerindex< ecgcnt;innerindex++){
                if(ecgpre[innerindex].EcgRate > ecgpre[maxindex].EcgRate){
                    maxindex = innerindex;
                }
            }
            if(maxindex != outindex){
                ecgk.EcgRate = ecgpre[outindex].EcgRate;
                ecgk.PeakPos = ecgpre[outindex].PeakPos;

                ecgpre[outindex].EcgRate = ecgpre[maxindex].EcgRate;
                ecgpre[outindex].PeakPos = ecgpre[maxindex].PeakPos;

                ecgpre[maxindex].EcgRate = ecgk.EcgRate;
                ecgpre[maxindex].PeakPos = ecgk.PeakPos;
            }
        }
}

/// 3.1.2
///  函数功能
///      粗略过滤峰值
///  输入：
///      ecgarray       ： 初步过滤峰值
///      ecgarraycount  ： 所有峰值的记录
///      ecgPeakList    ： 符合条件的数据列表
///  输出：
///      符合条件的记录
///
///
unsigned short ECGDataProcess::SimpleFilterPeak(ECGDataProcess::EcgPre *ecgarray, unsigned short ecgarraycount, unsigned short *ecgPeakList)
{
    unsigned short int index = 0,j = 0, PeakCnt = 0,ecgsortcnt = 0,max_mag_cnt = 0,mag_count = 0;
        unsigned int minvalue = 0xFFFFFFFF;
        unsigned int tmpvalue = 0;
        unsigned int order_of_magnitude[50];//高宽比的数量级->个数
        if(ecgarraycount < PPRE_PARA_CNT){
            for(index = 0;index < ecgarraycount;index++ )
                ecgPeakList[PeakCnt++] = ecgarray[index].PeakPos;
        }
        else{// 3~N
            // matlab
            //a=sort(r_list0(:,2),'descend');%对改进高宽比从大到小排序
            DataSortDesc(ecgarray,ecgarraycount);
            // 截取数据
            ecgsortcnt = ecgarraycount < 50? ecgarraycount : 50; //求数量级
            for(index = 0;index < ecgsortcnt;index++){
                order_of_magnitude[index] = (unsigned int)(log10((ecgarray[index].EcgRate)*1.0));
                //printf("ecgrr=%f",(ecgarray[index].EcgRate));
            //	printf("ecg=%d",order_of_magnitude[index]);
                //	printf(" \n ");
            }
            //找到高宽比数量级最大的前两个->个数mag_count
            for(index = 0;index < ecgsortcnt;index++)
            {
                if(order_of_magnitude[0] == order_of_magnitude[index])
                    max_mag_cnt++;
            }
            mag_count = max_mag_cnt;

            // for(index = mag_count;index < ecgsortcnt;index++)
            // {
                // if(order_of_magnitude[max_mag_cnt] == order_of_magnitude[index])
                    // mag_count++;
            // }
            ////////////////////////////*******************2023.4.19修改***************///////////////////////////////////////////////////
            if (max_mag_cnt <5)
            {
                for(index = mag_count;index < ecgsortcnt;index++)
                {
                    if(order_of_magnitude[max_mag_cnt] == order_of_magnitude[index])   //前两个级别的
                        mag_count++;
                }
            }
            else if (max_mag_cnt>=5 && max_mag_cnt <=15)
            {
                if(order_of_magnitude[0]-1 == order_of_magnitude[max_mag_cnt])   // order_of_magnitude[max_mag_cnt]<= order_of_magnitude[0]-1
                {
                    for(index = mag_count;index < ecgsortcnt;index++)
                    {
                        if(order_of_magnitude[0]-1 == order_of_magnitude[index])
                            mag_count++;
                    }
                }
                else
                {
                    mag_count = max_mag_cnt;
                }
            }
            else
            {
                if(order_of_magnitude[0]-1 == order_of_magnitude[max_mag_cnt])   // order_of_magnitude[max_mag_cnt]<= order_of_magnitude[0]-1
                {
                    for(index = mag_count;index < ecgsortcnt;index++)
                    {
                        if(order_of_magnitude[0]-1 == order_of_magnitude[index])
                            mag_count++;
                    }
                }
                else
                {
                    mag_count = max_mag_cnt;
                }
            }

            ////////////////////////////*******************2023.4.19修改***************///////////////////////////////////////////////////
            ///////////////////////////***********************************************///// 2020.1.26修改
            //if (max_mag_cnt <=15 )  //  最高的没有几个，可以越级取
            //{
            //	for(index = mag_count;index < ecgsortcnt;index++)
            //	{
            //		if(order_of_magnitude[max_mag_cnt] == order_of_magnitude[index])
            //			mag_count++;
            //	}
            //}
            //else //
            //{
            //	for(index = mag_count;index < ecgsortcnt;index++)
            //	{
            //		if(order_of_magnitude[0]-1 == order_of_magnitude[index])
            //			mag_count++;
            //	}
            //}
            //printf("rate=%f",(ecgarray[index].EcgRate));
            //printf("pos=%d",ecgarray[index].PeakPos);
            //printf(" \n ");
            ///////////////////////////***********************************************/////
            //printf("mag_count=%d",mag_count);
            // 取出高宽比最大的前两个 对应的位置index
            // r_list=r_list0(r_list0(:,2)>=a(2));
            for(index = 0;index < PPRE_PARA_CNT;index++){
                ecgPeakList[PeakCnt++] = ecgarray[index].PeakPos; //ecgsort[index].PeakPos;
                //printf("rate=%f",(ecgarray[index].EcgRate));
                //printf("pos2=%d",ecgarray[index].PeakPos);
                //printf(" \n ");
            }
            // 开始循环
            for(index = PPRE_PARA_CNT;index < mag_count;index++){
                minvalue = 0xFFFFFFFF;
                for(j = 0;j < PeakCnt;j++){
                    tmpvalue = (unsigned int)(fabs((ecgarray[index].PeakPos - ecgPeakList[j])*1.0f));
                    if( tmpvalue < minvalue){ minvalue = tmpvalue; }

                }
                //{ // min(abs(r_list-v_temp(j)))/200>=1/5
                ///  2017-07-03   2019. 12.25 【0.025f根据 min(abs(r_list-v_temp(j)))/200>=1/5计算】【1/5的选取与采样率和心率有关，决定了RR最小间隔】
                if(((minvalue * 0.00556f) >=1))         //  && (ecgarray[PeakCnt - 1].EcgRate / ecgarray[index].EcgRate < 2)  2020.10.28修改
                {
                    ecgPeakList[PeakCnt++] = ecgarray[index].PeakPos;
                    //printf("rate=%f",(ecgarray[index].EcgRate));
                //	printf("pos2=%d",ecgarray[index].PeakPos);
                    //printf*/(" \n ");
                }
            }// 结束循环
        }
        return PeakCnt;
}
/// 3.1.3.1
/// 函数功能：
///     求数组前后的差值
/// 输入参数：
///     DataArray    :  查询数据的数组
///     dasize       :  数组的尺寸
void ECGDataProcess::GetDiff(unsigned short *DataArray, unsigned short dasize, unsigned short *difflist)
{
    unsigned short int index = 0;
    for(index = 0;index < dasize - 1;index++){
        difflist[index] = DataArray[index + 1] - DataArray[index];
    }
}
/// 3.1.3
/// 函数功能：
///     合并参数，推导周期,精确推导
/// 输入参数
///     ecgPeakList            ：初步过滤的峰值位置
///     PeakCnt                ：峰值的数量
///     EcgQualtifyPeakPosList ：
///
/// 输出
///     合理的分支的数量
unsigned short ECGDataProcess::FilterPeakList(unsigned short *ecgPeakList, unsigned short PeakCnt, unsigned short *EcgQualtifyPeakPosList)
{
    /// 临时变量
        int16_t index = 0,tmpsumdiff = 0,tmpindex = 0,searchi = 0; //
        /// 标准的值，标准值的索引
        unsigned short int standarddiff = 0,standardindex = 0;
        unsigned short int Diffcount = PeakCnt - 1;
        //r_list=sort(r_list); 峰值正排序
        // 有效值的数量
        unsigned short int ecgpeakcnt = 0;
        SelectSortAsc(ecgPeakList,PeakCnt);
        //gap_list=diff(r_list);
        GetDiff(ecgPeakList,PeakCnt,DiffPeakList);

        for(index = 0;index < Diffcount;index++){
            DiffTmp[index] = DiffPeakList[index];
        }
        standardindex = GetMaxPos32(DiffTmp,Diffcount); // 最大值的id
        //gap_standard=max(gap_list);%以最大gap为周期时长基
        standarddiff = DiffPeakList[standardindex];          // 标准值

        /// 对应标准值的前一个点的位置
        EcgQualtifyPeakPosList[ecgpeakcnt++] = ecgPeakList[standardindex];
        /// 对应标准值的后一个点的位置
        EcgQualtifyPeakPosList[ecgpeakcnt++] = ecgPeakList[standardindex + 1];

        //  保存后一个便准 的值
        tmpindex = standardindex;
        /// 向前推导
        searchi = tmpindex;
        while(1){
            if(searchi-- <= 0){  break; }
            // 求和  // 1-0.8
            if((unsigned short int)GetSumU16(DiffPeakList,standardindex) < (unsigned short int)(standarddiff * 0.2)){
                break;
            }
            tmpsumdiff = 0;
            for(index = standardindex - 1;index >= 0;index--){
                tmpsumdiff += DiffPeakList[index];
                if(qFabs((tmpsumdiff - standarddiff)*1.0) *  1.0f / standarddiff <= 0.8 ){
                    EcgQualtifyPeakPosList[ecgpeakcnt++] = ecgPeakList[index];
                    standardindex = index;
                    break;
                }
            }
        }
        /// 向后推导
        standardindex = tmpindex + 1;
        searchi = standardindex;
        while(1){
            if(tmpindex++ >= Diffcount){ break; }
            // 求和  // 1-0.8
            if((unsigned short int)GetSumU16(DiffPeakList + standardindex,Diffcount- standardindex ) < (unsigned short int)(standarddiff * 0.2)){
                break;
            }
            if(ecgpeakcnt >= MAX_HEARTBEAT_3SEC){ break;  }
            tmpsumdiff = 0;
            for(index = standardindex + 1;index < PeakCnt;index++){
                tmpsumdiff += DiffPeakList[index - 1];
                if(qFabs((tmpsumdiff - standarddiff)*1.0) *  1.0f / standarddiff <= 0.8 ){
                    EcgQualtifyPeakPosList[ecgpeakcnt++] = ecgPeakList[index];
                    standardindex = index;
                    break;
                }
            }
        }
        SelectSortAsc(EcgQualtifyPeakPosList,ecgpeakcnt);
        return ecgpeakcnt;
}

unsigned short ECGDataProcess::GetAPeakList(float *fcardinal, unsigned short *EcgQualtifyPeakPosList)
{
    //***************************************//
        /// 增加15HZ高通滤波  【2020.9.4号增加】
        //float fcardinal_filter[10000]={0};
        //EMG_interference_remove(fcardinal, fcardinal_filter);
        //	for(unsigned short int j=0; j<1000; j++)
        //{
        //	printf(" j =%d ",j );
        //	printf(" fcardinal_filter =%d ",fcardinal_filter[j] );
        //	printf("\n");
        //}
         //HPforbaseline(fcardinal, fcardinal_filter);          //
         //**************************************//
        /// 判断所有的谷峰谷
        unsigned short int PeakCnt = 0,ecgcnt = 0;
        //unsigned short int ecgarraycount = GetCardinalCylce( fcardinal_filter,ecgarray);  // [此处替换了]
        unsigned short int ecgarraycount = GetCardinalCylce( fcardinal,ecgarray);  // [此处替换了]

    //	printf(" **\n ");
            //printf("ecgarraycount=%d ", ecgarraycount);
        if(ecgarraycount < MIN_HEARTBEAT_3SEC) {
            return 0;
        }
        /// 前15个粗糙过滤
        PeakCnt = SimpleFilterPeak(ecgarray, ecgarraycount,ecgPeakList);
        for(int i=0; i<PeakCnt ; i++)
        {
            //printf("EcgPeak=%d ", ecgPeakList[i]);
            //printf(" \n ");

        }
        if(PeakCnt < 2){ return 0;  }
        /// 精确过滤 合并

        ecgcnt = FilterPeakList(ecgPeakList,PeakCnt,EcgQualtifyPeakPosList);
        //for(int i=0; i<ecgcnt ; i++)
        //{
        //	printf("EcgPeakPos=%d ", EcgQualtifyPeakPosList[i]);

        //}
        ///***********************************************/// 2020.9.7号   2023.3.1 修改
        /// 增加R波精确位置确定（滤波后信号有偏移）【现在的滤波是基本无偏移滤波，但是波形顶端 有变化，有可能会找错位置】

        //for(unsigned  short int i=0; i<ecgcnt ; i++)
        //{
        //	if (fcardinal[EcgQualtifyPeakPosList[i]]<0 && fcardinal[EcgQualtifyPeakPosList[i]]+1<0  && fcardinal[EcgQualtifyPeakPosList[i]-1]<0  )
        //	{
        //	     EcgQualtifyPeakPosList[i]= min_point_find( fcardinal,10000,EcgQualtifyPeakPosList[i],10);
        //	}
        //	else
        //	{
        //		EcgQualtifyPeakPosList[i]= max_point_find( fcardinal,10000,EcgQualtifyPeakPosList[i],10);
        //	}

        //}

        ///***********************************************///

        return ecgcnt;
}





/*

  心率的计算方法 返回值为心率值

*/
unsigned short ECGDataProcess::M3_HeartRateCAL(float *fcardinal) //心率的计算方法 返回值为心率
{

    unsigned char i;
    unsigned short int PeakCnt;
    unsigned short int R_Cnt=0;
    float RR_temp = 0.0;

    //float fcardinal_mid[2000] = {0.0};
    //for(int j=0; j<2000;j++)
    //{
    //	fcardinal_mid[j] = fcardinal[j]-2000;
    //}

    PeakCnt = GetAPeakList(fcardinal,EcgQualtifyPeakPosList);

    if(PeakCnt>1)
    {
        if (PeakCnt>=5)
        {
            for(i=1; i<PeakCnt-2; i++)
            {
                RR_temp += (EcgQualtifyPeakPosList[i+1] - EcgQualtifyPeakPosList[i]);
            }
            R_Cnt = PeakCnt-3;
        }
        else if (PeakCnt>=3 && PeakCnt<5)
        {
            for(i=1; i<PeakCnt-1; i++)
            {
                RR_temp += (EcgQualtifyPeakPosList[i+1] - EcgQualtifyPeakPosList[i]);
            }
            R_Cnt = PeakCnt-2;
        }
        else
        {
            for(i=0; i<PeakCnt-1; i++)
            {
                RR_temp += (EcgQualtifyPeakPosList[i+1] - EcgQualtifyPeakPosList[i]);
            }
            R_Cnt = PeakCnt-1;
        }
    }

    RR_temp = RR_temp/(float)(R_Cnt );//num of average RR point
    RR_temp = RR_temp*1000/SAMPLE_RATE;//RR lenth ms
    RR_temp = 60*1000/RR_temp;//hart rate per min

    return (unsigned short int)(RR_temp+0.5) ;  // 四舍五入

}



/*
*
* 以下是滤波相关的方法
*
*/

/// 这一版 分段连接 无跳跃


/// 函数功能：
///  进行低通/高通滤波
//  [可供多阶滤波器使用]
void ECGDataProcess::filter(float *fcardinal, unsigned short len, float *fcardinal_filter, const float *filter_B, const float *filter_A, unsigned short order_filter)
{
    for (unsigned short int i = 0; i < len; i++)
    {
        for (unsigned short int j = 0; i >=j && j <= order_filter; j++)
        {
            fcardinal_filter[i]+=filter_B[j]*fcardinal[i-j]-filter_A[j]*fcardinal_filter[i-j];
        }
    }
    // 前两点用原数据代替
    fcardinal_filter[0]=fcardinal[0];
    fcardinal_filter[1]=fcardinal[1];
}
/// 函数功能：
///  进行低通/高通滤波
//  [调用filter，可供多阶滤波器使用]  2020.8.4号新增
//  f_data_in,需要带入的数据（初始可以定义为0，第一次滤波时候不用）；f_data_out；滤波后保存的数据，以便下一次使用；sign=0，代表是第一次滤波，sign=1，代表2-N次滤波
void ECGDataProcess::filter_pro(float *fcardinal, unsigned short len, float *fcardinal_filter, const float *filter_B, const float *filter_A, unsigned short order_filter, float *f_data, unsigned short sign)
{

    if (sign == 0)
        {
            filter(fcardinal, len,fcardinal_filter, filter_B, filter_A, order_filter);
            //保存最后的几个点数
            for (unsigned short int j = 0; j <= order_filter; j++)
            {
                //printf("j=%d ",j);
                f_data[j]= fcardinal[len-order_filter+j-1]; //原始数据的部分
                //*(f_data+j)= fcardinal[len-order_filter+j-1];
            }
            for (unsigned short int j = order_filter+1; j <=2* order_filter+1; j++)
            {
                f_data[j]= fcardinal_filter[len-2*order_filter+j-2]; //滤波数据的部分
                //*(f_data+j)= fcardinal_filter[len-2*order_filter+j-2]; //滤波数据的部分
            }
        }
        else if (sign == 1)
        {
            float fcardinal_mid[12000]= {0.0};
            float fcardinal_filter_mid[12000]= {0.0};
            for (unsigned short int i = 0; i <=order_filter; i++)
            {
                //printf("i=%d ",i+len-order_filter-1);
                fcardinal_mid[i+len-order_filter-1]= f_data[i];
            }
            for (unsigned short int i = order_filter+1; i <=2*order_filter+1; i++)
            {
                //printf("i=%d ",i+len-2*order_filter-2);
                fcardinal_filter_mid[i+len-2*order_filter-2]= f_data[i];
            }
            for (unsigned short int i = len; i <2*len; i++)
            {

                fcardinal_mid[i]= fcardinal[i-len];
            }

            for (unsigned short int i = len-order_filter-1; i <2* len-order_filter-1; i++)
            {
                //printf("i=%d ",i = len-order_filter-1);
                for (unsigned short int j = 0; i >=j && j <= order_filter; j++)
                {
                    fcardinal_filter_mid[i+order_filter+1]+=filter_B[j]*fcardinal_mid[i+order_filter+1-j]-filter_A[j]* fcardinal_filter_mid[i+order_filter+1-j];
                }
            }

            //保存最后的几个点数[原始数据和滤波以后的数据]
            for (unsigned short int j = 0; j <len; j++)
            {
                fcardinal_filter[j]=  fcardinal_filter_mid[j+len];
            }

            for (unsigned short int j = 0; j <= order_filter; j++)
            {
                f_data[j]= fcardinal[len-order_filter+j-1]; //原始数据的部分
                //*(f_data+j)= fcardinal[len-order_filter+j-1];
            }
            for (unsigned short int j = order_filter+1; j <=2* order_filter+1; j++)
            {
                f_data[j]= fcardinal_filter[len-2*order_filter+j-2]; //滤波数据的部分
                //*(f_data+j)= fcardinal_filter[len-2*order_filter+j-2]; //滤波数据的部分
            }
    }
}
/// 函数功能：
///  带阻滤波器
void ECGDataProcess::bandstop_filter(float *fcardinal, unsigned short len, float *fcardinal_filter, const float *filter_B, const float *filter_A)
{
    float u0=0.0;
    float u1=0.0;
    float u2=0.0;
    float u3=0.0;

    for (unsigned short int i = 0; i < len; i++)
    {
        //printf("i =%d ", i);
        u0 = fcardinal[i];
        u1 = u0 - filter_A[1]*u2 -filter_A[2]*u3;
        fcardinal_filter[i]= filter_B[0]*u1 + filter_B[1]*u2 + filter_B[2]*u3;
        u3=u2;
        u2=u1;
        //printf("fcardinal_filter[i] =%f ",fcardinal_filter[i]);
        //printf("\n");
    }
    // 前两点用原数据代替
    fcardinal_filter[0]=fcardinal[0];
    fcardinal_filter[1]=fcardinal[1];
}
/// 函数功能：
///  对数据进行高通滤波(matlab)
//  【进行基线漂移滤除，可以选择0.05HZ,0.15HZ,0.3HZ 】
void ECGDataProcess::HPforbaseline_remove(float *fcardinal, unsigned short len, unsigned short BL_type, float *fcardinal_filter, float *f_data, unsigned short sign)
{
    unsigned short int filter_order =0;
        //滤波
        if (len>10) //长度大于2才进行滤波
        {
            if (BL_type == 0)  // 0.05HZ
            {
                unsigned short int order_HP=1;
                filter_order = order_HP;
                filter_pro(fcardinal, len,fcardinal_filter, HP_B1, HP_A1, filter_order,f_data,sign);
            }
            else if (BL_type == 1)  //0.15HZ
            {
                unsigned short int order_HP=1;
                filter_order = order_HP;
                filter_pro(fcardinal, len,fcardinal_filter, HP_B2, HP_A2, filter_order,f_data,sign);
            }
            else if (BL_type == 2)  //0.3HZ
            {
                unsigned short int order_HP=1;
                filter_order = order_HP;
                filter_pro(fcardinal, len,fcardinal_filter, HP_B3, HP_A3, filter_order,f_data,sign);
            }
            else if (BL_type == 3)  //0.67
            {
                unsigned short int order_HP=1;
                filter_order = order_HP;
                filter_pro(fcardinal, len,fcardinal_filter, HP_B4, HP_A4, filter_order,f_data,sign);
            }
            else if (BL_type == 4)  //不进行滤波
            {
                for (unsigned short int i = 0; i < len; i++)
                {
                    fcardinal_filter[i]=fcardinal[i];
                }
            }
        } // (len>10)
        else  //
        {
            for (unsigned short int i = 0; i < len; i++)
            {
                fcardinal_filter[i]=fcardinal[i];
            }
        }

}

//12导高通滤波
void ECGDataProcess::HPforbaseline_remove_12L(float *fcardinal_12L, unsigned short fcardinal_length, unsigned short BL_type, float *fcardinal_filter_12L, float *f_12Ldata, unsigned short sign)
{
    float fcardinal[10000]= {0.0};
    float fcardinal_filter[10000]= {0.0};

    unsigned short int order_HP=1;

    for(unsigned short int i=0; i<12; i++)
    {
        float f_data[12]={0.0};

        for(unsigned short int k=0; k<2*(order_HP+1); k++)
        {
            f_data[k] =f_12Ldata[i*2*(order_HP+1)+k];
        }
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal[j] = fcardinal_12L[i*fcardinal_length+j];
        }
        HPforbaseline_remove(fcardinal, fcardinal_length, BL_type,fcardinal_filter,f_data,sign);
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal_filter_12L[i*fcardinal_length+j] = fcardinal_filter[j];
        }
        for(unsigned short int k=0; k<2*(order_HP+1); k++)
        {
            f_12Ldata[i*2*(order_HP+1)+k]= f_data[k];
        }
    }
}

/// 函数功能：
///  对数据进行低通滤波(matlab)
//  【进行肌电干扰滤波，可以选择25HZ,35HZ,150HZ 】

void ECGDataProcess::EMG_interference_remove(float *fcardinal, unsigned short len, unsigned short EMG_type, float *fcardinal_filter, float *f_data, unsigned short sign)
{
    unsigned short int filter_order =0;
    //滤波
    if (len>10) //长度大于2才进行滤波
    {
        if (EMG_type == 0)  // 25HZ
        {
            unsigned short int order_LP=4;
            filter_order = order_LP;
            filter_pro(fcardinal, len,fcardinal_filter, EMG_LP_B1_25, EMG_LP_A1_25, filter_order,f_data,sign);
        }
        else if (EMG_type == 1)  //40
        {
            unsigned short int order_LP=4;
            filter_order = order_LP;
            filter_pro(fcardinal, len,fcardinal_filter, EMG_LP_B2_40, EMG_LP_A2_40, filter_order,f_data,sign);
        }
        else if (EMG_type == 2)  //150HZ
        {
            unsigned short int order_LP=4;
            filter_order = order_LP;
            filter_pro(fcardinal, len,fcardinal_filter, EMG_LP_B3_150, EMG_LP_A3_150,filter_order,f_data,sign);
        }
        else if (EMG_type == 3)  //不进行滤波
        {
            for (unsigned short int i = 0; i < len; i++)
            {
                fcardinal_filter[i]=fcardinal[i];
            }
        }
    } // (len>10)
    else  //
    {
        for (unsigned short int i = 0; i < len; i++)
        {
            fcardinal_filter[i]=fcardinal[i];
        }
    }
}
//12导肌电滤波
void ECGDataProcess::EMG_interference_remove_12L(float *fcardinal_12L, unsigned short fcardinal_length, unsigned short EMG_type, float *fcardinal_filter_12L, float *f_12Ldata, unsigned short sign)
{
    float fcardinal[10000]= {0.0};
    float fcardinal_filter[10000]= {0.0};

    unsigned short int order_LP=4;

    for(unsigned short int i=0; i<12; i++)
    {

        float f_data[12]={0.0};

        for(unsigned short int k=0; k<2*(order_LP+1); k++)
        {
            //printf("k=%d ",k);
            f_data[k] =f_12Ldata[i*2*(order_LP+1)+k] ;
        }
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal[j] = fcardinal_12L[i*fcardinal_length+j];
        }
        EMG_interference_remove(fcardinal, fcardinal_length, EMG_type,fcardinal_filter,f_data,sign);
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal_filter_12L[i*fcardinal_length+j] = fcardinal_filter[j];
        }
        for(unsigned short int k=0; k<2*(order_LP+1); k++)
        {
            f_12Ldata[i*2*(order_LP+1)+k]= f_data[k];
        }
    }

}
/// 函数功能：
///  对数据进行工频干扰滤波;
//  【 带阻滤波器】【可选50HZ\60HZ】
void ECGDataProcess::Power_line_interference_remove(float *fcardinal, unsigned short len, unsigned short AC_type, float *fcardinal_filter)
{
    //unsigned short int filter_order =0;
    //滤波
    if (len>10) //长度大于2才进行滤波
    {
        if (AC_type == 0)  // 50HZ
        {
            //printf("filter_order=%d ", filter_order);
            bandstop_filter(fcardinal, len,fcardinal_filter,SP_B_50, SP_A_50);
        }
        else if (AC_type  == 1)  //60HZ
        {

            bandstop_filter(fcardinal, len,fcardinal_filter, SP_B_60, SP_A_60);
        }
        else if (AC_type == 2 || AC_type == 3)  //不进行滤波
        {
            for (unsigned short int i = 0; i < len; i++)
            {
                fcardinal_filter[i]=fcardinal[i];
            }
        }
    } // (len>10)
    else  //
    {
        for (unsigned short int i = 0; i < len; i++)
        {
            fcardinal_filter[i]=fcardinal[i];
        }
    }
}

//12导工频干扰滤波

void ECGDataProcess::Power_line_interference_remove_12L(float *fcardinal_12L, unsigned short fcardinal_length, unsigned short AC_type, float *fcardinal_filter_12L)
{
    float fcardinal[10000]= {0.0};
    float fcardinal_filter[10000]= {0.0};
    for(unsigned short int i=0; i<12; i++)
    {
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal[j] = fcardinal_12L[i*fcardinal_length+j];
        }
        Power_line_interference_remove(fcardinal, fcardinal_length, AC_type,fcardinal_filter);
        for(unsigned short int j=0; j<fcardinal_length; j++)
        {
            fcardinal_filter_12L[i*fcardinal_length+j] = fcardinal_filter[j];
        }
    }
}


