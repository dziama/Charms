#include "dodawanie.h"

Dodawanie::Dodawanie(Wyrazenie* a,Wyrazenie* b) : WyrazenieDwuargumentowe(a, b)
{

}

double Dodawanie::oblicz(double x){
    return wyr1->oblicz(x)+wyr2->oblicz(x);
}
