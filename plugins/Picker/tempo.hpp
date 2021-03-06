#ifndef METRONOME_TEMPO_HPP
#define METRONOME_TEMPO_HPP

#include <QObject>
#include <picker_plugin_export.h>

class PICKER_PLUGIN_EXPORT Tempo : public QObject
{
    Q_OBJECT

    int _current;

    Q_PROPERTY(int current READ current WRITE setCurrent NOTIFY currentChanged)
    Q_PROPERTY(int index READ index WRITE setIndex NOTIFY indexChanged)
    Q_PROPERTY(int range READ range NOTIFY rangeChanged)
    Q_PROPERTY(int max MEMBER Max CONSTANT)
    Q_PROPERTY(int min MEMBER Min CONSTANT)

signals:
    void currentChanged();
    void indexChanged();
    void rangeChanged();

public:
    using min = std::chrono::minutes;
    using msec = std::chrono::milliseconds;

    // QTime().msecsTo(QTime(0, 1, 0, 0)) doesnt constexpr
    static constexpr int MsecsInMinute = std::chrono::duration_cast<msec>(min(1)).count();

    static constexpr int Max = 230;
    static constexpr int Default = 120;
    static constexpr int Min = 20;

    explicit Tempo(QObject *parent = nullptr);

    static int range() { return Max - Min + 1; }

    int current() const;
    void setCurrent(int tempo);
    int index() const;
    void setIndex(int index);
};

#endif //METRONOME_TEMPO_HPP
