#ifndef TEMPO_CONTROLLER_HPP
#define TEMPO_CONTROLLER_HPP

#include <QSettings>

#include <Picker/pickercontroller.hpp>

class TempoController : public PickerController
{
    Q_OBJECT
    Q_PROPERTY(int maxTempo READ maxTempo WRITE setMaxTempo NOTIFY maxTempoChanged)
    Q_PROPERTY(int minTempo READ minTempo WRITE setMinTempo NOTIFY minTempoChanged)
    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY tempoChanged)
    Q_PROPERTY(int range READ range NOTIFY rangeChanged)

public:
    explicit TempoController(QObject *parent = nullptr);
    ~TempoController();
    void setIndex(QVariant index) override;
    Q_INVOKABLE QVariant formatText(const QVariant &count, const QVariant &modelData) override;

    Q_REQUIRED_RESULT int maxTempo() const;
    Q_REQUIRED_RESULT int minTempo() const;
    void setMaxTempo(int value);
    void setMinTempo(int value);

    Q_REQUIRED_RESULT int tempo() const;
    void setTempo(int tempo);

    Q_REQUIRED_RESULT int range() const;
    Q_INVOKABLE void loadSettings();
    Q_INVOKABLE void loadTempo();
    Q_INVOKABLE void saveTempo();

private:
    int _maxTempo;
    int _minTempo;

signals:
    void maxTempoChanged();
    void minTempoChanged();
    void tempoChanged();
    void rangeChanged();
};

#endif // TEMPO_CONTROLLER_HPP
