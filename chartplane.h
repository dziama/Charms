/*
    Nagłówek zawierający definicję klasy ChartPlane.
    Klasa ChartPlane reprezentuje plaszczyzne, na ktorej
    rysujemy wykres. W praktyce jest widgetem Qt,
    czyli elementem, który można w swoim projekcie
    wstawic do okna. Odpowiada za:
        
        a) narysowanie ukladu wspolrzednych o okreslonej
        jednostce;
        
        b) rysowanie wykresow, ktore podajemy mu jako
        obiekty klasy Chart;
        
        c) przyblizanie, oddalanie oraz przesuwanie
        widoku;
*/

#ifndef CHARTPLANE_H
#define CHARTPLANE_H

#include <QWidget>
#include <QImage>

#include "Charms_global.h"
#include "chart.h"

class CHARMSSHARED_EXPORT ChartPlane : public QWidget
{
    public:
        /*
            Konstruktor. Przyjmuje cztery opcjonalne
            argumenty.
                - jednostke typu double (mówi o tym,
                jakie liczby wypisywane sa pod osia
                liczbowa; dla 5.0 beda to -10, -5, 0, 5, 10, etc.);

                - współrzędną x-ową oraz y-ową typu double
                środka obszaru wyświetlanego;

                - promień obszaru wyświetlanego typu
                double (czyli to samo, co połowa szerokości
                i wysokości obszaru).
        */
        ChartPlane(double unit = 1.0,
                   double centerX = 0.0,
                   double centerY = 0.0,
                   double radius = 10.0);
        ~ChartPlane();
        
        // Zmienia jednostke w trakcie dzialania programu.
        void setUnit(double newUnit);
        
        // Zwraca obecnie ustawiona jednostke.
        double getUnit();
        
        /* 
            Metody przesuwaja wykresy wzdluz
            osi X, osi Y lub obu. Przyjmuja liczbe
            jednostek, o ktore przesuwamy widok.
        */
        void moveX(double units);
        void moveY(double units);
        void move(double x, double y);
        
        /*
            Przybliza lub oddala widok n-krotnie.
            Oznacza to, ze obecna jednostke wymnazamy
            przez odwrotnosc podanego mnoznika przy tej
            samej rzeczywistej odleglosci pomiedzy
            kreskami na osi.
        */
        void zoom(double multiplier);

        /*
            Metody dodaja lub usuwaja wykres z plaszczyzny.
        */
        void addChart(Chart* chart);
        void removeChart(Chart* chart);
        
        // Zwraca obiekt obrazka z aktualna zawartoscia plaszczyzny.
        QImage getSnapshot();
};

#endif // CHARTPLANE_H
