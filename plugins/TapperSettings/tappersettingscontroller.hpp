#ifndef TAPPER_SETTINGS_HPP
#define TAPPER_SETTINGS_HPP

#include <QtQml>
#include <QSoundEffect>
#include <QTimer>
#include <QQmlEngine>

#include "iconfigurable.hpp"

class TapperSettingsController :public ICongigurable
{
    Q_OBJECT

    Q_PROPERTY(int inertia READ inertia WRITE setInertia NOTIFY inertiaChanged)

    Q_PROPERTY(int strongMaxInertia READ strongMaxInertia)
    Q_PROPERTY(int strongMinInertia READ strongMinInertia)

public:
    explicit TapperSettingsController(QObject *parent = nullptr);
    ~TapperSettingsController() override = default;

    enum KeysId{
        INERTIA = 0
    };
    Q_INVOKABLE void init();

    int inertia() const;

    Q_INVOKABLE void setInertia(int inertia);

    Q_DECL_RELAXED_CONSTEXPR int strongMaxInertia() const {return _strongMaxInertia;}
    Q_DECL_RELAXED_CONSTEXPR int strongMinInertia() const {return _strongMinInertia;}

signals:
    void inertiaChanged();

private:
    int _strongMaxInertia;
    int _strongMinInertia;

};

#endif // TAPPER_SETTINGS_HPP
