import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观

import QtQuick.Layouts 1.12        //Popup布局管理器




Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"

    signal filterChoiceReturn          //滤波页面关闭
    signal lpSelectSignal              //lp单击信号

//    property alias lpChosen: lpchosen   //lp选择的内容
//    property alias hpChosen: hpchosen   //hp选择的内容
//    property alias acChosen: acchosen   //ac选择的内容

//    property int lpchosen:0               //lp选择的内容
//    property int hpchosen:0               //hp选择的内容
//    property int acchosen:0               //ac选择的内容

    Rectangle {          //标题栏
        id: filterChoiceTitle
        x: 0
        y: 0
        width: 880
        height: 76
        color: "#585858"
        Rectangle{
            x: 13
            y: 13
            width: 50
            height: 50
            color: "#eeecee"
            radius:9
            Text {
                id: image //返回符号
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
                    filterChoiceReturn()
                    contentLoader.source="ECGSetPage.qml" //跳转到ECG设置界面
                }
            }
        }

        Text {          //标题名字
            id: text1
            x: 352
            y: 0
            width: 176
            height: 76
            color:"#ffffff"
            text:"滤波选择"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: filterChoicePage
        x: 0
        y: 76
        width: 880
        height: 570
        color: "#D8D8D8"
        Column{
            spacing: 2
            Rectangle {
                id: lp
                x: 0
                y: 0
                width: 880
                height: 100
                color: "#ffffff"



                Text {
                    id: lpText
                    x: 60
                    y: 25
                    width: 100
                    height: 50
                    text: qsTr("LP")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }

                Text {
                    id: lpchosenText
                    x: 650
                    y: 25
                    width: 200
                    height: 50
                    text: qsTr("关闭")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            show_M3.lpSelectPopupshow()

                        }
                    }
                }



                Image {
                    id: imageLP
                    x: 796
                    y: 16
                    width: 55
                    height: 69
                    source: "img/righttriangle.png"
                    fillMode: Image.PreserveAspectFit

                }
            }

            Rectangle {
                id: ap

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: hpText
                    x: 60
                    y: 25
                    width: 263
                    height: 50
                    text: qsTr("HP")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                Text {
                    id: hpChosenText
                    x: 650
                    y: 25
                    width: 200
                    height: 50
                    text: qsTr("关闭")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            show_M3.hpSelectPopupshow()
                        }
                    }
                }


                Image {
                    id: imageAP
                    x: 796
                    y: 16
                    width: 55
                    height: 69
                    source: "img/righttriangle.png"
                    fillMode: Image.PreserveAspectFit

                }
            }
            Rectangle {
                id: ac

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: acText
                    x: 60
                    y: 25
                    width: 100
                    height: 50
                    text: qsTr("AC")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                Text {
                    id: acChosenText
                    x: 650
                    y: 25
                    text: qsTr("关闭")
                    width: 200
                    height: 50
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                             show_M3.acSelectPopupshow()
                        }
                    }
                }


                Image {
                    id: imageAC
                    x: 796
                    y: 16
                    width: 55
                    height: 69
                    source: "img/righttriangle.png"
                    fillMode: Image.PreserveAspectFit

                }
            }

        }
    }
    Component.onCompleted: {  //组件加载完成

        //低通滤波
        if(m3DataControl.lpSelectIndex === 0)
        {
            lpchosenText.text = "25Hz"
        }
        else if(m3DataControl.lpSelectIndex === 1)
        {
            lpchosenText.text = "40Hz"
        }
        else if(m3DataControl.lpSelectIndex === 2)
        {
            lpchosenText.text = "150Hz"
        }
        else if(m3DataControl.lpSelectIndex === 3)
        {
            lpchosenText.text = "关闭"
        }

        //高通滤波
        if(m3DataControl.hpSelectIndex === 0)
        {
            hpChosenText.text = "0.05Hz"
        }
        else if(m3DataControl.hpSelectIndex === 1)
        {
            hpChosenText.text = "0.15Hz"
        }
        else if(m3DataControl.hpSelectIndex === 2)
        {
            hpChosenText.text = "0.3Hz"
        }
        else if(m3DataControl.hpSelectIndex === 3)
        {
            hpChosenText.text = "0.67Hz"
        }
        else if(m3DataControl.hpSelectIndex === 4)
        {
            hpChosenText.text = "关闭"
        }


        //电源滤波
        if(m3DataControl.acSelectIndex === 0)
        {
            acChosenText.text = "50Hz"
        }
        else if(m3DataControl.acSelectIndex === 1)
        {
            acChosenText.text = "60Hz"
        }
        else if(m3DataControl.acSelectIndex === 2)
        {
            acChosenText.text = "关闭"
        }

        m3DataControl.lpSelectIndexChanged.connect(lpChosenChanged)
        m3DataControl.hpSelectIndexChanged.connect(hpChosenChanged)
        m3DataControl.acSelectIndexChanged.connect(acChosenChanged)



    }
    function lpChosenChanged(value)
    {
        //低通滤波
        if(value === 0)
        {
            lpchosenText.text = "25Hz"
        }
        else if(value === 1)
        {
            lpchosenText.text = "40Hz"
        }
        else if(value === 2)
        {
            lpchosenText.text = "150Hz"
        }
        else if(value === 3)
        {
            lpchosenText.text = "关闭"
        }
//        if(m3DataControl.lpSelectIndex === 0)
//        {
//            lpchosenText.text = "25Hz"
//        }
//        else if(m3DataControl.lpSelectIndex === 1)
//        {
//            lpchosenText.text = "40Hz"
//        }
//        else if(m3DataControl.lpSelectIndex === 2)
//        {
//            lpchosenText.text = "150Hz"
//        }
//        else if(m3DataControl.lpSelectIndex === 3)
//        {
//            lpchosenText.text = "关闭"
//        }
    }

    function hpChosenChanged(value)
    {

        //高通滤波
        if(value === 0)
        {
            hpChosenText.text = "0.05Hz"
        }
        else if(value === 1)
        {
            hpChosenText.text = "0.15Hz"
        }
        else if(value === 2)
        {
            hpChosenText.text = "0.3Hz"
        }
        else if(value === 3)
        {
            hpChosenText.text = "0.67Hz"
        }
        else if(value === 4)
        {
            hpChosenText.text = "关闭"
        }
//        if(m3DataControl.hpSelectIndex === 0)
//        {
//            hpChosenText.text = "0.05Hz"
//        }
//        else if(m3DataControl.hpSelectIndex === 1)
//        {
//            hpChosenText.text = "0.15Hz"
//        }
//        else if(m3DataControl.hpSelectIndex === 2)
//        {
//            hpChosenText.text = "0.3Hz"
//        }
//        else if(m3DataControl.hpSelectIndex === 3)
//        {
//            hpChosenText.text = "0.67Hz"
//        }
//        else if(m3DataControl.hpSelectIndex === 4)
//        {
//            hpChosenText.text = "关闭"
//        }

    }

    function acChosenChanged(value)
    {
        //电源滤波
        if(value === 0)
        {
            acChosenText.text = "50Hz"
        }
        else if(value === 1)
        {
            acChosenText.text = "60Hz"
        }
        else if(value === 2)
        {
            acChosenText.text = "关闭"
        }
//        if(m3DataControl.acSelectIndex === 0)
//        {
//            acChosenText.text = "50Hz"
//        }
//        else if(m3DataControl.acSelectIndex === 1)
//        {
//            acChosenText.text = "60Hz"
//        }
//        else if(m3DataControl.acSelectIndex === 2)
//        {
//            acChosenText.text = "关闭"
//        }
    }
    /*
    Popup{
        id:lpPopup
        x:100
        y:78
        width:200
        height: 260

        font.bold : true
        font.pixelSize: 38
        ColumnLayout{
            anchors.fill:parent
            //RadioButton{text:qsTr("")}
            Text{
                text:"25Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Text{
                text:"50Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Text{
                text:"100Hz"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            Text{
                text:"关闭"
                width: parent.width
                font.bold : true
                font.pixelSize: 38
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }*/

}






/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/
