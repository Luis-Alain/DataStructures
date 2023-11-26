/*Hemos visto inserciones en orden y al final de la lista. Supongamos, que los nodos tienen una
posición relativa 0,1, ...n − 1, donde n es el número de elementos en la lista. Implemente una
función que inserte un dato en una posición dada. Si la posición es 0 tiene que insertarlo al inicio.
El último nodo está en la posición n − 1, por lo tanto, si se le pide insertar en n − 1, el dato debe ser
insertado antes del último y el ´ultimo avanza. Note que es posible insertar un dato en n, eso haría
que el dato se inserte al final de todos.*/

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

// Función para insertar un dato en una posición dada en la lista enlazada
void insertarEnPosicion(Nodo *&inicio, int dato, int posicion) {
    Nodo *nuevoNodo = new Nodo(dato);

    if (posicion <= 0) {
        // Caso especial: Insertar al inicio
        nuevoNodo->siguiente = inicio;
        inicio = nuevoNodo;
    } else {
        Nodo *actual = inicio;
        int i = 0;

        while (actual != nullptr && i < posicion - 1) {
            actual = actual->siguiente;
            i++;
        }

        if (actual != nullptr) {
            // Insertar el nuevo nodo después de 'actual'
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        } else {
            // La posición está más allá del final de la lista, insertar al final
            Nodo *ultimo = inicio;
            while (ultimo->siguiente != nullptr) {
                ultimo = ultimo->siguiente;
            }

            ultimo->siguiente = nuevoNodo;
        }
    }
}

int main() {
    // Crear una lista de ejemplo
    Nodo *lista = nullptr;

    // Insertar datos en posiciones específicas
    insertarEnPosicion(lista, 1, 0); // Insertar al inicio (posición 0)
    insertarEnPosicion(lista, 3, 1); // Insertar en la posición 1
    insertarEnPosicion(lista, 2, 1); // Insertar en la posición 1 (desplaza el 3)
    insertarEnPosicion(lista, 4, 3); // Insertar en la posición 3 (antes del último)

    cout << "Lista después de insertar en posiciones específicas:" << endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr) {
        Nodo *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}
