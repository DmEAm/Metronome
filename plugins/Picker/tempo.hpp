#ifndef METRONOME_TEMPO_HPP
#define METRONOME_TEMPO_HPP

#include <QObject>

class Tempo : public QObject
{
    Q_OBJECT

    int _current;

    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(int range READ range NOTIFY rangeChanged)
    Q_PROPERTY(int max MEMBER Max CONSTANT)
    Q_PROPERTY(int min MEMBER Min CONSTANT)

signals:
    void currentChanged();
    void rangeChanged();

public:
    static constexpr int Max = 230;
    static constexpr int Default = 120;
    static constexpr int Min = 20;

    explicit Tempo(int t = Default)
        : _current(t)
    {}

    static int range() { return Max - Min + 1; }

    int current() const;
    void setCurrent(int tempo);
};

#endif //METRONOME_TEMPO_HPP
