/*Implemente una función que inserte un dato de modo similar al insertar básico, al inicio o al
final de la lista. Pero ahora, no se debe permitir insertar datos repetidos, si un dato ya está
almacenado entonces la lista no varía.*/

#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para imprimir la lista
void imprimirLista(Nodo *inicio) {
    Nodo *actual = inicio;
    while (actual != nullptr) {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

// Función para insertar un dato al inicio o al final de la lista sin permitir datos repetidos
void insertarUnico(Nodo *&inicio, int dato, bool alInicio) {
    Nodo *nuevoNodo = new Nodo(dato);

    // Verificar si el dato ya está en la lista
    Nodo *actual = inicio;
    while (actual != nullptr) {
        if (actual->dato == dato) {
            // El dato ya está presente, no realizar la inserción
            delete nuevoNodo; // Liberar memoria del nuevo nodo
            return;
        }
        actual = actual->siguiente;
    }

    if (alInicio) {
        // Insertar al inicio
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
    } else {
        // Insertar al final
        if (inicio == nullptr) {
            // Caso especial: La lista está vacía
            inicio = nuevoNodo;
        } else {
            Nodo *ultimo = inicio;
            while (ultimo->siguiente != nullptr) {
                ultimo = ultimo->siguiente;
            }
            ultimo->siguiente = nuevoNodo;
        }
    }
}

int main(){
    // Crear una lista de ejemplo
    Nodo *lista = nullptr;

    // Insertar datos al inicio o al final sin permitir datos repetidos
    insertarUnico(lista, 1, true);
    insertarUnico(lista, 2, false);
    insertarUnico(lista, 3, true);
    insertarUnico(lista, 1, false); // Este dato ya está presente, no se insertará
    insertarUnico(lista, 4, true);
    insertarUnico(lista, 3, false); // Este dato ya está presente, no se insertará

    cout << "Lista después de insertar datos únicos al inicio o al final:" << endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr) {
        Nodo *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}
