#ifndef MAIN_HPP
#define MAIN_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>

#include "mixer.hpp"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool playing READ playing NOTIFY toggled)
    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY changedTempo)
    Q_PROPERTY(int accent READ accent WRITE setAccent NOTIFY changedAccent)
    Q_PROPERTY(int interval READ interval)

public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController() override = default;

    bool playing() const;
    int tempo() const;
    int accent() const;
    int interval();
    void setTempo(int tempo);
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
    bool _playing;
    int _tempo;
    int _accent;
    QTimer *_timer;
    Mixer *_mixer;

    void changeState();
    void changeAccent();
};

#endif // MAIN_HPP
