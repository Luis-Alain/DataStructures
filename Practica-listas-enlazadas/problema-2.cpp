/*Escribir un Programa que devuelva el Número de Nodos de una Lista Enlazada.*/

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

int contarNodos(Nodo* cabeza){
    int contador = 0;

    Nodo* actual = cabeza;
    while(actual != nullptr) {
        contador++;
        actual = actual->siguiente;
    }

    return contador;
}

int main() {
    // Crear una lista enlazada simple
    Nodo *nodo1 = new Nodo{1, nullptr};
    Nodo *nodo2 = new Nodo{2, nullptr};
    Nodo *nodo3 = new Nodo{3, nullptr};

    // Enlazar los nodos
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;

    int cantidadNodos = contarNodos(nodo1);
    cout << "La lista tiene: " << cantidadNodos << " nodos";

    return 0;
}