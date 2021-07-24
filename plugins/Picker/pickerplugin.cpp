#include "pickerplugin.hpp"

void PickerPlugin::registerTypes(const char *uri)
{
    qmlRegisterModule(uri, 1, 0);
    qmlRegisterType<PickerModel>(uri, 1, 0, "PickerModel");
    qmlRegisterType<PickerController>(uri, 1, 0, "PickerController");
    //qmlRegisterType<NumberController>(uri, 1, 0, "NumberController");
}
