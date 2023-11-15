#include <iostream>
using namespace std;

const int MAX_PILA = 10;

int pila[MAX_PILA];

void crearPila(int &tope){
    tope = -1;
}

bool pilaVacia(int tope){
    return tope == -1;
}

bool pilaLlena(int tope){
    return tope == MAX_PILA - 1;
}

bool apilar(int &tope, int dato){
    if (pilaLlena(tope)){
        return false;
    }
    tope++;
    pila[tope] = dato;
    return true;
}

bool desapilar(int &tope, int &dato){
    if (pilaVacia(tope)){
        return false;
    }
    dato = pila[tope];
    tope--;
    return true;
}

void mostrarPila(int tope){
    cout << "Estado actual de la pila: ";
    if (pilaVacia(tope)) {
        cout << "La pila esta vacia.";
    } else{
        for (int i = 0; i <= tope; i++){
            cout << pila[i] << " ";
        }
    }
    cout << endl;
}

int main(){
    int tope;
    crearPila(tope);
    int option;

    cout << "Que deseas hacer: \n1.Añadir elemento \n2.Eliminar elemento \n3.Mostrar pila \n4.Salir" << endl;
    cin >> option;

    while (option != 4){
        if (option == 1){
            int dato;
            cout << "Ingrese el dato: ";
            cin >> dato;
            if (apilar(tope, dato)){
                cout << "Dato apilado exitosamente." << endl;
            } else{
                cout << "La pila esta llena." << endl;
            }
        } else if (option == 2){
            int dato;
            if (desapilar(tope, dato)){
                cout << "Dato desapilado exitosamente." << endl;
            } else{
                cout << "La pila esta vacia." << endl;
            }
        } else if (option == 3){
            mostrarPila(tope);
        } else {
            cout << "Opcion invalida." << endl;
        }
        cout << "Que deseas hacer: \n1.Añadir elemento \n2.Eliminar elemento \n3.Mostrar pila \n4.Salir" << endl;
        cin >> option;
    }
    return 0;
}
