#include "chartplane.h"

#include <QPainter>
#include <QPainterPath>
#include <QPoint>
#include <QFont>

#include <cmath>
#include <cfloat>
#include <sstream>

const double ChartPlane::d = 1;
const int ChartPlane::margin = 40;

// Funkcja pomocnicza, sprawdzajaca, czy wyrazenie jest skonczone.
bool isFiniteNumber(double x)
{
    return (x <= DBL_MAX && x >= -DBL_MAX);
}

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

void ChartPlane::setUnit(double newUnit)
{
    this->unit = newUnit;
    this->repaint();
}

void ChartPlane::moveX(double units)
{
    this->centerX -= units;
    this->repaint();
}

void ChartPlane::moveY(double units)
{
    this->centerY -= units;
    this->repaint();
}

void ChartPlane::move(double x, double y)
{
    this->centerX -= x;
    this->centerY -= y;

    this->repaint();
}

void ChartPlane::zoom(double multiplier)
{
    this->unit /= multiplier;
    this->repaint();
}

void ChartPlane::addChart(Chart* chart)
{
    this->charts->push_back(chart);
    this->repaint();
}

void ChartPlane::removeChart(Chart* chart)
{
    vector<Chart*>::iterator it;
    for(it = charts->begin(); it != charts->end(); it++) {
        if(*it == chart) {
            this->charts->erase(it);
            break;
        }
    }

    this->repaint();
}

void ChartPlane::drawAxes (QPainter& painter)
{
    // "Fizyczna" szerokość i wysokość pojedynczej jednostki w pikselach.
    double unitW = (this->width() - this->margin)/(2 * this->radius);
    double unitH = (this->height() - this->margin)/(2 * this->radius);

    if (this->centerX < this->radius and this->centerX > -this->radius)
    {
        double oY = abs(this->centerX - this->radius) * unitW + this->margin;
        painter.drawLine(oY, 0, oY, this->height() - this->margin);
    }

    if (this->centerY < this->radius and this->centerY > -this->radius)
    {
        double oX = abs(this->centerY + this->radius) * unitH;
        painter.drawLine(this->margin, oX, this->width(), oX);
    }
}

void ChartPlane::drawCharts (QPainter& painter)
{
    int j = (this->width() - this->margin)/d; // Liczba punktów do narysowania. 'd' - "dokładność".

    // Zmiana argumentu - odległość pomiędzy kolejnymi x-ami, dla których wyliczamy wartość funkcji.
    double skok = 2*this->radius/j;

    double unitW = (this->width() - this->margin)/(2 * this->radius);
    double unitH = (this->height() - this->margin)/(2 * this->radius);

    for (unsigned int i = 0; i < this->charts->size(); i++)
    {
        Chart* tempChart = (*this->charts)[i];

        painter.setPen(tempChart->getLineStyle());

        bool prevFinite = false;
        double prevY = 0;
        QPainterPath path;

        // Najbliższa następna wielokrotność jednostki.
        double currUnitMult = this->centerX - this->radius;
        double epsilon = skok;

        for (int a = 0; a < j; a++)
        {
            double currentX = this->centerX - this->radius + a * skok;
            double currentY = tempChart->getValue(currentX);

            if(isFiniteNumber(currentY))
            {
                double x = (this->width() - this->margin)/2 + currentX * unitW - this->centerX * unitW + this->margin;
                double y = (this->height() - this->margin)/2 + this->centerY * unitH - currentY * unitH;

                if (!prevFinite)
                    path.moveTo(x, y);

                else
                {
                    if (prevY >= this->height() - this->margin)
                        path.moveTo(x, y);
                    else
                        path.lineTo(x, y);
                }

                if (abs(currentX - currUnitMult) < epsilon)
                {
                    QPixmap tempPM = tempChart->getPointMarker();
                    painter.drawPixmap(x - tempPM.width()/2, y - tempPM.height()/2, tempPM);
                }

                prevY = y;
                prevFinite = true;
            }
            else
            {
                double x = (this->width() - this->margin)/2 + currentX * unitW - this->centerX * unitW + this->margin;

                path.moveTo(x, -1);

                prevY = -1;
                prevFinite = false;
            }

            if (abs(currentX - currUnitMult) < epsilon)
                currUnitMult += this->unit;
        }

        painter.drawPath(path);
    }
}

void ChartPlane::drawLabels (QPainter& painter)
{
    int m = this->margin, hm = this->height() - this->margin;

    painter.setPen(QPen(Qt::darkGray));
    painter.drawLine(m, 0, m, hm);
    painter.drawLine(m, hm, this->width(), hm);

    // Liczba "kresek" podziałki.
    int num = 2 * this->radius/this->unit + 1; // Automatycznie obcinana część po przecinku.

    double uW = (this->width() - this->margin)/(2 * this->radius) * this->unit;
    double uH = (this->height() - this->margin)/(2 * this->radius) * this->unit;

    // Pion
    int x1 = 2 * this->margin/3, x2 = this->margin;
    // X punktów lewego górnego oraz prawego dolnego rogu obszaru, w którym jest tekst.
    int tx1 = 0, tx2 = this->margin*2/3 - 3;

    for (int i = 0; i < num; i++)
    {
        double value = this->centerY - this->radius + i * this->unit;

        int y = this->height() - this->margin - i*uH;
        painter.drawLine(x1, y, x2, y);

        painter.setFont(QFont("Trebuchet", 6));

        int ty1 = y - 5;

        std::stringstream ss;
        ss << value;

        painter.drawText(tx1, ty1, tx2 - tx1, 10, Qt::AlignRight | Qt::TextSingleLine, ss.str().c_str());
        // Musimy dopisać .c_str, ponieważ metoda drawText przyjmuje tablicę charów, a nie std::string.
    }

    // Poziom
    int y1 = this->height() - this->margin, y2 = this->height() - this->margin*2/3;

    int ty1 = this->height() - this->margin*2/3 + 3;

    for (int i = 0; i < num; i++)
    {
        double value = this->centerX - this->radius + i * this->unit;

        int x = this->margin + i*uW;
        painter.drawLine(x, y1, x, y2);

        painter.setFont(QFont("Trebuchet", 6));

        std::stringstream ss;
        ss << value;

        int tx1 = x - this->margin * 1/3;
        int tx2 = x + this->margin * 1/3;

        painter.drawText(tx1, ty1, tx2 - tx1, 10, Qt::AlignCenter | Qt::TextSingleLine, ss.str().c_str());
    }
}


void ChartPlane::paintEvent(QPaintEvent *e)
{
    (void)e;

    QPainter painter(this);
    this->drawAxes(painter);
    this->drawCharts(painter);
    this->drawLabels(painter);
}
