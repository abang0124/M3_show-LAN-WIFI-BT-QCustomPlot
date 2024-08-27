import QtQuick 2.12

Rectangle {
    width: 880
    height: 632
    signal threeLeadsUpClicked
    signal threeLeadsDownClicked
//    property alias leadsXmax: leadsOf1.maxOfX
//    property alias leadsXmin: leadsOf1.minOfX
//    property alias leadsYmax: leadsOf1.maxOfY
//    property alias leadsYmin: leadsOf1.minOfX
//    property alias spo2Xmax: spo2.maxOfX
//    property alias spo2Xmin: spo2.minOfX
//    property alias spo2Ymax: spo2.maxOfY
//    property alias spo2Ymin: spo2.minOfY
    Column{
        OneLeadShow{
            id:leadsOf1
            onThreeLeadsUpClicked: {
                threeLeadsUpClicked()

            }
            onThreeLeadsDownClicked: {
                threeLeadsDownClicked()

            }

        }
        SPO2ChartShow{
            id:spo2

        }
    }
}


