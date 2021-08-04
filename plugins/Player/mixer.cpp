#include "mixer.h"
#include <QDebug>

Mixer::Mixer(QObject *parent)
: QObject(parent)
, currentEffect(0)
{
    setStandartMode();
}

void Mixer::setStandartMode()
{
    _effects.clear();
    _effects.append(standartEffect());
    resetPosition();
}

void Mixer::setAccentMode(int accent)
{
    if(accent == 0)
    {
        setStandartMode();
        return;
    }
    _effects.clear();
    _effects.append(accentEffect());
    for(int i = 1; i < accent; i++)
        _effects.append(standartEffect());
    resetPosition();
}

QSoundEffect * Mixer::standartEffect()
{
    QSoundEffect *_effect = new QSoundEffect();
    _effect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    _effect->setVolume(0.25f);
    _effect->setLoopCount(0);
    return _effect;
}

QSoundEffect * Mixer::accentEffect()
{
    QSoundEffect *_effect = new QSoundEffect();
    _effect->setSource(QUrl("qrc:/audio/accient_1(wav)"));
    _effect->setVolume(0.25f);
    _effect->setLoopCount(0);
    return _effect;
}

void Mixer::upPosition()
{
    currentEffect += 1;
    if(currentEffect >= _effects.size())
        currentEffect = 0;
}

void Mixer::resetPosition()
{
    currentEffect = 0;
}

void Mixer::click()
{
    _effects[currentEffect]->play();
    upPosition();
}

void Mixer::stop()
{
    if(_effects[currentEffect]->isPlaying())
        _effects[currentEffect]->stop();
    resetPosition();
}
