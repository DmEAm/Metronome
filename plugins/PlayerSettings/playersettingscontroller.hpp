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

public:
    explicit PlayerSettingsController(QObject *parent = nullptr);
    ~PlayerSettingsController() override = default;
    enum {
        VOLUME
    };

signals:

private:

};

#endif // PLAYER_SETTINGS_HPP
