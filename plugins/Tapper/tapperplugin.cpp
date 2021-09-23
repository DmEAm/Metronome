#include "tapperplugin.hpp"

void TapperPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TapperController>(uri, 1, 0, "TapperController");
    qmlRegisterType<TapperSettingsController>(uri, 1, 0, "TapperSettingsController");
}
