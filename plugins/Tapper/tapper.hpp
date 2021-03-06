#ifndef TAPPER_HPP
#define TAPPER_HPP

#include <QContiguousCache>
#include <QObject>
#include <QQuickItem>
#include <QSettings>
#include <QString>
#include <QTime>

#include <tapper_plugin_export.h>

#include <chrono>

class TAPPER_PLUGIN_EXPORT TapperController : public QObject
{
    Q_OBJECT
    Q_DISABLE_COPY_MOVE(TapperController)

    Q_PROPERTY(int tempo READ tempo NOTIFY tempoChanged)
    Q_PROPERTY(int inertia READ inertia WRITE setInertia)

    const int Inertia = 10;

public:
    explicit TapperController(QObject *parent = nullptr);

    Q_REQUIRED_RESULT int tempo() const;
    Q_REQUIRED_RESULT int inertia();
    Q_INVOKABLE void tap();

    Q_INVOKABLE void loadSettings();

    void setInertia(int inertia);

signals:
    void tempoChanged(int tempo);

private:
    QContiguousCache<QTime> _timeCache;
    QContiguousCache<qint64> _tempoCache;
};

#endif // TAPPER_HPP
