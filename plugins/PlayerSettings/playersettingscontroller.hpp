#ifndef PLAYER_SETTINGS_HPP
#define PLAYER_SETTINGS_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>
#include <QQmlEngine>

#include "iconfigurable.hpp"

class PlayerSettingsController :public ICongigurable
{
    Q_OBJECT
    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY changedVolume)
    Q_PROPERTY(int idBaseSound READ idBaseSound WRITE setIdBaseSound NOTIFY changedIdBaseSound)
    Q_PROPERTY(int idAccentSound READ idAccentSound WRITE setIdAccentSound NOTIFY changedIdAccentSound)

public:
    explicit PlayerSettingsController(QObject *parent = nullptr);
    ~PlayerSettingsController() override = default;

    enum KeysId{
        VOLUME = 0, BASESOUND = 1, ACCENTSOUND = 2
    };

    int volume() const;
    int idBaseSound() const;
    int idAccentSound() const;

    Q_INVOKABLE void setVolume(int volume);
    Q_INVOKABLE void setIdBaseSound(int idBaseSound);
    Q_INVOKABLE void setIdAccentSound(int idAccentSound);

signals:
    void changedVolume();
    void changedIdBaseSound();
    void changedIdAccentSound();

private:
    QVector<QString> baseSound;
    QVector<QString> accentSound;

};

#endif // PLAYER_SETTINGS_HPP
