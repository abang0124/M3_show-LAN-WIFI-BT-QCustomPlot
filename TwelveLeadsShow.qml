import QtQuick 2.12
import QtCharts 2.3
import QtQml 2.12   //使用定时器
import CustomPlot 1.0
Rectangle {
    width:880
    height: 548//518
    color: "#000000"
    //    Rectangle{
    //        x:0
    //        y:0
    //        height: 30
    //        width: 880
    //        color:"red"
    //        z:1
    //    }
    property var textClolor: "green" //导联名称字的颜色
    property var fontSize: 24 //导联名称的字号
    property var firstColPosition: 8    //导联名称第一列的位置
    property var secondColPosition: 448 //导联名称第二列的位置
    property var rowPositionAray: [70,150,232,320,400,485] //导联名称每行的位置
    property var filterstring:""
    property var leadOffTextRowOffset: 200
    property var leadOffTextColOffset: 15

    property var twelveLeadsArray:[0]  //12导联的基线数组
    //property var twelveLeadsArray:[0]  //12导联的基线数组
    //property var testArray:[0]
    Text {
        id: speedAndGainText
        x: 8
        y: 9
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
    Text{
        x:firstColPosition
        y:rowPositionAray[0]
        z:1
        text:"  I "
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition
        y:rowPositionAray[1]
        z:1
        text:"  II"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition
        y:rowPositionAray[2]
        z:1
        text:" III"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition
        y:rowPositionAray[3]
        z:1
        text:"aVR"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition
        y:rowPositionAray[4]
        z:1
        text:"aVL"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition
        y:rowPositionAray[5]
        z:1
        text:"aVF"
        color:textClolor
        font.pixelSize: fontSize

    }

    Text{
        x:secondColPosition
        y:rowPositionAray[0]
        z:1
        text:"V1"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:secondColPosition
        y:rowPositionAray[1]
        z:1
        text:"V2"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:secondColPosition
        y:rowPositionAray[2]
        z:1
        text:"V3"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:secondColPosition
        y:rowPositionAray[3]
        z:1
        text:"V4"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:secondColPosition
        y:rowPositionAray[4]
        z:1
        text:"V5"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:secondColPosition
        y:rowPositionAray[5]
        z:1
        text:"V6"
        color:textClolor
        font.pixelSize: fontSize

    }
    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[0]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff1
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[1]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff2
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[2]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff3
        text:"导联脱落"
        color:"yellow"
    }

    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[3]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff4
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[4]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff5
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:firstColPosition+leadOffTextRowOffset
        y:rowPositionAray[5]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff6
        text:"导联脱落"
        color:"yellow"
    }

    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[0]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff7
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[1]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff8
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[2]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff9
        text:"导联脱落"
        color:"yellow"
    }

    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[3]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff10
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[4]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff11
        text:"导联脱落"
        color:"yellow"
    }
    Text{
        x:secondColPosition+leadOffTextRowOffset
        y:rowPositionAray[5]-leadOffTextColOffset
        z:1
        font.pixelSize: fontSize
        id:leadOff12
        text:"导联脱落"
        color:"yellow"
    }

    Item {
        x:0
        y:30
        width: 880
        height: 518
        id:leadShow12 //导联的显示
        CustomPlotItem {
            id: customPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                //initCustomPlot()
                initCustomPlot_12Lead(m3DataControl.gainType,m3DataControl.speedType)
            }
            //Component.onDestruction:
        }
    }

    Component.onCompleted: {  //组件加载完成 实现与m3DataControl信号的对接
        //m3DataControl.list_ECG_data_show_changed.connect(on_receive_ecg_show_data)
        //m3DataControl.list_ECG_data_show_changed.connect(openTimerAndSendBackSignal)
        //current = 0
        //replaceFlag = false
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
            //valueAxisX.max = 900//400+400+50*2 每个导联曲线长度是400。导联字符占50


        }
        else if(m3DataControl.speedType === 1)
        {
            speedAndGainText.text = speedAndGainText.text + "50mm/s";
            //valueAxisX.max = 500//200+200+50*2 每个导联曲线长度是200。导联字符占50
        }

        leadOffShowChanged() //加载完成，查看导联是否有脱落
                    //calcultaXY12LeadsSubLevel()
                    //leads12ShowBaselineYCalculate()
                    //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot) //
                    m3DataControl.leadsOffRAChange.connect(leadOffShowChanged)  //导联脱落检测函数
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
        console.log("12leads load completed")
    }

    Component.onDestruction:  {
        //leadShow12.deleteLater()
        m3DataControl.leadsOffRAChange.disconnect(leadOffShowChanged)  //导联脱落检测函数
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


    }



    function on_receive_ecg_show_data()
    {

//        console.log("the length is "+leadIArray.length)
        //12导联数据的最小值
        twelveLeadsArray[0] = m3DataControl.leadIBaseLine;
        twelveLeadsArray[1] = m3DataControl.leadIIBaseLine;
        twelveLeadsArray[2] = m3DataControl.leadIIIBaseLine;
        twelveLeadsArray[3] = m3DataControl.leadaVRBaseLine;
        twelveLeadsArray[4] = m3DataControl.leadaVLBaseLine;
        twelveLeadsArray[5] = m3DataControl.leadaVFBaseLine;
        twelveLeadsArray[6] = m3DataControl.leadV1BaseLine;
        twelveLeadsArray[7] = m3DataControl.leadV2BaseLine;
        twelveLeadsArray[8] = m3DataControl.leadV3BaseLine;
        twelveLeadsArray[9] = m3DataControl.leadV4BaseLine;
        twelveLeadsArray[10] = m3DataControl.leadV5BaseLine;
        twelveLeadsArray[11] = m3DataControl.leadV6BaseLine;
        //12导联数据的最大值
        twelveLeadsArray[12] = m3DataControl.leadIMaxLine;
        twelveLeadsArray[13] = m3DataControl.leadIIMaxLine;
        twelveLeadsArray[14] = m3DataControl.leadIIIMaxLine;
        twelveLeadsArray[15] = m3DataControl.leadaVRMaxLine;
        twelveLeadsArray[16] = m3DataControl.leadaVLMaxLine;
        twelveLeadsArray[17] = m3DataControl.leadaVFMaxLine;
        twelveLeadsArray[18] = m3DataControl.leadV1MaxLine;
        twelveLeadsArray[19] = m3DataControl.leadV2MaxLine;
        twelveLeadsArray[20] = m3DataControl.leadV3MaxLine;
        twelveLeadsArray[21] = m3DataControl.leadV4MaxLine;
        twelveLeadsArray[22] = m3DataControl.leadV5MaxLine;
        twelveLeadsArray[23] = m3DataControl.leadV6MaxLine;


        customPlot.ecg_Y_BaseLine12(twelveLeadsArray);

        customPlot.update12LeadsShow(m3DataControl.getECG12ShowArray(0),m3DataControl.getECG12ShowArray(1),m3DataControl.getECG12ShowArray(2),m3DataControl.getECG12ShowArray(3),m3DataControl.getECG12ShowArray(4),m3DataControl.getECG12ShowArray(5),m3DataControl.getECG12ShowArray(6),m3DataControl.getECG12ShowArray(7),m3DataControl.getECG12ShowArray(8),m3DataControl.getECG12ShowArray(9),m3DataControl.getECG12ShowArray(10),m3DataControl.getECG12ShowArray(11))

        m3DataControl.showOverAndClear()
    }


    function leadOffShowChanged()
    {
        leadOff1.visible = false
        leadOff2.visible = false
        leadOff3.visible = false
        leadOff4.visible = false
        leadOff5.visible = false
        leadOff6.visible = false
        leadOff7.visible = false
        leadOff8.visible = false
        leadOff9.visible = false
        leadOff10.visible = false
        leadOff11.visible = false
        leadOff12.visible = false
        if(m3DataControl.leadsOffRA === true) //RA导联脱落  第I导联和第II导联显示脱落
        {
            leadOff1.visible = true
            leadOff2.visible = true

            leadOff4.visible = true
            leadOff5.visible = true
            leadOff6.visible = true
            leadOff7.visible = true
            leadOff8.visible = true
            leadOff9.visible = true
            leadOff10.visible = true
            leadOff11.visible = true
            leadOff12.visible = true
        }
        if(m3DataControl.leadsOffLA === true) //LA导联脱落  第I导联和第III导联显示脱落
        {
            leadOff1.visible = true
            leadOff3.visible = true

            leadOff4.visible = true
            leadOff5.visible = true
            leadOff6.visible = true
            leadOff7.visible = true
            leadOff8.visible = true
            leadOff9.visible = true
            leadOff10.visible = true
            leadOff11.visible = true
            leadOff12.visible = true
        }
        if(m3DataControl.leadsOffLL === true) //LL导联脱落  第II导联和第III导联显示脱落
        {
            leadOff1.visible = true
            leadOff2.visible = true
            leadOff3.visible = true
            leadOff4.visible = true
            leadOff5.visible = true
            leadOff6.visible = true
            leadOff7.visible = true
            leadOff8.visible = true
            leadOff9.visible = true
            leadOff10.visible = true
            leadOff11.visible = true
            leadOff12.visible = true
        }
        if(m3DataControl.leadsOffV1 === true)
        {
            leadOff7.visible = true
        }
        if(m3DataControl.leadsOffV2 === true)
        {
            leadOff8.visible = true
        }
        if(m3DataControl.leadsOffV3 === true)
        {
            leadOff9.visible = true
        }
        if(m3DataControl.leadsOffV4 === true)
        {
            leadOff10.visible = true
        }
        if(m3DataControl.leadsOffV5 === true)
        {
            leadOff11.visible = true
        }
        if(m3DataControl.leadsOffV6 === true)
        {
            leadOff12.visible = true
        }
        if(m3DataControl.leadsOffRL === true) //RL导联脱落  所有导联显示脱落
        {
            leadOff1.visible = true
            leadOff2.visible = true
            leadOff3.visible = true
            leadOff4.visible = true
            leadOff5.visible = true
            leadOff6.visible = true
            leadOff7.visible = true
            leadOff8.visible = true
            leadOff9.visible = true
            leadOff10.visible = true
            leadOff11.visible = true
            leadOff12.visible = true
        }
    }
}





