#ifndef BLUETOOTHSERVER_H
#define BLUETOOTHSERVER_H

#include <QObject>

#include <QtBluetooth/qbluetoothaddress.h>
#include <QtBluetooth/qbluetoothserviceinfo.h>
#include <QBluetoothServer>
#include <QBluetoothSocket>
#include <QBluetoothLocalDevice>

class BluetoothServer : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothServer(QObject *parent = nullptr);
    ~BluetoothServer();
    bool startServer(const QBluetoothAddress &localAdapter = QBluetoothAddress());
    void stopServer();
    QString btMacAddress;
public slots:
    //void sendMessage(const QString &message);
    void sendMessage(const QByteArray buf);
    void clientDisconnected();

signals:
    void messageReceivedSig(const QString &sender, const QString &message);
    //void clientConnectedSig(const QString &name);
    //void clientDisconnectedSig(const QString &name);

    void clientConnectedSig();
    void clientDisconnectedSig();

    void bluetoothOpenSuccess(); //蓝牙打开成功
    void bluetoothOpenFailed();  //蓝牙打开失败
    void bluetoothStartTranDataFlag(bool);//是否开始通过蓝牙传数据

private slots:
    void clientConnected();
    //void clientDisconnected();
    void readSocket();

private:
    QBluetoothServer *rfcommServer = nullptr;
    QBluetoothServiceInfo serviceInfo;
    QList<QBluetoothSocket *> clientSockets;
};

#endif // BLUETOOTHSERVER_H
