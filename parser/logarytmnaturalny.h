#ifndef LOGARYTMNATURALNY_H
#define LOGARYTMNATURALNY_H
#include "wyrazeniejednoargumentowe.h"

class LogarytmNaturalny : public WyrazenieJednoargumentowe
{
public:
    LogarytmNaturalny(Wyrazenie* a);
    double oblicz (double x);
};

#endif // LOGARYTMNATURALNY_H
