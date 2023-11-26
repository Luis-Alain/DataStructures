#include <iostream>
#include <string>
using namespace std;

struct datos{
    string nombre;
    string t1, t2, t3;
};

int main(){
    datos contacto[3];

    for (int i = 0; i < 3; i++){
        cout << "Introduce un nombre: ";
        getline(cin, contacto[i].nombre);
        cout << "Introduce el telefono 1: ";
        getline(cin, contacto[i].t1);
        cout << "Introduce el telefono 2: ";
        getline(cin, contacto[i].t2);
        cout << "Introduce el telefono 3: ";
        getline(cin, contacto[i].t3);
    }

    char opcion;
    do{
        cout << "\n¿Qué deseas filtrar? (n para nombre, q para salir): ";
        cin >> opcion;
        cin.ignore(); 

        switch (opcion){
        case 'n':{
            cout << "Introduce el nombre que deseas buscar: ";
            string nombreBuscado;
            getline(cin, nombreBuscado);

            bool encontrado = false;
            for (int i = 0; i < 3; i++){
                if (contacto[i].nombre == nombreBuscado){
                    cout << "El nombre de la persona es: " << contacto[i].nombre << "\n";
                    cout << "El teléfono 1 es: " << contacto[i].t1 << "\n";
                    cout << "El teléfono 2 es: " << contacto[i].t2 << "\n";
                    cout << "El teléfono 3 es: " << contacto[i].t3 << "\n";
                    encontrado = true;
                    break;
                }
            }

            if (!encontrado){
                cout << "No se encontró ninguna coincidencia para el nombre ingresado.\n";
            }
            break;
        }
        case 'q':
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opción no válida.\n";
            break;
        }
    } while (opcion != 'q');

    return 0;
}