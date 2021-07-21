#ifndef MAIN_HPP
#define MAIN_HPP

#include <time.h>

#include <QObject>
#include <QString>
#include <QQuickItem>
#include <QtMultimedia>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QTimer>
#include <QDateTime>

#include "soundstruct.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWork READ isWork WRITE setWorkState NOTIFY workStateChanged)

    int time;

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController();

    bool isWork();
    void setWorkState(const bool &workState);
    Q_INVOKABLE void changeWorkState();
    void sclick();

signals:
    void workStateChanged();
    void click();
    void stp();

private:
    bool m_isWork;
    QTimer *_timer;
    QSoundEffect *sound;
    QThread *thread;
};

#endif // MAIN_HPP
