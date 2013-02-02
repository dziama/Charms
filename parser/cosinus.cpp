#include "cosinus.h"
#include <cmath>

Cosinus::Cosinus(Wyrazenie* a) : WyrazenieJednoargumentowe(a)
{
}
double Cosinus::oblicz(double x){
    return cos(wyr1->oblicz(x));
}
