#include "tappersettingscontroller.hpp"

TapperSettingsController::TapperSettingsController(QObject *parent)
    : IConfigurable(parent)
{}

void TapperSettingsController::init()
{
    QStringList sett = { "Tapper/Inertia" };
    QStringList basic = { "10" };
    configure(sett, basic);
}

int TapperSettingsController::inertia() const
{
    return value(INERTIA).toInt();
}

void TapperSettingsController::setInertia(int inertia)
{
    if (inertia > Inertia::Max || inertia < Inertia::Min)
    {
        return;
    }

//    QString stringInertia = QString::number(inertia);
//    if (value(INERTIA) != stringInertia)
//    {
//        valueRef(INERTIA) = stringInertia;
//        emit inertiaChanged();
//    }
}
