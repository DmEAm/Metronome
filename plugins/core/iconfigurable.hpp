#ifndef ICONFURABLE_H
#define ICONFURABLE_H

#include <QObject>
#include <QSettings>
#include <QtPlugin>

class ICongigurable: public QObject
{

public:

    explicit ICongigurable(QObject *parent = nullptr);
    ~ICongigurable();

    void configure(QStringList settings, QStringList basic);
    Q_INVOKABLE void save();
    Q_INVOKABLE QList<QString> keys() const {return _keys;}
    Q_INVOKABLE QString key(int id)   const {return _keys[id];}
    Q_INVOKABLE QString& valueRef(int idKey)   {return _settings[key(idKey)];}
    Q_INVOKABLE QString value(int idKey) const  {return _settings[key(idKey)];}

protected:
    QHash<QString, QString> _settings;
    QList<QString> _keys;
    bool isConfigure;

};

#define ICongigurable_iid "com.acme.ICongigurable"

Q_DECLARE_INTERFACE(ICongigurable, ICongigurable_iid)

#endif // ICONFURABLE_H
