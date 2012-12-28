#ifndef CHARTPLANE_H
#define CHARTPLANE_H

#include <QWidget>
#include <QImage>

#include "Charms_global.h"
#include "chart.h"
#include "chartlegend.h"

class CHARMSSHARED_EXPORT ChartPlane : public QWidget
{
    public:
        ChartPlane(double unit = 1.0, ChartLegend* legend = NULL);
        ~ChartPlane();

        void setUnit(double newUnit);

        void moveX(double units);
        void moveY(double units);
        void move(double x, double y);

        void zoom(double multiplier);

        void addChart(Chart* chart);
        void removeChart(Chart* chart);

        QImage getSnapshot();
};

#endif // CHARTPLANE_H
