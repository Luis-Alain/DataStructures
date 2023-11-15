#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main(){
    const int max = 5;
    string nombres[max] = {"Roderik", "Fredy", "Bryan", "Carlos", "Luis"};
    double ventas[max];
    int suma = 0;

    // Solicitar al usuario ingresar las ventas
    for (int i = 0; i < max; i++){
        cout << "Ingrese la venta para " << nombres[i] << ": ";
        cin >> ventas[i];
    }

    cout << " " << endl;

    // Ordenar las ventas de menor a mayor junto con los nombres
    for (int i = 0; i < max - 1; i++){
        for (int j = i + 1; j < max; j++){
            if (ventas[i] > ventas[j]){
                // Intercambiar ventas
                double auxVenta = ventas[i];
                ventas[i] = ventas[j];
                ventas[j] = auxVenta;

                // Intercambiar nombres correspondientes
                string auxNombre = nombres[i];
                nombres[i] = nombres[j];
                nombres[j] = auxNombre;
            }
        }
    }

    // Imprimir los resultados ordenados
    cout << "Nombre \tVenta   \tComisión" << endl;
    for (int i = 0; i < max; i++){
        double comision = 0.0;
        if (ventas[i] < 5000.0){
            comision = ventas[i] * 0.05;
        }
        else if (ventas[i] >= 5000.0 && ventas[i] <= 10000.0){
            comision = ventas[i] * 0.07;
        }
        else if (ventas[i] > 10000.0){
            comision = ventas[i] * 0.12;
        }

        cout << nombres[i] << "\t" << "$" << ventas[i] << "\t" << fixed << setprecision(2) << "$" << comision << endl;
    }

    cout << " " << endl;

    //Calcular suma total de todas las ventas
    for (int i = 0; i < max; i++){
        suma += ventas[i];
    }

    cout << "Ventas totales: $" << suma << endl;

    //Calcular promedio
    double promedio = suma / max;
    cout << "Promedio de ventas: $" << promedio << endl;

    return 0;
}