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
            x: 352
            y: 0
            width: 176
            height: 76
            text: qsTr("无线网络")
            color:"#ffffff"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Rectangle {
            id: refreshbtn
            x: 726
            y: 18
            width: 100
            height: 45
            radius: 6
            Text {
                anchors.fill:parent
                id: refreshTxt
                font.pixelSize: 20
                text: qsTr("刷 新")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {  //刷新按钮按下
                    m3DataControl.scanWifi();
                }
            }

        }
    }


    ListView{
        id: listView
        x: 0
        y: 76
        width: 880
        height: 557
        clip:true //解决向上滑动时，Item底部超出显示范围，Item 才会消失的问题
        model: wifiServiceList//wifiServiceList在MainPage页面中
        delegate: Rectangle {
            x: 0
            width: 880
            height: 80
            color: "#EAECEA"
            border.width: 1
            border.color: "#000000"
            Row{
                spacing: 5
                WifiServiceItem{
                    serviceSSID: wifiSSID
                    serviceStatus: connectState
                }
            }
        }

    }


    ListModel{    //用于存储 点击完扫描wifi 存储扫描到的wifi的列表
        id:wifiServiceList
//        ListElement{
//            wifiSSID:"schiller"
//            connectState:true
//        }
    }

    Component.onCompleted: {

        updataWifiList()
        m3DataControl.serviceChangeCompleted.connect(updataWifiList)

    }
    Component.onDestruction: {
        m3DataControl.serviceChangeCompleted.disconnect(updataWifiList)
    }
    function updataWifiList()
    {
        if(wifiServiceList.count > 0)
        {
            wifiServiceList.clear()
        }
        for(var name in m3DataControl.wifiServiceMap)
        {
            console.log(name,m3DataControl.wifiServiceMap[name])
            //console.log(name,m3DataControl.wifiServiceMap[name])
            wifiListAddElement(name,m3DataControl.wifiServiceMap[name])
            //wifiListAddElement(state,m3DataControl.wifiServiceMap[name])
        }
    }

    function wifiListAddElement(name,state) //第一个参数是名字 第二个参数是连接状态
    {
        //if()
        var data = {wifiSSID:name,connectState:state}
        wifiServiceList.append(data) //向历史列表添加一组历史数据
    }

}


