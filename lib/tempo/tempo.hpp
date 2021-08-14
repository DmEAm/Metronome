#ifndef TEMPO_LIBRARY_H
#define TEMPO_LIBRARY_H

#include <QAudioBuffer>
#include <QScopedPointer>
#include <QDebug>
#include <QTime>

#include <rhythmextractor2013.h>
#include <poolstorage.h>
#include <network.h>
#include <algorithmfactory.h>
#include <types.h>

#include <vector>
#include <type_traits>

int detectTempo(const QAudioBuffer &buffer);

QVector<size_t> findExtremum(const QVector<qint16> &values);

#endif //TEMPO_LIBRARY_H
