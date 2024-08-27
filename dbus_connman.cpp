#include "dbus_connman.h"


# define DBUS_PATH "/"
# define DBUS_CON_SERVICE "net.connman"
# define DBUS_VPN_SERVICE "net.connman.vpn"
# define DBUS_CON_MANAGER "net.connman.Manager"
# define DBUS_VPN_MANAGER "net.connman.vpn.Manager"



DBusConnman::DBusConnman(QObject *parent) : QObject(parent)
{

    //bool result;
    //    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
    //    qDebug()<<"PropertyChanged reslut is"<<result;


    //    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    //    qDebug()<<"ServicesChanged reslut is"<<result;
    //    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PeersChanged", this, SLOT(dbsPeersChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    //    qDebug()<<"PeersChanged reslut is"<<result;

    bool result;
    agent = new huaSiAgent(this);
    conn_manager = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);//连接到net.connman.Manager的接口上
    QDBusMessage reply = conn_manager->call("RegisterAgent",QVariant::fromValue(QDBusObjectPath(AGENT_OBJECT))); //将huaSiAgent的对象注册到当前的connman上
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    //qDebug()<<"result = "<<result;
    result = this->getServices();
    //qDebug()<<"result = "<<result;
    result = this->getTechnologies();
    //qDebug()<<"result = "<<result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
    //qDebug()<<"result = "<<result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));


    //qDebug()<<"getServices result is "<<result;
    //尝试获取网卡的IP地址
    //QNetworkInterface ifterface = QNetworkInterface();
    //qDebug()<<"mac address"<<ifterface.hardwareAddress();
}

void DBusConnman::connenctConnman()
{

    conn_manager = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);//连接到connman
    //打印出当前设备的属性，功能 和 服务
    if(getProperties())
    {
        qDebug()<<"the property size is "<<properties_map.size();
    }

    if(getServices())
    {
        qDebug()<<"the services size is "<<services_list.length();
        for(int i = 0;i<services_list.length();i++)
        {

            //qDebug()<<services_list[i].objpath.path();
            if(services_list[i].objmap.value("Type").toString()=="wifi")
            {
                qDebug()<<"name is "<<services_list[i].objmap.value("Name").toString();
            }
        }
    }
    if(getTechnologies())
    {
        qDebug()<<"the technologies list is"<<technologies_list.length();
        for(int i = 0;i<technologies_list.length();i++)
        {

            //qDebug()<<technologies_list[i].objpath.path();
            qDebug()<<technologies_list[i].objmap.value("Type").toString();
            //                foreach(const QString &key,technologies_list[i].objmap.keys())
            //                {
            //                    qDebug()<<"key = "<<key;
            //                }
            if(technologies_list[i].objmap.value("Type") == "wifi")
            {

                QDBusInterface *iface = new QDBusInterface(DBUS_CON_SERVICE,technologies_list[i].objpath.path(),"net.connman.Service",QDBusConnection::systemBus(),this);
                QDBusMessage re = iface->call("GetProperties");
                getMap(properties_map,re);
                //                    foreach(const QString &key,properties_map.keys())
                //                    {
                //                        qDebug()<<"properties key = "<<key;
                //                    }
                //qDebug()<<"TetheringIdentifier is"<<properties_map.value("TetheringIdentifier");
                //qDebug()<<"TetheringPassphrase is"<<properties_map.value("TetheringPassphrase");
                //qDebug()<<"TetheringIdentifier contains is"<<properties_map.contains("TetheringIdentifier");
                //qDebug()<<"TetheringPassphrase contains is"<<properties_map.contains("TetheringPassphrase");
                //                    qDebug()<<"TetheringIdentifier is"<<technologies_list[i].objmap.value("TetheringIdentifier").toString();
                //                    qDebug()<<"TetheringPassphrase is"<<technologies_list[i].objmap.value("TetheringPassphrase").toString();
                //                    qDebug()<<"Passphrase is"<<technologies_list[i].objmap.value("Passphrase").toString();
                //                    qDebug()<<"TetheringIdentifier contains is"<<technologies_list[i].objmap.contains("TetheringIdentifier");
                //                    qDebug()<<"TetheringPassphrase contains is"<<technologies_list[i].objmap.contains("TetheringPassphrase");
                //                    qDebug()<<"Passphrase contains is"<<technologies_list[i].objmap.contains("Passphrase");
            }
        }
    }
    //conn_manager->call(QDBus::AutoDetect,"RegisterAgent", QVariant::fromValue(QDBusObjectPath(AGENT_PATH)));
    bool result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
    //result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
    //qDebug()<<"PropertyChanged result is "<<result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "ServicesChanged", this, SLOT(dbsServicesChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    //qDebug()<<"ServicesChanged result is "<<result;
    //        result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "PeersChanged", this, SLOT(dbsPeersChanged(QList<QVariant>, QList<QDBusObjectPath>, QDBusMessage)));
    //        qDebug()<<"PeersChanged result is "<<result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "TechnologyAdded", this, SLOT(dbsTechnologyAdded(QDBusObjectPath, QVariantMap)));
    //qDebug()<<"TechnologyAdded result is "<<result;
    result = QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, "TechnologyRemoved", this, SLOT(dbsTechnologyRemoved(QDBusObjectPath)));
    //qDebug()<<"TechnologyRemoved result is "<<result;
}


