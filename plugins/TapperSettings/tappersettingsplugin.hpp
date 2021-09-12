#ifndef TAPPER_SETTINGS_PLUGIN_HPP
#define TAPPER_SETTINGS_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "tappersettingscontroller.hpp"

class TapperSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TAPPER_SETTINGS_PLUGIN_HPP
