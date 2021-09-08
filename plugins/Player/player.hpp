#ifndef MAIN_HPP
#define MAIN_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>

#include "mixer.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playing READ playing NOTIFY toggled)
    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY changedTempo)
    Q_PROPERTY(int accent READ accent WRITE setAccent NOTIFY changedAccent)
    Q_PROPERTY(int tempoMax READ tempoMax NOTIFY changedTempoMax)
    Q_PROPERTY(int tempoMin READ tempoMin NOTIFY changedTempoMin)
    Q_PROPERTY(int range READ range NOTIFY changedRange)
    Q_PROPERTY(int interval READ interval)

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    int tempo() const;
    int accent() const;
    int range() const;
    int interval();
    int tempoMax() const;
    int tempoMin() const;
    void setTempo(int tempo);
    void setAccent(int accent);

    Q_INVOKABLE void toggle();
    Q_INVOKABLE void loadSettings();

signals:
    void toggled();
    void changedTempo();
    void changedAccent();
    void changedTempoMax();
    void changedTempoMin();
    void changedRange();

private:
    bool _playing;
    int _tempo;
    int _accent;
    int _tempoMax;
    int _tempoMin;
    QTimer *_timer;
    Mixer *_mixer;

    void changeState();
    void changeAccent();
};

#endif // MAIN_HPP
