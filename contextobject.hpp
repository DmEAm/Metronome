#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include <global.hpp>
#include <QObject>

#include <Player/player.hpp>
#include <tempocontroller.hpp>

class ContextObject : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(ContextObject)

    Q_PROPERTY(TempoController *tempoController READ tempo CONSTANT FINAL)
    Q_PROPERTY(PlayerController *playerController READ player CONSTANT FINAL)

public:
    ContextObject(QObject *parent = nullptr);
    ~ContextObject() override = default;

    TempoController *tempo() const { return _tempoController; }
    PlayerController *player() const { return _playerController; }

private:
    TempoController *_tempoController;
    PlayerController *_playerController;
};

#endif //CONTEXT_HPP
