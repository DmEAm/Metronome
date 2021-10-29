#include "pickerplugin.hpp"

void PickerPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<PickerModel>(uri, 1, 0, "PickerModel");
    qmlRegisterType<PickerController>(uri, 1, 0, "PickerController");

    qmlRegisterType<TempoController>("TempoPicker", 1, 0, "TempoController");
    qmlRegisterType<TempoSettingsController>("TempoPicker", 1, 0, "TempoSettingsController");

    qmlRegisterUncreatableType<Tempo>(uri, 1, 0, "Tempo", "");
}
