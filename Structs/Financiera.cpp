#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Fecha{
    int dia;
    int mes;
    int año;
};

struct Hora{
    int hora;
    int minutos;
};

struct Transaccion{
    int numeroTransaccion;
    int tipo;
    int monto;
    Fecha fecha;
    Hora hora;
};

struct Cliente{
    string cedula;
    string nombre;
    int edad;
    int numeroCuenta;
    int saldoCuenta;
    vector<Transaccion> transacciones;
};

int main(){
    vector<Cliente> clientes;

    Cliente cliente1 = {"131322", "María", 23, 1001, 5000};
    Cliente cliente2 = {"323233", "Luis", 19, 1002, 10000};
    Cliente cliente3 = {"324132", "Bryan", 18, 1003, 8500};

    clientes.push_back(cliente1);
    clientes.push_back(cliente2);
    clientes.push_back(cliente3);

    int numeroTransaccion = 1;

    bool operacion = true;
    do
    {
        int transaccion;
        cout << "¿Qué operación deseas realizar? \n0 para Depósito\n 1 para Retiro\n 2 para Consulta de saldo\n 3 para mostrar datos del cliente\n 4 para mostrar todas las operaciones de un mes \n";
        cin >> transaccion;

        if (cin.fail() || (transaccion < 0 || transaccion > 4)){
            cout << "Operación no válida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        int cuentaSeleccionada;
        cout << "Selecciona la cuenta (1, 2, 3): ";
        cin >> cuentaSeleccionada;

        if (cin.fail() || (cuentaSeleccionada < 1 || cuentaSeleccionada > 3)){
            cout << "Cuenta no válida." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            operacion = false;
            continue;
        }

        Cliente &clienteSeleccionado = clientes[cuentaSeleccionada - 1];

        switch (transaccion){
        case 0:{
            cout << "Realizar Depósito en la cuenta de " << clienteSeleccionado.nombre << endl;
            int nuevoDeposito;
            cout << "Ingresa la cantidad a depositar: ";
            cin >> nuevoDeposito;

            Transaccion deposito = {numeroTransaccion++, 0, nuevoDeposito};
            cout << "Ingresa la hora y los minutos (ejemplo: 14 30): ";
            cin >> deposito.hora.hora >> deposito.hora.minutos;

            cout << "Ingresa el dia, mes y año. (Ejemplo: 23 9 2023): ";
            cin >> deposito.fecha.dia >> deposito.fecha.mes >> deposito.fecha.año;

            clienteSeleccionado.transacciones.push_back(deposito);
            clienteSeleccionado.saldoCuenta += nuevoDeposito;
            break;
        }
        case 1:{
            cout << "Realizar Retiro de la cuenta de " << clienteSeleccionado.nombre << endl;
            int nuevoRetiro;
            cout << "Ingresa la cantidad a retirar: ";
            cin >> nuevoRetiro;

            if (nuevoRetiro <= clienteSeleccionado.saldoCuenta){
                Transaccion retiro = {numeroTransaccion++, 1, nuevoRetiro};
                cout << "Ingresa la hora y los minutos (ejemplo: 14 30): ";
                cin >> retiro.hora.hora >> retiro.hora.minutos;

                cout << "Ingresa el dia, mes y año. (Ejemplo: 23 9 2023): ";
                cin >> retiro.fecha.dia >> retiro.fecha.mes >> retiro.fecha.año;

                clienteSeleccionado.transacciones.push_back(retiro);
                clienteSeleccionado.saldoCuenta -= nuevoRetiro;
            }
            else{
                cout << "Saldo insuficiente." << endl;
            }
            break;
        }
        case 2:{
            cout << "Consultar saldo de la cuenta de " << clienteSeleccionado.nombre << ": " << clienteSeleccionado.saldoCuenta << endl;
            break;
        }
        case 3:{
            cout << "Cedula: " << clienteSeleccionado.cedula << endl;
            cout << "Nombre: " << clienteSeleccionado.nombre << endl;
            cout << "Edad: " << clienteSeleccionado.edad << endl;
            cout << "Numero de cuenta: " << clienteSeleccionado.numeroCuenta << endl;
            break;
        }
        case 4:{
            int mes;
            cout << "Ingresa el mes (1 para Enero, 2 para Febrero, ...): ";
            cin >> mes;

            for (const auto &transaccion : clienteSeleccionado.transacciones){
                if (transaccion.fecha.mes == mes){
                    cout << "Transaccion #" << transaccion.numeroTransaccion << " - Tipo: ";
                    if (transaccion.tipo == 0){
                        cout << "Depósito";
                    }
                    else if (transaccion.tipo == 1){
                        cout << "Retiro";
                    }
                    else if (transaccion.tipo == 2){
                        cout << "Consulta de saldo";
                    }
                    cout << " - Monto: " << transaccion.monto << " - Fecha: " << transaccion.fecha.dia << " de " << transaccion.fecha.mes << " de " << transaccion.fecha.año << " a las " << transaccion.hora.hora << ":" << transaccion.hora.minutos << endl;
                }
            }
            break;
        }
        default:
            cout << "Operación no válida." << endl;
        }

        cout << "¿Deseas realizar otra operación? (1 para sí, 0 para no): ";
        cin >> operacion;
    } while (operacion);

    return 0;
}

// Hecho por Luis Alain & María García