#ifndef TAPPER_HPP
#define TAPPER_HPP

#include <QObject>
#include <QString>
#include <QQuickItem>

class TapperController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString userName READ userName WRITE setUserName NOTIFY userNameChanged)

public:
    explicit TapperController(QObject *parent = nullptr);

    QString userName();
    void setUserName(const QString &userName);

signals:
    void userNameChanged();

private:
    QString m_userName;
};

#endif // TAPPER_HPP
