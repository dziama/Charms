#ifndef COSINUS_H
#define COSINUS_H
#include "wyrazeniejednoargumentowe.h"

class Cosinus : public WyrazenieJednoargumentowe
{
public:
    Cosinus(Wyrazenie* a);
    double oblicz (double x);
};

#endif // COSINUS_H
