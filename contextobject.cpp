#include "contextobject.hpp"

ContextObject::ContextObject(QObject *parent)
    : QObject(parent)
    , _tempoController(new TempoController(this))
    , _playerController(new PlayerController(_tempoController))
{
    QQmlApplicationEngine::setObjectOwnership(_tempoController, QQmlEngine::CppOwnership);
    QQmlApplicationEngine::setObjectOwnership(_playerController, QQmlEngine::CppOwnership);

}
