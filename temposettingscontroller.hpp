#ifndef TEMPO_SETTINGS_HPP
#define TEMPO_SETTINGS_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>
#include <QQmlEngine>

#include "core/iconfigurable.hpp"

class TempoSettingsController :public ICongigurable
{
    Q_OBJECT

    Q_PROPERTY(int tempo READ tempo WRITE setTempo NOTIFY tempoChanged)
    Q_PROPERTY(int maxTempo READ maxTempo WRITE setMaxTempo NOTIFY maxTempoChanged)
    Q_PROPERTY(int minTempo READ minTempo WRITE setMinTempo NOTIFY minTempoChanged)

    Q_PROPERTY(int strongMaxTempo READ strongMaxTempo)
    Q_PROPERTY(int strongMinTempo READ strongMinTempo)

public:
    explicit TempoSettingsController(QObject *parent = nullptr);
    ~TempoSettingsController() override = default;

    enum KeysId{
        TEMPO = 0, MAXTEMPO = 1, MINTEMPO = 2
    };
    Q_INVOKABLE void init();

    int tempo() const;
    int maxTempo() const;
    int minTempo() const;

    Q_DECL_RELAXED_CONSTEXPR int strongMaxTempo() const {return _strongMaxTempo;}
    Q_DECL_RELAXED_CONSTEXPR int strongMinTempo() const {return _strongMinTempo;}

    Q_INVOKABLE void setTempo(int tempo);
    Q_INVOKABLE void setMaxTempo(int maxTempo);
    Q_INVOKABLE void setMinTempo(int minTempo);

signals:
    void tempoChanged();
    void maxTempoChanged();
    void minTempoChanged();

private:
    int _strongMaxTempo;
    int _strongMinTempo;
    int _deltaTempo;
};

#endif // TEMPO_SETTINGS_HPP
