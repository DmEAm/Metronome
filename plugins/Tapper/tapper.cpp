#include "tapper.hpp"
#include <QDebug>

TapperController::TapperController(QObject *parent)
    : QObject(parent)
    , _timeCache(2)
    , _tempoCache(Inertia)
{
   loadSettings();
}

int TapperController::tempo() const
{
    int tempo = 0;

    for (int i = _tempoCache.firstIndex(); i <= _tempoCache.lastIndex(); i++)
    {
        tempo += static_cast<int>(_tempoCache.at(i));
    }

    return tempo / _tempoCache.size();
}

void TapperController::tap()
{
    _timeCache.append(QDateTime::currentDateTime().time());

    auto diff = _timeCache.first().msecsTo(_timeCache.last());

    _tempoCache.append(diff > 0 ? QTime(0, 1, 0, 0).second() / diff : 0);

    _tempoCache.normalizeIndexes();
    _timeCache.normalizeIndexes();
    emit tempoChanged();
}

void TapperController::loadSettings()
{
    setInertia(QSettings().value( "Tapper/Inertia", "10" ).toInt());
}

int TapperController::inertia()
{
    return _tempoCache.capacity();
}

void TapperController::setInertia(int inertia)
{
    _tempoCache.setCapacity(inertia);
}
