#ifndef TEMPO_SETTINGS_PLUGIN_HPP
#define TEMPO_SETTINGS_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "temposettingscontroller.hpp"

class TempoSettingsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TEMPO_SETTINGS_PLUGIN_HPP
