#include <iostream>
using namespace std;

int main(){
    int arreglo[20];
    int contador[6] = {0}; 

    cout << "Ingresa 20 números del 1 al 5:" << endl;
    for (int i = 0; i < 20; i++){
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];

        if (arreglo[i] < 1 || arreglo[i] > 5){
            cout << "Número fuera de rango. Debe ser del 1 al 5." << endl;
            i--; 
        }
    }

    for (int i = 0; i < 20; i++){
        contador[arreglo[i]]++;
    }

    for (int i = 1; i <= 5; i++){
        cout << "El número " << i << " aparece " << contador[i] << " veces." << endl;
    }

    return 0;
}