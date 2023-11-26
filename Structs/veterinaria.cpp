#include <iostream>
#include <string>
using namespace std;

struct Animal
{
    string tipo;
    string nombre;
    int edad;
    string nombreDueno;
};

void atenderAnimal(Animal *animales, int &nAnimales, Animal *animalesAtendidos, int &nAnimalesAtendidos, string descripcion)
{
    cout << "\n---------------------------" << endl;
    cout << "Atendiendo al animal: " << animales[0].nombre << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "---------------------------\n"
         << endl;

    // Guardar el animal atendido en el arreglo de animalesAtendidos
    animalesAtendidos[nAnimalesAtendidos] = animales[0];
    nAnimalesAtendidos++;

    // Desplazar los animales en la cola
    for (int j = 0; j < nAnimales - 1; j++)
    {
        animales[j] = animales[j + 1];
    }

    nAnimales--;
}

void mostrarAnimalesAtendidos(Animal *animalesAtendidos, int nAnimalesAtendidos)
{
    cout << "\nAnimales Atendidos:" << endl;
    for (int i = 0; i < nAnimalesAtendidos; i++)
    {
        cout << "Animal " << i + 1 << ": " << animalesAtendidos[i].nombre << endl;
    }
    cout << "---------------------------\n"
         << endl;
}

int main()
{
    Animal *animales = new Animal[10];
    int nAnimales = 0;
    int opcion;

    Animal *animalesAtendidos = new Animal[10];
    int nAnimalesAtendidos = 0;

    do
    {
        cout << "Menu de opciones:" << endl;
        cout << "1. Encolar un animal" << endl;
        cout << "2. Desencolar (Atender) un animal" << endl;
        cout << "3. Mostrar animales atendidos" << endl;
        cout << "Ingrese su opción: ";

        if (!(cin >> opcion))
        {
            cout << "\n---------------------------" << endl;
            cout << "Opción inválida. Por favor, ingrese un número." << endl;
            cout << "---------------------------\n"
                 << endl;
            continue;
        }

        if (opcion == 1)
        {
            if (nAnimales < 10)
            {
                cout << "\n---------------------------" << endl;
                cout << "Ingrese el tipo de animal " << nAnimales + 1 << ": ";
                cin >> animales[nAnimales].tipo;
                cout << "Ingrese el nombre del animal " << nAnimales + 1 << ": ";
                cin >> animales[nAnimales].nombre;
                cout << "Ingrese la edad del animal " << nAnimales + 1 << ": ";
                cin >> animales[nAnimales].edad;
                cout << "Ingrese el nombre del dueño del animal " << nAnimales + 1 << ": ";
                cin >> animales[nAnimales].nombreDueno;
                nAnimales++;
                cout << "---------------------------\n"
                     << endl;
            }
            else
            {
                cout << "\n---------------------------" << endl;
                cout << "La cola de animales está llena." << endl;
                cout << "---------------------------\n"
                     << endl;
            }
        }
        else if (opcion == 2)
        {
            if (nAnimales > 0)
            {
                string descripcion;
                cout << "Atendiendo al animal " << animales[0].nombre << endl;
                cout << "Ingrese la descripción de lo realizado o aplicado al animal: ";
                cin >> descripcion;

                atenderAnimal(animales, nAnimales, animalesAtendidos, nAnimalesAtendidos, descripcion);
            }
            else
            {
                cout << "\n---------------------------" << endl;
                cout << "No hay animales en espera para atender." << endl;
                cout << "---------------------------\n"
                     << endl;
            }
        }
        else if (opcion == 3)
        {
            mostrarAnimalesAtendidos(animalesAtendidos, nAnimalesAtendidos);
        }
        else
        {
            cout << "\n---------------------------" << endl;
            cout << "Opción inválida. Por favor, ingrese una opción válida." << endl;
            cout << "---------------------------\n"
                 << endl;
        }

    } while (true);

    delete[] animales;
    delete[] animalesAtendidos;

    return 0;
}