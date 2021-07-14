#include "tapper.hpp"

TapperController::TapperController(QObject *parent) : QObject(parent)
{

}

QString TapperController::userName()
{
    return m_userName;
}

void TapperController::setUserName(const QString &userName)
{
    qDebug() << userName;
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
