#ifndef UPDOWN_HPP
#define UPDOWN_HPP

#include <QObject>
#include <QString>
#include <QTimer>
#include <QContiguousCache>
#include <QQuickItem>

class UpDownController : public QObject
{
    Q_OBJECT

public:
    explicit UpDownController(QObject *parent = nullptr);

    Q_INVOKABLE void pressUp();
    Q_INVOKABLE void releaseUp();
    Q_INVOKABLE void pressDown();
    Q_INVOKABLE void releaseDown();

signals:
    void up();
    void down();

private:
    bool _isMoveUp;
    bool _isMoveDown;
    QTimer *_timer;

    size_t _timeLoopMin;
    size_t _timeLoopDefaulth;
    size_t _timeLoopDecrease;
    size_t _timeLoopCurrent;

    void release();
    void timeOut();
    void decreaseTimeLoop();
};

#endif // UPDOWN_HPP
