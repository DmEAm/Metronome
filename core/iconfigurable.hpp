#ifndef ICONFURABLE_H
#define ICONFURABLE_H

#include <QObject>
#include <QSettings>
#include <QtPlugin>

class ICongigurable: public QObject
{
    Q_OBJECT

public:

    explicit ICongigurable(QObject *parent = nullptr);
    ~ICongigurable() override = default;

    void configure(QStringList settings, QStringList basic);
    Q_INVOKABLE void save();

protected:
    QHash<QString, QString> _settings;

};

#endif // ICONFURABLE_H
