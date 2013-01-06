/*
    Naglowek klasy ChartLegend.
    ChartLegend reprezentuje legende.
    Odpowiada za uklad i pozycje legendy
    oraz za przechowywanie informacji o jej aktualnym
    stanie (liscie obecnie wyswietlanych oznaczen
    i podpisow).
    
    Klasa ChartLegend jest "zaprzyjazniona"
    z klasa ChartPlane (po angielsku "friend"),
    przez co klasa ChartPlane bedzie miala dostep
    do jej metod prywatnych, z kolei uzytkownik
    biblioteki nie bedzie mial takiego dostepu.
    Unikamy w ten sposob sztucznego dodawania
    i usuwania opisow w legendzie.
*/


#ifndef CHARTLEGEND_H
#define CHARTLEGEND_H

#include "Charms_global.h"

/*
    Typ opisujacy pozycje legendy na plaszczyznie.
*/
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

/*
    Typ opisujacy uklad legendy (Czy opisy
    wyswietlane sa w kolejnych liniach, czy
    obok siebie).
*/
enum LegendOrientation
{
    Horizontal,
    Vertical
};

class CHARMSSHARED_EXPORT ChartLegend
{
    public:
        /*
            Konstruktor. Przyjmuje opcjonalnie
            pozycje i uklad legendy.
        */
        ChartLegend(LegendPosition position = BottomRight,
                    LegendOrientation orientation = Vertical);
        ~ChartLegend();
        
        /*
            Zmieniaja uklad lub pozycje legendy
            w trakcie dzialania programu.
        */
        void setOrientation(LegendOrientation orientation);
        void setPosition(LegendPosition position);
        
        // Zwracaja aktualny uklad i pozycje.
        LegendOrientation getOrientation();
        LegendPosition getPosition();
        
        // Wlaczaja lub wylaczaja wyswietlanie legendy.
        void show();
        void hide();
        
        // Zwraca czy wyswietlanie legendy jest wlaczone.
        bool isVisible();
};

#endif // CHARTLEGEND_H
