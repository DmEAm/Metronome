#include "player.hpp"

PlayerController::PlayerController(QObject *parent)
: QObject(parent)
, _playing(false)
, _tempo(120)
, _tempoLimit(230)
, _timer(new QTimer(this))
, _mixer(new Mixer(this))
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, _mixer, &Mixer::click);
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
        _mixer->click();
        _timer->start(interval());
    }
    else
    {
        _mixer->stop();
        _timer->stop();
    }
}

size_t PlayerController::tempo() const
{
    return _tempo;
}

void PlayerController::setTempo(size_t tempo)
{
    if(tempo > _tempoLimit)
        return;
    _tempo = tempo;
    emit changedTempo();
}

int PlayerController::interval()
{
    return 1000 * 60 / (int)_tempo;
}

