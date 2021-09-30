#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "tempocontroller.hpp"
#include "temposettingscontroller.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("DmEAm");
    QCoreApplication::setApplicationName("Metronome");
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("plugins");

    qmlRegisterType<TempoController>("TempoPicker", 1, 0, "TempoController");
    qmlRegisterType<TempoSettingsController>("TempoPicker", 1, 0, "TempoSettingsController");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
