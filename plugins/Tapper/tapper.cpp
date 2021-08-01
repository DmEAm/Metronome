#include "tapper.hpp"
#include <QDebug>

TapperController::TapperController(QObject *parent)
: QObject(parent)
, _timeCache(2)
, _tempoCache(10) { }

int TapperController::tempo() const
{
    int tempo = 0;

    for (int i = _tempoCache.firstIndex(); i <= _tempoCache.lastIndex(); i++)
        tempo += _tempoCache.at(i);

    return tempo / _tempoCache.size();
}

void TapperController::tap()
{
    _timeCache.append(QDateTime::currentDateTime().time());

    auto diff = _timeCache.first().msecsTo(_timeCache.last());

    _tempoCache.append(diff > 0 ? 1000L * 60 / diff : 0);

    _tempoCache.normalizeIndexes();
    _timeCache.normalizeIndexes();
    emit tempoChanged();
}
