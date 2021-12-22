#include "contextobject.hpp"
#include <QDebug>

ContextObject::ContextObject(QObject *parent)
    : QObject(parent)
    , _tempoController(new TempoController(this))
    , _playerController(new PlayerController(_tempoController))
    , _tempoSettingsController(new TempoSettingsController(_tempoController))
    , _tapperController(new TapperController(this))
    , _tapperSettingsController(new TapperSettingsController(_tapperController))
{
    QQmlApplicationEngine::setObjectOwnership(_tempoController, QQmlEngine::CppOwnership);
    QQmlApplicationEngine::setObjectOwnership(_playerController, QQmlEngine::CppOwnership);
    QQmlApplicationEngine::setObjectOwnership(_tempoSettingsController, QQmlEngine::CppOwnership);
    QQmlApplicationEngine::setObjectOwnership(_tapperController, QQmlEngine::CppOwnership);
    QQmlApplicationEngine::setObjectOwnership(_tapperSettingsController, QQmlEngine::CppOwnership);

    initConnections();
}

void ContextObject::initConnections()
{
    connect(_tapperController, &TapperController::tempoChanged, _tempoController->tempo(), &Tempo::setCurrent);
}
