#include "playersettingscontroller.hpp"
#include <QDebug>

PlayerSettingsController::PlayerSettingsController(QObject *parent)
: ICongigurable(parent)
{
    QStringList sett = {"Player/Volume"};
    QStringList basic = {"0.25"};
    configure(sett, basic);
}

int PlayerSettingsController::volume() const
{
    return int(_settings["Player/Volume"].toFloat() * 100);
}

void PlayerSettingsController::setVolume(int volume)
{
    QString stringVolume = QString::number(double(volume) / 100.0);
    if(_settings["Player/Volume"] != stringVolume)
        _settings["Player/Volume"] = stringVolume;
}
