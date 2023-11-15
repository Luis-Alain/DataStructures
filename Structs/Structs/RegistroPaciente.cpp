#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Paciente{
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string direccion;
    string telefono;
    string seguro;
    string sala;
};

// Función para mostrar los datos de un paciente
void mostrarPaciente(const Paciente &paciente){
    cout << "Cedula: " << paciente.cedula << endl;
    cout << "Nombre: " << paciente.nombre << " " << paciente.apellido << endl;
    cout << "Edad: " << paciente.edad << endl;
    cout << "Direccion: " << paciente.direccion << endl;
    cout << "Telefono: " << paciente.telefono << endl;
    cout << "Seguro: " << paciente.seguro << endl;
    cout << "Sala: " << paciente.sala << endl;
    cout << "-----------------------" << endl;
}

// Función para agregar un nuevo paciente a la lista
void agregarPaciente(std::vector<Paciente> &pacientes){
    Paciente nuevoPaciente;
    cout << "Ingrese la cedula: ";
    cin >> nuevoPaciente.cedula;
    cout << "Ingrese el nombre: ";
    cin >> nuevoPaciente.nombre;
    cout << "Ingrese el apellido: ";
    cin >> nuevoPaciente.apellido;
    cout << "Ingrese la edad: ";
    cin >> nuevoPaciente.edad;
    cin.ignore(); 
    cout << "Ingrese la direccion: ";
    getline(std::cin, nuevoPaciente.direccion);
    cout << "Ingrese el telefono: ";
    cin >> nuevoPaciente.telefono;
    cout << "Ingrese el representante de seguro (Cía. Internacional, El león azulado, FEDPA): ";
    cin >> nuevoPaciente.seguro;
    cout << "Ingrese el número de sala (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
    cin >> nuevoPaciente.sala;

    pacientes.push_back(nuevoPaciente);
    cout << "Paciente registrado exitosamente." << endl;
}

int main(){
    vector<Paciente> pacientes;

    while (true){
        cout << "Opciones:" << endl;
        cout << "1. Registrar nuevo paciente" << endl;
        cout << "2. Actualizar datos de un paciente" << endl;
        cout << "3. Eliminar paciente" << endl;
        cout << "4. Mostrar listado de todos los pacientes" << endl;
        cout << "5. Mostrar pacientes por sala" << endl;
        cout << "6. Mostrar pacientes por edad" << endl;
        cout << "7. Mostrar pacientes por representante de seguro" << endl;
        cout << "8. Salir" << endl;

        int opcion;
        cin >> opcion;

        if (opcion == 1){
            agregarPaciente(pacientes);
        } else if (opcion == 2){
            int cedulaActualizar;
            cout << "Ingrese la cédula del paciente a actualizar: ";
            cin >> cedulaActualizar;

            for (Paciente &paciente : pacientes){
                if (paciente.cedula == cedulaActualizar){
                    cout << "Ingrese el nuevo nombre: ";
                    cin >> paciente.nombre;
                    cout << "Ingrese el nuevo apellido: ";
                    cin >> paciente.apellido;
                    cout << "Ingrese la nueva edad: ";
                    cin >> paciente.edad;
                    cin.ignore(); 
                    cout << "Ingrese la nueva dirección: ";
                    getline(std::cin, paciente.direccion);
                    cout << "Ingrese el nuevo teléfono: ";
                    cin >> paciente.telefono;
                    cout << "Ingrese el nuevo representante de seguro (Cía. Internacional, El león azulado, FEDPA): ";
                    cin >> paciente.seguro;
                    cout << "Ingrese el nuevo número de sala (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
                    cin >> paciente.sala;

                    cout << "Datos actualizados exitosamente." << std::endl;
                    break;
                }
            }
        }
        else if (opcion == 3){
            int cedulaEliminar;
            cout << "Ingrese la cédula del paciente a eliminar: ";
            cin >> cedulaEliminar;

            for (auto it = pacientes.begin(); it != pacientes.end(); ++it){
                if (it->cedula == cedulaEliminar){
                    it = pacientes.erase(it);
                    cout << "Paciente eliminado exitosamente." << std::endl;
                    break;
                }
            }
        } else if (opcion == 4){
            cout << "Listado de todos los pacientes:" << endl;
            for (const Paciente &paciente : pacientes){
                mostrarPaciente(paciente);
            }
        } else if (opcion == 5){
            string salaBuscada;
            cout << "Ingrese la sala a buscar (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
            cin >> salaBuscada;

            cout << "Pacientes en la sala " << salaBuscada << ":" << endl;
            for (const Paciente &paciente : pacientes){
                if (paciente.sala == salaBuscada){
                    mostrarPaciente(paciente);
                }
            }
        } else if (opcion == 6) {
            int edadBuscada;
            cout << "Ingrese la edad a buscar: ";
            cin >> edadBuscada;

            cout << "Pacientes de " << edadBuscada << " años:" << std::endl;
            for (const Paciente &paciente : pacientes){
                if (paciente.edad == edadBuscada){
                    mostrarPaciente(paciente);
                }
            }
        } else if (opcion == 7){
            string seguroBuscado;
            cout << "Ingrese el representante de seguro a buscar (Cía. Internacional, El león azulado, FEDPA): ";
            cin >> seguroBuscado;

            cout << "Pacientes con seguro " << seguroBuscado << ":" << endl;
            for (const Paciente &paciente : pacientes){
                if (paciente.seguro == seguroBuscado){
                    mostrarPaciente(paciente);
                }
            }
        } else if (opcion == 8){
            break;
        } else {
            cout << "Opción no válida. Intente nuevamente." << endl;
        }
    }

    return 0;
}
