#include <iostream>
using namespace std;

struct Vitales{
    double temperatura;
    double presionSanguinea;
    double pulso;
}signosVitales;

struct Paciente{
    string nombre;
    string apellido;
    int edad;
    Vitales signos;
    string representante;
}paciente;

void mostrarDatos(Paciente print){
    cout << "Nombre: " << paciente.nombre << endl;
    cout << "Apellido: " << paciente.apellido << endl;
    cout << "edad: " << paciente.edad << endl;
    cout << "Representante: " << paciente.representante << endl;
}

void mostrarSignosVitales(Vitales print){
    cout << "Temperatura: " << paciente.signos.temperatura << endl;
    cout << "Presion sanguinea: " << paciente.signos.presionSanguinea << endl;
    cout << "Pulso: " << paciente.signos.pulso << endl;
}

int main(){
    cout << "introduce el nombre del paciente: ";
    getline(cin, paciente.nombre);
    cout << "Introduce el apellido del paciente: ";
    getline(cin, paciente.apellido);
    cout << "introduce la edad del paciente: ";
    cin >> paciente.edad;
    cout << "Introduce el representante de seguro del paciente: ";
    getline(cin, paciente.representante);
    cin.ignore();

    cout << " " << endl;

    cin.ignore();
    cout << "Introduce los signos vitales del paciente " << paciente.nombre << ": " << endl;
    cin.ignore();
    cout << "Introduce la temperatura del paciente: ";
    cin >> paciente.signos.temperatura;
    cout << "Introduce la presion sanguinea del paciente: ";
    cin >> paciente.signos.presionSanguinea;
    cout << "Introduce el pulso del paciente: ";
    cin >> paciente.signos.pulso;
    cin.ignore();

    if(paciente.signos.temperatura > 38){
        cout << "Tiene Fiebre!" << endl;
    }
    if(paciente.signos.presionSanguinea > 80){
        cout << "Presion alta!" << endl;
    }

    cout << "----Mostrar datos del paciente----" << endl;
    mostrarDatos(paciente);

    cout << " " << endl;

    cout << "----Mostrar signos vitales del paciente----" << endl;
    mostrarSignosVitales(signosVitales);
}