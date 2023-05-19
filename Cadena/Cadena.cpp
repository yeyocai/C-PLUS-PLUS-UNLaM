#include <string.h>
#include "Cadena.h"

Cadena::Cadena()
{
    _cad = new char[1]; /// new me devuelve la direccion de memoria del bloque de memoria que reservo, no necesito castear puntero
    *_cad = '\0';
}


Cadena::Cadena(const char * cad) /// pido memoria dinamica porque no se cuanto va a ocupar esa cadena
{
    _cad = new char[strlen(cad)+1]; /// strlen no cuenta el '\0'
    strcpy(_cad, cad);
}


/// Cadena c2(c1);
Cadena::Cadena(const Cadena & c) /// constructor de copia: porque estoy trabajando con mem dinamica y tengo un operador que me devuelve un objeto nuevo
{                                  /// recibe un objeto y me genera una copia identica e independiente
    this->_cad = new char[strlen(c._cad)+1];
	strcpy(this->_cad, c._cad);
}


Cadena::~Cadena() /// hago destructor si constructor/es tiene/n memoria dinamica (puedo tener varios ctores pero solo necesito un dtor)
{
    delete [] _cad; /// libero memoria
}


/// c1 + " Mundo"; c1: this - " Mundo": cad
Cadena Cadena::operator+(const char * cad)const
{
    Cadena aux;
    aux._cad = new char[strlen(this->_cad) + strlen(cad) + 1];
    strcpy(aux._cad, this->_cad);
    strcat(aux._cad, cad);
    return aux;
}


/// c3 = c1;
Cadena& Cadena::operator=(const Cadena & c)
{
    if(this == &c) /// por si es el mismo: c3 = c3
        return *this;

    int longCad = strlen(c._cad);
    int longThis = strlen(this->_cad);

    if(longCad != longThis)
    {
        delete [] this->_cad; /// libero lo que hay en esa direccion de memoria
        this->_cad = new char[longCad + 1];
    }
    strcpy(this->_cad, c._cad);

    return *this; /// retorna el contenido del puntero this por referencia, por si hay que concatenar (this: puntero - *this(contenido del puntero (el objeto))
}


/// cout << c1
ostream& operator<<(ostream & salida, const Cadena & c)
{
    salida << c._cad;
    return salida;
}
