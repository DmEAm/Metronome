#include "temposettingsplugin.hpp"

void TempoSettingsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<TempoSettingsController>(uri, 1, 0, "TempoSettingsController");
}
