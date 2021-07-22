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

public slots:
    void click();
    void stop();

private:
    QVector<QSoundEffect*> _effects;
    int currentEffect;

    void upPosition();
    void resetPosition();
};

#endif // MIXER_H
