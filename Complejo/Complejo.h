#ifndef COMPLEJO_H_INCLUDED
#define COMPLEJO_H_INCLUDED
#include <iostream>

using namespace std;

class Complejo
{
private:
    float _real;
    float _imag;

public:
    Complejo(float re = 0, float im = 0);

    float getReal()const;
    void setReal(float re);

    friend void mostrarValoresFriend(const Complejo& obj); // funcion amiga: funcion que no pertenece a la clase pero puede acceder a sus miembros privados

    Complejo operator+(const Complejo& obj)const;

    friend Complejo operator+(const float& f, const Complejo& obj);

    friend ostream& operator<<(ostream& salida, const Complejo& obj);

    friend istream& operator>>(istream& entrada, Complejo& obj);
};

#endif // COMPLEJO_H_INCLUDED
