#include "temposettingscontroller.hpp"
#include <QDebug>

TempoSettingsController::TempoSettingsController(TempoController *parent)
: IConfigurable(parent),
  _deltaTempo(5),
  _tempoController(parent)
{
    init();
    connect(this, &TempoSettingsController::tempoChanged, _tempoController->tempo(), &Tempo::setCurrent);
}

void TempoSettingsController::init()
{
    QStringList sett = {"Tempo/Tempo"};
    QStringList basic = {"120"};
    configure(sett, basic);
}

int TempoSettingsController::tempo() const
{
    return value(TEMPO).toInt();
}

void TempoSettingsController::setTempo(int tempo)
{
    if(!isConfigure)
        return;

    if(tempo < strongMinTempo())
        tempo = strongMinTempo();
    else if(tempo > strongMaxTempo())
        tempo = strongMaxTempo();
    valueRef(TEMPO) = QString::number(tempo);
    emit tempoChanged(this->tempo());
}
