#include "chart.h"

#include "parser/wyrazenia.h"

Chart::Chart(string function,
             QPen lineStyle,
             QPixmap pointMarker):
    lineStyle(lineStyle), pointMarker(pointMarker)
{
    this->dane = parser(function);
}

Chart::~Chart()
{
    delete this->dane;
}

void Chart::setLineStyle(QPen lineStyle)
{
    this->lineStyle = lineStyle;
}

void Chart::setPointMarker(QPixmap pointMarker)
{
    this->pointMarker = pointMarker;
}

const QPen& Chart::getLineStyle()
{
    return this->lineStyle;
}

const QPixmap& Chart::getPointMarker()
{
    return this->pointMarker;
}

double Chart::getValue(double x)
{
    return this->dane->oblicz(x);
}
