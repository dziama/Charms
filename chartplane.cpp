#include "chartplane.h"

#include <QPainter>
#include <QPoint>

ChartPlane::ChartPlane(QWidget *parent,
                       double unit,
                       double centerX,
                       double centerY,
                       double radius):
    QWidget(parent), unit(unit), centerX(centerX), centerY(centerY), radius(radius)
{
    // Inicjalizujemy this->charts (wektor).
    this->charts = new std::vector<Chart*>;
}

ChartPlane::~ChartPlane()
{
    delete this->charts;
    // Usuwamy this->charts.
}

void ChartPlane::addChart(Chart* chart)
{
    this->charts->push_back(chart);
}

void ChartPlane::paintEvent(QPaintEvent *e)
{
    (void)e;

    QPainter painter(this);
    int j = (this->width())/d; // Liczba punktów do narysowania. 'd' - "dokładność".
    double skok = 2*this->radius/j;
    double unitW = this->width()/(2 * this->radius);
    double unitH = this->height()/(2 * this->radius);

    for (unsigned int i = 0; i < this->charts->size(); i++)
    {
        Chart* tempChart = (*this->charts)[i];

        painter.setPen(tempChart->getLineStyle());

        QPointF* table = new QPointF[j];

        for (int a = 0; a < j; a++)
        {
            double currentX = this->centerX - this->radius + a * skok;
            double currentY = tempChart->getValue(currentX);

            table[a] = QPointF(
                        this->width()/2 + currentX * unitW,
                        this->height()/2 + this->centerY * unitH - currentY * unitH
            );
        }

        painter.drawPolyline(table, j);
        delete table;
    }
}
