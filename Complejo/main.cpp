// Hacer funcionar el siguiente main():

#include <iostream>
#include "Complejo.h"

using namespace std;

int main()
{
    Complejo c1;
    mostrarValoresFriend(c1);

    Complejo c2(1.1, 2.2);
    mostrarValoresFriend(c2);

    Complejo c3(c2);
    mostrarValoresFriend(c3);
    cout << c3.getReal() << endl;
    c3.setReal(4.4);
    cout << c3.getReal() << endl;
    mostrarValoresFriend(c3);

    cout << "C1: ";
    mostrarValoresFriend(c1);
    cout << "C2: ";
    mostrarValoresFriend(c2);
    cout << "Operador c1 = c2" << endl;
    c1 = c2;
    cout << "C1: ";
    mostrarValoresFriend(c1);
    cout << "C2: ";
    mostrarValoresFriend(c2);

    cout << "C1: ";
    mostrarValoresFriend(c1);
    cout << "C2: ";
    mostrarValoresFriend(c2);
    cout << "Operador c3 = c1 + c2" << endl;
    c3 = c1 + c2;
    mostrarValoresFriend(c3);

    cout << "Ingrese numero: real imag" << endl;
    cin >> c3;
    cout << "c3: " << c3 << endl;
    cout << endl;

    Complejo c4(0, 0);
    c4 = 7 + c3;
    cout << "c4: " << c4 << endl;

    Complejo c5(0, 0);
    c5 = c4 + 2;
    cout << "c5: " << c5 << endl;

    return 0;
}
