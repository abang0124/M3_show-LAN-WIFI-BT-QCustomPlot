#include "battery.h"

Battery::Battery(QObject *parent) : QObject(parent) //构造函数
{
    //filename = "/dev/bat_volt";
    fd = ::open("/dev/bat_volt",O_RDONLY);//只读方式打开设备文件,c语言函数前要加::
    if(-1==fd)
    {
        qDebug()<<"The device file open failed";
    }
}

void Battery::readBatteryValue() //读取电池电量//实际电池的电压变化范围是1520mv~1800mv对应的电池百分比是1~100
{
    int ret;
    ret = ::read(fd,batVal,sizeof (batVal));
    if(ret<0)
    {
        batVal[0] = -1;
    }
}
