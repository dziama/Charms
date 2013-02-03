#ifndef WYRAZENIEDWUARGUMENTOWE_H
#define WYRAZENIEDWUARGUMENTOWE_H
#include "wyrazenie.h"

class WyrazenieDwuargumentowe : public Wyrazenie
{
protected:
    Wyrazenie* wyr1;
    Wyrazenie* wyr2;
public:
    WyrazenieDwuargumentowe(Wyrazenie* wyr1, Wyrazenie* wyr2);
};

#endif // WYRAZENIEDWUARGUMENTOWE_H
