#include "odejmowanie.h"

Odejmowanie::Odejmowanie(Wyrazenie* a,Wyrazenie* b) : WyrazenieDwuargumentowe(a, b)
{

}

double Odejmowanie::oblicz(double x){
    return wyr1->oblicz(x)-wyr2->oblicz(x);
}
