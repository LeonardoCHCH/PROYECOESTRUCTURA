//
// Created by leona on 9/29/2024.
//

#ifndef UNTITLED4_LIBRERIA_H
#define UNTITLED4_LIBRERIA_H

#include "iostream"
#include "string"
#include "vector"
#include "limits"

using namespace std;

struct camion {
    int peso = 700;
    int region;
    camion* siguiente;
    camion* anterior;
};

camion* primerCamion;
camion* ultimoCamion;

struct  articulo {
    string nombre;
    int peso;
    int region;
    articulo* siguiente;
    articulo* anterior;
};

articulo* primerArticulo;
articulo* ultimoArticulo;

struct region {
    int region;
    string nombre;
};
region primerRegion = {1, "Norte"};
region segundaRegion = {2, "Centro"};
region terceraRegion = {3, "Sur"};
string validarString() {
    string texto;
    while (true) {
        getline(cin, texto);
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un dato válido: " << endl;
        } else if (texto.length() == 0) {
            cout << "Ingrese un dato válido: " << endl;
        } else {
            break;
        }
    }
    return texto;
}

int validarNumero(string mensaje) {
    int numero;
    cout << mensaje;
    while (true) {
        cin >> numero;
        if (cin.fail() || numero < 0 || numero > 700) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un dato valido: " << endl;
        } else {
            return numero;
        }
    }
}
int validar123(string mensaje) {
    int numero;
    cout << mensaje;
    while (true) {
        cin >> numero;
        if (cin.fail() || numero < 1 || numero > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ingrese un dato valido: " << endl;
        } else {
            return numero;
        }
    }
}
void crearArticulo() {
    articulo *nuevo = new articulo();
    cout << "Ingrese el nombre del articulo: ";
    nuevo->nombre = validarString();
    nuevo->peso = validarNumero("Ingrese el peso del articulo: ");
    nuevo->region = validar123("Ingrese la region del articulo: ");
    if (primerArticulo == nullptr) {
        primerArticulo = nuevo;
        ultimoArticulo = nuevo;
    } else {
        ultimoArticulo->siguiente = nuevo;
        nuevo->anterior = ultimoArticulo;
        ultimoArticulo = nuevo;
    }
}
void crearCamion(int region) {
    camion *nuevo = new camion();
    nuevo->region = region;
    if (primerCamion == nullptr) {
        primerCamion = nuevo;
        ultimoCamion = nuevo;
    } else {
        ultimoCamion->siguiente = nuevo;
        ultimoCamion = nuevo;
    }
}

void mostrarRegiones() {
    cout << "1. " << primerRegion.nombre << endl;
    cout << "2. " << segundaRegion.nombre << endl;
    cout << "3. " << terceraRegion.nombre << endl;
}
void crearCamiones() {
    crearCamion(primerRegion.region);
    crearCamion(segundaRegion.region);
    crearCamion(terceraRegion.region);
}
void mostrarArticulos() {
    articulo* actual = primerArticulo;
    if (actual == nullptr) {
        cout << "No hay articulos" << endl;
        return;
    }
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << " Peso: " << actual->peso << endl;
        actual = actual->siguiente;
    }
}

void ordenarArticulosEnCamiones(){
    articulo* actual = primerArticulo;
    camion* actualCamion = primerCamion;
    while (actual != nullptr) {
        if (actual->region == actualCamion->region) {
            if (actual->peso <= actualCamion->peso) {
                cout << "El articulo " << actual->nombre << " fue cargado en el camion de la region " << actual->region << endl;
                actual = actual->siguiente;
            } else {
                cout << "El articulo " << actual->nombre << " no cabe en el camion de la region " << actual->region << endl;
                crearCamion(actual->region);
                cout << "Se ha creado un nuevo camion para la region " << actual->region << endl;
                actualCamion = actualCamion->siguiente;
            }
        } else {
            actualCamion = actualCamion->siguiente;
        }
    }
}
#endif //UNTITLED4_LIBRERIA_H