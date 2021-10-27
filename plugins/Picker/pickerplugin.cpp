#include "pickerplugin.hpp"

void PickerPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<PickerModel>(uri, 1, 0, "PickerModel");
    qmlRegisterType<PickerController>(uri, 1, 0, "PickerController");

    qmlRegisterUncreatableType<Tempo>(uri, 1, 0, "Tempo", "");
}
