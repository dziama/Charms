#ifndef ODEJMOWANIE_H
#define ODEJMOWANIE_H
#include "wyrazeniedwuargumentowe.h"

class Odejmowanie : public WyrazenieDwuargumentowe
{
public:
    Odejmowanie(Wyrazenie* a,Wyrazenie* b);
    double oblicz(double x);
};

#endif // ODEJMOWANIE_H
