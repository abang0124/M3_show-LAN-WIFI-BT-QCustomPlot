import QtQuick 2.9
import QtQuick.Window 2.2

Window {
    visible: true
    width: 1280
    height: 800

    MainPage{
        id:mainpage
        Component.onCompleted: {
            mainpage.loadCompleted() //界面加载完成，控制串口的开始接收数据
        }

    }

    //flags:
    //title: qsTr("Hello World")
}
