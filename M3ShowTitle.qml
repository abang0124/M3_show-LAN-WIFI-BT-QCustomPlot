import QtQuick 2.12

Rectangle {
    id:m3ShowTitle
    width: 400
    height: 34
    color: "#64676c"
    property alias lefttxt : lefttxt.text   //左边显示的内容
    property alias righttxt : righttxt.text //右边显示的内容
    Text {
        id: lefttxt
        x: 11
        y: 0
        width: 187
        height: 34
        color: "#ffffff"
        text: qsTr("Text")
        font.pixelSize: 18
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: righttxt
        x: 232
        y: 0
        width: 158
        height: 34
        color: "#ffffff"
        text: qsTr("Text")
        font.pixelSize: 18
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.33;height:34;width:400}
}
##^##*/
