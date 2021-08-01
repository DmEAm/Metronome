#include "tempo.hpp"

int detectTempo(const QAudioBuffer &buffer)
{
    const auto &format = buffer.format();
    const auto *data = buffer.constData<qint16>();

    QVector<qint16> channelData(buffer.sampleCount() / format.channelCount());

    for (auto i = 0; i < buffer.sampleCount(); i += format.channelCount())
    {
        channelData[i / format.channelCount()] = data[i];
    }

    return 100;
}
