#include "player.hpp"

PlayerController::PlayerController(QObject *parent) : QObject(parent)
{
    m_isWork = false;
    qDebug() << m_isWork;
}

bool PlayerController::isWork()
{
    return m_isWork;
}

void PlayerController::setWorkState(const bool &workState)
{
    qDebug() << workState;
    if (workState == m_isWork)
        return;

    m_isWork = workState;
    emit workStateChanged();
}

void PlayerController::changeWorkState()
{
    setWorkState(!m_isWork);
}
