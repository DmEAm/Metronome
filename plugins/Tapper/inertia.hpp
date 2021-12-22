#ifndef METRONOME_INERTIA_HPP
#define METRONOME_INERTIA_HPP

#include <QObject>

class Inertia : public QObject
{
    Q_PROPERTY(int max MEMBER Max CONSTANT)
    Q_PROPERTY(int min MEMBER Min CONSTANT)

public:
    static constexpr int Max = 10;
    static constexpr int Min = 2;
};

#endif //METRONOME_INERTIA_HPP
