#ifndef MAIN_PLUGIN_HPP
#define MAIN_PLUGIN_HPP

#include <QQmlExtensionPlugin>

#include "mainwindow.hpp"

class MainPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // MAIN_PLUGIN_HPP
