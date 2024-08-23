import QtQuick 2.12

Rectangle {
    id:m3_Button
    width: 213
    height: 100
    color: "#d8d8d8"
    property alias txt: txt.text
    property alias source: img.source
    property alias textColor: txt.color
    property alias bkColor:m3_Button.color
    property alias customtxt : customText.text
    property alias picx: img.x
    property alias picy: img.y
    property alias txtx: txt.x
    property alias txty: txt.y
    property bool btnAnimationEnable: false
    signal clicked
    enabled: true
    border.width: 1
    border.color:"#203f4d"
    Text {
        id: txt
        x: 65
        y: 26
        width: 136
        height: 48
        color: "#363f4d"
        text:""
        font.pixelSize: 24
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }

    Image {
        id: img
        x: 12
        y: 25
        width: 50
        height: 50
    }

    ColorAnimation {  //按键按下动画
        id:btnPressed
        target: m3_Button
        from: "#303000"
        to: "#d8d8d8"
        properties: "color"
        duration: 200

    }
    MouseArea
    {
        id:m3_ButtonMA
        anchors.fill: parent
        onClicked:
        {
            if(btnAnimationEnable)
            {
                btnPressed.restart()
            }
            m3_Button.clicked()
        }

        Text {
            id: customText
            x: 88
            y: 8
            width: 34
            height: 16
            color: "gray"
            text: qsTr("")
            font.pixelSize: 18
        }
    }

}
