#ifndef BATTERY_H
#define BATTERY_H

#include <QObject>
#include <QDebug>
extern "C"{

    #include "stdio.h"
    #include "unistd.h"
    #include "sys/types.h"
    #include "sys/stat.h"
    #include "fcntl.h"
    #include "stdlib.h"
    #include "string.h"

}
class Battery : public QObject
{
    Q_OBJECT
public:
    explicit Battery(QObject *parent = nullptr);
    int fd;//打开电池文件的文件描述符
    char* filename;

    void readBatteryValue();

     int batVal[2];//第1位为电池电量，第2个数据为电池的充电状态//充电时为高电平，不充电时为低电平
signals:

public slots:
};

#endif // BATTERY_H
