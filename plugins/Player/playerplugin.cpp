#include "playerplugin.hpp"

void PlayerPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<PlayerController>(uri, 1, 0, "PlayerController");
}
