#ifndef MAIN_HPP
#define MAIN_HPP

#include <QSoundEffect>
#include <QTimer>
#include <QtQml>

#include "mixer.hpp"
#include "tempocontroller.hpp"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(PlayerController)

    Q_PROPERTY(bool playing READ playing NOTIFY toggled)
    Q_PROPERTY(int accent READ accent WRITE setAccent NOTIFY changedAccent)

public:
    explicit PlayerController(TempoController *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    int accent() const;
    void setAccent(int accent);

    Q_INVOKABLE void toggle();
    Q_INVOKABLE void loadSettings();
    Q_INVOKABLE void setVolume(QString volume);
    Q_INVOKABLE void setBaseSound(QString baseSound);
    Q_INVOKABLE void setAccentSound(QString accentSound);

signals:
    void toggled();
    void changedTempo();
    void changedAccent();
    void changedRange();

private:
    void changeState();
    void changeAccent();

private:
    bool _playing;
    int _accent;
    QTimer *_timer;
    Mixer *_mixer;
    TempoController *_tempoController;
};

#endif // MAIN_HPP
