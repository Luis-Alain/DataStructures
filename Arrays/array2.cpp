#include <iostream>

using namespace std;

int main(){
    int i = 0;
    int j = 4;
    int aux;

    const int maxLength = 5;
    int vector[maxLength];

    for (int i = 0; i < maxLength; ++i){
        cout << "Ingrese el valor para la posición " << i << ": ";
        cin >> vector[i];
    }

    cout << "Valores ingresados en el array:" << endl;
    for (int i = 0; i < maxLength; ++i){
        cout << vector[i] << " ";
    }

    cout << " " << endl;

    for (int i = 0; i < maxLength - 1; ++i){
        for (int j = 0; j < maxLength - i - 1; ++j){
            if (vector[j] > vector[j + 1]){
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
    }

    for ( int i = 0; i < maxLength; ++i) {
         cout << vector[i] << " ";
    }

}
