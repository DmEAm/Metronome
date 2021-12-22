#ifndef TAPPER_SETTINGS_HPP
#define TAPPER_SETTINGS_HPP

#include <QQmlEngine>
#include <QtQml>

#include "iconfigurable.hpp"
#include "inertia.hpp"
#include "tapper.hpp"

#include <tapper_plugin_export.h>

class TAPPER_PLUGIN_EXPORT TapperSettingsController : public IConfigurable
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(TapperSettingsController)
    Q_INTERFACES(IConfigurable)

    Q_PROPERTY(int inertia READ inertia WRITE setInertia NOTIFY inertiaChanged)
    Q_PROPERTY(int strongMaxInertia READ strongMaxInertia)
    Q_PROPERTY(int strongMinInertia READ strongMinInertia)

public:
    explicit TapperSettingsController(TapperController *parent = nullptr);
    ~TapperSettingsController() override = default;

    enum KeysId
    {
        INERTIA = 0
    };
    Q_INVOKABLE void init();

    int inertia() const;

    Q_INVOKABLE void setInertia(int inertia);

    Q_DECL_RELAXED_CONSTEXPR int strongMaxInertia() const { return Inertia::Max; }
    Q_DECL_RELAXED_CONSTEXPR int strongMinInertia() const { return Inertia::Min; }

signals:
    void inertiaChanged(int inertia);

private:
    TapperController * _tapper;
};

#endif // TAPPER_SETTINGS_HPP
