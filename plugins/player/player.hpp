#ifndef MAIN_HPP
#define MAIN_HPP

#include <QObject>
#include <QString>
#include <QQuickItem>

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isWork READ isWork WRITE setWorkState NOTIFY workStateChanged)

public:
    explicit PlayerController(QObject *parent = nullptr);

    bool isWork();
    void setWorkState(const bool &workState);
    Q_INVOKABLE void changeWorkState();

signals:
    void workStateChanged();

private:
    bool m_isWork;
};

#endif // MAIN_HPP
