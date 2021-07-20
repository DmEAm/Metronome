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

public:
    explicit PlayerController(QObject *parent = nullptr);

    bool isWork();
    void setWorkState(const bool &workState);
    Q_INVOKABLE void changeWorkState();

signals:
    void workStateChanged();

private slots:
    void on_positionChanged(qint64 t);
    void on_durationChanged(qint64 t);
    void mediaStatuChngd(QMediaPlayer::MediaStatus t);
    void click();

private:
    bool m_isWork;
    QMediaPlayer *_player;
    QMediaPlaylist *_playlist;
    QTimer *_timer;
    QBuffer *buffer;
    QSoundEffect *sound;
    int count;
    int time;

};

#endif // MAIN_HPP
