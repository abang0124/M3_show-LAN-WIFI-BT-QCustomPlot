import QtQuick 2.12
import QtCharts 2.3
import QtQml 2.12   //使用定时器
import CustomPlot 1.0
Rectangle {
    id:test
    width:880
    height: 548//518
    color: "#000000"
    signal sixLeadsUpClicked                     //3导联显示，向上的按键
    signal sixLeadsDownClicked                    //3导联显示，向下的按键
    property alias speedtxt:speedAndGainText.text         //关于显示速度相关的信息
    property alias filtertxt: filterText.text      //关于滤波器相关的信息
    property alias lead1Name:lead1txt.text         //第1个导联的名字
    property alias lead2Name:lead2txt.text         //第2个导联的名字
    property alias lead3Name:lead3txt.text         //第3个导联的名字
    property alias lead4Name:lead4txt.text         //第4个导联的名字
    property alias lead5Name:lead5txt.text         //第5个导联的名字
    property alias lead6Name:lead6txt.text         //第6个导联的名字

    property int leadsPageIndex : 0                //用来标志显示的页面
    property bool  replaceFlag: false
    property int current:0

    property int ecgDataCount: 0
    property string  filterstring: ''

    property var factor: 0.01

    property var sixLeadsArray:[6] //6导联基线数组

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
                if(lead1txt.text == "I")
                {
                    lead1txt.text = "V1"
                    lead2txt.text = "V2"
                    lead3txt.text = "V3"
                    lead4txt.text = "V4"
                    lead5txt.text = "V5"
                    lead6txt.text = "V6"
                    leadsPageIndex = 1
                }
                else if(lead1txt.text == "V1")
                {
                    lead1txt.text = "I"
                    lead2txt.text = "II"
                    lead3txt.text = "III"
                    lead4txt.text = "aVR"
                    lead5txt.text = "aVL"
                    lead6txt.text = "aVF"
                    leadsPageIndex = 0
                }
                leadOffShow(leadsPageIndex)
                clearAllLines()
                current = 0
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
                    lead1txt.text = "V1"
                    lead2txt.text = "V2"
                    lead3txt.text = "V3"
                    lead4txt.text = "V4"
                    lead5txt.text = "V5"
                    lead6txt.text = "V6"
                    leadsPageIndex = 1
                }
                else if(lead1txt.text == "V1")
                {
                    lead1txt.text = "I"
                    lead2txt.text = "II"
                    lead3txt.text = "III"
                    lead4txt.text = "aVR"
                    lead5txt.text = "aVL"
                    lead6txt.text = "aVF"
                    leadsPageIndex = 0
                }
                leadOffShow(leadsPageIndex)
                clearAllLines()
                current = 0
            }

        }
    }


    Text {
        id: speedAndGainText
        x: 81
        y: 8
        z:1
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
        z:1
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
        x: 60
        y: 70
        z:1
        width: 30
        text: qsTr("I")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead2txt
        x: 60
        y: 140
        z:1
        width: 30
        text: qsTr("II")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead3txt
        x: 60
        y: 214
        z:1
        width: 30
        text: qsTr("III")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead4txt
        x: 60
        y: 296
        z:1
        width: 30
        text: qsTr("aVR")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead5txt
        x: 60
        y: 376
        z:1
        width: 30
        text: qsTr("aVL")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }

    Text {
        id: lead6txt
        x: 60
        y: 470
        z:1
        text: qsTr("aVF")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
    }


    Text {
        id: leadOff1
        x: 393
        y: 68
        z:1
        color:"yellow"
        width: 94
        height: 28
        text: qsTr("导联脱落")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 20
    }
    Text {
        id: leadOff2
        x: 393
        y: 138
        z:1
        width: 94
        height: 28
        color: "#ffff00"
        text: qsTr("导联脱落")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        id: leadOff3
        x: 393
        y: 214
        z:1
        width: 94
        height: 28
        color: "#ffff00"
        text: qsTr("导联脱落")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        id: leadOff4
        x: 393
        y: 294
        z:1
        width: 94
        height: 28
        color: "#ffff00"
        text: qsTr("导联脱落")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        id: leadOff5
        x: 393
        y: 374
        z:1
        width: 94
        height: 28
        color: "#ffff00"
        text: qsTr("导联脱落")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Text {
        id: leadOff6
        x: 393
        y: 468
        z:1
        width: 94
        height: 28
        color: "#ffff00"
        text: qsTr("导联脱落")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Item{
        x:100
        y:0
        width: 780
        height:548
        CustomPlotItem {
            id: sixCustomPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                initCustomPlot_6Lead(m3DataControl.gainType,m3DataControl.speedType)
            }
        }
    }

    Component.onCompleted: {     //6导联显示界面加载完成
        //m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //m3DataControl.list_ECG_data_show_changed.connect(openTimerAndSendBackSigenal)
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
        leadsPageIndex = 0  //12导联的2页面 6导联显示

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

        //calcultaX6LeadsSubLevel()
        //leads6ShowBaselineYCalculate()

        leadOffShow(leadsPageIndex)
        console.log("6leads load completed")
        m3DataControl.clearECGData();
    }


    Component.onDestruction:  {
        //m3DataControl.setGetECGDataTimerFlagFalse(); //将定时器开关的标志位置为假
        //m3DataControl.list_ECG_data_show_changed.disconnect(openTimerAndSendBackSigenal)
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
         console.log("6leads load show destroyed")
    }

    //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
    //m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
    function ecgShowStopOrnot()
    {
        if(m3DataControl.ecgShowStopFlag === true)
        {
            readECGDataTimer.running = false;//关闭定时器
            m3DataControl.setGetECGDataTimerFlagFalse();
        }
    }


    function leadOffShowChanged()
    {
        if(leadsPageIndex  == 0) //加载时为第一页面显示 I II III aVR aVL aVF
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            leadOff4.visible = false
            leadOff5.visible = false
            leadOff6.visible = false
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRL === true) //RL导联脱落  所有导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
        }
        else if(leadsPageIndex == 1)//加载时为第二页面 V1 V2 V3 V4 V5 V6
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            leadOff4.visible = false
            leadOff5.visible = false
            leadOff6.visible = false

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
            if(m3DataControl.leadsOffV4 === true)
            {
                leadOff4.visible = true
            }
            if(m3DataControl.leadsOffV5 === true)
            {
                leadOff5.visible = true
            }
            if(m3DataControl.leadsOffV6 === true)
            {
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRL === true) //RL导联脱落  所有导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
        }
    }

    function leadOffShow(leadPage)
    {
        if(leadPage  === 0) //加载时为第一页面显示 I II III aVR aVL aVF
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            leadOff4.visible = false
            leadOff5.visible = false
            leadOff6.visible = false
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LA导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRL === true) //RL导联脱落  所有导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
        }
        else if(leadPage === 1)//加载时为第二页面 V1 V2 V3 V4 V5 V6
        {
            leadOff1.visible = false
            leadOff2.visible = false
            leadOff3.visible = false
            leadOff4.visible = false
            leadOff5.visible = false
            leadOff6.visible = false

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
            if(m3DataControl.leadsOffV4 === true)
            {
                leadOff4.visible = true
            }
            if(m3DataControl.leadsOffV5 === true)
            {
                leadOff5.visible = true
            }
            if(m3DataControl.leadsOffV6 === true)
            {
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRL === true) //RL导联脱落  所有导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true
                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
            if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
            {
                leadOff1.visible = true
                leadOff2.visible = true
                leadOff3.visible = true

                leadOff4.visible = true
                leadOff5.visible = true
                leadOff6.visible = true
            }
        }

    }

