#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <QtTest>
#include <QAudioDecoder>
#include <QAudioDeviceInfo>

#include "tempo.hpp"

class TempoDetectionTestCase : public QObject
{
    Q_OBJECT
    QAudioDecoder *_decoder;
    QAudioFormat _format;

public:
    TempoDetectionTestCase();
    ~TempoDetectionTestCase() override = default;

private slots:
    void initTestCase();
    void initTestCase_data();
    void detectTempoTestCase();

};

TempoDetectionTestCase::TempoDetectionTestCase()
: _format(QAudioDeviceInfo::defaultOutputDevice().preferredFormat())
, _decoder(new QAudioDecoder(this))
{
    _decoder->setAudioFormat(_format);
}

void TempoDetectionTestCase::initTestCase()
{
    QVERIFY(_format.isValid());
}

void TempoDetectionTestCase::initTestCase_data()
{
    QTest::addColumn<int>("tempo");
    QTest::addColumn<QAudioBuffer>("buffer");

    QDirIterator it(":audio", QDirIterator::Subdirectories);
    while (it.hasNext())
    {
        QFile file(it.next());
        auto fileName = it.fileName();
        QFileInfo info(fileName);

//        this shit does not work
//        file.open(QIODevice::ReadOnly);
//        _decoder->setSourceDevice(&file);
        _decoder->setSourceFilename(info.absoluteFilePath());
        _decoder->start();

        while(!_decoder->bufferAvailable());

        QTest::newRow(qPrintable(QString("Audio %1").arg(fileName)))
        << fileName.leftRef(fileName.indexOf('_')).toInt()
        << _decoder->read();
    }
}

void TempoDetectionTestCase::detectTempoTestCase()
{
    QFETCH_GLOBAL(int, tempo);
    QFETCH_GLOBAL(QAudioBuffer, buffer);

    QVERIFY(buffer.isValid());
    QVERIFY(buffer.sampleCount());
    QCOMPARE(detectTempo(buffer), tempo);
}

QTEST_APPLESS_MAIN(TempoDetectionTestCase)

#include "tst_tempodetectiontestcase.moc"

#pragma clang diagnostic pop