#include "potega.h"

Potega::Potega(Wyrazenie* a, Wyrazenie* b) : WyrazenieDwuargumentowe(a, b)
{

}

double Potega::oblicz(double x){
    return pow(wyr1->oblicz(x), wyr2->oblicz(x));
}
