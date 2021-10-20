#ifndef UPDOWN_PLUGIN_HPP
#define UPDOWN_PLUGIN_HPP

#include <QQmlExtensionPlugin>

class UpDownPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // UPDOWN_PLUGIN_HPP
