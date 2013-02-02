#include "mnozenie.h"

Mnozenie::Mnozenie(Wyrazenie* a, Wyrazenie* b) : WyrazenieDwuargumentowe(a,b)
{
}
double Mnozenie::oblicz(double x){
    return wyr1->oblicz(x)*wyr2->oblicz(x);
}
