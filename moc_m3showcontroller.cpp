/****************************************************************************
** Meta object code from reading C++ file 'm3showcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "m3showcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'm3showcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_M3ShowController_t {
    QByteArrayData data[286];
    char stringdata0[5046];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_M3ShowController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_M3ShowController_t qt_meta_stringdata_M3ShowController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "M3ShowController"
QT_MOC_LITERAL(1, 17, 22), // "updateSoftWare2DataAcq"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 20), // "softWareUpdataSucess"
QT_MOC_LITERAL(4, 62, 20), // "softWareUpdataFailed"
QT_MOC_LITERAL(5, 83, 12), // "fileNotExist"
QT_MOC_LITERAL(6, 96, 16), // "recordFileFailed"
QT_MOC_LITERAL(7, 113, 18), // "starDataAcquSignal"
QT_MOC_LITERAL(8, 132, 11), // "timeChanged"
QT_MOC_LITERAL(9, 144, 11), // "dateChanged"
QT_MOC_LITERAL(10, 156, 15), // "batValueChanged"
QT_MOC_LITERAL(11, 172, 17), // "chargeFlagChanged"
QT_MOC_LITERAL(12, 190, 16), // "heartRateChanged"
QT_MOC_LITERAL(13, 207, 14), // "bPValueChanged"
QT_MOC_LITERAL(14, 222, 14), // "spo2NumChanged"
QT_MOC_LITERAL(15, 237, 12), // "piNumChanged"
QT_MOC_LITERAL(16, 250, 18), // "columHeightChanged"
QT_MOC_LITERAL(17, 269, 22), // "list_SPO2_data_changed"
QT_MOC_LITERAL(18, 292, 11), // "test_signal"
QT_MOC_LITERAL(19, 304, 15), // "NIBPStartSignal"
QT_MOC_LITERAL(20, 320, 14), // "NIBPStopSignal"
QT_MOC_LITERAL(21, 335, 10), // "testsignal"
QT_MOC_LITERAL(22, 346, 14), // "QList<quint16>"
QT_MOC_LITERAL(23, 361, 26), // "list_ECG_data_show_changed"
QT_MOC_LITERAL(24, 388, 21), // "ecg3or12ChangedSignal"
QT_MOC_LITERAL(25, 410, 26), // "autoMeasureNIBPFlagChanged"
QT_MOC_LITERAL(26, 437, 24), // "autoMeasureMinuteChanged"
QT_MOC_LITERAL(27, 462, 20), // "recordECGFlagChanged"
QT_MOC_LITERAL(28, 483, 25), // "recordECGFlagChangeSignal"
QT_MOC_LITERAL(29, 509, 20), // "lpSelectIndexChanged"
QT_MOC_LITERAL(30, 530, 20), // "hpSelectIndexChanged"
QT_MOC_LITERAL(31, 551, 20), // "acSelectIndexChanged"
QT_MOC_LITERAL(32, 572, 18), // "patientTypeChanged"
QT_MOC_LITERAL(33, 591, 24), // "patientTypeChangedSignal"
QT_MOC_LITERAL(34, 616, 32), // "wideOrNarrowThresHoldPageChanged"
QT_MOC_LITERAL(35, 649, 34), // "wideOrNarrowThresHoldChoiceCh..."
QT_MOC_LITERAL(36, 684, 25), // "spo2ThresHoldValueChanged"
QT_MOC_LITERAL(37, 710, 25), // "spo2ThresHoldLevelChanged"
QT_MOC_LITERAL(38, 736, 27), // "bpSYSThresHoldValueHChanged"
QT_MOC_LITERAL(39, 764, 27), // "bpDIAThresHoldValueHChanged"
QT_MOC_LITERAL(40, 792, 27), // "bpSYSThresHoldValueLChanged"
QT_MOC_LITERAL(41, 820, 27), // "bpDIAThresHoldValueLChanged"
QT_MOC_LITERAL(42, 848, 26), // "bpSYSThresHoldLevelChanged"
QT_MOC_LITERAL(43, 875, 26), // "bpDIAThresHoldLevelChanged"
QT_MOC_LITERAL(44, 902, 18), // "hrFastValueChanged"
QT_MOC_LITERAL(45, 921, 18), // "hrFastLevelChanged"
QT_MOC_LITERAL(46, 940, 18), // "hrSlowValueChanged"
QT_MOC_LITERAL(47, 959, 18), // "hrSlowLevelChanged"
QT_MOC_LITERAL(48, 978, 29), // "spo2ThresHoldValueChangedWide"
QT_MOC_LITERAL(49, 1008, 29), // "spo2ThresHoldLevelChangedWide"
QT_MOC_LITERAL(50, 1038, 31), // "bpSYSThresHoldValueHChangedWide"
QT_MOC_LITERAL(51, 1070, 31), // "bpDIAThresHoldValueHChangedWide"
QT_MOC_LITERAL(52, 1102, 31), // "bpSYSThresHoldValueLChangedWide"
QT_MOC_LITERAL(53, 1134, 31), // "bpDIAThresHoldValueLChangedWide"
QT_MOC_LITERAL(54, 1166, 30), // "bpSYSThresHoldLevelChangedWide"
QT_MOC_LITERAL(55, 1197, 30), // "bpDIAThresHoldLevelChangedWide"
QT_MOC_LITERAL(56, 1228, 22), // "hrFastValueChangedWide"
QT_MOC_LITERAL(57, 1251, 22), // "hrFastLevelChangedWide"
QT_MOC_LITERAL(58, 1274, 22), // "hrSlowValueChangedWide"
QT_MOC_LITERAL(59, 1297, 22), // "hrSlowLevelChangedWide"
QT_MOC_LITERAL(60, 1320, 22), // "ECGDataProcessedSignal"
QT_MOC_LITERAL(61, 1343, 20), // "leadsShowTypeChanged"
QT_MOC_LITERAL(62, 1364, 13), // "batValSendSig"
QT_MOC_LITERAL(63, 1378, 15), // "gainTypeChanged"
QT_MOC_LITERAL(64, 1394, 16), // "speedTypeChanged"
QT_MOC_LITERAL(65, 1411, 15), // "leadsTypeChange"
QT_MOC_LITERAL(66, 1427, 20), // "warnMessage2MainPage"
QT_MOC_LITERAL(67, 1448, 8), // "warnType"
QT_MOC_LITERAL(68, 1457, 9), // "warnLevel"
QT_MOC_LITERAL(69, 1467, 15), // "warnAlarmSignal"
QT_MOC_LITERAL(70, 1483, 5), // "level"
QT_MOC_LITERAL(71, 1489, 16), // "leadsOffRAChange"
QT_MOC_LITERAL(72, 1506, 16), // "leadsOffLAChange"
QT_MOC_LITERAL(73, 1523, 16), // "leadsOffLLChange"
QT_MOC_LITERAL(74, 1540, 16), // "leadsOffV1Change"
QT_MOC_LITERAL(75, 1557, 16), // "leadsOffV2Change"
QT_MOC_LITERAL(76, 1574, 16), // "leadsOffV3Change"
QT_MOC_LITERAL(77, 1591, 16), // "leadsOffV4Change"
QT_MOC_LITERAL(78, 1608, 16), // "leadsOffV5Change"
QT_MOC_LITERAL(79, 1625, 16), // "leadsOffV6Change"
QT_MOC_LITERAL(80, 1642, 16), // "leadsOffRLChange"
QT_MOC_LITERAL(81, 1659, 20), // "leadIBaseLineChanged"
QT_MOC_LITERAL(82, 1680, 21), // "leadIIBaseLineChanged"
QT_MOC_LITERAL(83, 1702, 22), // "leadIIIBaseLineChanged"
QT_MOC_LITERAL(84, 1725, 22), // "leadaVRBaseLineChanged"
QT_MOC_LITERAL(85, 1748, 22), // "leadaVLBaseLineChanged"
QT_MOC_LITERAL(86, 1771, 22), // "leadaVFBaseLineChanged"
QT_MOC_LITERAL(87, 1794, 21), // "leadV1BaseLineChanged"
QT_MOC_LITERAL(88, 1816, 21), // "leadV2BaseLineChanged"
QT_MOC_LITERAL(89, 1838, 21), // "leadV3BaseLineChanged"
QT_MOC_LITERAL(90, 1860, 21), // "leadV4BaseLineChanged"
QT_MOC_LITERAL(91, 1882, 21), // "leadV5BaseLineChanged"
QT_MOC_LITERAL(92, 1904, 21), // "leadV6BaseLineChanged"
QT_MOC_LITERAL(93, 1926, 19), // "leadIMaxLineChanged"
QT_MOC_LITERAL(94, 1946, 20), // "leadIIMaxLineChanged"
QT_MOC_LITERAL(95, 1967, 21), // "leadIIIMaxLineChanged"
QT_MOC_LITERAL(96, 1989, 21), // "leadaVRMaxLineChanged"
QT_MOC_LITERAL(97, 2011, 21), // "leadaVLMaxLineChanged"
QT_MOC_LITERAL(98, 2033, 21), // "leadaVFMaxLineChanged"
QT_MOC_LITERAL(99, 2055, 20), // "leadV1MaxLineChanged"
QT_MOC_LITERAL(100, 2076, 20), // "leadV2MaxLineChanged"
QT_MOC_LITERAL(101, 2097, 20), // "leadV3MaxLineChanged"
QT_MOC_LITERAL(102, 2118, 20), // "leadV4MaxLineChanged"
QT_MOC_LITERAL(103, 2139, 20), // "leadV5MaxLineChanged"
QT_MOC_LITERAL(104, 2160, 20), // "leadV6MaxLineChanged"
QT_MOC_LITERAL(105, 2181, 19), // "setAlarmSoundVolume"
QT_MOC_LITERAL(106, 2201, 5), // "value"
QT_MOC_LITERAL(107, 2207, 22), // "ecgShowStopFlagChanged"
QT_MOC_LITERAL(108, 2230, 18), // "dateAandTimeChange"
QT_MOC_LITERAL(109, 2249, 20), // "warnCloseFlagChanged"
QT_MOC_LITERAL(110, 2270, 27), // "sendUILoadCompleted2dataAcq"
QT_MOC_LITERAL(111, 2298, 19), // "netTransFlagChanged"
QT_MOC_LITERAL(112, 2318, 20), // "lanMacAddressChanged"
QT_MOC_LITERAL(113, 2339, 19), // "lanIPAddressChanged"
QT_MOC_LITERAL(114, 2359, 17), // "lanNetMaskChanged"
QT_MOC_LITERAL(115, 2377, 17), // "lanNetGateChanged"
QT_MOC_LITERAL(116, 2395, 21), // "wlanMacAddressChanged"
QT_MOC_LITERAL(117, 2417, 20), // "wlanIPAddressChanged"
QT_MOC_LITERAL(118, 2438, 21), // "WifiServiceMapChanged"
QT_MOC_LITERAL(119, 2460, 22), // "serviceChangeCompleted"
QT_MOC_LITERAL(120, 2483, 19), // "btMacAddressChanged"
QT_MOC_LITERAL(121, 2503, 27), // "netChangedAndIPAddressGeted"
QT_MOC_LITERAL(122, 2531, 24), // "connectedWIFINameChanged"
QT_MOC_LITERAL(123, 2556, 16), // "bluetoothOpenSig"
QT_MOC_LITERAL(124, 2573, 11), // "btConnected"
QT_MOC_LITERAL(125, 2585, 14), // "btDisconnected"
QT_MOC_LITERAL(126, 2600, 12), // "btOpenResult"
QT_MOC_LITERAL(127, 2613, 17), // "time_upadate_slot"
QT_MOC_LITERAL(128, 2631, 11), // "onTestTimer"
QT_MOC_LITERAL(129, 2643, 24), // "onRecNIBPDataFromDataAcq"
QT_MOC_LITERAL(130, 2668, 15), // "QList<quint16>*"
QT_MOC_LITERAL(131, 2684, 11), // "NIBPSYSData"
QT_MOC_LITERAL(132, 2696, 11), // "NIBPDIAData"
QT_MOC_LITERAL(133, 2708, 24), // "onRecSPO2DataFromDataAcq"
QT_MOC_LITERAL(134, 2733, 14), // "QList<quint8>*"
QT_MOC_LITERAL(135, 2748, 2), // "PI"
QT_MOC_LITERAL(136, 2751, 4), // "data"
QT_MOC_LITERAL(137, 2756, 4), // "rata"
QT_MOC_LITERAL(138, 2761, 6), // "column"
QT_MOC_LITERAL(139, 2768, 5), // "waves"
QT_MOC_LITERAL(140, 2774, 5), // "state"
QT_MOC_LITERAL(141, 2780, 25), // "onRecHeartRateFromDataAcq"
QT_MOC_LITERAL(142, 2806, 9), // "heartRate"
QT_MOC_LITERAL(143, 2816, 29), // "onRecLeadsShowDataFromDataAcq"
QT_MOC_LITERAL(144, 2846, 14), // "QList<int>[12]"
QT_MOC_LITERAL(145, 2861, 24), // "onMeasureNIBPFlagChanged"
QT_MOC_LITERAL(146, 2886, 22), // "onMeasureMinuteChanged"
QT_MOC_LITERAL(147, 2909, 22), // "onRecordECGFlagChanged"
QT_MOC_LITERAL(148, 2932, 20), // "onPatientTypeChanged"
QT_MOC_LITERAL(149, 2953, 17), // "onRecBatValSignal"
QT_MOC_LITERAL(150, 2971, 3), // "val"
QT_MOC_LITERAL(151, 2975, 4), // "val2"
QT_MOC_LITERAL(152, 2980, 30), // "onRecLeadsOffSignalFromDataAcq"
QT_MOC_LITERAL(153, 3011, 12), // "leadsOffData"
QT_MOC_LITERAL(154, 3024, 20), // "onDataAndTimeChanged"
QT_MOC_LITERAL(155, 3045, 21), // "netTransFlagChangeRev"
QT_MOC_LITERAL(156, 3067, 20), // "onDBusServiceChanged"
QT_MOC_LITERAL(157, 3088, 4), // "type"
QT_MOC_LITERAL(158, 3093, 20), // "onRecCanGetIPAddress"
QT_MOC_LITERAL(159, 3114, 21), // "onNetTransFlagChanged"
QT_MOC_LITERAL(160, 3136, 24), // "onRecBluetoothOpenResult"
QT_MOC_LITERAL(161, 3161, 20), // "recordFileFailedSlot"
QT_MOC_LITERAL(162, 3182, 13), // "sPO2DataCount"
QT_MOC_LITERAL(163, 3196, 11), // "getSPO2Data"
QT_MOC_LITERAL(164, 3208, 10), // "QList<int>"
QT_MOC_LITERAL(165, 3219, 13), // "clearSPO2Data"
QT_MOC_LITERAL(166, 3233, 23), // "transmitNIBPStartSignal"
QT_MOC_LITERAL(167, 3257, 22), // "transmitNIBPStopSignal"
QT_MOC_LITERAL(168, 3280, 20), // "getECG1leadShowArray"
QT_MOC_LITERAL(169, 3301, 1), // "i"
QT_MOC_LITERAL(170, 3303, 15), // "getECGShowArray"
QT_MOC_LITERAL(171, 3319, 16), // "getECG6ShowArray"
QT_MOC_LITERAL(172, 3336, 17), // "getECG12ShowArray"
QT_MOC_LITERAL(173, 3354, 15), // "ecg3or12changed"
QT_MOC_LITERAL(174, 3370, 20), // "warnSetBackToDefalut"
QT_MOC_LITERAL(175, 3391, 12), // "clearECGData"
QT_MOC_LITERAL(176, 3404, 16), // "showOverAndClear"
QT_MOC_LITERAL(177, 3421, 26), // "setGetECGDataTimerFlagTrue"
QT_MOC_LITERAL(178, 3448, 27), // "setGetECGDataTimerFlagFalse"
QT_MOC_LITERAL(179, 3476, 9), // "alarmPlay"
QT_MOC_LITERAL(180, 3486, 16), // "alarmSoundVolume"
QT_MOC_LITERAL(181, 3503, 15), // "uiLoadCompleted"
QT_MOC_LITERAL(182, 3519, 10), // "enableWifi"
QT_MOC_LITERAL(183, 3530, 9), // "enableLan"
QT_MOC_LITERAL(184, 3540, 15), // "enableBluetooth"
QT_MOC_LITERAL(185, 3556, 16), // "setLanIPAdddress"
QT_MOC_LITERAL(186, 3573, 11), // "connectWifi"
QT_MOC_LITERAL(187, 3585, 8), // "wifiName"
QT_MOC_LITERAL(188, 3594, 8), // "passCode"
QT_MOC_LITERAL(189, 3603, 14), // "disconnectWifi"
QT_MOC_LITERAL(190, 3618, 8), // "scanWifi"
QT_MOC_LITERAL(191, 3627, 10), // "readBtName"
QT_MOC_LITERAL(192, 3638, 11), // "writeBtName"
QT_MOC_LITERAL(193, 3650, 14), // "updateSoftWare"
QT_MOC_LITERAL(194, 3665, 4), // "time"
QT_MOC_LITERAL(195, 3670, 4), // "date"
QT_MOC_LITERAL(196, 3675, 8), // "batValue"
QT_MOC_LITERAL(197, 3684, 10), // "chargeFlag"
QT_MOC_LITERAL(198, 3695, 7), // "bPValue"
QT_MOC_LITERAL(199, 3703, 19), // "autoMeasureNIBPFlag"
QT_MOC_LITERAL(200, 3723, 20), // "autoMeasureNIBPMinut"
QT_MOC_LITERAL(201, 3744, 7), // "spo2Num"
QT_MOC_LITERAL(202, 3752, 5), // "piNum"
QT_MOC_LITERAL(203, 3758, 11), // "columHeight"
QT_MOC_LITERAL(204, 3770, 13), // "recordECGFlag"
QT_MOC_LITERAL(205, 3784, 13), // "lpSelectIndex"
QT_MOC_LITERAL(206, 3798, 13), // "hpSelectIndex"
QT_MOC_LITERAL(207, 3812, 13), // "acSelectIndex"
QT_MOC_LITERAL(208, 3826, 11), // "patientType"
QT_MOC_LITERAL(209, 3838, 25), // "wideOrNarrowThresHoldPage"
QT_MOC_LITERAL(210, 3864, 27), // "wideOrNarrowThresHoldChoice"
QT_MOC_LITERAL(211, 3892, 18), // "spo2ThresHoldValue"
QT_MOC_LITERAL(212, 3911, 18), // "spo2ThresHoldLevel"
QT_MOC_LITERAL(213, 3930, 20), // "bpSYSThresHoldValueH"
QT_MOC_LITERAL(214, 3951, 20), // "bpSYSThresHoldValueL"
QT_MOC_LITERAL(215, 3972, 20), // "bpDIAThresHoldValueH"
QT_MOC_LITERAL(216, 3993, 20), // "bpDIAThresHoldValueL"
QT_MOC_LITERAL(217, 4014, 19), // "bpSYSThresHoldLevel"
QT_MOC_LITERAL(218, 4034, 19), // "bpDIAThresHoldLevel"
QT_MOC_LITERAL(219, 4054, 11), // "hrFastValue"
QT_MOC_LITERAL(220, 4066, 11), // "hrFastLevel"
QT_MOC_LITERAL(221, 4078, 11), // "hrSlowValue"
QT_MOC_LITERAL(222, 4090, 11), // "hrSlowLevel"
QT_MOC_LITERAL(223, 4102, 22), // "spo2ThresHoldValueWide"
QT_MOC_LITERAL(224, 4125, 22), // "spo2ThresHoldLevelWide"
QT_MOC_LITERAL(225, 4148, 24), // "bpSYSThresHoldValueHWide"
QT_MOC_LITERAL(226, 4173, 24), // "bpSYSThresHoldValueLWide"
QT_MOC_LITERAL(227, 4198, 24), // "bpDIAThresHoldValueHWide"
QT_MOC_LITERAL(228, 4223, 24), // "bpDIAThresHoldValueLWide"
QT_MOC_LITERAL(229, 4248, 23), // "bpSYSThresHoldLevelWide"
QT_MOC_LITERAL(230, 4272, 23), // "bpDIAThresHoldLevelWide"
QT_MOC_LITERAL(231, 4296, 15), // "hrFastValueWide"
QT_MOC_LITERAL(232, 4312, 15), // "hrFastLevelWide"
QT_MOC_LITERAL(233, 4328, 15), // "hrSlowValueWide"
QT_MOC_LITERAL(234, 4344, 15), // "hrSlowLevelWide"
QT_MOC_LITERAL(235, 4360, 13), // "leadsShowType"
QT_MOC_LITERAL(236, 4374, 8), // "gainType"
QT_MOC_LITERAL(237, 4383, 9), // "speedType"
QT_MOC_LITERAL(238, 4393, 9), // "leadsType"
QT_MOC_LITERAL(239, 4403, 10), // "leadsOffRA"
QT_MOC_LITERAL(240, 4414, 10), // "leadsOffLA"
QT_MOC_LITERAL(241, 4425, 10), // "leadsOffLL"
QT_MOC_LITERAL(242, 4436, 10), // "leadsOffRL"
QT_MOC_LITERAL(243, 4447, 10), // "leadsOffV1"
QT_MOC_LITERAL(244, 4458, 10), // "leadsOffV2"
QT_MOC_LITERAL(245, 4469, 10), // "leadsOffV3"
QT_MOC_LITERAL(246, 4480, 10), // "leadsOffV4"
QT_MOC_LITERAL(247, 4491, 10), // "leadsOffV5"
QT_MOC_LITERAL(248, 4502, 10), // "leadsOffV6"
QT_MOC_LITERAL(249, 4513, 13), // "leadIBaseLine"
QT_MOC_LITERAL(250, 4527, 14), // "leadIIBaseLine"
QT_MOC_LITERAL(251, 4542, 15), // "leadIIIBaseLine"
QT_MOC_LITERAL(252, 4558, 15), // "leadaVRBaseLine"
QT_MOC_LITERAL(253, 4574, 15), // "leadaVLBaseLine"
QT_MOC_LITERAL(254, 4590, 15), // "leadaVFBaseLine"
QT_MOC_LITERAL(255, 4606, 14), // "leadV1BaseLine"
QT_MOC_LITERAL(256, 4621, 14), // "leadV2BaseLine"
QT_MOC_LITERAL(257, 4636, 14), // "leadV3BaseLine"
QT_MOC_LITERAL(258, 4651, 14), // "leadV4BaseLine"
QT_MOC_LITERAL(259, 4666, 14), // "leadV5BaseLine"
QT_MOC_LITERAL(260, 4681, 14), // "leadV6BaseLine"
QT_MOC_LITERAL(261, 4696, 12), // "leadIMaxLine"
QT_MOC_LITERAL(262, 4709, 13), // "leadIIMaxLine"
QT_MOC_LITERAL(263, 4723, 14), // "leadIIIMaxLine"
QT_MOC_LITERAL(264, 4738, 14), // "leadaVRMaxLine"
QT_MOC_LITERAL(265, 4753, 14), // "leadaVLMaxLine"
QT_MOC_LITERAL(266, 4768, 14), // "leadaVFMaxLine"
QT_MOC_LITERAL(267, 4783, 13), // "leadV1MaxLine"
QT_MOC_LITERAL(268, 4797, 13), // "leadV2MaxLine"
QT_MOC_LITERAL(269, 4811, 13), // "leadV3MaxLine"
QT_MOC_LITERAL(270, 4825, 13), // "leadV4MaxLine"
QT_MOC_LITERAL(271, 4839, 13), // "leadV5MaxLine"
QT_MOC_LITERAL(272, 4853, 13), // "leadV6MaxLine"
QT_MOC_LITERAL(273, 4867, 15), // "ecgShowStopFlag"
QT_MOC_LITERAL(274, 4883, 11), // "dateAndTime"
QT_MOC_LITERAL(275, 4895, 13), // "warnCloseFlag"
QT_MOC_LITERAL(276, 4909, 12), // "netTransFlag"
QT_MOC_LITERAL(277, 4922, 13), // "lanMacAddress"
QT_MOC_LITERAL(278, 4936, 12), // "lanIPAddress"
QT_MOC_LITERAL(279, 4949, 10), // "lanNetMask"
QT_MOC_LITERAL(280, 4960, 10), // "lanNetGate"
QT_MOC_LITERAL(281, 4971, 14), // "wlanMacAddress"
QT_MOC_LITERAL(282, 4986, 13), // "wlanIPAddress"
QT_MOC_LITERAL(283, 5000, 17), // "connectedWIFIName"
QT_MOC_LITERAL(284, 5018, 14), // "wifiServiceMap"
QT_MOC_LITERAL(285, 5033, 12) // "btMacAddress"

    },
    "M3ShowController\0updateSoftWare2DataAcq\0"
    "\0softWareUpdataSucess\0softWareUpdataFailed\0"
    "fileNotExist\0recordFileFailed\0"
    "starDataAcquSignal\0timeChanged\0"
    "dateChanged\0batValueChanged\0"
    "chargeFlagChanged\0heartRateChanged\0"
    "bPValueChanged\0spo2NumChanged\0"
    "piNumChanged\0columHeightChanged\0"
    "list_SPO2_data_changed\0test_signal\0"
    "NIBPStartSignal\0NIBPStopSignal\0"
    "testsignal\0QList<quint16>\0"
    "list_ECG_data_show_changed\0"
    "ecg3or12ChangedSignal\0autoMeasureNIBPFlagChanged\0"
    "autoMeasureMinuteChanged\0recordECGFlagChanged\0"
    "recordECGFlagChangeSignal\0"
    "lpSelectIndexChanged\0hpSelectIndexChanged\0"
    "acSelectIndexChanged\0patientTypeChanged\0"
    "patientTypeChangedSignal\0"
    "wideOrNarrowThresHoldPageChanged\0"
    "wideOrNarrowThresHoldChoiceChanged\0"
    "spo2ThresHoldValueChanged\0"
    "spo2ThresHoldLevelChanged\0"
    "bpSYSThresHoldValueHChanged\0"
    "bpDIAThresHoldValueHChanged\0"
    "bpSYSThresHoldValueLChanged\0"
    "bpDIAThresHoldValueLChanged\0"
    "bpSYSThresHoldLevelChanged\0"
    "bpDIAThresHoldLevelChanged\0"
    "hrFastValueChanged\0hrFastLevelChanged\0"
    "hrSlowValueChanged\0hrSlowLevelChanged\0"
    "spo2ThresHoldValueChangedWide\0"
    "spo2ThresHoldLevelChangedWide\0"
    "bpSYSThresHoldValueHChangedWide\0"
    "bpDIAThresHoldValueHChangedWide\0"
    "bpSYSThresHoldValueLChangedWide\0"
    "bpDIAThresHoldValueLChangedWide\0"
    "bpSYSThresHoldLevelChangedWide\0"
    "bpDIAThresHoldLevelChangedWide\0"
    "hrFastValueChangedWide\0hrFastLevelChangedWide\0"
    "hrSlowValueChangedWide\0hrSlowLevelChangedWide\0"
    "ECGDataProcessedSignal\0leadsShowTypeChanged\0"
    "batValSendSig\0gainTypeChanged\0"
    "speedTypeChanged\0leadsTypeChange\0"
    "warnMessage2MainPage\0warnType\0warnLevel\0"
    "warnAlarmSignal\0level\0leadsOffRAChange\0"
    "leadsOffLAChange\0leadsOffLLChange\0"
    "leadsOffV1Change\0leadsOffV2Change\0"
    "leadsOffV3Change\0leadsOffV4Change\0"
    "leadsOffV5Change\0leadsOffV6Change\0"
    "leadsOffRLChange\0leadIBaseLineChanged\0"
    "leadIIBaseLineChanged\0leadIIIBaseLineChanged\0"
    "leadaVRBaseLineChanged\0leadaVLBaseLineChanged\0"
    "leadaVFBaseLineChanged\0leadV1BaseLineChanged\0"
    "leadV2BaseLineChanged\0leadV3BaseLineChanged\0"
    "leadV4BaseLineChanged\0leadV5BaseLineChanged\0"
    "leadV6BaseLineChanged\0leadIMaxLineChanged\0"
    "leadIIMaxLineChanged\0leadIIIMaxLineChanged\0"
    "leadaVRMaxLineChanged\0leadaVLMaxLineChanged\0"
    "leadaVFMaxLineChanged\0leadV1MaxLineChanged\0"
    "leadV2MaxLineChanged\0leadV3MaxLineChanged\0"
    "leadV4MaxLineChanged\0leadV5MaxLineChanged\0"
    "leadV6MaxLineChanged\0setAlarmSoundVolume\0"
    "value\0ecgShowStopFlagChanged\0"
    "dateAandTimeChange\0warnCloseFlagChanged\0"
    "sendUILoadCompleted2dataAcq\0"
    "netTransFlagChanged\0lanMacAddressChanged\0"
    "lanIPAddressChanged\0lanNetMaskChanged\0"
    "lanNetGateChanged\0wlanMacAddressChanged\0"
    "wlanIPAddressChanged\0WifiServiceMapChanged\0"
    "serviceChangeCompleted\0btMacAddressChanged\0"
    "netChangedAndIPAddressGeted\0"
    "connectedWIFINameChanged\0bluetoothOpenSig\0"
    "btConnected\0btDisconnected\0btOpenResult\0"
    "time_upadate_slot\0onTestTimer\0"
    "onRecNIBPDataFromDataAcq\0QList<quint16>*\0"
    "NIBPSYSData\0NIBPDIAData\0"
    "onRecSPO2DataFromDataAcq\0QList<quint8>*\0"
    "PI\0data\0rata\0column\0waves\0state\0"
    "onRecHeartRateFromDataAcq\0heartRate\0"
    "onRecLeadsShowDataFromDataAcq\0"
    "QList<int>[12]\0onMeasureNIBPFlagChanged\0"
    "onMeasureMinuteChanged\0onRecordECGFlagChanged\0"
    "onPatientTypeChanged\0onRecBatValSignal\0"
    "val\0val2\0onRecLeadsOffSignalFromDataAcq\0"
    "leadsOffData\0onDataAndTimeChanged\0"
    "netTransFlagChangeRev\0onDBusServiceChanged\0"
    "type\0onRecCanGetIPAddress\0"
    "onNetTransFlagChanged\0onRecBluetoothOpenResult\0"
    "recordFileFailedSlot\0sPO2DataCount\0"
    "getSPO2Data\0QList<int>\0clearSPO2Data\0"
    "transmitNIBPStartSignal\0transmitNIBPStopSignal\0"
    "getECG1leadShowArray\0i\0getECGShowArray\0"
    "getECG6ShowArray\0getECG12ShowArray\0"
    "ecg3or12changed\0warnSetBackToDefalut\0"
    "clearECGData\0showOverAndClear\0"
    "setGetECGDataTimerFlagTrue\0"
    "setGetECGDataTimerFlagFalse\0alarmPlay\0"
    "alarmSoundVolume\0uiLoadCompleted\0"
    "enableWifi\0enableLan\0enableBluetooth\0"
    "setLanIPAdddress\0connectWifi\0wifiName\0"
    "passCode\0disconnectWifi\0scanWifi\0"
    "readBtName\0writeBtName\0updateSoftWare\0"
    "time\0date\0batValue\0chargeFlag\0bPValue\0"
    "autoMeasureNIBPFlag\0autoMeasureNIBPMinut\0"
    "spo2Num\0piNum\0columHeight\0recordECGFlag\0"
    "lpSelectIndex\0hpSelectIndex\0acSelectIndex\0"
    "patientType\0wideOrNarrowThresHoldPage\0"
    "wideOrNarrowThresHoldChoice\0"
    "spo2ThresHoldValue\0spo2ThresHoldLevel\0"
    "bpSYSThresHoldValueH\0bpSYSThresHoldValueL\0"
    "bpDIAThresHoldValueH\0bpDIAThresHoldValueL\0"
    "bpSYSThresHoldLevel\0bpDIAThresHoldLevel\0"
    "hrFastValue\0hrFastLevel\0hrSlowValue\0"
    "hrSlowLevel\0spo2ThresHoldValueWide\0"
    "spo2ThresHoldLevelWide\0bpSYSThresHoldValueHWide\0"
    "bpSYSThresHoldValueLWide\0"
    "bpDIAThresHoldValueHWide\0"
    "bpDIAThresHoldValueLWide\0"
    "bpSYSThresHoldLevelWide\0bpDIAThresHoldLevelWide\0"
    "hrFastValueWide\0hrFastLevelWide\0"
    "hrSlowValueWide\0hrSlowLevelWide\0"
    "leadsShowType\0gainType\0speedType\0"
    "leadsType\0leadsOffRA\0leadsOffLA\0"
    "leadsOffLL\0leadsOffRL\0leadsOffV1\0"
    "leadsOffV2\0leadsOffV3\0leadsOffV4\0"
    "leadsOffV5\0leadsOffV6\0leadIBaseLine\0"
    "leadIIBaseLine\0leadIIIBaseLine\0"
    "leadaVRBaseLine\0leadaVLBaseLine\0"
    "leadaVFBaseLine\0leadV1BaseLine\0"
    "leadV2BaseLine\0leadV3BaseLine\0"
    "leadV4BaseLine\0leadV5BaseLine\0"
    "leadV6BaseLine\0leadIMaxLine\0leadIIMaxLine\0"
    "leadIIIMaxLine\0leadaVRMaxLine\0"
    "leadaVLMaxLine\0leadaVFMaxLine\0"
    "leadV1MaxLine\0leadV2MaxLine\0leadV3MaxLine\0"
    "leadV4MaxLine\0leadV5MaxLine\0leadV6MaxLine\0"
    "ecgShowStopFlag\0dateAndTime\0warnCloseFlag\0"
    "netTransFlag\0lanMacAddress\0lanIPAddress\0"
    "lanNetMask\0lanNetGate\0wlanMacAddress\0"
    "wlanIPAddress\0connectedWIFIName\0"
    "wifiServiceMap\0btMacAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_M3ShowController[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
     167,   14, // methods
      93, 1104, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
     120,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  849,    2, 0x06 /* Public */,
       3,    0,  850,    2, 0x06 /* Public */,
       4,    0,  851,    2, 0x06 /* Public */,
       5,    0,  852,    2, 0x06 /* Public */,
       6,    0,  853,    2, 0x06 /* Public */,
       7,    0,  854,    2, 0x06 /* Public */,
       8,    0,  855,    2, 0x06 /* Public */,
       9,    0,  856,    2, 0x06 /* Public */,
      10,    0,  857,    2, 0x06 /* Public */,
      11,    0,  858,    2, 0x06 /* Public */,
      12,    0,  859,    2, 0x06 /* Public */,
      13,    0,  860,    2, 0x06 /* Public */,
      14,    0,  861,    2, 0x06 /* Public */,
      15,    0,  862,    2, 0x06 /* Public */,
      16,    0,  863,    2, 0x06 /* Public */,
      17,    0,  864,    2, 0x06 /* Public */,
      18,    0,  865,    2, 0x06 /* Public */,
      19,    0,  866,    2, 0x06 /* Public */,
      20,    0,  867,    2, 0x06 /* Public */,
      21,    2,  868,    2, 0x06 /* Public */,
      23,    0,  873,    2, 0x06 /* Public */,
      24,    1,  874,    2, 0x06 /* Public */,
      25,    0,  877,    2, 0x06 /* Public */,
      26,    0,  878,    2, 0x06 /* Public */,
      27,    0,  879,    2, 0x06 /* Public */,
      28,    1,  880,    2, 0x06 /* Public */,
      29,    1,  883,    2, 0x06 /* Public */,
      30,    1,  886,    2, 0x06 /* Public */,
      31,    1,  889,    2, 0x06 /* Public */,
      32,    0,  892,    2, 0x06 /* Public */,
      33,    1,  893,    2, 0x06 /* Public */,
      34,    0,  896,    2, 0x06 /* Public */,
      35,    0,  897,    2, 0x06 /* Public */,
      36,    0,  898,    2, 0x06 /* Public */,
      37,    0,  899,    2, 0x06 /* Public */,
      38,    0,  900,    2, 0x06 /* Public */,
      39,    0,  901,    2, 0x06 /* Public */,
      40,    0,  902,    2, 0x06 /* Public */,
      41,    0,  903,    2, 0x06 /* Public */,
      42,    0,  904,    2, 0x06 /* Public */,
      43,    0,  905,    2, 0x06 /* Public */,
      44,    0,  906,    2, 0x06 /* Public */,
      45,    0,  907,    2, 0x06 /* Public */,
      46,    0,  908,    2, 0x06 /* Public */,
      47,    0,  909,    2, 0x06 /* Public */,
      48,    0,  910,    2, 0x06 /* Public */,
      49,    0,  911,    2, 0x06 /* Public */,
      50,    0,  912,    2, 0x06 /* Public */,
      51,    0,  913,    2, 0x06 /* Public */,
      52,    0,  914,    2, 0x06 /* Public */,
      53,    0,  915,    2, 0x06 /* Public */,
      54,    0,  916,    2, 0x06 /* Public */,
      55,    0,  917,    2, 0x06 /* Public */,
      56,    0,  918,    2, 0x06 /* Public */,
      57,    0,  919,    2, 0x06 /* Public */,
      58,    0,  920,    2, 0x06 /* Public */,
      59,    0,  921,    2, 0x06 /* Public */,
      60,    0,  922,    2, 0x06 /* Public */,
      61,    1,  923,    2, 0x06 /* Public */,
      62,    2,  926,    2, 0x06 /* Public */,
      63,    0,  931,    2, 0x06 /* Public */,
      64,    0,  932,    2, 0x06 /* Public */,
      65,    0,  933,    2, 0x06 /* Public */,
      66,    2,  934,    2, 0x06 /* Public */,
      69,    1,  939,    2, 0x06 /* Public */,
      71,    0,  942,    2, 0x06 /* Public */,
      72,    0,  943,    2, 0x06 /* Public */,
      73,    0,  944,    2, 0x06 /* Public */,
      74,    0,  945,    2, 0x06 /* Public */,
      75,    0,  946,    2, 0x06 /* Public */,
      76,    0,  947,    2, 0x06 /* Public */,
      77,    0,  948,    2, 0x06 /* Public */,
      78,    0,  949,    2, 0x06 /* Public */,
      79,    0,  950,    2, 0x06 /* Public */,
      80,    0,  951,    2, 0x06 /* Public */,
      81,    0,  952,    2, 0x06 /* Public */,
      82,    0,  953,    2, 0x06 /* Public */,
      83,    0,  954,    2, 0x06 /* Public */,
      84,    0,  955,    2, 0x06 /* Public */,
      85,    0,  956,    2, 0x06 /* Public */,
      86,    0,  957,    2, 0x06 /* Public */,
      87,    0,  958,    2, 0x06 /* Public */,
      88,    0,  959,    2, 0x06 /* Public */,
      89,    0,  960,    2, 0x06 /* Public */,
      90,    0,  961,    2, 0x06 /* Public */,
      91,    0,  962,    2, 0x06 /* Public */,
      92,    0,  963,    2, 0x06 /* Public */,
      93,    0,  964,    2, 0x06 /* Public */,
      94,    0,  965,    2, 0x06 /* Public */,
      95,    0,  966,    2, 0x06 /* Public */,
      96,    0,  967,    2, 0x06 /* Public */,
      97,    0,  968,    2, 0x06 /* Public */,
      98,    0,  969,    2, 0x06 /* Public */,
      99,    0,  970,    2, 0x06 /* Public */,
     100,    0,  971,    2, 0x06 /* Public */,
     101,    0,  972,    2, 0x06 /* Public */,
     102,    0,  973,    2, 0x06 /* Public */,
     103,    0,  974,    2, 0x06 /* Public */,
     104,    0,  975,    2, 0x06 /* Public */,
     105,    1,  976,    2, 0x06 /* Public */,
     107,    0,  979,    2, 0x06 /* Public */,
     108,    0,  980,    2, 0x06 /* Public */,
     109,    0,  981,    2, 0x06 /* Public */,
     110,    0,  982,    2, 0x06 /* Public */,
     111,    0,  983,    2, 0x06 /* Public */,
     112,    0,  984,    2, 0x06 /* Public */,
     113,    0,  985,    2, 0x06 /* Public */,
     114,    0,  986,    2, 0x06 /* Public */,
     115,    0,  987,    2, 0x06 /* Public */,
     116,    0,  988,    2, 0x06 /* Public */,
     117,    0,  989,    2, 0x06 /* Public */,
     118,    0,  990,    2, 0x06 /* Public */,
     119,    0,  991,    2, 0x06 /* Public */,
     120,    0,  992,    2, 0x06 /* Public */,
     121,    0,  993,    2, 0x06 /* Public */,
     122,    0,  994,    2, 0x06 /* Public */,
     123,    1,  995,    2, 0x06 /* Public */,
     124,    0,  998,    2, 0x06 /* Public */,
     125,    0,  999,    2, 0x06 /* Public */,
     126,    1, 1000,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
     127,    0, 1003,    2, 0x0a /* Public */,
     128,    0, 1004,    2, 0x0a /* Public */,
     129,    2, 1005,    2, 0x0a /* Public */,
     133,    6, 1010,    2, 0x0a /* Public */,
     141,    1, 1023,    2, 0x0a /* Public */,
     143,    1, 1026,    2, 0x0a /* Public */,
     145,    0, 1029,    2, 0x0a /* Public */,
     146,    0, 1030,    2, 0x0a /* Public */,
     147,    0, 1031,    2, 0x0a /* Public */,
     148,    0, 1032,    2, 0x0a /* Public */,
     149,    2, 1033,    2, 0x0a /* Public */,
     152,    1, 1038,    2, 0x0a /* Public */,
     154,    0, 1041,    2, 0x0a /* Public */,
     155,    0, 1042,    2, 0x0a /* Public */,
     156,    1, 1043,    2, 0x0a /* Public */,
     158,    0, 1046,    2, 0x0a /* Public */,
     159,    0, 1047,    2, 0x0a /* Public */,
     160,    2, 1048,    2, 0x0a /* Public */,
     161,    0, 1053,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
     162,    0, 1054,    2, 0x02 /* Public */,
     163,    0, 1055,    2, 0x02 /* Public */,
     165,    0, 1056,    2, 0x02 /* Public */,
     166,    0, 1057,    2, 0x02 /* Public */,
     167,    0, 1058,    2, 0x02 /* Public */,
     168,    1, 1059,    2, 0x02 /* Public */,
     170,    1, 1062,    2, 0x02 /* Public */,
     171,    1, 1065,    2, 0x02 /* Public */,
     172,    1, 1068,    2, 0x02 /* Public */,
     173,    1, 1071,    2, 0x02 /* Public */,
     174,    0, 1074,    2, 0x02 /* Public */,
     175,    0, 1075,    2, 0x02 /* Public */,
     176,    0, 1076,    2, 0x02 /* Public */,
     177,    0, 1077,    2, 0x02 /* Public */,
     178,    0, 1078,    2, 0x02 /* Public */,
     179,    1, 1079,    2, 0x02 /* Public */,
     180,    1, 1082,    2, 0x02 /* Public */,
     181,    0, 1085,    2, 0x02 /* Public */,
     182,    0, 1086,    2, 0x02 /* Public */,
     183,    0, 1087,    2, 0x02 /* Public */,
     184,    0, 1088,    2, 0x02 /* Public */,
     185,    0, 1089,    2, 0x02 /* Public */,
     186,    2, 1090,    2, 0x02 /* Public */,
     189,    1, 1095,    2, 0x02 /* Public */,
     190,    0, 1098,    2, 0x02 /* Public */,
     191,    0, 1099,    2, 0x02 /* Public */,
     192,    1, 1100,    2, 0x02 /* Public */,
     193,    0, 1103,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22, 0x80000000 | 22,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UChar,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   67,   68,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  106,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 130, 0x80000000 | 130,  131,  132,
    QMetaType::Void, 0x80000000 | 134, 0x80000000 | 134, 0x80000000 | 134, 0x80000000 | 134, 0x80000000 | 134, 0x80000000 | 134,  135,  136,  137,  138,  139,  140,
    QMetaType::Void, QMetaType::UShort,  142,
    QMetaType::Void, 0x80000000 | 144,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,  150,  151,
    QMetaType::Void, QMetaType::Int,  153,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,  157,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool, QMetaType::QString,    2,    2,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Int,
    0x80000000 | 164,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 164, QMetaType::Int,  169,
    0x80000000 | 164, QMetaType::Int,  169,
    0x80000000 | 164, QMetaType::Int,  169,
    0x80000000 | 164, QMetaType::Int,  169,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   70,
    QMetaType::Void, QMetaType::Int,  106,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,  187,  188,
    QMetaType::Void, QMetaType::QString,  187,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

 // properties: name, type, flags
     194, QMetaType::QString, 0x00495103,
     195, QMetaType::QString, 0x00495003,
     196, QMetaType::UInt, 0x00495103,
     197, QMetaType::Bool, 0x00495103,
     142, QMetaType::QString, 0x00495103,
     198, QMetaType::QString, 0x00495103,
     199, QMetaType::Bool, 0x00495003,
     200, QMetaType::Int, 0x00495003,
     201, QMetaType::QString, 0x00495103,
     202, QMetaType::QString, 0x00495003,
     203, QMetaType::UChar, 0x00495003,
     204, QMetaType::Bool, 0x00495103,
     205, QMetaType::UChar, 0x00495003,
     206, QMetaType::UChar, 0x00495003,
     207, QMetaType::UChar, 0x00495003,
     208, QMetaType::UChar, 0x00495103,
     209, QMetaType::Bool, 0x00495103,
     210, QMetaType::Bool, 0x00495103,
     211, QMetaType::UChar, 0x00495003,
     212, QMetaType::UChar, 0x00495003,
     213, QMetaType::UChar, 0x00495003,
     214, QMetaType::UChar, 0x00495003,
     215, QMetaType::UChar, 0x00495003,
     216, QMetaType::UChar, 0x00495003,
     217, QMetaType::UChar, 0x00495003,
     218, QMetaType::UChar, 0x00495003,
     219, QMetaType::UChar, 0x00495003,
     220, QMetaType::UChar, 0x00495003,
     221, QMetaType::UChar, 0x00495003,
     222, QMetaType::UChar, 0x00495003,
     223, QMetaType::UChar, 0x00495003,
     224, QMetaType::UChar, 0x00495003,
     225, QMetaType::UChar, 0x00495003,
     226, QMetaType::UChar, 0x00495003,
     227, QMetaType::UChar, 0x00495003,
     228, QMetaType::UChar, 0x00495003,
     229, QMetaType::UChar, 0x00495003,
     230, QMetaType::UChar, 0x00495003,
     231, QMetaType::UChar, 0x00495003,
     232, QMetaType::UChar, 0x00495003,
     233, QMetaType::UChar, 0x00495003,
     234, QMetaType::UChar, 0x00495003,
     235, QMetaType::UChar, 0x00495103,
     236, QMetaType::UChar, 0x00495003,
     237, QMetaType::UChar, 0x00495003,
     238, QMetaType::UChar, 0x00495003,
     239, QMetaType::Bool, 0x00495003,
     240, QMetaType::Bool, 0x00495003,
     241, QMetaType::Bool, 0x00495003,
     242, QMetaType::Bool, 0x00495003,
     243, QMetaType::Bool, 0x00495003,
     244, QMetaType::Bool, 0x00495003,
     245, QMetaType::Bool, 0x00495003,
     246, QMetaType::Bool, 0x00495003,
     247, QMetaType::Bool, 0x00495003,
     248, QMetaType::Bool, 0x00495003,
     249, QMetaType::Int, 0x00495003,
     250, QMetaType::Int, 0x00495003,
     251, QMetaType::Int, 0x00495003,
     252, QMetaType::Int, 0x00495003,
     253, QMetaType::Int, 0x00495003,
     254, QMetaType::Int, 0x00495003,
     255, QMetaType::Int, 0x00495003,
     256, QMetaType::Int, 0x00495003,
     257, QMetaType::Int, 0x00495003,
     258, QMetaType::Int, 0x00495003,
     259, QMetaType::Int, 0x00495003,
     260, QMetaType::Int, 0x00495003,
     261, QMetaType::Int, 0x00495003,
     262, QMetaType::Int, 0x00495003,
     263, QMetaType::Int, 0x00495003,
     264, QMetaType::Int, 0x00495003,
     265, QMetaType::Int, 0x00495003,
     266, QMetaType::Int, 0x00495003,
     267, QMetaType::Int, 0x00495003,
     268, QMetaType::Int, 0x00495003,
     269, QMetaType::Int, 0x00495003,
     270, QMetaType::Int, 0x00495003,
     271, QMetaType::Int, 0x00495003,
     272, QMetaType::Int, 0x00495003,
     273, QMetaType::Bool, 0x00495003,
     274, QMetaType::QString, 0x00495003,
     275, QMetaType::Bool, 0x00495003,
     276, QMetaType::UChar, 0x00495003,
     277, QMetaType::QString, 0x00495003,
     278, QMetaType::QString, 0x00495003,
     279, QMetaType::QString, 0x00495003,
     280, QMetaType::QString, 0x00495003,
     281, QMetaType::QString, 0x00495003,
     282, QMetaType::QString, 0x00495003,
     283, QMetaType::QString, 0x00495003,
     284, QMetaType::QVariantMap, 0x00495103,
     285, QMetaType::QString, 0x00495003,

 // properties: notify_signal_id
       6,
       7,
       8,
       9,
      10,
      11,
      22,
      23,
      12,
      13,
      14,
      24,
      26,
      27,
      28,
      29,
      31,
      32,
      33,
      34,
      35,
      37,
      36,
      38,
      39,
      40,
      41,
      42,
      43,
      44,
      45,
      46,
      47,
      49,
      48,
      50,
      51,
      52,
      53,
      54,
      55,
      56,
      58,
      60,
      61,
      62,
      65,
      66,
      67,
      74,
      68,
      69,
      70,
      71,
      72,
      73,
      75,
      76,
      77,
      78,
      79,
      80,
      81,
      82,
      83,
      84,
      85,
      86,
      87,
      88,
      89,
      90,
      91,
      92,
      93,
      94,
      95,
      96,
      97,
      98,
     100,
     101,
     102,
     104,
     105,
     106,
     107,
     108,
     109,
     110,
     115,
     111,
     113,

       0        // eod
};

