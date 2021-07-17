#include "mainwindow.hpp"

MainController::MainController(QObject *parent) : QObject(parent)
{
    m_userName = "Ilya";
    qDebug() << m_userName;
}

QString MainController::userName()
{
    return m_userName;
}

void MainController::setUserName(const QString &userName)
{
    qDebug() << userName;
    if (userName == m_userName)
        return;

    m_userName = userName;
    emit userNameChanged();
}
