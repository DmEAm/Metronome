#include "playerplugin.hpp"

void PlayerPlugin::registerTypes(const char *uri)
{
    qmlRegisterUncreatableType<PlayerController>(uri, 1, 0, "PlayerController", "");
    qmlRegisterType<PlayerSettingsController>(uri, 1, 0, "PlayerSettingsController");
}
