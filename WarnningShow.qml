import QtQuick 2.12

Rectangle {
    width: 241//322
    height: 68
      //背景色不用导出为属性吧
    id: warn
    property alias content: warntxt.text
    signal clicked
    visible: true
    color:"red"
    Text {
        id: warntxt
        x: 1
        y: 8
        width: 241//321
        height: 56
        text: ""//"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\np, li { white-space: pre-wrap; }\n</style></head><body style=\" font-family:'Titillium Web'; font-size:9pt; font-weight:400; font-style:normal;\">\n<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">txt</span></p></body></html>"
        anchors.fill: parent
        font.pixelSize: 40
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "#ffffff"
        //textFormat: Text.RichText

    }
    MouseArea{
        anchors.fill:parent
        onClicked: {
            warn.clicked()
        }
    }
}

/*##^##
Designer {
    D{i:0;height:68;width:322}
}
##^##*/
