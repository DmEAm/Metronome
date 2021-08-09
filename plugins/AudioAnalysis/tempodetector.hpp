#ifndef TEMPO_DETECTOR_HPP
#define TEMPO_DETECTOR_HPP

#include <QAudioBuffer>
#include <QDebug>
#include <QFileInfo>
#include <QUrl>
#include <QAudioDecoder>
#include <QAudioDeviceInfo>

#include "tempo.hpp"

#include "audio_analysis_plugin_export.h"

class AUDIO_ANALYSIS_PLUGIN_EXPORT TempoDetector : public QObject
{
    Q_OBJECT

    const QAudioDeviceInfo _info;
    QAudioDecoder *_decoder;
    QAudioFormat _format;
    QByteArray _buffer;

public:
    explicit TempoDetector(QObject *parent = nullptr);
    ~TempoDetector() override = default;

public slots:
    void detect(const QUrl &url);

signals:
    void detecting();
    void progress(int percent);
    void detected(int tempo);

private:
    void detect();
    void readBuffer();
};


#endif //TEMPO_DETECTOR_HPP
