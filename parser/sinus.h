#ifndef SINUS_H
#define SINUS_H
#include "wyrazeniejednoargumentowe.h"

class Sinus : public WyrazenieJednoargumentowe
{
public:
    Sinus(Wyrazenie* a);
    double oblicz(double x);
};

#endif // SINUS_H
