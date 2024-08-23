#ifndef DBUS_CONNMAN_H
#define DBUS_CONNMAN_H

#include <QObject>

# include <QObject>
# include <QtDBus/QtDBus>
# include <QtDBus/QDBusInterface>
# include <QtDBus/QDBusMessage>
# include <QtDBus/QDBusObjectPath>
# include <QString>
# include <QMap>
# include <QVariant>
# include <QDBusMetaType>
# include "huasiagent.h"
/* 本类的主要作用是通过DBus与connman进行连接，实现对有线网络，无线网络，甚至蓝牙的控制
*首先在目标机上实现了DBUS，connman wap.supplicant bluez等
* 20231213 by pw
*/
struct arrayElement
{
   QDBusObjectPath objpath;//请求connman的DBus数据返回的路径值
   QMap<QString,QVariant> objmap;
};
#define  AGENT_PATH "/org/dbusConnmam/Agent"

class DBusConnman : public QObject
{
    Q_OBJECT
public:
    explicit DBusConnman(QObject *parent = nullptr);
    QString LanMacAddress,LanIPAddress,LANNetMask,LANNetGate,WLanMacAddress,WLanIPAddress;
    QDBusInterface *conn_manager; //存储的是net.connman.Manager的接口
    QMap<QString,QVariant>  properties_map;
    QList<arrayElement>  services_list;     //保存的是当前服务的名单
    QList<arrayElement> technologies_list;
    QList<arrayElement> wifi_list;
    huaSiAgent *agent;
    quint8 netConnectType;//网络的服务类型 =1 有线传输 2无线传输 3蓝牙传输
    QString connectedWIFIName;
    void connenctConnman(void);//连接DBUS上的Connman服务
    bool getProperties();
    bool getTechnologies();
    bool getServices();
    bool getArray(QList<arrayElement>&, const QDBusMessage&);
    bool getMap(QMap<QString,QVariant>&, const QDBusMessage&);
    bool unregisterAgent(void);
    void getLanAndWLanInformation(void);
//    void enableWLAN(void);//打开无线网络，关闭有线网络
//    void enableLAN(void); //打开有线网络，关闭无线网络
    bool enableWLAN(bool);//打开或关闭无线网络 参数=true 是打开无线网络 =false 是关闭无线网络 返回值=true 是执行成功 =false 是执行失败
    bool enableLAN(bool); //打开或关闭有线网络 参数=true 是打开无线网络 =false 是关闭无线网络 返回值=true 是执行成功 =false 是执行失败
    quint8 getCurrentServiceType(void); //获取当前服务的网络类型 返回值为int类型 =1 有线传输 2无线传输 3蓝牙传输

    bool setLanIPAddress(QString);
    void setWIFIPassCode(QString passCode);

signals:
    void service_changed(int type); //type用来表示服务的变化类型 是减少服务 还是增加服务 通知其他类，服务已经发生了改变
    void canGetIPAddressSig(); //有线网络或者无线网络在网络变化后，获取IP地址完成的信号
public slots:
    void scan_wifi(void);
    void connect_wifi(QString WIFIName);
    void disconnect_wifi(QString WIFIName);


private slots:
    void dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage);
    void dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage);

};

#endif // DBUS_CONNMAN_H
