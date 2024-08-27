import QtQuick 2.12

Rectangle {
    id:bPComponent
    width: 400
    height: 210.67
    color: "#3f4247"
    property alias titleLefttxt: title.lefttxt  //更改标题左上角的内容
    //第一界面(血压内容显示界面)需要控制的显示的内容

    property alias bPtxt: bPtxt.text    //显示血压
    property alias bPUptxt:  bPtxt.uptxt //显示上限，目前显示100，不知是否需要更改
    property alias bPDowntxt: bPtxt.downtxt //显示下限，目前显示90，不知是否需要更改
    property alias bPBKcolor: bPComponent.color //整个组件的背景颜色，报警时光报警需要更改颜色
    property alias countDownTime:  bPtxt.countDownTime //倒计时，字符串模式 //定时测量血压时需要
    property alias counDownTimeVisible :bPtxt.countDownTimeVisible //测量血压倒计时是否可见，手动测量时为不可见
    property alias bPtxtVisible : bPtxt.visible      //第一界面是否可见
    property alias countDownTimeVisible: countDownTime.visible //倒计时文本的显示与否

    //第二界面(血压列表)需要现实的内容
    property alias bPListViewVisible : bPListView.visible //第二界面是否可见



    signal clicked                   //单击信号
    signal listNIBPShowClicked       //NIBP显示列表信号
    signal listNIBPCloseClicked       //NIBP关闭列表信号
    M3ShowTitle{
        id :title
        x:0
        y:0
        lefttxt: ""
        righttxt: "mmHg"
    }

    Text {  //第一界面
        id: bPtxt
        visible: true
        property alias uptxt: uptxt.text      //上标限制 显示为100
        property alias downtxt: downtxt.text  //下表显示 显示为90
        property alias countDownTime : countDownTime.text //倒计时
        property alias countDownTimeVisible : countDownTime.visible //倒计时


        x: 0
        y: 34
        width: 400
        height: 137
        text: qsTr("--/--")
        font.pixelSize: 80
        font.bold: true
        color:"#ffffff"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        Text {
            id: uptxt
            x: 8
            y: 19
            width: 38
            height: 27
            font.bold: true
            color:"#ffffff"
            font.pixelSize: 20
            text: qsTr("")

        }
        Text {
            id: downtxt
            x: 8
            y: 129
            width: 38
            height: 27
            font.bold: true
            color:"#ffffff"
            font.pixelSize: 20
            text: qsTr("")

        }

        Text {
            id: sysdia
            x: 153
            y: 8
            width: 76
            height: 21
            color: "#fdfdfd"
            text: qsTr("SYS/DIA")
            font.bold: true
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter

        }
        Text {
            id:countDownTime
            x: 306
            y: 141

            width: 87
            height: 25
            color: "#fdfdfd"
            text: qsTr("00:20")
            font.bold: true
            font.pixelSize: 20
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        MouseArea
        {
            anchors.fill:parent
            onClicked:
            {
                bPComponent.clicked()

                console.log("MainClicked")
            }
        }
        Rectangle {  //测量血压的历史记录列表
            id: bPlistBotton
            x: 131
            y: 137
            width: 120
            height: 34
            //color: "#d8d8d8"
            color: "#3f4247"
            border.color:"#ffffff"
            border.width: 1
            radius:5
            visible:true

            Text {
                id: listNIBP
                x: 8
                y: 0
                width: 85
                height: 34
                text: qsTr("NIBP列表")
                color: "#ffffff"
                font.pixelSize: 20
                font.bold: true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: upArrow
                x: 95
                y: 8
                width: 26
                height: 20
                color: "#ffffff"
                font.bold: true
                text: qsTr(">>")
                rotation:270
                font.pixelSize: 22
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    bPtxt.visible=false
                    bPlistBotton.visible=false
                    title.lefttxt = "NIBP"
                    bPListView.visible = true
                    bPComponent.listNIBPShowClicked() //将要显示NIBP列表的信号传递出去
                    console.log("NIBPListOpenClicked")
                }
            }

        }


    }

    //第二界面 要显示的内容
    Rectangle {
        visible: false
        id: bPListView
        x: 0
        y: 34
        width: 400
        height: 176
        color: "#3f4247"

        Rectangle {
            id: bPlistCloseButton
            x: 137
            y: 0
            width: 126
            height: 32
            color: "#3f4247"
            border.color: "#ffffff"
            border.width: 2
            radius:5
            Text {
                id: listShowNIBP
                x: 8
                y: 4
                width: 82
                height: 24
                text: qsTr("NIBP列表")
                color: "#ffffff"
                font.pixelSize: 20
                font.bold: true

                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }

            Text {
                id: text2
                x: 96
                y: 5
                width: 25
                height: 24
                color: "#ffffff"
                font.bold: true
                text: qsTr(">>")
                rotation:90
                font.pixelSize: 18
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            MouseArea{
                anchors.fill:parent
                onClicked: {
                    bPtxt.visible=true
                    bPListView.visible = false
                    bPlistBotton.visible= true
                    title.lefttxt = ""
                    bPComponent.listNIBPCloseClicked() //将要显示NIBP列表的信号传递出去
                    console.log("NIBPListCloseClicked")
                }
            }
        }

        Text {
            id: sysdialabel
            x: 26
            y: 21
            width: 72
            height: 24
            text: qsTr("SYS/DIA")
            color:"#ffffff"
            font.pixelSize: 16
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        Text {
            id: tim
            x: 311
            y: 21
            width: 72
            height: 24
            text: qsTr("时间")
            color:"#ffffff"

            font.pixelSize: 16
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }

        //显示NIBP列表的内容

        //使用 modle list delegate实现血压列表的显示
        ListModel{
            id:listBPModel
            /*
            ListElement{BPValue: "110/85";BPTimeValue:"20:12"}
            ListElement{BPValue: "120/85";BPTimeValue:"20:22"}
            ListElement{BPValue: "115/85";BPTimeValue:"20:32"}
            ListElement{BPValue: "130/85";BPTimeValue:"20:42"}
            ListElement{BPValue: "121/85";BPTimeValue:"20:52"}
            */
        }

        ListView {   //有一个显示的问题，当向上滑动时显示的一个元素会覆盖一些信息？？？？？？？？？？？？，需要修改添加clip：true 问题解决
            id: historyOfNIBP
            x: 20
            y: 51
            width: 363
            height: 117
            clip:true //解决向上滑动时，Item底部超出显示范围，Item 才会消失的问题
            model:listBPModel
            delegate:NIBPListItem{
                bPValue:BPValue
                bPTimeValue:BPTimeValue
                height: 45
            }
        }


    }
    Component.onCompleted: {
        m3DataControl.bPValueChanged.connect(historyOfNIBPAdd) //与血压测量结果发出的信号相关联

    }
    Component.onDestruction: {
        m3DataControl.bPValueChanged.disconnect(historyOfNIBPAdd) //解除与血压测量结果发出的信号关联
    }
    function historyOfNIBPAdd()
    {
        var timeBP = m3DataControl.time //时间
        var bpValue = m3DataControl.bPValue //血压值
        var data = {BPValue:bpValue ,BPTimeValue:timeBP}
        listBPModel.append(data) //向历史列表添加一组历史数据

    }
}



/*##^##
Designer {
    D{i:0;height:210;width:400}
}
##^##*/
