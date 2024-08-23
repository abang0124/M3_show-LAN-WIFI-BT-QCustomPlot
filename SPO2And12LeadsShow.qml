import QtQuick 2.12

Rectangle {
    width: 880
    height: 632
//    property alias leadsXmax: leadsOf12.maxOfX
//    property alias leadsXmin: leadsOf12.minOfX
//    property alias leadsYmax: leadsOf12.maxOfY
//    property alias leadsYmin: leadsOf12.minOfX
//    property alias spo2Xmax: spo2.maxOfX
//    property alias spo2Xmin: spo2.minOfX
//    property alias spo2Ymax: spo2.maxOfY
//    property alias spo2Ymin: spo2.minOfY
    Column{
        TwelveLeadsShow{
            id:leadsOf12

        }
        SPO2ChartShow{
            id:spo2

        }
    }
}

/*##^##
Designer {
    D{i:0;height:632;width:880}
}
##^##*/
