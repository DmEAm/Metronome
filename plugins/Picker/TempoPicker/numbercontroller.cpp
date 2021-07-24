#include "numbercontroller.h"

NumberController::NumberController(QObject *parent) :
  PickerController(parent),
  _maxValue(100),
  _minValue(0)
{
    _value = 0;
}


void NumberController::setValue(QVariant value)
{
    if(value.value<int>() > _maxValue)
        _value = _maxValue;
    else if(value.value<int>() < _minValue)
        _value = _minValue;
    else
        _value = value.value<int>();
}

int NumberController::maxValue() const
{
    return _maxValue;
}

int NumberController::minValue() const
{
    return _minValue;
}

void NumberController::setMaxValue(int value)
{
    if(_maxValue == value)
        return;
    _maxValue = value;
    emit maxValueChanged();
}

void NumberController::setMinValue(int value)
{
    if(_minValue == value)
        return;
    _minValue = value;
    emit minValueChanged();
}

