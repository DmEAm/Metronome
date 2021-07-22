#include "soundstruct.h"

SoundStruct::SoundStruct(QObject *parent) : QObject(parent),
    _tempo(230)
  , _effects(new QVector<QSoundEffect*>)
  , currentEffect(0)
{
    setStandartMode();
}

SoundStruct::~SoundStruct()
{
    delete _effects;
}

int SoundStruct::interval()
{
    return 1000 * 60 / (int)_tempo;
}

void SoundStruct::setStandartMode()
{
    _effects->clear();
    QSoundEffect *_effect = new QSoundEffect();
    _effect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
    _effect->setVolume(0.25f);
    _effect->setLoopCount(0);
    _effects->append(_effect);
    resetPosition();
}

void SoundStruct::upPosition()
{
    currentEffect += 1;
    if(currentEffect >= _effects->size())
        currentEffect = 0;
}

void SoundStruct::resetPosition()
{
    currentEffect = 0;
}

void SoundStruct::click()
{
    _effects->at(currentEffect)->play();
    upPosition();
}

void SoundStruct::stop()
{
    if(_effects->at(currentEffect)->isPlaying())
        _effects->at(currentEffect)->stop();
    resetPosition();
}
