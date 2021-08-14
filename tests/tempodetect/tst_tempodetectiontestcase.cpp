#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <QtTest>
#include <QAudioDecoder>
#include <QAudioDeviceInfo>

#include <chrono>

#include "tempo.hpp"

class TempoDetectionTestCase : public QObject
{
    const static int TempoPrecision = 15;

    Q_OBJECT
    const QAudioDeviceInfo _info;
    QAudioDecoder *_decoder;
    QAudioFormat _format;

    QAudioBuffer _buffer;
public:
    TempoDetectionTestCase();
    ~TempoDetectionTestCase() override = default;

private slots:
    void init();

    void initTestCase();
    void initTestCase_data();

    void detectTempoTestCase();

};

TempoDetectionTestCase::TempoDetectionTestCase()
: _info(QAudioDeviceInfo::defaultOutputDevice())
, _format(_info.preferredFormat())
, _decoder(new QAudioDecoder(this))
{
    _format.setSampleRate(44100);
    _decoder->setAudioFormat(_format);
}

void TempoDetectionTestCase::init()
{
    using namespace std::chrono;

    QFETCH_GLOBAL(QFileInfo, info);

    _decoder->setSourceFilename(info.absoluteFilePath());
    _decoder->start();

    QByteArray buffer;

    while(QTest::qWaitFor([&](){ return _decoder->bufferAvailable(); }, 1000))
    {
        auto chunk = _decoder->read();
        buffer.append(chunk.constData<char>(), chunk.byteCount());
    }
    _buffer = QAudioBuffer(buffer, _format);

    auto ms = duration_cast<milliseconds>(microseconds(_buffer.duration())).count();
    auto duration = QTime::fromMSecsSinceStartOfDay(static_cast<int>(ms));

    qInfo("Duration %s", qPrintable(duration.toString()));
}

void TempoDetectionTestCase::initTestCase()
{
    QVERIFY(_format.isValid());
    QVERIFY(_info.isFormatSupported(_format));

    essentia::init();
}

void TempoDetectionTestCase::initTestCase_data()
{
    QTest::addColumn<int>("tempo");
    QTest::addColumn<QFileInfo>("info");

    for(const auto &entry : QDir::current().entryList({"*.wav"}, QDir::Files))
    {
        QFile file(entry);
        QFileInfo info(file);
        const auto &fileName = file.fileName();

        QTest::newRow(qPrintable(QString("Audio %1").arg(fileName)))
        << fileName.leftRef(fileName.indexOf('_')).toInt()
        << info;
    }
}

void TempoDetectionTestCase::detectTempoTestCase()
{
    QFETCH_GLOBAL(int, tempo);

    QVERIFY(_buffer.isValid());
    QVERIFY(_buffer.sampleCount());

    QBENCHMARK_ONCE
    {
        auto actual = detectTempo(_buffer);
        QVector<int> range { actual / 2, actual, actual * 2 };

        qInfo("Detected %i, Expected %i", actual, tempo);

        QVERIFY(std::any_of(range.cbegin(), range.cend(), [&](int i)
        {
            return std::abs(i - tempo) < TempoPrecision;
        }));
    }
}

QTEST_APPLESS_MAIN(TempoDetectionTestCase)

#include "tst_tempodetectiontestcase.moc"

#pragma clang diagnostic pop