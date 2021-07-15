#include "mainplugin.hpp"

void MainPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<MainController>(uri, 1, 0, "MainController");
}
