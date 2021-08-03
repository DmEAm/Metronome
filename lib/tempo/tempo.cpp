#include "tempo.hpp"

QVector<size_t> findExtremum(const QVector<qint16> &values);

int detectTempo(const QAudioBuffer &buffer)
{
    const auto &format = buffer.format();
    const auto *data = buffer.constData<qint16>();

    QVector<qint16> channelData(buffer.sampleCount() / format.channelCount());

    for (auto i = 0; i < buffer.sampleCount(); i += format.channelCount())
    {
        channelData[i / format.channelCount()] = data[i];
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