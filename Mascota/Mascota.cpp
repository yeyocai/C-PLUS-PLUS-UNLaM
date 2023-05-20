#include <iostream>
#include <string>
#include "Mascota.h"

Mascota::Mascota(string nombre)
    : nombre(nombre)
{
}


void Mascota::dormir()
{
    cout << "Duermo por las proximas 8 horas." << endl;
}


void Mascota::comer()
{
    cout << "Como 150 gramos de alimento." << endl;
}


string Mascota::getNombre()
{
    return this->nombre;
}


///-----------------------------------------------------------------------


Perro::Perro(string nombre)
    : Mascota(nombre)
{
}


void Perro::moverCola()
{
    cout << "Perro: Muevo la cola." << endl;
}


void Perro::dormir()
{
    cout << "Perro: ";
    Mascota::dormir();
}


void Perro::comer()
{
    cout << "Perro: ";
    Mascota::comer();
}


/// -------------------------------------------------------------------------


Gato::Gato(string nombre)
    : Mascota(nombre)
{
}


void Gato::jugarConLaser()
{
    cout << "Gato: Juego con laser." << endl;
}


void Gato::dormir()
{
    cout << "Gato: ";
    Mascota::dormir();
}


void Gato::comer()
{
    cout << "Gato: ";
    Mascota::comer();
}
