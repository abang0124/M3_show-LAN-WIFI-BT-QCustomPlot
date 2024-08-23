import QtQuick 2.12
import QtQuick.Controls 2.5       //引入RadioButton
import QtQuick.Controls 1.4        //设置RadioButton的一组互斥
import QtQuick.Controls.Styles 1.4 //设置RadioButton的外观
Rectangle {
    width: 880
    height: 630
    color:"#d8d8d8"

    signal warnLogePageClosed
    Rectangle {
        id: secondMebunTitle
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
                anchors.fill: parent
                onClicked: {
                    warnLogePageClosed()
                    //contentLoader.source="SPO2And3LeadsShow.qml" //跳转回到主界面
                    //contentLoader.source=show_M3.ecgShowSource//返回主界面
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
            color:"#ffffff"
            text:"报警信息"
            font.pixelSize: 36
            font.bold: true
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
        }
    }
//    ListModel{
//        id:warnList
//        ListElement {
//            occurrtime:"19.03"
//            content:"SPO2传感器脱落"
//        }

//        ListElement {
//            occurrtime:"19.44"
//            content: "心动过速"

//        }

//        ListElement {
//            occurrtime:"19.45"
//            content:"心动过缓"

//        }

//        ListElement {
//            occurrtime:"20.11"
//            content:"导联脱落"
//        }
//    }
    ListView {
        id: listView
        x: 0
        y: 76
        width: 880
        height: 557
        clip:true //解决向上滑动时，Item底部超出显示范围，Item 才会消失的问题
        model: warnList//warnList在MainPage页面中
        delegate: Rectangle {
            x: 0
            width: 880
            height: 80
            color: "#EAECEA"
            border.width: 1
            border.color: "#000000"
            Row{
                spacing: 5
                WarnLogItem{
                    ocurrTime: occurrtime
                    warnConten: content
                }
            }

        }
    }
    Component.onCompleted: { //

    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:0.9}
}
##^##*/