//获取connman Manager所提供的所有的属性值
bool DBusConnman::getProperties()
{
    // call connman and GetProperties
    QDBusMessage reply = conn_manager->call("GetProperties");
    //shared::processReply(reply);

    // call the function to get the map values
    properties_map.clear();
    return getMap(properties_map, reply);
}
//获取所有的接口值，如有线，无线和蓝牙
bool DBusConnman::getTechnologies()
{
    // call connman and GetTechnologies
    QDBusMessage reply = conn_manager->call("GetTechnologies");
    //shared::processReply(reply);

    // call the function to get the map values
    technologies_list.clear();
    return getArray(technologies_list, reply);

}
//获取所有的服务
bool DBusConnman::getServices()
{
    bool result;
    QDBusMessage reply = conn_manager->call("GetServices");
    //shared::processReply(reply);

    // call the function to get the map values
    //qDebug()<<reply;
    services_list.clear();
    result = getArray(services_list, reply);
    //qDebug()<<"services_list.length  = "<<services_list.length();
    for(int i = 0;i<services_list.length();i++)
    {
        QDBusConnection::systemBus().connect(DBUS_CON_SERVICE,services_list[i].objpath.path(),"net.connman.Service","PropertyChange",this,SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
    }
    return result;
}
//获取数组值
bool DBusConnman::getArray(QList<arrayElement> &r_list, const QDBusMessage &r_msg)
{
    // make sure r_msg is a QDBusArgument
    if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;

    // make sure the QDBusArgument holds an array
    const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
    if (qdb_arg.currentType() != QDBusArgument::ArrayType ) return false;

    // iterate over the QDBusArgument pulling array elements out and inserting into
    // an arrayElement structure.
    qdb_arg.beginArray();
    r_list.clear();

    while ( ! qdb_arg.atEnd() ) {
        // make sure the argument is a structure type
        if (qdb_arg.currentType() != QDBusArgument::StructureType ) return false;

        arrayElement ael;
        qdb_arg.beginStructure();
        qdb_arg >> ael.objpath >> ael.objmap;
        qdb_arg.endStructure();
        r_list.append (ael);
    } // while
    qdb_arg.endArray();

    return true;
}


//获取字典值
bool DBusConnman::getMap(QMap<QString, QVariant> &r_map, const QDBusMessage &r_msg)
{
    // make sure r_msg is a QDBusArgument
    if ( ! r_msg.arguments().at(0).canConvert<QDBusArgument>() ) return false;

    // make sure the QDBusArgument holds a map
    const QDBusArgument &qdb_arg = r_msg.arguments().at(0).value<QDBusArgument>();
    if (qdb_arg.currentType() != QDBusArgument::MapType ) return false;

    // iterate over the QDBusArgument pulling map keys and values out
    qdb_arg.beginMap();
    r_map.clear();

    while ( ! qdb_arg.atEnd() ) {
        QString key;
        QVariant value;
        qdb_arg.beginMapEntry();
        qdb_arg >> key >> value;
        qdb_arg.endMapEntry();
        r_map.insert(key, value);
    }
    qdb_arg.endMap();

    return true;
}



bool DBusConnman::unregisterAgent()
{
    //QDBusConnection *iface = new QDBusConnection();
    conn_manager = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);//连接到connman
    QDBusMessage reply = conn_manager->call("UnregisterAgent",QVariant::fromValue(QDBusObjectPath(AGENT_OBJECT))); //将huaSiAgent的对象注册到当前的connman上
    qDebug()<<"unregisterAgent reply is"<<reply;
}