//    function calcultaXY12LeadsSubLevel() //计算X轴每段线的要显示的点数.val为轴的长度
//    {
//        var num = (parseInt((valueAxisX.max-100)/2)/(spLineSeriesLeadV6Array.length))
//        for(var i = 0;i< spLineSeriesLeadV6Array.length ;i++)
//        {
//            twelveLeadsSubLevel[i] = num*i
//            console.log("12LeadsSubLevel["+i+"] ="+twelveLeadsSubLevel[i])
//        }
//        leads12ShowBaselineX[0] = 50
//        leads12ShowBaselineX[1] = parseInt(valueAxisX.max/2+50)
//    }
////    function leads12ShowBaselineYCalculate() //左右两排，第1个和第7个的Y轴是一样的
////    {
////        var num = parseInt(valueAxisY.max/6)
////        for(var i = 0;i<12;i++)
////        {
////            leads12ShowBaselineY[i] = show_M3.baselineNUM[i] + (5-(i%6))*num
////        }
////    }
//    function leads12ShowBaselineYCalculate()
//    {
//        var num = parseInt(valueAxisY.max/6)


//        leads12ShowBaselineY[0] = m3DataControl.leadIBaseLine+5*num
//        leads12ShowBaselineY[1] = m3DataControl.leadIIBaseLine+4*num
//        leads12ShowBaselineY[2] = m3DataControl.leadIIIBaseLine+3*num
//        leads12ShowBaselineY[3] = m3DataControl.leadaVRBaseLine+2*num
//        leads12ShowBaselineY[4] = m3DataControl.leadaVLBaseLine+num
//        leads12ShowBaselineY[5] = m3DataControl.leadaVFBaseLine