void M3ShowController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<M3ShowController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateSoftWare2DataAcq(); break;
        case 1: _t->softWareUpdataSucess(); break;
        case 2: _t->softWareUpdataFailed(); break;
        case 3: _t->fileNotExist(); break;
        case 4: _t->recordFileFailed(); break;
        case 5: _t->starDataAcquSignal(); break;
        case 6: _t->timeChanged(); break;
        case 7: _t->dateChanged(); break;
        case 8: _t->batValueChanged(); break;
        case 9: _t->chargeFlagChanged(); break;
        case 10: _t->heartRateChanged(); break;
        case 11: _t->bPValueChanged(); break;
        case 12: _t->spo2NumChanged(); break;
        case 13: _t->piNumChanged(); break;
        case 14: _t->columHeightChanged(); break;
        case 15: _t->list_SPO2_data_changed(); break;
        case 16: _t->test_signal(); break;
        case 17: _t->NIBPStartSignal(); break;
        case 18: _t->NIBPStopSignal(); break;
        case 19: _t->testsignal((*reinterpret_cast< QList<quint16>(*)>(_a[1])),(*reinterpret_cast< QList<quint16>(*)>(_a[2]))); break;
        case 20: _t->list_ECG_data_show_changed(); break;
        case 21: _t->ecg3or12ChangedSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->autoMeasureNIBPFlagChanged(); break;
        case 23: _t->autoMeasureMinuteChanged(); break;
        case 24: _t->recordECGFlagChanged(); break;
        case 25: _t->recordECGFlagChangeSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 26: _t->lpSelectIndexChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 27: _t->hpSelectIndexChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 28: _t->acSelectIndexChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 29: _t->patientTypeChanged(); break;
        case 30: _t->patientTypeChangedSignal((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 31: _t->wideOrNarrowThresHoldPageChanged(); break;
        case 32: _t->wideOrNarrowThresHoldChoiceChanged(); break;
        case 33: _t->spo2ThresHoldValueChanged(); break;
        case 34: _t->spo2ThresHoldLevelChanged(); break;
        case 35: _t->bpSYSThresHoldValueHChanged(); break;
        case 36: _t->bpDIAThresHoldValueHChanged(); break;
        case 37: _t->bpSYSThresHoldValueLChanged(); break;
        case 38: _t->bpDIAThresHoldValueLChanged(); break;
        case 39: _t->bpSYSThresHoldLevelChanged(); break;
        case 40: _t->bpDIAThresHoldLevelChanged(); break;
        case 41: _t->hrFastValueChanged(); break;
        case 42: _t->hrFastLevelChanged(); break;
        case 43: _t->hrSlowValueChanged(); break;
        case 44: _t->hrSlowLevelChanged(); break;
        case 45: _t->spo2ThresHoldValueChangedWide(); break;
        case 46: _t->spo2ThresHoldLevelChangedWide(); break;
        case 47: _t->bpSYSThresHoldValueHChangedWide(); break;
        case 48: _t->bpDIAThresHoldValueHChangedWide(); break;
        case 49: _t->bpSYSThresHoldValueLChangedWide(); break;
        case 50: _t->bpDIAThresHoldValueLChangedWide(); break;
        case 51: _t->bpSYSThresHoldLevelChangedWide(); break;
        case 52: _t->bpDIAThresHoldLevelChangedWide(); break;
        case 53: _t->hrFastValueChangedWide(); break;
        case 54: _t->hrFastLevelChangedWide(); break;
        case 55: _t->hrSlowValueChangedWide(); break;
        case 56: _t->hrSlowLevelChangedWide(); break;
        case 57: _t->ECGDataProcessedSignal(); break;
        case 58: _t->leadsShowTypeChanged((*reinterpret_cast< quint8(*)>(_a[1]))); break;
        case 59: _t->batValSendSig((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 60: _t->gainTypeChanged(); break;
        case 61: _t->speedTypeChanged(); break;
        case 62: _t->leadsTypeChange(); break;
        case 63: _t->warnMessage2MainPage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 64: _t->warnAlarmSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 65: _t->leadsOffRAChange(); break;
        case 66: _t->leadsOffLAChange(); break;
        case 67: _t->leadsOffLLChange(); break;
        case 68: _t->leadsOffV1Change(); break;
        case 69: _t->leadsOffV2Change(); break;
        case 70: _t->leadsOffV3Change(); break;
        case 71: _t->leadsOffV4Change(); break;
        case 72: _t->leadsOffV5Change(); break;
        case 73: _t->leadsOffV6Change(); break;
        case 74: _t->leadsOffRLChange(); break;
        case 75: _t->leadIBaseLineChanged(); break;
        case 76: _t->leadIIBaseLineChanged(); break;
        case 77: _t->leadIIIBaseLineChanged(); break;
        case 78: _t->leadaVRBaseLineChanged(); break;
        case 79: _t->leadaVLBaseLineChanged(); break;
        case 80: _t->leadaVFBaseLineChanged(); break;
        case 81: _t->leadV1BaseLineChanged(); break;
        case 82: _t->leadV2BaseLineChanged(); break;
        case 83: _t->leadV3BaseLineChanged(); break;
        case 84: _t->leadV4BaseLineChanged(); break;
        case 85: _t->leadV5BaseLineChanged(); break;
        case 86: _t->leadV6BaseLineChanged(); break;
        case 87: _t->leadIMaxLineChanged(); break;
        case 88: _t->leadIIMaxLineChanged(); break;
        case 89: _t->leadIIIMaxLineChanged(); break;
        case 90: _t->leadaVRMaxLineChanged(); break;
        case 91: _t->leadaVLMaxLineChanged(); break;
        case 92: _t->leadaVFMaxLineChanged(); break;
        case 93: _t->leadV1MaxLineChanged(); break;
        case 94: _t->leadV2MaxLineChanged(); break;
        case 95: _t->leadV3MaxLineChanged(); break;
        case 96: _t->leadV4MaxLineChanged(); break;
        case 97: _t->leadV5MaxLineChanged(); break;
        case 98: _t->leadV6MaxLineChanged(); break;
        case 99: _t->setAlarmSoundVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 100: _t->ecgShowStopFlagChanged(); break;
        case 101: _t->dateAandTimeChange(); break;
        case 102: _t->warnCloseFlagChanged(); break;
        case 103: _t->sendUILoadCompleted2dataAcq(); break;
        case 104: _t->netTransFlagChanged(); break;
        case 105: _t->lanMacAddressChanged(); break;
        case 106: _t->lanIPAddressChanged(); break;
        case 107: _t->lanNetMaskChanged(); break;
        case 108: _t->lanNetGateChanged(); break;
        case 109: _t->wlanMacAddressChanged(); break;
        case 110: _t->wlanIPAddressChanged(); break;
        case 111: _t->WifiServiceMapChanged(); break;
        case 112: _t->serviceChangeCompleted(); break;
        case 113: _t->btMacAddressChanged(); break;
        case 114: _t->netChangedAndIPAddressGeted(); break;
        case 115: _t->connectedWIFINameChanged(); break;
        case 116: _t->bluetoothOpenSig((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 117: _t->btConnected(); break;
        case 118: _t->btDisconnected(); break;
        case 119: _t->btOpenResult((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 120: _t->time_upadate_slot(); break;
        case 121: _t->onTestTimer(); break;
        case 122: _t->onRecNIBPDataFromDataAcq((*reinterpret_cast< QList<quint16>*(*)>(_a[1])),(*reinterpret_cast< QList<quint16>*(*)>(_a[2]))); break;
        case 123: _t->onRecSPO2DataFromDataAcq((*reinterpret_cast< QList<quint8>*(*)>(_a[1])),(*reinterpret_cast< QList<quint8>*(*)>(_a[2])),(*reinterpret_cast< QList<quint8>*(*)>(_a[3])),(*reinterpret_cast< QList<quint8>*(*)>(_a[4])),(*reinterpret_cast< QList<quint8>*(*)>(_a[5])),(*reinterpret_cast< QList<quint8>*(*)>(_a[6]))); break;
        case 124: _t->onRecHeartRateFromDataAcq((*reinterpret_cast< quint16(*)>(_a[1]))); break;
        case 125: _t->onRecLeadsShowDataFromDataAcq((*reinterpret_cast< QList<int>(*)[12]>(_a[1]))); break;
        case 126: _t->onMeasureNIBPFlagChanged(); break;
        case 127: _t->onMeasureMinuteChanged(); break;
        case 128: _t->onRecordECGFlagChanged(); break;
        case 129: _t->onPatientTypeChanged(); break;
        case 130: _t->onRecBatValSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 131: _t->onRecLeadsOffSignalFromDataAcq((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 132: _t->onDataAndTimeChanged(); break;
        case 133: _t->netTransFlagChangeRev(); break;
        case 134: _t->onDBusServiceChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 135: _t->onRecCanGetIPAddress(); break;
        case 136: _t->onNetTransFlagChanged(); break;
        case 137: _t->onRecBluetoothOpenResult((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 138: _t->recordFileFailedSlot(); break;
        case 139: { int _r = _t->sPO2DataCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 140: { QList<int> _r = _t->getSPO2Data();
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 141: _t->clearSPO2Data(); break;
        case 142: _t->transmitNIBPStartSignal(); break;
        case 143: _t->transmitNIBPStopSignal(); break;
        case 144: { QList<int> _r = _t->getECG1leadShowArray((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 145: { QList<int> _r = _t->getECGShowArray((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 146: { QList<int> _r = _t->getECG6ShowArray((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 147: { QList<int> _r = _t->getECG12ShowArray((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<int>*>(_a[0]) = std::move(_r); }  break;
        case 148: _t->ecg3or12changed((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 149: _t->warnSetBackToDefalut(); break;
        case 150: _t->clearECGData(); break;
        case 151: _t->showOverAndClear(); break;
        case 152: _t->setGetECGDataTimerFlagTrue(); break;
        case 153: _t->setGetECGDataTimerFlagFalse(); break;
        case 154: _t->alarmPlay((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 155: _t->alarmSoundVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 156: _t->uiLoadCompleted(); break;
        case 157: { bool _r = _t->enableWifi();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 158: { bool _r = _t->enableLan();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 159: _t->enableBluetooth(); break;
        case 160: _t->setLanIPAdddress(); break;
        case 161: _t->connectWifi((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 162: _t->disconnectWifi((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 163: _t->scanWifi(); break;
        case 164: { QString _r = _t->readBtName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 165: _t->writeBtName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 166: _t->updateSoftWare(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 19:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<quint16> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::updateSoftWare2DataAcq)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::softWareUpdataSucess)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::softWareUpdataFailed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::fileNotExist)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::recordFileFailed)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::starDataAcquSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::timeChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::dateChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::batValueChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::chargeFlagChanged)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::heartRateChanged)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bPValueChanged)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::spo2NumChanged)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::piNumChanged)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::columHeightChanged)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::list_SPO2_data_changed)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::test_signal)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::NIBPStartSignal)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::NIBPStopSignal)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(QList<quint16> , QList<quint16> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::testsignal)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::list_ECG_data_show_changed)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::ecg3or12ChangedSignal)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::autoMeasureNIBPFlagChanged)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::autoMeasureMinuteChanged)) {
                *result = 23;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::recordECGFlagChanged)) {
                *result = 24;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::recordECGFlagChangeSignal)) {
                *result = 25;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::lpSelectIndexChanged)) {
                *result = 26;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hpSelectIndexChanged)) {
                *result = 27;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::acSelectIndexChanged)) {
                *result = 28;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::patientTypeChanged)) {
                *result = 29;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::patientTypeChangedSignal)) {
                *result = 30;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::wideOrNarrowThresHoldPageChanged)) {
                *result = 31;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::wideOrNarrowThresHoldChoiceChanged)) {
                *result = 32;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::spo2ThresHoldValueChanged)) {
                *result = 33;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::spo2ThresHoldLevelChanged)) {
                *result = 34;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldValueHChanged)) {
                *result = 35;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldValueHChanged)) {
                *result = 36;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldValueLChanged)) {
                *result = 37;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldValueLChanged)) {
                *result = 38;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldLevelChanged)) {
                *result = 39;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldLevelChanged)) {
                *result = 40;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrFastValueChanged)) {
                *result = 41;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrFastLevelChanged)) {
                *result = 42;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrSlowValueChanged)) {
                *result = 43;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrSlowLevelChanged)) {
                *result = 44;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::spo2ThresHoldValueChangedWide)) {
                *result = 45;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::spo2ThresHoldLevelChangedWide)) {
                *result = 46;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldValueHChangedWide)) {
                *result = 47;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldValueHChangedWide)) {
                *result = 48;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldValueLChangedWide)) {
                *result = 49;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldValueLChangedWide)) {
                *result = 50;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpSYSThresHoldLevelChangedWide)) {
                *result = 51;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bpDIAThresHoldLevelChangedWide)) {
                *result = 52;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrFastValueChangedWide)) {
                *result = 53;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrFastLevelChangedWide)) {
                *result = 54;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrSlowValueChangedWide)) {
                *result = 55;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::hrSlowLevelChangedWide)) {
                *result = 56;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::ECGDataProcessedSignal)) {
                *result = 57;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(quint8 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsShowTypeChanged)) {
                *result = 58;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::batValSendSig)) {
                *result = 59;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::gainTypeChanged)) {
                *result = 60;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::speedTypeChanged)) {
                *result = 61;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsTypeChange)) {
                *result = 62;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::warnMessage2MainPage)) {
                *result = 63;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::warnAlarmSignal)) {
                *result = 64;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffRAChange)) {
                *result = 65;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffLAChange)) {
                *result = 66;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffLLChange)) {
                *result = 67;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV1Change)) {
                *result = 68;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV2Change)) {
                *result = 69;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV3Change)) {
                *result = 70;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV4Change)) {
                *result = 71;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV5Change)) {
                *result = 72;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffV6Change)) {
                *result = 73;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadsOffRLChange)) {
                *result = 74;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIBaseLineChanged)) {
                *result = 75;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIIBaseLineChanged)) {
                *result = 76;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIIIBaseLineChanged)) {
                *result = 77;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVRBaseLineChanged)) {
                *result = 78;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVLBaseLineChanged)) {
                *result = 79;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVFBaseLineChanged)) {
                *result = 80;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV1BaseLineChanged)) {
                *result = 81;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV2BaseLineChanged)) {
                *result = 82;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV3BaseLineChanged)) {
                *result = 83;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV4BaseLineChanged)) {
                *result = 84;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV5BaseLineChanged)) {
                *result = 85;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV6BaseLineChanged)) {
                *result = 86;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIMaxLineChanged)) {
                *result = 87;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIIMaxLineChanged)) {
                *result = 88;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadIIIMaxLineChanged)) {
                *result = 89;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVRMaxLineChanged)) {
                *result = 90;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVLMaxLineChanged)) {
                *result = 91;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadaVFMaxLineChanged)) {
                *result = 92;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV1MaxLineChanged)) {
                *result = 93;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV2MaxLineChanged)) {
                *result = 94;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV3MaxLineChanged)) {
                *result = 95;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV4MaxLineChanged)) {
                *result = 96;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV5MaxLineChanged)) {
                *result = 97;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::leadV6MaxLineChanged)) {
                *result = 98;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::setAlarmSoundVolume)) {
                *result = 99;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::ecgShowStopFlagChanged)) {
                *result = 100;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::dateAandTimeChange)) {
                *result = 101;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::warnCloseFlagChanged)) {
                *result = 102;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::sendUILoadCompleted2dataAcq)) {
                *result = 103;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::netTransFlagChanged)) {
                *result = 104;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::lanMacAddressChanged)) {
                *result = 105;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::lanIPAddressChanged)) {
                *result = 106;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::lanNetMaskChanged)) {
                *result = 107;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::lanNetGateChanged)) {
                *result = 108;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::wlanMacAddressChanged)) {
                *result = 109;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::wlanIPAddressChanged)) {
                *result = 110;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::WifiServiceMapChanged)) {
                *result = 111;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::serviceChangeCompleted)) {
                *result = 112;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::btMacAddressChanged)) {
                *result = 113;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::netChangedAndIPAddressGeted)) {
                *result = 114;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::connectedWIFINameChanged)) {
                *result = 115;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::bluetoothOpenSig)) {
                *result = 116;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::btConnected)) {
                *result = 117;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::btDisconnected)) {
                *result = 118;
                return;
            }
        }
        {
            using _t = void (M3ShowController::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&M3ShowController::btOpenResult)) {
                *result = 119;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<M3ShowController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->time(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->m_date; break;
        case 2: *reinterpret_cast< uint*>(_v) = _t->batValue(); break;
        case 3: *reinterpret_cast< bool*>(_v) = _t->chargeFlag(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->heartRate(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->bPValue(); break;
        case 6: *reinterpret_cast< bool*>(_v) = _t->getNIBPAutoFlag(); break;
        case 7: *reinterpret_cast< int*>(_v) = _t->getAutoMeasureMinute(); break;
        case 8: *reinterpret_cast< QString*>(_v) = _t->spo2Num(); break;
        case 9: *reinterpret_cast< QString*>(_v) = _t->piNum(); break;
        case 10: *reinterpret_cast< quint8*>(_v) = _t->m_columHeight; break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->getRecordECGFlag(); break;
        case 12: *reinterpret_cast< quint8*>(_v) = _t->getLPSelectIndex(); break;
        case 13: *reinterpret_cast< quint8*>(_v) = _t->getHPSelectIndex(); break;
        case 14: *reinterpret_cast< quint8*>(_v) = _t->getACSelectIndex(); break;
        case 15: *reinterpret_cast< quint8*>(_v) = _t->getPatientType(); break;
        case 16: *reinterpret_cast< bool*>(_v) = _t->getWideOrNarrowThresHoldPage(); break;
        case 17: *reinterpret_cast< bool*>(_v) = _t->getWideOrNarrowThresHoldChoice(); break;
        case 18: *reinterpret_cast< quint8*>(_v) = _t->getSPO2ThresHoldValue(); break;
        case 19: *reinterpret_cast< quint8*>(_v) = _t->getSPO2ThresHoldLevel(); break;
        case 20: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldValueH(); break;
        case 21: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldValueL(); break;
        case 22: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldValueH(); break;
        case 23: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldValueL(); break;
        case 24: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldLevel(); break;
        case 25: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldLevel(); break;
        case 26: *reinterpret_cast< quint8*>(_v) = _t->getHRFastValue(); break;
        case 27: *reinterpret_cast< quint8*>(_v) = _t->getHRFastLevel(); break;
        case 28: *reinterpret_cast< quint8*>(_v) = _t->getHRSlowValue(); break;
        case 29: *reinterpret_cast< quint8*>(_v) = _t->getHRSlowLevel(); break;
        case 30: *reinterpret_cast< quint8*>(_v) = _t->getSPO2ThresHoldValueWide(); break;
        case 31: *reinterpret_cast< quint8*>(_v) = _t->getSPO2ThresHoldLevelWide(); break;
        case 32: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldValueHWide(); break;
        case 33: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldValueLWide(); break;
        case 34: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldValueHWide(); break;
        case 35: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldValueLWide(); break;
        case 36: *reinterpret_cast< quint8*>(_v) = _t->getBPSYSThresHoldLevelWide(); break;
        case 37: *reinterpret_cast< quint8*>(_v) = _t->getBPDIAThresHoldLevelWide(); break;
        case 38: *reinterpret_cast< quint8*>(_v) = _t->getHRFastValueWide(); break;
        case 39: *reinterpret_cast< quint8*>(_v) = _t->getHRFastLevelWide(); break;
        case 40: *reinterpret_cast< quint8*>(_v) = _t->getHRSlowValueWide(); break;
        case 41: *reinterpret_cast< quint8*>(_v) = _t->getHRSlowLevelWide(); break;
        case 42: *reinterpret_cast< quint8*>(_v) = _t->getLeadsShowType(); break;
        case 43: *reinterpret_cast< quint8*>(_v) = _t->m_gainType; break;
        case 44: *reinterpret_cast< quint8*>(_v) = _t->m_speedType; break;
        case 45: *reinterpret_cast< quint8*>(_v) = _t->m_leadsType; break;
        case 46: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffRA; break;
        case 47: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffLA; break;
        case 48: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffLL; break;
        case 49: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffRL; break;
        case 50: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV1; break;
        case 51: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV2; break;
        case 52: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV3; break;
        case 53: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV4; break;
        case 54: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV5; break;
        case 55: *reinterpret_cast< bool*>(_v) = _t->m_leadsOffV6; break;
        case 56: *reinterpret_cast< int*>(_v) = _t->m_leadIBaseLine; break;
        case 57: *reinterpret_cast< int*>(_v) = _t->m_leadIIBaseLine; break;
        case 58: *reinterpret_cast< int*>(_v) = _t->m_leadIIIBaseLine; break;
        case 59: *reinterpret_cast< int*>(_v) = _t->m_leadaVRBaseLine; break;
        case 60: *reinterpret_cast< int*>(_v) = _t->m_leadaVLBaseLine; break;
        case 61: *reinterpret_cast< int*>(_v) = _t->m_leadaVFBaseLine; break;
        case 62: *reinterpret_cast< int*>(_v) = _t->m_leadV1BaseLine; break;
        case 63: *reinterpret_cast< int*>(_v) = _t->m_leadV2BaseLine; break;
        case 64: *reinterpret_cast< int*>(_v) = _t->m_leadV3BaseLine; break;
        case 65: *reinterpret_cast< int*>(_v) = _t->m_leadV4BaseLine; break;
        case 66: *reinterpret_cast< int*>(_v) = _t->m_leadV5BaseLine; break;
        case 67: *reinterpret_cast< int*>(_v) = _t->m_leadV6BaseLine; break;
        case 68: *reinterpret_cast< int*>(_v) = _t->m_leadIMaxLine; break;
        case 69: *reinterpret_cast< int*>(_v) = _t->m_leadIIMaxLine; break;
        case 70: *reinterpret_cast< int*>(_v) = _t->m_leadIIIMaxLine; break;
        case 71: *reinterpret_cast< int*>(_v) = _t->m_leadaVRMaxLine; break;
        case 72: *reinterpret_cast< int*>(_v) = _t->m_leadaVLMaxLine; break;
        case 73: *reinterpret_cast< int*>(_v) = _t->m_leadaVFMaxLine; break;
        case 74: *reinterpret_cast< int*>(_v) = _t->m_leadV1MaxLine; break;
        case 75: *reinterpret_cast< int*>(_v) = _t->m_leadV2MaxLine; break;
        case 76: *reinterpret_cast< int*>(_v) = _t->m_leadV3MaxLine; break;
        case 77: *reinterpret_cast< int*>(_v) = _t->m_leadV4MaxLine; break;
        case 78: *reinterpret_cast< int*>(_v) = _t->m_leadV5MaxLine; break;
        case 79: *reinterpret_cast< int*>(_v) = _t->m_leadV6MaxLine; break;
        case 80: *reinterpret_cast< bool*>(_v) = _t->m_ecgShowStopFlag; break;
        case 81: *reinterpret_cast< QString*>(_v) = _t->m_dateAndTime; break;
        case 82: *reinterpret_cast< bool*>(_v) = _t->m_warnCloseFlag; break;
        case 83: *reinterpret_cast< quint8*>(_v) = _t->m_netTransFlag; break;
        case 84: *reinterpret_cast< QString*>(_v) = _t->m_lanMacAddress; break;
        case 85: *reinterpret_cast< QString*>(_v) = _t->m_lanIPAddress; break;
        case 86: *reinterpret_cast< QString*>(_v) = _t->m_lanNetMask; break;
        case 87: *reinterpret_cast< QString*>(_v) = _t->m_lanNetGate; break;
        case 88: *reinterpret_cast< QString*>(_v) = _t->m_wlanMacAddress; break;
        case 89: *reinterpret_cast< QString*>(_v) = _t->m_wlanIPAddress; break;
        case 90: *reinterpret_cast< QString*>(_v) = _t->m_connectedWIFIName; break;
        case 91: *reinterpret_cast< QMap<QString,QVariant>*>(_v) = _t->getWifiServiceMap(); break;
        case 92: *reinterpret_cast< QString*>(_v) = _t->m_BtMacAddress; break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<M3ShowController *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setTime(*reinterpret_cast< QString*>(_v)); break;
        case 1:
            if (_t->m_date != *reinterpret_cast< QString*>(_v)) {
                _t->m_date = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->dateChanged();
            }
            break;
        case 2: _t->setBatValue(*reinterpret_cast< uint*>(_v)); break;
        case 3: _t->setChargeFlag(*reinterpret_cast< bool*>(_v)); break;
        case 4: _t->setHeartRate(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setBPValue(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setNIBPAutoFlag(*reinterpret_cast< bool*>(_v)); break;
        case 7: _t->setAutoMeasureMinute(*reinterpret_cast< int*>(_v)); break;
        case 8: _t->setSpo2Num(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setpiNum(*reinterpret_cast< QString*>(_v)); break;
        case 10:
            if (_t->m_columHeight != *reinterpret_cast< quint8*>(_v)) {
                _t->m_columHeight = *reinterpret_cast< quint8*>(_v);
                Q_EMIT _t->columHeightChanged();
            }
            break;
        case 11: _t->setRecordECGFlag(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setLPSelectIndex(*reinterpret_cast< quint8*>(_v)); break;
        case 13: _t->setHPSelectIndex(*reinterpret_cast< quint8*>(_v)); break;
        case 14: _t->setACSelectIndex(*reinterpret_cast< quint8*>(_v)); break;
        case 15: _t->setPatientType(*reinterpret_cast< quint8*>(_v)); break;
        case 16: _t->setWideOrNarrowThresHoldPage(*reinterpret_cast< bool*>(_v)); break;
        case 17: _t->setWideOrNarrowThresHoldChoice(*reinterpret_cast< bool*>(_v)); break;
        case 18: _t->setSPO2ThresHoldValue(*reinterpret_cast< quint8*>(_v)); break;
        case 19: _t->setSPO2ThresHoldLevel(*reinterpret_cast< quint8*>(_v)); break;
        case 20: _t->setBPSYSThresHoldValueH(*reinterpret_cast< quint8*>(_v)); break;
        case 21: _t->setBPSYSThresHoldValueL(*reinterpret_cast< quint8*>(_v)); break;
        case 22: _t->setBPDIAThresHoldValueH(*reinterpret_cast< quint8*>(_v)); break;
        case 23: _t->setBPDIAThresHoldValueL(*reinterpret_cast< quint8*>(_v)); break;
        case 24: _t->setBPSYSThresHoldLevel(*reinterpret_cast< quint8*>(_v)); break;
        case 25: _t->setBPDIAThresHoldLevel(*reinterpret_cast< quint8*>(_v)); break;
        case 26: _t->setHRFastValue(*reinterpret_cast< quint8*>(_v)); break;
        case 27: _t->setHRFastLevel(*reinterpret_cast< quint8*>(_v)); break;
        case 28: _t->setHRSlowValue(*reinterpret_cast< quint8*>(_v)); break;
        case 29: _t->setHRSlowLevel(*reinterpret_cast< quint8*>(_v)); break;
        case 30: _t->setSPO2ThresHoldValueWide(*reinterpret_cast< quint8*>(_v)); break;
        case 31: _t->setSPO2ThresHoldLevelWide(*reinterpret_cast< quint8*>(_v)); break;
        case 32: _t->setBPSYSThresHoldValueHWide(*reinterpret_cast< quint8*>(_v)); break;
        case 33: _t->setBPSYSThresHoldValueLWide(*reinterpret_cast< quint8*>(_v)); break;
        case 34: _t->setBPDIAThresHoldValueHWide(*reinterpret_cast< quint8*>(_v)); break;
        case 35: _t->setBPDIAThresHoldValueLWide(*reinterpret_cast< quint8*>(_v)); break;
        case 36: _t->setBPSYSThresHoldLevelWide(*reinterpret_cast< quint8*>(_v)); break;
        case 37: _t->setBPDIAThresHoldLevelWide(*reinterpret_cast< quint8*>(_v)); break;
        case 38: _t->setHRFastValueWide(*reinterpret_cast< quint8*>(_v)); break;
        case 39: _t->setHRFastLevelWide(*reinterpret_cast< quint8*>(_v)); break;
        case 40: _t->setHRSlowValueWide(*reinterpret_cast< quint8*>(_v)); break;
        case 41: _t->setHRSlowLevelWide(*reinterpret_cast< quint8*>(_v)); break;
        case 42: _t->setLeadsShowType(*reinterpret_cast< quint8*>(_v)); break;
        case 43:
            if (_t->m_gainType != *reinterpret_cast< quint8*>(_v)) {
                _t->m_gainType = *reinterpret_cast< quint8*>(_v);
                Q_EMIT _t->gainTypeChanged();
            }
            break;
        case 44:
            if (_t->m_speedType != *reinterpret_cast< quint8*>(_v)) {
                _t->m_speedType = *reinterpret_cast< quint8*>(_v);
                Q_EMIT _t->speedTypeChanged();
            }
            break;
        case 45:
            if (_t->m_leadsType != *reinterpret_cast< quint8*>(_v)) {
                _t->m_leadsType = *reinterpret_cast< quint8*>(_v);
                Q_EMIT _t->leadsTypeChange();
            }
            break;
        case 46:
            if (_t->m_leadsOffRA != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffRA = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffRAChange();
            }
            break;
        case 47:
            if (_t->m_leadsOffLA != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffLA = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffLAChange();
            }
            break;
        case 48:
            if (_t->m_leadsOffLL != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffLL = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffLLChange();
            }
            break;
        case 49:
            if (_t->m_leadsOffRL != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffRL = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffRLChange();
            }
            break;
        case 50:
            if (_t->m_leadsOffV1 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV1 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV1Change();
            }
            break;
        case 51:
            if (_t->m_leadsOffV2 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV2 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV2Change();
            }
            break;
        case 52:
            if (_t->m_leadsOffV3 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV3 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV3Change();
            }
            break;
        case 53:
            if (_t->m_leadsOffV4 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV4 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV4Change();
            }
            break;
        case 54:
            if (_t->m_leadsOffV5 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV5 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV5Change();
            }
            break;
        case 55:
            if (_t->m_leadsOffV6 != *reinterpret_cast< bool*>(_v)) {
                _t->m_leadsOffV6 = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->leadsOffV6Change();
            }
            break;
        case 56:
            if (_t->m_leadIBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIBaseLineChanged();
            }
            break;
        case 57:
            if (_t->m_leadIIBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIIBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIIBaseLineChanged();
            }
            break;
        case 58:
            if (_t->m_leadIIIBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIIIBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIIIBaseLineChanged();
            }
            break;
        case 59:
            if (_t->m_leadaVRBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVRBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVRBaseLineChanged();
            }
            break;
        case 60:
            if (_t->m_leadaVLBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVLBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVLBaseLineChanged();
            }
            break;
        case 61:
            if (_t->m_leadaVFBaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVFBaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVFBaseLineChanged();
            }
            break;
        case 62:
            if (_t->m_leadV1BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV1BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV1BaseLineChanged();
            }
            break;
        case 63:
            if (_t->m_leadV2BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV2BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV2BaseLineChanged();
            }
            break;
        case 64:
            if (_t->m_leadV3BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV3BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV3BaseLineChanged();
            }
            break;
        case 65:
            if (_t->m_leadV4BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV4BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV4BaseLineChanged();
            }
            break;
        case 66:
            if (_t->m_leadV5BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV5BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV5BaseLineChanged();
            }
            break;
        case 67:
            if (_t->m_leadV6BaseLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV6BaseLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV6BaseLineChanged();
            }
            break;
        case 68:
            if (_t->m_leadIMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIMaxLineChanged();
            }
            break;
        case 69:
            if (_t->m_leadIIMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIIMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIIMaxLineChanged();
            }
            break;
        case 70:
            if (_t->m_leadIIIMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadIIIMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadIIIMaxLineChanged();
            }
            break;
        case 71:
            if (_t->m_leadaVRMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVRMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVRMaxLineChanged();
            }
            break;
        case 72:
            if (_t->m_leadaVLMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVLMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVLMaxLineChanged();
            }
            break;
        case 73:
            if (_t->m_leadaVFMaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadaVFMaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadaVFMaxLineChanged();
            }
            break;
        case 74:
            if (_t->m_leadV1MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV1MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV1MaxLineChanged();
            }
            break;
        case 75:
            if (_t->m_leadV2MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV2MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV2MaxLineChanged();
            }
            break;
        case 76:
            if (_t->m_leadV3MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV3MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV3MaxLineChanged();
            }
            break;
        case 77:
            if (_t->m_leadV4MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV4MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV4MaxLineChanged();
            }
            break;
        case 78:
            if (_t->m_leadV5MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV5MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV5MaxLineChanged();
            }
            break;
        case 79:
            if (_t->m_leadV6MaxLine != *reinterpret_cast< int*>(_v)) {
                _t->m_leadV6MaxLine = *reinterpret_cast< int*>(_v);
                Q_EMIT _t->leadV6MaxLineChanged();
            }
            break;
        case 80:
            if (_t->m_ecgShowStopFlag != *reinterpret_cast< bool*>(_v)) {
                _t->m_ecgShowStopFlag = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->ecgShowStopFlagChanged();
            }
            break;
        case 81:
            if (_t->m_dateAndTime != *reinterpret_cast< QString*>(_v)) {
                _t->m_dateAndTime = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->dateAandTimeChange();
            }
            break;
        case 82:
            if (_t->m_warnCloseFlag != *reinterpret_cast< bool*>(_v)) {
                _t->m_warnCloseFlag = *reinterpret_cast< bool*>(_v);
                Q_EMIT _t->warnCloseFlagChanged();
            }
            break;
        case 83:
            if (_t->m_netTransFlag != *reinterpret_cast< quint8*>(_v)) {
                _t->m_netTransFlag = *reinterpret_cast< quint8*>(_v);
                Q_EMIT _t->netTransFlagChanged();
            }
            break;
        case 84:
            if (_t->m_lanMacAddress != *reinterpret_cast< QString*>(_v)) {
                _t->m_lanMacAddress = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->lanMacAddressChanged();
            }
            break;
        case 85:
            if (_t->m_lanIPAddress != *reinterpret_cast< QString*>(_v)) {
                _t->m_lanIPAddress = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->lanIPAddressChanged();
            }
            break;
        case 86:
            if (_t->m_lanNetMask != *reinterpret_cast< QString*>(_v)) {
                _t->m_lanNetMask = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->lanNetMaskChanged();
            }
            break;
        case 87:
            if (_t->m_lanNetGate != *reinterpret_cast< QString*>(_v)) {
                _t->m_lanNetGate = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->lanNetGateChanged();
            }
            break;
        case 88:
            if (_t->m_wlanMacAddress != *reinterpret_cast< QString*>(_v)) {
                _t->m_wlanMacAddress = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->wlanMacAddressChanged();
            }
            break;
        case 89:
            if (_t->m_wlanIPAddress != *reinterpret_cast< QString*>(_v)) {
                _t->m_wlanIPAddress = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->wlanIPAddressChanged();
            }
            break;
        case 90:
            if (_t->m_connectedWIFIName != *reinterpret_cast< QString*>(_v)) {
                _t->m_connectedWIFIName = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->connectedWIFINameChanged();
            }
            break;
        case 91: _t->setWifiServiceMap(*reinterpret_cast< QMap<QString,QVariant>*>(_v)); break;
        case 92:
            if (_t->m_BtMacAddress != *reinterpret_cast< QString*>(_v)) {
                _t->m_BtMacAddress = *reinterpret_cast< QString*>(_v);
                Q_EMIT _t->btMacAddressChanged();
            }
            break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject M3ShowController::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_M3ShowController.data,
    qt_meta_data_M3ShowController,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *M3ShowController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *M3ShowController::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_M3ShowController.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int M3ShowController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 167)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 167;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 167)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 167;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 93;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 93;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 93;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 93;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 93;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 93;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void M3ShowController::updateSoftWare2DataAcq()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void M3ShowController::softWareUpdataSucess()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void M3ShowController::softWareUpdataFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void M3ShowController::fileNotExist()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void M3ShowController::recordFileFailed()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void M3ShowController::starDataAcquSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void M3ShowController::timeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void M3ShowController::dateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void M3ShowController::batValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void M3ShowController::chargeFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void M3ShowController::heartRateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void M3ShowController::bPValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void M3ShowController::spo2NumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}

// SIGNAL 13
void M3ShowController::piNumChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 13, nullptr);
}

// SIGNAL 14
void M3ShowController::columHeightChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 14, nullptr);
}

// SIGNAL 15
void M3ShowController::list_SPO2_data_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 15, nullptr);
}

