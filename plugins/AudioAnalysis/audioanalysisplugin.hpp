#ifndef AUDIO_ANALYSIS_PLUGIN_HPP
#define AUDIO_ANALYSIS_PLUGIN_HPP

#include <QmlTypeAndRevisionsRegistration>
#include <QQmlExtensionPlugin>

#include "audiochart.hpp"
#include "tempodetector.hpp"

#include "audiorecordcontroller.hpp"

class AudioAnalysisPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // AUDIO_ANALYSIS_PLUGIN_HPP
