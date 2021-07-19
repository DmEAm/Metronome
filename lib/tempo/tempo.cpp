#include "tempo.hpp"

size_t detectTempo(const QAudioBuffer& buffer) {
    Q_UNUSED(buffer);
    return 100;
}
