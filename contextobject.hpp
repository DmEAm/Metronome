#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <global.hpp>
#include <QObject>

#include <Player/player.hpp>
#include <tempocontroller.hpp>
#include <temposettingscontroller.hpp>
#include <tapper.hpp>
#include <tappersettingscontroller.hpp>

class ContextObject : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(ContextObject)

    Q_PROPERTY(TempoController *tempoController READ tempo CONSTANT FINAL)
    Q_PROPERTY(PlayerController *playerController READ player CONSTANT FINAL)
    Q_PROPERTY(TempoSettingsController *tempoSettingsController READ tempoSettings CONSTANT FINAL)
    Q_PROPERTY(TapperController *tapperController READ tapper CONSTANT FINAL)
    Q_PROPERTY(TapperSettingsController *tapperSettingsController READ tapperSettings CONSTANT FINAL)

public:
    ContextObject(QObject *parent = nullptr);
    ~ContextObject() override = default;

    TempoController *tempo() const { return _tempoController; }
    PlayerController *player() const { return _playerController; }
    TempoSettingsController *tempoSettings() const { return _tempoSettingsController; }
    TapperController *tapper() const { return _tapperController; }
    TapperSettingsController *tapperSettings() const { return _tapperSettingsController; }

private:
    TempoController *_tempoController;
    PlayerController *_playerController;
    TempoSettingsController *_tempoSettingsController;
    TapperController *_tapperController;
    TapperSettingsController *_tapperSettingsController;

    void initConnections();
};

#endif //CONTEXT_HPP
