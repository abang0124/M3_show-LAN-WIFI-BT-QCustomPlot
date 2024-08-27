import QtQuick 2.12
import QtQuick.Controls 2.5      //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"

    signal maintenancePageReturnBack          //维护页面的返回按键
    signal closeAllWarn                       //整体报警关闭
    signal resetAllWarn                       //整体报警复位
    Rectangle {
        id: secondMebunTitle
        x: 0
        y: 0
        width: 880
        height: 76
        color: "#585858"
        Rectangle{
            x: 13
            y: 13
            width: 50
            height: 50
            color: "#eeecee"
            radius:9
            Text {
                id: image //返回符号
                anchors.fill:parent
                text:"<"
                font.pixelSize: 40
                font.bold: true
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    maintenancePageReturnBack()
                    contentLoader.source="WarnSetPage.qml" //报警设置界面
                }
            }
        }

        Text {
            id: text1
            x: 352
            y: 0
            width: 176
            height: 76
            color:"#ffffff"
            text:"维护"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: rectangle
        x: 0
        y: 76
        width: 880
        height: 570
        color: "#D8D8D8"

        Rectangle {
            id: close
            x: 0
            y: 8
            width: 880
            height: 100
            color: "#ffffff"

            Image {
                id: borderImage
                x: 60
                y: 25
                width: 50
                height: 50
                source: "img/WarnStop.png"
            }

            Text {
                id: text2
                x: 140
                y: 25
                width: 300
                height: 50
                text: qsTr("整体报警关闭")
                font.pixelSize: 40
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                   // closeAllWarn()
                    show_M3.warnClose()
                }
            }
        }

        Rectangle {
            id: reset
            x: 0
            y: 110
            width: 880
            height: 100
            color: "#ffffff"

            Image {
                id: borderImage1
                x: 60
                y: 25
                width: 50
                height: 50
                source: "img/WarnReset.png"
            }

            Text {
                id: text3
                x: 140
                y: 25
                width: 300
                height: 50
                text: qsTr("整体报警复位")
                font.pixelSize: 40
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                font.bold: true
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    //resetAllWarn()
                    show_M3.warnOpen()
                }
            }
        }
    }


    //text:"手动测量"
    //font.pixelSize: 40
    //font.bold: ture

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
