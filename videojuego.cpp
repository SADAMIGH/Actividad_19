#include "videojuego.h"

Videojuego::Videojuego()
{

}

Videojuego::Videojuego(const string &usuario)               
{
    this->usuario = usuario;
}

void Videojuego::setUsuario(const string &u)
{
    usuario = u;
}

string Videojuego::getUsuario()
{
    return usuario;
}

void Videojuego::agregarCivilizacion(const Civilizacion &p)
{
    civilizaciones.push_back(p);
}

void Videojuego::mostrar()
{
    cout << left;
    cout << setw(20) << "Civilizacion";
    cout << setw(15) << "Ubicacion X";
    cout << setw(15) << "Ubicacion Y";
    cout << setw(15) << "Puntuacion";
    cout << endl;
    for (size_t i = 0; i < civilizaciones.size(); i++) {
        Civilizacion &p = civilizaciones[i];
        cout << p;
    }
}

void Videojuego::insertar(const Civilizacion &p, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, p);
}

size_t Videojuego::size()
{
    return civilizaciones.size();
}

void Videojuego::inicializar(const Civilizacion &p, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, p);
}

void Videojuego::primeraCivilizacion()
{
    cout<<civilizaciones.front();
}

void Videojuego::ultimaCivilizacion()
{
    cout<<civilizaciones.back();
}

void Videojuego::eliminar(size_t pos)
{
    civilizaciones.erase(civilizaciones.begin()+pos);
}

void Videojuego::ordenar()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion p1, Civilizacion p2){return p1.getNombre() < p2.getNombre();});
}
void Videojuego::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion p1, Civilizacion p2){return p1.getX() < p2.getX();});
}
void Videojuego::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion p1, Civilizacion p2){return p1.getY() < p2.getY();});
}
void Videojuego::ordenarPuntuacion()
{
    sort(civilizaciones.begin(), civilizaciones.end(),
    [](Civilizacion p1, Civilizacion p2){return p1.getPuntuacion() < p2.getPuntuacion();});
}

Civilizacion* Videojuego::buscar(const Civilizacion &p)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), p);

    if (it == civilizaciones.end()) {
        return nullptr;
    }
    else {
        return &(*it);
    }
}

void Videojuego::respaldar()
{
    ofstream archivo("civilizaciones.txt", ios::out);

    for (int i = 0; i < civilizaciones.size(); ++i) {
        Civilizacion &c = civilizaciones[i];
        archivo << c.getNombre() << endl;
        archivo << c.getX() << endl;
        archivo << c.getY() << endl;
        archivo << c.getPuntuacionRestar() << endl;
        c.respaldarAldeanos();
    }
    archivo.close();
}

void Videojuego::recuperar()
{
    ifstream archivo("civilizaciones.txt");
    if (archivo.is_open()) {
        string temp;
        int prov;
        Civilizacion c;

        while (true)
        {
            getline(archivo, temp); 
            if (archivo.eof()) {
                break;
            }
            c.setNombre(temp);

            getline(archivo, temp);
            prov = stoi(temp);
            c.setX(prov);

            getline(archivo, temp);
            prov = stoi(temp);
            c.setY(prov);

            getline(archivo, temp);
            prov = stoi(temp);
            c.setPuntuacion(prov);
            agregarCivilizacion(c);
        }
            
    }
    archivo.close();
}
