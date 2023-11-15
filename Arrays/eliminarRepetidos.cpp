#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

int main(){
    srand(static_cast<unsigned int>(time(nullptr)));

    const int tamañoArray = 10;
    const int valorMínimo = 1;
    const int valorMáximo = 20;

    vector<int> numerosAleatorios;

    for (int i = 0; i < tamañoArray; ++i){
        int numeroAleatorio = rand() % (valorMáximo - valorMínimo + 1) + valorMínimo;
        numerosAleatorios.push_back(numeroAleatorio);
    }

    cout << "Array original: ";
    for (int numero : numerosAleatorios){
        cout << numero << " ";
    }
    cout << endl;

    for (int i = 0; i < tamañoArray - 1; ++i){
        for (int j = i + 1; j < tamañoArray; ++j){
            if (numerosAleatorios[i] > numerosAleatorios[j]){
                int temp = numerosAleatorios[i];
                numerosAleatorios[i] = numerosAleatorios[j];
                numerosAleatorios[j] = temp;
            }
        }
    }

    int nuevoTamaño = 1;
    for (int i = 1; i < tamañoArray; ++i){
        if (numerosAleatorios[i] != numerosAleatorios[i - 1]){
            numerosAleatorios[nuevoTamaño] = numerosAleatorios[i];
            ++nuevoTamaño;
        }
    }

    cout << "Array sin duplicados: ";
    for (int numero : numerosAleatorios){
        cout << numero << " ";
    }
    cout << endl;

    return 0;
}