// SIGNAL 16
void M3ShowController::test_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 16, nullptr);
}

// SIGNAL 17
void M3ShowController::NIBPStartSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 17, nullptr);
}

// SIGNAL 18
void M3ShowController::NIBPStopSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 18, nullptr);
}

// SIGNAL 19
void M3ShowController::testsignal(QList<quint16> _t1, QList<quint16> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void M3ShowController::list_ECG_data_show_changed()
{
    QMetaObject::activate(this, &staticMetaObject, 20, nullptr);
}

// SIGNAL 21
void M3ShowController::ecg3or12ChangedSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void M3ShowController::autoMeasureNIBPFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 22, nullptr);
}

// SIGNAL 23
void M3ShowController::autoMeasureMinuteChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 23, nullptr);
}

// SIGNAL 24
void M3ShowController::recordECGFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 24, nullptr);
}

// SIGNAL 25
void M3ShowController::recordECGFlagChangeSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 25, _a);
}

// SIGNAL 26
void M3ShowController::lpSelectIndexChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 26, _a);
}

// SIGNAL 27
void M3ShowController::hpSelectIndexChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 27, _a);
}

// SIGNAL 28
void M3ShowController::acSelectIndexChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 28, _a);
}

// SIGNAL 29
void M3ShowController::patientTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 29, nullptr);
}

