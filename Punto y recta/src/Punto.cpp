#include <math.h>
#include "Punto.h"

Punto::Punto(double x, double y)
{
    this->_x = x;
    this->_y = y;
}


double Punto::getX() const
{
    return _x;
}


double Punto::getY() const
{
    return _y;
}


void Punto::setX(double v)
{
    this->_x = v;
}


void Punto::setY(double v)
{
    this->_y = v;
}

/// cout << p
ostream& operator<<(ostream& salida, const Punto& obj)
{
    salida << "(" << obj.getX() << ", " << obj.getY() << ")";
    return salida;
}




