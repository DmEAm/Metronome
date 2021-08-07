#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <Tapper/tapper.hpp>
#include <Player/player.hpp>

#include <tempo/tempodetector.hpp>

#include "tempocontroller.hpp"
#include "audiorecordcontroller.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("plugins");

    qmlRegisterType<TempoController>("TempoPicker", 1, 0, "TempoController");
    qmlRegisterType<AudioRecordController>("TempoDetector", 1, 0, "AudioRecordController");
    qmlRegisterType<TempoDetector>("TempoDetector", 1, 0, "TempoDetector");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
