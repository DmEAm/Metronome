#include "mixer.hpp"

Mixer::Mixer(QObject *parent)
    : QObject(parent)
    , _stdEffect(new QSoundEffect(this))
    , _accEffect(new QSoundEffect(this))
    , _currentEffect(0)
{
    {
        _stdEffect->setSource(QUrl("qrc:/audio/stick_1(wav)"));
        _stdEffect->setVolume(StandardVolume);
        _stdEffect->setLoopCount(0);
    }

    {
        _accEffect->setSource(QUrl("qrc:/audio/accient_1(wav)"));
        _accEffect->setVolume(StandardVolume);
        _accEffect->setLoopCount(0);
    }

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
    if (accent == 0)
    {
        setStandardMode();
        return;
    }
    _effects.clear();
    _effects.append(_accEffect);
    for (int i = 1; i < accent; i++)
        _effects.append(_stdEffect);
    resetPosition();
}

void Mixer::loadSettingsVolume()
{
    QString volume = QSettings().value( "Player/Volume", "0.25" ).toString();
    setVolume(volume);
}

void Mixer::loadSettingsBaseSound()
{
    QString baseSound = QSettings().value( "Player/BaseSound", "qrc:/audio/stick_1(wav)" ).toString();
    setBaseSound(baseSound);
}

void Mixer::loadSettingsAccentSound()
{
    QString accentSound = QSettings().value( "Player/AccentSound", "qrc:/audio/accient_1(wav)" ).toString();
    setAccentSound(accentSound);
}

void Mixer::setVolume(QString volume)
{
    _stdEffect->setVolume(volume.toFloat());
    _accEffect->setVolume(volume.toFloat());
}

void Mixer::setBaseSound(QString baseSound)
{
    _stdEffect->setSource(QUrl(baseSound));
}

void Mixer::setAccentSound(QString accentSound)
{
    _accEffect->setSource(QUrl(accentSound));
}

void Mixer::upPosition()
{
    _currentEffect += 1;
    if (_currentEffect >= _effects.size())
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
    if (_effects[_currentEffect]->isPlaying())
        _effects[_currentEffect]->stop();
    resetPosition();
}
