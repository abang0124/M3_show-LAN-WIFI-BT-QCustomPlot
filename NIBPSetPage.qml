import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    property alias checked: munualRadio.checked //现在用的是手动还是自动 true是手动，false是自动
    property alias minutString: minut.text     //手动设置的分钟数
    signal nIBPSetPageClose                     //NIBP设置界面的关闭
    Rectangle {
        id: secondMebunTitle
        x: 0
        y: 0
        width: 880
        height: 76
        color: "#585858"

        Image {
            id: image
            x: 13
            y: 13
            width: 50
            height: 50
            source: "img/CloseButton.png"

            MouseArea{
                anchors.fill: parent
                onClicked: {
                    nIBPSetPageClose()
                   // contentLoader.source="SPO2And3LeadsShow.qml" //返回主界面
                   // contentLoader.source=show_M3.ecgShowSource//返回主界面
                   show_M3.backMainPage()
                }
            }
        }

        Text {
            id: text1
            x: 352
            y: 0
            width: 176
            height: 76
            text: qsTr("NIBP")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    ExclusiveGroup{
        id: radioGroup  //将radiobutton控件绑定到同一个组，实现radiobutoon的互斥切换
    }
    Column{
        x: 0
        y: 82
        spacing: 5
        Rectangle {
            id: rectangle
            y: 76
            width: 880
            height: 100
            color: "#EAECEA"


            Text{
                x: 55
                y: 8
                id : munualText
                height: 90
                width: 360
                text:"手动测量"
                font.pixelSize: 40
                font.bold: true
                // horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }



            RadioButton {
                id: munualRadio
                x: 748
                y: 19
                text:''
                checked: true
                exclusiveGroup: radioGroup
                style:RadioButtonStyle{
                    indicator: Rectangle {
                        implicitWidth: 56
                        implicitHeight: 56
                        x: control.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 28
                        border.color: control.down ? "#000000" : "#000000"

                        Rectangle {
                            width: 34
                            height: 34
                            x: 11  // (56 - 34) / 2
                            y: 11
                            radius: 17
                            color: control.down ? "#000000" : "#000000"
                            visible: control.checked
                        }
                    }
                }
                onClicked: {
                    plusButton.enabled=false
                    minusButton.enabled = false
                    autoText.opacity = 0.6
                    munualText.opacity = 1
                    m3DataControl.autoMeasureNIBPFlag = false
                }


            }
        }
        Rectangle {
            id: rectangle1
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                id:autoText
                x: 55
                y: 4

                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "自动测量间隔(分钟)"
                verticalAlignment: Text.AlignVCenter
            }
            Row {
                id: row
                x: 533
                y: 27
                width: 148
                height: 52
                spacing: 10
                Rectangle{
                    id:plusButton
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius: 9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"-"
                        font.pixelSize: 40
                        font.bold: true
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {

                            minut.text =((Number(minut.text))-1).toString()
                            if(Number(minut.text)<1)
                            {
                               minut.text = "1"
                            }
                            m3DataControl.autoMeasureNIBPMinut = Number(minut.text)
                        }

                    }
                }
                Text{
                    id:minut
                    width: 50
                    height: 50
                    text:"12"
                    font.pixelSize: 30
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }
                Rectangle{

                    id:minusButton
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius:9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"+"
                        font.pixelSize: 40
                        font.bold: true
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            minut.text = (Number(minut.text)+1).toString();
                            if(Number(minut.text)>120)
                            {
                               minut.text = "120"
                            }
                            m3DataControl.autoMeasureNIBPMinut = Number(minut.text)
                        }
                    }
                }

            }
            RadioButton {
                id: autoRadio
                x: 749
                y: 27
                text:''
                checked: false
                exclusiveGroup: radioGroup
                style:RadioButtonStyle{
                    indicator: Rectangle {
                        implicitWidth: 56
                        implicitHeight: 56
                        x: control.leftPadding
                        y: parent.height / 2 - height / 2
                        radius: 28
                        border.color: control.down ? "#000000" : "#000000"

                        Rectangle {
                            width: 34
                            height: 34
                            x: 11  // (56 - 34) / 2
                            y: 11
                            radius: 17
                            color: control.down ? "#000000" : "#000000"
                            visible: control.checked
                        }
                    }
                }
                onClicked: {

                    plusButton.enabled=true
                    minusButton.enabled = true
                    autoText.opacity = 1
                    munualText.opacity = 0.6
                    m3DataControl.autoMeasureNIBPFlag = true
                }
            }

        }


    }
    Component.onCompleted: { //页面加载完成

        //血压的测量模式 手动测量和自动测量 以及时间间隔
        if(m3DataControl.autoMeasureNIBPFlag === true)//自动测量
        {
            munualRadio.checked = false
            autoRadio.checked = true
            autoText.opacity = 1
            munualText.opacity = 0.6
            plusButton.enabled=true
            minusButton.enabled = true
        }
        else{           //手动测量
            munualRadio.checked = true
            autoRadio.checked = false
            autoText.opacity = 0.6
            munualText.opacity = 1
            plusButton.enabled=false
            minusButton.enabled = false
        }
        minut.text = (m3DataControl.autoMeasureNIBPMinut).toString()
    }
    Component.onDestruction: { //页面销毁

        //发送最终的测量模式 手动测量或者自动测量以及时间间隔(单位是分钟)
    }

}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.1}
}
##^##*/
