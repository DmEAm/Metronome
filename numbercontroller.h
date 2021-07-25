#ifndef NUMBERCONTROLLER_H
#define NUMBERCONTROLLER_H

#include "plugins/Picker/pickercontroller.hpp"

class NumberController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(int maxTempo READ maxTempo WRITE setMaxTempo NOTIFY maxTempoChanged)
    Q_PROPERTY(int minTempo READ minTempo WRITE setMinTempo NOTIFY minTempoChanged)
    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY tempoChanged)
    Q_PROPERTY(int shift READ shift WRITE setShift NOTIFY shiftChanged)

public:
    explicit NumberController(QObject *parent = nullptr);

    void setIndex(QVariant index) override;
    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    Q_REQUIRED_RESULT int maxTempo() const;
    Q_REQUIRED_RESULT int minTempo() const;
    void setMaxTempo(int value);
    void setMinTempo(int value);

    Q_REQUIRED_RESULT int tempo() const;
    void setTempo(int tempo);

    Q_REQUIRED_RESULT int shift() const;
    void setShift(int shift);

private:
    int _maxTempo;
    int _minTempo;
    int _tempo;
    int _shift;

signals:
    void maxTempoChanged();
    void minTempoChanged();
    void tempoChanged();
    void shiftChanged();

};

#endif // NUMBERCONTROLLER_H
