#include "tappersettingscontroller.hpp"
#include <QDebug>

TapperSettingsController::TapperSettingsController(QObject *parent)
    : IConfigurable(parent)
    , _strongMaxInertia(10)
    , _strongMinInertia(2)
{

}

void TapperSettingsController::init()
{
    QStringList sett = {"Tapper/Inertia"};
    QStringList basic = {"10"};
    configure(sett, basic);
}

int TapperSettingsController::inertia() const
{
    return value(INERTIA).toInt();
}

void TapperSettingsController::setInertia(int inertia)
{
    if(inertia > _strongMaxInertia || inertia < _strongMinInertia)
        return;
    QString stringInertia = QString::number(inertia);
    if(value(INERTIA) != stringInertia)
    {
        valueRef(INERTIA) = stringInertia;
        emit inertiaChanged();
    }
}
