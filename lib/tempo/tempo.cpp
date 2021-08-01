#include "tempo.hpp"

int detectTempo(const QAudioBuffer &buffer)
{
    const auto &format = buffer.format();
    const auto *data = buffer.constData<qint16>();

    qDebug()<< buffer.duration() << buffer.sampleCount() << format.sampleType();

    for (auto i = 0; i < buffer.sampleCount(); i += format.channelCount())
    {
        qDebug() << data[i];
    }

    return 100;
}
