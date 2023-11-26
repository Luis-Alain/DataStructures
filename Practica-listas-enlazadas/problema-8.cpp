/*Escribir un Programa que permita eliminar el penúltimo Nodo de una Lista Enlazada.*/

#include <iostream>
using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

// Función para imprimir la lista
void imprimirLista(Nodo *inicio)
{
    Nodo *actual = inicio;
    while (actual != nullptr)
    {
        cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    cout << endl;
}

void eliminarPenultimoNodo(Nodo *&inicio){
    if (inicio == nullptr || inicio->siguiente == nullptr || inicio->siguiente->siguiente == nullptr) {
        // Lista vacía o con menos de dos nodos, no se puede eliminar el penúltimo nodo
        return;
    }

    Nodo *actual = inicio;

    // Moverse hasta el nodo que precede al último nodo
    while (actual->siguiente->siguiente != nullptr) {
        actual = actual->siguiente;
    }

    // Almacenar el penúltimo nodo
    Nodo *penultimo = actual;

    // Actualizar el puntero del penúltimo nodo para omitir el último nodo
    penultimo->siguiente = nullptr;

    // Liberar memoria del último nodo
    delete actual->siguiente;
}

int main(){
    // Crear una lista de ejemplo  
    Nodo *lista = new Nodo(1);
    lista->siguiente = new Nodo(2);
    lista->siguiente->siguiente = new Nodo(3);
    lista->siguiente->siguiente->siguiente = new Nodo(4);

    cout << "Lista original:" << endl;
    imprimirLista(lista);

    // Llamar a la función para eliminar el penúltimo nodo
    eliminarPenultimoNodo(lista);

    cout << "\nLista después de eliminar el penúltimo nodo:" << endl;
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
