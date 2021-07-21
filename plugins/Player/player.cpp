#include "player.hpp"

PlayerController::PlayerController(QObject *parent)
: QObject(parent)
, _effect(new QSoundEffect(this))
, _timer(new QTimer(this))
, _tempo(120)
, _playing(false)
{
    _effect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    _effect->setVolume(0.25f);
    _effect->setLoopCount(0);

    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, _effect, &QSoundEffect::play);
}

bool PlayerController::playing() const
{
    return _playing;
}

void PlayerController::toggle()
{
    _playing = !_playing;

    if(_playing)
    {
        _effect->play();
        _timer->start(1000 * 60 / (int)_tempo);
    }
    else
    {
        _effect->stop();
        _timer->stop();
    }
    emit toggled();
}

bool PlayerController::tempo() const
{
    return _tempo;
}

void PlayerController::setTempo(size_t tempo)
{
    _tempo = tempo;
}

