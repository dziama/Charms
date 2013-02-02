#ifndef ZMIENNA_H
#define ZMIENNA_H

#include "wyrazenie.h"

class Zmienna : public Wyrazenie{
public:
    Zmienna();
    double oblicz(double x);
};

#endif // ZMIENNA_H
