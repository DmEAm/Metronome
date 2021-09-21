#include "tempocontroller.hpp"

TempoController::TempoController(QObject *parent)
    : PickerController(parent)
    , _tempo(new Tempo(this))
{
    _index = 0;
}

void TempoController::setIndex(QVariant index)
{
    _index = index;
    emit indexChanged();
}

QVariant TempoController::formatText(const QVariant &count, const QVariant &modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>();
    return data;
}

Tempo *TempoController::tempo() const
{
    return _tempo;
}