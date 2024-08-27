
//#include <QThread>
#include "bluetoothserver.h"

//! [Service UUID]
static const QLatin1String serviceUuid("a8e10f75-1a71-4b37-9ccf-12024024e9c8");
//! [Service UUID]
//!
//!
BluetoothServer::BluetoothServer(QObject *parent) : QObject(parent)
{
    //QBluetoothLocalDevice adapter(QBluetoothLocalDevice::allDevices().at(0).address());
    //qDebug()<<"the name is "<<QBluetoothLocalDevice::allDevices().at(0).name();
    //adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);  //设置蓝牙可被发现
}

BluetoothServer::~BluetoothServer()
{
    stopServer();
}

bool BluetoothServer::startServer(const QBluetoothAddress &localAdapter)
{
//    QBluetoothHostInfo *info = new QBluetoothHostInfo(QBluetoothLocalDevice::allDevices().at(0));
//    const QBluetoothAddress addr = QBluetoothAddress("BB:C6:EE:C6:4F:5E");
//    qDebug()<<"the info name is "<<info->name();
//    info->setName("HUASI-M3");
//    qDebug()<<"the info name is "<<info->name();
//    QBluetoothLocalDevice();
//    info->setAddress(addr);
//    qDebug()<<"the info name is "<<info->address();
//    //QBluetoothLocalDevice::
//    //QBluetoothLocalDevice::allDevices().at(0) = info;
//    QBluetoothLocalDevice adapter(info->address());
//    qDebug()<<"the adapter name is "<<adapter.name();
//    qDebug()<<"the adapter address is "<<adapter.address();
    QBluetoothLocalDevice adapter(QBluetoothLocalDevice::allDevices().at(0).address());
    //QBluetoothLocalDevice::allDevices().at(0);返回的是一个QBluetoothHostInfor类型的值
    qDebug()<<"the name is "<<QBluetoothLocalDevice::allDevices().at(0).name();
    qDebug()<<"the state is "<<adapter.hostMode();
    adapter.setHostMode(QBluetoothLocalDevice::HostConnectable);  //设置蓝牙可被发现
    adapter.setHostMode(QBluetoothLocalDevice::HostDiscoverable);  //设置蓝牙可被发现
    qDebug()<<"the state 2 is "<<adapter.hostMode();
    adapter.name();

    //qDebug()<<"BtServer thread StartServer is "<<QThread::currentThreadId();

    if (rfcommServer)
            return false;


    //! [Create the server]
        //rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol, this);
        rfcommServer = new QBluetoothServer(QBluetoothServiceInfo::RfcommProtocol);
        connect(rfcommServer, &QBluetoothServer::newConnection,
                this, &BluetoothServer::clientConnected);
        bool result = rfcommServer->listen(localAdapter);
        if (!result) {
            qWarning() << "Cannot bind chat server to" << localAdapter.toString();
            return false;
        }
        //! [Create the server]

        QBluetoothServiceInfo::Sequence profileSequence;
        QBluetoothServiceInfo::Sequence classId;
        classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));
        classId << QVariant::fromValue(quint16(0x100));
        profileSequence.append(QVariant::fromValue(classId));
        serviceInfo.setAttribute(QBluetoothServiceInfo::BluetoothProfileDescriptorList,
                                 profileSequence);

        classId.clear();
        classId << QVariant::fromValue(QBluetoothUuid(serviceUuid));
        classId << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::SerialPort));

        serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceClassIds, classId);

        //! [Service name, description and provider]
        serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceName, tr("M3BtServer"));
        serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceDescription,
                                 tr("M3 Bluetooth server"));
        serviceInfo.setAttribute(QBluetoothServiceInfo::ServiceProvider, tr("huasi.org"));
        //! [Service name, description and provider]

        //! [Service UUID set]
        serviceInfo.setServiceUuid(QBluetoothUuid(serviceUuid));
        //! [Service UUID set]

        //! [Service Discoverability]
        QBluetoothServiceInfo::Sequence publicBrowse;
        publicBrowse << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::PublicBrowseGroup));
        serviceInfo.setAttribute(QBluetoothServiceInfo::BrowseGroupList,
                                 publicBrowse);
        //! [Service Discoverability]

        //! [Protocol descriptor list]
        QBluetoothServiceInfo::Sequence protocolDescriptorList;
        QBluetoothServiceInfo::Sequence protocol;
        protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::L2cap));
        protocolDescriptorList.append(QVariant::fromValue(protocol));
        protocol.clear();
        protocol << QVariant::fromValue(QBluetoothUuid(QBluetoothUuid::Rfcomm))
                 << QVariant::fromValue(quint8(rfcommServer->serverPort()));
        protocolDescriptorList.append(QVariant::fromValue(protocol));
        serviceInfo.setAttribute(QBluetoothServiceInfo::ProtocolDescriptorList,
                                 protocolDescriptorList);
        //! [Protocol descriptor list]

        //! [Register service]
        bool re  = serviceInfo.registerService(localAdapter);
        if(re == true) //蓝牙开启成功
        {
            //emit bluetoothOpenSuccess(); //发送蓝牙打开成功信号
            qDebug()<<"emit bluetoothServerOpenSuccess";
            btMacAddress = QBluetoothLocalDevice::allDevices().at(0).address().toString();
            return true;
        }
        else { //蓝牙开启失败
            //emit bluetoothOpenFailed();  //发送蓝牙打开失败信号
            qDebug()<<"bluetoothServerOpenFailed";
            btMacAddress = "";
            return false;
        }
        //! [Register service]
}

