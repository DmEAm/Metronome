#include "soundthread.h"

SoundThread::SoundThread(QObject *parent) : QObject(parent)
{
    sound = nullptr;
    isWork = false;
}

void SoundThread::process()
{
    isWork = true;
    qDebug() << "Start Thread";
    sound = new QSoundEffect(this);
    sound->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    sound->setVolume(0.25f);
    int time = clock();
    while (isWork)
    {
        sound->play();
        QThread::msleep(1000);
        qDebug() << "" << clock() - time;
        time = clock();
    }

}

void SoundThread::stop()
{
    isWork = false;
    if(sound)
    {
        delete sound;
    }
}