void DBusConnman::getLanAndWLanInformation() //获取有线和无线的信息 有线信息有 mac地址 IP地址 网关，子网掩码  无线信息有mac地址，IP地址
{
    QMap<QString,QVariant> map;
    this->getServices();
    qDebug()<<"in getLanAndWLanInformation";
    qDebug()<<"the length is "<<services_list.length();
    LanIPAddress = "";
    LanMacAddress = "";
    LANNetGate = "";
    LANNetMask = "";
    WLanIPAddress = "";
    WLanMacAddress = "";
    for(int i = 0;i<services_list.length();i++)
    {
        //qDebug()<<services_list;
//**************************************************************************************************
        //本段为测试代码，用来打印当前服务的详细信息
//        qDebug()<<services_list[i].objmap.value("Type").toString();
//        qDebug()<<"the map length is "<<services_list[i].objmap.size();
//        QMap<QString,QVariant>::iterator itor;
//        for (itor =services_list[i].objmap.begin();itor != services_list[i].objmap.end();++itor ) {
//            // qDebug()<<itor.key()<<"="<<itor.value()<<itor.value().canConvert<QDBusArgument>();
//            if(itor.value().canConvert<QDBusArgument>())
//            {
//                const QDBusArgument testarg = itor.value().value<QDBusArgument>();
//                qDebug()<<itor.key()<<"{";
//                testarg.beginMap();
//                map.clear();
//                while ( ! testarg.atEnd() ) {
//                    QString key;
//                    QVariant value;
//                    testarg.beginMapEntry();
//                    testarg >> key >> value;
//                    testarg.endMapEntry();
//                    //Debug()<<"test";
//                    //qDebug()<<key;
//                    qDebug()<<key<<"="<<value.toString();
//                    map.insert(key, value);

//                }
//                testarg.endMap();
//                qDebug()<<"}";

//            }
//            else if(itor.value().canConvert<QStringList>())
//            {
//                const QStringList strList = itor.value().value<QStringList>();
//                qDebug()<<itor.key()<<"[";
//                if(strList.size())
//                {
//                    for(int i =0;i<strList.size();i++)
//                    {
//                        qDebug()<<strList[i];
//                    }
//                }
//                qDebug()<<"]";
//            }
//            else {
//                qDebug()<<itor.key()<<itor.value();
//            }
//        }
//************************************************************************************************
        if(services_list[i].objmap.value("Type").toString()=="ethernet")//如果是有线网络
        {
            //不加const 会报错 can not write from a read only object
            const QDBusArgument arg = services_list[i].objmap.value("Ethernet").value<QDBusArgument>();
            if(arg.currentType()==QDBusArgument::MapType)
            {

                arg.beginMap();
                map.clear();
                while ( ! arg.atEnd() ) {
                    QString key;
                    QVariant value;
                    arg.beginMapEntry();
                    arg >> key >> value;
                    arg.endMapEntry();
//                    qDebug()<<"test";
//                    qDebug()<<key <<"="<<value;
                    map.insert(key, value);

                }
                arg.endMap();
            }
//            qDebug()<<"================================================";
            LanMacAddress = map.value("Address").toString();
            const QDBusArgument IPV4 = services_list[i].objmap.value("IPv4").value<QDBusArgument>();

            if(IPV4.currentType()==QDBusArgument::MapType)
            {
                IPV4.beginMap();
                map.clear();

                while ( ! IPV4.atEnd() ) {
                    QString key;
                    QVariant value;
                    IPV4.beginMapEntry();
                    IPV4 >> key >> value;
                    //qDebug()<<"key = "<<key;
                    IPV4.endMapEntry();
                    map.insert(key, value);
//                    qDebug()<<key<<" = "<<value;
                }
                IPV4.endMap();
            }

            LanIPAddress =  map.value("Address").toString();
            LANNetGate = map.value("Gateway").toString();
            LANNetMask = map.value("Netmask").toString();
            qDebug()<<"Address = "<<LanIPAddress<<"Netmask = "<<LANNetMask;
        }
        if(services_list[i].objmap.value("Type").toString()=="wifi")
        {
            connectedWIFIName = services_list[i].objmap.value("Name").toString();
            const QDBusArgument arg = services_list[i].objmap.value("Ethernet").value<QDBusArgument>();
            if(arg.currentType()==QDBusArgument::MapType)
            {

                arg.beginMap();
                map.clear();
                while ( ! arg.atEnd() ) {
                    QString key;
                    QVariant value;
                    arg.beginMapEntry();
                    arg >> key >> value;
                    arg.endMapEntry();
                    map.insert(key, value);
                }
                arg.endMap();
            }
            WLanMacAddress = map.value("Address").toString();
            const QDBusArgument IPV4 = services_list[i].objmap.value("IPv4").value<QDBusArgument>();

            if(IPV4.currentType()==QDBusArgument::MapType)
            {
                IPV4.beginMap();
                map.clear();

                while ( ! IPV4.atEnd() ) {
                    QString key;
                    QVariant value;
                    IPV4.beginMapEntry();
                    IPV4 >> key >> value;
                    qDebug()<<"key = "<<key;
                    IPV4.endMapEntry();
                    map.insert(key, value);
                }
                IPV4.endMap();
            }

            WLanIPAddress =  map.value("Address").toString();

        }
    }
}

