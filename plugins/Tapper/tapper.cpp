#include "tapper.hpp"

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

    return tempo / _tempoCache.capacity();
}

void TapperController::tap()
{
    using min = std::chrono::minutes;
    using msec = std::chrono::milliseconds;
    using std::chrono::duration_cast;

    _timeCache.append(QDateTime::currentDateTime().time());

    auto diff = _timeCache.first().msecsTo(_timeCache.last());

    // QTime().msecsTo(QTime(0, 1, 0, 0)) doesnt constexpr
    _tempoCache.append(diff > 0 ? duration_cast<msec>(min(1)).count() / diff : 0);

    _tempoCache.normalizeIndexes();
    _timeCache.normalizeIndexes();
    emit tempoChanged();
}

void TapperController::loadSettings()
{
    setInertia(QSettings().value("Tapper/Inertia", "10").toInt());
}

int TapperController::inertia()
{
    return _tempoCache.capacity();
}

void TapperController::setInertia(int inertia)
{
    _tempoCache.setCapacity(inertia);
}
