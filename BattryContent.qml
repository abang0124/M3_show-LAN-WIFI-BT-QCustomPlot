import QtQuick 2.12
Rectangle {
    width: 110
    height: 68
    color: "#d8d8d8"//"#fdfdfd"
    //visible: true
    property alias battryValue:battry.value //将电池电量引出外部可访问
    property alias battryColor:battry.batColor //电池内部颜色
    property alias percent: content.text
    property alias chargeFlagVisible: image.visible
    Battry{
        id:battry
        x: 8
        y: 22

    }

    Text {
        id: content
        x: 60
        y: 22
        width: 34
        height: 25
        text: "100%"
        font.pixelSize: 18
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Image {
        id: image
        x: 15
        y: 19
        width: 22
        height: 31
        source: "img/ChargingFlag.png"
        fillMode: Image.PreserveAspectFit
        visible: false
    }
}
