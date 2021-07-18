#include "player.hpp"

PlayerController::PlayerController(QObject *parent) : QObject(parent)
{
    _player = new QMediaPlayer(this);
    _playlist = new QMediaPlaylist(_player);
    m_isWork = false;
    _playlist->addMedia(QUrl("qrc:/audio/D"));
    _playlist->setPlaybackMode(QMediaPlaylist::Loop);
    _player->setPlaylist(_playlist);
    _player->setVolume(70);

    connect(_player,SIGNAL(positionChanged(qint64)) ,this,SLOT(on_positionChanged(qint64)));
    connect(_player,SIGNAL(durationChanged(qint64)) ,this,SLOT(on_durationChanged(qint64)));
    connect(_player,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),this,SLOT(mediaStatuChngd(QMediaPlayer::MediaStatus)));
}

bool PlayerController::isWork()
{
    return m_isWork;
}

void PlayerController::setWorkState(const bool &workState)
{
    qDebug() << workState;
    if (workState == m_isWork)
        return;

    m_isWork = workState;
    if(m_isWork)
    {
        qDebug() << _player->state();
        _player->play();
        qDebug() << _player->position();
    }
    else
    {
        qDebug() << _player->state();
        _player->stop();
        qDebug() << _player->position();
    }
    emit workStateChanged();
}

void PlayerController::changeWorkState()
{
    setWorkState(!m_isWork);
}

void PlayerController::on_positionChanged(qint64 t)
{
    qDebug() << "position "<< t;
}

void PlayerController::on_durationChanged(qint64 t)
{
    qDebug() << "duration "<< t;
}

void PlayerController::mediaStatuChngd(QMediaPlayer::MediaStatus t)
{
    qDebug() << "Status "<< t;
}
