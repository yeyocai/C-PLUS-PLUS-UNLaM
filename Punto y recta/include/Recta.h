#ifndef RECTA_H
#define RECTA_H

#include <iostream>

#include "Punto.h"

using namespace std;


class Recta
{
private:
    Punto _p1;
    Punto _p2;

public:
    Recta(const Punto& p1, const Punto& p2);

    double operator-(const Punto& obj)const;

    Punto operator&&(const Recta& obj)const;

    friend ostream& operator<<(ostream& salida, const Recta& obj);
};


#endif // RECTA_H

