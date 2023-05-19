#ifndef CADENA_H_INCLUDED
#define CADENA_H_INCLUDED
#include <iostream>

using namespace std;

class Cadena
{
private:
    char * _cad;

public:
    Cadena();
    Cadena(const char * cad);
    Cadena(const Cadena & c);
    ~Cadena();

    Cadena operator+(const char * cad)const;
    Cadena& operator=(const Cadena & c);

    friend ostream& operator<<(ostream & salida, const Cadena & c);

};
#endif // CADENA_H_INCLUDED
