#include "player.hpp"

PlayerController::PlayerController(QObject *parent) : QObject(parent)
{
    _player = new QMediaPlayer(this, QMediaPlayer::LowLatency);
    _playlist = new QMediaPlaylist(_player);
    sound = new QSoundEffect(this);
    m_isWork = false;
    count = 0;
    time = 0;
    sound->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    //sound->setLoopCount(QSoundEffect::Infinite);
    sound->setVolume(0.25f);
    //sound->play();

    _playlist->addMedia(QUrl("qrc:/audio/stick_1"));
    _playlist->setPlaybackMode(QMediaPlaylist::Sequential);
    _playlist->setCurrentIndex(0);
    _player->setPlaylist(_playlist);
    _player->setVolume(70);

    /*
    QFile file(":/audio/stick_1");
   file.open(QIODevice::ReadOnly);
   auto arr = new QByteArray();
   arr->append(file.readAll());
   file.close();
   buffer = new QBuffer(arr);
   buffer->open(QIODevice::ReadWrite);

   _player->setMedia(QMediaContent(), buffer);
    */
    _timer = new QTimer(this);
    connect(_timer, &QTimer::timeout, this, &PlayerController::click);

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
        _timer->start(1000);
        time = clock();
    }
    else
    {
        _timer->stop();
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

void PlayerController::click()
{
    qDebug() << "" << clock() - time;
    time = clock();
    qDebug() << "new " << count;
    count++;
    sound->play();
}
