#ifndef TAPPER_PLUGIN_HPP
#define TAPPER_PLUGIN_HPP

#include <QQmlExtensionPlugin>
#include <QmlTypeAndRevisionsRegistration>

#include "pickermodel.hpp"
#include "pickercontroller.hpp"

class PickerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // TAPPER_PLUGIN_HPP
