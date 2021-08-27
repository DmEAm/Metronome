#ifndef PLAYER_SETTINGS_PLUGIN_HPP
#define PLAYER_SETTINGS_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "playersettingscontroller.hpp"

class PlayerSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PLAYER_SETTINGS_PLUGIN_HPP
