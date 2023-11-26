#include <iostream>

using namespace std;

int main(){
    int n; 
    cout << "Ingrese el tamaño de las matrices cuadradas: ";
    cin >> n;

    int matriz1[n][n];
    int matriz2[n][n];
    int resultado[n][n];

    cout << "Ingrese los elementos de la primera matriz:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << "Ingrese el elemento en la posición [" << i << "][" << j << "]: ";
            cin >> matriz1[i][j];
        }
    }

    cout << "Ingrese los elementos de la segunda matriz:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << "Ingrese el elemento en la posición [" << i << "][" << j << "]: ";
            cin >> matriz2[i][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            resultado[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            for (int k = 0; k < n; k++){
                resultado[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }

    cout << "El resultado de la multiplicación es:" << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << resultado[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
