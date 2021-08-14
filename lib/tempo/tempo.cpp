#include "tempo.hpp"

int detectTempo(const QAudioBuffer &buffer)
{
    using namespace essentia::standard;
    using AudioFrame = QAudioBuffer::S16S;

    const auto *data = buffer.constData<AudioFrame>();
    std::vector<essentia::Real> signal;

    for (auto i = 0; i < buffer.frameCount(); i++)
    {
        signal.emplace_back(data[i].left);
    }

    essentia::Real bpm;
    essentia::Real confidence;
    std::vector<essentia::Real> ticks;
    std::vector<essentia::Real> estimates;
    std::vector<essentia::Real> bpmIntervals;

    QScopedPointer<Algorithm> extractor(AlgorithmFactory::create("RhythmExtractor2013"));
    extractor->configure();

    extractor->input("signal").set(signal);
    extractor->output("bpm").set(bpm);

    extractor->output("ticks").set(ticks);
    extractor->output("confidence").set(confidence);
    extractor->output("estimates").set(estimates);
    extractor->output("bpmIntervals").set(bpmIntervals);

    extractor->compute();

    return static_cast<int>(bpm);
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
