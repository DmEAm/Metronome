#include "tempo.hpp"

int detectTempo(const QAudioBuffer &buffer)
{
    using mcs = std::chrono::microseconds;
    using ms = std::chrono::milliseconds;
    using AudioFrame = QAudioBuffer::S16S;
    using std::chrono::duration_cast;

    qDebug() << duration_cast<ms>(mcs(buffer.duration())).count();
    auto duration = QTime::fromMSecsSinceStartOfDay(buffer.duration());
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

TempoDetector::TempoDetector(QObject *parent) : QObject(parent)
{

}
