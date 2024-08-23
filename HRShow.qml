import QtQuick 2.12

Rectangle {
    id:hRComponent
    width: 400
    height: 210.67
    color: "#3f4247"
    property alias hRtxt: hRtxt.text    //显示心率
    property alias hRUuptxt: uptxt.text //显示上限，目前显示100，不知是否需要更改
    property alias hRDowntxt: downtxt.text //显示下限，目前显示90，不知是否需要更改
    property alias hRBKcolor: hRComponent.color //整个组件的背景颜色，报警时光报警需要更改颜色
    signal clicked                   //单击信号
    M3ShowTitle{
        x:0
        y:0
        lefttxt: "HR"
        righttxt: "b/min"
    }

    Text {
        id: hRtxt
        x: 0
        y: 34
        width: 400
        height: 176
        text: qsTr("85")
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
        text: qsTr("")

    }
    Text {
        id: downtxt
        x: 8
        y: 150
        width: 38
        height: 27
        font.bold: true
        color:"#ffffff"
        font.pixelSize: 20
        text: qsTr("")

    }
    MouseArea
    {
        anchors.fill:parent
        onClicked:
        {
            hRComponent.clicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.25;height:210;width:400}
}
##^##*/
