import QtQuick 2.12

Rectangle {
    width: 1280
    height: 68
    color: "#d8d8d8"//"#fdfdfd"
    id:m3Title
    //各组件属性相关的内容
    //时间相关
    property alias date: dateTime.date //标题栏日期
    property alias time: dateTime.time //标题栏时间
    //成人儿童按钮
    property alias adultOrChild: adultOrChild.source //切换成人还是儿童的图片资源
    //技术报警
    property alias techWarnConten :techWarnning.content //技术报警要显示的内容
    property alias techWarnBackColor: techWarnning.color //技术报警背景颜色 //光报警需要
    property alias techWarnVisble:techWarnning.visible     //技术报警是否可见
    //生理报警
    property alias phsicWarnConten :phsicWarnning.content //生理报警要显示的内容
    property alias phsicWarnBackColor: phsicWarnning.color //生理报警背景颜色 //光报警需要
    property alias phsicWarnVisble: phsicWarnning.visible     //生理报警是否可见
    //报警暂停倒计时
    property alias warnCountDownTime: countDownTime.countDownTime //报警暂停倒计时
    property alias warnCountDownTimeVisible: countDownTime.visible  //报警倒计时是否可见
    property alias warnCountDownText:countDownTime.warnconTxt   //用于切换文字显示报警暂停和报警关闭
    property alias warnimageSource:countDownTime.source                       //切换报警关闭和报警暂停的图片资源
    property alias warnCountDownTimeContentVisible:countDownTime.warnCountDownTimeContentVisible //报警倒计时时间内容是否可见
    //电池相关的参数
    property alias batValue: bat.battryValue                     //电池的电量值
    property alias batPercent: bat.percent                       //显示电池电量的百分比
    property alias batColor:bat.battryColor                      //电池的显示颜色
    property alias batChargeVisible: bat.chargeFlagVisible      //充电标志是否可见

    //wifi状态图标
    property alias wifiSources: wifiImage.source
    //有线的状态图标
    property alias netSources: netImage.source
    //蓝牙的状态信息
    property alias btSource: btpic.source


    //整个标题会产生的信号
    signal adultOrChildClicked  //成人儿童选择按钮
    signal techWarnClicked //技术报警被按下
    signal phsicWarnClicked //生理报警被按下
    signal ecgStopClicked //心电图显示暂停
    signal setDateAndTimeClicked //设置时间的按键按下
    signal wifiShowClicked //wifi连接后显示具体的状态信息
    signal netShowClicked  //有线连接后显示具体的状态信息

    DataTime{
        id:dateTime
        x: 0
        y: 0
        onDateAndTimeClicked: {
            setDateAndTimeClicked()
        }

    }
    Rectangle{//空白间隙
        x:100
        y:0
        width: 2
        height: 68
        color: "#fdfdfd"
    }
    AdultOrChild{
        id:adultOrChild //width 68
        x: 102
        y: 0
        onClicked: {
            adultOrChildClicked()
        }

    }
    Rectangle{//空白间隙
        x:170
        y:0
        width: 2
        height: 68
        color: "#fdfdfd"
    }
    Rectangle{ // wifi的显示按钮
        id:wifiBtn
        x:172
        y:0
        width: 68
        Image {
            id: wifiImage
            source: "img/wifi_disconnected.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    wifiShowClicked();

                }
            }
        }

    }
    Rectangle{//空白间隙
        x:240
        y:0
        width: 2
        height: 68
        color: "#fdfdfd"
    }
    Rectangle{ // net的显示按钮
        id:netBtn
        x:242
        y:0
        width: 68
        Image {
            id: netImage
            source: "img/net_disconnected.png"
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    netShowClicked()

                }
            }
        }

    }
    Rectangle{//空白间隙
        x:310
        y:0
        width: 2
        height: 68
        color: "#fdfdfd"
    }
    Rectangle{
        id:ecgShowStopBtn
        x: 312
        y: 0
        width: 48
        height: 68
        color: "#d8d8d8"
        MouseArea {
            id: ecgShowStop
            anchors.fill:parent

            onClicked: {
                ecgStopClicked()
            }
        }
    }
    WarnningShow{
        id:techWarnning
        x: 360//225
        y: 0
        color:"#379DEE"
        onClicked: {
            techWarnClicked()
        }


    }
    WarnningShow{
        id:phsicWarnning
        x: 611//557
        y: 0
        color:"#FD0000"
        onClicked: {
            phsicWarnClicked()
        }

    }

    WarnningCountdown
    {
        id:countDownTime
        x: 890
        y: 0

    }
    Rectangle{
        id:btState //蓝牙状态显示
        x:1105
        y:19
        width: 31
        height: 31
        color: "#d8d8d8"
        Image {
            id: btpic
            source: "img/BT_connected.png"
        }
    }
    BattryContent{
        id:bat
        x: 1169
        y: 0

    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
