import QtQuick 2.12
import QtCharts 2.3
import QtQml 2.12   //使用定时器
import CustomPlot 1.0
Rectangle {
    id:test
    width:880
    height: 548
    color: "#000000"
    property alias speedAndGaintxt:speedAndGainText.text         //关于显示速度相关的信息
    property alias filtertxt: filterText.text      //关于滤波器相关的信息
    property alias lead1Name:lead1txt.text         //第1个导联的名字
    property alias lead2Name:lead2txt.text         //第2个导联的名字
    property alias lead3Name:lead3txt.text         //第3个导联的名字
    property int leadsPageIndex : 0                //用来标志显示的页面

    property int ecgDataCount: 0
    property string  filterstring: ''
    property var factor: 0.01
    property var threeLeadsArray:[0]  //3导联基线数组

    Text {
        id: speedAndGainText
        x: 20
        y: 9
        z:1
        width: 178
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
        x: 10
        y: 140
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
        x: 10
        y: 267
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
        x: 10
        y: 395
        z:1
        text: qsTr("III")
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"green"
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
    Item{
        //x:100
        x:50
        y:0
        //width: 780
        width: 830
        height:548
//        Rectangle{
//            anchors.fill: parent
//            color: "red"
//        }
        CustomPlotItem {
            id: threeCustomPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                initCustomPlot_Only3Lead(m3DataControl.gainType,m3DataControl.speedType)
            }
        }
    }


    Component.onCompleted: {     //3导联显示界面加载完成
        //m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //m3DataControl.list_ECG_data_show_changed.connect(openTimerAndSendBackSigenal)
        m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
        m3DataControl.leadsOffRAChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffLAChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.connect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.connect(leadOffShowChanged)
        m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        leadOffShowChanged() //页面加载完成，检查是否有导联脱落
        leadsPageIndex = 0  //12导联的4页面 3导联显示

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
        leadOffShowChanged()
        console.log("only 3leads load completed")
        m3DataControl.clearECGData();

    }

    Component.onDestruction:  {
        //m3DataControl.setGetECGDataTimerFlagFalse(); //将定时器开关的标志位置为假
        //m3DataControl.list_ECG_data_show_changed.disconnect(openTimerAndSendBackSigenal)
        m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
        m3DataControl.leadsOffRAChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffLAChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.disconnect(leadOffShowChanged)
        m3DataControl.leadsOffLLChange.disconnect(leadOffShowChanged)
        m3DataControl.list_ECG_data_show_changed.disconnect(on_receive_ecg_show_data)
         console.log("only 3leads load show destroyed")
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
        if(m3DataControl.leadsOffLL === true) //LA导联脱落  第II导联和第III导联显示脱落
        {
            leadOff2.visible = true
            leadOff3.visible = true
        }
        if(m3DataControl.leadsOffRL === true) //RL导联脱落
        {
            leadOff1.visible = true
            leadOff2.visible = true
            leadOff3.visible = true
        }
    }

//    function leads3ShowBaselineYCalculate()
//    {
//        var num = parseInt(valueAxisY.max/3)
//        for(var i = 0;i<12;i++)
//        {
//            leads3ShowBaselineY[i] = show_M3.baselineNUM[i] + (i%3)*num
//        }
//    }




    function on_receive_ecg_show_data()
    {
        threeLeadsArray[0] = m3DataControl.leadIBaseLine;
        threeLeadsArray[1] = m3DataControl.leadIIBaseLine;
        threeLeadsArray[2] = m3DataControl.leadIIIBaseLine;
        threeLeadsArray[3] = m3DataControl.leadIMaxLine;
        threeLeadsArray[4] = m3DataControl.leadIIMaxLine;
        threeLeadsArray[5] = m3DataControl.leadIIIMaxLine;
        threeCustomPlot.ecg_Y_BaseLine3(threeLeadsArray)
        threeCustomPlot.update3LeadsShow(m3DataControl.getECGShowArray(0),m3DataControl.getECGShowArray(1),m3DataControl.getECGShowArray(2))
        m3DataControl.showOverAndClear()
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25;height:518;width:880}
}
##^##*/
