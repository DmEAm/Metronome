#ifndef TEMPO_DETECTOR_HPP
#define TEMPO_DETECTOR_HPP

#include <QAudioBuffer>
#include <QDebug>
#include <QFileInfo>
#include <QUrl>
#include <QAudioDecoder>
#include <QAudioDeviceInfo>

#include "tempo.hpp"

#include "tempo_export.h"

class TEMPO_EXPORT TempoDetector : public QObject
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
    void detected(int tempo);

private:
    void detect();
    void readBuffer();
};


#endif //TEMPO_DETECTOR_HPP
