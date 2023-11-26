/*Desarrollar un Programa que dada una Lista Enlazada ordene los Nodos en forma Ascendente.*/

#include <iostream>

using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para imprimir la lista
void imprimirLista(Nodo *inicio){
    Nodo *actual = inicio;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// Función para intercambiar los datos de dos nodos
void intercambiarDatos(Nodo *nodo1, Nodo *nodo2){
    int temp = nodo1->dato;
    nodo1->dato = nodo2->dato;
    nodo2->dato = temp;
}

// Función para ordenar la lista enlazada de manera ascendente
void ordenarLista(Nodo *inicio) {
    if (inicio == nullptr || inicio->siguiente == nullptr) {
        // La lista está vacía o tiene un solo nodo, ya está ordenada
        return;
    }

    bool intercambio; // Bandera para verificar si se realizó algún intercambio en la iteración
    Nodo *actual;
    Nodo *siguiente = nullptr;

    do {
        intercambio = false;
        actual = inicio;

        while (actual->siguiente != siguiente) {
            if (actual->dato > actual->siguiente->dato) {
                intercambiarDatos(actual, actual->siguiente);
                intercambio = true;
            }
            actual = actual->siguiente;
        }
        siguiente = actual;

    } while (intercambio);
}

int main(){
    // Crear una lista de ejemplo
    Nodo *lista = new Nodo(5);
    lista->siguiente = new Nodo(2);
    lista->siguiente->siguiente = new Nodo(8);
    lista->siguiente->siguiente->siguiente = new Nodo(1);

    cout << "Lista original:" << endl;
    imprimirLista(lista);

    // Llamar a la función para ordenar la lista
    ordenarLista(lista);

    cout << "\nLista ordenada de manera ascendente:" << endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr) {
        Nodo *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}