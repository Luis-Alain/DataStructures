#include <iostream>

using namespace std;

struct NodoCircular {
    int dato;
    NodoCircular* siguiente;
};

void mostrarLista(NodoCircular* head) {
    NodoCircular* aux = head;

    do {
        cout << aux->dato << " -> ";
        aux = aux->siguiente;
    } while (aux != head);
    cout << endl;
}

void crearNodo(NodoCircular*& head, int dato) {
    NodoCircular* nuevoNodo = new NodoCircular;
    nuevoNodo->dato = dato;
    nuevoNodo->siguiente = nullptr;

    if ( head == nullptr) {
        head = nuevoNodo;
        head->siguiente = head;
    }
    else {
        NodoCircular* aux = head;
        while (aux->siguiente != head) {
            aux = aux->siguiente;
        }
        aux->siguiente = nuevoNodo;
        nuevoNodo->siguiente = head;
    }
}

void eliminarNodo(NodoCircular*& head, int dato) {
    if (head == nullptr) {
        cout << "La lista esta vacia" << endl;
        return;
    }

    NodoCircular* actual = head;
    NodoCircular* anterior = nullptr;

    while(actual->dato != dato) {
        if (actual->siguiente == head) {
            cout << "El dato no existe en la lista" << endl;
            return;
        }

        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == head && actual->siguiente == head) {
        delete actual;
        head = nullptr;
    } else if (actual == head){
        anterior = head;
        while (anterior->siguiente != head) {
            anterior = anterior->siguiente;
        }
        anterior->siguiente = actual->siguiente;
        head = actual->siguiente;
        delete actual;
    } else {
        anterior->siguiente = actual->siguiente;
        delete actual;
    }

    cout << "Elemento eliminado: "
         << "'" << dato << "'" << endl;
}

int main() {
    NodoCircular* head = nullptr;

    int opcion;

    do {
        cout << "\nElige la opcion: " << endl;
        cout << "1. Insertar un elemento en la lista" << endl;
        cout << "2. Eliminar un elemento de la lista" << endl;
        cout << "3. Salir" << endl;
        cin >> opcion;

        switch (opcion){
            case 1: 
                int dato;
                cout << "Ingresa el dato: ";
                cin >> dato;
                crearNodo(head, dato);
                break;
            case 2: 
                int valor;
                cout << "Ingresa el dato a eliminar: ";
                cin >> valor;
                eliminarNodo(head, valor);
                break;
            case 3: 
                cout << "Saliendo..." << endl;
                break;
        }
        cout << "\nLista circular: " << endl;
        mostrarLista(head);
    } while (opcion != 3);
    
    return 0; 
}