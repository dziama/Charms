#include "chartplane.h"

#include <QPainter>
#include <QPoint>

#include <cmath>

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

void ChartPlane::drawAxes (QPainter& painter)
{
    // "Fizyczna" szerokość i wysokość pojedynczej jednostki w pikselach.
    double unitW = this->width()/(2 * this->radius);
    double unitH = this->height()/(2 * this->radius);

    if (this->centerX < this->radius and this->centerX > -this->radius)
    {
        double oY = abs(this->centerX - this->radius) * unitW;
        painter.drawLine(oY, 0, oY, this->height());
    }

    if (this->centerY < this->radius and this->centerY > -this->radius)
    {
        double oX = abs(this->centerY + this->radius) * unitH;
        painter.drawLine(0, oX, this->width(), oX);
    }
}

void ChartPlane::drawCharts (QPainter& painter)
{
    int j = (this->width())/d; // Liczba punktów do narysowania. 'd' - "dokładność".

    // Zmiana argumentu - odległość pomiędzy kolejnymi x-ami, dla których wyliczamy wartość funkcji.
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

void ChartPlane::drawLabels (QPainter& painter)
{

}


void ChartPlane::paintEvent(QPaintEvent *e)
{
    (void)e;

    QPainter painter(this);
    this->drawAxes(painter);
    this->drawCharts(painter);
    this->drawLabels(painter);
}
