#include "chart.h"

#include "parser/wyrazenia.h"

Chart::Chart(string function,
             QPen lineStyle = QPen(Qt::NoBrush, 1.0),
             QPixmap pointMarker = QPixmap()):
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

QPen& Chart::getLineStyle() const
{
    return this->lineStyle;
}

QPixmap& Chart::getPointMarker() const
{
    return this->pointMarker;
}

double Chart::getValue(double x)
{
    return this->dane->oblicz(x);
}
