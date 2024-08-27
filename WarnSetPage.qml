import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    //property alias checked: munualRadio.checked //现在用的是手动还是自动 true是手动，false是自动
    //property alias minutString: minute.text     //手动设置的分钟数
    signal resetDefault                         //恢复默认的配置的信号
    signal turnToMaintenancePage                //跳转到维护页面信号
    signal turnToWideThresHoldPage              //跳转到宽阈值设置界面的信号
    signal turnToNarrowThresHoldPage            //跳转到窄阈值设置界面的信号
    signal wideThresHoldSelected                //宽阈值被选择
    signal narrowThresHoldSelected              //窄阈值被选择
    signal warnSetPageReturn                    //报警设置界面返回信号
    Rectangle {
        id: warnSetPageTitle
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
                anchors.fill:parent
                onClicked: {
                    warnSetPageReturn()
                    console.log("界面返回")
                    //contentLoader.source="SPO2And3LeadsShow.qml" //返回主界面
                    //contentLoader.source=show_M3.ecgShowSource//返回主界面
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
            text: qsTr("报警设置")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
        Text{
            x: 680
            y: 24
            width: 113
            height: 39
            text:"恢复默认"
            font.pixelSize: 26
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            MouseArea{
                anchors.fill:parent
                anchors.rightMargin: 0
                anchors.bottomMargin: 0
                anchors.leftMargin: 0
                anchors.topMargin: 0
                onClicked:
                {
                    m3DataControl.warnSetBackToDefalut();
//                   m3DataControl.wideOrNarrowThresHoldPage = m3DataControl.defultWideOrNarrowThresHoldPage ;
//                   m3DataControl.wideOrNarrowThresHoldChoice = m3DataControl.defultWideOrNarrowThresHoldChoice;
//                   m3DataControl.spo2ThresHoldValue = m3DataControl.defultSPO2ThresHoldValue;
//                   m3DataControl.spo2ThresHoldLevel = m3DataControl.defultSPO2ThresHoldLevel;
//                   m3DataControl.spo2ThresHoldValueWide = m3DataControl.defultSPO2ThresHoldValueWide;
//                   m3DataControl.spo2ThresHoldLevelWide = m3DataControl.defultSPO2ThresHoldLevelWide;
//                   m3DataControl.bpSYSThresHoldValue = m3DataControl.defultBPSYSThresHoldValue;
//                   m3DataControl.bpDIAThresHoldValue = m3DataControl.defultBPDIAThresHoldValue;
//                   m3DataControl.bpSYSThresHoldLevel = m3DataControl.defultBPSYSThresHoldLevel;
//                   m3DataControl.bpDIAThresHoldLevel = m3DataControl.defultBPDIAThresHoldLevel;
//                   m3DataControl.bpSYSThresHoldValueWide = m3DataControl.defultBPSYSThresHoldValueWide;
//                   m3DataControl.bpDIAThresHoldValueWide = m3DataControl.defultBPDIAThresHoldValueWide;
//                   m3DataControl.bpSYSThresHoldLevelWide = m3DataControl.defultBPSYSThresHoldLevelWide;
//                   m3DataControl.bpDIAThresHoldLevelWide = m3DataControl.defultBPDIAThresHoldLevelWide;
//                   m3DataControl.hrFastValue = m3DataControl.defult_hrFastValue;
//                   m3DataControl.hrFastLevel = m3DataControl.defult_hrFastLevel;
//                   m3DataControl.hrSlowValue = m3DataControl.defult_hrSlowValue;
//                   m3DataControl.hrSlowLevel = m3DataControl.defult_hrSlowLevel;
//                   m3DataControl.hrFastValueWide = m3DataControl.defultHRFastValueWide
//                   m3DataControl.hrFastLevelWide = m3DataControl.defultHRFastLevelWide
//                   m3DataControl.hrSlowValueWide = m3DataControl.defultHRSlowValueWide
//                   m3DataControl.hrSlowLevelWide = m3DataControl.defultHRSlowLevelWide

                }
            }
        }
    }

    ExclusiveGroup{
        id: radioGroup  //将radiobutton控件绑定到同一个组，实现radiobutoon的互斥切换
        //checked:
    }
    Column{
        x: 0
        y: 82
        spacing: 5
        Rectangle {
            id: wideThreshold
            // x: 0
            y: 76
            width: 880
            height: 100
            color: "#EAECEA"


            Text{
                x: 55
                y: 8
                id:wideThresholdtxt
                height: 90
                width: 360
                text:"宽阈值设置"
                font.pixelSize: 40
                font.bold: true
                // horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                x: 19
                y: 8
                id:wideThresholdMA
                height: 90
                width: 656
                onClicked: {
                    //进入宽阈值设置界面
                    turnToWideThresHoldPage()
                    //console.log("跳转至宽阈值界面")
                    m3DataControl.wideOrNarrowThresHoldPage = false  //标记当前进入宽阈值的设置
                    contentLoader.source="WideThresHoldSetPage.qml" //跳转到宽阈值设置界面界面
                }
            }


            RadioButton {
                id: wideThresholdlRadio
                x: 748
                y: 19
                text:''
                checked: true
                exclusiveGroup: radioGroup
                style:RadioButtonStyle{
                    indicator: Rectangle {
                        implicitWidth: 56
                        implicitHeight: 56
                        //x: control.leftPadding
                        x: 0
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
                    m3DataControl.wideOrNarrowThresHoldChoice = false //宽阈值被选中
                }


            }
        }

        Rectangle {
            id: narrowThresHold
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:narrowThresholdtxt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "窄阈值设置"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                x: 22
                y: 8
                id:narrowThresholdMA

                height: 90
                width: 653
                onClicked: {
                    //进入窄阈值设置界面
                    turnToNarrowThresHoldPage()
                    console.log("跳转至窄阈值界面")
                    m3DataControl.wideOrNarrowThresHoldPage = true  //标记当前进入窄阈值的设置
                    contentLoader.source="NarrowThresHoldSetPage.qml" //跳转到宽阈值设置界面界面
                }
            }
            RadioButton {
                id: narrowThresHoldRadio
                x: 749
                y: 27
                text:''
                checked: false
                exclusiveGroup: radioGroup
                style:RadioButtonStyle{
                    indicator: Rectangle {
                        implicitWidth: 56
                        implicitHeight: 56
                        //x: control.leftPadding
                        x: 0
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
                    m3DataControl.wideOrNarrowThresHoldChoice = true //窄阈值被选中
                }
            }

        }

        Rectangle {
            id: pauseTimeLength //暂停时长
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:txtcontent
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                opacity: 0.5
                font.pixelSize: 40
                font.bold: true
                text: "暂停时长(秒)"
                verticalAlignment: Text.AlignVCenter
            }
            Row {                      //加减按键和显示内容组件
                id: row
                x: 630
                y: 27
                width: 171
                height: 52
                spacing: 10
                Rectangle{
                    //x: 505
                    // y: 27
                    //rowCenter: parent.horizontalCenter
                    id:plusButton
                    //horizontalCenter: parent.horizontalCenter
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius: 9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"+"
                        font.pixelSize: 40
                        font.bold: true
                        // font.pix
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            minut.text = (Number(minut.text)+1).toString();
                            //minut.text = "4"
                            console.log((Number(minut.text)+1).toString())
                        }

                    }
                }
                Text{
                    // x: 571
                    // y: 30
                    // horizontalCenter: parent.horizontalCenter
                    id:second
                    width: 50
                    height: 50
                    text:"120"
                    font.pixelSize: 30
                    font.bold: true
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter

                }
                Rectangle{

                    //x: 634
                    //y: 27
                    id:minusButton
                    //horizontalCenter: parent.horizontalCenter
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius:9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"-"
                        font.pixelSize: 40
                        font.bold: true
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            //minut.text = "20"
                            // minut.text =QString((Number(minut.text))-1)
                            second.text =((Number(second.text))-1).toString()
                            console.log((Number(second.text)-1).toString())
                        }
                    }
                }

            }
        }
        Rectangle {
            id: maintenance //维护
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4

                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "维护"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    //turnToMaintenancePage()
                    passCodeDialog.open()

                }
            }
        }


    }
    Component.onCompleted: {
        if(m3DataControl.wideOrNarrowThresHoldChoice === true)//当前是窄阈值设置界面
        {
            narrowThresHoldRadio.checked = true
        }
        else
        {
            wideThresholdlRadio.checked = true
        }

    }
    //内容部分的结尾
    /*
            Row {                      //加减按键和显示内容组件
                id: row
                x: 533
                y: 27
                width: 148
                height: 52
                spacing: 10
                Rectangle{
                    //x: 505
                    // y: 27
                    //rowCenter: parent.horizontalCenter
                    id:plusButton
                    //horizontalCenter: parent.horizontalCenter
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius: 9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"+"
                        font.pixelSize: 40
                        font.bold: true
                        // font.pix
                    }
                    MouseArea{
                        anchors.fill: parent
                        onClicked: {
                            minut.text = (Number(minut.text)+1).toString();
                            //minut.text = "4"
                            console.log((Number(minut.text)+1).toString())
                        }

                    }
                }
                Text{
                    // x: 571
                    // y: 30
                    // horizontalCenter: parent.horizontalCenter
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
                    //x: 634
                    //y: 27
                    id:minusButton
                    //horizontalCenter: parent.horizontalCenter
                    width: 50
                    height: 50
                    enabled: false
                    color: "#6D6E72"
                    radius:9
                    Text{
                        anchors.fill:parent
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text:"-"
                        font.pixelSize: 40
                        font.bold: true
                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                           //minut.text = "20"
                           // minut.text =QString((Number(minut.text))-1)
                            minut.text =((Number(minut.text))-1).toString()
                            console.log((Number(minut.text)-1).toString())
                        }
                    }
                }

            }
*/

}


