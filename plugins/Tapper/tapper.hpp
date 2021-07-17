#ifndef TAPPER_HPP
#define TAPPER_HPP

#include <QObject>
#include <QString>
#include <QTime>
#include <QContiguousCache>
#include <QQuickItem>

class TapperController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(qint64 tempo READ tempo NOTIFY tempoChanged)

public:
    explicit TapperController(QObject *parent = nullptr);

    Q_REQUIRED_RESULT qint64 tempo() const;
    Q_INVOKABLE void tap();

signals:
    void tempoChanged();

private:
    QContiguousCache<QTime> _timeCache;
    QContiguousCache<qint64> _tempoCache;
};

#endif // TAPPER_HPP
