#ifndef MAIN_HPP
#define MAIN_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>

#include "soundstruct.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playing READ playing NOTIFY toggled)
    Q_PROPERTY(bool tempo READ tempo WRITE setTempo)

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    bool tempo() const;
    void setTempo(size_t tempo);

    Q_INVOKABLE void toggle();

signals:
    void toggled();
    void changedTempo();

private:
    bool _playing;
    int _tempoLimit;
    QTimer *_timer;
    SoundStruct *_soundStruct;

    void changeState();
};

#endif // MAIN_HPP
