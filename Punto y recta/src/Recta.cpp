#include <math.h>

#include "RectaException.h"
#include "Recta.h"


Recta::Recta(const Punto &p1, const Punto &p2)
{
    this->_p1 = p1;
    this->_p2 = p2;
}


/// cout << r1
ostream& operator<<(ostream& salida, const Recta& obj)
{
    salida << "[" << obj._p1 << ", " << obj._p2 << "]";

    return salida;
}


/// r1 - p
double Recta::operator-(const Punto& obj)const
{
    double res;
    res = fabs( ((this->_p2.getY() - this->_p1.getY()) * obj.getX())
    - ((this->_p2.getX() - this->_p1.getX()) * obj.getY())
    + this->_p2.getX() * this->_p1.getY() - this->_p2.getY() * this->_p1.getX() )
    / sqrt(pow(this->_p2.getY() - this->_p1.getY(), 2) + pow(this->_p2.getX() - this->_p1.getX(), 2));

    return res;
}


/// r1 && r2
Punto Recta::operator&&(const Recta& obj) const
{
    Punto p;
    double x,
           y,
           denom;

    denom = ( (this->_p1.getX() - this->_p2.getX())*(obj._p1.getY() - obj._p2.getY())
            - (this->_p1.getY() - this->_p2.getY())*(obj._p1.getX() - obj._p2.getX()) );

    if(denom == 0)
    {
        throw RectaException();
    }


    x = ( (this->_p1.getX()*this->_p2.getY() - this->_p1.getY()*this->_p2.getX())
           *(obj._p1.getX() - obj._p2.getX()) - (this->_p1.getX() - this->_p2.getX())
           *(obj._p1.getX()*obj._p2.getY() - obj._p1.getY()*obj._p2.getX()) )
           / denom;


    y = ( (this->_p1.getX()*this->_p2.getY() - this->_p1.getY()*this->_p2.getX())
           * (obj._p1.getY() - obj._p2.getY()) - (this->_p1.getY()- this->_p2.getY())
           * (obj._p1.getX()*obj._p2.getY() - obj._p1.getY()*obj._p2.getX())  )
           / denom;

    p.setX(x);
    p.setY(y);

    return p;
}




