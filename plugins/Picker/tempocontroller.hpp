#ifndef TEMPO_CONTROLLER_HPP
#define TEMPO_CONTROLLER_HPP

#include <QTime>
#include <QSettings>

#include <global.hpp>

#include "pickercontroller.hpp"
#include "tempo.hpp"

class PICKER_PLUGIN_EXPORT TempoController : public PickerController
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(TempoController)

    Q_PROPERTY(Tempo *tempo READ tempo CONSTANT FINAL)
    Q_PROPERTY(int interval READ interval)

public:
    explicit TempoController(QObject *parent = nullptr);
    ~TempoController();

    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    Tempo *tempo() const;

    Q_INVOKABLE void loadSettings();
    Q_INVOKABLE void loadTempo();
    Q_INVOKABLE void saveTempo();
    void setIndex(QVariant index) override;
    Q_REQUIRED_RESULT QVariant index() const override;

    int interval()
    {
        return Tempo::MsecsInMinute / _tempo->current();
    }

private:
    Tempo *_tempo;
};

#endif // TEMPO_CONTROLLER_HPP
