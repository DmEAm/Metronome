#include "updowncontroller.hpp"

UpDownController::UpDownController(QObject *parent)
: QObject(parent),
  _isMoveUp(false),
  _isMoveDown(false),
  _timer(new QTimer(this))
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, this, &UpDownController::timeOut);
}

void UpDownController::pressUp()
{
    releaseDown();
    _isMoveUp = true;
    _timer->start(_timeLoop.timeLoopCurrent);
    emit up();
}

void UpDownController::releaseUp()
{
    release();
    _isMoveUp = false;
}

void UpDownController::pressDown()
{
    releaseUp();
    _isMoveDown = true;
    _timer->start(_timeLoop.timeLoopCurrent);
    emit down();
}

void UpDownController::releaseDown()
{
    release();
    _isMoveDown = false;
}

void UpDownController::release()
{
    _timer->stop();
    _timeLoop.timeLoopCurrent = _timeLoop.timeLoopDefaulth;;
}

void UpDownController::timeOut()
{
    if(_isMoveUp)
        emit up();
    else if(_isMoveDown)
        emit down();
    decreaseTimeLoop();
}

void UpDownController::decreaseTimeLoop()
{
    if(_timeLoop.timeLoopCurrent > _timeLoop.timeLoopMin)
    {
        if (_timeLoop.timeLoopCurrent - _timeLoop.timeLoopDecrease < _timeLoop.timeLoopMin)
            _timeLoop.timeLoopCurrent = _timeLoop.timeLoopMin;
        else
            _timeLoop.timeLoopCurrent -= _timeLoop.timeLoopDecrease;
        _timer->start(_timeLoop.timeLoopCurrent);
    }
}


