/*Diseña un programa que permita llevar un registro de empleados en una empresa. Cada empleado debe tener los siguientes datos: nombre, número de identificación, salario, y departamento. El programa debe permitir al usuario realizar las siguientes acciones:

1. Agregar un nuevo empleado al registro.
2. Mostrar la lista de empleados con sus detalles.
3. Calcular y mostrar el salario promedio de todos los empleados en un departamento específico.
4. Buscar un empleado por su número de identificación y mostrar sus detalles.*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int NUM_EMPLEADOS = 100;

struct Empleado{
    string nombre;
    int id;
    double salario;
    string departamento;
} empleado;

void imprimirEmpleado(Empleado print){
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "id: " << empleado.id << endl;
    cout << "salario: " << empleado.salario << endl;
    cout << "Departamento: " << empleado.departamento << endl;
}

int main(){
    vector<Empleado> empleados;
    bool agregarEmpleado = true;

    do
    {
        if (empleados.size() < NUM_EMPLEADOS){
            cout << "Ingrese el nombre del empleado: ";
            getline(cin, empleado.nombre);
            cout << "Ingresa el id del empleado: ";
            cin >> empleado.id;
            cout << "Ingresa el salario del empleado: ";
            cin >> empleado.salario;
            cin.ignore();
            cout << "Introduce el departamento: ";
            getline(cin, empleado.departamento);

            empleados.push_back(empleado);

            cout << "¿Deseas agregar otro empleado? (1 para sí, 0 para no): ";
            cin >> agregarEmpleado;
            cin.ignore();
        }
        else{
            cout << "Se ha alcanzado el número máximo de estudiantes (" << NUM_EMPLEADOS << ")." << endl;
            agregarEmpleado = false;
        }
    } while (agregarEmpleado);

    char answer;
    cout << "Desea ver la informacion de los empleados? (Y: cierto, N: falso) ";
    cin >> answer;
    cin.ignore();

    if (answer == 'Y' || answer == 'y'){
        cout << "Información de todos los empleados:" << endl;
        for (const Empleado &empleado : empleados){
            imprimirEmpleado(empleado);
            cout << endl;
        }
    }
    else{
        cout << "Chúpalo entonces" << endl;
    }

    return 0;
}
