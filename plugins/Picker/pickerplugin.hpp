#ifndef TAPPER_PLUGIN_HPP
#define TAPPER_PLUGIN_HPP

#include <QQmlExtensionPlugin>
#include <QmlTypeAndRevisionsRegistration>

class PickerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TAPPER_PLUGIN_HPP
