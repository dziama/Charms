#ifndef WYRAZENIEJEDNOARGUMENTOWE_H
#define WYRAZENIEJEDNOARGUMENTOWE_H
#include "wyrazenie.h"

class WyrazenieJednoargumentowe : public Wyrazenie
{
protected:
    Wyrazenie* wyr1;

public:
    WyrazenieJednoargumentowe(Wyrazenie* wyr1);
};

#endif // WYRAZENIEJEDNOARGUMENTOWE_H
