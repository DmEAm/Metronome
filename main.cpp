#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>
#include <QScopedPointer>
#include <QDebug>
#include <QQuickItem>

#include <Player/player.hpp>
#include <Tapper/tapper.hpp>
#include <tempocontroller.hpp>

#include "contextobject.hpp"
#include "temposettingscontroller.hpp"

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("DmEAm");
    QCoreApplication::setApplicationName(PROJECT_NAME);
    QCoreApplication::setApplicationVersion(PROJECT_VERSION);
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlComponent component(&engine);
    ContextObject object;
    engine.addImportPath("plugins");

    qmlRegisterType<TempoController>("TempoPicker", 1, 0, "TempoController");
    qmlRegisterType<TempoSettingsController>("TempoPicker", 1, 0, "TempoSettingsController");

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    auto context = engine.rootContext();
    context->setContextObject(&object);

    engine.load(url);

    return QGuiApplication::exec();
}
