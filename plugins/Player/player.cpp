#include "player.hpp"

PlayerController::PlayerController(QObject *parent)
    : QObject(parent)
    , _playing(false)
    , _tempo(120)
    , _accent(0)
    , _timer(new QTimer(this))
    , _mixer(new Mixer(this))
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, _mixer, &Mixer::click);
    connect(this, &PlayerController::toggled, this, &PlayerController::changeState);
    connect(this, &PlayerController::changedTempo, this, &PlayerController::changeState);
    connect(this, &PlayerController::changedAccent, this, &PlayerController::changeAccent);
    loadSettings();
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

void PlayerController::loadSettings()
{
    _mixer->loadSettingsVolume();
    _mixer->loadSettingsBaseSound();
    _mixer->loadSettingsAccentSound();
}

void PlayerController::setVolume(QString volume)
{
    _mixer->setVolume(volume);
}

void PlayerController::setBaseSound(QString baseSound)
{
    _mixer->setBaseSound(baseSound);
}

void PlayerController::setAccentSound(QString accentSound)
{
    _mixer->setAccentSound(accentSound);
}

void PlayerController::changeState()
{
    if (_playing)
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

void PlayerController::changeAccent()
{
    _mixer->setAccentMode(_accent);
    changeState();
}

int PlayerController::tempo() const
{
    return _tempo;
}

int PlayerController::accent() const
{
    return _accent;
}

void PlayerController::setTempo(int tempo)
{
    if(tempo == _tempo)
        return;
    _tempo = tempo;
    emit changedTempo();
}

void PlayerController::setAccent(int accent)
{
    if (_accent == accent)
        return;
    _accent = accent;
    emit changedAccent();
}

int PlayerController::interval()
{
    return 1000 * 60 / _tempo;
}

