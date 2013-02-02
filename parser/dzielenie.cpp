#include "dzielenie.h"

Dzielenie::Dzielenie(Wyrazenie* a, Wyrazenie* b) : WyrazenieDwuargumentowe(a, b)
{
}

double Dzielenie::oblicz(double x){
    return wyr1->oblicz(x)/wyr2->oblicz(x);
}
