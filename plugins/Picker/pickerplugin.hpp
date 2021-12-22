#ifndef PICKER_PLUGIN_HPP
#define PICKER_PLUGIN_HPP

#include <QQmlExtensionPlugin>
#include <QtQml>

#include "tempocontroller.hpp"
#include "temposettingscontroller.hpp"
#include "pickercontroller.hpp"
#include "pickermodel.hpp"
#include "tempo.hpp"

class PickerPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // PICKER_PLUGIN_HPP
