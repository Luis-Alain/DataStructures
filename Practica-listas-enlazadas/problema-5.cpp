/*Desarrollar un Programa que Muestre por pantalla la Posición de un Nodo Especifico (el dato se
debe pedir por Teclado).*/

#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

Nodo *buscarElemento(Nodo *inicio, int elemento) {
    Nodo *actual = inicio;

    while (actual != nullptr) {
        if (actual->dato == elemento) {
            return actual;
        }
        actual = actual->siguiente;
    }

    return nullptr; 
}

int main() {
    Nodo *nodo1 = new Nodo{1, nullptr};
    Nodo *nodo2 = new Nodo{2, nullptr};
    Nodo *nodo3 = new Nodo{3, nullptr};

    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;

    cout << "Introduce el elemento que quieres buscar: ";
    int elementoBuscado;
    cin >> elementoBuscado;

    Nodo *resultado = buscarElemento(nodo1, elementoBuscado);

    if (resultado != nullptr) {
        cout << "Elemento encontrado en la lista." << endl;
    } else {
        cout << "Elemento no encontrado en la lista." << endl;
    }

    return 0;
}