//        leads12ShowBaselineY[6] = m3DataControl.leadV1BaseLine+5*num
//        leads12ShowBaselineY[7] = m3DataControl.leadV2BaseLine+4*num
//        leads12ShowBaselineY[8] = m3DataControl.leadV3BaseLine+3*num
//        leads12ShowBaselineY[9] = m3DataControl.leadV4BaseLine+2*num
//        leads12ShowBaselineY[10] = m3DataControl.leadV5BaseLine+num
//        leads12ShowBaselineY[11] = m3DataControl.leadV6BaseLine
////        for( var a=0;a<12;a++)
////        {
////            console.log("lead12ShowBaselineY["+a+"] = "+leads12ShowBaselineY[a])
////        }

//    }




//    //leads12ShowBaselineY
//    //leads12ShowBaselineX


//    Component.onDestruction:  {
//        m3DataControl.setGetECGDataTimerFlagFalse(); //将定时器开关的标志位置为假
//        m3DataControl.list_ECG_data_show_changed.disconnect(openTimerAndSendBackSignal)
//        m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
//        m3DataControl.leadsOffRAChange.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffLAChange.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffLLChange.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV1Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV2Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV3Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV4Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV5Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffV6Change.disconnect(leadOffShowChanged)
//        m3DataControl.leadsOffRLChange.disconnect(leadOffShowChanged)
//        console.log("12leads load show destroyed")
//    }

