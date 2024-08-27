import QtQuick 2.12

Rectangle {
    width: 880
    height: 632
    signal sixLeadsUpClicked
    signal sixLeadsDownClicked
//    property alias spo2Xmax: spo2.maxOfX
//    property alias spo2Xmin: spo2.minOfX
//    property alias spo2Ymax: spo2.maxOfY
//    property alias spo2Ymin: spo2.minOfY
    Column{
        SixLeadsShow{
            id:leadsOf6
            onSixLeadsUpClicked: {
                sixLeadsUpClicked()
            }
            onSixLeadsDownClicked: {
                sixLeadsDownClicked()
            }

        }
        SPO2ChartShow{
            id:spo2

        }
    }
}


