import QtQuick 2.12
import QtCharts 2.3
Rectangle {
    width: 880
    height: 164
    border.width: 1
    property alias leadname: leadName.text
    property alias xMax:valueOfAxisX.max
    property alias xMin:valueOfAxisX.min
    property alias xTicCount:valueOfAxisX.tickCount
    property alias yMax:valueOfAxisY.max
    property alias yMin:valueOfAxisY.min
    property alias yTicCount:valueOfAxisY.tickCount
    Text{
        id:leadName
        x: 0
        y: 0
        width: 31
        height: 164
        color: "Green"
        text:"V1"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 18
        font.bold: true

    }
    ChartView{
        id:leadline
        x: 30
        y: 0
        width: 850
        height: parent.height
        plotAreaColor: "#f9f8f8"
        legend.visible: false
        //backgroundColor: "green"
        backgroundRoundness: 0
        margins.top:0       // margin属性是设置plotArea和Rectangle边界的距离
        margins.bottom:0
        margins.left:0
        margins.right:0
        //Grid{}
        axes{
            ValueAxis{
                id:valueOfAxisXtest //X轴坐标系
                min:0
                max:80
                tickCount: 50
                labelsVisible: true
                gridVisible: true
                gridLineColor: "red"

            }
        }
        Column{
            //spacing: 10
            ValueAxis{
                id:valueOfAxisX //X轴坐标系
                min:0
                max:80
                tickCount: 50
                labelsVisible: true
                gridVisible: true
                gridLineColor: "red"

            }
            ValueAxis{
                id:valueOfAxisY //Y轴坐标系
                min:-10
                max:30
                tickCount: 50
                labelsVisible: true
                gridVisible: true
                gridLineColor: "red"
            }
            LineSeries{
                id:leadnum
                name:"I"
                axisX:valueOfAxisX
                axisY:valueOfAxisY
                color:"#00FF00"

            }

//            ValueAxis{
//                id:valueOfAxisX1 //X轴坐标系
//                min:0
//                max:800
//                tickCount: 50
//                labelsVisible: false

//            }
//            ValueAxis{
//                id:valueOfAxisY1 //Y轴坐标系
//                min:-10
//                max:30
//                tickCount: 50
//                labelsVisible: false
//            }
//            LineSeries{
//                id:leadnum1
//                name:"I"
//                axisX:valueOfAxisX1
//                axisY:valueOfAxisY1
//                color:"#FF0000"

//            }
        }


    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25}
}
##^##*/
