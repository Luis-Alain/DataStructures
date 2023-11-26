#include <iostream>
#include <vector>
using namespace std;

struct Colaborador{
    string nombre;
    int edad;
    char sexo;
    int añosServicio;
    double salarioHora;
    int horasTrabajadas;
};

double calcularSalarioBruto(const Colaborador &colaborador){
    int horasNormales = min(colaborador.horasTrabajadas, 104);
    int horasExtras = max(colaborador.horasTrabajadas - 104, 0);
    double salarioBruto = (horasNormales * colaborador.salarioHora) + (horasExtras * colaborador.salarioHora * 1.5);
    return salarioBruto;
}

int main(){
    int numColaboradores;
    cout << "Ingrese el número de colaboradores: ";
    cin >> numColaboradores;

    vector<Colaborador> colaboradores(numColaboradores);

    for (int i = 0; i < numColaboradores; i++){
        cout << "Colaborador " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> colaboradores[i].nombre;
        cout << "Edad: ";
        cin >> colaboradores[i].edad;
        cout << "Sexo (M/F): ";
        cin >> colaboradores[i].sexo;
        cout << "Años de servicio: ";
        cin >> colaboradores[i].añosServicio;
        cout << "Salario por hora: ";
        cin >> colaboradores[i].salarioHora;
        cout << "Horas trabajadas en la semana: ";
        cin >> colaboradores[i].horasTrabajadas;
    }

    cout << "\nInforme de pago - Servicio Medico J&J" << endl;
    for (int i = 0; i < numColaboradores; i++){
        double salarioBruto = calcularSalarioBruto(colaboradores[i]);
        cout << "Nombre: " << colaboradores[i].nombre << endl;
        cout << "Sexo: " << colaboradores[i].sexo << endl;
        cout << "Edad: " << colaboradores[i].edad << endl;
        cout << "Total de horas: " << colaboradores[i].horasTrabajadas << endl;
        cout << "Salario Bruto: $" << salarioBruto << endl;
        cout << endl;
    }

    return 0;
}
