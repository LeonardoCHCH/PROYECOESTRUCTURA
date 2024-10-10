#include <iostream>
#include "libreria.h"

using namespace std;


void menu() {
    int opcion;
    cout << "Bienvenido al sistema de transporte de productos" << endl;
    do {
        cout << "1. Agregar articulo" << endl;
        cout << "2. Mostrar articulos" << endl;
        cout << "3. Agregar region" << endl;
        cout << "4. Comenzar transporte de productos" << endl;
        cout << "5. Salir" << endl;
        opcion = validarNumero("Ingrese una opción: ");
        switch (opcion) {
            case 1:
                cout << "Agregando articulo" << endl;
                crearArticulo();
                break;
            case 2:
                cout << "Mostrando articulos" << endl;\
                mostrarArticulos();
                break;
            case 3:
                cout << "Agregando region" << endl;
                break;
            case 4:
                cout << "Comenzando transporte de productos" << endl;
                ordenarArticulosEnCamiones();
                break;
            case 5:
                cout << "Saliendo del sistema" << endl;
                break;
            default:
                cout << "Opción no válida" << endl;
                break;
        }

}while (opcion != 5);
}

int main() {
    mostrarRegiones();
    crearCamiones();
    menu();
    return 0;
}