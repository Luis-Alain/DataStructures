/*Escribir un Programa que separe los números pares e impares que se encuentran en los Nodos
de una Lista enlazada. Se debe generar dos nuevas listas una para los pares y otra para los impares*/

#include <iostream>
using namespace std;

struct Nodo {
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

// Función para separar los números pares e impares en dos listas enlazadas
void separarParesImpares(Nodo *&lista, Nodo *&pares, Nodo *&impares)
{
    if (lista == nullptr)
    {
        // Lista vacía
        return;
    }

    Nodo *actual = lista;
    while (actual != nullptr)
    {
        Nodo *siguiente = actual->siguiente;

        // Separar el nodo de la lista original
        actual->siguiente = nullptr;

        if (actual->dato % 2 == 0)
        {
            // Es par, agregar a la lista de pares
            if (pares == nullptr)
            {
                pares = actual;
            }
            else
            {
                actual->siguiente = pares;
                pares = actual;
            }
        }
        else
        {
            // Es impar, agregar a la lista de impares
            if (impares == nullptr)
            {
                impares = actual;
            }
            else
            {
                actual->siguiente = impares;
                impares = actual;
            }
        }

        actual = siguiente;
    }
    // Actualizar la lista original a nullptr ya que los nodos se han movido a las listas de pares e impares
    lista = nullptr;
}

int main()
{
    // Crear una lista de ejemplo
    Nodo *lista = new Nodo(1);
    lista->siguiente = new Nodo(2);
    lista->siguiente->siguiente = new Nodo(3);
    lista->siguiente->siguiente->siguiente = new Nodo(4);

    cout << "Lista original:" << endl;
    imprimirLista(lista);

    // Crear listas para pares e impares
    Nodo *pares = nullptr;
    Nodo *impares = nullptr;

    // Llamar a la función para separar pares e impares
    separarParesImpares(lista, pares, impares);

    cout << "\nLista de pares:" << endl;
    imprimirLista(pares);

    cout << "\nLista de impares:" << endl;
    imprimirLista(impares);

    // Liberar la memoria
    while (pares != nullptr)
    {
        Nodo *siguiente = pares->siguiente;
        delete pares;
        pares = siguiente;
    }

    while (impares != nullptr)
    {
        Nodo *siguiente = impares->siguiente;
        delete impares;
        impares = siguiente;
    }

    return 0;
}
