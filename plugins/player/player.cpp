#include "player.hpp"

PlayerController::PlayerController(QObject *parent) : QObject(parent)
{
    m_userName = "Ilya";
    qDebug() << m_userName;
}

QString PlayerController::userName()
{
    return m_userName;
}

void PlayerController::setUserName(const QString &userName)
{
    qDebug() << userName;
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
