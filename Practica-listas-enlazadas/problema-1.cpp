/*Escribir un Programa que devuelva cierto (true), si la Lista esta vacía.*/

#include <iostream>
using namespace std;

// Definición de un nodo
struct Nodo {
    int dato;
    Nodo *siguiente;
};

bool estaVacia(Nodo *&cabeza) {
    if (cabeza == NULL) {
        return true;
    } else {
        return false;
    }
}

int main() {
    Nodo *cabeza = NULL;
    if (estaVacia(cabeza)) {
        cout << "La lista está vacía" << endl;
    } else {
        cout << "La lista no está vacía" << endl;
    }
    return 0;
}
