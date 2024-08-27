import QtQuick 2.12

Rectangle {
    id:sPO2Component
    width: 400
    height: 210.67
    color: "#3f4247"



    property alias sP02txt: sPO2txt.text    //显示心率
    property alias sPO2Uptxt: uptxt.text //显示上限，目前显示100，不知是否需要更改
    property alias sPO2Downtxt: downtxt.text //显示下限，目前显示90，不知是否需要更改
    property alias sPO2BKcolor: sPO2Component.color //整个组件的背景颜色，报警时光报警需要更改颜色
    property alias pItxt:pItxt.text  //血氧pI的显示值
    property alias valueHeight:showHeight.width  //showHeight.width  //显示一个高度值,范围是(0-130)
//    property alias columnRotation: showHeight.rotation //脉搏柱的旋转角度
//    property alias columnTransformOrigin: showHeight.transformOrigin //脉搏柱的旋转基点
//    property alias columnX: showHeight.x
//    property alias columnY: showHeight.y
    signal clicked                   //单击信号


    M3ShowTitle{
        x:0
        y:0
        lefttxt: "SPO2"
        righttxt: "%"
    }

    Text {
        id: sPO2txt
        x: 0
        y: 35
        width: 400
        height: 176
        text: qsTr("99")
        font.pixelSize: 160
        font.bold: true
        color:"#ffffff"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: uptxt
        x: 8
        y: 56
        width: 38
        height: 27
        font.bold: true
        color:"#ffffff"
        font.pixelSize: 20
        text: qsTr("100")

    }
    Text {
        id: downtxt
        x: 8
        y: 168
        width: 38
        height: 27
        font.bold: true
        color:"#ffffff"
        font.pixelSize: 20
        text: qsTr("90")

    }


    Rectangle {
        id: rectangle
        x: 342
        y: 41
        width: 23
        height: 136
        color: "#3f4247"
        border.width: 2
        border.color: "#979797"
    }

    Rectangle {   //可变化的，显示高度的条
        id: showHeight
        x:362
        y:158
        height: 17
        width: 10
        transformOrigin: Item.BottomLeft
        rotation: -90
        color: "#ffffff"
    }
    Text {
        id: pItxt
        x: 315
        y: 182
        width: 77
        height: 21
        text: qsTr("PI 2.68")
        font.bold: true
        color:"#ffffff"
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    MouseArea
    {
        anchors.fill:parent
        onClicked:
        {
            sPO2Component.clicked()
        }
    }

}



/*##^##
Designer {
    D{i:0;height:210;width:400}
}
##^##*/
