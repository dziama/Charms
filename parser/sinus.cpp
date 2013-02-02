#include "sinus.h"
#include <cmath>

Sinus::Sinus(Wyrazenie* a) : WyrazenieJednoargumentowe(a)
{

}

double Sinus::oblicz(double x){
    return sin(wyr1->oblicz(x));
}
