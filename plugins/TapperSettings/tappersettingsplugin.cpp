#include "tappersettingsplugin.hpp"

void TapperSettingsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TapperSettingsController>(uri, 1, 0, "TapperSettingsController");
}
