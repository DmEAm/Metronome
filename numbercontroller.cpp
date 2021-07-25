#include "numbercontroller.h"
#include <QDebug>

NumberController::NumberController(QObject *parent) :
  PickerController(parent),
  _maxTempo(100),
  _minTempo(0),
  _tempo(-1),
  _shift(20)
{
    _index = 0;
}



void NumberController::setIndex(QVariant index)
{
    if(index.value<int>() == _index)
        return;
    if(index.value<int>() > _maxTempo - _shift)
        _index = _maxTempo - _shift;
    else if(index.value<int>() < _minTempo - _shift)
        _index = _minTempo - _shift;
    else
        _index = index.value<int>();
    _tempo = _index.value<int>() + _shift;
    qDebug() << "id" << _index << " " << _tempo << " " << index;
    emit indexChanged();
}

QVariant NumberController::formatText(const QVariant& count, const QVariant& modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>() + _shift;
    return data;
}

int NumberController::maxTempo() const
{
    return _maxTempo;
}

int NumberController::minTempo() const
{
    return _minTempo;
}

int NumberController::tempo() const
{
    return _tempo;
}

int NumberController::shift() const
{
    return _shift;
}

void NumberController::setMaxTempo(int value)
{
    if(_maxTempo == value)
        return;
    _maxTempo = value;
    emit maxTempoChanged();
}


void NumberController::setMinTempo(int value)
{
    if(_minTempo == value)
        return;
    _minTempo = value;
    emit minTempoChanged();
}

void NumberController::setTempo(int tempo)
{
    if(tempo == _tempo)
        return;
    if(tempo > _maxTempo)
        _tempo = _maxTempo;
    else if(tempo < _minTempo)
        _tempo = _minTempo;
    else
        _tempo = tempo;
    _index = _tempo - _shift;
    qDebug() << "tempo" << _index << " " << _tempo << " " << tempo;
    emit tempoChanged();
}

void NumberController::setShift(int shift)
{
    if(_shift == shift)
        return;
    _shift = shift;
    emit shiftChanged();
}
