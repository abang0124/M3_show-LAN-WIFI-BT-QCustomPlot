import QtQuick 2.12
//@dsiable-check M16
Rectangle {
    width: 360
    height: 50
    border.width: 1
    border.color: "#ffffff"
    radius: 5
    color: "#3f4247"
    property alias bPValue: bPValue.text           //显示列表项的血压值
    property alias bPTimeValue: bPTimeValue.text   //显示列表项的血压值对应的测量时间
    Text {
        id: bPValue
        x: 17
        y: 8
        width: 112
        height: 34
        text: qsTr("Text")
        color: "#ffffff"
        font.pixelSize: 18
        font.bold: true
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }

    Text {
        id: bPTimeValue
        x: 258
        y: 8
        width: 83
        height: 34
        text: qsTr("Text")
        color: "#ffffff"
        font.pixelSize: 18
        font.bold: true
        horizontalAlignment: Text.AlignRight
        verticalAlignment: Text.AlignVCenter
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:3;height:50;width:360}
}
##^##*/
