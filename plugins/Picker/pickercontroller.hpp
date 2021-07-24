#ifndef PICKER_CONTROLLER_H
#define PICKER_CONTROLLER_H

#include <QObject>
#include <QVariant>

class PickerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVariant value READ value WRITE setValue NOTIFY valueChanged)

public:
    explicit PickerController(QObject *parent = nullptr);

    Q_REQUIRED_RESULT QVariant value() const;
    virtual void setValue(QVariant value);
    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData);

protected:
    QVariant _value;

signals:
    void valueChanged();

};

#endif // PICKER_CONTROLLER_H