bool DBusConnman::enableWLAN(bool onOrOff) //打开或关闭无线网络 参数=true 是打开无线网络 =false 是关闭无线网络 返回值=true 是执行成功 =false 是执行失败
{
    QDBusInterface *con = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);
    QDBusMessage reply =  con->call("GetTechnologies");//获取
    QList<arrayElement> elemetlist;
    elemetlist.clear();
    getArray(elemetlist,reply);
    for(int i = 0;i<elemetlist.length();i++)
    {
        if(elemetlist[i].objmap.value("Type").toString()=="wifi")//有线网络
        {
            con = new QDBusInterface(DBUS_CON_SERVICE,elemetlist[i].objpath.path(),"net.connman.Technology",QDBusConnection::systemBus(),this);
            reply = con->call("SetProperty","Powered",QVariant::fromValue(QDBusVariant(onOrOff)));
            qDebug()<<reply;
            if (reply.type()==QDBusMessage::ReplyMessage)
            {
                return true;
            }
            else{
                qDebug()<<"there is an dbus error,the name is"<<reply.errorName();
                //if(reply.errorName() == "net.connman.Error.AlreadyDisabled")//根据报错的具体信息，如果是已经使能了，那么也算切换成功了
                if((reply.errorName() == "net.connman.Error.AlreadyDisabled")||(reply.errorName() == "net.connman.Error.AlreadyEnabled"))//根据报错的具体信息，如果是已经使能了，那么也算切换成功了
                {
                    return true;
                }
                else {
                   return false ;
                }

            }
        }
    }
}

