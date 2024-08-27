#include "huasiagent.h"
#include "agent_adaptor.h"
#include "agent_interface.h"

huaSiAgent::huaSiAgent(QObject *parent) : QObject(parent)
{
    input_map.clear();
    new AgentAdaptor(this);
    bool result = QDBusConnection::systemBus().registerObject(AGENT_OBJECT, this);
    //bool result = QDBusConnection::sessionBus().registerObject(AGENT_OBJECT, this);
    if(result)
    {
        qDebug()<<"in the agent registed success";
    }
    else {
        qDebug()<<"in the agent registed failed";
    }
    //creat an interface for the agent
    //huasi::Agent *iface;
    //iface = new huasi::Agent(QString("huasi.agent"),QString("/org/huasi/agent"),QDBusConnection::systemBus(),this);
}

void huaSiAgent::Release()
{
    qDebug()<<"unregistered in agent";
    //return;
}

void huaSiAgent::ReportError(QDBusObjectPath path, QString err)
{
    (void) path;
    qDebug()<<"there is an error accure in huasiagent.cpp ReportError,error is"<<err;
}

void huaSiAgent::RequestBrowser(QDBusObjectPath path, QString url)
{
    (void) path;
    qDebug()<<"there is an requestBrowser accure in huasiagent.cpp RequestBrowser,url is"<<url;
}

QVariantMap huaSiAgent::RequestInput(QDBusObjectPath path, QMap<QString, QVariant> dict)
{
    (void) path;
    qDebug()<<"the request path is "<<path.path();
    qDebug()<<dict.size();
    qDebug()<<dict.keys();

    //this->createInputMap(dict);

    QMap<QString,QVariant> rtn;
    rtn.clear();
    //rtn.insert("Passphrase",QVariant("schiller"));
    rtn.insert("Passphrase",QVariant(passCode));
    return rtn;
    //rtn.clear();
}

void huaSiAgent::Cancel()
{
    return;
}
//将QMap<QString,QVariant>转换为 QMap<QString，QString>
void huaSiAgent::createInputMap(const QMap<QString, QVariant> &r_map)
{
    input_map.clear();//清除类成员
    QMap<QString,QVariant>::const_iterator i = r_map.constBegin();

    while (i!=r_map.constEnd()) {

        if(!i.value().canConvert<QDBusArgument>()) //如果不能转换为QDBusArgumnent
        {
            return;
        }
        const QDBusArgument qdba = i.value().value<QDBusArgument>(); //将对应的值转换为QDBusArgument 的数据类型
        if(qdba.currentType()!=QDBusArgument::MapType) //如果不是一个Map的数据类型
        return;
        qdba.beginMap();
        QMap<QString,QString> m;
        while (!qdba.atEnd()) {
            QString k;
            QVariant v;
            qdba.beginMapEntry();
            qdba>>k>>v;

            qdba.endMapEntry();
            m.insert(k,v.toString());
        }
        qdba.endMap();
        if(m.contains("Requirement"))
        {

            QString val = QString();
            if ( m.value("Requirement").contains("mandatory", Qt::CaseInsensitive) || m.value("Requirement").contains("informational", Qt::CaseInsensitive) )
            {
              if (m.contains("Value") ) val = m.value("Value");
            }
            input_map[i.key()] = val;
        }

        i++;

    }
    return;
}
