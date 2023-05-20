#include <iostream>
#include "Cadena.h"

using namespace std;

int main()
{
    Cadena c1("Hola");
    cout << "c1: " << c1 << endl;

    Cadena c2(c1);
    cout << "c2: " << c2 << endl;

    Cadena c3;          /// en memoria dinamica debo definir el constructor de copia cuando un operador devuelve un nuevo objeto
    c3 = c1 + " Mundo"; /// en memoria dinamica debo definir el operador de asignacion(=)
    cout << "c3: " << c3 << endl;

    cout << "Resumen:" << endl;
    cout << "c1: " << c1 << endl;
    cout << "c2: " << c2 << endl;
    cout << "c3: " << c3 << endl;

    return 0;
}