void BluetoothServer::stopServer()
{
    // Unregister service
    serviceInfo.unregisterService();
    QBluetoothLocalDevice adapter(QBluetoothLocalDevice::allDevices().at(0).address());
    adapter.setHostMode(QBluetoothLocalDevice::HostPoweredOff);  //设置蓝牙可被发现
    // Close sockets
    qDeleteAll(clientSockets);

    // Close server
    delete rfcommServer;
    rfcommServer = nullptr;
    adapter.deleteLater();

}

void BluetoothServer::sendMessage(const QByteArray buf)
{
    //QByteArray text = message.toUtf8() + '\n';

    for (QBluetoothSocket *socket : qAsConst(clientSockets))
        socket->write(buf);
}

void BluetoothServer::clientConnected()
{
    QBluetoothSocket *socket = rfcommServer->nextPendingConnection();
    if (!socket)
        return;
    //qDebug()<<"BtServer  thread is "<<QThread::currentThreadId();
    connect(socket, &QBluetoothSocket::readyRead, this, &BluetoothServer::readSocket);
    connect(socket, &QBluetoothSocket::disconnected, this, &BluetoothServer::clientDisconnected);
    clientSockets.append(socket);
    //emit clientConnectedSig(socket->peerName());
    emit clientConnectedSig();
    qDebug()<<"the bt connected sig is send";
}

void BluetoothServer::clientDisconnected()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
    if (!socket)
        return;

    emit bluetoothStartTranDataFlag(false);//结束通过蓝牙传数据
    //emit clientDisconnectedSig(socket->peerName()); //发出断开连接的信号
    emit clientDisconnectedSig(); //发出断开连接的信号
    qDebug()<<"the bt disconnected sig is send";

    clientSockets.removeOne(socket);

    socket->deleteLater();
}

void BluetoothServer::readSocket()
{
    QBluetoothSocket *socket = qobject_cast<QBluetoothSocket *>(sender());
    if (!socket)
        return;
    QByteArray socketReadBuf = socket->readAll();
    QString str = QString(socketReadBuf);
    if(str == "Start")
    {
        //netConnectedFlag = true;
        emit bluetoothStartTranDataFlag(true);//开始通过蓝牙传数据
    }
    else if(str == "Stop")
    {
        emit bluetoothStartTranDataFlag(false);//结束通过蓝牙传数据
        //netConnectedFlag = false;
    }

//    while (socket->canReadLine()) {
//        QByteArray line = socket->readLine().trimmed();

//        emit messageReceivedSig(socket->peerName(),
//                             QString::fromUtf8(line.constData(), line.length()));
//    }
}
