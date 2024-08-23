import QtQuick 2.12

Rectangle {
    width: 880
    height: 100
    property  alias  itemContent: txt.text
    property  alias  warnLevel: text3.text
    property  alias  spo2ThresHoldValue:higsetInput.text
    signal warnLeveClicked //报警级别设置
    Text {
        id: txt
        x: 22
        y: 20
        width: 306
        height: 60
        text: qsTr("血氧饱和度低于:")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Rectangle{
        id:highset
        x: 381
        y: 17
        width: 96
        height: 67
        visible:true
        color:"lightgray"
        TextInput{
            id:higsetInput
            anchors.fill:parent
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors.rightMargin: 0
            text:"100"
            maximumLength: 3
            inputMask: "999"
            inputMethodHints: Qt.ImhDigitsOnly
            //validator: IntValidator{ bottom: 1; top: 100; } //只能输入1~100之间的数
        }
    }



    Rectangle {
        id: rectangle
        x: 630
        y: 5
        width: 185
        height: 62
        color: "#ffffff"

        Text {
            id: text2
            x: 8
            y: 14
            text: qsTr("级别:")
            font.pixelSize: 40

            Text {
                id: text3
                x: 98
                y: 0
                width: 38
                height: 40
                text: qsTr("高")
                font.pixelSize: 40

                Image {
                    id: image
                    x: 48
                    y: 13
                    width: 25
                    height: 40
                    source:"img/righttriangle.png"
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

    Text {
        id: text1
        x: 479
        y: 20
        width: 38
        height: 61
        text: qsTr("%")
        font.pixelSize: 50
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

}



