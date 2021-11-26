#include "temposettingscontroller.hpp"
#include <QDebug>

TempoSettingsController::TempoSettingsController(QObject *parent)
: IConfigurable(parent),
  _strongMaxTempo(250),
  _strongMinTempo(10),
  _deltaTempo(5)
{

}

void TempoSettingsController::init()
{
    QStringList sett = {"Tempo/Tempo", "Tempo/MaxTempo", "Tempo/MinTempo"};
    QStringList basic = {"120", "230", "20"};
    configure(sett, basic);
}

int TempoSettingsController::tempo() const
{
    return value(TEMPO).toInt();
}

int TempoSettingsController::maxTempo() const
{
    return value(MAXTEMPO).toInt();
}

int TempoSettingsController::minTempo() const
{
    return value(MINTEMPO).toInt();
}

void TempoSettingsController::setTempo(int tempo)
{
    if(tempo < value(MINTEMPO).toInt())
        tempo = value(MINTEMPO).toInt();
    else if(tempo > value(MAXTEMPO).toInt())
        tempo = value(MAXTEMPO).toInt();
    QString stringTempo = QString::number(tempo);
    if(value(TEMPO) != stringTempo)
    {
        valueRef(TEMPO) = stringTempo;
        emit tempoChanged();
    }
}

void TempoSettingsController::setMaxTempo(int maxTempo)
{
    if(maxTempo - value(MINTEMPO).toInt() <= _deltaTempo)
        return;
    QString strMaxTempo = QString::number(maxTempo);
    if(value(MAXTEMPO) != strMaxTempo)
    {
        if(value(TEMPO).toInt() > maxTempo)
            setTempo(maxTempo);
        valueRef(MAXTEMPO) = strMaxTempo;
        emit maxTempoChanged();
    }
}

void TempoSettingsController::setMinTempo(int minTempo)
{
    if(value(MAXTEMPO).toInt() - minTempo <= _deltaTempo)
        return;
    QString strMinTempo = QString::number(minTempo);
    if(value(MINTEMPO) != strMinTempo)
    {
        if(value(TEMPO).toInt() < minTempo)
            setTempo(minTempo);
        valueRef(MINTEMPO) = strMinTempo;
        emit minTempoChanged();
    }
}