// SIGNAL 30
void M3ShowController::patientTypeChangedSignal(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 30, _a);
}

// SIGNAL 31
void M3ShowController::wideOrNarrowThresHoldPageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 31, nullptr);
}

// SIGNAL 32
void M3ShowController::wideOrNarrowThresHoldChoiceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 32, nullptr);
}

// SIGNAL 33
void M3ShowController::spo2ThresHoldValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 33, nullptr);
}

// SIGNAL 34
void M3ShowController::spo2ThresHoldLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 34, nullptr);
}

// SIGNAL 35
void M3ShowController::bpSYSThresHoldValueHChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 35, nullptr);
}

// SIGNAL 36
void M3ShowController::bpDIAThresHoldValueHChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 36, nullptr);
}

// SIGNAL 37
void M3ShowController::bpSYSThresHoldValueLChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 37, nullptr);
}

// SIGNAL 38
void M3ShowController::bpDIAThresHoldValueLChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 38, nullptr);
}

// SIGNAL 39
void M3ShowController::bpSYSThresHoldLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 39, nullptr);
}

// SIGNAL 40
void M3ShowController::bpDIAThresHoldLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 40, nullptr);
}

// SIGNAL 41
void M3ShowController::hrFastValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 41, nullptr);
}

// SIGNAL 42
void M3ShowController::hrFastLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 42, nullptr);
}

