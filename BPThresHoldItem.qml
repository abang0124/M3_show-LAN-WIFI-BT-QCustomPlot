import QtQuick 2.12

Rectangle {
    width: 880
    height: 100
    property  alias  itemContent: txt.text
    property  alias  bpValueH: bpValueInput.text
    property  alias  bpValueL: bpValueInput2.text
    property  alias  warnLevelContent: warnLevel.text
    signal warnLeveClicked //报警级别设置
    Text {
        id: txt
        x: 36
        y: 20
        width: 178
        height: 60
        text: qsTr("收缩压")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Rectangle{
        id:highset
        x: 231
        y: 19
        width: 100
        height: 67
        visible:true
        color:"lightgray"

        TextInput{
            id:bpValueInput
            anchors.fill:parent
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
           // anchors.rightMargin: -113
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            text:"120"
            maximumLength: 3
            inputMethodHints: Qt.ImhDigitsOnly
            inputMask: "999"
            //validator: IntValidator{ bottom: 1; top: 500; } //只能输入1~500之间的数

        }
    }
    Text {
        //id: txt1
        x: 375
        y: 20
        width: 71
        height: 60
        text: qsTr("~")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Rectangle{
        id:lowset
        x: 494
        y: 19
        width: 100
        height: 67
        visible:true
        color:"lightgray"

        TextInput{
            id:bpValueInput2
            anchors.fill:parent
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
           // anchors.rightMargin: -113
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
            text:"120"
            maximumLength: 3
            inputMethodHints: Qt.ImhDigitsOnly
            inputMask: "999"
            //validator: IntValidator{ bottom: 1; top: 500; } //只能输入1~500之间的数

        }
    }

    Rectangle {
        id: rectangle
        x: 630
        y: 19
        width: 185
        height: 62
        color: "#ffffff"

        Text {
            id: text2
            x: 8
            y: 0
            text: qsTr("级别:")
            font.pixelSize: 40

            Text {
                id: warnLevel
                x: 98
                y: 0
                width: 38
                height: 40
                text: qsTr("高")
                font.pixelSize: 40

                Image {
                    id: image
                    x: 48
                    y: 12
                    width: 25
                    height: 40
                    source: "img/righttriangle.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
        MouseArea{
            anchors.fill:parent
            onClicked: {
                warnLeveClicked()
            }
        }
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9;height:100;width:880}
}
##^##*/
