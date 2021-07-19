#ifndef TEMPO_LIBRARY_H
#define TEMPO_LIBRARY_H

#include <QAudioBuffer>

size_t detectTempo(const QAudioBuffer& buffer);

#endif //TEMPO_LIBRARY_H
