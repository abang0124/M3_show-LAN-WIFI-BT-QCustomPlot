import QtQuick 2.12

Rectangle {
    width: 880
    height: 100
    property  alias  itemContent: txt.text

    property alias hrFastWarnValue : higsetInput.text //心动过速阈值设置值
    property alias hrSlowWarnValue : lowsetInput.text //心动过缓阈值设置值
    property alias hrWarnLevel : text3.text           //心率的阈值报警级别
    property  alias  highsetVisible: highset.visible
    property  alias  lowsetVisible: lowset.visible
    signal warnLeveClicked //报警级别设置
    Text {
        id: txt
        x: 36
        y: 20
        width: 66
        height: 60
        text: qsTr("HR")
        font.pixelSize: 40
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }
    Rectangle{
        id:highset
        x: 220
        y: 20
        width: 174
        height: 67
        visible:true

        Text {
            id: text1
            height: parent.height
            text: qsTr("高:")
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        Rectangle{
            x: 75
            y: 14
            width:80
            height: 50
            //border.width: 1
            color: "lightgray"
            TextInput{
                id:higsetInput
                anchors.fill:parent
                font.pixelSize: 40
                maximumLength: 3
                focus: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                inputMethodHints: Qt.ImhDigitsOnly
                inputMask: "999"
                //validator: IntValidator{ bottom: 1; top: 300; } //只能输入1~300之间的数

            }
        }


    }

    Rectangle{
        id:lowset
        x: 472
        y: 20
        width: 174
        height: 67
        visible:true

        Text {
            id: lowsettxt
            height: parent.height
            text: qsTr("低:")
            font.pixelSize: 40
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        Rectangle{
            x: 75
            y: 14
            width:80
            height: 55
            //border.width: 1
            color:"lightgray"
            TextInput{
                id:lowsetInput
                anchors.fill:parent
                font.pixelSize: 40
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                maximumLength: 3
                inputMethodHints: Qt.ImhDigitsOnly
                text:"80"
                inputMask: "999"
                //validator: IntValidator{ bottom: 1; top: 300; } //只能输入1~300之间的数
                onActiveFocusChanged:
                {
                    console.log("test")
                }
                onFocusChanged: {
                    console.log("test11")
                }


            }
        }


    }

    Rectangle {
        id: rectangle
        x: 687
        y: 10
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
                    source: "img/righttriangle.png"
                    fillMode: Image.PreserveAspectFit
                }
            }
        }
        MouseArea{
            anchors.fill:parent
            anchors.rightMargin: 0
            anchors.bottomMargin: 0
            anchors.leftMargin: 0
            anchors.topMargin: 0
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
