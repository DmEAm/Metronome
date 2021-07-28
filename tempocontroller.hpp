#ifndef TEMPOCONTROLLER_H
#define TEMPOCONTROLLER_H

#include "pickercontroller.hpp"

class TempoController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(int maxTempo READ maxTempo WRITE setMaxTempo NOTIFY maxTempoChanged)
    Q_PROPERTY(int minTempo READ minTempo WRITE setMinTempo NOTIFY minTempoChanged)
    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY tempoChanged)

public:
    explicit TempoController(QObject *parent = nullptr);

    void setIndex(QVariant index) override;
    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    Q_REQUIRED_RESULT int maxTempo() const;
    Q_REQUIRED_RESULT int minTempo() const;
    void setMaxTempo(int value);
    void setMinTempo(int value);

    Q_REQUIRED_RESULT int tempo() const;
    void setTempo(int tempo);

private:
    int _maxTempo;
    int _minTempo;

signals:
    void maxTempoChanged();
    void minTempoChanged();
    void tempoChanged();

};

#endif // TEMPOCONTROLLER_H
