import QtQuick 2.12
//该模块为标题栏的时间显示的模块
Rectangle {
    width: 100
    height: 68
    color: "#d8d8d8"
    property alias date: date.text //对外打开日期显示的接口
    property alias time: time.text //对外打开时间现实的接口
    signal dateAndTimeClicked //时间设置按下
    Text {
        id: date
        x: 8
        y: 8
        width: 84
        height: 25
        text:"--/--/--"
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Text {
        id: time
        x: 16
        y: 39
        width: 67
        height: 21
        text:"--:--:--"
        font.pixelSize: 12
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }
    MouseArea{
        anchors.fill:parent
        onClicked: {
            dateAndTimeClicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:3;height:68;width:100}
}
##^##*/
