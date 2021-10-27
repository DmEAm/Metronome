#include "iconfigurable.hpp"

IConfigurable::IConfigurable(QObject *parent)
    : QObject(parent)
{

}

IConfigurable::~IConfigurable()
{
    save();
}

void IConfigurable::save()
{
    foreach(auto key, _settings.keys())
        QSettings().setValue( key, _settings[key] );
}

void IConfigurable::configure(QStringList settings, QStringList basic)
{
    _settings.clear();
    _keys = settings;
    for(int i = 0; i < settings.size(); i++)
        _settings[settings[i]] = QSettings().value( settings[i], basic[i] ).toString();
}
