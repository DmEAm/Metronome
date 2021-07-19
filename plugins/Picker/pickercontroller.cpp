#include "pickercontroller.hpp"

PickerController::PickerController(QObject *parent) : QObject(parent)
{

}

QVariant PickerController::value() const
{
    return QVariant(0);
}

QVariant PickerController::formatText(const QVariant& count, const QVariant& modelData)
{
    auto data = count == 12 ? modelData.value<int>() + 1 : modelData;
    return data.toString().length() < 2 ? "0" + data.toString() : data;
}
