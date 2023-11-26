/*Implementar una función para insertar un dato en orden ascendente en una lista enlazada. Es
decir, el nodo que representa el dato debe ser insertado en una posición tal que al recorrer la lista
los nodos se recorran de menor a mayor respecto del dato.*/

#include <iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para imprimir la lista
void imprimirLista(Nodo *cabeza){
    Nodo *actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

// Función para insertar un dato en orden ascendente en una lista enlazada
void insertarEnOrden(Nodo *&cabeza, int dato) {
    Nodo *nuevoNodo = new Nodo(dato);

    if (cabeza == nullptr || cabeza->dato > dato) {
        // Caso especial: El nuevo nodo es el primero o debe ser el nuevo cabeza
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    } else {
        Nodo *actual = cabeza;

        while (actual->siguiente != nullptr && actual->siguiente->dato < dato) {
            actual = actual->siguiente;
        }

        // Insertar el nuevo nodo después de 'actual'
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}

int main()
{
    // Crear una lista de ejemplo
    Nodo *lista = nullptr;

    // Insertar datos en orden ascendente
    insertarEnOrden(lista, 3);
    insertarEnOrden(lista, 1);
    insertarEnOrden(lista, 4);
    insertarEnOrden(lista, 2);

    std::cout << "Lista después de insertar en orden ascendente:" << std::endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr)
    {
        Nodo *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}
