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
    Q_PROPERTY(int tempoMax READ tempoMax NOTIFY changedTempoMax)
    Q_PROPERTY(int tempoMin READ tempoMin NOTIFY changedTempoMin)
    Q_PROPERTY(int range READ range NOTIFY changedRange)
    Q_PROPERTY(int interval READ interval)

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    int tempo() const;
    void setTempo(int tempo);
    int tempoMax() const;
    int tempoMin() const;
    int range() const;
    int interval();

    Q_INVOKABLE void toggle();

signals:
    void toggled();
    void changedTempo();
    void changedTempoMax();
    void changedTempoMin();
    void changedRange();

private:
    bool _playing;
    int _tempo;
    int _tempoMax;
    int _tempoMin;
    QTimer *_timer;
    Mixer *_mixer;

    void changeState();
};

#endif // MAIN_HPP
