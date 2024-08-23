import QtQuick 2.12

Rectangle {
    width: 880
    height: 632
//    property alias leadsXmax: leadsOf3.maxOfX
//    property alias leadsXmin: leadsOf3.minOfX
//    property alias leadsYmax: leadsOf3.maxOfY
//    property alias leadsYmin: leadsOf3.minOfX
//    property alias spo2Xmax: spo2.maxOfX
//    property alias spo2Xmin: spo2.minOfX
//    property alias spo2Ymax: spo2.maxOfY
//    property alias spo2Ymin: spo2.minOfY
    Column{
        OnlyThreeLeadsShow{
            id:leadsOf3

        }
        SPO2ChartShow{
            id:spo2

        }
    }
}


