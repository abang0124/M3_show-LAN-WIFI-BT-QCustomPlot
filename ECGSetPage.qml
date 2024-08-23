import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 632
    color:"#d8d8d8"

    signal closeECGPage1          //ECG第一层页面关闭
    signal filterChose            //滤波选择信号发出
    signal speedChoice            //速度选择信号发出
    signal gainChoice             //增益选择信号发出
    signal showStyleChoice        //显示类型信号选择
    signal leadTypeChoice         //导联类型选择
    Rectangle {          //标题栏
        id: ecgPageTitle
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
            Image {
                anchors.fill:parent
                width: 50
                height: 50
                source: "img/CloseButton.png"
            }

            MouseArea{
                anchors.fill:parent
                onClicked: {
                    closeECGPage1()
                    //contentLoader.source="SPO2And3LeadsShow.qml" //返回主界面
                    //contentLoader.source=show_M3.ecgShowSource//返回主界面
                    show_M3.backMainPage()
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
            text:"ECG"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }

    Rectangle {
        id: contentECGPage1
        x: 0
        y: 76
        width: 880
        height: 570
        color: "#D8D8D8"
        Column{
            id:column1
            spacing: 2
            Rectangle {
                id: gain
                x: 0
                y: 0
                width: 880
                height: 100
                color: "#ffffff"



                Text {
                    id: gainText
                    x: 60
                    y: 25
                    width: 300
                    height: 50
                    text: qsTr("增益")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                       //gainChoice()
                        show_M3.gainPopupOpen()
                    }
                    Text {
                        id: gainshow
                        x: 679
                        y: 28
                        width: 99
                        height: 44
                        text: qsTr("10mm/mv")
                        font.pixelSize: 30
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    Image {
                        id: imagegain
                        x: 796
                        y: 16
                        width: 55
                        height: 69
                        source: "img/righttriangle.png"
                        fillMode: Image.PreserveAspectFit

                    }
                }

            }

            Rectangle {
                id: speed

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: speedText
                    x: 60
                    y: 25
                    width: 300
                    height: 50
                    text: qsTr("速度")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        //speedChoice()    //速度选择信号发出
                        show_M3.speedPopupOpen()
                    }
                    Text {
                        id: speedshow
                        x: 679
                        y: 28
                        width: 99
                        height: 44
                        text: qsTr("25mm/s")
                        font.pixelSize: 30
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    Image {
                        id: imagespeed
                        x: 796
                        y: 16
                        width: 55
                        height: 69
                        source: "img/righttriangle.png"
                        fillMode: Image.PreserveAspectFit

                    }
                }
            }
            Rectangle {
                id: filterChoice

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: filterChoiceText
                    x: 60
                    y: 25
                    width: 300
                    height: 50
                    text: qsTr("滤波选择")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                        filterChose() //滤波选择信号发出
                        contentLoader.source = "FilterChoicePage.qml" //跳转到滤波选择设置界面
                    }
                }
            }
            Rectangle {
                id: leadType

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: leadTypeText
                    x: 60
                    y: 25
                    width: 300
                    height: 50
                    text: qsTr("导联类型")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                MouseArea{
                    anchors.fill:parent
                    onClicked: {
                       // resetAllWarn()
                        //leadTypeChoice() //导联类型选择
                        show_M3.threeOrTwelveLeadsPopupOpen()
                    }

                    Text {
                        id: leadshow
                        x: 679
                        y: 28
                        width: 99
                        height: 44
                        text: qsTr("12导联")
                        font.pixelSize: 30
                        font.bold: true
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                    }

                    Image {
                        id: image
                        x: 796
                        y: 16
                        width: 55
                        height: 69
                        source: "img/righttriangle.png"
                        fillMode: Image.PreserveAspectFit

                    }
                }
            }
            Rectangle {
                id: showStyle

                width: 880
                height: 100
                color: "#ffffff"


                Text {
                    id: showStyleText
                    x: 60
                    y: 25
                    width: 300
                    height: 50
                    text: qsTr("显示样式")
                    font.pixelSize: 40
                    horizontalAlignment: Text.AlignLeft
                    verticalAlignment: Text.AlignVCenter
                    font.bold: true
                }
                MouseArea{
                    id:showStyleMA
                    anchors.fill:parent
                    onClicked: {
                        show_M3.leadsTypeSUPopupOpen()
                        //show_M3.leadsTypePopupOpen()
                        //切换12导联的显示形式 2*6或者3*4
                    }

                    Text {
                        id: style
                        x: 680
                        y: 20
                        width: 96
                        height: 61
                        text: qsTr("12")
                        font.pixelSize: 40
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        font.bold: true
                    }

                    Image {
                        id: image1
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
    }
    Component.onCompleted:
    { //ecg设置界面加载完成
        console.log("m3DataControl.leadsShowType = "+m3DataControl.leadsShowType)

        if(m3DataControl.gainType === 0)
        {
            gainshow.text = "10mm/mv";
        }
        else if(m3DataControl.gainType === 1)
        {
            gainshow.text = "20mm/mv";
        }
        else if(m3DataControl.gainType === 2)
        {
            gainshow.text = "5mm/mv";
        }


        if(m3DataControl.speedType === 0)
        {
            speedshow.text = "25mm/s";
        }
        else if(m3DataControl.speedType === 1)
        {
            speedshow.text = "50mm/s";
        }

        if(m3DataControl.leadsType === 0) //如果是12导联
        {
            leadshow.text = "12导联"
            showStyleMA.enabled=true
            showStyleText.color ="0"
            style.color ="0"
            if(m3DataControl.leadsShowType === 0)
            {
                style.text = "3"
            }
            else if(m3DataControl.leadsShowType === 1)
            {
                style.text = "6"
            }
            else if(m3DataControl.leadsShowType === 2)
            {
                style.text = "12"
            }
            else if(m3DataControl.leadsShowType === 3)
            {
                style.text = "1"
            }
        }
        else if(m3DataControl.leadsType === 1)
        {
            leadshow.text = "3导联"
            showStyleText.color ="lightgray"
            style.text = "3"
            style.color ="lightgray"
            showStyleMA.enabled=false
        }

        m3DataControl.leadsShowTypeChanged.connect(leadsTypeNumShow)
        m3DataControl.gainTypeChanged.connect(gainTypeShow)
        m3DataControl.speedTypeChanged.connect(speedTypeShow)
        m3DataControl.leadsTypeChange.connect(leadsTypeShow)

    }
    Component.onDestruction:
    {
        m3DataControl.leadsShowTypeChanged.disconnect(leadsTypeNumShow)
        m3DataControl.gainTypeChanged.disconnect(gainTypeShow)
        m3DataControl.speedTypeChanged.disconnect(speedTypeShow)
        m3DataControl.leadsTypeChange.connect(leadsTypeShow)
    }
    function leadsTypeShow()
    {
        if(m3DataControl.leadsType === 0)
        {
            leadshow.text = "12导联"
            showStyleMA.enabled=true
            showStyleText.color ="0"
            style.color ="0"
            if(m3DataControl.leadsShowType === 0)
            {
                style.text = "3"
            }
            else if(m3DataControl.leadsShowType === 1)
            {
                style.text = "6"
            }
            else if(m3DataControl.leadsShowType === 2)
            {
                style.text = "12"
            }
            else if(m3DataControl.leadsShowType === 3)
            {
                style.text = "1"
            }
        }
        else if(m3DataControl.leadsType === 1)
        {
            leadshow.text = "3导联"
            showStyleText.color ="lightgray"
            style.text = "3"
            style.color ="lightgray"
            showStyleMA.enabled=false

        }

    }
    function leadsTypeNumShow()
    {
        if(m3DataControl.leadsShowType === 0)
        {
            style.text = "3"
        }
        else if(m3DataControl.leadsShowType === 1)
        {
            style.text = "6"
        }
        else if(m3DataControl.leadsShowType === 2)
        {
            style.text = "12"
        }
        else if(m3DataControl.leadsShowType === 3)
        {
            style.text = "1"
        }
    }
    function gainTypeShow()
    {
        if(m3DataControl.gainType === 0)
        {
            gainshow.text = "10mm/mv";
        }
        else if(m3DataControl.gainType === 1)
        {
            gainshow.text = "20mm/mv";;
        }
        else if(m3DataControl.gainType === 2)
        {
            gainshow.text = "5mm/mv";;
        }
    }
    function speedTypeShow()
    {
        if(m3DataControl.speedType === 0)
        {
            speedshow.text = "25mm/s";
        }
        else if(m3DataControl.speedType === 1)
        {
            speedshow.text = "50mm/s";
        }
    }

}



/*##^##
Designer {
    D{i:0;formeditorZoom:0.75}
}
##^##*/

