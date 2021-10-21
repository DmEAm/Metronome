#include "updowncontroller.hpp"

UpDownController::UpDownController(QObject *parent)
: QObject(parent),
  _isMoveUp(false),
  _isMoveDown(false),
  _timer(new QTimer(this)),
  _timeLoopMin(80),
  _timeLoopDefaulth(350),
  _timeLoopDecrease(40),
  _timeLoopCurrent(_timeLoopDefaulth)
{
    _timer->setTimerType(Qt::PreciseTimer);
    connect(_timer, &QTimer::timeout, this, &UpDownController::timeOut);
}

void UpDownController::pressUp()
{
    releaseDown();
    _isMoveUp = true;
    _timer->start(_timeLoopCurrent);
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
    _timer->start(_timeLoopCurrent);
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
    _timeLoopCurrent = _timeLoopDefaulth;;
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
    if(_timeLoopCurrent > _timeLoopMin)
    {
        if (_timeLoopCurrent - _timeLoopDecrease < _timeLoopMin)
            _timeLoopCurrent = _timeLoopMin;
        else
            _timeLoopCurrent -= _timeLoopDecrease;
        _timer->start(_timeLoopCurrent);
    }
}


