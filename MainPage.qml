import QtQuick 2.12
import M3ShowDataController 1.0
import QtQuick.Controls 2.5   //引入Popup
import QtQuick.Layouts 1.12        //Popup布局管理器
//import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观

import QtQuick.VirtualKeyboard 2.4        //虚拟键盘相关的包
import QtQuick.VirtualKeyboard.Styles 2.2
import QtQuick.VirtualKeyboard.Settings 2.2

import QtMultimedia 5.8 //播放声音

Rectangle {
    width: 1280
    height: 800
    id:show_M3
    property int alarmCount : 0
    property var soundArray: ["sound/Ring01.wav","sound/Alarm.mp3","sound/alarm1.wav","sound/alarm2.mp3","sound/alarm3.mp3","sound/alarm4.wav"]
    property string ecgShowSource : "qrc:/SPO2And3LeadsShow.qml" //心电图的显示界面。3导联还是12导联
    //property string ecgShowSource : "qrc:/SPO2AndOnly3LeadsShow.qml" //心电图的显示界面。3导联还是12导联
    //生理报警相关的变量
    property int warnHighLevelCount: 0     //高级别报警计数
    property int warnMediumLevelCount: 0   //中级别报警计数
    property int warnLowLevelCount: 0      //低级别报警计数
    property int hrtooFastFlag: 0         //心动过速标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int hrtooSlowFlag: 0         //心动过缓标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2ValueLowFlag: 0      //血氧过低标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int bptooHightFlag: 0        //血压过高标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int bptooLowFlag: 0          //血压过低标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property var phsicList: []            //生理报警列表 标题栏显示的内容 当报警存在时 此列表中有相应的内容 报警比消失时，该列表中对应的内容消失
    //技术报警暂时都为低级别报警
    property int leadsDroppedFlag: 0      //导联脱落标志位   =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2FingersOut: 0        //血氧手指未插入标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2DroppedFlag: 0       //血氧探头脱落标志位  =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int batteryLowFlag: 0        //电池电量标志位  =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagRA:0           //导联RA脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagLA:0           //导联LA脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagLL:0           //导联LL脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV1:0           //导联V1脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV2:0           //导联V2脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV3:0           //导联V3脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV4:0           //导联V4脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV5:0           //导联V5脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagV6:0           //导联V6脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int leadOFFFlagRL:0           //导联V6脱落标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警

    property var techList: []             //技术报警列表 标题栏显示的内容 当报警存在时 此列表中有相应的内容 报警比消失时，该列表中对应的内容消失

    property bool warnPauseFlag: false        //报警暂停标志位


    property color warnHRShowBKColor: "red"     //心率框报警时的背景颜色
    property color warnBPShowBKColor: "red"     //心率框报警时的背景颜色
    property color warnSPO2ShowBKColor: "red"     //心率框报警时的背景颜色
    property string soundSource: "sound/Alarm.mp3" //声报警的声源

    property string wlanSSID: ""
    //property string connectedWIIFName: ""

    // property string ecgShowSource : "qrc:/SPO2And12LeadsShow.qml" //心电图的显示界面。3导联还是12导联
    //心电图测试用的数据和分析
    /////心电图的分析
    /***
    第I导联的最大值为4646.55，最小值为451.505 差值为4195.045
    第II导联的最大值为11014.9，最小值为3455.95 差值为7558.95
    第III导联的最大值为6458.91，最小值为2783.91 差值为4195.045
    第aVR导联的最大值为-2014.08，最小值为-7795.92 差值为5781.84
    第aVL导联的最大值为-739.843，最小值为-1563.13 差值为823.287
    第aVF导联的最大值为8736.92，最小值为3135.2 差值为5601.72
    第V1导联的最大值为3498.79，最小值为-3199.65 差值为6698.44
    第V2导联的最大值为2296.46，最小值为536.069 差值为1760.391
    第V3导联的最大值为3905.97，最小值为725.314 差值为3180.656
    第V4导联的最大值为7510.93，最小值为1037.49 差值为6473.44
    第V5导联的最大值为6553.9，最小值为1171.23 差值为5382.67
    第V6导联的最大值为6518.64，最小值为2205.37 差值为4312.77


    可以看到其中最大的差值为7558.95

 //在3导联的显示界面中   故 将每个导联的值设置为2倍 16000，每个chart显示3个导联，所以chart的Y值为16000*3=48000
    其中 I，II，III 为一组 I基值偏移为  -300+16000*2  II基值偏移为  -3000+16000 II基值偏移为  -2500
    其中 aVR，aVL，aVF 为一组 aVR基值偏移为  8000+16000*2  aVL基值偏移为  1800+16000 aVF基值偏移为  -3000
    其中 V1，V2，V3 为一组 V1基值偏移为  3500+16000*2  V2基值偏移为  16000 V3基值偏移为  -300
    其中 V4，V5，V6 为一组 V4基值偏移为  -800+16000*2  V5基值偏移为  -900+16000 V6基值偏移为  -2000


 //在12导联的显示界面中
    采用的是6行2列的排列方式  故 将每个导联的值设置为2倍 16000，每个chart显示3个导联，所以chart的Y值为16000*6=96000

    每一到联要显示5s的数据，对应的实际数据就是5000个点，但是由于要显示的数据为原来数据的1/25，所以每个导联要显示的点为200

    第1列
          I    y=y+16000*5-300 = 79700  x=x+40                V1  y=y+16000*5+3500 =83500      x=x+280 280=40+200+40
    第2列
          II   y=y+16000*4-3000 = 61000  x=x+40                V2  y=y+16000*4  = 64000           x=x+280 280=40+200+40
    第3列
          III  y=y+16000*3-2500 = 45500  x=x+40                V3  y=y+16000*3-300 = 47700       x=x+280 280=40+200+40
    第4列
          aVR  y=y+16000*2+8000 = 40000  x=x+40                V4  y=y+16000*2-800  =31200      x=x+280 280=40+200+40
    第5列
          aVL  y=y+16000*1+1800 = 17800  x=x+40                V5  y=y+16000*1-900  = 15100      x=x+280 280=40+200+40
    第6列
          aVF  y=y+16000*0-3000 = -3000  x=x+40                V6  y=y+16000*0-2000  =-2000     x=x+280 280=40+200+40
**/

    //property var leads12ShowBaselineY: [79700,61000,45500,40000,17800,-3000,83500,64000,47700,31200,15100,-2000]
    //为了传数据方便将数据在算心率的数据的基础上再*100
    //property var leads12ShowBaselineY: [7970000,6100000,4550000,4000000,1780000,-300000,8350000,6400000,4770000,3120000,1510000,-200000]

    // property var leads12ShowBaselineX: [30,30,30,30,30,30,227,227,227,227,227,227]
    // property var leads12ShowBaselineX: [30,30,30,30,30,30,1060,1060,1060,1060,1060,1060]
    //property var leads12ShowBaselineX: [40,280,40,280,40,280,40,280,40,280,40,280]
    // property var leads3ShowBaselineY: [31700,15300,-100,34200,17000,-1000,32000,18000,300,31600,15500,-800]
    /*
    //时间相关
    //成人儿童按钮
    property alias titleAdultOrChildSrc    :title.adultOrChild  //标题栏成人儿童的图片资源
    //技术报警
    property alias titleTechWarnContent    :title.techWarnConten      //技术报警的内容
    property alias titleTechWarnBackColor  :title.techWarnBackColor   //技术报警的背景色
    property alias titleTechWarnVisible    :title.techWarnVisble     //技术报警是否可见
    //生理报警
    property alias titlePhsicWarnContent   :title.phsicWarnConten     //生理报警的内容
    property alias titlePhsicWarnBackColor :title.phsicWarnBackColor  //生理报警的背景色
    property alias titlePhsicWarnVisible   :title.phsicWarnVisble     //生理报警是否可见
    //报警暂停倒计时
    property alias titleCountDownTime      :title.countDownTime        //报警倒计时text
    property alias titleCountDownTimeVisible:title.countDownTimeVisible //报警倒计时是否可见
    //电池相关的参数
    property alias titleBatValue           :title.batValer             //电池的电量       //对应C++数据已添加 M3ShowController类中的batValue数据类型为unsigned int
    property alias titleBatPercent         :title.batPercent           //电池显示的百分比  //根据电池电量计算百分比
    property alias titleBatChargeVisible   :title.batChargeVisible     //充电标志是否可见  //对应C++数据已添加 M3ShowController类中的chargeFlag数据类型为bool
    */
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    //心率框的属性和信号
    property alias heartRate:hRshow.hRtxt     //显示心率
    property alias heartRateMax:hRshow.hRUuptxt  //显示上限，目前显示100，不知是否需要更改
    property alias heartRateMin:hRshow.hRDowntxt //显示下限，目前显示90，不知是否需要更改
    property alias heartRateBackColor:hRshow.hRBKcolor //整个组件的背景颜色，报警时光报警需要更改颜色
    signal hrShowlicked                   //单击信号
    /////////////////////////////////////////////////////////////////////////////////////////////////////
    //血压框的属性和信号
    property alias bPShowTitleLefttxt       :bPShow.titleLefttxt              //更改标题左上角的内容
    //第一界面(血压内容显示界面)需要控制的显示的内容

    property alias bPShowBPtxt              :bPShow.bPtxt                      //显示血压
    property alias bPShowMaxtxt             :bPShow.bPUptxt                   //显示上限，目前显示100，不知是否需要更改
    property alias bPShowMintxt             :bPShow.bPDowntxt                  //显示下限，目前显示90，不知是否需要更改
    property alias bPShowBPBKcolor          :bPShow.bPBKcolor                  //整个组件的背景颜色，报警时光报警需要更改颜色
    property alias bPShowCountDownTime      :bPShow.countDownTime              //倒计时，字符串模式 //定时测量血压时需要
    property alias bPShowCounDownTimeVisible:bPShow.counDownTimeVisible      //测量血压倒计时是否可见，手动测量时为不可见
    property alias bPShowBPtxtVisible       :bPShow.bPtxtVisible               //第一界面是否可见
    property int bPshowCountDownSeconds : 0

    //第二界面(血压列表)需要现实的内容
    property alias bPShowBPListViewVisible  :bPShow.bPListViewVisible          //第二界面是否可见



    signal bPShowClicked                   //单击信号
    signal bpShowListNIBPShowClicked       //NIBP显示列表信号
    signal bpShowListNIBPCloseClicked       //NIBP关闭列表信号
    //////////////////////////////////////////////////////////////////////////////////////////////////
    //血氧框的属性和信号
    property alias sPO2ShowTxt     :sPO2Show.sP02txt                //显示血氧值
    property alias sPO2ShowMax    :sPO2Show.sPO2Uptxt               //显示上限，目前显示100，不知是否需要更改
    property alias sPO2ShowMin   :sPO2Show.sPO2Downtxt              //显示下限，目前显示90，不知是否需要更改
    property alias sPO2ShowBKcolor   :sPO2Show.sPO2BKcolor              //整个组件的背景颜色，报警时光报警需要更改颜色
    property alias sPO2ShowPItxt       :sPO2Show.pItxt                  //血氧pI的显示值
    property alias sPO2ShowValueHeight :sPO2Show.valueHeight            //showHeight.width  //显示一个高度值,范围是(0-130)



    signal sPO2ShowClicked                   //单击信号
    ///////////////////////////////////////////////////////////////////////////////////////////////////
    //底部按键栏的属性和信号
    signal bottomBtnWarnResetCilcked
    signal bottomBtnWarnPauseCilcked
    signal bottomBtnStartBPCilcked
    signal bottomBtnRecordECGCilcked
    signal bottomBtnWarnSetCilcked
    signal bottomBtnMainMenuCilcked

    property alias bottomBtnWarnResetBKColor:bottomBtn.warnResetBKColor
    property alias bottomBtnWarnPauseBKColor:bottomBtn.warnPauseBKColor
    property alias bottomBtnStartBPBKColor  :bottomBtn.startBPBKColor
    property alias bottomBtnRecordECGBKColor:bottomBtn.recordECGBKColor
    property alias bottomBtnWarnSetBKColor  :bottomBtn.warnSetBKColor
    property alias bottomBtnMainMenuBKColor :bottomBtn.mainMenuBKColor

    property int loaderContenIndex: 1
    //标题栏的属性和信号
    property int warnPauseCountDownTime : 120 //报警暂停倒计时 目前设定是120S
    property int warnPauseCountDownTimetmp    //倒计时用到的临时变量

    //报警阈值属性 //用来区分是哪一个报警调用了该Popup
    property string warnLevelName : "null"


    //property var baselineNUM: [580,-560,-1050,2320,1000,-810,1400,-250,-620,-520,-500,-850] //根据导联数据最小值推算的，相应的导联+该数组的值。基线维持在0~20之间
    //property var baselineNUM: [580,-560,-1050,2320,1700,-810,1400,200,-620,-520,-500,-850] //根据导联数据最小值推算的，相应的导联+该数组的值。基线维持在0~20之间aVL和V2由于幅值太小需要再加一些基准值
    //property var baselineNUM: [820,-69160,-69880,36490,36920,-69520,-45410,-47090,-46743,-47035,-46909,-47609] //根据导联数据最小值推算的，相应的导联+该数组的值。AD芯片导联脱落模式设置为上拉电阻和下拉电阻模式，基线维持在0~20之间aVL+1400和V2-400由于幅值太小需要再加一些基准值
    property var baselineNUM: [m3DataControl.leadIBaseLine,m3DataControl.leadIIBaseLine,m3DataControl.leadIIIBaseLine,
        m3DataControl.leadaVRBaseLine,m3DataControl.leadaVLBaseLine,m3DataControl.leadaVFBaseLine,
        m3DataControl.leadV1BaseLine,m3DataControl.leadV2BaseLine,m3DataControl.leadV3BaseLine,
        m3DataControl.leadV4BaseLine,m3DataControl.leadV5BaseLine,m3DataControl.leadV6BaseLine] //根据导联数据最小值推算的，相应的导联+该数组的值。AD芯片导联脱落模式设置为上拉电阻和下拉电阻模式，基线维持在0~20之间aVL+1400和V2-400由于幅值太小需要再加一些基准值


    property bool hrToogle: false //心率框是否闪烁
    property bool bpToogle: false //血压框是否闪烁
    property bool spo2Toogle: false //血氧框是否闪烁
    function backMainPage()       //返回主界面的函数
    {
        contentLoader.source=show_M3.ecgShowSource//返回主界面
    }
    Image{
        anchors.fill:parent
        z:1
        id:startImage
        source:"img/logo_kernel.bmp"
    }

    M3ShowController{ //C++编写的数据类

        id:m3DataControl
        autoMeasureNIBPFlag:true

    }

    M3_title{

        id:title
        date:m3DataControl.date
        time:m3DataControl.time
        onSetDateAndTimeClicked: {
            dateAndTimeSetPopOpen()//打开时间设置的对话框
        }
        onAdultOrChildClicked:{
            //titleAdultOrChildClicked()
            adultOrChildDialog.open()

        }
        onTechWarnClicked:{

            contentLoader.source="WarnLogPage.qml" //跳转到报警日志界面

        }
        onPhsicWarnClicked:{

            contentLoader.source="WarnLogPage.qml" //跳转到报警日志界面
        }
        Component.onCompleted: { //组件加载完成
            title.warnCountDownTimeVisible = false //报警暂停倒计时不可见
            title.techWarnVisble = false           //技术报警不可见
            title.phsicWarnVisble = false          //生理报警不可见
            if(m3DataControl.netTransFlag === 1) //如果数据的传输状态为有线模式
            {
                title.wifiSources = "img/wifi_disconnected.png" //wifi图标
                title.netSources = "img/net_connected.png"  //有线图标
                title.btSource = "img/BT_closed.png"
            }
            else if(m3DataControl.netTransFlag === 2) //如果数据的传输状态为无线模式
            {
                title.wifiSources = "img/wifi_connected.png" //wifi图标
                title.netSources = "img/net_disconnected.png"  //有线图标
                title.btSource = "img/BT_closed.png"
            }
            else if(m3DataControl.netTransFlag === 3) //如果数据传输模式为蓝牙模式
            {
                title.wifiSources = "img/wifi_disconnected.png" //wifi图标
                title.netSources = "img/net_disconnected.png"  //有线图标
                title.btSource = "img/BT_open.png"
            }
            m3DataControl.batValSendSig.connect(showBatValue) //将电池电量显示出来
            m3DataControl.netTransFlagChanged.connect(netTransChanged)//网络传输方式的变化
            m3DataControl.btConnected.connect(btConnected) //蓝牙连接
            m3DataControl.btDisconnected.connect(btDisConnected) //蓝牙断开连接
        }
        onEcgStopClicked: {
            //心电图显示暂停按钮
            m3DataControl.ecgShowStopFlag = !m3DataControl.ecgShowStopFlag
            //console.log("m3DataControl.ecgShowStopFlag = ",m3DataControl.ecgShowStopFlag)
        }
        //wifiShowClicked
        onWifiShowClicked: {
            //netWlanStateDialog()
            if(m3DataControl.netTransFlag === 2) //如果数据的传输状态为无线模式
            {
                netWlanStateDialogOpen()
                console.log("wlan open")
            }

        }
        onNetShowClicked:{
            if(m3DataControl.netTransFlag === 1) //如果数据的传输状态为有线模式
            {
                netLanStateDialogOpen()
                console.log("lan open")
            }
        }
        function btConnected()
        {
            title.btSource = "img/BT_connected.png"
        }
        function btDisConnected()
        {
            title.btSource = "img/BT_open.png"
        }
        function showBatValue(val,val2)
        {
            //此处处理电池相关的数据 val为电池电量百分比
            if(val === 999)
            {
                batPercent = "--";
                batValue = 0;
            }
            else
            {
                if(startImage.visible === true)
                {
                    startImage.visible = false
                    console.log("startImage visible = false")
                }

                batPercent = val+"%";
                if((val>=80)&&(val<=100))
                {
                    batValue = 39;
                    batColor = "green"
                    warnMessageProcess(42,2)
                }
                else if((val>=60)&&(val<80))
                {
                    batValue = 32;
                    batColor = "green"
                    warnMessageProcess(42,2)
                }
                else if((val>=40)&&(val<60))
                {
                    batValue = 24;
                    batColor = "green"
                    warnMessageProcess(42,2)
                }
                else if((val>=20)&&(val<40))
                {
                    batValue = 16;
                    batColor = "green"
                    warnMessageProcess(42,2)
                }
                else if(val<20)
                {
                    batValue = 8;
                    batColor = "red"
                    warnMessageProcess(24,2)

                }
            }
            if(val2 === 1) //如果值为1,则为充电状态
            {
                batChargeVisible = true
            }
            else if(val2 === 0) //如果值为0,则未充电
            {
                batChargeVisible = false
            }
        }
        function netTransChanged()
        {
            console.log("m3DataControl.netTransFlag = ",m3DataControl.netTransFlag )
            if(m3DataControl.netTransFlag === 1) //如果数据的传输状态为有线模式
            {
                title.wifiSources = "img/wifi_disconnected.png" //wifi图标
                title.netSources = "img/net_connected.png"  //有线图标
                title.btSource = "img/BT_closed.png"
            }
            else if(m3DataControl.netTransFlag === 2) //如果数据的传输状态为无线模式
            {
                title.wifiSources = "img/wifi_connected.png" //wifi图标
                title.netSources = "img/net_disconnected.png"  //有线图标
                title.btSource = "img/BT_closed.png"
            }
            else if(m3DataControl.netTransFlag === 3) //如果数据传输模式为蓝牙模式
            {
                title.wifiSources = "img/wifi_disconnected.png" //wifi图标
                title.netSources = "img/net_disconnected.png"  //有线图标
                title.btSource = "img/BT_open.png"
            }
        }
    }

    /*关于报警关闭和打开相关的函数*/
    function warnClose()//报警关闭
    {
        title.warnimageSource = "img/warnClose.png"
        title.warnCountDownText = "报警关闭" //显示报警关闭
        title.warnCountDownTimeContentVisible = false//不显示倒计时
        //失能两个按键
        bottomBtn.warnResetBKColor = "gray"
        bottomBtn.warnPauseBKColor = "gray"
        title.warnCountDownTimeVisible = true
        m3DataControl.alarmSoundVolume(0);//报警关闭，关闭报警声音
        m3DataControl.warnCloseFlag = true
    }
    function warnOpen()//报警打开
    {
        title.warnimageSource = "img/WarnningPause.png"
        title.warnCountDownText = "报警关闭" //显示报警关闭
        title.warnCountDownTimeContentVisible = "false"//不显示倒计时
        //失能两个按键
        bottomBtn.warnResetBKColor = "#d8d8d8"
        bottomBtn.warnPauseBKColor = "#d8d8d8"
        title.warnCountDownTimeVisible = false
        m3DataControl.alarmSoundVolume(100);//报警打开，打开报警声音
        m3DataControl.warnCloseFlag = false
    }



    HRShow{   //心率框
        id:hRshow
        x: 880
        y: 69
        hRtxt: m3DataControl.heartRate //心率值的显示
        onClicked: {
            hrShowlicked()
            contentLoader.source = "ECGSetPage.qml" //跳转到ECG设置界面
        }
        Component.onCompleted: { //心率模块加载完成
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
            {
                hRshow.hRUuptxt = m3DataControl.hrFastValue //心率过速上限值
                hRshow.hRDowntxt = m3DataControl.hrSlowValue //心动过缓下限值
            }
            else if (m3DataControl.wideOrNarrowThresHoldChoice === false) //为宽阈值时
            {
                hRshow.hRUuptxt = m3DataControl.hrFastValueWide    //心率过速上限值
                hRshow.hRDowntxt = m3DataControl.hrSlowValueWide   //心动过缓下限值
            }
            m3DataControl.hrFastValueChanged.connect(hrFastValueShow)
            m3DataControl.hrSlowValueChanged.connect(hrSlowValueShow)
            m3DataControl.hrFastValueChangedWide.connect(hrFastValueWideShow)
            m3DataControl.hrSlowValueChangedWide.connect(hrSlowValueWideShow)
        }
        function hrFastValueShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//如果当前阈值为窄阈值
            {
                hRshow.hRUuptxt = m3DataControl.hrFastValue //心率过速上限值
            }
        }
        function hrSlowValueShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//如果当前阈值为窄阈值
            {
                hRshow.hRDowntxt = m3DataControl.hrSlowValue //心动过缓下限值
            }
        }

        function hrFastValueWideShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === false)//如果当前阈值为窄阈值
            {
                hRshow.hRUuptxt = m3DataControl.hrFastValueWide    //心率过速上限值
            }
        }
        function hrSlowValueWideShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === false)//如果当前阈值为窄阈值
            {
                hRshow.hRDowntxt = m3DataControl.hrSlowValueWide   //心动过缓下限值
            }
        }

    }
    BPSHow{ //血压框
        x: 880
        y: 278
        id:bPShow
        onClicked:{
            bPShowClicked()
            contentLoader.source = "NIBPSetPage.qml" //跳转到血压设置界面
        }
        onListNIBPShowClicked:{
            bpShowListNIBPShowClicked()
        }
        onListNIBPCloseClicked:{
            bpShowListNIBPCloseClicked()
        }
        Component.onCompleted: {
            if(m3DataControl.autoMeasureNIBPFlag === true) //如果是自动测量模式
            {
                bPShow.countDownTimeVisible = true
                bPshowCountDownSeconds = m3DataControl.autoMeasureNIBPMinut*60
                if(m3DataControl.autoMeasureNIBPMinut<0)
                {
                    countDownTime = "0"+m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                }
                else
                {
                    countDownTime = m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                }
            }
            else                                           //手动测量模式
            {
                bPShow.countDownTimeVisible = false
            }

            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
            {
                bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValueH+"/"+m3DataControl.bpDIAThresHoldValueH //收缩压上限值
                bPShow.bPDowntxt = m3DataControl.bpSYSThresHoldValueL+"/"+m3DataControl.bpDIAThresHoldValueL //舒张压下限值
            }
            else if (m3DataControl.wideOrNarrowThresHoldChoice === false) //为宽阈值时
            {
                bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValueHWide+"/"+m3DataControl.bpDIAThresHoldValueHWide //收缩压上限值
                bPShow.bPDowntxt = m3DataControl.bpSYSThresHoldValueLWide+"/"+m3DataControl.bpDIAThresHoldValueLWide //舒张压下限值
//                bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValueWide    //收缩压上限值
//                bPShow.bPDowntxt = m3DataControl.bpDIAThresHoldValueWide   //舒张压下限值
            }


            m3DataControl.autoMeasureNIBPFlagChanged.connect(countDownTimeVisibleOrNot) //自动或者手动模式的处理函数
            m3DataControl.autoMeasureMinuteChanged.connect(countDownTimeVisibleOrNot)   //根据模式倒计时是否可见
            m3DataControl.bpSYSThresHoldValueHChanged.connect(bpSYSValueShow)//窄阈值收缩压阈值
            m3DataControl.bpSYSThresHoldValueLChanged.connect(bpSYSValueShow)//窄阈值收缩压阈值
            m3DataControl.bpDIAThresHoldValueHChanged.connect(bpDIAValueShow)//窄阈值舒张压阈值
            m3DataControl.bpDIAThresHoldValueLChanged.connect(bpDIAValueShow)//窄阈值舒张压阈值
            m3DataControl.bpSYSThresHoldValueHChangedWide.connect(bpSYSValueWideShow)//窄阈值收缩压阈值
            m3DataControl.bpSYSThresHoldValueLChangedWide.connect(bpSYSValueWideShow)//窄阈值收缩压阈值
            m3DataControl.bpDIAThresHoldValueHChangedWide.connect(bpDIAValueWideShow)//窄阈值舒张压阈值
            m3DataControl.bpDIAThresHoldValueLChangedWide.connect(bpDIAValueWideShow)//窄阈值舒张压阈值
        }
        function bpSYSValueShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//如果当前阈值为窄阈值
            {
                bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValue //收缩压上限值
            }
        }
        function bpDIAValueShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//如果当前阈值为窄阈值
            {
                bPShow.bPDowntxt = m3DataControl.bpDIAThresHoldValue //舒张压下限值
            }
        }

        function bpSYSValueWideShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === false)//如果当前阈值为宽阈值
            {
                bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValueWide //收缩压上限值
            }
        }
        function bpDIAValueWideShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === false)//如果当前阈值为宽阈值
            {
                bPShow.bPDowntxt = m3DataControl.bpDIAThresHoldValueWide //舒张压下限值
            }
        }



    }

    function countDownTimeVisibleOrNot()
    {
        if(m3DataControl.autoMeasureNIBPFlag === true) //如果是自动测量模式
        {
            bPShow.countDownTimeVisible = true
            bPshowCountDownSeconds = m3DataControl.autoMeasureNIBPMinut*60
            if(m3DataControl.autoMeasureNIBPMinut<10)
            {
                bPShow.countDownTime = "0"+m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
            }
            else{
                bPShow.countDownTime = m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
            }
        }
        else                                           //手动测量模式
        {
            bPShow.countDownTimeVisible = false
        }
    }

    SPO2Show{ //血氧框
        x: 880
        y: 487
        id:sPO2Show
        sP02txt:m3DataControl.spo2Num
        onClicked: {
            sPO2ShowClicked() //暂时没有二级界面
        }
        Component.onCompleted: {

            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
            {
                sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValue
            }
            else if (m3DataControl.wideOrNarrowThresHoldChoice === false) //为宽阈值时
            {
                sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValueWide
            }

            m3DataControl.spo2ThresHoldValueChanged.connect(sPO2ValueShow)
            m3DataControl.spo2ThresHoldValueChangedWide.connect(sPO2ValueWideShow)
        }
        function sPO2ValueShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === true)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
            {
                sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValue
            }
        }
        function sPO2ValueWideShow()
        {
            if(m3DataControl.wideOrNarrowThresHoldChoice === false)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
            {
                sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValueWide
            }
        }
    }

    function wideOrNarrowThresHoldChanged()
    {
        if(m3DataControl.wideOrNarrowThresHoldChoice === true)//判断当前设置是窄阈值还是宽阈值 true为窄阈值 false为宽阈值
        {
            hRshow.hRUuptxt = m3DataControl.hrFastValue //心率过速上限值
            hRshow.hRDowntxt = m3DataControl.hrSlowValue //心动过缓下限值
            sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValue //血氧的下限值
            bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValue //收缩压上限值
            bPShow.bPDowntxt = m3DataControl.bpDIAThresHoldValue //舒张压下限值
        }
        else if (m3DataControl.wideOrNarrowThresHoldChoice === false) //为宽阈值时
        {
            hRshow.hRUuptxt = m3DataControl.hrFastValueWide    //心率过速上限值
            hRshow.hRDowntxt = m3DataControl.hrSlowValueWide   //心动过缓下限值
            sPO2Show.sPO2Downtxt = m3DataControl.spo2ThresHoldValueWide //血氧的下限值
            bPShow.bPUptxt = m3DataControl.bpSYSThresHoldValueWide    //收缩压上限值
            bPShow.bPDowntxt = m3DataControl.bpDIAThresHoldValueWide   //舒张压下限值
        }
    }





    Loader{
        x: 0
        y: 69
        id:contentLoader //内容加载器
        source:ecgShowSource
    }


    BottomButton{ //底部按键
        x: 0
        y: 700
        width: 1280
        height: 100
        id:bottomBtn
        onWarnResetCilcked:{   //报警复位。就是在底部按键栏报警暂停后，撤销报警暂停，恢复报警功能
            //bottomBtnWarnResetCilcked()
            if(m3DataControl.warnCloseFlag === false)
            {
                if(title.warnCountDownTimeVisible === true) //如果报警暂停已经按下
                {
                    title.warnCountDownTimeVisible = false
                    bottomBtn.warnPauseBKColor = "#d8d8d8"
                    m3DataControl.alarmSoundVolume(100);//暂停完毕，打开报警声音
                }
            }

            ScreenShot.capture() //屏幕截屏
            console.log("ScreenShotted")
        }
        onWarnPauseCilcked:{  //报警暂停 暂时无界面 //标题栏现实报警暂停符号，显示倒计时，本按键背景变为红色，倒计时结束，暂停图标消失，按键背景恢复原色
            if(m3DataControl.warnCloseFlag === false)
            {
                if(warnPauseBKColor == "#d8d8d8") //如果按键没有按下
                {
                    var seconds
                    var minutes
                    var countDownString

                    warnPauseCountDownTimetmp = warnPauseCountDownTime
                    title.warnCountDownTimeVisible = true
                    warnPauseBKColor = "red"
                    minutes = parseInt(warnPauseCountDownTimetmp/60)
                    seconds = warnPauseCountDownTimetmp%60
                    if(minutes<10)
                    {
                        countDownString = "0"+minutes.toString()
                    }
                    else if(minutes === 0)
                    {
                        countDownString = "00"
                    }
                    else
                    {
                        countDownString = "0"+minutes.toString()
                    }
                    if(seconds<10)
                    {
                        countDownString = countDownString+":0"+seconds.toString()
                    }
                    else
                    {
                        countDownString = countDownString+":"+seconds.toString()
                    }
                    title.warnCountDownTime = countDownString

                    //关闭报警声
                    m3DataControl.alarmSoundVolume(0)
                }
            }

        }
        onStartBPCilcked:{    //血压开始测量按键，发送血压模块测试指令 血压值回传后更新血压框数值
            bottomBtnStartBPCilcked()
            if(startBPBKTxt == "测量血压")
            {
                startBPBKTxt = "结束测量"
                startBPBKColor = "yellow"
                //此处连接到数据控制类，控制类通过信号与槽连接到数据采集类中，将血压测量信号发送给采集模块
                m3DataControl.transmitNIBPStartSignal(); //发送测量血压指令
            }
            else if(startBPBKTxt == "结束测量")
            {
                startBPBKTxt = "测量血压"
                startBPBKColor = "#d8d8d8"
                if(m3DataControl.autoMeasureNIBPFlag === true) //如果是自动模式 倒计时复位
                {
                    bPshowCountDownSeconds = m3DataControl.autoMeasureNIBPMinut*60
                    if(m3DataControl.autoMeasureNIBPMinut<10)
                    {
                        bPShow.countDownTime = "0"+m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                    }
                    else
                    {
                        bPShow.countDownTime = m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                    }
                }
                m3DataControl.transmitNIBPStopSignal(); //发送测量血压指令
            }
            //此处连接到数据控制类，控制类通过信号与槽连接到数据采集类中，将血压测量信号发送给采集模块
            //m3DataControl.transmitNIBPStartSignal();
        }
        onRecordECGCilcked:{  //记录心电按键，暂时未开发
            //bottomBtnRecordECGCilcked()
            //暂时用于将心电数据存入以时间为标志的文件中
            if(recordECGBKColor == "#d8d8d8") //处于未记录的状态
            {
                recordECGBKTxt = "停止记录"
                recordECGBKColor = "yellow"
                m3DataControl.recordECGFlag = true
            }
            else //处于记录的状态
            {
                recordECGBKTxt = "记录心电"
                recordECGBKColor = "#d8d8d8"
                m3DataControl.recordECGFlag = false
            }
        }
        onWarnSetCilcked:{    //报警设置界面
            bottomBtnWarnSetCilcked()
            contentLoader.source="WarnSetPage.qml" //报警设置界面
        }
        onSettingCilcked: {  //设置页面
            contentLoader.source="SetPage.qml"

        }
        onMainMenuCilcked:{
            bottomBtnMainMenuCilcked()
            backMainPage()
        }
    }
    function playAlarmSound()
    {
        if(warnHighLevelCount>0) //当前有高级别的报警
        {
            m3DataControl.alarmPlay(0);//播放声音
        }
        else if(warnHighLevelCount === 0)//当前无高级别的报警
        {
            if(warnMediumLevelCount>0)//当前有中级别的报警
            {
                m3DataControl.alarmPlay(1);//播放声音
            }
            else if(warnMediumLevelCount===0)//当前无中级别的报警
            {
                if(warnLowLevelCount>0) //当前有低级别的报警
                {
                    m3DataControl.alarmPlay(2);//播放声音
                }
                else if(warnLowLevelCount === 0)
                {
                    m3DataControl.alarmPlay(3)//关闭声音
                }
            }

        }
    }


    Component.onCompleted: {   //组件加载完毕  ，初始化信号连接 变量定义等

        m3DataControl.bPValueChanged.connect(changeBPValue)  //更新血压值的显示
        m3DataControl.spo2NumChanged.connect(changeSPO2Value)//更新血氧值的显示
        m3DataControl.timeChanged.connect(updataTitleTime)   //更新时间显示
        m3DataControl.timeChanged.connect(bPAutoCountDownTimeUpdata)//自动测量血压的倒计时
        m3DataControl.timeChanged.connect(warnPauseCountDownTimeUpdata)//自动测量血压的倒计时
        m3DataControl.heartRateChanged.connect(changeHeartRateValue) //更新心率显示
        m3DataControl.patientTypeChanged.connect(changeTitlePatientType)//更新病人类型。更新标题栏病人类型图片
        m3DataControl.wideOrNarrowThresHoldChoiceChanged.connect(wideOrNarrowThresHoldChanged)//宽窄阈值切换时，心率框，血压框，血氧框上限值下限值的变化
        m3DataControl.warnMessage2MainPage.connect(warnMessageProcess)  //处理报警信息

        // playAlarmSound()
        //测试模块闪烁代码
        //        hrShowTimer.start()
        //        bpShowTimer.start()
        //        spo2ShowTimer.start()
    }
    /*
    property int warnHighLevelCount: 0     //高级别报警计数
    property int warnMediumLevelCount: 0   //中级别报警计数
    property int warnLowLevelCount: 0      //低级别报警计数
    property int hrtooFastFlag: 0         //心动过速标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int hrtooSlowFlag: 0         //心动过缓标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2ValueLowFlag: 0      //血氧过低标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int bptooHightFlag: 0        //血压过高标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int bptooLowFlag: 0          //血压过低标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    //技术报警暂时都为低级别报警
    property int leadsDroppedFlag: 0      //导联脱落标志位   =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2FingersOut: 0        //血氧手指未插入标志位 =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int spo2DroppedFlag: 0       //血氧探头脱落标志位  =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警
    property int batteryLowFlag: 0        //电池电量标志位  =1 为高级别报警  =2为中级别报警   =3为低级别报警 =0无报警

    property bool warnPauseFlag: false        //报警暂停标志位
*/


    function warnMessageProcess(warnType,warnLevel) //warnType代表的是报警类型 warnLevel是报警级别  0  高       1   中       2 低
    {
        var index = 0   //用来标记将要在报警列表中删除信息的索引值
        var i = 0

        switch(warnType)
        {

        case 1:      //心动过速
            if(hrtooFastFlag === 0) //如果没有心动过速的报警 避免重复报警
            {
                title.phsicWarnVisble = true
                title.phsicWarnConten = ""
                title.phsicWarnConten = "心动过速"
                phsicList.unshift("心动过速")
                warnListAddElement(m3DataControl.time,"心动过速") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    hrtooFastFlag = 1 //高级别报警
                    warnHighLevelCount +=1 //高级别报警计数+1
                    hRShowLightWarn(hrtooFastFlag) //打开心率框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    hrtooFastFlag = 2 //中级别报警
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    hRShowLightWarn(hrtooFastFlag) //打开心率框光报警
                    playAlarmSound() //播放声音

                }
                else if(warnLevel === 2)//报警级别为低
                {
                    hrtooFastFlag = 3 //低级别报警
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }

            }
            break;
        case 2:      //心动过缓
            //console.log("hrtooSlowFlag = ",hrtooSlowFlag)
            if(hrtooSlowFlag === 0)//当前没有心动过缓的报警 避免重复报警
            {
                title.phsicWarnVisble = true
                title.phsicWarnConten = ""
                title.phsicWarnConten = "心动过缓"
                warnListAddElement(m3DataControl.time,"心动过缓") //报警列表中添加相应的内容
                phsicList.unshift("心动过缓")
                if(warnLevel === 0)//报警级别为高
                {
                    hrtooSlowFlag = 1 //高级别报警
                    warnHighLevelCount +=1 //高级别报警计数+1
                    hRShowLightWarn(hrtooSlowFlag) //打开心率框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    hrtooSlowFlag = 2 //中级别报警
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    hRShowLightWarn(hrtooSlowFlag) //打开心率框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    hrtooSlowFlag = 3 //低级别报警
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 3:      //血氧过低

            if(spo2ValueLowFlag ===0)  //当前没有血氧值过低的报警
            {
                title.phsicWarnVisble = true
                title.phsicWarnConten = ""
                title.phsicWarnConten = "血氧过低"
                warnListAddElement(m3DataControl.time,"血氧过低") //报警列表中添加相应的内容
                phsicList.unshift("血氧过低")
                if(warnLevel === 0)//报警级别为高
                {
                    spo2ValueLowFlag = 1 //血氧过低为高级别报警
                    warnHighLevelCount+=1 //高级别报警计数+1
                    spo2ShowLightWarn(spo2ValueLowFlag)
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    spo2ValueLowFlag = 2 //血氧过低为中级别报警
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    spo2ShowLightWarn(spo2ValueLowFlag)
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    spo2ValueLowFlag = 3 //血氧过低为低级别报警
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 4:      //血压过高 大于收缩压

            if(bptooHightFlag === 0)//当前状态无血压过高的报警
            {
                title.phsicWarnVisble = true
                title.phsicWarnConten = ""
                title.phsicWarnConten = "血压过高"
                phsicList.unshift("血压过高")
                warnListAddElement(m3DataControl.time,"血压过高") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    bptooHightFlag = 1 //血压过高为高级别报警
                    warnHighLevelCount+=1 //高级别报警计数+1
                    bpShowLightWarn(bptooHightFlag) //血压框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    bptooHightFlag = 2 //血压过高为中级别报警
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    bpShowLightWarn(bptooHightFlag) //血压框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    bptooHightFlag = 3 //血压过高为低级别报警
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 5:      //血压过低 小于舒张压
            if(bptooLowFlag === 0) //当前没有低血压报警
            {
                title.phsicWarnVisble = true
                title.phsicWarnConten = ""
                title.phsicWarnConten = "血压过低"
                phsicList.unshift("血压过低")
                warnListAddElement(m3DataControl.time,"血压过低") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    bptooLowFlag = 1 //低血压报警为高级别
                    warnHighLevelCount+=1 //高级别报警计数+1
                    bpShowLightWarn(bptooLowFlag) //血压框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    bptooLowFlag = 2 //低血压报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    bpShowLightWarn(bptooLowFlag) //血压框光报警
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    bptooLowFlag = 3 //低血压报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 11:          //心率正常
            if((hrtooFastFlag>0)||(hrtooSlowFlag>0))//当心动过缓或者心动过速标志位大于0时
            {
                if(hrtooFastFlag>0) //心动过速标志位大于0
                {
                    if(hrtooFastFlag === 1) //心动过速为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }
                    }
                    else if(hrtooFastFlag === 2) //心动过速为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }
                    }
                    else if(hrtooFastFlag === 3) //心动过速为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<phsicList.length;i++)
                    {
                        if(phsicList[i] === "心动过速")
                        {
                            index = i
                            break;
                        }
                    }
                    phsicList.splice(index,1)//删除list中的心动过速相关的记录
                    warnListRemoveElement("心动过速")//报警记录列表删除相应的记录
                    if(phsicList.length ===0) //如果列表为0，关掉标题栏生理报警显示
                    {
                        title.phsicWarnVisble = false
                    }
                    else
                    {
                        title.phsicWarnConten = phsicList[0]
                    }
                }


                if(hrtooSlowFlag>0) //心动过缓标志位
                {
                    if(hrtooSlowFlag === 1) //心动过速为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }
                    }
                    else if(hrtooSlowFlag === 2) //心动过速为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }
                    }
                    else if(hrtooSlowFlag === 3) //心动过速为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<phsicList.length;i++)
                    {
                        if(phsicList[i] === "心动过缓")
                        {
                            index = i
                            break;
                        }
                    }
                    phsicList.splice(index,1) //删除list中的心动过缓相关的记录
                    warnListRemoveElement("心动过缓")//报警记录列表删除相应的记录
                    if(phsicList.length ===0) //如果列表为0，关掉标题栏生理报警显示
                    {
                        title.phsicWarnVisble = false
                    }
                    else
                    {
                        title.phsicWarnConten = phsicList[0]
                    }
                }
            }
            hrtooFastFlag = 0 //心动过速标志位清零
            hrtooSlowFlag = 0 //心动过缓标志位清零
            break;
        case 12:          //血氧正常
            if(spo2ValueLowFlag>0) //当前有血氧过低的报警
            {
                if(spo2ValueLowFlag === 1) //心动过速为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(spo2ValueLowFlag === 2) //心动过速为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(spo2ValueLowFlag === 3) //心动过速为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<phsicList.length;i++)
                {
                    if(phsicList[i] === "血氧过低")
                    {
                        index = i
                        break;
                    }
                }
                phsicList.splice(index,1) //删除list中的血氧报警相关的记录
                warnListRemoveElement("血氧过低") //报警记录列表删除相应的记录
                if(phsicList.length ===0) //如果列表为0，关掉标题栏生理报警显示
                {
                    title.phsicWarnVisble = false
                }
                else
                {
                    title.phsicWarnConten = phsicList[0]
                }
            }
            spo2ValueLowFlag = 0 //血氧过低标志位清零
            break;
        case 13:          //血压正常
            if((bptooHightFlag>0)||(bptooLowFlag>0))//当前血压有报警
            {
                if(bptooHightFlag>0) //高血压
                {
                    if(bptooHightFlag === 1) //血压过高为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }

                    }
                    else if(bptooHightFlag === 2) //血压过高为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }

                    }
                    else if(bptooHightFlag === 3) //血压过高为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<phsicList.length;i++)
                    {
                        if(phsicList[i] === "血压过高")
                        {
                            index = i
                            break;
                        }
                    }
                    phsicList.splice(index,1)//删除list中的血压过高相关的记录
                    warnListRemoveElement("血压过高") //报警记录列表删除相应的记录
                    if(phsicList.length ===0) //如果列表为0，关掉标题栏生理报警显示
                    {
                        title.phsicWarnVisble = false
                    }
                    else
                    {
                        title.phsicWarnConten = phsicList[0]
                    }
                }

                if(bptooLowFlag>0) //低血压
                {
                    if(bptooLowFlag === 1) //血压过低为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }
                    }
                    else if(bptooLowFlag === 2) //血压过低为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }
                    }
                    else if(bptooLowFlag === 3) //血压过低为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<phsicList.length;i++)
                    {
                        if(phsicList[i] === "血压过低")
                        {
                            index = i
                            break;
                        }
                    }
                    phsicList.splice(index,1)//删除list中的血压过低相关的记录
                    warnListRemoveElement("血压过低") //报警记录列表删除相应的记录
                    if(phsicList.length ===0) //如果列表为0，关掉标题栏生理报警显示
                    {
                        title.phsicWarnVisble = false
                    }
                    else
                    {
                        title.phsicWarnConten = phsicList[0]
                    }
                }
            }
            spo2ValueLowFlag=0
            bptooLowFlag=0
            break;
        case 21:     //导联脱落
            if(leadsDroppedFlag == 0) //当前没有导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="导联脱落"
                techList.unshift("导联脱落")
                warnListAddElement(m3DataControl.time,"导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadsDroppedFlag = 1 //导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadsDroppedFlag = 2 //导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    leadsDroppedFlag = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 22:     //手指未插入
            if(spo2FingersOut == 0)
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="手指未插入"
                techList.unshift("手指未插入")
                warnListAddElement(m3DataControl.time,"手指未插入") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    spo2FingersOut = 1 //导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    spo2FingersOut = 2 //导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    spo2FingersOut = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 23:     //血氧探头脱落
            if(spo2DroppedFlag == 0) //当前没有血氧探头脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="血氧探头脱落"
                techList.unshift("血氧探头脱落")
                warnListAddElement(m3DataControl.time,"血氧探头脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    spo2DroppedFlag = 1 //导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    spo2DroppedFlag = 2 //导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    spo2DroppedFlag = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 24:     //电池电量过低
            if(batteryLowFlag == 0) //当前没有电池电量低报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="电池电量低"
                techList.unshift("电池电量低")
                warnListAddElement(m3DataControl.time,"电池电量低") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    batteryLowFlag = 1 //导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    batteryLowFlag = 2 //导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//报警级别为低
                {
                    batteryLowFlag = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            break;
        case 25: //RA导联脱落
            if(leadOFFFlagRA == 0) //当前没有RA导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="RA导联脱落"
                techList.unshift("RA导联脱落")
                warnListAddElement(m3DataControl.time,"RA导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagRA = 1 //RA导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagRA = 2 //RA导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//RA导联脱落报警级别为低
                {
                    leadOFFFlagRA = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffRA = true
            break;
        case 26: //LA导联脱落
            if(leadOFFFlagLA == 0) //当前没有RA导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="LA导联脱落"
                techList.unshift("LA导联脱落")
                warnListAddElement(m3DataControl.time,"LA导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagLA = 1 //RA导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagLA = 2 //RA导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//RA导联脱落报警级别为低
                {
                    leadOFFFlagLA = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffLA = true
            break;
        case 27: //LL导联脱落
            if(leadOFFFlagLL == 0) //当前没有RA导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="LL导联脱落"
                techList.unshift("LL导联脱落")
                warnListAddElement(m3DataControl.time,"LL导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagLL = 1 //RA导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagLL = 2 //RA导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//RA导联脱落报警级别为低
                {
                    leadOFFFlagLL = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffLL = true
            break;
        case 28: //V1导联脱落
            if(leadOFFFlagV1 == 0) //当前没有V1导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V1导联脱落"
                techList.unshift("V1导联脱落")
                warnListAddElement(m3DataControl.time,"V1导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV1 = 1 //V1导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV1 = 2 //RA导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//RA导联脱落报警级别为低
                {
                    leadOFFFlagV1 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV1 = true
            break;
        case 29: //V2导联脱落
            if(leadOFFFlagV2 == 0) //当前没有V2导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V2导联脱落"
                techList.unshift("V2导联脱落")
                warnListAddElement(m3DataControl.time,"V2导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV2 = 1 //V2导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV2 = 2 //V2导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V2导联脱落报警级别为低
                {
                    leadOFFFlagV2 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV2 = true
            break;
        case 30: //V3导联脱落
            if(leadOFFFlagV3 == 0) //当前没有V3导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V3导联脱落"
                techList.unshift("V3导联脱落")
                warnListAddElement(m3DataControl.time,"V3导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV3 = 1 //V3导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV3 = 2 //V3导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V3导联脱落报警级别为低
                {
                    leadOFFFlagV3 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV3 = true
            break;
        case 31: //V4导联脱落
            if(leadOFFFlagV4 == 0) //当前没有RA导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V4导联脱落"
                techList.unshift("V4导联脱落")
                warnListAddElement(m3DataControl.time,"V4导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV4 = 1 //V4导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV4 = 2 //V4导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V4导联脱落报警级别为低
                {
                    leadOFFFlagV4 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV4 = true
            break;
        case 32: //V5导联脱落
            if(leadOFFFlagV5 == 0) //当前没有V5导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V5导联脱落"
                techList.unshift("V5导联脱落")
                warnListAddElement(m3DataControl.time,"V5导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV5 = 1 //V5导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV5 = 2 //V5导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V5导联脱落报警级别为低
                {
                    leadOFFFlagV5 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV5 = true
            break;
        case 33: //V6导联脱落
            if(leadOFFFlagV6 == 0) //当前没有V6导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="V6导联脱落"
                techList.unshift("V6导联脱落")
                warnListAddElement(m3DataControl.time,"V6导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagV6 = 1 //V6导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagV6 = 2 //V6导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V6导联脱落报警级别为低
                {
                    leadOFFFlagV6 = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffV6 = true
            break;

        case 34: //RL导联脱落
            if(leadOFFFlagRL == 0) //当前没有V6导联脱落报警
            {
                title.techWarnVisble = true    //技术报警可见
                title.techWarnConten =""
                title.techWarnConten ="RL导联脱落"
                techList.unshift("RL导联脱落")
                warnListAddElement(m3DataControl.time,"RL导联脱落") //报警列表中添加相应的内容
                if(warnLevel === 0)//报警级别为高
                {
                    leadOFFFlagRL = 1 //V6导联脱落报警为高级别
                    warnHighLevelCount +=1 //高级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 1)//报警级别为中
                {
                    leadOFFFlagRL = 2 //V6导联脱落报警为中级别
                    warnMediumLevelCount +=1 //中级别报警计数+1
                    playAlarmSound() //播放声音
                }
                else if(warnLevel === 2)//V6导联脱落报警级别为低
                {
                    leadOFFFlagRL = 3 //导联脱落报警为低级别
                    warnLowLevelCount +=1 //低级别报警计数+1
                    playAlarmSound() //播放声音
                }
            }
            m3DataControl.leadsOffRL = true
            break;

        case 41:       //血氧状态正常指令
            if((spo2FingersOut > 0)||(spo2DroppedFlag > 0))
            {
                if(spo2FingersOut>0) //当前有手指未插入的报警
                {
                    if(spo2FingersOut === 1) //为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }
                    }
                    else if(spo2FingersOut === 2) //为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }
                    }
                    else if(spo2FingersOut === 3) //为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<techList.length;i++)
                    {
                        if(techList[i] === "手指未插入")
                        {
                            index = i
                            break;
                        }
                    }
                    techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                    warnListRemoveElement("手指未插入") //报警记录列表删除相应的记录
                    if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                    {
                        title.techWarnVisble = false
                    }
                    else
                    {
                        techWarnConten = techList[0]
                    }
                }


                if(spo2DroppedFlag>0) //当前有血氧探头脱落的报警
                {
                    if(spo2DroppedFlag === 1) //为高级别报警时
                    {
                        if(warnHighLevelCount>0)
                        {
                            warnHighLevelCount -=1
                        }
                    }
                    else if(spo2DroppedFlag === 2) //为中级别报警时
                    {
                        if(warnMediumLevelCount>0)
                        {
                            warnMediumLevelCount -=1
                        }
                    }
                    else if(spo2DroppedFlag === 3) //为低级别报警时
                    {
                        if(warnLowLevelCount>0)
                        {
                            warnLowLevelCount -=1
                        }
                    }
                    playAlarmSound() //播放声音
                    for(i=0;i<techList.length;i++)
                    {
                        if(techList[i] === "血氧探头脱落")
                        {
                            index = i
                            break;
                        }
                    }
                    techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                    warnListRemoveElement("血氧探头脱落") //报警记录列表删除相应的记录
                    if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                    {
                        title.techWarnVisble = false
                    }
                    else
                    {
                        techWarnConten = techList[0]
                    }
                }


            }
            spo2FingersOut = 0
            spo2DroppedFlag = 0
            break;
        case 42:       //解除电池电量低的报警
            if(batteryLowFlag>0) //当前有导联脱落的报警
            {
                if(batteryLowFlag === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(batteryLowFlag === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(batteryLowFlag === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "电池电量低")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("电池电量低") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]
                }
            }
            batteryLowFlag = 0

            break;
        case 43:       //心电导联正常的指令
            if(leadsDroppedFlag>0) //当前有导联脱落的报警
            {
                if(leadsDroppedFlag === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadsDroppedFlag === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadsDroppedFlag === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadsDroppedFlag = 0
            break;

        case 44:       //RA心电导联正常的指令
            if(leadOFFFlagRA>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagRA === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagRA === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagRA === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "RA导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("RA导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagRA = 0
            m3DataControl.leadsOffRA = false
            break;

        case 45:       //LA心电导联正常的指令
            if(leadOFFFlagLA>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagLA === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagLA === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagLA === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "LA导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("LA导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagLA = 0
            m3DataControl.leadsOffLA = false
            break;
        case 46:       //LL心电导联正常的指令
            if(leadOFFFlagLL>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagLL === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagLL === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagLL === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "LL导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("LL导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagLL = 0
            m3DataControl.leadsOffLL = false
            break;
        case 47:       //V1心电导联正常的指令
            if(leadOFFFlagV1>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV1 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV1 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV1 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V1导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V1导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV1 = 0
            m3DataControl.leadsOffV1 = false
            break;
        case 48:       //V2心电导联正常的指令
            if(leadOFFFlagV2>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV2 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV2 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV2 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V2导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V2导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV2 = 0
            m3DataControl.leadsOffV2 = false
            break;
        case 49:       //V3心电导联正常的指令
            if(leadOFFFlagV3>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV3 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV3 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV3 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V3导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V3导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV3 = 0
            m3DataControl.leadsOffV3 = false
            break;
        case 50:       //V4心电导联正常的指令
            if(leadOFFFlagV4>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV4 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV4 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV4 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V4导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V4导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV4 = 0
            m3DataControl.leadsOffV4 = false
            break;
        case 51:       //V5心电导联正常的指令
            if(leadOFFFlagV5>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV5 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV5 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV5 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V5导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V5导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV5 = 0
            m3DataControl.leadsOffV5 = false
            break;
        case 52:       //V6心电导联正常的指令
            if(leadOFFFlagV6>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagV6 === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagV6 === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagV6 === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "V6导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("V6导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV6 = 0
            m3DataControl.leadsOffV6 = false
            break;
        case 53:       //RL心电导联正常的指令
            if(leadOFFFlagRL>0) //当前有导联脱落的报警
            {
                if(leadOFFFlagRL === 1) //为高级别报警时
                {
                    if(warnHighLevelCount>0)
                    {
                        warnHighLevelCount -=1
                    }
                }
                else if(leadOFFFlagRL === 2) //为中级别报警时
                {
                    if(warnMediumLevelCount>0)
                    {
                        warnMediumLevelCount -=1
                    }
                }
                else if(leadOFFFlagRL === 3) //为低级别报警时
                {
                    if(warnLowLevelCount>0)
                    {
                        warnLowLevelCount -=1
                    }
                }
                playAlarmSound() //播放声音
                for(i=0;i<techList.length;i++)
                {
                    if(techList[i] === "RL导联脱落")
                    {
                        index = i
                        break;
                    }
                }
                techList.splice(index,1) //删除list中的导联脱落报警相关的记录
                warnListRemoveElement("RL导联脱落") //报警记录列表删除相应的记录
                if(techList.length ===0) //如果列表为0，关掉标题栏技术报警显示
                {
                    title.techWarnVisble = false
                }
                else
                {
                    title.techWarnConten = techList[0]

                }
            }
            leadOFFFlagV6 = 0
            m3DataControl.leadsOffV6 = false
            break;

        }
        // console.log("phsicList.lenth = "+phsicList.length)
    }
    function resetAllWarns() //复位所有的报警
    {

        //        hrtooFastFlag = 0 //关闭心动过速报警
        //        //清除高 中 低 级别的计数
        //        warnHighLevelCount = 0
        //        warnMediumLevelCount = 0
        //        warnLowLevelCount = 0
        //        //关闭对应显示框 心率 血氧 血压的光闪烁报警

        //        //关闭声音

        //        //清除生理报警列表
        //        phsicList.clean
        //        //清除技术报警列表
        //        te
        //清楚报警日志列表
        //将所有的正常信号都发射一边
        //        warnMessageProcess(11,2) //心率正常
        //        warnMessageProcess(12,2) //血氧正常
        //        //warnMessageProcess(13) //血压正常
        //        warnMessageProcess(41,2) //血氧模块正常
        //        resetAllLeadOff() //复位所有导联
        resetAllPhicsWarn()
        resetAllTechWarn()


    }
    function resetAllPhicsWarn()
    {
        warnMessageProcess(11,2) //心率正常
        warnMessageProcess(12,2) //血氧正常
        //warnMessageProcess(13) //血压正常
    }
    function resetAllTechWarn()
    {
        warnMessageProcess(41,2) //血氧模块正常
        resetAllLeadOff() //复位所有导联
    }
    function resetAllLeadOff()
    {
        warnMessageProcess(44,2)//RA心电导联正常的指令
        warnMessageProcess(45,2)//LA心电导联正常的指令
        warnMessageProcess(46,2)//LL心电导联正常的指令
        warnMessageProcess(47,2)//V1心电导联正常的指令
        warnMessageProcess(48,2)//V2心电导联正常的指令
        warnMessageProcess(49,2)//V3心电导联正常的指令
        warnMessageProcess(50,2)//V4心电导联正常的指令
        warnMessageProcess(51,2)//V5心电导联正常的指令
        warnMessageProcess(52,2)//V6心电导联正常的指令
        warnMessageProcess(53,2)//RL心电导联正常的指令
    }

    Timer{
        interval: 500
        id:warnShowTimer //心率+血压+血氧框在报警时闪烁
        repeat: true
        triggeredOnStart: true
        onTriggered: {
            if(hrToogle == true) //当前有心率光报警
            {
                if(hRshow.hRBKcolor == "#3f4247")
                {

                    hRshow.hRBKcolor = warnHRShowBKColor
                }
                else{
                    hRshow.hRBKcolor = "#3f4247"
                }
            }
            if(bpToogle == true) //当前有血压光报警
            {
                if(bPShow.bPBKcolor == "#3f4247")
                {
                    bPShow.bPBKcolor = warnBPShowBKColor
                }
                else{
                    bPShow.bPBKcolor = "#3f4247"
                }
            }
            if(spo2Toogle == true) //当前有血氧光报警
            {
                if(sPO2Show.sPO2BKcolor == "#3f4247")
                {
                    sPO2Show.sPO2BKcolor = warnSPO2ShowBKColor
                }
                else{
                    sPO2Show.sPO2BKcolor = "#3f4247"
                }
            }

            if((hrtooFastFlag!=2) && (hrtooSlowFlag!=2)&&(hrtooFastFlag!=1) && (hrtooSlowFlag!=1)) //都不是高级别和中级别的报警
            {
                hRshow.hRBKcolor = "#3f4247"
                hrToogle = false //关闭心率框闪烁
            }
            if((bptooHightFlag != 2)&&(bptooLowFlag != 2)&&(bptooHightFlag != 1)&&(bptooLowFlag != 1))//当前没有中级别和高级别的报警
            {
                bPShow.bPBKcolor = "#3f4247"
                bpToogle = false //关闭血压框的光报警
            }
            if((spo2ValueLowFlag != 1)&&(spo2ValueLowFlag != 2))
            {
                sPO2Show.sPO2BKcolor = "#3f4247"
                spo2Toogle = false //关闭血氧框的光报警
            }
            if((hrToogle == false)&&(bpToogle == false)&&(spo2Toogle == false))
            {
                warnShowTimer.stop()
            }
        }
    }

    function hRShowLightWarn(level) //心率框光报警   心动过速和心动过缓不可能同时出现
    {
        if(level ===1)
        {
            warnHRShowBKColor = "red" //红灰闪烁
            hrToogle = true
            if(warnShowTimer.running == false) //如果当前心率框没有光报警
            {
                warnShowTimer.start() //心率框开始闪烁
            }
        }
        else if(level ===2)
        {
            warnHRShowBKColor = "yellow" //黄灰闪烁
            hrToogle = true
            if(warnShowTimer.running == false) //如果当前心率框没有光报警
            {
                warnShowTimer.start() //心率框开始闪烁
            }
        }
        else if(level ===3)
        {
            //            warnHRShowBKColor = "yellow" //黄灰闪烁
            //            hrToogle = true
            //            if(warnShowTimer.running == false) //如果当前心率框没有光报警
            //            {
            //                warnShowTimer.start() //心率框开始闪烁
            //            }
        }

    }
    function changeHeartRateValue()
    {
        if(m3DataControl.heartRate === "9999")
        {
            hRshow.hRtxt = "--"
        }
        else
        {
            hRshow.hRtxt = m3DataControl.heartRate; //更新心率数据
        }

    }

    function updataTitleTime()
    {
        title.date = m3DataControl.date;        //更新日期
        title.time = m3DataControl.time;        //更新时间
    }



    function bpShowLightWarn(level) //血压框光报警
    {
        if(level ===1)
        {
            warnBPShowBKColor = "red"  //红灰闪烁
            bpToogle = true
            if(warnShowTimer.running == false) //如果当前血压框没有光报警
            {
                warnShowTimer.start() //心率框开始闪烁
            }
        }
        else if(level ===2)
        {
            warnBPShowBKColor  = "yellow" //黄灰闪烁
            bpToogle = true
            if(warnShowTimer.running == false) //如果当前血压框没有光报警
            {
                warnShowTimer.start() //心率框开始闪烁
            }
        }
        else if(level ===3)
        {
            //            warnBPShowBKColor  = "yellow" //黄灰闪烁
            //            bpToogle = true
            //            if(warnShowTimer.running == false) //如果当前血压框没有光报警
            //            {
            //                warnShowTimer.start() //心率框开始闪烁
            //            }
        }

    }



    function changeBPValue()
    {
        bPShow.bPtxt = m3DataControl.bPValue;   //更新血压数值
        if(m3DataControl.autoMeasureNIBPFlag ==false) //如果是手动测量 ，按键颜色和内容都要改变
        {
            bottomBtn.startBPBKTxt = "测量血压"
            bottomBtn.startBPBKColor = "#d8d8d8"
        }
    }



    function spo2ShowLightWarn(level) //血氧框光报警
    {
        if(level ===1)
        {
            warnSPO2ShowBKColor = "red" //红灰闪烁
            spo2Toogle = true
            if(warnShowTimer.running == false) //如果当前血氧框没有光报警
            {
                warnShowTimer.start() //血氧框开始闪烁
            }
        }
        else if(level ===2)
        {
            warnSPO2ShowBKColor = "yellow" //黄灰闪烁
            spo2Toogle = true
            if(warnShowTimer.running == false) //如果当前血氧框没有光报警
            {
                warnShowTimer.start() //血氧框开始闪烁
            }
        }
        else if(level ===3)
        {
            //            warnSPO2ShowBKColor = "yellow" //黄灰闪烁
            //            spo2Toogle = true
            //            if(warnShowTimer.running == false) //如果当前血氧框没有光报警
            //            {
            //                warnShowTimer.start() //心率框开始闪烁
            //            }
        }

    }



    function changeSPO2Value()
    {
        if(m3DataControl.spo2Num == 0)
        {
            sPO2Show.sP02txt = "--"
        }
        else
        {
            sPO2Show.sP02txt = m3DataControl.spo2Num; //更新血氧值
        }
        //console.log("spo2Num = "+m3DataControl.spo2Num)
        sPO2Show.pItxt = m3DataControl.piNum; //更新血氧框中的PI值

        sPO2ShowValueHeight = m3DataControl.columHeight; //更新脉搏柱
    }
    function bPAutoCountDownTimeUpdata()
    {
        if((m3DataControl.autoMeasureNIBPFlag)&&(bottomBtn.startBPBKTxt == "结束测量"))//当前模式是自动测量，且测量按键已经按下 m3DataControl.autoMeasureNIBPFlag =true为自动模式
        {
            var seconds
            var minutes
            var countDownTimeShow
            seconds = bPshowCountDownSeconds
            seconds = seconds - 1
            minutes = parseInt(seconds/60)
            if(minutes<10)
            {
                countDownTimeShow = "0"+minutes.toString()
            }
            else
            {
                countDownTimeShow = minutes.toString()
            }
            seconds = seconds % 60
            if(seconds<10)
            {
                countDownTimeShow = countDownTimeShow+":0"+seconds.toString()
            }
            else
            {
                countDownTimeShow = countDownTimeShow+":"+seconds.toString()
            }
            bPShow.countDownTime = countDownTimeShow
            bPshowCountDownSeconds = bPshowCountDownSeconds -1
            if(bPshowCountDownSeconds == 0) //计时结束 发送测量指令
            {
                //发送测量血压的指令
                m3DataControl.transmitNIBPStartSignal(); //发送测量血压指令
                //更新倒计时的显示
                bPshowCountDownSeconds = m3DataControl.autoMeasureNIBPMinut*60
                if(m3DataControl.autoMeasureNIBPMinut<10)
                {
                    bPShow.countDownTime = "0"+m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                }
                else
                {
                    bPShow.countDownTime = m3DataControl.autoMeasureNIBPMinut.toString()+":00"  //自动测量倒计时
                }
            }
        }
    }
    function warnPauseCountDownTimeUpdata()
    {
        var seconds
        var minutes
        var countDownString
        if(title.warnCountDownTimeVisible === true) //如果报警暂停已经按下
        {

            minutes = parseInt(warnPauseCountDownTimetmp/60)
            seconds = warnPauseCountDownTimetmp%60
            if(minutes<10)
            {
                countDownString = "0"+minutes.toString()
            }
            else if(minutes === 0)
            {
                countDownString = "00"
            }
            else
            {
                countDownString = "0"+minutes.toString()
            }
            if(seconds<10)
            {
                countDownString = countDownString+":0"+seconds.toString()
            }
            else
            {
                countDownString = countDownString+":"+seconds.toString()
            }
            title.warnCountDownTime = countDownString
            warnPauseCountDownTimetmp  = warnPauseCountDownTimetmp -1
            if(warnPauseCountDownTimetmp === 0)
            {
                title.warnCountDownTimeVisible = false
                bottomBtn.warnPauseBKColor = "#d8d8d8"
                m3DataControl.alarmSoundVolume(100);//暂停完毕，打开报警声音
            }
        }
    }
    function changeTitlePatientType() //更新标题栏病人类型的的图片
    {
        if(m3DataControl.patientType ===0) //成人类型
        {
            title.adultOrChild = "img/AdultOrChild.png"
        }
        else if(m3DataControl.patientType ===1) //儿童类型
        {
            title.adultOrChild = "img/Child.png"
        }
    }
    function lpSelectPopupshow()
    {
        lpPopup.open()
    }
    function hpSelectPopupshow()
    {
        hpPopup.open()
    }
    function acSelectPopupshow()
    {
        acPopup.open()
    }
    Popup{
        id:adultOrChildDialog
        width: 541
        height: 300
        x:165
        y:200


        topPadding: 0
        bottomPadding: 0
        leftPadding: 0
        rightPadding: 0


        Rectangle {
            id:adultOrChild
            anchors.fill:parent
            color:"#3F4247"
            signal adultOrChildChecked //上传选择信息
            property int checkedIndex: 0
            Text {
                id: patient
                x: 182
                y: 0
                width: 177
                height: 64
                text: qsTr("患者类型")
                color: "#ffffff"
                font.pixelSize: 40
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Rectangle {
                id: closeButon
                x: 20
                y: 15
                width: 50
                height: 50
                color: "#ffffff"
                radius:5

                Image {
                    id: closeImage
                    x: 0
                    y: 0
                    width: 50
                    height: 50
                    source: "img/CloseButton.png"
                    fillMode: Image.PreserveAspectFit
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        adultOrChildDialog.close();
                    }
                }

            }
            ExclusiveGroup{
                id: radioGroup  //将radiobutton控件绑定到同一个组，实现radiobutoon的互斥切换
            }
            Column{
                x: 0
                y: 82
                spacing: 1
                Rectangle {
                    id: rectangle
                    y: 0
                    width: 541
                    height: 109
                    color: "#EAECEA"
                    Image {
                        id: adultPic
                        x: 23
                        y: 25
                        width: 68
                        height: 68
                        source: "img/AdultOrChild.png"
                    }

                    Text{
                        x: 135
                        y: 11
                        id : munualText
                        height: 90
                        width: 204
                        text:"成人"
                        font.pixelSize: 40
                        font.bold: true

                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                    }



                    RadioButton {
                        id: adultRadio
                        x: 450
                        y: 19
                        checked: true
                        exclusiveGroup: radioGroup
                        style:RadioButtonStyle{
                            indicator: Rectangle {
                                implicitWidth: 56
                                implicitHeight: 56
                                //x: control.leftPadding
                                x:0
                                y: parent.height / 2 - height / 2
                                radius: 28
                                border.color: control.down ? "#000000" : "#000000"

                                Rectangle {
                                    width: 34
                                    height: 34
                                    x: 11  // (56 - 34) / 2
                                    y: 11
                                    radius: 17
                                    color: control.down ? "#000000" : "#000000"
                                    visible: control.checked
                                }
                            }
                        }
                        onClicked:
                        {
                            //console.log("成人")
                            m3DataControl.patientType = 0

                        }


                    }
                }
                Rectangle {
                    id: rectangle1
                    width: 541
                    height: 109
                    color: "#EAECEA"
                    Image {
                        id: childPic
                        x: 23
                        y: 20
                        width: 68
                        height: 68
                        source: "img/Child.png"
                    }

                    Text{
                        id:autoText
                        x: 135
                        y: 11

                        height: 90
                        //horizontalCenter: parent.horizontalCenter
                        width: 204
                        font.pixelSize: 40
                        font.bold: true
                        text: "儿童"
                        verticalAlignment: Text.AlignVCenter
                    }

                    RadioButton {
                        id: childRadio
                        x: 450
                        y: 27
                        text:''
                        checked: false
                        exclusiveGroup: radioGroup
                        style:RadioButtonStyle{
                            indicator: Rectangle {
                                implicitWidth: 56
                                implicitHeight: 56
                                //x: control.leftPadding
                                x:0
                                y: parent.height / 2 - height / 2
                                radius: 28
                                border.color: control.down ? "#000000" : "#000000"

                                Rectangle {
                                    width: 34
                                    height: 34
                                    x: 11  // (56 - 34) / 2
                                    y: 11
                                    radius: 17
                                    color: control.down ? "#000000" : "#000000"
                                    visible: control.checked
                                }
                            }
                        }
                        onClicked:
                        {
                            m3DataControl.patientType = 1
                        }
                    }

                }


            }
        }
        Component.onCompleted: { //组件加载完成
            if(m3DataControl.patientType === 0)
            {
                adultRadio.checked = true//成人框的radiobutton会被选中
            }
            else if(m3DataControl.patientType === 1)
            {
                childRadio.checked = true//儿童框的radiobutton会被选中
            }
            if(ecgShowSource === "qrc:/SPO2And12LeadsShow.qml") //如果是12导联显示界面
            {
                m3DataControl.ecg3or12changed(false)
                console.log("current is 12")
            }
            else if(ecgShowSource === "qrc:/SPO2And3LeadsShow.qml") //如果是3导联显示界面
            {
                m3DataControl.ecg3or12changed(true)
                //console.log("current is 3")
            }
        }
    }


    //滤波选择相关的Popup
    //lp(低通滤波)
    Popup{
        id:lpPopup
        x:860
        y:78
        width:160
        height: 240

        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent
            Text{
                text:"25Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.lpSelectIndex = 0
                        lpPopup.close()
                    }
                }
            }
            Text{
                text:"40Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.lpSelectIndex = 1
                        lpPopup.close()
                    }
                }
            }
            Text{
                text:"150Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.lpSelectIndex = 2
                        lpPopup.close()
                    }
                }
            }
            Text{
                text:"关闭"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.lpSelectIndex = 3
                        lpPopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }


    //hp(高通滤波)
    Popup{
        id:hpPopup
        x:860
        y:178
        width:180
        height: 300

        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent
            Text{
                text:"0.05Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.hpSelectIndex = 0
                        hpPopup.close()
                    }
                }
            }
            Text{
                text:"0.15Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.hpSelectIndex = 1
                        hpPopup.close()
                    }
                }
            }
            Text{
                text:"0.30Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.hpSelectIndex = 2
                        hpPopup.close()
                    }
                }
            }
            Text{
                text:"0.67Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.hpSelectIndex = 3
                        hpPopup.close()
                    }
                }
            }
            Text{
                text:"关闭"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.hpSelectIndex = 4
                        hpPopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }



    //ac(电源滤波)
    Popup{
        id:acPopup
        x:860
        y:278
        width:160
        height: 220
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent
            Text{
                text:"50Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.acSelectIndex = 0
                        acPopup.close()
                    }
                }
            }
            Text{
                text:"60Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.acSelectIndex = 1
                        acPopup.close()
                    }
                }
            }
            Text{
                text:"关闭"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.acSelectIndex = 2
                        acPopup.close()
                    }
                }
            }

        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }


    //报警级别(阈值设置界面会用到)
    Popup{

        id:warnLevelPopup
        x:810
        y:278
        width:100
        height: 160//200
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent
            Text{
                text:"高"
                width: parent.width
                font.bold : true
                font.pixelSize: 38

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        console.log(show_M3.warnLevelName)
                        if(show_M3.warnLevelName === "NIBPSYSLevel") //血压窄阈值收缩压
                        {
                            m3DataControl.bpSYSThresHoldLevel = 0
                        }
                        else if(show_M3.warnLevelName === "NIBPDIALevel") //血压窄阈值舒张压
                        {
                            m3DataControl.bpDIAThresHoldLevel = 0
                        }
                        else if(show_M3.warnLevelName === "NIBPSYSLevelWide") //血压宽阈值收缩压
                        {
                            m3DataControl.bpSYSThresHoldLevelWide = 0
                        }
                        else if(show_M3.warnLevelName === "NIBPDIALevelWide") //血压宽阈值舒张压
                        {
                            m3DataControl.bpDIAThresHoldLevelWide = 0
                        }
                        else if(show_M3.warnLevelName === "SPO2Level") //血氧窄阈值
                        {
                            m3DataControl.spo2ThresHoldLevel = 0
                        }
                        else if(show_M3.warnLevelName === "SPO2LevelWide") //血氧宽阈值
                        {
                            m3DataControl.spo2ThresHoldLevelWide = 0
                        }
                        else if(show_M3.warnLevelName === "HRFastLevel") //心率过速窄阈值
                        {
                            m3DataControl.hrFastLevel = 0
                            //console.log("m3DataControl.hrFastLevel",m3DataControl.hrFastLevel)
                        }
                        else if(show_M3.warnLevelName === "HRFastLevelWide") //心率过速宽阈值
                        {
                            m3DataControl.hrFastLevelWide = 0
                        }
                        else if(show_M3.warnLevelName === "HRSlowLevel") //心率过缓窄阈值
                        {
                            m3DataControl.hrSlowLevel = 0
                        }
                        else if(show_M3.warnLevelName === "HRSlowLevelWide") //心率过缓宽阈值
                        {
                            m3DataControl.hrSlowLevelWide = 0
                        }
                        resetAllPhicsWarn();// 复位所有的生理报警
                        warnLevelPopup.close()
                    }
                }
            }
            Text{
                text:"中"
                width: parent.width
                font.bold : true
                font.pixelSize: 38

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        if(show_M3.warnLevelName === "NIBPSYSLevel") //血压窄阈值收缩压
                        {
                            m3DataControl.bpSYSThresHoldLevel = 1
                        }
                        else if(show_M3.warnLevelName === "NIBPDIALevel") //血压窄阈值舒张压
                        {
                            m3DataControl.bpDIAThresHoldLevel = 1
                        }
                        else if(show_M3.warnLevelName === "NIBPSYSLevelWide") //血压宽阈值收缩压
                        {
                            m3DataControl.bpSYSThresHoldLevelWide = 1
                        }
                        else if(show_M3.warnLevelName === "NIBPDIALevelWide") //血压宽阈值舒张压
                        {
                            m3DataControl.bpDIAThresHoldLevelWide = 1
                        }
                        else if(show_M3.warnLevelName === "SPO2Level") //血氧窄阈值
                        {
                            m3DataControl.spo2ThresHoldLevel = 1
                        }
                        else if(show_M3.warnLevelName === "SPO2LevelWide") //血氧宽阈值
                        {
                            m3DataControl.spo2ThresHoldLevelWide = 1
                        }
                        else if(show_M3.warnLevelName === "HRFastLevel") //心率过速窄阈值
                        {
                            m3DataControl.hrFastLevel = 1
                        }
                        else if(show_M3.warnLevelName === "HRFastLevelWide") //心率过速宽阈值
                        {
                            m3DataControl.hrFastLevelWide = 1
                        }
                        else if(show_M3.warnLevelName === "HRSlowLevel") //心率过缓窄阈值
                        {
                            m3DataControl.hrSlowLevel = 1
                        }
                        else if(show_M3.warnLevelName === "HRSlowLevelWide") //心率过缓宽阈值
                        {
                            m3DataControl.hrSlowLevelWide = 1
                        }
                        resetAllPhicsWarn();// 复位所有的生理报警
                        warnLevelPopup.close()
                    }
                }
            }
//            Text{
//                text:"低"
//                width: parent.width
//                font.bold : true
//                font.pixelSize: 38

//                horizontalAlignment: Text.AlignHCenter
//                verticalAlignment: Text.AlignVCenter
//                MouseArea{
//                    anchors.fill:parent
//                    onClicked: {
//                        if(show_M3.warnLevelName === "NIBPSYSLevel") //血压窄阈值收缩压
//                        {
//                            m3DataControl.bpSYSThresHoldLevel = 2
//                        }
//                        else if(show_M3.warnLevelName === "NIBPDIALevel") //血压窄阈值舒张压
//                        {
//                            m3DataControl.bpDIAThresHoldLevel = 2
//                        }
//                        else if(show_M3.warnLevelName === "NIBPSYSLevelWide") //血压宽阈值收缩压
//                        {
//                            m3DataControl.bpSYSThresHoldLevelWide = 2
//                        }
//                        else if(show_M3.warnLevelName === "NIBPDIALevelWide") //血压宽阈值舒张压
//                        {
//                            m3DataControl.bpDIAThresHoldLevelWide = 2
//                        }
//                        else if(show_M3.warnLevelName === "SPO2Level") //血氧窄阈值
//                        {
//                            m3DataControl.spo2ThresHoldLevel = 2
//                        }
//                        else if(show_M3.warnLevelName === "SPO2LevelWide") //血氧宽阈值
//                        {
//                            m3DataControl.spo2ThresHoldLevelWide = 2
//                        }
//                        else if(show_M3.warnLevelName === "HRFastLevel") //心率过速窄阈值
//                        {
//                            m3DataControl.hrFastLevel = 2
//                        }
//                        else if(show_M3.warnLevelName === "HRFastLevelWide") //心率过速宽阈值
//                        {
//                            m3DataControl.hrFastLevelWide = 2
//                        }
//                        else if(show_M3.warnLevelName === "HRSlowLevel") //心率过缓窄阈值
//                        {
//                            m3DataControl.hrSlowLevel = 2
//                        }
//                        else if(show_M3.warnLevelName === "HRSlowLevelWide") //心率过缓宽阈值
//                        {
//                            m3DataControl.hrSlowLevelWide = 2
//                        }
//                        resetAllPhicsWarn();// 复位所有的生理报警
//                        warnLevelPopup.close()
//                    }
//                }
//            }

        }
        onClosed: {
            //console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }


    //    Popup{
    //        id:dateAndTimeSet
    //        width:
    //    }



    InputPanel{
        id:windowInputpanel
        visible: false
        y:800
        width: 400
        z:3
        //anchors.left: parent.left
        //anchors.right:parent.right
        anchors.left: parent.left
        anchors.right:parent.right
        //            anchors.left: show_M3.left
        //            anchors.right:show_M3.right
        //            anchors.bottom: show_M3.bottom
        anchors.bottom: parent.bottom
        height: 170
        onActiveChanged: {
            if(!active){
                visible = false;
            }

        }
    }

    Popup{
        id:passCodeDialog
        width: 540
        height: 350//407
        x:165
        y:200
        z:1

        topPadding: 0
        bottomPadding: 0
        leftPadding: 0
        rightPadding: 0
        Rectangle{

            color:"#3F4247"
            anchors.fill:parent
            Rectangle {
                id: unTitle
                x: 0
                y: 82
                width: 540
                height: 300//325
                color: "#d8d8d8"

                Rectangle{
                    width:265
                    height:56
                    x:194
                    y:112
                    border.width: 1
                    color: "#ffffff"
                    TextField{
                        id:passCodeField
                        anchors.fill:parent
                        text:"passcode"
                        //color:"red"
                        font.letterSpacing: 4
                        //passwordCharacter: "*"
                        //passwordMaskDelay: 6
                        font.pixelSize: 35
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        inputMethodHints: Qt.ImhDigitsOnly
                        maximumLength: 4  //最多输入4位数
                        validator: IntValidator{ bottom: 0000; top: 9999; } //只能输入1~300之间的数
                        onFocusChanged: {
                            //inputpanel.visible = focus;
                            if(focus === true)
                            {
                                //passCodeDialog.y = 100
                                //inputpanel.visible = true
                                windowInputpanel.visible = true
                                //passCodeDialog.Bottom = windowInputpanel.top+20
                                passCodeDialog.x = 165
                                passCodeDialog.y = 2
                                console.log("text on foucused")
                            }
                            else{
                                //passCodeDialog.y = 200
                                //inputpanel.visible = false
                                passCodeDialog.x = 194
                                passCodeDialog.y = 112
                                windowInputpanel.visible = false
                            }
                        }
                        onAccepted:{
                            //inputpanel.visible = false
                            passCodeDialog.x = 194
                            passCodeDialog.y = 112
                            windowInputpanel.visible = false
                        }
                    }

                }

                Text {
                    id: text2
                    x: 62
                    y: 117
                    width: 126
                    height: 46
                    text: qsTr("安全密钥")
                    font.pixelSize: 30
                    font.bold: true
                    font.letterSpacing: 2
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                }

                Rectangle {
                    id: cancelBtn
                    x: 0
                    y: 223//243
                    width: 266
                    height: 82
                    color: "#ffffff"

                    Text {
                        id: cancelText
                        anchors.fill:parent
                        text: qsTr("取消")
                        font.pixelSize: 30
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    MouseArea{              //取消按键按下
                        anchors.fill:parent
                        onClicked: {
                            passCodeField.focus = false
                            passCodeDialog.close()
                        }
                    }
                }

                Rectangle {
                    id: confimBtn
                    x: 272
                    y: 223//243
                    width: 268
                    height: 82
                    color: "#3f4247"

                    Text {
                        id: confimText

                        anchors.fill:parent
                        text: qsTr("确定")
                        font.pixelSize: 30
                        font.bold: true
                        color: "#ffffff"
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }
                    MouseArea{              //确认按键按下
                        anchors.fill:parent
                        onClicked: {
                            passCodeField.focus = false
                            passCodeDialog.close()
                            console.log("跳转至维护界面")
                            contentLoader.source="MaintenancePage.qml" //跳转到宽阈值设置界面界面
                        }
                    }
                }



            }

            Text {
                id: text1
                x: 177
                y: 14
                width: 186
                height: 56
                text: qsTr("维护")
                color:"#ffffff"
                font.pixelSize: 40
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }


        }
        Component.onCompleted: {
            passCodeField.focus = false
        }
        closePolicy: Popup.CloseOnEscape
        //        InputPanel{
        //            id:inputpanel
        //            visible: false
        //            y:800
        //            //width: 400
        //            //anchors.left: parent.left
        //            //anchors.right:parent.right
        //            anchors.left: parent.left
        //            anchors.right:parent.right
        //            //            anchors.left: show_M3.left
        //            //            anchors.right:show_M3.right
        //            //            anchors.bottom: show_M3.bottom
        //            anchors.top: parent.bottom
        //            height: 170
        //            onActiveChanged: {
        //                if(!active){
        //                    visible = false;
        //                }

        //            }
        //        }
    }
    //单个页面导联显示类型选择相关的Popup
    //
    Popup{
        id:leadsShowTypePopup
        x:860
        y:490
        width:80
        height: 220
        property alias leads3Color: leads3.color
        property alias leads6Color: leads6.color
        property alias leads12Color: leads12.color
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent
            Text{
                id:leads3
                text:"3"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 0
                        show_M3.ecgShowSource  = "qrc:/SPO2And3LeadsShow.qml"
                        leads3.color = "green"
                        leads12.color = "black"
                        leads6.color = "black"
                        leadsShowTypePopup.close()
                    }
                }
            }
            Text{
                id:leads6
                text:"6"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 1
                        show_M3.ecgShowSource  = "qrc:/SPO2And6LeadsShow.qml"
                        leads6.color = "green"
                        leads3.color = "black"
                        leads12.color = "black"
                        leadsShowTypePopup.close()
                    }
                }
            }
            Text{
                text:"12"
                id:leads12
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 2
                        show_M3.ecgShowSource  = "qrc:/SPO2And12LeadsShow.qml"
                        leads12.color = "green"
                        leads3.color = "black"
                        leads6.color = "black"
                        leadsShowTypePopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }
    function leadsTypePopupOpen()
    {
        leadsShowTypePopup.open()
        //此处要添加根据导联显示的类型，将导联显示数字变色处理
        if(m3DataControl.leadsShowType === 0)
        {
            leadsShowTypePopup.leads3Color = "green"
            leadsShowTypePopup.leads6Color = "black"
            leadsShowTypePopup.leads12Color = "black"

        }
        else if(m3DataControl.leadsShowType === 1)
        {
            leadsShowTypePopup.leads3Color = "black"
            leadsShowTypePopup.leads6Color = "green"
            leadsShowTypePopup.leads12Color = "black"

        }
        else if(m3DataControl.leadsShowType === 2)
        {
            leadsShowTypePopup.leads3Color = "black"
            leadsShowTypePopup.leads6Color = "black"
            leadsShowTypePopup.leads12Color = "green"

        }
    }




    Popup{
        id:leadsShowTypePopupSU   //隐藏导联显示菜单
        x:860
        y:450
        width:80
        height: 280
        property alias leadsSU1Color: leadsSU1.color
        property alias leadsSU3Color: leadsSU3.color
        property alias leadsSU6Color: leadsSU6.color
        property alias leadsSU12Color: leadsSU12.color
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent

            Text{
                id:leadsSU1
                text:"1"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 3 //当前选择页面为单个导联的显示
                        show_M3.ecgShowSource  = "qrc:/SPO2And1LeadsShow.qml"
                        leadsSU1.color = "green"
                        leadsSU3.color = "black"
                        leadsSU6.color = "black"
                        leadsSU12.color = "black"
                        leadsShowTypePopupSU.close()
                    }
                }
            }


            Text{
                id:leadsSU3
                text:"3"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 0
                        show_M3.ecgShowSource  = "qrc:/SPO2And3LeadsShow.qml"
                        leadsSU1.color = "black"
                        leadsSU3.color = "green"
                        leadsSU6.color = "black"
                        leadsSU12.color = "black"
                        leadsShowTypePopupSU.close()
                    }
                }
            }
            Text{
                id:leadsSU6
                text:"6"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 1
                        show_M3.ecgShowSource  = "qrc:/SPO2And6LeadsShow.qml"
                        leadsSU1.color = "black"
                        leadsSU3.color = "black"
                        leadsSU6.color = "green"
                        leadsSU12.color = "black"
                        leadsShowTypePopupSU.close()
                    }
                }
            }
            Text{
                text:"12"
                id:leadsSU12
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsShowType = 2
                        show_M3.ecgShowSource  = "qrc:/SPO2And12LeadsShow.qml"
                        leadsSU1.color = "black"
                        leadsSU3.color = "black"
                        leadsSU6.color = "black"
                        leadsSU12.color = "green"
                        leadsShowTypePopupSU.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }
    function leadsTypeSUPopupOpen()
    {
        leadsShowTypePopupSU.open()
        //此处要添加根据导联显示的类型，将导联显示数字变色处理
        if(m3DataControl.leadsShowType === 0)  //3个导联显示
        {
            leadsShowTypePopupSU.leadsSU1Color = "black"
            leadsShowTypePopupSU.leadsSU3Color = "green"
            leadsShowTypePopupSU.leadsSU6Color = "black"
            leadsShowTypePopupSU.leadsSU12Color = "black"

        }
        else if(m3DataControl.leadsShowType === 1) //6个导联显示
        {
            leadsShowTypePopupSU.leadsSU1Color = "black"
            leadsShowTypePopupSU.leadsSU3Color = "black"
            leadsShowTypePopupSU.leadsSU6Color = "green"
            leadsShowTypePopupSU.leadsSU12Color = "black"

        }
        else if(m3DataControl.leadsShowType === 2) //12个导联显示
        {
            leadsShowTypePopupSU.leadsSU1Color = "black"
            leadsShowTypePopupSU.leadsSU3Color = "black"
            leadsShowTypePopupSU.leadsSU6Color = "black"
            leadsShowTypePopupSU.leadsSU12Color = "green"

        }
        else if(m3DataControl.leadsShowType === 3) //单个导联显示
        {
            leadsShowTypePopupSU.leadsSU1Color = "green"
            leadsShowTypePopupSU.leadsSU3Color = "black"
            leadsShowTypePopupSU.leadsSU6Color = "black"
            leadsShowTypePopupSU.leadsSU12Color = "black"

        }
    }








    //导联显示速度选择相关的Popup
    //

    function speedPopupOpen()
    {
        speedPopup.open()
    }
    Popup{
        id:speedPopup
        x:860
        y:230
        width:200
        height: 140
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent

            Text{
                id:speed25
                text:"25mm/s"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        m3DataControl.speedType = 0
                        speedPopup.close()
                    }
                }
            }
            Text{
                text:"50mm/s"
                id:speed50
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        m3DataControl.speedType = 1;
                        speedPopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }


    //导联显示增益选择相关的Popup
    //

    function gainPopupOpen()
    {
        gainPopup.open()
    }

    Popup{
        id:gainPopup
        x:860
        y:85//120
        width:230
        //height: 140
        height: 210
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent

            Text{
                id:gain5
                text:"5mm/mv"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.gainType = 2;
                        gainPopup.close()

                    }
                }
            }
            Text{
                id:gain10
                text:"10mm/mv"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.gainType = 0;
                        gainPopup.close()

                    }
                }
            }
            Text{
                text:"20mm/mv"
                id:gain20
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.gainType = 1;
                        gainPopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }

    //导联显示增益选择相关的Popup
    //

    function threeOrTwelveLeadsPopupOpen()
    {
        threeOrTewlveLeadPopup.open()
    }

    Popup{
        id:threeOrTewlveLeadPopup
        x:860
        y:425
        width:200
        height: 140
        font.bold : true
        font.pixelSize: 38
        ColumnLayout
        {
            anchors.fill:parent

            Text{
                id:threeLeads
                text:"3导联"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsType = 1;
                        m3DataControl.leadsShowType = 0;
                        show_M3.ecgShowSource  = "qrc:/SPO2AndOnly3LeadsShow.qml"
                        resetAllLeadOff() //复位所有的导联显示
                        threeOrTewlveLeadPopup.close()

                    }
                }
            }
            Text{
                text:"12导联"
                id:twelveLeads
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                opacity: 1
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        m3DataControl.leadsType = 0;
                        m3DataControl.leadsShowType = 0;
                        show_M3.ecgShowSource  = "qrc:/SPO2And3LeadsShow.qml"
                        resetAllLeadOff() //复位所有的导联显示
                        threeOrTewlveLeadPopup.close()
                    }
                }
            }
        }
        onClosed: {
            console.log("closed")
        }
        closePolicy: Popup.CloseOnReleaseOutside

    }
    function dateAndTimeSetPopOpen()
    {
        dateTimeSetPop.open()
        // dateInputPanel.visible = true
        windowInputpanel.visible = true
        //        yearField.focus = false
        //        monthFiled.focus = false
        //        dayfiled.focus = false
        //        hourFiled.focus = false
        //        minuteFiled.focus = false
        //        secondFiled.focus = false
    }
    Popup{
        id:dateTimeSetPop
        x:165
        y:80
        width: 540
        height: 300
        //margins: 0
        padding: 0
        property var yearValue: 0
        property var monthValue: 0
        property var dayValue: 0
        property var hourValue: 0
        property var minuteValue: 0
        property var secondValue: 0
        Rectangle {
            width: 540
            height: 300

            x:0
            y:0
            color: "#D8D8D8"
            border.width: 1
            Rectangle {
                id: dateTitle
                x: 0
                y: 0
                width: 540
                height: 64
                color: "#3F4247"

                Text {
                    id: titleTxt
                    x: 156
                    y: 11
                    width: 229
                    height: 43
                    text: qsTr("时间和日期")
                    color: "#ffffff"
                    font.pixelSize: 38
                    font.letterSpacing: 4
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }

            TextField {
                id: yearField
                x: 27
                y: 133
                width: 70
                height: 34
                text: "2023"
                placeholderText: qsTr("2023")
                font.pixelSize: 20
                font.letterSpacing: 1
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 4  //最多输入4位数
                validator: IntValidator{ bottom: 1970; top: 9999; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.yearValue = Number(text)
                        if(dateTimeSetPop.yearValue<2024)
                        {
                            text = "2023"
                            dateTimeSetPop.yearValue = 2024
                        }
                    }
                }
            }

            TextField {
                id: monthFiled
                x: 124
                y: 133
                width: 45
                height: 34
                text: "09"
                placeholderText: qsTr("09")
                font.pixelSize: 20
                font.letterSpacing: 2
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 2  //最多输入2位数
                validator: IntValidator{ bottom: 1; top: 12; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.monthValue = Number(text)
                        if((dateTimeSetPop.monthValue>12)||(dateTimeSetPop.monthValue<1))
                        {
                            text = "0"
                        }
                        if((dateTimeSetPop.monthValue>=0)&&(dateTimeSetPop.monthValue<=9))
                        {
                            text = "0"+dateTimeSetPop.monthValue.toString()
                        }
                    }
                }
            }

            TextField {
                id: dayfiled
                x: 201
                y: 133
                width: 45
                height: 34
                text: "14"
                placeholderText: qsTr("14")
                font.pixelSize: 20
                font.letterSpacing: 2
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 2  //最多输入2位数
                validator: IntValidator{ bottom: 2; top: 31; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.dayValue = Number(text)
                        if((dateTimeSetPop.dayValue>31)||(dateTimeSetPop.dayValue<0))
                        {
                            text = "0"
                        }
                        if((dateTimeSetPop.dayValue>=0)&&(dateTimeSetPop.dayValue<=9))
                        {
                            text = "0"+dateTimeSetPop.dayValue.toString()
                        }
                    }
                }
            }

            Text {
                id: lineTxt
                x: 90
                y: 144
                width: 24
                height: 12
                text: qsTr("—")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: text3
                x: 171
                y: 144
                width: 24
                height: 12
                text: qsTr("—")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: yeadText
                x: 34
                y: 106
                width: 44
                height: 21
                text: qsTr("年")
                font.pixelSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: monthText
                x: 128
                y: 106
                width: 29
                height: 21
                text: qsTr("月")
                font.pixelSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: dateText
                x: 210
                y: 106
                width: 25
                height: 21
                text: qsTr("日")
                font.pixelSize: 20
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: hourFiled
                x: 307
                y: 133
                width: 45
                height: 34
                text: "10"
                font.letterSpacing: 1
                font.pixelSize: 20
                placeholderText: qsTr("10")
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 2  //最多输入2位数
                validator: IntValidator{ bottom: 0; top: 23; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.hourValue = Number(text)
                        if((dateTimeSetPop.hourValue>59)||(dateTimeSetPop.hourValue<0))
                        {
                            text = "0"
                        }
                        if((dateTimeSetPop.hourValue>=0)&&(dateTimeSetPop.hourValue<=9))
                        {
                            text = "0"+dateTimeSetPop.hourValue.toString()
                        }
                    }
                }

            }

            TextField {
                id: minuteFiled
                x: 387
                y: 133
                width: 45
                height: 34
                text: "48"
                font.letterSpacing: 2
                font.pixelSize: 20
                placeholderText: qsTr("48")
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 2  //最多输入2位数
                validator: IntValidator{ bottom: 0; top: 59; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.minuteValue = Number(text)
                        if((dateTimeSetPop.minuteValue>59)||(dateTimeSetPop.minuteValue<0))
                        {
                            text = "0"
                        }
                        if((dateTimeSetPop.minuteValue>=0)&&(dateTimeSetPop.minuteValue<=9))
                        {
                            text = "0"+dateTimeSetPop.hour.toString()
                        }
                    }
                }
            }

            TextField {
                id: secondFiled
                x: 468
                y: 133
                width: 45
                height: 34
                text: "03"
                font.letterSpacing: 2
                font.pixelSize: 20
                placeholderText: qsTr("03")
                inputMethodHints: Qt.ImhDigitsOnly
                maximumLength: 2  //最多输入2位数
                validator: IntValidator{ bottom: 0; top: 59; } //只能输入1970~9999之间的数
                onFocusChanged: {
                    if(focus === true)
                    {
                        //dateInputPanel.visible =true
                    }
                    else{
                        //dateInputPanel.visible =false
                        dateTimeSetPop.secondValue = Number(text)
                        if((dateTimeSetPop.secondValue>59)||(dateTimeSetPop.secondValue<0))
                        {
                            text = "0"
                        }
                        if((dateTimeSetPop.secondValue>=0)&&(dateTimeSetPop.secondValue<=9))
                        {
                            text = "0"+dateTimeSetPop.secondValue.toString()
                        }
                    }
                }
            }

            Text {
                id: text7
                x: 357
                y: 144
                width: 24
                height: 12
                text: qsTr(":")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: text8
                x: 438
                y: 144
                width: 24
                height: 12
                text: qsTr(":")
                font.pixelSize: 12
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: hourText
                x: 301
                y: 106
                width: 44
                height: 21
                font.pixelSize: 20
                text: qsTr("时")
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            Text {
                id: minuteText
                x: 391
                y: 106
                width: 29
                height: 21
                text: qsTr("分")
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            Text {
                id: secondText
                x: 476
                y: 106
                width: 25
                height: 21
                text: qsTr("秒")
                font.pixelSize: 20
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }

            Rectangle {
                id: dateCancelBtn
                x: 0
                y: 245
                width: 270
                height: 55
                color: "#D8D8D8"
                border.width: 1
                Text {
                    id: dateCancelText
                    anchors.fill: parent
                    text: qsTr("取消")
                    font.pixelSize: 30
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    width: 270 //取消按键按下
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    onClicked: {
                        //passCodeField.focus = false
                        dateTimeSetPop.close()
                    }
                }
            }

            Rectangle {
                id: confirmBtn
                x: 270
                y: 245
                width: 270
                height: 55
                color: "#3f4247"

                Text {
                    id: dateConfimTxt

                    anchors.fill: parent
                    text: qsTr("确定")
                    font.pixelSize: 30
                    font.bold: true
                    color: "#ffffff"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    //确认按键按下
                    // var timeString
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    onClicked: {
                        //console.log("设置的时间是："+yearField.text+"-"+monthFiled.text+"-"+dayfiled.text+" "+hourFiled.text+":"+minuteFiled.text+":"+secondFiled.text)
                        //var process =  Qt.createQProcess
                        m3DataControl.dateAndTime = yearField.text+"-"+monthFiled.text+"-"+dayfiled.text+" "+hourFiled.text+":"+minuteFiled.text+":"+secondFiled.text
                        //title.date =
                        title.time = hourFiled.text+":"+minuteFiled.text+":"+secondFiled.text
                        dateTimeSetPop.close()
                    }
                }
            }
        }
        onClosed: {
            windowInputpanel.visible = false
        }
        closePolicy: Popup.CloseOnEscape
        //        InputPanel{
        //            id:dateInputPanel
        //            visible: false
        //            y:400
        //            //width: 400
        //            //anchors.left: parent.left
        //            //anchors.right:parent.right
        //            anchors.left: parent.left
        //            anchors.right:parent.right
        //            //            anchors.left: show_M3.left
        //            //            anchors.right:show_M3.right
        //            //            anchors.bottom: show_M3.bottom
        //            anchors.top: parent.bottom
        //            height: 170
        //            onActiveChanged: {
        //                if(!active){
        //                    visible = false;
        //                }

        //            }
        //        }

        //closePolicy: Popup.CloseOnReleaseOutside
    }

    ListModel{
        id:warnList
        //        ListElement {
        //            occurrtime:"19.03"
        //            content:"SPO2传感器脱落"
        //        }

        //        ListElement {
        //            occurrtime:"19.44"
        //            content: "心动过速"

        //        }

        //        ListElement {
        //            occurrtime:"19.45"
        //            content:"心动过缓"

        //        }

        //        ListElement {
        //            occurrtime:"20.11"
        //            content:"导联脱落"
        //        }
    }
    function warnListAddElement(time,cont) //第一个参数是发生时间 第二个参数是报警内容
    {
        var data = {occurrtime:time,content:cont}
        warnList.append(data) //向历史列表添加一组历史数据
    }
    function warnListRemoveElement(cont)//根据内容移除某条报警记录
    {
        var len  = warnList.count //获取报警记录的长度
        var index ;
        for(var i = 0;i<len;i++)
        {
            var data = warnList.get(i)
            if(data.content === cont)
            {
                index = i
                break;
            }
        }
        warnList.remove(index,1)
    }



    function loadCompleted() //所有的组件加载完成
    {
        m3DataControl.uiLoadCompleted();
    }





    function wlanPassCodeSetPopOpen() //Wifi密码输入框打开函数
    {
        wlanPassCodeSetPop.open()
        passCodeInput.text = qsTr("")
        ssidTxt.text = wlanSSID
        windowInputpanel.visible = true //密码可见
        passCodeInput.echoMode = TextInput.Normal //输入框显示正常
        passCodeInput.placeholderText = qsTr("请点击输入密码")
    }

    Popup{  //wifi输入密码框
        id:wlanPassCodeSetPop
        x:200
        y:80
        width: 540
        height: 300
        //margins: 0
        padding: 0
        Rectangle {
            width: 540
            height: 300

            x:0
            y:0
            color: "#D8D8D8"
            border.width: 1
            Rectangle {
                id: passCodeTitle
                x: 0
                y: 0
                width: 540
                height: 64
                color: "#3F4247"

                Text {
                    id: wlanPCTitel
                    x: 156
                    y: 11
                    width: 229
                    height: 43
                    text: qsTr("请输入密码")
                    color: "#ffffff"
                    font.pixelSize: 38
                    font.letterSpacing: 4
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
            }



            Text {
                id: ssid
                x: 51
                y: 89
                width: 77
                height: 39
                text: qsTr("SSID:")
                font.pixelSize: 26
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: ssidTxt
                x: 142
                y: 89
                width: 374
                height: 39
                text: qsTr("")
                font.pixelSize: 25
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: passCode
                x: 51
                y: 154
                width: 77
                height: 39
                text: qsTr("密码:")
                font.pixelSize: 26
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            TextField {
                id: passCodeInput
                x: 142
                y: 154
                width: 312//374
                height: 39
                text: qsTr("")
                font.pixelSize: 25
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                placeholderText: qsTr("请点击输入密码")
            }
            CheckBox{
                id:showOrnot
                x: 460
                y: 154
                text: "可见"
                width: 63
                height: 39
                checked:true
                onCheckedChanged: {
                    //console.log("checked = ",showOrnot.checked)
                    if(showOrnot.checked)
                    {
                        passCodeInput.echoMode = TextInput.Normal
                    }
                    else
                    {
                        passCodeInput.echoMode = TextInput.Password
                    }
                }
            }


            Rectangle {
                id: wlanPCCancelBtn
                x: 0
                y: 245
                width: 270
                height: 55
                color: "#D8D8D8"
                border.width: 1
                Text {
                    id: wlanPCCancelText
                    anchors.fill: parent
                    text: qsTr("取消")
                    font.pixelSize: 30
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    width: 270 //取消按键按下
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    onClicked: {
                        //passCodeField.focus = false

                        wlanPassCodeSetPop.close()
                    }
                }
            }

            Rectangle {
                id: wlanPCConfirmBtn
                x: 270
                y: 245
                width: 270
                height: 55
                color: "#3f4247"

                Text {
                    id: wlanPCConfimTxt

                    anchors.fill: parent
                    text: qsTr("确定")
                    font.pixelSize: 30
                    font.bold: true
                    color: "#ffffff"
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                }
                MouseArea {
                    //确认按键按下
                    // var timeString
                    anchors.fill: parent
                    anchors.rightMargin: 0
                    anchors.bottomMargin: 0
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    onClicked: {


                        //将密码和要联接的wifi的名字传递给 M3ShowController类
                        m3DataControl.connectWifi(ssidTxt.text,passCodeInput.text)
                        wlanPassCodeSetPop.close()
                    }
                }
            }
        }
        onClosed: {
            windowInputpanel.visible = false
        }
        closePolicy: Popup.CloseOnEscape
    }


    function netLanStateDialogOpen()
    {
        netLanStateDialog.open() //后续添加网络的信息
        macAddresstxt.text = m3DataControl.lanMacAddress
        ipAddresstxt.text = m3DataControl.lanIPAddress
        netGatetxt.text = m3DataControl.lanNetGate
        netMasktxt.text = m3DataControl.lanNetMask
    }



    Popup{
        id:netLanStateDialog  //有线网络信息显示框
        width: 541
        height: 300
        x:165
        y:200


        topPadding: 0
        bottomPadding: 0
        leftPadding: 0
        rightPadding: 0


        Rectangle {
            id:lan
            anchors.fill:parent
            color:"#3F4247"
            //signal adultOrChildChecked //上传选择信息
            property int checkedIndex: 0
            Text {
                id: lanTitle
                x: 182
                y: 0
                width: 177
                height: 64
                text: qsTr("有线网络信息")
                color: "#ffffff"
                font.pixelSize: 40
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Rectangle {
                id: lanCloseButon
                x: 20
                y: 15
                width: 50
                height: 50
                color: "#ffffff"
                radius:5

                Image {
                    id: lanCloseImage
                    x: 0
                    y: 0
                    width: 50
                    height: 50
                    source: "img/CloseButton.png"
                    fillMode: Image.PreserveAspectFit
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        netLanStateDialog.close();
                    }
                }
            }
            Rectangle {
                id: netLanContent
                x: 0
                y: 71
                width: 541
                height: 229
                color: "#EAECEA"

                Text {
                    id: macAddresstxt
                    x: 198
                    y: 17
                    width: 275
                    height: 30
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: ipAddresstxt
                    x: 198
                    y: 69
                    width: 275
                    height: 30
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: netGatetxt
                    x: 198
                    y: 123
                    width: 275
                    height: 30
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: netMasktxt
                    x: 198
                    y: 177
                    width: 275
                    height: 30
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: macAddress
                    x: 62
                    y: 17
                    width: 96
                    height: 30
                    text: qsTr("MAC地址：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: ipAddress
                    x: 62
                    y: 69
                    width: 96
                    height: 30
                    text: qsTr("IP地址：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: netGate
                    x: 62
                    y: 123
                    width: 96
                    height: 30
                    text: qsTr("网关：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: netMask
                    x: 62
                    y: 177
                    width: 96
                    height: 30
                    text: qsTr("子网掩码：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                }
            }

        }
        Component.onCompleted: { //组件加载完成

        }
        closePolicy: Popup.CloseOnPressOutside
    }


    function netWlanStateDialogOpen()
    {
        netWlanStateDialog.open() //后续添加网络的信息
        wlanMacAddressTxt.text = m3DataControl.wlanMacAddress
        wlanIPAddressTxt.text = m3DataControl.wlanIPAddress
        wifiNameTxt.text = m3DataControl.connectedWIFIName  //当前连接的WIFI名字
    }



    Popup{
        id:netWlanStateDialog  //有线网络信息显示框
        width: 541
        height: 300
        x:165
        y:200


        topPadding: 0
        bottomPadding: 0
        leftPadding: 0
        rightPadding: 0


        Rectangle {
            id:wlan
            anchors.fill:parent
            color:"#3F4247"
            signal adultOrChildChecked //上传选择信息
            property int checkedIndex: 0
            Text {
                id: wlanTitle
                x: 182
                y: 0
                width: 177
                height: 64
                text: qsTr("无线网络信息")
                color: "#ffffff"
                font.pixelSize: 40
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Rectangle {
                id: wlanCloseButon
                x: 20
                y: 15
                width: 50
                height: 50
                color: "#ffffff"
                radius:5

                Image {
                    id: wlanCloseImage
                    x: 0
                    y: 0
                    width: 50
                    height: 50
                    source: "img/CloseButton.png"
                    fillMode: Image.PreserveAspectFit
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {

                        netWlanStateDialog.close();
                    }
                }
            }
            Rectangle {
                id: netwLanContent
                x: 0
                y: 71
                width: 541
                height: 229
                color: "#EAECEA"


                Text {
                    id: wifiName
                    x: 60
                    y: 40
                    width: 107
                    height: 34
                    text: qsTr("WIFI：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: wlanMacAddress
                    x: 60
                    y: 98
                    width: 107
                    height: 34
                    text: qsTr("MAC地址：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: wlanipAddress
                    x: 60
                    y: 155
                    width: 107
                    height: 34
                    text: qsTr("IP地址：")
                    font.pixelSize: 17
                    horizontalAlignment: Text.AlignRight
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: wifiNameTxt
                    x: 229
                    y: 40
                    width: 285
                    height: 34
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: wlanMacAddressTxt
                    x: 229
                    y: 98
                    width: 285
                    height: 34
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: wlanIPAddressTxt
                    x: 229
                    y: 155
                    width: 285
                    height: 34
                    text: qsTr("")
                    font.pixelSize: 16
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
            }

        }
        Component.onCompleted: { //组件加载完成
            m3DataControl.connectedWIFINameChanged.connect(updataWIFIName)
        }
//        Component.onDestroyed: {
//            m3DataControl.connectedWIFINameChange.disconnect(updataWIFIName)
//        }
        function updataWIFIName()
        {
            wifiNameTxt.text = m3DataControl.connectedWIFIName  //当前连接的WIFI名字
        }
        closePolicy: Popup.CloseOnPressOutside
    }




}




/*##^##
Designer {
    D{i:0;formeditorZoom:0.5}
}
##^##*/
