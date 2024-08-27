import QtQuick 2.12

Rectangle {
    width: 880
    height: 80
    color: "#EAECEA"

    property alias ocurrTime: occurredTime.text
    property alias warnConten: warnContent.text
    border.width:1
    border.color:Qt.lighter("#EAECEA",0.7)
    Text {
        id: occurredTime
        x: 53
        y: 8
        width: 139
        height: 64
        text: qsTr("Text")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: true
    }

    Text {
        id: warnContent
        x: 309
        y: 8
        width: 508
        height: 64
        text: qsTr("Text")
        font.bold: true
        font.pixelSize: 40
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
