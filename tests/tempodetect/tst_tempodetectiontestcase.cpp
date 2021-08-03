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

    QByteArray array;
    array.push_back(0x3c); array.push_back(0x3c);
    array.push_back(0xb8); array.push_back(0xb8);
    array.push_back(0x64); array.push_back(0x64);
    array.push_back(0xcd); array.push_back(0xa5);
    array.push_back(0x4); array.push_back(0x75);
    array.push_back(0x18); array.push_back(0x18);
    array.push_back(0xca); array.push_back(0xca);
    array.push_back(0x3c); array.push_back(0x3c);

    array.push_back(0x3c); array.push_back(0x3a);
    array.push_back(0xb7); array.push_back(0xb9);
    array.push_back(0x61); array.push_back(0x65);
    array.push_back(0x19); array.push_back(0x17);
    array.push_back(0xc9); array.push_back(0xc6);
    array.push_back(0x3c); array.push_back(0x3d);

    QTest::newRow("Raw audio") << 1000 << QAudioBuffer(array, _format);

//    for(const auto &entry : QDir::current().entryList({"*.wav"}, QDir::Files))
//    {
//        QFile file(entry);
//        QFileInfo info(file);
//        const auto &fileName = file.fileName();

//        this shit does not work
//        file.open(QIODevice::ReadOnly);
//        _decoder->setSourceDevice(&file);
//        _decoder->setSourceFilename(info.absoluteFilePath());
//        _decoder->start();
//
//        while(!_decoder->bufferAvailable());
//
//        QTest::newRow(qPrintable(QString("Audio %1").arg(fileName)))
//        << fileName.leftRef(fileName.indexOf('_')).toInt()
//        << _decoder->read();
//    }
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