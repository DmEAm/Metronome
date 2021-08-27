#include "playersettingscontroller.hpp"

PlayerSettingsController::PlayerSettingsController(QObject *parent)
: ICongigurable(parent)
{
    QStringList sett = {"Player/Volume"};
    QStringList basic = {"0.25"};
    configure(sett, basic);
}
