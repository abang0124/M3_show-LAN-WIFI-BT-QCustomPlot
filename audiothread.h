#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H

#include <QObject>
#include <QSoundEffect>
#include <QMediaPlayer>
#include <QDebug>
#include <QTimer>
//播放音乐的子线程类
class AudioThread : public QObject
{
    Q_OBJECT
public:
    explicit AudioThread(QObject *parent = nullptr);

private:
    QMediaPlayer *AlarmSound;
    QTimer *soundTimer;
    int volumValue;
signals:

public slots:
    void AlarmSoundPlay(int level); //level 代表报警声音的等级 0代表高 1代表中 2代表低
    void AlarmSoundStop();
    void onTimeOut();
    void onCreatAudioThread();
    void setSoundVolume(int value);//设置报警声音的大小
};

#endif // AUDIOTHREAD_H
