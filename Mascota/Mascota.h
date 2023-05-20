#ifndef MASCOTA_H_INCLUDED
#define MASCOTA_H_INCLUDED
#include <string>

using namespace std;


class Mascota
{
private:
    string nombre;

public:
    Mascota(string nombre);
    void dormir();
    void comer();
    string getNombre();
};



class Perro : public Mascota
{
public:
    Perro(string nombre);
    void moverCola();
    void dormir();
    void comer();
};



class Gato : public Mascota
{
public:
    Gato(string nombre);
    void jugarConLaser();
    void dormir();
    void comer();
};


#endif // MASCOTA_H_INCLUDED
