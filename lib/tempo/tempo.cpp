#include "tempo.hpp"

int detectTempo(const QAudioBuffer &buffer)
{
    using namespace std::chrono;
    using AudioFrame = QAudioBuffer::S16S;

    auto ms = duration_cast<milliseconds>(microseconds(buffer.duration())).count();
    auto duration = QTime::fromMSecsSinceStartOfDay(static_cast<int>(ms));

    const auto &format = buffer.format();

    qDebug() << buffer.frameCount() << format.sampleRate() << buffer.duration() << duration;
    const auto *data = buffer.constData<AudioFrame>();
    QVector<qint16> channelData(buffer.sampleCount() / format.channelCount());

    for (auto i = 0; i < buffer.frameCount(); i++)
    {
        channelData[i / format.channelCount()] = data[i].average();
    }

    auto ext = findExtremum(channelData);
    qDebug() << ext;

    return 100;
}

/** Find all local extremum
 * @param values target func values */
QVector<size_t> findExtremum(const QVector<qint16> &values)
{
    QVector<size_t> vector;

    auto last = values.begin();

    do
    {
        last = std::adjacent_find(last, values.end(), std::greater<qint16>());
        if(last == values.end()) break;

        vector.push_back(std::distance(values.begin(), last));
    }
    while(++last != values.end());

    return vector;
}
