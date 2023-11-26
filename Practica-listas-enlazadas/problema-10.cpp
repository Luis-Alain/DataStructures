/*Implementar una función para insertar un dato en orden descendente en una lista enlazada. Es
decir, el nodo que representa el dato debe ser insertado en una posición tal que al recorrer la lista
los nodos se recorran de mayor a menor respecto del dato.*/

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

// Función para insertar un dato en orden descendente en una lista enlazada
void insertarEnOrdenDescendente(Nodo *&inicio, int dato){
    Nodo *nuevoNodo = new Nodo(dato);

    if (inicio == nullptr || inicio->dato < dato) {
        // Caso especial: El nuevo nodo es el primero o debe ser el nuevo inicio
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
    } else {
        Nodo *actual = inicio;

        while (actual->siguiente != nullptr && actual->siguiente->dato > dato) {
            actual = actual->siguiente;
        }

        // Insertar el nuevo nodo después de 'actual'
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

int main(){
    // Crear una lista de ejemplo
    Nodo *lista = nullptr;

    // Insertar datos en orden descendente
    insertarEnOrdenDescendente(lista, 3);
    insertarEnOrdenDescendente(lista, 1);
    insertarEnOrdenDescendente(lista, 4);
    insertarEnOrdenDescendente(lista, 2);

    cout << "Lista después de insertar en orden descendente:" << endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr) {
        Nodo *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}
