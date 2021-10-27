#ifndef PLAYER_SETTINGS_HPP
#define PLAYER_SETTINGS_HPP

#include <QtQml>
#include <QQmlEngine>

#include "iconfigurable.hpp"

class PlayerSettingsController : public IConfigurable
{
    Q_OBJECT
    Q_INTERFACES(IConfigurable)
    Q_DISABLE_COPY_AND_MOVE(PlayerSettingsController)

    Q_PROPERTY(int volume READ volume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(int idBaseSound READ idBaseSound WRITE setIdBaseSound NOTIFY idBaseSoundChanged)
    Q_PROPERTY(int idAccentSound READ idAccentSound WRITE setIdAccentSound NOTIFY idAccentSoundChanged)

public:
    explicit PlayerSettingsController(QObject *parent = nullptr);
    ~PlayerSettingsController() override = default;

    enum KeysId{
        VOLUME = 0, BASESOUND = 1, ACCENTSOUND = 2
    };
    Q_INVOKABLE void init();

    int volume() const;
    Q_INVOKABLE QString getStrVolume() const;
    int idBaseSound() const;
    Q_INVOKABLE QString getStrBaseSound() const;
    int idAccentSound() const;
    Q_INVOKABLE QString getStrAccentSound() const;

    Q_INVOKABLE void setVolume(int volume);
    Q_INVOKABLE void setIdBaseSound(int idBaseSound);
    Q_INVOKABLE void setIdAccentSound(int idAccentSound);

signals:
    void volumeChanged();
    void idBaseSoundChanged();
    void idAccentSoundChanged();

private:
    QVector<QString> baseSound;
    QVector<QString> accentSound;

};

#endif // PLAYER_SETTINGS_HPP
