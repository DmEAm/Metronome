#include "pickercontroller.hpp"

PickerController::PickerController(QObject *parent) :
QObject(parent)
, _index(QVariant(0))
{

}

QVariant PickerController::index() const
{
    return _index;
}

void PickerController::setIndex(QVariant index)
{
    if(_index == index)
        return;
    _index = index;
    emit indexChanged();
}

QVariant PickerController::formatText(const QVariant& count, const QVariant& modelData)
{
    Q_UNUSED(count)
    auto data = modelData.value<int>();
    return data;
}
