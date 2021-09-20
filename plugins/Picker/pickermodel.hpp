#ifndef PICKER_MODEL_H
#define PICKER_MODEL_H

#include <QAbstractListModel>

class PickerModel : public QAbstractListModel
{
    Q_OBJECT
    constexpr static int RowCount = 10;

public:
    explicit PickerModel(QObject *parent = nullptr);

    QHash<int, QByteArray> roleNames() const override;

    int rowCount(const QModelIndex &parent) const override;

    QVariant data(const QModelIndex &index, int role) const override;

private:
};

#endif // PICKER_MODEL_H