bool DBusConnman::enableLAN(bool onOrOff) //打开或关闭有线网络 参数=true 是打开无线网络 =false 是关闭无线网络 返回值=true 是执行成功 =false 是执行失败
{
    QDBusInterface *con = new QDBusInterface(DBUS_CON_SERVICE, DBUS_PATH, DBUS_CON_MANAGER, QDBusConnection::systemBus(), this);
    QDBusMessage reply =  con->call("GetTechnologies");//获取
    QList<arrayElement> elemetlist;
    elemetlist.clear();
    getArray(elemetlist,reply);
    for(int i = 0;i<elemetlist.length();i++)
    {
        if(elemetlist[i].objmap.value("Type").toString()=="ethernet")//有线网络
        {
            con = new QDBusInterface(DBUS_CON_SERVICE,elemetlist[i].objpath.path(),"net.connman.Technology",QDBusConnection::systemBus(),this);
            reply = con->call("SetProperty","Powered",QVariant::fromValue(QDBusVariant(onOrOff)));
            qDebug()<<reply;
            if (reply.type()==QDBusMessage::ReplyMessage)
            {
                //netConnectType = 2;
                return true;
            }
            else{
                qDebug()<<"there is an dbus error,the name is"<<reply.errorName();
                //if(reply.errorName() == "net.connman.Error.AlreadyDisabled")//根据报错的具体信息，如果是已经使能了，那么也算切换成功了
                if((reply.errorName() == "net.connman.Error.AlreadyDisabled")||(reply.errorName() == "net.connman.Error.AlreadyEnabled"))//根据报错的具体信息，如果是已经使能了，那么也算切换成功了
                {
                    return true;
                }
                else {
                   return false ;
                }
            }
        }
    }
}


quint8 DBusConnman::getCurrentServiceType() //获取当前服务的网络类型 返回值为int类型 =1 有线传输 2无线传输 3蓝牙传输   仅在上电初期调用该函数查看上次用的是无线 有线还是蓝牙
{
    quint8 result = 0;

    qDebug()<<"services_list.size() = "<<services_list.size();
    if(services_list.size() == 0) //如果DBus当前没有服务，那么默认就是启动蓝牙服务
    {
        result = 3;
    }
    else {
        for(int i = 0;i<services_list.size();i++)
        {
            if(services_list[i].objmap.value("Type").toString() == "ethernet") //当前类型是有线类型
            {
                result = 1;
            }
            else if(services_list[i].objmap.value("Type").toString() == "wifi")
            {
                result = 2;
            }
//            else {   //如果都不是，那么就是打开的蓝牙
//                result = 3;
//            }
            //        else if (services_list[i].objmap.value("Type").toString() == "bluetooth")
            //        {
            //            result = 3;
            //        }
        }
    }


    netConnectType = result;
    return result;
}

