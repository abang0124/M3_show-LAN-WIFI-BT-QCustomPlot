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
                    setPageReturn()
                    //console.log("界面返回")
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
            text: qsTr("设置")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
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
            id: netLAN
            // x: 0
            y: 76
            width: 880
            height: 100
            color: "#EAECEA"


            Text{
                x: 55
                y: 8
                id:netLANtxt
                height: 90
                width: 360
                text:"有线联网设置"
                font.pixelSize: 40
                font.bold: true
                // horizontalCenter: parent.horizontalCenter
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                x: 19
                y: 8
                id:netLANMA
                height: 90
                width: 656
                onClicked: {
                    //                    //跳转到有线管理界面
                    if(netLANRadio.checked === true) //如果被选中
                    {
                       // contentLoader.source="LANSetPage.qml" //跳转到窄阈值设置界面界面
                       // m3DataControl.setLanIPAdddress()
                    }

                }

                Text {
                    id: lanMacAddr
                    x: 383
                    y: 8
                    width: 52
                    height: 31
                    text: qsTr("mac地址:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                }

                Text {
                    id: lanIPAddr
                    x: 383
                    y: 45
                    width: 52
                    height: 31
                    text: qsTr("IP    地址:")
                    verticalAlignment: Text.AlignVCenter
                    font.pixelSize: 12
                }

                Text {
                    id: lanMacAddrContent
                    x: 441
                    y: 8
                    width: 207
                    height: 31
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: lanIPAddrContent
                    x: 441
                    y: 45
                    width: 207
                    height: 31
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }
            }


            RadioButton {
                id: netLANRadio
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
                        x:0
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
                    //有线联网被选中
                    if(m3DataControl.enableLan())//如果切换成功
                    {
                        m3DataControl.netTransFlag = 1
                        btMacAddrContent.text = ""
                        wlanIPAddrContent.text = ""
                        wlanMacAddrContent.text = ""
                        netSwitchSucessOpen()

                        //updataIPAddress()
                        console.log("net switch success")
                    }
                    else //如果切换失败
                    {
                        netConnectStateShow() //切换失败后根据当前网络的连接方式，切换回原来的状态
                        netSwitchfailedOpen()
                    }
                }


            }
        }

        Rectangle {
            id: netWLAN
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:netWLANtxt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "无线联网设置"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                x: 22
                y: 8
                id:netWLANMA

                height: 90
                width: 653
                onClicked: {
                    //                    //跳转到WIFI界面
                    if(netWLANRadio.checked === true) //如果被选中
                    {
                        contentLoader.source="WifiListpage.qml" //跳转到wifi列表界面
                        m3DataControl.scanWifi();
                    }

                }

                Text {
                    id: wlanMacAddr
                    x: 383
                    y: 8
                    width: 51
                    height: 31
                    text: qsTr("mac地址:")
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: wlanIPAddr
                    x: 383
                    y: 45
                    width: 51
                    height: 31
                    text: qsTr("IP    地址:")
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: wlanMacAddrContent
                    x: 441
                    y: 8
                    width: 207
                    height: 31
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    id: wlanIPAddrContent
                    x: 441
                    y: 45
                    width: 207
                    height: 31
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }
            }
            RadioButton {
                id: netWLANRadio
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
                    //无线传输被选中
                    //m3DataControl.netTransFlag = 2
                    //m3DataControl.enableWifi()
                    if(m3DataControl.enableWifi())//如果切换成功
                    {
                        m3DataControl.netTransFlag = 2
                        btMacAddrContent.text = ""
                        lanIPAddrContent.text = ""
                        lanMacAddrContent.text = ""
                        netSwitchSucessOpen()
                        //updataIPAddress()
                        console.log("net switch success")
                    }
                    else //如果切换失败
                    {
                        netConnectStateShow() //切换失败后根据当前网络的连接方式，切换回原来的状态
                        netSwitchfailedOpen()
                    }
                }
            }

        }
        Rectangle {
            id: netBT
            // x: 0
            // y: 159
            width: 880
            height: 100
            color: "#EAECEA"
            Text{
                x: 55
                y: 4
                id:netBTtxt
                height: 90
                //horizontalCenter: parent.horizontalCenter
                width: 360
                font.pixelSize: 40
                font.bold: true
                text: "蓝牙设置"
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                x: 22
                y: 8
                id:netBTMA



                Text {
                    id: btMacAddr //蓝牙mac地址
                    x: 383
                    y: 8
                    width: 52
                    height: 31
                    text: qsTr("mac地址:")
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                }
                Text {
                    id: btMacAddrContent //蓝牙mac地址的内容
                    x: 441
                    y: 8
                    width: 207
                    height: 31
                    horizontalAlignment: Text.AlignLeft
                    font.pixelSize: 12
                    verticalAlignment: Text.AlignVCenter
                }

                height: 90
                width: 653
                onClicked: {
                    //跳转到蓝牙管理界面
                    if(netBTRadio.checked === true)
                    {
                        contentLoader.source="BtSetPage.qml" //跳转到wifi列表界面
                    }
                }
            }

            RadioButton {
                id: netBTRadio
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
                    //蓝牙传输被选中
                    m3DataControl.enableBluetooth()
                }
            }

        }
    }
    Timer{
        id: popupShowTimer
        interval: 1000
        repeat: false
        running: false
        triggeredOnStart: false
        onTriggered:
        {
            if(netSwitchSucess.opened === true)
            {
                netSwitchSucess.close()
            }
            if(netSwitchfailed.opened === true)
            {
                netSwitchfailed.close()
            }
        }
    }
    Component.onCompleted: {
        if(m3DataControl.netTransFlag === 1) //有线网络传输
        {
            netLANRadio.checked = true
            lanIPAddrContent.text = m3DataControl.lanIPAddress
            lanMacAddrContent.text = m3DataControl.lanMacAddress
        }
        else if(m3DataControl.netTransFlag === 2) //无线网络传输
        {
            netWLANRadio.checked = true
            wlanIPAddrContent.text = m3DataControl.wlanIPAddress
            wlanMacAddrContent.text = m3DataControl.wlanMacAddress
        }
        else if(m3DataControl.netTransFlag === 3) //蓝牙网络传输
        {
            netBTRadio.checked = true
            btMacAddrContent.text = m3DataControl.btMacAddress
        }


        m3DataControl.netChangedAndIPAddressGeted.connect(updataIPAddress)
        m3DataControl.netTransFlagChanged.connect(updataNetChoice)
        m3DataControl.btOpenResult.connect(bluetoothOpenResult)
    }
    Component.onDestruction: {
        m3DataControl.netChangedAndIPAddressGeted.disconnect(updataIPAddress)
        m3DataControl.netTransFlagChanged.disconnect(updataNetChoice)
        m3DataControl.btOpenResult.disconnect(bluetoothOpenResult)
    }
    function updataNetChoice()
    {
        if(m3DataControl.netTransFlag === 1) //有线网络传输
        {
            netLANRadio.checked = true
        }
        else if(m3DataControl.netTransFlag === 2) //无线网络传输
        {
            netWLANRadio.checked = true
        }
        else if(m3DataControl.netTransFlag === 3) //蓝牙网络传输
        {
            netBTRadio.checked = true
        }
    }
    function updataIPAddress() //更新IP地址显示信息
    {
        if(m3DataControl.netTransFlag === 1)//如果当前网络状态为有线传输
        {
            wlanIPAddrContent.text = ""
            wlanMacAddrContent.text = ""
            lanIPAddrContent.text = m3DataControl.lanIPAddress
            lanMacAddrContent.text = m3DataControl.lanMacAddress
            btMacAddrContent.text = ""
        }
        else if(m3DataControl.netTransFlag === 2) //如果当前为无线传输
        {
            lanIPAddrContent.text = ""
            lanMacAddrContent.text = ""
            wlanIPAddrContent.text = m3DataControl.wlanIPAddress
            wlanMacAddrContent.text = m3DataControl.wlanMacAddress
            btMacAddrContent.text = ""
        }
        else if(m3DataControl.netTransFlag === 3) //如果当前为蓝牙传输
        {
            lanIPAddrContent.text = ""
            lanMacAddrContent.text = ""
            wlanIPAddrContent.text = ""
            wlanMacAddrContent.text = ""
            btMacAddrContent.text = m3DataControl.btMacAddress
        }
    }
    function netConnectStateShow() //切换失败后根据当前网络的连接方式，切换回原来的状态
    {
        if(m3DataControl.netTransFlag === 1)//如果当前网络状态为有线传输
        {
            netLANRadio.checked = true
            wlanIPAddrContent.text = ""
            wlanMacAddrContent.text = ""
            lanIPAddrContent.text = m3DataControl.lanIPAddress
            lanMacAddrContent.text = m3DataControl.lanMacAddress
            btMacAddrContent.text = ""
        }
        else if(m3DataControl.netTransFlag === 2)//如果当前为无线传输
        {
            netWLANRadio.checked = true
            lanIPAddrContent.text = ""
            lanMacAddrContent.text = ""
            wlanIPAddrContent.text = m3DataControl.wlanIPAddress
            wlanMacAddrContent.text = m3DataControl.wlanMacAddress
            btMacAddrContent.text = ""
        }
        else if(m3DataControl.netTransFlag === 3) //如果当前为蓝牙传输
        {
            netBTRadio.checked = true
            lanIPAddrContent.text = ""
            lanMacAddrContent.text = ""
            wlanIPAddrContent.text = ""
            wlanMacAddrContent.text = ""
            btMacAddrContent.text = m3DataControl.btMacAddress
        }
    }

    function netSwitchSucessOpen()
    {
        netSwitchSucess.open()
        popupShowTimer.start()
    }
    function netSwitchfailedOpen()
    {
        netSwitchfailed.open()
        popupShowTimer.start()
    }

    function bluetoothOpenResult(re)
    {
        if(re) //如果蓝牙打开成功
        {
            m3DataControl.netTransFlag = 3
            btMacAddrContent.text = m3DataControl.btMacAddress
            netSwitchSucessOpen()
            //updataIPAddress()
            console.log("bluetooth switch success")
        }
        else   //如果蓝牙打开失败
        {
            btMacAddrContent.text = ""
            netConnectStateShow() //切换失败后根据当前网络的连接方式，切换回原来的状态
            netSwitchfailedOpen()
        }
    }

    Popup{
        id:netSwitchSucess
        x:420
        y:280
        width: 160
        height: 40
        leftMargin: 0
        rightMargin: 0
        topMargin: 0
        bottomMargin: 0
        leftPadding: 0
        rightPadding: 0
        topPadding: 0
        bottomPadding: 0
        Rectangle {
            anchors.fill: parent
            color: "#4d4141"
            Text {
                anchors.fill:parent
                text: "切换成功"
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.centerIn: parent

            }
        }
    }
    Popup{
        id:netSwitchfailed
        x:320
        y:280
        width: 280
        height: 30
        leftMargin: 0
        rightMargin: 0
        topMargin: 0
        bottomMargin: 0
        leftPadding: 0
        rightPadding: 0
        topPadding: 0
        bottomPadding: 0
        Rectangle {
            anchors.fill: parent
            color: "#4d4141"
            Text {
                anchors.fill:parent
                color: "white"
                text: "切换失败，稍后再试"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                anchors.centerIn: parent
            }
        }
    }

}


