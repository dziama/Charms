#ifndef WYRAZENIE_H
#define WYRAZENIE_H

class Wyrazenie
{
public:
    virtual double oblicz(double x) = 0;
    virtual ~Wyrazenie() {}
};

#endif // WYRAZENIE_H
