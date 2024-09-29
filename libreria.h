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
    string region;
};

camion* primerCamion;
camion* ultimoCamion;

struct  articulo {
    string nombre;
    int peso;
    articulo* siguiente;
    articulo* anterior;
};

articulo* primerArticulo;
articulo* ultimoArticulo;

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
        if (cin.fail()) {
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
    if (primerArticulo == nullptr) {
        primerArticulo = nuevo;
        ultimoArticulo = nuevo;
    } else {
        ultimoArticulo->siguiente = nuevo;
        nuevo->anterior = ultimoArticulo;
        ultimoArticulo = nuevo;
    }
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
#endif //UNTITLED4_LIBRERIA_H