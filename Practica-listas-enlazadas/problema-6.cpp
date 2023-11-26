/*Se tiene una lista de simple enlace, el campo dato es un registro (estructura) con los campos de
un alumno: nombre, edad, sexo. Escribir una función para transformar la lista de tal forma que si
el primer nodo es de un alumno de sexo masculino el siguiente sea de sexo femenino.*/

#include <iostream>
using namespace std;

struct Alumno{
    string nombre;
    int edad;
    char sexo;
    Alumno *siguiente;

    Alumno(string n, int e, char s) : nombre(n), edad(e), sexo(s), siguiente(nullptr) {}
};

void intercambiarSexos(Alumno *&cabeza){
    if (cabeza == nullptr || cabeza->siguiente == nullptr) {
        // Lista vacía o con un solo nodo, no hay nada que intercambiar
        return;
    }

    // Verificar el sexo del primer nodo
    char sexoActual = cabeza->sexo;

    // Crear dos listas temporales para almacenar nodos de cada sexo
    Alumno *masculinos = nullptr;
    Alumno *femeninos = nullptr;

    // Separar nodos en las listas temporales
    Alumno *actual = cabeza;
    while (actual != nullptr) {
        Alumno *siguiente = actual->siguiente;
        actual->siguiente = nullptr; // Desvincular el nodo de la lista original

        if (actual->sexo == 'M') {
            actual->siguiente = masculinos;
            masculinos = actual;
        } else {
            actual->siguiente = femeninos;
            femeninos = actual;
        }

        actual = siguiente;
    }

    // Unir las dos listas temporales
    if (sexoActual == 'M') {
        cabeza = femeninos;
        actual = femeninos;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = masculinos;
    } else {
        cabeza = masculinos;
        actual = masculinos;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = femeninos;
    }
}

// Función para imprimir la lista
void imprimirLista(Alumno *cabeza){
    Alumno *actual = cabeza;
    while (actual != nullptr) {
        cout << "Nombre: " << actual->nombre << ", Edad: " << actual->edad << ", Sexo: " << actual->sexo << endl;
        actual = actual->siguiente;
    }
}

int main(){
    // Crear una lista de ejemplo
    Alumno *lista = new Alumno("Juan", 20, 'M');
    lista->siguiente = new Alumno("Maria", 22, 'F');
    lista->siguiente->siguiente = new Alumno("Pedro", 21, 'M');
    lista->siguiente->siguiente->siguiente = new Alumno("Ana", 23, 'F');

    cout << "Lista original:" << endl;
    imprimirLista(lista);

    // Llamar a la función para intercambiar los sexos
    intercambiarSexos(lista);

    cout << "\nLista después de intercambiar sexos:" << endl;
    imprimirLista(lista);

    // Liberar la memoria
    while (lista != nullptr) {
        Alumno *siguiente = lista->siguiente;
        delete lista;
        lista = siguiente;
    }

    return 0;
}
