#ifndef STALALICZBOWA_H
#define STALALICZBOWA_H
#include "wyrazenie.h"

class StalaLiczbowa : public Wyrazenie
{
private:
    double a;

public:
    StalaLiczbowa(double a);
    double oblicz(double x);
};

#endif // STALALICZBOWA_H
