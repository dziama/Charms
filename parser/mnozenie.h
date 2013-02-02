#ifndef MNOZENIE_H
#define MNOZENIE_H
#include "wyrazeniedwuargumentowe.h"

class Mnozenie : public WyrazenieDwuargumentowe
{
public:
    Mnozenie(Wyrazenie* a, Wyrazenie* b);
    double oblicz(double x);
};

#endif // MNOZENIE_H
