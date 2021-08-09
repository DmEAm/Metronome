#ifndef AUDIO_CHART_HPP
#define AUDIO_CHART_HPP

#include <QTimer>
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
    QTimer m_timer;
    QSplineSeries *m_series;
    QStringList m_titles;
    QValueAxis *m_axisX;
    QValueAxis *m_axisY;
    qreal m_step;
    qreal m_x;
    qreal m_y;
};

#endif //AUDIO_CHART_HPP
