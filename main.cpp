#include <QApplication>
#include <QQmlApplicationEngine>

#include <Tapper/tapper.hpp>
#include <Player/player.hpp>
#include <QMainWindow>
#include <audiochart.hpp>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>

#include "tempocontroller.hpp"
#include "tempo.hpp"

int main(int argc, char *argv[])
{
    essentia::init();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.addImportPath("plugins");

    qmlRegisterType<TempoController>("TempoPicker", 1, 0, "TempoController");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