//    //m3DataControl.ecgShowStopFlagChanged.connect(ecgShowStopOrnot)
//    //m3DataControl.ecgShowStopFlagChanged.disconnect(ecgShowStopOrnot)
//    function ecgShowStopOrnot()
//    {
//        if(m3DataControl.ecgShowStopFlag === true)
//        {
//            readECGDataTimer.running = false;//关闭定时器
//            m3DataControl.setGetECGDataTimerFlagFalse();
//        }
//    }




//    function openTimerAndSendBackSignal()
//    {
//        readECGDataTimer12.running = true;
//        m3DataControl.setGetECGDataTimerFlagTrue();
//        console.log("timer is started");
//    }


//    function on_receive_ecg_show_data()
//    {
//        //console.log("ecg_data_received")



//        leadIYArray = m3DataControl.getECG12ShowArray(0)
//        //showECGdata(leadIYArray,0)
//        leadIIYArray = m3DataControl.getECG12ShowArray(1)
//        //showECGdata(leadIIYArray,1)
//        leadIIIYArray = m3DataControl.getECG12ShowArray(2)
//        //showECGdata(leadIIIYArray,2)
//        leadaVRYArray = m3DataControl.getECG12ShowArray(3)
//        //showECGdata(leadaVRYArray,3)
//        leadaVLYArray = m3DataControl.getECG12ShowArray(4)
//        //showECGdata(leadaVLYArray,4)
//        leadaVFYArray = m3DataControl.getECG12ShowArray(5)
//        //showECGdata(leadaVFYArray,5)
//        leadV1YArray = m3DataControl.getECG12ShowArray(6)
//        //showECGdata(leadV1YArray,6)
//        leadV2YArray = m3DataControl.getECG12ShowArray(7)
//        //showECGdata(leadV2YArray,7)
//        leadV3YArray = m3DataControl.getECG12ShowArray(8)
//        //showECGdata(leadV3YArray,8)
//        leadV4YArray = m3DataControl.getECG12ShowArray(9)
//        //showECGdata(leadV4YArray,9)
//        leadV5YArray = m3DataControl.getECG12ShowArray(10)
//        //showECGdata(leadV5YArray,10)
//        leadV6YArray = m3DataControl.getECG12ShowArray(11)
//        //showECGdata(leadV6YArray,11)
//        leads12ShowBaselineYCalculate()

