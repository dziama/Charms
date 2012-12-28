#ifndef CHART_H
#define CHART_H

#include <QPen>
#include <QPixmap>

#include <string>

#include "Charms_global.h"

using namespace std;

class CHARMSSHARED_EXPORT Chart
{
    public:
        Chart(string function, QPen lineStyle, QPixmap pointMarker);
        ~Chart();

        void setLineStyle(QPen lineStyle);
        void setPointMarker(QPixmap pointMarker);
};

#endif // CHART_H
