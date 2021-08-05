#ifndef TEMPO_LIBRARY_H
#define TEMPO_LIBRARY_H

#include <QAudioBuffer>
#include <QDebug>
#include <QTime>

#include <chrono>
#include <type_traits>

class TempoDetector : public QObject
{
    Q_OBJECT
    explicit TempoDetector(QObject *parent = nullptr);

};

int detectTempo(const QAudioBuffer &buffer);

QVector<size_t> findExtremum(const QVector<qint16> &values);

#endif //TEMPO_LIBRARY_H
