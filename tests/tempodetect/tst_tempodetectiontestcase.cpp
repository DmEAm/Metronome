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
    const QAudioDeviceInfo _info;
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
: _info(QAudioDeviceInfo::defaultOutputDevice())
, _format(_info.preferredFormat())
, _decoder(new QAudioDecoder(this))
{
    _format.setSampleRate(48000);
    _decoder->setAudioFormat(_format);
}

void TempoDetectionTestCase::initTestCase()
{
    QVERIFY(_format.isValid());
    QVERIFY(_info.isFormatSupported(_format));
}

void TempoDetectionTestCase::initTestCase_data()
{
    QTest::addColumn<int>("tempo");
    QTest::addColumn<QAudioBuffer>("buffer");

    for(const auto &entry : QDir::current().entryList({"*.wav"}, QDir::Files))
    {
        QFile file(entry);
        QFileInfo info(file);
        const auto &fileName = file.fileName();

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