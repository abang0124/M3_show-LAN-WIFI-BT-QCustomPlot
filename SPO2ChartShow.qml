import QtQuick 2.12
import QtCharts 2.3
import QtQml 2.12   //使用定时器
import CustomPlot 1.0
Rectangle {
    width:880
    height: 80//110 -30
    color: "black"

    property var lineColor:"#05DFDE"
//    ChartView{         //SPO2显示区



//        Connections{
//            target: m3DataControl
//            //onTest_signal:{
//            onSpo2NumChanged:{
//                var index = 0//index 代表spo2SplineSeriesArray用其中的哪条线段划线
//                var length = m3DataControl.sPO2DataCount();
//                if(length > 0)
//                {
//                    for(var count =0;count<length;count++)
//                    {
//                        index = parseInt(counter/(valueAxisX.max/spo2SplineSeriesArray.length))
//                        spo2SplineSeriesArray[index].append(counter,m3DataControl.getSPO2Data());
//                        counter++;
//                        //console.log("count = ",counter)
//                        if (counter>=valueAxisX.max)
//                        {
//                            for(var i = 0;i<spo2SplineSeriesArray.length;i++)
//                            {
//                                spo2SplineSeriesArray[i].clear()
//                                //console.log("spo2SplineSeriesArray["+i+"] cleard")
//                            }
//                            counter = 0;
//                            counter += 5;
//                        }
//                    }
//                }
////                index = parseInt(counter/(valueAxisX.max/spo2SplineSeriesArray.length)) //


////                if(m3DataControl.sPO2DataCount()>0)
////                {
////                    spo2SplineSeriesArray[index].append(counter,m3DataControl.getSPO2Data());
////                }
////                counter++;
////                if (counter>=valueAxisX.max)
////                {
////                    for(var i = 0;i<spo2SplineSeriesArray.length;i++)
////                    {
////                        spo2SplineSeriesArray[i].clear()
////                        //console.log("spo2SplineSeriesArray["+i+"] cleard")
////                    }
////                    counter = 0;
////                    counter += 5;
////                }
//            }
//        }

//    }
    Text {
        id: lead1txt
        x: 5
        y: 54
        z:1
        width: 55
        height: 27
        text: qsTr("SPO2")
        wrapMode: Text.WrapAnywhere
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color:"#05DFDe"
    }
    Item{
        x:60
        y:0
        width: 820
        height:parent.height
        CustomPlotItem {
            id: spo2CustomPlot
            anchors.fill: parent
            Component.onCompleted:
            {
                initCustomPlot_SPO2()
            }
        }
    }
    Component.onCompleted: {
        m3DataControl.spo2NumChanged.connect(spo2WaveChanged)
    }
    Component.onDestruction: {
        m3DataControl.spo2NumChanged.disconnect(spo2WaveChanged)
    }
    function spo2WaveChanged()
    {
        spo2CustomPlot.updateSPO2Show(m3DataControl.getSPO2Data())
        m3DataControl.clearSPO2Data()
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
