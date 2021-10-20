#include"updownplugin.hpp"
#include "updowncontroller.hpp"

void UpDownPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<UpDownController>(uri, 1, 0, "UpDownController");
}