// SIGNAL 43
void M3ShowController::hrSlowValueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 43, nullptr);
}

// SIGNAL 44
void M3ShowController::hrSlowLevelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 44, nullptr);
}

// SIGNAL 45
void M3ShowController::spo2ThresHoldValueChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 45, nullptr);
}

// SIGNAL 46
void M3ShowController::spo2ThresHoldLevelChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 46, nullptr);
}

// SIGNAL 47
void M3ShowController::bpSYSThresHoldValueHChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 47, nullptr);
}

// SIGNAL 48
void M3ShowController::bpDIAThresHoldValueHChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 48, nullptr);
}

// SIGNAL 49
void M3ShowController::bpSYSThresHoldValueLChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 49, nullptr);
}

// SIGNAL 50
void M3ShowController::bpDIAThresHoldValueLChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 50, nullptr);
}

// SIGNAL 51
void M3ShowController::bpSYSThresHoldLevelChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 51, nullptr);
}

// SIGNAL 52
void M3ShowController::bpDIAThresHoldLevelChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 52, nullptr);
}

// SIGNAL 53
void M3ShowController::hrFastValueChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 53, nullptr);
}

// SIGNAL 54
void M3ShowController::hrFastLevelChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 54, nullptr);
}

// SIGNAL 55
void M3ShowController::hrSlowValueChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 55, nullptr);
}

