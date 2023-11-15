#include <iostream>
using namespace std;

const int MAX = 100;
int arreglo[MAX];
int tope = -1;

bool estaVacia(){
    return tope == -1;
}

bool estaLlena(){
    return tope == MAX - 1;
}

void push(int elemento){
    if (!estaLlena()){
        tope++;
        arreglo[tope] = elemento;
    }
    else{
        cout << "La pila está llena. No se puede agregar más elementos." << endl;
    }
}

void pop(){
    if (!estaVacia()){
        tope--;
    }
    else{
        cout << "La pila está vacía. No se puede eliminar un elemento." << endl;
    }
}

int top(){
    if (!estaVacia()){
        return arreglo[tope];
    }
    else{
        cout << "La pila está vacía. No hay elementos en la cima." << endl;
        return -1;
    }
}

int main(){
    int elemento;
    char continuar;

    do{
        cout << "Ingrese un elemento para agregar a la pila: ";
        cin >> elemento;

        push(elemento);

        cout << "¿Desea agregar otro elemento? (S/N): ";
        cin >> continuar;

    } while (continuar == 'S' || continuar == 's');

    cout << "Elementos en la pila:" << endl;
    while (!estaVacia()){
        cout << top() << " ";
    }
    cout << endl;

    return 0;
}
