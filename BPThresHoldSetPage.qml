import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
import QtQuick.VirtualKeyboard 2.4
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    signal bpThresHoldPageReturn                    //心律阈值设置界面返回信号
    property int sysValueH: 0
    property int sysValueL: 0
    property int diaValueH: 0
    property int diaValueL: 0
    Rectangle {
        id: bpThresHoldPageTitle
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
                anchors.fill:parent
                onClicked: {
                    //bpThresHoldPageReturn()
                    //要判断返回宽阈值还是窄阈值
                    saveCurrentData()
                    if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
                    {
                        contentLoader.source="NarrowThresHoldSetPage.qml" //跳转到窄阈值设置界面界面
                    }
                    else
                    {
                        contentLoader.source="WideThresHoldSetPage.qml" //跳转到宽阈值设置界面界面
                    }

                }
            }

        }
        Text {
            id: text1
            x: 329
            y: 0
            width: 222
            height: 76
            text: qsTr("血压阈值设置")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

    }
    Rectangle{
        x:0
        y:76
        width:880
        height: 556
        id:test
        color:"#d8d8d8"

        Column{

            spacing: 2
            BPThresHoldItem{
                id:sysItem
                itemContent: "收缩压:"

                onWarnLeveClicked:
                {
                    if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
                    {
                        show_M3.warnLevelName = "NIBPSYSLevel"
                    }
                    else
                    {
                        show_M3.warnLevelName = "NIBPSYSLevelWide"
                    }
                    warnLevelPopup.y = 115//80
                    warnLevelPopup.open()
                }
            }
            BPThresHoldItem{
                id:diaItem
                itemContent: "舒张压:"

                onWarnLeveClicked:
                {
                    if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
                    {
                        show_M3.warnLevelName = "NIBPDIALevel"
                    }
                    else
                    {
                        show_M3.warnLevelName = "NIBPDIALevelWide"
                    }
                    warnLevelPopup.y = 225//200
                    warnLevelPopup.open()
                }
            }


        }
    }//内容部分的结尾
//    InputPanel{
//        id:inputpanel
//        visible: true
//        y:800
//        anchors.left: parent.left
//        anchors.right:parent.right
//        anchors.bottom: parent.bottom
//        height: 170
//        onActiveChanged: {
//            if(!active){
//                visible = false;
//            }

//        }

