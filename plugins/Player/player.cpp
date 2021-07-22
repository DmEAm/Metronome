#include "player.hpp"

PlayerController::PlayerController(QObject *parent)
: QObject(parent)
, _playing(false)
, _tempoLimit(230)
, _timer(new QTimer(this))
, _soundStruct(new SoundStruct(this))
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, _soundStruct, &SoundStruct::click);
    connect(this, &PlayerController::toggled, this, &PlayerController::changeState);
    connect(this, &PlayerController::changedTempo, this, &PlayerController::changeState);
}

bool PlayerController::playing() const
{
    return _playing;
}

void PlayerController::toggle()
{
    _playing = !_playing;
    emit toggled();
}

void PlayerController::changeState()
{
    if(_playing)
    {
        _soundStruct->click();
        _timer->start(_soundStruct->interval());
    }
    else
    {
        _soundStruct->stop();
        _timer->stop();
    }
}

bool PlayerController::tempo() const
{
    return _soundStruct->_tempo;
}

void PlayerController::setTempo(size_t tempo)
{
    if (tempo == _soundStruct->_tempo)
        return;
    else if((int)tempo > _tempoLimit)
        return;
    _soundStruct->_tempo = tempo;
    emit changedTempo();
}

