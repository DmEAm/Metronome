#include "pickercontroller.hpp"
#include <QDebug>

PickerController::PickerController(QObject *parent) :
QObject(parent)
, _value(QVariant(0))
{

}

QVariant PickerController::value() const
{
    return _value;
}


QVariant PickerController::formatText(const QVariant& count, const QVariant& modelData)
{
    auto data = modelData.value<int>();
    return data;
}
