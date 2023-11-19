#include <iostream>
using namespace std;

struct Paciente
{
    int cedula;
    string nombre;
    string apellido;
    int edad;
    string direccion;
    string telefono;
    string seguro;
    string sala;
    Paciente *next;
};

void agregarPaciente(Paciente *&head, int cedula, string nombre, string apellido, int edad, string direccion, string telefono, string seguro, string sala)
{
    Paciente *newNode = new Paciente();
    newNode->cedula = cedula;
    newNode->nombre = nombre;
    newNode->apellido = apellido;
    newNode->edad = edad;
    newNode->direccion = direccion;
    newNode->telefono = telefono;
    newNode->seguro = seguro;
    newNode->sala = sala;
    newNode->next = head;
    head = newNode;
}

void actualizarPaciente(Paciente *&head, int cedula, string nombre, string apellido, int edad, string direccion, string telefono, string seguro, string sala)
{
    Paciente *temp = head;
    while (temp != NULL)
    {
        if (temp->cedula == cedula)
        {
            temp->nombre = nombre;
            temp->apellido = apellido;
            temp->edad = edad;
            temp->direccion = direccion;
            temp->telefono = telefono;
            temp->seguro = seguro;
            temp->sala = sala;
            break;
        }
        temp = temp->next;
    }
}

void eliminarPaciente(Paciente *&head, int cedula)
{
    Paciente *temp = head;
    Paciente *prev = NULL;
    while (temp != NULL)
    {
        if (temp->cedula == cedula)
        {
            if (prev == NULL)
            {
                head = temp->next;
            }
            else
            {
                prev->next = temp->next;
            }
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void mostrarPacientes(Paciente *head)
{
    while (head != NULL)
    {
        cout << "Cedula: " << head->cedula << endl;
        cout << "Nombre: " << head->nombre << " " << head->apellido << endl;
        cout << "Edad: " << head->edad << endl;
        cout << "Direccion: " << head->direccion << endl;
        cout << "Telefono: " << head->telefono << endl;
        cout << "Seguro: " << head->seguro << endl;
        cout << "Sala: " << head->sala << endl;
        cout << "-----------------------" << endl;
        head = head->next;
    }
}

void mostrarPacientePorSalas(Paciente *head, string sala)
{
    while (head != NULL)
    {
        if (head->sala == sala)
        {
            cout << "Cedula: " << head->cedula << endl;
            cout << "Nombre: " << head->nombre << " " << head->apellido << endl;
            cout << "Edad: " << head->edad << endl;
            cout << "Direccion: " << head->direccion << endl;
            cout << "Telefono: " << head->telefono << endl;
            cout << "Seguro: " << head->seguro << endl;
            cout << "Sala: " << head->sala << endl;
            cout << "-----------------------" << endl;
        }
        head = head->next;
    }
}

void mostrarPacientePorSeguro(Paciente *head, string seguro)
{
    while (head != NULL)
    {
        if (head->seguro == seguro)
        {
            cout << "Cedula: " << head->cedula << endl;
            cout << "Nombre: " << head->nombre << " " << head->apellido << endl;
            cout << "Edad: " << head->edad << endl;
            cout << "Direccion: " << head->direccion << endl;
            cout << "Telefono: " << head->telefono << endl;
            cout << "Seguro: " << head->seguro << endl;
            cout << "Sala: " << head->sala << endl;
            cout << "-----------------------" << endl;
        }
        head = head->next;
    }
}

int main() {
    Paciente *head = NULL;

    int opciones;

    do {
        cout << "\nOpciones:" << endl;
        cout << "Introduce la opcion deseada: " << endl;
        cout << "1. Registrar nuevo paciente" << endl;
        cout << "2. Actualizar datos de un paciente" << endl;
        cout << "3. Eliminar paciente" << endl;
        cout << "4. Mostrar todos los pacientes" << endl;
        cout << "5. Mostrar pacientes por sala" << endl;
        cout << "6. Mostrar pacientes por seguro" << endl;
        cout << "7. Salir" << endl;

        cin >> opciones;

        switch (opciones)
        {
        case 1:
        {
            int cedula;
            string nombre, apellido, direccion, telefono, seguro, sala;
            int edad;

            cout << "Ingrese la cedula: ";
            cin >> cedula;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese la edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Ingrese la direccion: ";
            getline(cin, direccion);
            cout << "Ingrese el telefono: ";
            cin >> telefono;
            cout << "Ingrese el representante de seguro (Cía. Internacional, El león azulado, FEDPA): ";
            cin >> seguro;
            cin.ignore();
            cout << "Ingrese el número de sala (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
            getline(cin, sala);

            agregarPaciente(head, cedula, nombre, apellido, edad, direccion, telefono, seguro, sala);
            break;
        }
        case 2:
        {
            int cedula;
            string nombre, apellido, direccion, telefono, seguro, sala;
            int edad;

            cout << "Ingrese la cedula: ";
            cin >> cedula;
            cout << "Ingrese el nombre: ";
            cin >> nombre;
            cout << "Ingrese el apellido: ";
            cin >> apellido;
            cout << "Ingrese la edad: ";
            cin >> edad;
            cin.ignore();
            cout << "Ingrese la direccion: ";
            getline(cin, direccion);
            cout << "Ingrese el telefono: ";
            cin >> telefono;
            cout << "Ingrese el representante de seguro (Cía. Internacional, El león azulado, FEDPA): ";
            cin >> seguro;
            cout << "Ingrese el número de sala (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
            getline(cin, sala);

            actualizarPaciente(head, cedula, nombre, apellido, edad, direccion, telefono, seguro, sala);
            break;
        }
        case 3:
        {
            int cedula;
            cout << "Ingrese la cedula: ";
            cin >> cedula;

            eliminarPaciente(head, cedula);
            break;
        }
        case 4:
            mostrarPacientes(head);
            break;
        case 5:
        {
            string sala;
            cout << "Ingrese la sala a buscar (Mujeres Medicina, Mujeres Parto, Mujeres Cirugía, Varones Medicina, Varones Cirugía): ";
            getline(cin, sala);

            mostrarPacientePorSalas(head, sala);
            break;
        }
        case 6:
        {
            string seguro;
            cout << "Ingrese el representante de seguro (Cía. Internacional, El león azulado, FEDPA): ";
            cin >> seguro;

            mostrarPacientePorSeguro(head, seguro);
            break;
        }
        default:
            cout << "Opcion invalida" << endl;
        }
    } while (opciones != 7);

    return 0;
}