#include "audiothread.h"



/*Qt中子线程的构造函数相当于时在主线程中创建的所以在此构造函数中的QMediaPlayer 和 soundTimer都属于创造该子线
的主线程，所以无法在该子线程中操作这些对象
*/

AudioThread::AudioThread(QObject *parent) : QObject(parent)
{
//    AlarmSound = new QMediaPlayer(this);
//    //AlarmSound->setMedia(QUrl("qrc:/sound/alarm1.wav"));
//    AlarmSound->setMedia(QUrl("qrc:/sound/alarm2.mp3"));
//    //AlarmSound->setMedia(QUrl::fromLocalFile("./sound/Alarm.mp3"));
//    soundTimer = new QTimer(this);
//    soundTimer->setInterval(500);
//    connect(soundTimer,&QTimer::timeout,this,&AudioThread::onTimeOut);
}

void AudioThread::AlarmSoundPlay(int level)
{

    AlarmSound->setVolume(volumValue);//设置声音的大小是100
    AlarmSound->stop();
    if(level == 0) //报警声音为高等级
    {
        //AlarmSound->setMedia(QUrl("qrc:/sound/alarm1.wav"));
        AlarmSound->setMedia(QUrl("qrc:/sound/alramH.wav"));
       // qDebug()<<"alarm";
        if(AlarmSound->state()!=QMediaPlayer::PlayingState)
        {
            //AlarmSound->play();
            //qDebug()<<"the sound is playing level = "<<level;
            soundTimer->start();
        }
    }
    else if(level == 1)//报警声音为中等级
    {
       // AlarmSound->setMedia(QUrl("qrc:/sound/Alarm.mp3"));
       AlarmSound->setMedia(QUrl("qrc:/sound/alarmM.wav"));
        if(AlarmSound->state()!=QMediaPlayer::PlayingState)
        {
            //AlarmSound->play();
            //qDebug()<<"the sound is playing level = "<<level;
            soundTimer->start();
        }

    }
    else if(level == 2)//报警声音为低等级 //低等级暂时也为关闭声音
    {
        AlarmSound->stop();
        soundTimer->stop();
    }
    else if(level == 3)//关闭报警
    {
        AlarmSound->stop();
        soundTimer->stop();

    }

}

void AudioThread::AlarmSoundStop() //关掉声音
{
    soundTimer->stop();//关闭定时器
    AlarmSound->stop(); //直接关掉报警声
}

void AudioThread::onTimeOut()
{
    if(AlarmSound->state()!=QMediaPlayer::PlayingState)
    {
        AlarmSound->play();
       // qDebug()<<"Play";

    }
    AlarmSound->play();
   // qDebug()<<"Alarm";
}

void AudioThread::onCreatAudioThread()
{
        AlarmSound = new QMediaPlayer();
        AlarmSound->setMedia(QUrl("qrc:/sound/alarm2.mp3"));
        volumValue = 100;//默认声音音量为100
        //AlarmSound->setMedia(QUrl::fromLocalFile("./sound/Alarm.mp3"));
        soundTimer = new QTimer();
        soundTimer->setInterval(500);
        connect(soundTimer,&QTimer::timeout,this,&AudioThread::onTimeOut);
}

void AudioThread::setSoundVolume(int value)
{
    volumValue = value;
    AlarmSound->setVolume(volumValue);//value 的大小在0~100之间
}
