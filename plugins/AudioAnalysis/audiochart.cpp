#include "audiochart.hpp"

AudioChart::AudioChart(QGraphicsItem *parent, Qt::WindowFlags wFlags)
: QChart(QChart::ChartTypeCartesian, parent, wFlags)
, _series(new QSplineSeries(this))
, _axisX(new QValueAxis(this))
, _axisY(new QValueAxis(this))
, _x(5)
, _y(1)
{
    QObject::connect(&_timer, &QTimer::timeout, this, &AudioChart::handleTimeout);
    _timer.setInterval(1000);

    QPen green(Qt::red);
    green.setWidth(3);

    _series->setPen(green);
    _series->append(_x, _y);

    addSeries(_series);

    addAxis(_axisX, Qt::AlignBottom);
    addAxis(_axisY, Qt::AlignLeft);
    _series->attachAxis(_axisX);
    _series->attachAxis(_axisY);
    _axisX->setTickCount(5);
    _axisX->setRange(0, 10);
    _axisY->setRange(-5, 10);

    _timer.start();
}

void AudioChart::handleTimeout()
{
    qreal x = plotArea().width() / _axisX->tickCount();
    qreal y = (_axisX->max() - _axisX->min()) / _axisX->tickCount();
    _x += y;
    _y = QRandomGenerator::global()->bounded(5) - 2.5;
    _series->append(_x, _y);
    scroll(x, 0);
    if (_x == 100)
        _timer.stop();
}
