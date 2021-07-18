#include "pickerplugin.hpp"

void PickerPlugin::registerTypes(const char *uri)
{
    qmlRegisterModule(uri, 1, 0);
}
