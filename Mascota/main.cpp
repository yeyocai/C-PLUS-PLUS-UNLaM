#include <iostream>
#include <string>
#include "Mascota.h"

using namespace std;

int main()
{
    Perro pluto("Pluto");
    cout << "Perro: " << pluto.getNombre() << endl;
    pluto.dormir();
    pluto.comer();
    pluto.moverCola();

    Gato garfield("Garfield");
    cout << "Gato: " << garfield.getNombre() << endl;
    garfield.dormir();
    garfield.comer();
    garfield.jugarConLaser();

    return 0;
}
