import QtQuick 2.12
import QtCharts 2.3
import QtQml 2.12   //使用定时器
import CustomPlot 1.0
Rectangle {
    id:test
    width:880
    height: 548//518
    color: "#000000"
    signal threeLeadsUpClicked                     //3导联显示，向上的按键
    signal threeLeadsDownClicked                    //3导联显示，向下的按键
    property alias speedAndGaintxt:speedAndGainText.text         //关于显示速度相关的信息
    property alias filtertxt: filterText.text      //关于滤波器相关的信息
//    property alias minOfX: valueAxisX.min          //x轴的最小值
//    property alias maxOfX: valueAxisX.max          //x轴的最大值
//    property alias minOfY: valueAxisY.min          //Y轴的最小值
//    property alias maxOfY: valueAxisX.max          //Y轴的最大值
    property alias lead1Name:lead1txt.text         //第1个导联的名字

    property int leadsPageIndex : 0                //用来标志显示的页面
    property bool  replaceFlag: false
    property int current:0

//    property var leadY1 : [2000]
//    property var leadY2 : [2000]
//    property var leadY3 : [2000]

    property int ecgDataCount: 0
    property string  filterstring: ''


    property var factor: 0.01

    property var oneLeadArray:[2]

    Rectangle {
        id: up
        x: 0
        y: 9
        width: 60
        height: 250
        color: "#585858"
        radius: 10
        Image {
            id: image
            x: 8
            y: 104
            width: 44
            height: 44
            verticalAlignment: Image.AlignVCenter
            source: "img/up.png"
            fillMode: Image.PreserveAspectFit
        }
        MouseArea{
            id:upBtn
            anchors.fill:parent
            onClicked: {
                //threeLeadsUpClicked()
                if(lead1txt.text == "I")
                {
                    lead1txt.text = "V6"
                    leadsPageIndex = 11
                }
                else if(lead1txt.text == "V6")
                {
                      lead1txt.text = "V5"
                      leadsPageIndex = 10
                }
                else if(lead1txt.text == "V5")
                {
                      lead1txt.text = "V4"
                      leadsPageIndex = 9
                }
                else if(lead1txt.text == "V4")
                {
                      lead1txt.text = "V3"
                      leadsPageIndex = 8
                }
                else if(lead1txt.text == "V3")
                {
                      lead1txt.text = "V2"
                      leadsPageIndex = 7
                }
                else if(lead1txt.text == "V2")
                {
                      lead1txt.text = "V1"
                      leadsPageIndex = 6
                }
                else if(lead1txt.text == "V1")
                {
                      lead1txt.text = "aVF"
                      leadsPageIndex = 5
                }
                else if(lead1txt.text == "aVF")
                {
                      lead1txt.text = "aVL"
                      leadsPageIndex = 4
                }
                else if(lead1txt.text == "aVL")
                {
                      lead1txt.text = "aVR"
                      leadsPageIndex = 3
                }
                else if(lead1txt.text == "aVR")
                {
                      lead1txt.text = "III"
                      leadsPageIndex = 2
                }
                else if(lead1txt.text == "III")
                {
                      lead1txt.text = "II"
                      leadsPageIndex = 1
                }
                else if(lead1txt.text == "II")
                {
                      lead1txt.text = "I"
                      leadsPageIndex = 0
                }
                leadOffShow(leadsPageIndex)
                //clearAllLines()

                //replaceFlag = false

                //current = 0
            }

        }
    }

    Rectangle {
        id: down
        x: 0
        y: 298//268
        width: 60
        height: 250
        color: "#585858"
        radius: 10
        Image {
            id: image1
            x: 8
            y: 103
            width: 44
            height: 44
            source: "img/down.png"
            fillMode: Image.PreserveAspectFit
        }
        MouseArea{
            id:downBtn
            anchors.fill:parent
            onClicked: {

                if(lead1txt.text == "I")
                {
                    lead1txt.text = "II"
                    leadsPageIndex = 1
                }
                else if(lead1txt.text == "II")
                {
                      lead1txt.text = "III"
                      leadsPageIndex = 2
                }
                else if(lead1txt.text == "III")
                {
                      lead1txt.text = "aVR"
                      leadsPageIndex = 3
                }
                else if(lead1txt.text == "aVR")
                {
                      lead1txt.text = "aVL"
                      leadsPageIndex = 4
                }
                else if(lead1txt.text == "aVL")
                {
                      lead1txt.text = "aVF"
                      leadsPageIndex = 5
                }
                else if(lead1txt.text == "aVF")
                {
                      lead1txt.text = "V1"
                      leadsPageIndex = 6
                }
                else if(lead1txt.text == "V1")
                {
                      lead1txt.text = "V2"
                      leadsPageIndex = 7
                }
                else if(lead1txt.text == "V2")
                {
                      lead1txt.text = "V3"
                      leadsPageIndex = 8
                }
                else if(lead1txt.text == "V3")
                {
                      lead1txt.text = "V4"
                      leadsPageIndex = 9
                }
                else if(lead1txt.text == "V4")
                {
                      lead1txt.text = "V5"
                      leadsPageIndex = 10
                }
                else if(lead1txt.text == "V5")
                {
                      lead1txt.text = "V6"
                      leadsPageIndex = 11
                }
                else if(lead1txt.text == "V6")
                {
                      lead1txt.text = "I"
                      leadsPageIndex = 0
                }
                leadOffShow(leadsPageIndex)
                //clearAllLines()

                //replaceFlag = false

                //current = 0

            }

        }
    }


   //第一行要显示的导联数据

    Text {
        id: leadOff1
        x: 331
        y: 45
        z: 1
        width: 158
        height: 48
        text: qsTr("导联脱落")
        verticalAlignment: Text.AlignVCenter
        color: "yellow"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 39
    }

    Text {
        id: speedAndGainText
        x: 81
        y: 8
        z: 1
        width: 164
        height: 29
        text: qsTr("25mm/s,10mm/mv")
        color: "#ffffff"
        font.pixelSize: 20
        font.bold: true
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: filterText
        x: 637
        y: 9
        z: 1
        width: 227
        height: 28
        text: qsTr("LP150Hz,AC50Hz")
        font.pixelSize: 20
        color: "#ffffff"
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        id: lead1txt
        x: 66
        y: 79
        z: 1
        width: 48
        height: 46
        text: qsTr("I")
        font.pixelSize: 39
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Item{
        x:100
        y:0
        width: 780
        height:548
        CustomPlotItem {
            id: oneCustomPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                initCustomPlot_1Lead(m3DataControl.gainType,m3DataControl.speedType)
            }
        }
    }


    Component.onCompleted: {     //3导联显示界面加载完成
        //m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //m3DataControl.list_ECG_data_show_changed.connect(openTimerAndSendBackSigenal)
        //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
        m3DataControl.leadsOffRAChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffLAChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffV1Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffV2Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffV3Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffV4Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffV5Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffV6Change.connect(leadOffShowChanged)
        m3DataControl.leadsOffRLChange.connect(leadOffShowChanged)
        m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //current = 0
        //replaceFlag = false
        leadsPageIndex = 0  //12导联的4页面 3导联显示


        //if(m3DataControl.)

        //低通滤波
        if(m3DataControl.lpSelectIndex === 0)
        {
               filterstring = "LP 25Hz"
        }
        else if(m3DataControl.lpSelectIndex === 1)
        {
               filterstring   = "LP 40Hz"
        }
        else if(m3DataControl.lpSelectIndex === 2)
        {
               filterstring  = "LP 150Hz"
        }
        else if(m3DataControl.lpSelectIndex === 3)
        {
               filterstring = ''
        }

        //高通滤波
        if(m3DataControl.hpSelectIndex === 0)
        {
            if(filterstring == '')
            {
                filterstring  =  filterstring + "HP 0.05Hz"
            }
            else
            {
                filterstring  =  filterstring + ",HP 0.05Hz"
            }
        }
        else if(m3DataControl.hpSelectIndex === 1)
        {

            if(filterstring == '')
            {
                filterstring  =  filterstring + "HP 0.15Hz"
            }
            else
            {
                filterstring  =  filterstring + ",HP 0.15Hz"
            }
        }
        else if(m3DataControl.hpSelectIndex === 2)
        {
            if(filterstring == '')
            {
                filterstring  =  filterstring + "HP 0.3Hz"
            }
            else
            {
                filterstring  =  filterstring + ",HP 0.3Hz"
            }

        }
        else if(m3DataControl.hpSelectIndex === 3)
        {
            if(filterstring == '')
            {
                filterstring  =  filterstring + "HP 0.67Hz"
            }
            else
            {
                filterstring  =  filterstring + ",HP 0.67Hz"
            }
        }
        else if(m3DataControl.hpSelectIndex === 4)
        {
            filterstring  =  filterstring + ''
        }


        //电源滤波
        if(m3DataControl.acSelectIndex === 0)
        {
            if(filterstring == '')
            {
                filterstring  =  filterstring + "AC 50Hz"
            }
            else
            {
                filterstring  =  filterstring + ",AC 50Hz"
            }
        }
        else if(m3DataControl.acSelectIndex === 1)
        {
            if(filterstring == '')
            {
                filterstring  =  filterstring + "AC 60Hz"
            }
            else
            {
                filterstring  =  filterstring + ",AC 60Hz"
            }
        }
        else if(m3DataControl.acSelectIndex === 2)
        {

                filterstring  =  filterstring + ''

        }
        filterText.text = filterstring

        if(m3DataControl.gainType === 0)
        {
           speedAndGainText.text = "10mm/mv,";
           //valueAxisY.max = 6024  //经测量1mv的大概变化范围是 1003,整个屏幕曲线显示区间是60mm，所以10mm/mv ，Y的最大值是6018
        }
        else if(m3DataControl.gainType === 1)
        {
            speedAndGainText.text = "20mm/mv,";
            //valueAxisY.max = 3012  //经测量1mv的大概变化范围是 1003,整个屏幕曲线显示区间是60mm，所以20mm/mv ，Y的最大值是3012
        }
        else if(m3DataControl.gainType === 2)
        {
            speedAndGainText.text = "5mm/mv,";//经测量1mv的大概变化范围是 1003,整个屏幕曲线显示区间是60mm，所以5mm/mv ，Y的最大值是12048
            //valueAxisY.max = 12048   //每行显示高度为2000
        }


        if(m3DataControl.speedType === 0)
        {
            speedAndGainText.text = speedAndGainText.text + "25mm/s";
            //valueAxisX.max = 800
        }
        else if(m3DataControl.speedType === 1)
        {
            speedAndGainText.text = speedAndGainText.text + "50mm/s";
            //valueAxisX.max = 400
        }


        leadOffShow(leadsPageIndex) //导联脱落显示


        //calcultaXOneLeadSubLevel() //计算X轴的
        //lead1ShowBaselineYCalculate()//计算要显示导联的Y轴方向的基值
        console.log("1leads load completed")
        m3DataControl.clearECGData();

    }

    Component.onDestruction:  {
        m3DataControl.setGetECGDataTimerFlagFalse(); //将定时器开关的标志位置为假
        //m3DataControl.list_ECG_data_show_changed.disconnect(openTimerAndSendBackSigenal)
        //m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
        m3DataControl.leadsOffRAChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffLAChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV1Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV2Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV3Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV4Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV5Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffV6Change.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffRLChange.disconnect(leadOffShowChanged)
        m3DataControl.list_ECG_data_show_changed.disconnect(on_receive_ecg_show_data)
         console.log("1leads load show destroyed")
    }


    //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
    //m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
//    function ecgShowStopOrnot()
//    {
//        if(m3DataControl.ecgShowStopFlag === true)
//        {
//            readECGDataTimer.running = false;//关闭定时器
//            m3DataControl.setGetECGDataTimerFlagFalse();
//        }
//    }



    function leadOffShowChanged() //导联脱落显示
    {
        if(leadsPageIndex == 0) //加载时为第一页面显示 I
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffRL === true)) //RA,LA,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 1) //加载时为第一页面显示 II
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //RA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 2) //加载时为第一页面显示 III
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 3) //加载时为第一页面显示 aVR
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 4) //加载时为第一页面显示 aVL
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 5) //加载时为第一页面显示 aVF
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 6) //加载时为第一页面显示 V1
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV1 === true))  //RA,LA,LL,V1导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 7) //加载时为第一页面显示 V2
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV2 === true))  //RA,LA,LL,V2导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 8) //加载时为第一页面显示 V3
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV3 === true))  //RA,LA,LL,V3导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 9) //加载时为第一页面显示 V4
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV4 === true))  //RA,LA,LL,V4导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 10) //加载时为第一页面显示 V5
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV5 === true))  //RA,LA,LL,V5导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 11) //加载时为第一页面显示 V6
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV6 === true))  //RA,LA,LL,V1导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }


    }

    function leadOffShow(leadPage) //导联脱落显示
    {
        if(leadsPageIndex == 0) //加载时为第一页面显示 I
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffRL === true)) //RA,LA,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 1) //加载时为第一页面显示 II
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //RA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 2) //加载时为第一页面显示 III
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 3) //加载时为第一页面显示 aVR
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 4) //加载时为第一页面显示 aVL
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 5) //加载时为第一页面显示 aVF
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true))  //RA,LA,LL,RL导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 6) //加载时为第一页面显示 V1
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV1 === true))  //RA,LA,LL,V1导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 7) //加载时为第一页面显示 V2
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV2 === true))  //RA,LA,LL,V2导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 8) //加载时为第一页面显示 V3
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV3 === true))  //RA,LA,LL,V3导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 9) //加载时为第一页面显示 V4
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV4 === true))  //RA,LA,LL,V4导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 10) //加载时为第一页面显示 V5
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV5 === true))  //RA,LA,LL,V5导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
        else if(leadsPageIndex == 11) //加载时为第一页面显示 V6
        {
            leadOff1.visible = false

            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffV6 === true))  //RA,LA,LL,V1导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
            }

        }
    }


    function on_receive_ecg_show_data()
    {
        if(leadsPageIndex == 0)//I
        {
            oneLeadArray[0] = m3DataControl.leadIBaseLine;
            oneLeadArray[1] = m3DataControl.leadIMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(0))
        }
        else if(leadsPageIndex == 1) // II
        {
            oneLeadArray[0] = m3DataControl.leadIIBaseLine;
            oneLeadArray[1] = m3DataControl.leadIIMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(1))
        }
        else if(leadsPageIndex == 2) // III
        {
            oneLeadArray[0] = m3DataControl.leadIIIBaseLine;
            oneLeadArray[1] = m3DataControl.leadIIIMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(2))
        }
        else if(leadsPageIndex == 3) // aVR
        {
            oneLeadArray[0] = m3DataControl.leadaVRBaseLine;
            oneLeadArray[1] = m3DataControl.leadaVRMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(3))
        }
        else if(leadsPageIndex == 4) // aVL
        {
            oneLeadArray[0] = m3DataControl.leadaVLBaseLine;
            oneLeadArray[1] = m3DataControl.leadaVLMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(4))
        }
        else if(leadsPageIndex == 5) // aVF
        {
            oneLeadArray[0] = m3DataControl.leadaVFBaseLine;
            oneLeadArray[1] = m3DataControl.leadaVFMaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(5))
        }
        else if(leadsPageIndex == 6) // V1
        {
            oneLeadArray[0] = m3DataControl.leadV1BaseLine;
            oneLeadArray[1] = m3DataControl.leadV1MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(6))
        }
        else if(leadsPageIndex == 7) // V2
        {
            oneLeadArray[0] = m3DataControl.leadV2BaseLine;
            oneLeadArray[1] = m3DataControl.leadV2MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(7))
        }
        else if(leadsPageIndex == 8) // V3
        {
            oneLeadArray[0] = m3DataControl.leadV3BaseLine;
            oneLeadArray[1] = m3DataControl.leadV3MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(8))
        }
        else if(leadsPageIndex == 9) // V4
        {
            oneLeadArray[0] = m3DataControl.leadV4BaseLine;
            oneLeadArray[1] = m3DataControl.leadV4MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(9))
        }
        else if(leadsPageIndex == 10) // V5
        {
            oneLeadArray[0] = m3DataControl.leadV5BaseLine;
            oneLeadArray[1] = m3DataControl.leadV5MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(10))
        }
        else if(leadsPageIndex == 11) // V6
        {
            oneLeadArray[0] = m3DataControl.leadV6BaseLine;
            oneLeadArray[1] = m3DataControl.leadV6MaxLine;
            oneCustomPlot.ecg_Y_BaseLine1(oneLeadArray)
            oneCustomPlot.update1LeadsShow(m3DataControl.getECG1leadShowArray(11))
        }
        m3DataControl.showOverAndClear()
    }





}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25;height:518;width:880}
}
##^##*/