//    function openTimerAndSendBackSigenal()
//    {
//        readECGDataTimer.running = true;//打开定时器
//        m3DataControl.setGetECGDataTimerFlagTrue();
//    }



    function on_receive_ecg_show_data()
    {
        //console.log("ecg_data_received")
        if(leadsPageIndex == 0) //第1页面 I,II,III,aVR,aVL,aVF导联显示
        {
            sixLeadsArray[0] = m3DataControl.leadIBaseLine;
            sixLeadsArray[1] = m3DataControl.leadIIBaseLine;
            sixLeadsArray[2] = m3DataControl.leadIIIBaseLine;
            sixLeadsArray[3] = m3DataControl.leadaVRBaseLine;
            sixLeadsArray[4] = m3DataControl.leadaVLBaseLine;
            sixLeadsArray[5] = m3DataControl.leadaVFBaseLine;

            sixLeadsArray[6] = m3DataControl.leadIMaxLine;
            sixLeadsArray[7] = m3DataControl.leadIIMaxLine;
            sixLeadsArray[8] = m3DataControl.leadIIIMaxLine;
            sixLeadsArray[9] = m3DataControl.leadaVRMaxLine;
            sixLeadsArray[10] = m3DataControl.leadaVLMaxLine;
            sixLeadsArray[11] = m3DataControl.leadaVFMaxLine;
            sixCustomPlot.ecg_Y_BaseLine6(sixLeadsArray)
            sixCustomPlot.update6LeadsShow(m3DataControl.getECG6ShowArray(0),m3DataControl.getECG6ShowArray(1),m3DataControl.getECG6ShowArray(2),m3DataControl.getECG6ShowArray(3),m3DataControl.getECG6ShowArray(4),m3DataControl.getECG6ShowArray(5));

        }
        else if(leadsPageIndex == 1) //第2页面 V1,V2,V3,V4,V5,V6导联显示
        {
            sixLeadsArray[0] = m3DataControl.leadV1BaseLine;
            sixLeadsArray[1] = m3DataControl.leadV2BaseLine;
            sixLeadsArray[2] = m3DataControl.leadV3BaseLine;
            sixLeadsArray[3] = m3DataControl.leadV4BaseLine;
            sixLeadsArray[4] = m3DataControl.leadV5BaseLine;
            sixLeadsArray[5] = m3DataControl.leadV6BaseLine;

            sixLeadsArray[6] = m3DataControl.leadV1MaxLine;
            sixLeadsArray[7] = m3DataControl.leadV2MaxLine;
            sixLeadsArray[8] = m3DataControl.leadV3MaxLine;
            sixLeadsArray[9] = m3DataControl.leadV4MaxLine;
            sixLeadsArray[10] = m3DataControl.leadV5MaxLine;
            sixLeadsArray[11] = m3DataControl.leadV6MaxLine;
            sixCustomPlot.ecg_Y_BaseLine6(sixLeadsArray)
            sixCustomPlot.update6LeadsShow(m3DataControl.getECG6ShowArray(6),m3DataControl.getECG6ShowArray(7),m3DataControl.getECG6ShowArray(8),m3DataControl.getECG6ShowArray(9),m3DataControl.getECG6ShowArray(10),m3DataControl.getECG6ShowArray(11));

        }
        m3DataControl.showOverAndClear()
        // console.log("clear")
    }


}

/*##^##
Designer {
    D{i:0;height:518;width:880}
}
##^##*/
