#include "mixer.h"

Mixer::Mixer(QObject *parent)
: QObject(parent)
, _stdEffect(new QSoundEffect(this))
, _accEffect(new QSoundEffect(this))
, _currentEffect(0)
{
    initStandardEffect();
    initAccentEffect();
    setStandardMode();
}

void Mixer::setStandardMode()
{
    _effects.clear();
    _effects.append(_stdEffect);
    resetPosition();
}

void Mixer::setAccentMode(int accent)
{
    if(accent == 0)
    {
        setStandardMode();
        return;
    }
    _effects.clear();
    _effects.append(_accEffect);
    for(int i = 1; i < accent; i++)
        _effects.append(_stdEffect);
    resetPosition();
}

void Mixer::initStandardEffect()
{
    _stdEffect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    _stdEffect->setVolume(0.25f);
    _stdEffect->setLoopCount(0);
}

void Mixer::initAccentEffect()
{
    _accEffect->setSource(QUrl("qrc:/audio/accient_1(wav)"));
    _accEffect->setVolume(0.25f);
    _accEffect->setLoopCount(0);
}

void Mixer::upPosition()
{
    _currentEffect += 1;
    if(_currentEffect >= _effects.size())
        _currentEffect = 0;
}

void Mixer::resetPosition()
{
    _currentEffect = 0;
}

void Mixer::click()
{
    _effects[_currentEffect]->play();
    upPosition();
}

void Mixer::stop()
{
    if(_effects[_currentEffect]->isPlaying())
        _effects[_currentEffect]->stop();
    resetPosition();
}
