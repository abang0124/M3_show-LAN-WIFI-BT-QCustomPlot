#include <QPixmap>
#include <QQuickView>
#include <QDebug>
#include <QDateTime>
#include <QDir>
#include "screencapture.h"

ScreenCapture::ScreenCapture(QQuickWindow *currentWindow) :
    QObject(0), currentWindow (currentWindow)
{
}

void ScreenCapture::capture () const
{
    QString cmd;
    QString filePathName = "full-"+QDateTime::currentDateTime().toString("hh-mm-ss")+".jpg";

    //QString filePath ="/test";
    QString filePath ="/media/usb0/data";
    QString absFileName = filePath + "/"+filePathName;

    QDir dir(filePath);

    if( !dir.exists() )
    {
        if( dir.mkpath(filePath) )
        {
            qDebug()<<"create dir:"<<filePath;
        }
    }
    qDebug()<<"save file Path="<<absFileName;
    QImage p = currentWindow->grabWindow();
    bool kk = p.save (absFileName);
    cmd = "sync";
    system(cmd.toLatin1().data());
    qDebug () << kk;
}
