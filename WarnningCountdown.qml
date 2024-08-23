import QtQuick 2.12

Rectangle {
    width: 220
    height: 68
    color: "#d8d8d8"
    property alias source: warnningPauseImage.source
    property alias countDownTime:warnningPauseCountTime.text
    property alias warnconTxt:warnningPauseLable.text   //切换报警暂停和 报警关闭
    property alias warnCountDownTimeContentVisible:warnningPauseCountTime.visible   //报警倒计时内容是否可见
    Image {
        id: warnningPauseImage
        x: 13
        y: 8
        width: 48
        height: 48
        source: "img/WarnningPause.png"
        fillMode: Image.PreserveAspectFit
    }

    Text {
        id: warnningPauseLable
        x: 67
        y: 17
        width: 71
        height: 31
        color: "#fd0000"
        text: "报警暂停"
        font.pixelSize: 20
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        font.bold: false
        textFormat: Text.RichText
    }

    Text {
        id: warnningPauseCountTime
        x: 144
        y: 17
        width: 56
        height: 31
        visible: true
        color: "#fd0000"
        text: "02:00"
        font.pixelSize: 16
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        textFormat: Text.RichText
    }
}
