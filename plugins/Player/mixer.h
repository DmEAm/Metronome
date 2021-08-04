#ifndef MIXER_H
#define MIXER_H

#include <QObject>
#include <QSoundEffect>

class Mixer : public QObject
{
    Q_OBJECT

public:
    explicit Mixer(QObject *parent = nullptr);
    ~Mixer() override = default;

    void setStandartMode();
    void setAccentMode(int accent);

public slots:
    void click();
    void stop();

private:
    QVector<QSoundEffect*> _effects;
    int currentEffect;

    QSoundEffect * standartEffect();
    QSoundEffect * accentEffect();
    void upPosition();
    void resetPosition();
};

#endif // MIXER_H
