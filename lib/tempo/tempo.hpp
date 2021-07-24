#ifndef TEMPO_LIBRARY_H
#define TEMPO_LIBRARY_H

#include <QAudioBuffer>
#include <QDebug>

#include <chrono>
#include <type_traits>

int detectTempo(const QAudioBuffer &buffer);

#endif //TEMPO_LIBRARY_H
