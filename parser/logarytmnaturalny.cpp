#include "logarytmnaturalny.h"
#include <cmath>

LogarytmNaturalny::LogarytmNaturalny(Wyrazenie* a) : WyrazenieJednoargumentowe(a)
{
}
double LogarytmNaturalny::oblicz(double x){
    return log(wyr1->oblicz(x));
}