// SIGNAL 56
void M3ShowController::hrSlowLevelChangedWide()
{
    QMetaObject::activate(this, &staticMetaObject, 56, nullptr);
}

// SIGNAL 57
void M3ShowController::ECGDataProcessedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 57, nullptr);
}

// SIGNAL 58
void M3ShowController::leadsShowTypeChanged(quint8 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 58, _a);
}

// SIGNAL 59
void M3ShowController::batValSendSig(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 59, _a);
}

// SIGNAL 60
void M3ShowController::gainTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 60, nullptr);
}

// SIGNAL 61
void M3ShowController::speedTypeChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 61, nullptr);
}

// SIGNAL 62
void M3ShowController::leadsTypeChange()
{
    QMetaObject::activate(this, &staticMetaObject, 62, nullptr);
}

// SIGNAL 63
void M3ShowController::warnMessage2MainPage(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 63, _a);
}

// SIGNAL 64
void M3ShowController::warnAlarmSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 64, _a);
}

// SIGNAL 65
void M3ShowController::leadsOffRAChange()
{
    QMetaObject::activate(this, &staticMetaObject, 65, nullptr);
}

// SIGNAL 66
void M3ShowController::leadsOffLAChange()
{
    QMetaObject::activate(this, &staticMetaObject, 66, nullptr);
}

