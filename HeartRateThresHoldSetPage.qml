import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
import QtQuick.VirtualKeyboard 2.4
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    property int fastValue: 0
    property int slowValue: 0
    signal heartRateThresHoldPageReturn                    //心律阈值设置界面返回信号
    Rectangle {
        id: heartRateThresHoldPageTitle
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
                  //heartRateThresHoldPageReturn()
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
            text: qsTr("心律阈值设置")
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
           /* HeartRateThresHoldItem{
                itemContent: "HR"
                highsetVisible: true
                lowsetVisible: true
                onWarnLeveClicked:
                {
                    console.log("HR 报警级别设置")
                }
            }*/
            HeartRateThresHoldItem{
                id:hrFast
                itemContent: "过速"
                highsetVisible: true
                lowsetVisible: false
                onWarnLeveClicked:
                {
                   //console.log("过速 报警级别设置")
                    if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
                    {
                        show_M3.warnLevelName ="HRFastLevel" //心率过速窄阈值
                    }
                    else
                    {
                         show_M3.warnLevelName ="HRFastLevelWide" //心率过速宽阈值
                    }
                    warnLevelPopup.x = 870
                    warnLevelPopup.y = 125//100
                    warnLevelPopup.open()
                }
            }
            HeartRateThresHoldItem{
                id:hrSlow
                itemContent: "过缓"
                highsetVisible: false
                lowsetVisible: true
                onWarnLeveClicked:
                {
                    if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
                    {

                        show_M3.warnLevelName = "HRSlowLevel" //心率过缓窄阈值
                    }
                    else
                    {
                         show_M3.warnLevelName = "HRSlowLevelWide" //心率过缓宽阈值
                    }
                    warnLevelPopup.x = 870
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
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            hrFast.hrFastWarnValue = m3DataControl.hrFastValue.toString()
            hrSlow.hrSlowWarnValue = m3DataControl.hrSlowValue.toString()
            if(m3DataControl.hrFastLevel === 0)
            {
                hrFast.hrWarnLevel = "高"
            }
            else if(m3DataControl.hrFastLevel === 1)
            {
                hrFast.hrWarnLevel = "中"
            }
            else if(m3DataControl.hrFastLevel === 2)
            {
                hrFast.hrWarnLevel = "低"
            }
            if(m3DataControl.hrSlowLevel === 0)
            {
                hrSlow.hrWarnLevel = "高"
            }
            else if(m3DataControl.hrSlowLevel === 1)
            {
                hrSlow.hrWarnLevel = "中"
            }
            else if(m3DataControl.hrSlowLevel === 2)
            {
                hrSlow.hrWarnLevel = "低"
            }
        }
        else   //如果是宽阈值设置
        {
            hrFast.hrFastWarnValue = m3DataControl.hrFastValueWide.toString()
            hrSlow.hrSlowWarnValue = m3DataControl.hrSlowValueWide.toString()
            if(m3DataControl.hrFastLevelWide === 0)
            {
                hrFast.hrWarnLevel = "高"
            }
            else if(m3DataControl.hrFastLevelWide === 1)
            {
                hrFast.hrWarnLevel = "中"
            }
            else if(m3DataControl.hrFastLevelWide === 2)
            {
                hrFast.hrWarnLevel = "低"
            }
            if(m3DataControl.hrSlowLevelWide === 0)
            {
                hrSlow.hrWarnLevel = "高"
            }
            else if(m3DataControl.hrSlowLevelWide === 1)
            {
                hrSlow.hrWarnLevel = "中"
            }
            else if(m3DataControl.hrSlowLevelWide === 2)
            {
                hrSlow.hrWarnLevel = "低"
            }
        }
        m3DataControl.hrFastValueChanged.connect(hrFastValChanged)
        m3DataControl.hrFastLevelChanged.connect(hrFastLevChanged)
        m3DataControl.hrSlowValueChanged.connect(hrSlowValChanged)
        m3DataControl.hrSlowLevelChanged.connect(hrSlowLevChanged)
        m3DataControl.hrFastValueChangedWide.connect(hrFastValChangedWide)
        m3DataControl.hrFastLevelChangedWide.connect(hrFastLevChangedWide)
        m3DataControl.hrSlowValueChangedWide.connect(hrSlowValChangedWide)
        m3DataControl.hrSlowLevelChangedWide.connect(hrSlowLevChangedWide)
        windowInputpanel.visible = true

    }
    Component.onDestruction: {
        saveCurrentData()
        m3DataControl.hrFastValueChanged.disconnect(hrFastValChanged)
        m3DataControl.hrFastLevelChanged.disconnect(hrFastLevChanged)
        m3DataControl.hrSlowValueChanged.disconnect(hrSlowValChanged)
        m3DataControl.hrSlowLevelChanged.disconnect(hrSlowLevChanged)
        m3DataControl.hrFastValueChangedWide.disconnect(hrFastValChangedWide)
        m3DataControl.hrFastLevelChangedWide.disconnect(hrFastLevChangedWide)
        m3DataControl.hrSlowValueChangedWide.disconnect(hrSlowValChangedWide)
        m3DataControl.hrSlowLevelChangedWide.disconnect(hrSlowLevChangedWide)
        windowInputpanel.visible = false

    }
    function saveCurrentData()
    {
        fastValue = Number(hrFast.hrFastWarnValue)
        slowValue = Number(hrSlow.hrSlowWarnValue)
        if(fastValue<=slowValue)
        {
            fastValue = slowValue+1
        }
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            m3DataControl.hrFastValue = fastValue
            m3DataControl.hrSlowValue = slowValue
        }
        else
        {
            m3DataControl.hrFastValueWide = fastValue
            m3DataControl.hrSlowValueWide = slowValue
        }
    }
    function hrFastValChanged()
    {
        hrFast.hrFastWarnValue = m3DataControl.hrFastValue.toString()
    }
    function hrFastLevChanged()
    {
        if(m3DataControl.hrFastLevel === 0)
        {
            hrFast.hrWarnLevel = "高"
        }
        else if(m3DataControl.hrFastLevel === 1)
        {
            hrFast.hrWarnLevel = "中"
        }
        else if(m3DataControl.hrFastLevel === 2)
        {
            hrFast.hrWarnLevel = "低"
        }
    }
    function hrSlowValChanged()
    {
        hrSlow.hrSlowWarnValue = m3DataControl.hrSlowValue.toString()
    }
    function hrSlowLevChanged()
    {
        if(m3DataControl.hrSlowLevel === 0)
        {
            hrSlow.hrWarnLevel = "高"
        }
        else if(m3DataControl.hrSlowLevel === 1)
        {
            hrSlow.hrWarnLevel = "中"
        }
        else if(m3DataControl.hrSlowLevel === 2)
        {
            hrSlow.hrWarnLevel = "低"
        }
    }


    function hrFastValChangedWide()
    {
        hrFast.hrFastWarnValue = m3DataControl.hrFastValueWide.toString()
    }
    function hrFastLevChangedWide()
    {
        if(m3DataControl.hrFastLevelWide === 0)
        {
            hrFast.hrWarnLevel = "高"
        }
        else if(m3DataControl.hrFastLevelWide === 1)
        {
            hrFast.hrWarnLevel = "中"
        }
        else if(m3DataControl.hrFastLevelWide === 2)
        {
            hrFast.hrWarnLevel = "低"
        }
    }
    function hrSlowValChangedWide()
    {
         hrSlow.hrSlowWarnValue = m3DataControl.hrSlowValueWide.toString()
    }
    function hrSlowLevChangedWide()
    {
        if(m3DataControl.hrSlowLevelWide === 0)
        {
            hrSlow.hrWarnLevel = "高"
        }
        else if(m3DataControl.hrSlowLevelWide === 1)
        {
            hrSlow.hrWarnLevel = "中"
        }
        else if(m3DataControl.hrSlowLevelWide === 2)
        {
            hrSlow.hrWarnLevel = "低"
        }
    }

}



