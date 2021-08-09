#ifndef AUDIO_CHART_HPP
#define AUDIO_CHART_HPP

#include <QTimer>
#include <QChartView>
#include <QChart>
#include <QSplineSeries>
#include <QValueAxis>
#include <QRandomGenerator>
#include <QDebug>

using namespace QtCharts;

class AudioChart : public QChart
{
    Q_OBJECT
public:
    explicit AudioChart(QGraphicsItem *parent = nullptr, Qt::WindowFlags wFlags = {});
    ~AudioChart() override = default;

public slots:
    void handleTimeout();

private:
    QTimer _timer;
    QSplineSeries *_series;
    QValueAxis *_axisX;
    QValueAxis *_axisY;
    qreal _x;
    qreal _y;
};

#endif //AUDIO_CHART_HPP
