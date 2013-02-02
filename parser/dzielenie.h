#ifndef DZIELENIE_H
#define DZIELENIE_H
#include "wyrazeniedwuargumentowe.h"

class Dzielenie : public WyrazenieDwuargumentowe
{
public:
    Dzielenie(Wyrazenie* a, Wyrazenie* b);
    double oblicz(double x);
};

#endif // DZIELENIE_H
