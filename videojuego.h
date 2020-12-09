#ifndef VIDEOJUEGO_H
#define VIDEOJUEGO_H

#include <iostream>
#include "civilizacion.h"
#include <vector>
using namespace std;

class Videojuego
{
    string usuario;
    vector<Civilizacion> civilizaciones;
public:
    Videojuego();
    Videojuego(const string &usuario);
    void setUsuario(const string &u);
    string getUsuario();
    void agregarCivilizacion(const Civilizacion &c);
    void mostrar();
    void insertar(const Civilizacion &c, size_t pos);
    size_t size();
    void inicializar(const Civilizacion &c, size_t n);
    void primeraCivilizacion();
    void ultimaCivilizacion();
    void eliminar(size_t pos);
    void ordenar(); 
    void ordenarX();
    void ordenarY();
    void ordenarPuntuacion();
    Civilizacion* buscar(const Civilizacion &c);
    void respaldar();
    void recuperar();

    friend Videojuego& operator<<(Videojuego &v, const Civilizacion &c)
    {
        v.agregarCivilizacion(c);
        return v;
    }
};

#endif