// SIGNAL 67
void M3ShowController::leadsOffLLChange()
{
    QMetaObject::activate(this, &staticMetaObject, 67, nullptr);
}

// SIGNAL 68
void M3ShowController::leadsOffV1Change()
{
    QMetaObject::activate(this, &staticMetaObject, 68, nullptr);
}

// SIGNAL 69
void M3ShowController::leadsOffV2Change()
{
    QMetaObject::activate(this, &staticMetaObject, 69, nullptr);
}

// SIGNAL 70
void M3ShowController::leadsOffV3Change()
{
    QMetaObject::activate(this, &staticMetaObject, 70, nullptr);
}

// SIGNAL 71
void M3ShowController::leadsOffV4Change()
{
    QMetaObject::activate(this, &staticMetaObject, 71, nullptr);
}

// SIGNAL 72
void M3ShowController::leadsOffV5Change()
{
    QMetaObject::activate(this, &staticMetaObject, 72, nullptr);
}

// SIGNAL 73
void M3ShowController::leadsOffV6Change()
{
    QMetaObject::activate(this, &staticMetaObject, 73, nullptr);
}

// SIGNAL 74
void M3ShowController::leadsOffRLChange()
{
    QMetaObject::activate(this, &staticMetaObject, 74, nullptr);
}

