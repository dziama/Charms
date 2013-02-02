#ifndef DODAWANIE_H
#define DODAWANIE_H
#include "wyrazeniedwuargumentowe.h"

class Dodawanie : public WyrazenieDwuargumentowe
{   
public:
    Dodawanie(Wyrazenie* a,Wyrazenie* b);
    double oblicz(double x);
};

#endif // DODAWANIE_H
