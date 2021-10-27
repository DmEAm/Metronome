#ifndef I_CONFIGURABLE_HPP
#define I_CONFIGURABLE_HPP

#include "global.hpp"
#include <QObject>
#include <QSettings>

class IConfigurable : public QObject
{
    Q_DISABLE_COPY_AND_MOVE(IConfigurable);
public:

    explicit IConfigurable(QObject *parent = nullptr);
    ~IConfigurable() override;

    void configure(QStringList settings, QStringList basic);
    Q_INVOKABLE void save();
    Q_INVOKABLE QList<QString> keys() const { return _keys; }
    Q_INVOKABLE QString key(int id) const { return _keys[id]; }
    Q_INVOKABLE QString& valueRef(int idKey) { return _settings[key(idKey)]; }
    Q_INVOKABLE QString value(int idKey) const { return _settings[key(idKey)]; }

private:
    QHash<QString, QString> _settings;
    QList<QString> _keys;
};

#define IConfigurable_iid "com.acme.IConfigurable"

Q_DECLARE_INTERFACE(IConfigurable, IConfigurable_iid)

#endif // I_CONFIGURABLE_HPP
