/*Desarrollar un Programa que devuelva la Multiplicación de los Números introducidos en los
Nodos de la Lista enlazada.*/

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

int multiplicarNodos(Nodo *cabeza){
    int producto = 1;

    Nodo *actual = cabeza;
    while (actual != nullptr) {
        producto *= actual->dato;
        actual = actual->siguiente;
    }

    return producto;
}

int main() {
    // Crear una lista enlazada simple
    Nodo *nodo1 = new Nodo{1, nullptr};
    Nodo *nodo2 = new Nodo{2, nullptr};
    Nodo *nodo3 = new Nodo{3, nullptr};

    // Enlazar los nodos
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;

    int productoNodos = multiplicarNodos(nodo1);
    cout << "Multiplicacion de los nodos = " << productoNodos << endl;

}