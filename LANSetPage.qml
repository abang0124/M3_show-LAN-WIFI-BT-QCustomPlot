import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
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
            text: qsTr("有线网络设置")
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
    }
    Component.onCompleted: {

    }

}


