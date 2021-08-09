#include "audioanalysisplugin.hpp"

void AudioAnalysisPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<AudioChart>(uri, 1, 0, "AudioChart");
    qmlRegisterType<AudioRecordController>(uri, 1, 0, "AudioRecordController");
    qmlRegisterType<TempoDetector>(uri, 1, 0, "TempoDetector");
}
