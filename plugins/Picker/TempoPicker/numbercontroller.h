#ifndef NUMBERCONTROLLER_H
#define NUMBERCONTROLLER_H

#include "../pickercontroller.hpp"

class NumberController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(int maxValue READ maxValue WRITE setMaxValue NOTIFY maxValueChanged)
    Q_PROPERTY(int minValue READ minValue WRITE setMinValue NOTIFY minValueChanged)

public:
    explicit NumberController(QObject *parent = nullptr);

    void setValue(QVariant value) override;
    Q_REQUIRED_RESULT int maxValue() const;
    Q_REQUIRED_RESULT int minValue() const;
    void setMaxValue(int value);
    void setMinValue(int value);

private:
    int _maxValue;
    int _minValue;

signals:
    void maxValueChanged();
    void minValueChanged();

};

#endif // NUMBERCONTROLLER_H
