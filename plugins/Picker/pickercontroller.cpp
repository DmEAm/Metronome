#include "pickercontroller.hpp"

PickerController::PickerController(QObject *parent) :
QObject(parent)
, _value(QVariant(0))
{

}

QVariant PickerController::value() const
{
    return _value;
}

void PickerController::setValue(QVariant value)
{
    if(_value == value)
        return;
    _value = value;
    emit valueChanged();
}

QVariant PickerController::formatText(const QVariant& count, const QVariant& modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>();
    return data;
}
