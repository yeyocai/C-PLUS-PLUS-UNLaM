#include <iostream>
#include "Complejo.h"

using namespace std;

Complejo::Complejo(float re, float im)
{
    _real = re;
    _imag = im;
}


float Complejo::getReal()const
{
    return this->_real;
}


void Complejo::setReal(float re)
{
    this->_real = re;
}


void mostrarValoresFriend(const Complejo &obj)
{
    cout << "(" << obj._real << "," << obj._imag << ")" << endl;
}


// c3 = c1 + c2;
Complejo Complejo::operator+(const Complejo& obj) const
{
    Complejo aux;
    aux._real = this->_real + obj._real;
    aux._imag = this->_imag + obj._imag;
    return aux;
}


// 7 + c1; - 7 (objeto llamador) no es miembro de la clase - uso operador amigo
Complejo operator+(const float& f, const Complejo& obj)
{
    Complejo aux(obj._real + f, obj._imag); // por definicion solo se suma a parte real
    return aux;
}


// cout << "c5: " << c5 << endl; -> cout << c5;
ostream& operator<<(ostream& salida, const Complejo& obj)
{
    salida << "(" << obj._real << ";" << obj._imag << ")";
    return salida; // para encadenar
}


// cin >> c3;
istream& operator>>(istream& entrada, Complejo& obj)
{
    //cout << "Ingrese parte real: ";
    entrada >> obj._real; // se asigna por orden
    //cout << "Ingrese parte imaginaria: ";
    entrada >> obj._imag;
    return entrada;
}
