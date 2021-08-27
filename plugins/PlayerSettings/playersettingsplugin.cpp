#include "playersettingsplugin.hpp"

void PlayerSettingsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<PlayerSettingsController>(uri, 1, 0, "PlayerSettingsController");
}
