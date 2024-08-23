import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    signal wideThresHoldReturn                          //宽阈值界面返回信号
    signal wideTurnToHeartRatePage                          //跳转至心律阈值界面
    signal wideTurnToBloodPressurePage                      //跳转至血压阈值界面
    signal wideTurnToSPO2Page                             //跳转至血氧阈值界面
    Rectangle {
        id: wideThresHoldPageTitle
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
                    wideThresHoldReturn()
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
            text: qsTr("宽阈值设置")
            color: "#ffffff"
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
            id: heartRate
            // x: 0
            y: 76
            width: 880
            height: 100
            color: "#EAECEA"


            Text{
                x: 55
                y: 8
                id:heartRatetxt
                height: 90
                width: 360
                text:"心率"
                font.pixelSize: 40
                font.bold: true
                // horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill: parent
                id:heartRateMA

                onClicked: {
                    wideTurnToHeartRatePage()
                    contentLoader.source="HeartRateThresHoldSetPage.qml" //心率阈值设置界面
                    console.log("跳转至心率阈值界面")
                }
            }

        }

        Rectangle {
            id:bloodPressure
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:bloodPressuretxt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "血压"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                id:bloodPressureMA
                anchors.fill:parent
                onClicked: {

                    wideTurnToBloodPressurePage()
                    contentLoader.source="BPThresHoldSetPage.qml" //血压阈值设置界面
                    console.log("跳转至血压阈值界面")
                }
            }
        }
        Rectangle {
            id: spo2
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:spo2txt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "血氧"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill:parent
                id:spo2MA
                onClicked: {
                    wideTurnToSPO2Page()
                    contentLoader.source="SPO2ThresHoldSetPage.qml" //血氧阈值设置界面
                    console.log("跳转至血氧阈值界面")
                }
            }
        }


    } //内容部分的结尾


}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
