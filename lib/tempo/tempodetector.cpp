#include "tempodetector.hpp"

TempoDetector::TempoDetector(QObject *parent)
: QObject(parent)
, _info(QAudioDeviceInfo::defaultOutputDevice())
, _format(_info.preferredFormat())
, _decoder(new QAudioDecoder(this))
, _buffer()
{
    _format.setSampleRate(48000);
    _decoder->setAudioFormat(_format);

    connect(_decoder, &QAudioDecoder::bufferReady, this, &TempoDetector::readBuffer);
    connect(_decoder, &QAudioDecoder::finished, this, QOverload<>::of(&TempoDetector::detect));
    connect(_decoder, QOverload<QAudioDecoder::Error>::of(&QAudioDecoder::error),
            [=](QAudioDecoder::Error error){ qDebug() << "Error" << error; });
}

void TempoDetector::detect(const QUrl &url)
{
    Q_ASSERT(url.isLocalFile());

    QFileInfo info(url.path());

    Q_ASSERT(info.exists());

    _decoder->setSourceFilename(info.absoluteFilePath());
    _decoder->start();
}

void TempoDetector::readBuffer()
{
    const auto &chunk = _decoder->read();
    _buffer.append(chunk.constData<char>(), chunk.byteCount());
}

void TempoDetector::detect()
{
    QAudioBuffer audio(_buffer, _format);

    Q_ASSERT(audio.isValid());

    auto tempo = detectTempo(audio);
    emit detected(tempo);

    _buffer.clear();
    _buffer.squeeze();
}

