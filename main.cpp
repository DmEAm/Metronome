#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include <Player/player.hpp>
#include <Tapper/tapper.hpp>
#include <Picker/tempocontroller.hpp>

#include "tempocontroller.hpp"
#include "temposettingscontroller.hpp"
#include "plugins/Picker/tempocontroller.hpp"
#include "updowncontroller.hpp"

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
    qmlRegisterType<UpDownController>("UpDown", 1, 0, "UpDownController");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QQmlComponent component(&engine, url);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    auto context = engine.rootContext();

    auto tempoController = new TempoController(&app);
    auto playerController = new PlayerController(tempoController);

    context->setContextProperty(tempoController->metaObject()->className(),
                                tempoController);

    context->setContextProperty(playerController->metaObject()->className(),
                                playerController);

    return QGuiApplication::exec();
}
