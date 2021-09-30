#include "playersettingscontroller.hpp"
#include <QDebug>

PlayerSettingsController::PlayerSettingsController(QObject *parent)
: ICongigurable(parent)
{

}

void PlayerSettingsController::init()
{
    baseSound = {"qrc:/audio/stick_1(wav)", "qrc:/audio/stick_2(wav)",
                 "qrc:/audio/stick_3(wav)", "qrc:/audio/stick_4(wav)",
                 "qrc:/audio/stick_5(wav)", "qrc:/audio/kick_1(wav)"};

    accentSound = {"qrc:/audio/accient_1(wav)", "qrc:/audio/accient_2(wav)"};
    QStringList sett = {"Player/Volume", "Player/BaseSound", "Player/AccentSound"};
    QStringList basic = {"0.25", baseSound[0], accentSound[0]};
    configure(sett, basic);
}

int PlayerSettingsController::volume() const
{
    return int(value(VOLUME).toFloat() * 100);
}

QString PlayerSettingsController::getStrVolume() const
{
    return value(VOLUME);
}

int PlayerSettingsController::idBaseSound() const
{
    return baseSound.indexOf(value(BASESOUND));
}

QString PlayerSettingsController::getStrBaseSound() const
{
    return value(BASESOUND);
}

int PlayerSettingsController::idAccentSound() const
{
    return accentSound.indexOf(value(ACCENTSOUND));
}

QString PlayerSettingsController::getStrAccentSound() const
{
    return value(ACCENTSOUND);
}

void PlayerSettingsController::setVolume(int volume)
{
    QString stringVolume = QString::number(double(volume) / 100.0);
    if(value(VOLUME) != stringVolume)
    {
        valueRef(VOLUME) = stringVolume;
        emit volumeChanged();
    }
}

void PlayerSettingsController::setIdBaseSound(int idBaseSound)
{
    if(idBaseSound < 0 || idBaseSound >= baseSound.size())
        return;
    if(value(BASESOUND) != baseSound[idBaseSound])
    {
        valueRef(BASESOUND) = baseSound[idBaseSound];
        emit idBaseSoundChanged();
    }
}

void PlayerSettingsController::setIdAccentSound(int idAccentSound)
{
    if(idAccentSound < 0 || idAccentSound >= accentSound.size())
        return;
    if(value(ACCENTSOUND) != accentSound[idAccentSound])
    {
        valueRef(ACCENTSOUND) = accentSound[idAccentSound];
        emit idAccentSoundChanged();
    }
}
