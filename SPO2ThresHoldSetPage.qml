import QtQuick 2.12
import QtQuick.Controls 2.5      //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
import QtQuick.VirtualKeyboard 2.4
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"
    signal spo2ThresHoldPageReturn                    //心律阈值设置界面返回信号
    property int spo2value: 0
    Rectangle {
        id: spo2ThresHoldPageTitle
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
                    //要判断返回宽阈值还是窄阈值
                    //spo2ThresHoldValue
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
            text: qsTr("血氧阈值设置")
            color: "#ffffff"
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
            SPO2ThresHoldItem{
                id:spo2Item
                itemContent: "血氧值低于:"

                onWarnLeveClicked:
                {
                    //console.log("SPO2 报警级别设置")
                    if(m3DataControl.wideOrNarrowThresHoldPage === true) //如果是窄阈值设置
                    {
                        show_M3.warnLevelName = "SPO2Level"
                    }
                    else
                    {
                        show_M3.warnLevelName = "SPO2LevelWide"
                    }
                    warnLevelPopup.y = 115//80
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
    Component.onCompleted: { //血氧阈值设置界面加载完成
        //血氧阈值设置的值

        //超出阈值范围的报警级别
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            spo2Item.spo2ThresHoldValue = m3DataControl.spo2ThresHoldValue.toString()
            if(m3DataControl.spo2ThresHoldLevel === 0)
            {
                spo2Item.warnLevel = "高"
            }
            else if(m3DataControl.spo2ThresHoldLevel === 1)
            {
                spo2Item.warnLevel = "中"
            }
            else if(m3DataControl.spo2ThresHoldLevel === 2)
            {
                spo2Item.warnLevel = "低"
            }
        }
        else
        {
            spo2Item.spo2ThresHoldValue = m3DataControl.spo2ThresHoldValueWide.toString()
            if(m3DataControl.spo2ThresHoldLevelWide === 0)
            {
                spo2Item.warnLevel = "高"
            }
            else if(m3DataControl.spo2ThresHoldLevelWide === 1)
            {
                spo2Item.warnLevel = "中"
            }
            else if(m3DataControl.spo2ThresHoldLevelWide === 2)
            {
                spo2Item.warnLevel = "低"
            }
        }
        m3DataControl.spo2ThresHoldLevelChanged.connect(spo2WarnLevelChanged)
        m3DataControl.spo2ThresHoldLevelChangedWide.connect(spo2WarnLevelChangedWide)

        m3DataControl.spo2ThresHoldValueChanged.connect(spo2WarnValueChanged)
        m3DataControl.spo2ThresHoldValueChangedWide.connect(spo2WarnValueChangedWide)
        windowInputpanel.visible = true

    }
    Component.onDestruction: {
        saveCurrentData()
        m3DataControl.spo2ThresHoldLevelChanged.disconnect(spo2WarnLevelChanged)
        m3DataControl.spo2ThresHoldLevelChangedWide.disconnect(spo2WarnLevelChangedWide)

        m3DataControl.spo2ThresHoldValueChanged.disconnect(spo2WarnValueChanged)
        m3DataControl.spo2ThresHoldValueChangedWide.disconnect(spo2WarnValueChangedWide)
        windowInputpanel.visible = false
    }
    function saveCurrentData()
    {
        spo2value = Number(spo2Item.spo2ThresHoldValue)
        if(spo2value>100)
        {
            spo2value = 100
        }
        else if(spo2value<1)
        {
            spo2value = 1
        }
        if(m3DataControl.wideOrNarrowThresHoldPage === true)//如果是窄阈值的设置
        {
            m3DataControl.spo2ThresHoldValue = spo2value
        }
        else
        {
            m3DataControl.spo2ThresHoldValueWide = spo2value
        }
    }
    function spo2WarnValueChanged()
    {
        spo2Item.spo2ThresHoldValue = m3DataControl.spo2ThresHoldValue.toString()
    }

    function spo2WarnValueChangedWide()
    {
        spo2Item.spo2ThresHoldValue = m3DataControl.spo2ThresHoldValueWide.toString()
    }

    function spo2WarnLevelChanged()
    {
        if(m3DataControl.spo2ThresHoldLevel === 0)
        {
            spo2Item.warnLevel = "高"
        }
        else if(m3DataControl.spo2ThresHoldLevel === 1)
        {
            spo2Item.warnLevel = "中"
        }
        else if(m3DataControl.spo2ThresHoldLevel === 2)
        {
            spo2Item.warnLevel = "低"
        }
    }
    function spo2WarnLevelChangedWide()
    {
        if(m3DataControl.spo2ThresHoldLevelWide === 0)
        {
            spo2Item.warnLevel = "高"
        }
        else if(m3DataControl.spo2ThresHoldLevelWide === 1)
        {
            spo2Item.warnLevel = "中"
        }
        else if(m3DataControl.spo2ThresHoldLevelWide === 2)
        {
            spo2Item.warnLevel = "低"
        }
    }
}



