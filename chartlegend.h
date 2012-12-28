#ifndef CHARTLEGEND_H
#define CHARTLEGEND_H

#include "Charms_global.h"

enum LegendPosition
{
    TopLeft,
    Top,
    TopRight,
    Right,
    BottomRight,
    Bottom,
    BottomLeft,
    Left
};

enum LegendOrientation
{
    Horizontal,
    Vertical
};

class CHARMSSHARED_EXPORT ChartLegend
{
    public:
        ChartLegend(LegendPosition position = BottomRight,
                    LegendOrientation orientation = Vertical);
        ~ChartLegend();

        void setOrientation(LegendOrientation orientation);
        void setPosition(LegendPosition position);

        void show();
        void hide();
};

#endif // CHARTLEGEND_H
