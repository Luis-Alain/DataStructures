#include <iostream>
#include <vector>
using namespace std;

int main(){
    //crear una pila
    const int MAX = 10;
    int pila[MAX];
    int tope = -1;
    int numero;

    //insertar elementos en la pila
    for(int i = 0; i < MAX; i++){
        cout << "Introduce un numero: ";
        cin >> numero;

        pila[i] = numero;
        tope++;

        if (tope == MAX){
            cout << "Pila llena" << endl;
            break;
        }
    }

    int length = sizeof(pila) / sizeof(pila[0]);

    //mostrar elementos de la pila
    for (int i = 0; i < length; i++ ){
        cout << "Posicion " << i << ": " <<  pila[i] << endl;
    }

    //eliminar elementos de la pila
    int indice;
    int contador = 0;
    int pilaAuxiliar[MAX];
    cout << "Introduce el indice del elemento a eliminar: ";
    cin >> indice;
    for (int i = 0; i < length; i++){
        if (i != indice){
            pilaAuxiliar[contador] = pila[i];
            contador++;
        }
    }

    length--;

    for (int i = 0; i < length; i++){
        pila[i] = pilaAuxiliar[i];
    }

    cout << " " << endl;


    //Mostrar pila actualizada
    for (int i = 0; i < length; i++){
        cout << "Posicion " << i << ": " << pila[i] << endl;
    }
}