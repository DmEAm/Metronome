#ifndef MAIN_HPP
#define MAIN_HPP

#include <QObject>
#include <QString>
#include <QQuickItem>

class MainController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit MainController(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // MAIN_HPP
