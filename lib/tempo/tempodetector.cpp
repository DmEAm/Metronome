#include "tempodetector.hpp"

TempoDetector::TempoDetector(QObject *parent)
: QObject(parent)
, _info(QAudioDeviceInfo::defaultOutputDevice())
, _format(_info.preferredFormat())
, _decoder(new QAudioDecoder(this))
{
    _format.setSampleRate(48000);
    _decoder->setAudioFormat(_format);

    connect(_decoder, &QAudioDecoder::bufferReady, this, QOverload<>::of(&TempoDetector::detect));
}

void TempoDetector::detect(const QUrl &url)
{
    Q_ASSERT(url.isLocalFile());

    QFileInfo info(url.fileName());

    Q_ASSERT(info.exists());

    _decoder->setSourceFilename(info.absoluteFilePath());
    _decoder->start();
}

void TempoDetector::detect()
{
    const auto &buffer = _decoder->read();
    auto tempo = detectTempo(buffer);
    emit detected(tempo);
}

