import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    radius: 0
    signal setPageReturn  //设置界面返回信号
    Rectangle {
        id: warnSetPageTitle
        x: 0
        y: 0
        width: 880
        height: 76
        color: "#585858"

        Rectangle{
            id: back
            x: 13
            y: 13
            width: 50
            height: 50
            color: "#eeecee"
            radius:9

            Text {
                id: txt //返回符号
                anchors.fill:parent
                text:"<"
                font.pixelSize: 40
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill: parent
                onClicked: { //返回设置页面
                    windowInputpanel.visible = false
                    contentLoader.source="SetPage.qml" //跳转到窄阈值设置界面界面
                }
            }
        }

        Text {
            id: text1
            x: 306
            y: 0
            width: 262
            height: 76
            text: qsTr("蓝牙相关设置")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Column{
        x: 0
        y: 82
        spacing: 5


        Rectangle {
            id: setBTName
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:netBTtxt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 181
                font.pixelSize: 40
                font.bold: true
                text: "蓝牙名字:"
                verticalAlignment: Text.AlignVCenter
            }
            TextInput{
                id:btName
                x: 267
                y: 32
                width: 256
                height: 44
                text:"HUASI-M3"
                transformOrigin: Item.Center
                font.pointSize: 20
                font.family: "Arial"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Button{
                id:confimBtname
                x: 676
                y: 32
                width: 129
                height: 44
                text:"确  定"
                style: ButtonStyle{
                    label:Text{
                        renderType: Text.NativeRendering
                        verticalAlignment: Text.AlignVCenter
                        horizontalAlignment: Text.AlignHCenter
                        font.pointSize: 30
                        color: "blue"
                        text: control.text
                    }
                }
                clip: false
                isDefault: true
                ColorAnimation {
                    from: "#E0E0E0"
                    to: "#EAECEA"
                    duration: 200
                }
                onClicked: //按键触发事件
                {
                     m3DataControl.writeBtName(btName.text);
                     //windowInputpanel.visible = false
                }

            }

        }
    }
    Component.onCompleted: {
        btName.text = m3DataControl.readBtName();
        windowInputpanel.visible = true
    }

}



/*##^## Designer {
    D{i:9;anchors_height:44;anchors_width:210;anchors_x:267;anchors_y:32}
}
 ##^##*/
