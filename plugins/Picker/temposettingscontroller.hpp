#ifndef TEMPO_SETTINGS_HPP
#define TEMPO_SETTINGS_HPP

#include <QtQml>
#include <QTimer>
#include <QQmlEngine>

#include <iconfigurable.hpp>

#include <picker_plugin_export.h>

#include "tempocontroller.hpp"

class PICKER_PLUGIN_EXPORT TempoSettingsController : public IConfigurable
{
    Q_OBJECT
    Q_INTERFACES(IConfigurable)
    Q_DISABLE_COPY_MOVE(TempoSettingsController)

    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY tempoChanged)

    Q_PROPERTY(int strongMaxTempo READ strongMaxTempo)
    Q_PROPERTY(int strongMinTempo READ strongMinTempo)

public:
    explicit TempoSettingsController(TempoController *parent = nullptr);
    ~TempoSettingsController() override = default;

    enum KeysId{
        TEMPO = 0
    };
    Q_INVOKABLE void init();

    int tempo() const;

    Q_REQUIRED_RESULT int strongMaxTempo() const {return _tempoController->tempo()->Max;}
    Q_REQUIRED_RESULT int strongMinTempo() const {return _tempoController->tempo()->Min;}

    Q_INVOKABLE void setTempo(int tempo);

signals:
    void tempoChanged(int tempo);

private:
    int _deltaTempo;
    TempoController *_tempoController;
};

#endif // TEMPO_SETTINGS_HPP
