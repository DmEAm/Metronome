#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <QtTest>
#include <QAudioDecoder>

#include "tempo.hpp"

class TempoDetectionTestCase : public QObject
{
    Q_OBJECT
    QAudioDecoder *_decoder;

public:
    TempoDetectionTestCase();
    ~TempoDetectionTestCase() override = default;

private slots:
    void initTestCase_data();
    void detectTempoTestCase();
};

TempoDetectionTestCase::TempoDetectionTestCase()
: _decoder(new QAudioDecoder(this))
{
}

void TempoDetectionTestCase::initTestCase_data()
{
    QTest::addColumn<int>("tempo");
    QTest::addColumn<QAudioBuffer>("buffer");

    QDirIterator it(":audio", QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        _decoder->setSourceFilename(it.next());

        auto file = it.fileName();

        QTest::newRow(qPrintable(QString("Audio %1").arg(file)))
        << file.leftRef(file.indexOf('_')).toInt()
        << _decoder->read();
    }

    QTest::addColumn<QString>("path");
}

void TempoDetectionTestCase::detectTempoTestCase()
{
    QFETCH_GLOBAL(int, tempo);
    QFETCH_GLOBAL(QAudioBuffer, buffer);

    QCOMPARE(detectTempo(buffer), tempo);
}

QTEST_APPLESS_MAIN(TempoDetectionTestCase)

#include "tst_tempodetectiontestcase.moc"

#pragma clang diagnostic pop