#ifndef TEMPO_CONTROLLER_HPP
#define TEMPO_CONTROLLER_HPP

#include <QTime>

#include "pickercontroller.hpp"
#include "tempo.hpp"

class TempoController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(Tempo * tempo READ tempo CONSTANT FINAL)
    Q_PROPERTY(int interval READ interval)

public:
    explicit TempoController(QObject *parent = nullptr);

    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    Tempo *tempo() const;

    int interval()
    {
        return Tempo::MsecsInMinute / _tempo->current();
    }

private:
    Tempo *_tempo;
};

#endif // TEMPO_CONTROLLER_HPP
