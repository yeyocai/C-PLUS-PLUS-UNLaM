#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <iostream>

using namespace std;

class Fecha
{
private:
    int _dia;
    int _mes;
    int _anio;

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    bool esBisiesto(const int a)const;
    int cantDiasMes(const int m, const int a)const;
    bool esFechaValida(const Fecha & f)const;

    Fecha operator++(int);
    bool operator==(const Fecha & f)const;
    Fecha& operator+=(const int & i);
    Fecha& operator--();

    friend ostream& operator<<(ostream & salida, const Fecha & f);
    friend istream& operator>>(istream & entrada, Fecha & f);
};


#endif // FECHA_H_INCLUDED
