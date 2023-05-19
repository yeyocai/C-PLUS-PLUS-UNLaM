#ifndef PUNTO_H
#define PUNTO_H

#include <iostream>

using namespace std;


class Punto
{
private:
    double _x;
    double _y;

public:
    Punto(double x = 0, double y = 0);

    double getX()const;
    double getY()const;
    void setX(double v);
    void setY(double v);

    friend ostream& operator<<(ostream& salida, const Punto& obj);
};


#endif // PUNTO_H

