import QtQuick 2.12

Rectangle {
    width: 46
    height: 25
    color:"#d8d8d8"//"#fdfdfd"

    id:battry
    property alias value:battryValue.width  //电池点亮显示与内部矩形框的宽度进行绑定
    property alias batColor: battryValue.color //电池图标内部颜色
    Rectangle{
        border.color: "black"
        border.width: 1
        x: 0
        y: 0
        width: 40
        height: 25
        //color: "gray"
        Rectangle {
            id: battryValue
            x: 1
            y: 1
            width: 39
            height: 23
            color: "Green"
        }
    }
    Rectangle {
        id: battryHead
        x: 40
        y: 8
        width: 4
        height: 10
        color: "black"
    }


}

/*##^##
Designer {
    D{i:0;formeditorZoom:16;height:25;width:46}
}
##^##*/
