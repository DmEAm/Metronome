#ifndef UPDOWN_HPP
#define UPDOWN_HPP

#include <QObject>
#include <QString>
#include <QTimer>
#include <QContiguousCache>
#include <QQuickItem>

struct TimeLoop{
    size_t timeLoopMin = 80;
    size_t timeLoopDefaulth = 350;
    size_t timeLoopDecrease = 40;
    size_t timeLoopCurrent = timeLoopDefaulth;
};

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

    TimeLoop _timeLoop;

    void release();
    void timeOut();
    void decreaseTimeLoop();
};

#endif // UPDOWN_HPP
