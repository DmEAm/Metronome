#include "tempo.hpp"

Tempo::Tempo(QObject *parent)
    : QObject(parent)
    , _current(Default)
{}

#include <QDebug>
void Tempo::setCurrent(int tempo)
{
    if (tempo >= Max)
    {
        _current = Max;
    }
    else if (tempo <= Min)
    {
        _current = Min;
    }
    else
    {
        _current = tempo;
    }

    qDebug() << _current;
    emit currentChanged();
}

int Tempo::current() const
{
    return _current;
}
