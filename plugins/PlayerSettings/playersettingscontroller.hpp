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

public:
    explicit PlayerSettingsController(QObject *parent = nullptr);
    ~PlayerSettingsController() override = default;
    enum {
        VOLUME
    };

    int volume() const;

    Q_INVOKABLE void setVolume(int volume);

signals:
    void changedVolume();

};

#endif // PLAYER_SETTINGS_HPP
