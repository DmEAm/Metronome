#include "mixer.h"

Mixer::Mixer(QObject *parent)
: QObject(parent)
, currentEffect(0)
{
    setStandartMode();
}

void Mixer::setStandartMode()
{
    _effects.clear();
    QSoundEffect *_effect = new QSoundEffect();
    _effect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    _effect->setVolume(0.25f);
    _effect->setLoopCount(0);
    _effects.append(_effect);
    resetPosition();
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
