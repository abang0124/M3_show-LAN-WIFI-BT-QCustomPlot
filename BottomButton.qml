import QtQuick 2.12

Rectangle {
    width: 1280
    height: 100
    color: "#d8d8d8"
    signal warnResetCilcked
    signal warnPauseCilcked
    signal startBPCilcked
    signal recordECGCilcked
    signal warnSetCilcked
    signal mainMenuCilcked
    signal settingCilcked
    property alias warnResetBKColor: warnReset.color
    property alias warnPauseBKColor: warnPuase.color
    property alias startBPBKColor  : startBP.color
    property alias recordECGBKColor: recordECG.color
    property alias warnSetBKColor  : warnSet.color
    property alias mainMenuBKColor : mainMenu.color

    property alias warnResetBKTxt: warnReset.txt
    property alias warnPuaseBKTxt: warnPuase.txt
    property alias startBPBKTxt  : startBP.txt
    property alias recordECGBKTxt: recordECG.txt
    property alias warnSetBKTxt  : warnSet.txt
    property alias mainMenuBKTxt : mainMenu.txt

    Row {
        id: bootomRow
        anchors.fill:parent
        spacing: 2
        M3_Button
        {
            id: warnReset
            source:"img/WarnReset.png"
            txt: "报警复位"
            width: 196//212
            btnAnimationEnable:false
            onClicked: {
                warnResetCilcked()
            }

        }

        M3_Button
        {
            id: warnPuase
            source:"img/WarnPause.png"
            txt: "报警暂停"
            width: 196//212
            onClicked: {

                warnPauseCilcked()
            }

        }
        M3_Button
        {
            id:startBP
            source:"img/BPStart.png"
            txt: "测量血压"
            width: 196//212
            customtxt:"手动"
            onClicked: {
                startBPCilcked()
            }

        }
        M3_Button
        {

            id:recordECG
            source:"img/ECGRecord.png"
            txt:"记录心电"
            width: 196//212
            onClicked: {
                recordECGCilcked()
            }

        }
        M3_Button
        {
            id:warnSet
            source:"img/WarnSet.png"
            txt:"报警设置"
            btnAnimationEnable:true
            width: 196//212
            onClicked: {
                warnSetCilcked()
            }

        }
        M3_Button
        {
            id:settingMenu //设置按钮
            source:"img/setting.png"
            btnAnimationEnable:true
            picx: 40
            txtx: 53
            txt:"设置"
            width: 196//211
            onClicked: {
                settingCilcked()
            }

        }
        M3_Button
        {
            id:mainMenu
            source:"img/mainmenu.png"
            btnAnimationEnable:true
            width: 103//211
            picx:22
            onClicked: {
                mainMenuCilcked()
            }

        }
    }

    Component.onCompleted: {
        if(m3DataControl.autoMeasureNIBPFlag === true)
        {
            startBP.customtxt = "自动"
        }
        else{
            startBP.customtxt = "手动"
        }
        m3DataControl.autoMeasureNIBPFlagChanged.connect(bpButtonCustomTextChanged)
        m3DataControl.bPValueChanged.connect(bpButtonColorAndTextReset)
    }
    function bpButtonColorAndTextReset()
    {
        if(m3DataControl.autoMeasureNIBPFlag === false)//如果是手动，更新按键的显示
        {
            startBPBKTxt = "测量血压"
            startBPBKColor = "#d8d8d8"
        }

    }
    function bpButtonCustomTextChanged()
    {
        if(m3DataControl.autoMeasureNIBPFlag === true)
        {
            startBP.customtxt = "自动"
        }
        else{
            startBP.customtxt = "手动"
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
