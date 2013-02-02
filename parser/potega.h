#ifndef POTEGA_H
#define POTEGA_H
#include "wyrazeniedwuargumentowe.h"
#include <cmath>

class Potega : public WyrazenieDwuargumentowe
{
public:
    Potega(Wyrazenie* a, Wyrazenie* b);
    double oblicz(double x);
};

#endif // POTEGA_H
