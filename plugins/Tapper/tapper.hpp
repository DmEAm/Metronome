#ifndef TAPPER_HPP
#define TAPPER_HPP

#include <QContiguousCache>
#include <QObject>
#include <QQuickItem>
#include <QString>
#include <QSettings>
#include <QTime>

#include <chrono>

class TapperController : public QObject
{
    Q_OBJECT
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
    void tempoChanged();

private:
    QContiguousCache<QTime> _timeCache;
    QContiguousCache<qint64> _tempoCache;
};

#endif // TAPPER_HPP
