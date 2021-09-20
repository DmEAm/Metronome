
#include "tempo.hpp"

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

int Tempo::current() const
{
    return _current;
}
