#include "tempo.hpp"
#include <QDebug>

Tempo::Tempo(QObject *parent)
    : QObject(parent)
    , _current(Default)
{}

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
    emit currentChanged();
}

int Tempo::index() const
{
    return current() - Min;
}

void Tempo::setIndex(int index)
{
    if (index >= range())
    {
        _current = Max;
    }
    else if (index <= 0)
    {
        _current = Min;
    }
    else
    {
        _current = index + Min;
    }
    emit indexChanged();
}

int Tempo::current() const
{
    return _current;
}
