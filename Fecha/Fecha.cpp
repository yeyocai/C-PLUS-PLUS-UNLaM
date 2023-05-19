#include <iostream>
#include <time.h>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
    time_t x = time(0); /// funcion time: retorna la fecha actual en forma de milisegundos desde una cierta fecha base (del tipo time_t) si le paso cero o puntero NULL
    struct tm y; /// struct tm: tiene campos de la fecha base, el nombre de la estructura aca es y
    y = *localtime(&x); /// lo convierto a la fecha actual con la funcion localtime

    _dia = y.tm_mday; /// le asigno el campo del dia
    _mes = y.tm_mon + 1; /// Enero es 0, por eso le sumo 1
    _anio = y.tm_year + 1900; /// me devuelve la cantidad de años que pasaron desde 1900, por eso se lo sumo
}

Fecha::Fecha(int dia, int mes, int anio)
: _dia(dia), _mes(mes), _anio(anio)
{
    if(!esFechaValida(*this))
    {
        cout << "La fecha ingresada es invalida." << endl;
        this->_dia = 0;
        this->_mes = 0;
        this->_anio = 0;
    }
}


bool Fecha::esBisiesto(const int a)const
{
    return (a%4==0 && a%100!=0)||a%400==0;
}


int Fecha::cantDiasMes(const int m, const int a)const
{
    static int cdm[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(m==2 && esBisiesto(a))
        return 29;
    return cdm[m-1];
}


bool Fecha::esFechaValida(const Fecha & f)const
{
    if(f._anio >= 1600)
        if(f._mes >= 1 && f._mes <= 12)
            if(f._dia >= 1 && f._dia <= cantDiasMes(f._mes, f._anio))
                return true;
    return false;
}


/// fecha1++;
Fecha Fecha::operator++(int) /// pos incremento
{
    Fecha f(this->_dia, this->_mes, this->_anio);
    int cdma = cantDiasMes(this->_mes, this->_anio);
    this->_dia++;
    if(this->_dia > cdma)
    {
        this->_dia = 1;
        this->_mes++;
        if(this->_mes > 12)
        {
            this->_mes = 1;
            this->_anio++;
        }
    }
    return f;
}


/// bool comparacion1 = fecha1 == fecha3;
bool Fecha::operator==(const Fecha & f)const
{
    if(this->_anio == f._anio && this->_mes == f._mes && this->_dia == f._dia)
        return true;
    return false;
}


/// fecha1 += 4;
Fecha& Fecha::operator+=(const int & i) /// retorno el objeto llamador por si hay que asignar el resultado a algo
{
    int cd = i;
    int cdma = cantDiasMes(this->_mes, this->_anio); /// cdma - cantidad de dias del mes actual
    int cdhmp = cdma - this->_dia + 1;      /// cdhmp - cantidad de dias hasta el mes proximo, me paro en el primer dia del mes proximo
    while(cd >= cdhmp)
    {
        cd -= cdhmp;
        this->_dia = 1;
        this->_mes++;
        if(this->_mes > 12)
        {
            this->_mes = 1;
            this->_anio++;
        }
        cdhmp = cantDiasMes(this->_mes, this->_anio);
    }
    this->_dia += cd;
    return *this;
}


/// --fecha5;
Fecha& Fecha::operator--() /// pre decremento
{
    this->_dia--;
    if(this->_dia == 0)
    {
        if(this->_mes == 1)
        {
            this->_dia = 31;
            this->_mes = 12;
            this->_anio--;
        }
        else
        {
            this->_dia = cantDiasMes(this->_mes - 1, this->_anio);
            this->_mes--;
        }
    }
    return *this;
}


/// cout << fecha1;
ostream& operator<<(ostream & salida, const Fecha & f)
{
    salida << f._dia << '/' << f._mes << '/' << f._anio << endl;
    return salida;
}


/// cin >> fecha5;
istream& operator>>(istream & entrada, Fecha & f)
{
    char c1, c2;
    entrada >> f._dia >> c1 >> f._mes >> c2 >> f._anio;

    if(!f.esFechaValida(f))
    {
        cout << "La fecha ingresada es invalida." << endl;
        f._dia = 0;
        f._mes = 0;
        f._anio = 0;
    }

    return entrada;
}


