#ifndef TEMPO_CONTROLLER_HPP
#define TEMPO_CONTROLLER_HPP

#include <QTime>

#include "pickercontroller.hpp"
#include "tempo.hpp"

class TempoController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(Tempo tempo READ tempo)
    Q_PROPERTY(int interval READ interval)

public:
    explicit TempoController(QObject *parent = nullptr);

    void setIndex(QVariant index) override;
    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    const Tempo *tempo() const;

    int interval()
    {
        return QTime(0, 1, 0, 0).second() / _tempo->current();
    }

private:
    Tempo *_tempo;
};

#endif // TEMPO_CONTROLLER_HPP
