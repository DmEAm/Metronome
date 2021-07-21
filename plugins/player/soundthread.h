#ifndef SOUNDTHREAD_H
#define SOUNDTHREAD_H

#include <QObject>
#include <QtMultimedia>

class SoundThread : public QObject
{
    Q_OBJECT

    QSoundEffect *sound;
    bool isWork;

public:
    explicit SoundThread(QObject *parent = nullptr);

public slots:
    void process();
    void stop();

signals:

};

#endif // SOUNDTHREAD_H