// SIGNAL 75
void M3ShowController::leadIBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 75, nullptr);
}

// SIGNAL 76
void M3ShowController::leadIIBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 76, nullptr);
}

// SIGNAL 77
void M3ShowController::leadIIIBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 77, nullptr);
}

// SIGNAL 78
void M3ShowController::leadaVRBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 78, nullptr);
}

// SIGNAL 79
void M3ShowController::leadaVLBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 79, nullptr);
}

// SIGNAL 80
void M3ShowController::leadaVFBaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 80, nullptr);
}

// SIGNAL 81
void M3ShowController::leadV1BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 81, nullptr);
}

// SIGNAL 82
void M3ShowController::leadV2BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 82, nullptr);
}

// SIGNAL 83
void M3ShowController::leadV3BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 83, nullptr);
}

// SIGNAL 84
void M3ShowController::leadV4BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 84, nullptr);
}

// SIGNAL 85
void M3ShowController::leadV5BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 85, nullptr);
}

// SIGNAL 86
void M3ShowController::leadV6BaseLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 86, nullptr);
}

// SIGNAL 87
void M3ShowController::leadIMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 87, nullptr);
}

// SIGNAL 88
void M3ShowController::leadIIMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 88, nullptr);
}

// SIGNAL 89
void M3ShowController::leadIIIMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 89, nullptr);
}

// SIGNAL 90
void M3ShowController::leadaVRMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 90, nullptr);
}

// SIGNAL 91
void M3ShowController::leadaVLMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 91, nullptr);
}

// SIGNAL 92
void M3ShowController::leadaVFMaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 92, nullptr);
}

// SIGNAL 93
void M3ShowController::leadV1MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 93, nullptr);
}

// SIGNAL 94
void M3ShowController::leadV2MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 94, nullptr);
}

// SIGNAL 95
void M3ShowController::leadV3MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 95, nullptr);
}

// SIGNAL 96
void M3ShowController::leadV4MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 96, nullptr);
}

// SIGNAL 97
void M3ShowController::leadV5MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 97, nullptr);
}

// SIGNAL 98
void M3ShowController::leadV6MaxLineChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 98, nullptr);
}

// SIGNAL 99
void M3ShowController::setAlarmSoundVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 99, _a);
}

// SIGNAL 100
void M3ShowController::ecgShowStopFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 100, nullptr);
}

// SIGNAL 101
void M3ShowController::dateAandTimeChange()
{
    QMetaObject::activate(this, &staticMetaObject, 101, nullptr);
}

// SIGNAL 102
void M3ShowController::warnCloseFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 102, nullptr);
}

// SIGNAL 103
void M3ShowController::sendUILoadCompleted2dataAcq()
{
    QMetaObject::activate(this, &staticMetaObject, 103, nullptr);
}

// SIGNAL 104
void M3ShowController::netTransFlagChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 104, nullptr);
}

// SIGNAL 105
void M3ShowController::lanMacAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 105, nullptr);
}

// SIGNAL 106
void M3ShowController::lanIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 106, nullptr);
}

// SIGNAL 107
void M3ShowController::lanNetMaskChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 107, nullptr);
}

// SIGNAL 108
void M3ShowController::lanNetGateChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 108, nullptr);
}

// SIGNAL 109
void M3ShowController::wlanMacAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 109, nullptr);
}

// SIGNAL 110
void M3ShowController::wlanIPAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 110, nullptr);
}

// SIGNAL 111
void M3ShowController::WifiServiceMapChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 111, nullptr);
}

// SIGNAL 112
void M3ShowController::serviceChangeCompleted()
{
    QMetaObject::activate(this, &staticMetaObject, 112, nullptr);
}

// SIGNAL 113
void M3ShowController::btMacAddressChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 113, nullptr);
}

// SIGNAL 114
void M3ShowController::netChangedAndIPAddressGeted()
{
    QMetaObject::activate(this, &staticMetaObject, 114, nullptr);
}

// SIGNAL 115
void M3ShowController::connectedWIFINameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 115, nullptr);
}

// SIGNAL 116
void M3ShowController::bluetoothOpenSig(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 116, _a);
}

// SIGNAL 117
void M3ShowController::btConnected()
{
    QMetaObject::activate(this, &staticMetaObject, 117, nullptr);
}

// SIGNAL 118
void M3ShowController::btDisconnected()
{
    QMetaObject::activate(this, &staticMetaObject, 118, nullptr);
}

// SIGNAL 119
void M3ShowController::btOpenResult(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 119, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
