#include "tempocontroller.hpp"
#include <QDebug>

TempoController::TempoController(QObject *parent)
    : PickerController(parent)
    , _tempo(new Tempo(this))
{
    connect(_tempo, &Tempo::currentChanged, this, [=](){emit tempoChanged();});
}

QVariant TempoController::formatText(const QVariant &count, const QVariant &modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>() + _tempo->Min;
    return data;
}

Tempo *TempoController::tempo() const
{
    return _tempo;
}

void TempoController::loadSettings()
{
    loadTempo();
}

void TempoController::loadTempo()
{
    _tempo->setCurrent(QSettings().value("Tempo/Tempo", "120").toInt());
}

void TempoController::saveTempo()
{
    QSettings().setValue("Tempo/Tempo", QString::number(tempo()->current()));
}

void TempoController::setIndex(QVariant index)
{
    _tempo->setIndex(index.value<int>());
    emit indexChanged();
}

QVariant TempoController::index() const
{
    return _tempo->index();
}
