/*
    Nagłówek zawierający definicję klasy Chart.
    Klasa Chart reprezentuje pojedynczy wykres znajdujący się
    na płaszczyźnie. Odpowiada za:

        a) przetworzenie tekstowego zapisu
        funkcji (np. x^2 + 2*x + 5) na postać zrozumiałą
        dla reszty programu (prawdziwa funkcja, którą można
        wywołać);

        b) ustawienie stylu linii (lineStyle) oraz jego zmianę
        w trakcie działania programu (setLineStyle);

        c) ustawienie "znaczników punktów" (pointMarker) - chodzi
        o obrazki (kropki, trójkąty, kwadraciki, etc), tworzące
        "punktowy" wykres funkcji - oraz ich zmianę w trakcie
        działania programu (setPointMarker).
*/

#ifndef CHART_H
#define CHART_H

#include <QPen>
#include <QPixmap>
#include <Qt>

#include <string>

#include "Charms_global.h"
#include "parser/wyrazenie.h"
using namespace std;

class CHARMSSHARED_EXPORT Chart
{
    public:
        /*
            Konstruktor. Przyjmuje tekstowy zapis funkcji
            (jest on wymagany), styl linii oraz obrazek
            znacznika punktu (nie jest konieczne wpisywanie
            wartości, gdyż istnieją wartości domyślne).
        */

        Chart(string function,
              // Domyślnie czarna linia ciągła o grubości 1.0.
              QPen lineStyle = QPen(Qt::NoBrush, 1.0),
              // Domyślnie pusty obrazek.
              QPixmap pointMarker = QPixmap());


        // Destruktor. Zwalnia pamięć.
        ~Chart();

        /*
            Metoda zwracająca wyliczoną wartość funkcji
            dla podanego argumentu.
        */
        double getValue(double x);

        // Metody zmieniające styl linii / znaczników punktów.
        void setLineStyle(QPen lineStyle);
        void setPointMarker(QPixmap pointMarker);

        /*
            Metody zwracające aktualny styl linii / znaczników
            punktów.

            Znak '&' sprawia, że zamiast zwracać kopię istniejącego
            obiektu (co następowałoby, gdyby zapisać metodę np.
            w ten sposób: QPen getLineStyle();),
            co wiązałoby się z niepotrzebnym wykorzystaniem
            pamięci, zwracamy referencję do niego
            (fajniejszy wskaźnik).

            Const sprawia, że zwrócona wartość nie może być
            zmieniona przez użytkownika biblioteki
            (do zmian służą metody setLineStyle i setPointMarker).
        */

        QPen& getLineStyle() const;
        QPixmap& getPointMarker() const;

    private:
        QPen lineStyle;
        QPixmap pointMarker;
        Wyrazenie* dane;

#endif // CHART_H
