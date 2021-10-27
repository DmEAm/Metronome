#include "tempocontroller.hpp"

TempoController::TempoController(QObject *parent)
    : PickerController(parent)
    , _tempo(new Tempo(this))
{
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