//    }
    Component.onCompleted: {
        //要判断返回宽阈值还是窄阈值
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            sysItem.bpValueH = m3DataControl.bpSYSThresHoldValueH.toString();
            sysItem.bpValueL = m3DataControl.bpSYSThresHoldValueL.toString();
            diaItem.bpValueH = m3DataControl.bpDIAThresHoldValueH.toString();
            diaItem.bpValueL = m3DataControl.bpDIAThresHoldValueL.toString();
            if( m3DataControl.bpSYSThresHoldLevel === 0)
            {
                sysItem.warnLevelContent = "高";
            }
            else if( m3DataControl.bpSYSThresHoldLevel === 1)
            {
                sysItem.warnLevelContent = "中";
            }
            else if( m3DataControl.bpSYSThresHoldLevel === 2)
            {
                sysItem.warnLevelContent = "低";
            }

            if( m3DataControl.bpDIAThresHoldLevel === 0)
            {
                diaItem.warnLevelContent = "高";
            }
            else if( m3DataControl.bpDIAThresHoldLevel === 1)
            {
                diaItem.warnLevelContent = "中";
            }
            else if( m3DataControl.bpDIAThresHoldLevel === 2)
            {
                diaItem.warnLevelContent = "低";
            }

        }
        else
        {
            //sysItem.bpValue = m3DataControl.bpSYSThresHoldValueWide.toString();
            //diaItem.bpValue = m3DataControl.bpDIAThresHoldValueWide.toString();
            sysItem.bpValueH = m3DataControl.bpSYSThresHoldValueHWide.toString();
            sysItem.bpValueL = m3DataControl.bpSYSThresHoldValueLWide.toString();
            diaItem.bpValueH = m3DataControl.bpDIAThresHoldValueHWide.toString();
            diaItem.bpValueL = m3DataControl.bpDIAThresHoldValueLWide.toString();
            if( m3DataControl.bpSYSThresHoldLevelWide === 0)
            {
                sysItem.warnLevelContent = "高";
            }
            else if( m3DataControl.bpSYSThresHoldLevelWide === 1)
            {
                sysItem.warnLevelContent = "中";
            }
            else if( m3DataControl.bpSYSThresHoldLevelWide === 2)
            {
                sysItem.warnLevelContent = "低";
            }

            if( m3DataControl.bpDIAThresHoldLevelWide === 0)
            {
                diaItem.warnLevelContent = "高";
            }
            else if( m3DataControl.bpDIAThresHoldLevelWide === 1)
            {
                diaItem.warnLevelContent = "中";
            }
            else if( m3DataControl.bpDIAThresHoldLevelWide === 2)
            {
                diaItem.warnLevelContent = "低";
            }
        }

        m3DataControl.bpSYSThresHoldLevelChanged.connect(changeBPSYSWarnLevel)
        m3DataControl.bpDIAThresHoldLevelChanged.connect(changeBPDIAWarnLevel)
        m3DataControl.bpSYSThresHoldLevelChangedWide.connect(changeBPSYSWarnLevelWide)
        m3DataControl.bpDIAThresHoldLevelChangedWide.connect(changeBPDIAWarnLevelWide)

        m3DataControl.bpSYSThresHoldValueHChanged.connect(changeBPSYSWarnValue)
        m3DataControl.bpDIAThresHoldValueHChanged.connect(changeBPDIAWarnValue)
        m3DataControl.bpSYSThresHoldValueHChangedWide.connect(changeBPSYSWarnValueWide)
        m3DataControl.bpDIAThresHoldValueHChangedWide.connect(changeBPDIAWarnValueWide)
        m3DataControl.bpSYSThresHoldValueLChanged.connect(changeBPSYSWarnValue)
        m3DataControl.bpDIAThresHoldValueLChanged.connect(changeBPDIAWarnValue)
        m3DataControl.bpSYSThresHoldValueLChangedWide.connect(changeBPSYSWarnValueWide)
        m3DataControl.bpDIAThresHoldValueLChangedWide.connect(changeBPDIAWarnValueWide)
        windowInputpanel.visible = true

    }
    Component.onDestruction: {
        saveCurrentData()
        m3DataControl.bpSYSThresHoldLevelChanged.disconnect(changeBPSYSWarnLevel)
        m3DataControl.bpDIAThresHoldLevelChanged.disconnect(changeBPDIAWarnLevel)
        m3DataControl.bpSYSThresHoldLevelChangedWide.disconnect(changeBPSYSWarnLevelWide)
        m3DataControl.bpDIAThresHoldLevelChangedWide.disconnect(changeBPDIAWarnLevelWide)

//        m3DataControl.bpSYSThresHoldValueChanged.disconnect(changeBPSYSWarnValue)
//        m3DataControl.bpDIAThresHoldValueChanged.disconnect(changeBPDIAWarnValue)
//        m3DataControl.bpSYSThresHoldValueChangedWide.disconnect(changeBPSYSWarnValueWide)
//        m3DataControl.bpDIAThresHoldValueChangedWide.disconnect(changeBPDIAWarnValueWide)
        m3DataControl.bpSYSThresHoldValueHChanged.disconnect(changeBPSYSWarnValue)
        m3DataControl.bpDIAThresHoldValueHChanged.disconnect(changeBPDIAWarnValue)
        m3DataControl.bpSYSThresHoldValueHChangedWide.disconnect(changeBPSYSWarnValueWide)
        m3DataControl.bpDIAThresHoldValueHChangedWide.disconnect(changeBPDIAWarnValueWide)
        m3DataControl.bpSYSThresHoldValueLChanged.disconnect(changeBPSYSWarnValue)
        m3DataControl.bpDIAThresHoldValueLChanged.disconnect(changeBPDIAWarnValue)
        m3DataControl.bpSYSThresHoldValueLChangedWide.disconnect(changeBPSYSWarnValueWide)
        m3DataControl.bpDIAThresHoldValueLChangedWide.disconnect(changeBPDIAWarnValueWide)
        windowInputpanel.visible = false
    }
    function saveCurrentData()
    {
        sysValueH = Number(sysItem.bpValueH)
        if(sysValueH<=10)
        {
            sysValueH = 10
        }
        sysValueL = Number(sysItem.bpValueL)
        if(sysValueL<=10)
        {
            sysValueL = 10
        }
        diaValueH = Number(diaItem.bpValueH)
        if(diaValueH<=10)
        {
            diaValueH = 10
        }
        diaValueL = Number(diaItem.bpValueL)
        if(diaValueL<=10)
        {
            diaValueL = 10
        }


        if(sysValueH <= diaValueH)
        {
            sysValueH = diaValueH + 1
        }
        if(sysValueL >= sysValueH)
        {
            sysValueL = sysValueH - 1
        }
        if(diaValueL >= diaValueH)
        {
            diaValueL = diaValueH - 1
        }
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            m3DataControl.bpSYSThresHoldValueH = sysValueH
            m3DataControl.bpDIAThresHoldValueH = diaValueH
            m3DataControl.bpSYSThresHoldValueL = sysValueL
            m3DataControl.bpDIAThresHoldValueL = diaValueL
        }
        else
        {

            m3DataControl.bpSYSThresHoldValueHWide = sysValueH
            m3DataControl.bpDIAThresHoldValueHWide = diaValueH
            m3DataControl.bpSYSThresHoldValueLWide = sysValueL
            m3DataControl.bpDIAThresHoldValueLWide = diaValueL
        }
    }
    function changeBPSYSWarnValue()
    {
        sysItem.bpValueH = m3DataControl.bpSYSThresHoldValueH.toString();
        sysItem.bpValueL = m3DataControl.bpSYSThresHoldValueL.toString();
    }
    function changeBPDIAWarnValue()
    {
        diaItem.bpValueH = m3DataControl.bpDIAThresHoldValueH.toString();
        diaItem.bpValueL = m3DataControl.bpDIAThresHoldValueL.toString();
    }
    function changeBPSYSWarnValueWide()
    {
        sysItem.bpValueH = m3DataControl.bpSYSThresHoldValueHWide.toString();
        sysItem.bpValueL = m3DataControl.bpSYSThresHoldValueLWide.toString();
    }
    function changeBPDIAWarnValueWide()
    {
        diaItem.bpValueH = m3DataControl.bpDIAThresHoldValueHWide.toString();
        diaItem.bpValueL = m3DataControl.bpDIAThresHoldValueLWide.toString();
    }



    function changeBPSYSWarnLevel()
    {

        if( m3DataControl.bpSYSThresHoldLevel === 0)
        {
            sysItem.warnLevelContent = "高";
        }
        else if( m3DataControl.bpSYSThresHoldLevel === 1)
        {
            sysItem.warnLevelContent = "中";
        }
        else if( m3DataControl.bpSYSThresHoldLevel === 2)
        {
            sysItem.warnLevelContent = "低";
        }
    }
    function changeBPSYSWarnLevelWide()
    {
        if( m3DataControl.bpSYSThresHoldLevelWide === 0)
        {
            sysItem.warnLevelContent = "高";
        }
        else if( m3DataControl.bpSYSThresHoldLevelWide === 1)
        {
            sysItem.warnLevelContent = "中";
        }
        else if( m3DataControl.bpSYSThresHoldLevelWide === 2)
        {
            sysItem.warnLevelContent = "低";
        }
    }



    function changeBPDIAWarnLevel()
    {

        if( m3DataControl.bpDIAThresHoldLevel === 0)
        {
            diaItem.warnLevelContent = "高";
        }
        else if( m3DataControl.bpDIAThresHoldLevel === 1)
        {
            diaItem.warnLevelContent = "中";
        }
        else if( m3DataControl.bpDIAThresHoldLevel === 2)
        {
            diaItem.warnLevelContent = "低";
        }
    }
    function changeBPDIAWarnLevelWide()
    {
        if( m3DataControl.bpDIAThresHoldLevelWide === 0)
        {
            diaItem.warnLevelContent = "高";
        }
        else if( m3DataControl.bpDIAThresHoldLevelWide === 1)
        {
            diaItem.warnLevelContent = "中";
        }
        else if( m3DataControl.bpDIAThresHoldLevelWide === 2)
        {
            diaItem.warnLevelContent = "低";
        }
    }

}



