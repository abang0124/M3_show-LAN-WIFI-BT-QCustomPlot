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
    property int leadsPageIndex : 0                //用来标志显示的页面
    property bool  replaceFlag: false

    property int ecgDataCount: 0
    property string  filterstring: ''
    property var threeLeadsArray:[0]  //3导联基线数组

    Rectangle {
        id: up
        x: 0
        y: 9
        z: 10
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
               // threeLeadsUpClicked()
                if(lead1txt.text == "I")
                {
                    lead1txt.text = "V4"
                    lead2txt.text = "V5"
                    lead3txt.text = "V6"
                    leadsPageIndex = 3
                }
                else if(lead1txt.text == "aVR")
                {
                      lead1txt.text = "I"
                      lead2txt.text = "II"
                      lead3txt.text = "III"
                      leadsPageIndex = 0
                }
                else if(lead1txt.text == "V1")
                {
                      lead1txt.text = "aVR"
                      lead2txt.text = "aVL"
                      lead3txt.text = "aVF"
                      leadsPageIndex = 1
                }
                else if(lead1txt.text == "V4")
                {
                    lead1txt.text = "V1"
                    lead2txt.text = "V2"
                    lead3txt.text = "V3"
                    leadsPageIndex = 2
                }
                leadOffShow(leadsPageIndex)
                clearAllLines()

                replaceFlag = false


            }

        }
    }

    Rectangle {

        id: down
        x: 0
        y: 298//268
        z: 10
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
              //  threeLeadsDownClicked()
                if(lead1txt.text == "I")
                {
                    lead1txt.text = "aVR"
                    lead2txt.text = "aVL"
                    lead3txt.text = "aVF"
                    leadsPageIndex = 1

                }
                else if(lead1txt.text == "aVR")
                {
                    lead1txt.text = "V1"
                    lead2txt.text = "V2"
                    lead3txt.text = "V3"
                    leadsPageIndex = 2
                }
                else if(lead1txt.text == "V1")
                {
                    lead1txt.text = "V4"
                    lead2txt.text = "V5"
                    lead3txt.text = "V6"
                    leadsPageIndex = 3
                }
                else if(lead1txt.text == "V4")
                {
                    lead1txt.text = "I"
                    lead2txt.text = "II"
                    lead3txt.text = "III"
                    leadsPageIndex = 0
                }
                clearAllLines()
                leadOffShow(leadsPageIndex)
                replaceFlag = false


            }

        }
    }



    Text {
        id: leadOff1
        x: 331
        y: 50
        z: 10
        width: 158
        height: 48
        text: qsTr("导联脱落")
        color: "yellow"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }
    Text {
        id: leadOff2
        x: 331
        y: 200
        z: 10
        width: 158
        height: 48
        text: qsTr("导联脱落")
        color: "yellow"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }
    Text {
        id: leadOff3
        x: 331
        y: 360
        z: 10
        width: 158
        height: 48
        text: qsTr("导联脱落")
        color: "yellow"
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 28
    }

    Text {
        id: speedAndGainText
        x: 81
        y: 8
        z: 10
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
        z: 10
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
        x: 65
        y: 140
        z: 10
        width: 30
        text: qsTr("I")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead2txt
        x: 65
        y: 267
        z: 10
        width: 30
        text: qsTr("II")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead3txt
        x: 65
        y: 420
        z: 10
        width: 30
        text: qsTr("III")
        font.pixelSize: 20
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
            id: threeCustomPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                initCustomPlot_3Lead(m3DataControl.gainType,m3DataControl.speedType)
            }
        }
    }
    Component.onCompleted: {     //3导联显示界面加载完成
        //m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //m3DataControl.list_ECG_data_show_changed.connect(openTimerAndSendBackSignal)
        m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
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


        //calcultaXthreeLeadsSubLevel()
        //leads3ShowBaselineYCalculate()//计算要显示导联的Y轴方向的基值
        console.log("3leads load completed")
        m3DataControl.clearECGData();

    }

    Component.onDestruction:  {
        m3DataControl.setGetECGDataTimerFlagFalse(); //将定时器开关的标志位置为假
        m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
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
         console.log("3leads load show destroyed")
    }
    //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
    //m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
    function ecgShowStopOrnot()
    {
        if(m3DataControl.ecgShowStopFlag === true)
        {
            readECGDataTimer.running = false;//关闭定时器
            m3DataControl.setGetECGDataTimerFlagFalse();
            //console.log("close Timer")
        }

        //console.log("Recive Signal")
    }
    function leadOffShowChanged() //导联脱落显示
    {
        if(leadsPageIndex == 0) //加载时为第一页面显示 I II III
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        else if(leadsPageIndex == 1)//加载时为第一页面 aVR aVL aVF
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //任何一个导联脱落，第二页面导联全部显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        else if(leadsPageIndex == 2)//加载时为第一页面//
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffV1 === true)
            {
                leadOff1.visible = true
            }
            if(m3DataControl.leadsOffV2 === true)
            {
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffV3 === true)
            {
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }

        }
        else if(leadsPageIndex == 3)//加载时为第一页面
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffV4 === true)
            {
                leadOff1.visible = true
            }
            if(m3DataControl.leadsOffV5 === true)
            {
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffV6 === true)
            {
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        leadOff1.z = 10
        leadOff2.z = 10
        leadOff3.z = 10
    }

    function leadOffShow(leadPage) //导联脱落显示
    {
        if(leadPage  === 0) //加载时为第一页面显示 I II III
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        else if(leadPage === 1)//加载时为第一页面 aVR aVL aVF
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if((m3DataControl.leadsOffRA === true)||(m3DataControl.leadsOffLA === true)||(m3DataControl.leadsOffLL === true)||(m3DataControl.leadsOffRL === true)) //任何一个导联脱落，第二页面导联全部显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        else if(leadPage === 2)//加载时为第一页面//
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffV1 === true)
            {
                leadOff1.visible = true
            }
            if(m3DataControl.leadsOffV2 === true)
            {
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffV3 === true)
            {
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }

        }
        else if(leadPage === 3)//加载时为第一页面
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            if(m3DataControl.leadsOffV4 === true)
            {
                leadOff1.visible = true
            }
            if(m3DataControl.leadsOffV5 === true)
            {
                leadOff2.visible = true
            }
            if(m3DataControl.leadsOffV6 === true)
            {
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRL === true)
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
            }
        }
        leadOff1.z = 10
        leadOff2.z = 10
        leadOff3.z = 10
    }
    function calcultaXthreeLeadsSubLevel() //计算X轴每断线的要显示的点数.val为轴的长度
    {
        //var num = ((valueAxisX.max)/(splinesLead3Array.length))
//        for(var i = 0;i< splinesLead3Array.length ;i++)
//        {
//            threeLeadsSubLevel[i] = num*i
//            console.log("threeLeadsSubLevel["+i+"] ="+threeLeadsSubLevel[i])
//        }
    }


    function on_receive_ecg_show_data()
    {

        if(leadsPageIndex == 0) //第1页面 I,II,III导联显示
        {
//            threeLeadsArray[0] = m3DataControl.leadIBaseLine;
//            threeLeadsArray[1] = m3DataControl.leadIIBaseLine;
            threeLeadsArray[0] = m3DataControl.leadIBaseLine;
            threeLeadsArray[1] = m3DataControl.leadIIBaseLine;
            threeLeadsArray[2] = m3DataControl.leadIIIBaseLine;
//            threeLeadsArray[3] = m3DataControl.leadIMaxLine;
//            threeLeadsArray[4] = m3DataControl.leadIIMaxLine;
            threeLeadsArray[3] = m3DataControl.leadIMaxLine;
            threeLeadsArray[4] = m3DataControl.leadIIMaxLine;
            threeLeadsArray[5] = m3DataControl.leadIIIMaxLine;
            threeCustomPlot.ecg_Y_BaseLine3(threeLeadsArray)
            threeCustomPlot.update3LeadsShow(m3DataControl.getECGShowArray(0),m3DataControl.getECGShowArray(1),m3DataControl.getECGShowArray(2))

        }
        else if(leadsPageIndex == 1) //第1页面 aVR,aVL,aVF导联显示
        {
            threeLeadsArray[0] = m3DataControl.leadaVRBaseLine;
            threeLeadsArray[1] = m3DataControl.leadaVLBaseLine;
            threeLeadsArray[2] = m3DataControl.leadaVFBaseLine;
            threeLeadsArray[3] = m3DataControl.leadaVRMaxLine;
            threeLeadsArray[4] = m3DataControl.leadaVLMaxLine;
            threeLeadsArray[5] = m3DataControl.leadaVFMaxLine;
            threeCustomPlot.ecg_Y_BaseLine3(threeLeadsArray)
            threeCustomPlot.update3LeadsShow(m3DataControl.getECGShowArray(3),m3DataControl.getECGShowArray(4),m3DataControl.getECGShowArray(5))

        }
        else if(leadsPageIndex == 2) //第1页面 V1,V2,V3导联显示
        {
            threeLeadsArray[0] = m3DataControl.leadV1BaseLine;
            threeLeadsArray[1] = m3DataControl.leadV2BaseLine;
            threeLeadsArray[2] = m3DataControl.leadV3BaseLine;
            threeLeadsArray[3] = m3DataControl.leadV1MaxLine;
            threeLeadsArray[4] = m3DataControl.leadV2MaxLine;
            threeLeadsArray[5] = m3DataControl.leadV3MaxLine;
            threeCustomPlot.ecg_Y_BaseLine3(threeLeadsArray)
            threeCustomPlot.update3LeadsShow(m3DataControl.getECGShowArray(6),m3DataControl.getECGShowArray(7),m3DataControl.getECGShowArray(8))

        }
        else if(leadsPageIndex == 3) //第1页面 V4,V5,V6导联显示
        {
            threeLeadsArray[0] = m3DataControl.leadV4BaseLine;
            threeLeadsArray[1] = m3DataControl.leadV5BaseLine;
            threeLeadsArray[2] = m3DataControl.leadV6BaseLine;
            threeLeadsArray[3] = m3DataControl.leadV4MaxLine;
            threeLeadsArray[4] = m3DataControl.leadV5MaxLine;
            threeLeadsArray[5] = m3DataControl.leadV6MaxLine;
            threeCustomPlot.ecg_Y_BaseLine3(threeLeadsArray)
            threeCustomPlot.update3LeadsShow(m3DataControl.getECGShowArray(9),m3DataControl.getECGShowArray(10),m3DataControl.getECGShowArray(11))

        }
        m3DataControl.showOverAndClear()
    }


    function clearAllLines()
    {
        for(var i=0;i<threeLeadsSplineSeriesArray.length;i++)
        {
            for(var j=0;j<threeLeadsSplineSeriesArray[i].length;j++)
            {
                threeLeadsSplineSeriesArray[i][j].clear()
            }
        }
    }




}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25;height:518;width:880}
}
##^##*/
