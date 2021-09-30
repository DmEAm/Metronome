#ifndef TAPPER_PLUGIN_HPP
#define TAPPER_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "tapper.hpp"
#include "tappersettingscontroller.hpp"

class TapperPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TAPPER_PLUGIN_HPP
