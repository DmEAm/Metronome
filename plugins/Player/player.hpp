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
    Q_PROPERTY(size_t tempo READ tempo WRITE setTempo)
    Q_PROPERTY(int interval READ interval)

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    size_t tempo() const;
    void setTempo(size_t tempo);
    int interval();

    Q_INVOKABLE void toggle();

signals:
    void toggled();
    void changedTempo();

private:
    bool _playing;
    size_t _tempo;
    size_t _tempoLimit;
    QTimer *_timer;
    Mixer *_mixer;

    void changeState();
};

#endif // MAIN_HPP
