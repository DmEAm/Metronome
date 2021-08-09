#ifndef AUDIO_RECORD_CONTROLLER_HPP
#define AUDIO_RECORD_CONTROLLER_HPP

#include <QObject>
#include <QAudioRecorder>
#include <QAudioDeviceInfo>
#include <QUuid>
#include <QUrl>
#include <QFileInfo>

class AudioRecordController : public QObject
{
    Q_OBJECT

public:
    explicit AudioRecordController(QObject *parent = nullptr);
    ~AudioRecordController() override = default;

public slots:
    void record();
    void stop();

signals:
    void recorded(const QUrl &url);

private:
    QAudioRecorder *_recorder;
};


#endif //AUDIO_RECORD_CONTROLLER_HPP
