#include "pickermodel.hpp"

PickerModel::PickerModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

QHash<int, QByteArray> PickerModel::roleNames() const
{
  return { {Qt::UserRole, "value"} };
}

int PickerModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 10;
}

QVariant PickerModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    QVector<int> data(10);
    std::iota(data.begin(), data.end(), 1000);

    return QVariant::fromValue(data.at(index.row()));
}
