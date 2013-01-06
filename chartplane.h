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
        
        d) rysowanie legendy, jesli podamy mu
        odpowiedni obiekt klasy ChartLegend.
*/

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
        /*
            Konstruktor. Przyjmuje dwie opcjonalne
            wartosci:
                - jednostke typu double (mówi o tym,
                jakie liczby wypisywane sa pod osia
                liczbowa; dla 5.0 beda to -10, -5, 0, 5, 10, etc.);
                - wskaznik na obiekt opisujacy uklad,
                wyglad i polozenie legendy (ChartLegend).
            Domylnie jednostka jest rowna 1.0, a legenda nie
            jest wyswietlana.
        */
        ChartPlane(double unit = 1.0, ChartLegend* legend = NULL);
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
            Jednoczesnie odswiezaja stan legendy, jesli
            jej wyswietlanie jest wlaczone.
        */
        void addChart(Chart* chart);
        void removeChart(Chart* chart);
        
        // Zwraca obiekt obrazka z aktualna zawartoscia plaszczyzny.
        QImage getSnapshot();
};

#endif // CHARTPLANE_H
