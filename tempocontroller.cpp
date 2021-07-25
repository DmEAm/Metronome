#include "tempocontroller.h"

TempoController::TempoController(QObject *parent) :
  PickerController(parent),
  _maxTempo(100),
  _minTempo(0)
{
    _index = 0;
}



void TempoController::setIndex(QVariant index)
{
    if(index.value<int>() == _index)
        return;
    if(index.value<int>() > _maxTempo - _minTempo)
        _index = _maxTempo - _minTempo;
    else if(index.value<int>() < 0)
        _index = 0;
    else
        _index = index;
    emit indexChanged();
}

QVariant TempoController::formatText(const QVariant& count, const QVariant& modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>() + _minTempo;
    return data;
}

int TempoController::maxTempo() const
{
    return _maxTempo;
}

int TempoController::minTempo() const
{
    return _minTempo;
}

int TempoController::tempo() const
{
    return _index.value<int>() + _minTempo;
}

void TempoController::setMaxTempo(int value)
{
    if(_maxTempo == value)
        return;
    _maxTempo = value;
    emit maxTempoChanged();
}


void TempoController::setMinTempo(int value)
{
    if(_minTempo == value)
        return;
    _minTempo = value;
    emit minTempoChanged();
}

void TempoController::setTempo(int tempo)
{
    if(tempo == this->tempo())
        return;
    if(tempo > _maxTempo)
        _index = _maxTempo - _minTempo;
    else if(tempo < _minTempo)
        _index = 0;
    else
        _index = tempo - _minTempo;
    emit tempoChanged();
}
