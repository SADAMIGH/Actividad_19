#include <iostream>
#include "videojuego.h"
#include <vector>
#include "MenuAldeanos.h"

using namespace std;

int main() {
    Videojuego v;
    string op = "00";
    while (op != "14")
    {
        cout << "01) Ingresar Nombre de Usuario" << endl;
        cout << "02) Agregar Civilizacion" << endl;
        cout << "03) Insertar" << endl;
        cout << "04) Inicializar" << endl;
        cout << "05) Primera Civilizacion" << endl;
        cout << "06) Ultima Civilizacion" << endl;
        cout << "07) Ordenar" << endl;
        cout << "08) Eliminar" << endl;
        cout << "09) Buscar y mostrar menu de Aldeanos" << endl;
        cout << "10) Modificar" << endl;
        cout << "11) Resumen" << endl;
        cout << "12) Respaldar Todo" << endl;
        cout << "13) Recuperar" << endl;
        cout << "14) Salir" << endl;

        cout << "Opcion: ";
        cin>>op;
        cin.ignore();
        cout << endl << endl;

        if (op == "1"){
        cout << "Nombre de Usuario: " << endl;
        string g;
        getline(cin, g);
        v.setUsuario(g);
        }
        else if (op == "2" ) {
            Civilizacion p;
            cin >> p;
            v.agregarCivilizacion(p); 
            cin.ignore();
        }
        else if (op == "3") {
            Civilizacion p;
            cin >> p;

            size_t pos;
            cout << "posición: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posición no válida" << endl;
            }
            else {
                v.insertar(p, pos);
            }
        } 
        else if (op == "4") {
            Civilizacion p;
            cin >> p;

            size_t n;
            cout << "n: ";
            cin >> n; cin.ignore();

            v.inicializar(p, n);
        }
        else if (op == "5") {
        v.primeraCivilizacion(); 
        cout << endl << endl;
        }
        else if (op == "6") {
        v.ultimaCivilizacion(); 
         cout << endl << endl;     
        }
        else if (op == "7") {
        cout<<"Ordenar por..."<<endl;
        cout<<"01) Nombre"<<endl;
        cout<<"02) Ubicacion X"<<endl;
        cout<<"03) Ubicacion Y"<<endl;
        cout<<"04) Puntuacion"<<endl;
        cout<<"Opcion: "; 
        cin>>op;
        cin.ignore();
        cout << endl << endl;
        if (op == "1") {
            v.ordenar();
        }
        else if (op == "2") {
            v.ordenarX();
        }
        else if (op == "3") {
            v.ordenarY();
        }
        else if (op == "4") {
            v.ordenarPuntuacion();
        }
        }
        else if (op == "8") {
            size_t pos;
            cout << "posicion: ";
            cin >> pos; cin.ignore();

            if (pos >= v.size()) {
                cout << "Posicion no valida" << endl;
            }
            else {
                v.eliminar(pos);
            }
        }
        else if (op == "9") {
        Civilizacion p;
        cin >> p; cin.ignore();
        Civilizacion *ptr = v.buscar(p);
        if (ptr == nullptr) {
            cout << "Civilizacion no encontrada" << endl;
        }
        else {
            cout << "Civilizacion encontrada" << endl;
            cout << *ptr << endl;
        menu(*ptr);
        }
        }
        else if (op == "10") {
            Civilizacion p;
            cin >> p; cin.ignore();
            Civilizacion *ptr = v.buscar(p);
            if (ptr == nullptr) {
                cout << "no encontrado" << endl << endl;
            }
            else {
                cout << "\nCivilizacion encontrada:\n\n";
                cout << *ptr << endl;

            int e = 0;
            do{
            cout << "Modificar..." << endl;
            cout << "1) Nombre" << endl;
            cout << "2) Ubicacion X" << endl;
            cout << "3) Ubicacion Y" << endl;
            cout << "4) Puntuacion" << endl;
            cout << "5) Salir" << endl;
            cout << "Opcion: ";
            cin >> e;
            cin.ignore();
            cout << endl << endl;
            if(e == 1 ){ 
            string nombre;
            cout << "Ingresa el nuevo Nombre: " ;
            cin>>nombre;
            ptr->setNombre(nombre); 
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
            }
            else if(e == 2 ){
            float x;
            cout << "Ingresa la nueva ubicacion en X: " ;
            cin>>x;
            ptr->setX(x);
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
            }
            else if(e == 3 ){
            float y;
            cout << "Ingresa la nueva ubicacion en Y: " ;
            cin>>y;
            ptr->setX(y);   
            cout << "Resultado:" << endl;
            cout << *ptr << endl; 
            }
            else if(e == 4 ){
            int p;
            cout << "Ingresa la nueva Puntuacion: " ;
            cin>>p;
            ptr->setPuntuacion(p);
            cout << "Resultado:" << endl;
            cout << *ptr << endl;
                    }
                }while(e != 5);
            }
        }
        else if (op == "11") {
            v.mostrar();
            cout << endl;
        }
        else if (op == "12") {
        v.respaldar();
        }
        else if (op == "13") {
        v.recuperar();   
        }

    }
    return 0;
}