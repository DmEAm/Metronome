#ifndef MIXER_HPP
#define MIXER_HPP

#include <QObject>
#include <QSettings>
#include <QSoundEffect>

class Mixer : public QObject
{
    Q_OBJECT

public:
    explicit Mixer(QObject *parent = nullptr);
    ~Mixer() override = default;

    void setStandardMode();
    void setAccentMode(int accent);
    void loadSettingsVolume();
    void loadSettingsBaseSound();
    void loadSettingsAccentSound();

    void setVolume(QString volume);
    void setBaseSound(QString baseSound);
    void setAccentSound(QString accentSound);

public slots:
    void click();
    void stop();

private:
    QVector<QSoundEffect *> _effects;
    QSoundEffect *_stdEffect;
    QSoundEffect *_accEffect;
    int _currentEffect;

    void initStandardEffect();
    void initAccentEffect();
    void upPosition();
    void resetPosition();
};

#endif // MIXER_HPP
