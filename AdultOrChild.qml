import QtQuick 2.12


Rectangle {
    id: adultOrChild
    width: 68
    height: 68
    color: "#d8d8d8"
    signal clicked//向外发出信号
    property alias source:image.source //公开对外的图片的接口
    Image {
        id: image
        x: 0
        y: 0
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        //width: 20
        //height: 68
        anchors.fill: parent
        source:"img/AdultOrChild.png"
        //source: "qrc:/qtquickplugin/images/template_image.png"
        fillMode: Image.PreserveAspectFit

        }
    MouseArea {
        id: mouseArea
        x: 0
        y: 0
       // width: 20
       // height: 68
        anchors.fill: parent
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        onClicked: {
            adultOrChild.clicked()

        }
    }
}

/*##^##
Designer {
    D{i:0;formeditorZoom:1.75;height:68;width:68}
}
##^##*/
