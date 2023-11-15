#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

void insertarNodoAlInicio(Nodo*& cabeza, int dato) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
} 

void insetarEnCualquierPosicion(Nodo*& cabeza, int dato, int posicion) {
    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->dato = dato;
    Nodo *actual = cabeza;

    for (int i = 0; i < posicion -1; i++) {
        if (actual == nullptr) {
            cout << "La lista no tiene suficientes elementos." << endl;
            return;
        }
        actual = actual->siguiente;
    }

    if (actual != nullptr) {
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    } else {
        cout << "La lista está vacía";
    }
}

int main() {
    Nodo *cabeza = nullptr;

    insertarNodoAlInicio(cabeza, 4);
    insertarNodoAlInicio(cabeza, 2);
    insertarNodoAlInicio(cabeza, 1);
    insetarEnCualquierPosicion(cabeza, 3, 2);

    Nodo *actual = cabeza;

    while (actual != nullptr) {
        cout << actual->dato << endl;
        actual = actual->siguiente;
    }

    // Liberar la memoria asignada para los nodos (no olvides hacerlo)
    while (cabeza != nullptr) {
        Nodo *temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}