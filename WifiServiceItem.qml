import QtQuick 2.12

Rectangle {
    width: 880
    height: 80
    color: "#EAECEA"
    radius: 0
    border.color: "#ffffff"

    property alias serviceSSID: serviceName.text
    property bool serviceStatus: false   //false代表未连接 true代表已连接
    signal connectBtnCliked  //确认按钮按下
    signal disConnectBtnClicked  //取消按钮按下
    border.width:1
    Text {
        id: serviceName
        x: 22
        y: 8
        width: 552
        height: 64
        text: qsTr("Text")
        font.pixelSize: 30
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        //font.bold: true
    }

    Text {
        id: serviceState
        x: 591
        y: 8
        width: 113
        height: 64
        text: qsTr("Text")
        //font.bold: true
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
    }

    Rectangle {
        id: stateChangeBtn
        x: 746
        y: 12
        width: 115
        height: 57
        color: "#d0c6c6"
        radius: 8
        border.color: "#ffffff"
        Text {
            anchors.fill: parent
            id: btnStateTxt
            text: qsTr("连接")
            style: Text.Normal
            font.pointSize: 21
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }
        MouseArea{
            id: stateBtnMA
            anchors.fill:parent
            hoverEnabled: true
            onClicked: {
                connectOrDisConnectService()
            }
        }
    }
    Component.onCompleted: {
        if(serviceStatus === false)
        {
            serviceState.text = "未连接"
            btnStateTxt.text =  "连接"
        }
        else if(serviceStatus === true)
        {
            serviceState.text = "已连接"
            btnStateTxt.text =  "断开"
        }
    }
    function connectOrDisConnectService()
    {
        if(serviceStatus)
        {
            //console.log("disconnect the ",serviceName.text)
            m3DataControl.disconnectWifi(serviceName.text)
            disConnectBtnClicked()

        }
        else
        {
            //console.log("connect the ",serviceName.text)
            show_M3.wlanSSID = serviceName.text
            connectBtnCliked(serviceName.text)
            show_M3.wlanPassCodeSetPopOpen()
        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