//        var twelveLeadsSubLevelCurrentCount
//        //以下内容为显示心电曲线的数据更新的程序
//        console.log("length = ",leadIYArray.length)
//        for(var j = 0;j<leadIYArray.length;j++)
//        {

//            leadY[0]   = leadIYArray[j]*factor
//            leadY[1]  = leadIIYArray[j]*factor
//            leadY[2] = leadIIIYArray[j]*factor

//            leadY[3]  = leadaVRYArray[j]*factor
//            leadY[4]  = leadaVLYArray[j]*factor
//            leadY[5]  = leadaVFYArray[j]*factor

//            leadY[6] = leadV1YArray[j]*factor
//            leadY[7] = leadV2YArray[j]*factor
//            leadY[8] = leadV3YArray[j]*factor

//            leadY[9] = leadV4YArray[j]*factor
//            leadY[10] = leadV5YArray[j]*factor
//            leadY[11] = leadV6YArray[j]*factor

//            for(var twelveLeadsSubLevelNum = 0; twelveLeadsSubLevelNum < twelveLeadsSubLevel.length; twelveLeadsSubLevelNum++)
//            {

//                if(twelveLeadsSubLevelNum === (twelveLeadsSubLevel.length - 1))
//                {
//                    twelveLeadsSubLevelCurrentCount = twelveLeadsSubLevelNum
//                    break;
//                }
//                if((current>=twelveLeadsSubLevel[twelveLeadsSubLevelNum])&&(current<twelveLeadsSubLevel[twelveLeadsSubLevelNum+1]))
//                {

//                    twelveLeadsSubLevelCurrentCount = twelveLeadsSubLevelNum
//                    break

//                }

//            }
//            //console.log(twelveLeadsSubLevelCurrentCount)
//            for(var leadsNum = 0; leadsNum < 12; leadsNum++)
//            {
//                if(leadsNum<6)  //区分左右两排的数据
//                {
//                    twelveLSplineSeriesAArray[leadsNum][twelveLeadsSubLevelCurrentCount].append(current+leads12ShowBaselineX[0], leadY[leadsNum]+leads12ShowBaselineY[leadsNum])
//                }
//                else
//                {
//                    twelveLSplineSeriesAArray[leadsNum][twelveLeadsSubLevelCurrentCount].append(current+leads12ShowBaselineX[1], leadY[leadsNum]+leads12ShowBaselineY[leadsNum])
//                }

//                if(current === twelveLeadsSubLevel[twelveLeadsSubLevelCurrentCount])
//                {
//                    if(twelveLeadsSubLevelCurrentCount === (twelveLeadsSubLevel.length-1))
//                    {
//                        twelveLSplineSeriesAArray[leadsNum][0].clear()
//                    }
//                    else
//                    {
//                        twelveLSplineSeriesAArray[leadsNum][twelveLeadsSubLevelCurrentCount+1].clear()
//                    }
//                    // console.log("cleared")

//                }

//            }

//            current = current+1;


//            //if (current >= (valueAxisX.max/2-100))
//            if (current >= (valueAxisX.max/2-50))
//            {
//                //replaceFlag = true
//                current = 0

//                return
//            }
//            if(j === (leadIYArray.length-1)) //如果显示到了最后一个数
//            {
//                m3DataControl.showOverAndClear()
//            }
//        }
//    }
//    function showECGdata(lead,num)
//    {
//        console.log("lead",num,".legth = ",lead.length)
//        for(var i =0;i<lead.length;i++)
//        {
//            console.log("lead[",num,"][",i,"] = ",lead[num])
//        }
//    }
//}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
