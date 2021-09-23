#ifndef MAIN_PLUGIN_HPP
#define MAIN_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "player.hpp"
#include "playersettingscontroller.hpp"

class PlayerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MAIN_PLUGIN_HPP
