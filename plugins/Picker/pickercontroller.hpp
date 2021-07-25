#ifndef PICKER_CONTROLLER_H
#define PICKER_CONTROLLER_H

#include <QObject>
#include <QVariant>

class PickerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant index READ index WRITE setIndex NOTIFY indexChanged)

public:
    explicit PickerController(QObject *parent = nullptr);

    Q_REQUIRED_RESULT QVariant index() const;
    virtual void setIndex(QVariant index);
    virtual Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData);

protected:
    QVariant _index;

signals:
    void indexChanged();

};

#endif // PICKER_CONTROLLER_H
