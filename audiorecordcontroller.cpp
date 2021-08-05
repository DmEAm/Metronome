#include "audiorecordcontroller.hpp"

AudioRecordController::AudioRecordController(QObject *parent)
: QObject(parent)
, _recorder(new QAudioRecorder(this))
{
    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
    QAudioFormat format(info.preferredFormat());
    QAudioEncoderSettings settings;

    settings.setQuality(QMultimedia::HighQuality);

    _recorder->setEncodingSettings(settings);

}

void AudioRecordController::record()
{
    QStringList info { QUuid::createUuid().toString(QUuid::WithoutBraces).toLower(), "wav" };
    _recorder->setOutputLocation(QUrl::fromLocalFile(info.join('.')));
    _recorder->record();
}

void AudioRecordController::stop()
{
    _recorder->stop();
    emit recorded(QFileInfo(_recorder->outputLocation().toString()));
}