bool DBusConnman::setLanIPAddress(QString addressMsg) //设置有线的IP地址
{
//该方法存在问题，无法设置IP地址，在调用 SetProperty的方法时报错

//QDBusMessage(type=Error, service=":1.9", error name="net.connman.Error.InvalidProperty", error message="Invalid property", signature="s", contents=("Invalid property") )
    if(getCurrentServiceType() == 1)//如果当前的服务类型是有线服务
    {
        this->getServices();//获取当前的服务
        if(services_list.size())
        {
            for(int i = 0;i<services_list.size();i++)
            {
                if(services_list[i].objmap.value("Type").toString() == "ethernet") //获取出有线连接
                {
                    QDBusInterface *con = new QDBusInterface(DBUS_CON_SERVICE,services_list[i].objpath.path(),"net.connman.Service",QDBusConnection::systemBus(),this);
                    QMap<QString,QVariant> map; //插入字典的类型就是QString和QVariant

                    map.insert("Address","192.168.1.101");
                    map.insert("Gateway","192.168.1.1");
                    map.insert("Method","dhcp");
                    map.insert("Netmask","255.255.255.0");
                    QDBusArgument arg;
                    QMap<QString,QVariant>::iterator itor;
                    //qDBusRegisterMetaType<QVariant>();
                    arg.beginMap(QVariant::String,qMetaTypeId<QDBusVariant>());
                    for(itor = map.begin();itor!= map.end();itor++)
                    {
                        arg.beginMapEntry();
                        arg<<itor.key()<<QDBusVariant(itor.value());
                        arg.endMapEntry();
                    }
                    arg.endMap();

                    for(itor = map.begin();itor!= map.end();itor++)
                    {
                        //arg<<itor.key()<<itor.value() ;
                        qDebug()<<itor.key();
                        qDebug()<<itor.value().toString();
                    }

                    QDBusMessage reply = con->call("SetProperty","IPv4",QVariant::fromValue(QDBusVariant(QVariant::fromValue(arg))));
                    //QDBusMessage reply = con->call("SetProperty","IPv4",QVariant::fromValue(arg));
                    qDebug()<<reply;
                    return true;
                }
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

void DBusConnman::setWIFIPassCode(QString passCode) //设置wifi密码
{
    agent->passCode = passCode; //将密码传递给huasigent类
}


void DBusConnman::dbsServicePropertyChanged(QString property, QDBusVariant dbvalue, QDBusMessage msg) //属性发生改变
{
    qDebug()<<"in dbsPropertyChanged";
    qDebug()<<property<<dbvalue.variant();
    if(property == "State") //状态属性的改变
    {
        if(netConnectType == 1) //如果当前的网络连接为有线网络
        {
            if(dbvalue.variant().toString() == "ready") //网络配置获取完成
            {
                QString str = "ifconfig>/demo/ifconfig.data";//将有线网络相关的信息存储到/demo/ifconfig.data这个文件中。这是为了解决connman无法在此设备上获取MAC地址，网管信息等
                system(str.toLatin1().data());
                qDebug()<<"system runned ++++++++++++++++++++++++++++++++++";
                emit canGetIPAddressSig();
            }

        }
        else if(netConnectType == 2)//如果当前的网络连接我无线网络
        {
            if((dbvalue.variant().toString() == "online")||(dbvalue.variant().toString() == "association")||(dbvalue.variant().toString() == "ready")) //网络连接成
            {
                QString str = "ifconfig>/demo/wlanifconfig.data";//将有线网络相关的信息存储到/demo/wlanifconfig.data这个文件中。这是为了解决connman有时无法在此设备上获取IP地址等信息
                system(str.toLatin1().data());
                emit canGetIPAddressSig();
            }

        }
        else if(netConnectType == 3) //如果当前的网络连接为蓝牙
        {


        }
    }
}
/**
* dbsServicesChange 函数 参数的意义   第一个参数 QList<QVariant> 存储的是当前service中的路径值，第二个是需要移除的List的路径信息
* 第3个参数是 根据当前是添加和是移除，对应的msg的值
*/
void DBusConnman::dbsServicesChanged(QList<QVariant> vlist, QList<QDBusObjectPath> removed, QDBusMessage msg) //服务类型发生改变
{
    // process removed services   //如果removed 不为空，则说明有services要移除
    if (! removed.isEmpty() ) {
       for (int i = 0; i < services_list.count(); ++i) {
          if (removed.contains(services_list.at(i).objpath) ) {
             QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, services_list.at(i).objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
             services_list.removeAt(i);
          } // if
       } // for
    } // if we needed to remove something

    if (! vlist.isEmpty() )  //如果vlist 不为空，则说明有service要添加
    {
       QList<arrayElement> revised_list;
       if (! getArray(revised_list, msg)) return;

       // merge the existing services_list into the revised_list
       // first find the original element that matches the revised
       for (int i = 0; i < revised_list.size(); ++i) {
          arrayElement revised_element = revised_list.at(i);
          arrayElement original_element = {QDBusObjectPath(), QMap<QString,QVariant>()};
          for (int j = 0; j < services_list.size(); ++j) {
             if (revised_element.objpath == services_list.at(j).objpath)
             {
                original_element = services_list.at(j);
                break;
             } // if
          } // j for

          // merge the new elementArray into the existing
          if (! original_element.objpath.path().isEmpty())
          {
             QMapIterator<QString, QVariant> itr(revised_element.objmap);
             while (itr.hasNext())
             {
                itr.next();
                original_element.objmap.insert(itr.key(), itr.value() );
             } // while

             // now insert the element into the revised list
             QDBusConnection::systemBus().disconnect(DBUS_CON_SERVICE, original_element.objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
             revised_list.replace(i, original_element);
             QDBusConnection::systemBus().connect(DBUS_CON_SERVICE, revised_element.objpath.path(), "net.connman.Service", "PropertyChanged", this, SLOT(dbsServicePropertyChanged(QString, QDBusVariant, QDBusMessage)));
          } // if original element is not empty
       } // i for

       // now copy the revised list to services_list
       services_list.clear();
       services_list = revised_list;
    } // revised_list not empty


    emit service_changed(1);      //发送 service_change 信号
    //测试用的代码
//    for (int i = 0;i<services_list.length();i++)
//    {
//        qDebug()<<services_list[i].objmap.value("Name").toString();
//        qDebug()<<services_list[i].objmap.value("State").toString();
//    }

}


//槽函数 浏览wifi
void DBusConnman::scan_wifi() //浏览 wifi
{
    for(int row = 0;row<technologies_list.length();row++)
    {
        qDebug()<<"in find wifi";
        if(technologies_list[row].objmap.value("Type").toString()=="wifi")
        {
            qDebug()<<"in wifi";
            if(technologies_list[row].objmap.value("Powered").toBool())
            {
                qDebug()<<"in scan";
                QDBusInterface *iface_tech = new QDBusInterface(DBUS_CON_SERVICE,technologies_list[row].objpath.path(),"net.connman.Technology",QDBusConnection::systemBus(),this);
                iface_tech->setTimeout(8*1000);
                QDBusMessage reply = iface_tech->call("Scan");
                iface_tech->deleteLater();
            }
        }
    }

}

void DBusConnman::connect_wifi(QString WIFIName) //连接wifi
{
    this->getServices();//获取当前的所有的服务
    for(int row = 0;row<services_list.length();row++)
    {
        //qDebug()<<"in find wifi";
        if(services_list[row].objmap.value("Type").toString()=="wifi")
        {
            if(services_list[row].objmap.value("Name").toString() == WIFIName) //如果当前网络的名字是SCH-office
            {
                QDBusInterface *iface_service = new QDBusInterface(DBUS_CON_SERVICE,services_list[row].objpath.path(),"net.connman.Service",QDBusConnection::systemBus(),this);
                qDebug()<<services_list[row].objpath.path();
                iface_service->setTimeout(50);
                QDBusMessage reply = iface_service->call(QDBus::AutoDetect,"Connect");
                qDebug()<<"called Connect function"<<reply;
                iface_service->deleteLater();
            }
        }
    }
}

void DBusConnman::disconnect_wifi(QString WIFIName)
{
    this->getServices();//获取当前的所有的服务
    for(int row = 0;row<services_list.length();row++)
    {
        //qDebug()<<"in find wifi";
        if(services_list[row].objmap.value("Type").toString()=="wifi")
        {
            if(services_list[row].objmap.value("Name").toString() == WIFIName) //如果当前网络的名字是SCH-office
            {
                QDBusInterface *iface_service = new QDBusInterface(DBUS_CON_SERVICE,services_list[row].objpath.path(),"net.connman.Service",QDBusConnection::systemBus(),this);
                qDebug()<<services_list[row].objpath.path();
                iface_service->setTimeout(50);
                QDBusMessage reply = iface_service->call(QDBus::AutoDetect,"Disconnect");
                qDebug()<<"called Connect function"<<reply;
                iface_service->deleteLater();
            }
        }
    }
}

//建立DBUS信号与槽的连接




