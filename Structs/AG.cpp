#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct FechaHora
{
	int dia;
	int mes;
	int anyo;
	int hora;
	int minuto;
};

struct Operacion
{
	string NumCuenta;
	int TipoOperacion; // 0 para depósito, 1 para retiro, 2 para consulta de saldo
	FechaHora FechaHora;
};

struct Cliente
{
	string cedula;
	string nombre;
	string sexo;
	int edad;
	int NumCuenta;
	double Saldo;
	vector<Operacion> transacciones;
};

int main()
{
	vector<Cliente> clientes;
	FechaHora ant;
	int NumClientes;

	cout << "Ingrese la cantidad de clientes por registrar: ";
	cin >> NumClientes;
	cout << "Ha ingresado: " << NumClientes << " clientes." << endl
		 << endl;
	cout << "REGISTRO DE CLIENTES." << endl;
	clientes.resize(NumClientes);

	for (int i = 0; i < NumClientes; i++)
	{
		cout << "CLIENTE " << i + 1 << ". " << endl;
		cout << "Introduzca la cédula del cliente: ";
		cin >> clientes[i].cedula;
		cout << "Introduzca el nombre del cliente: ";
		cin >> clientes[i].nombre;
		cout << "Introduzca el sexo del cliente, M para masculino y F para femenino: ";
		cin >> clientes[i].sexo;
		cout << "Introduzca la edad del cliente: ";
		cin >> clientes[i].edad;

		if (clientes[i].edad <= 0)
		{
			cout << "ERROR. La edad introducida no es permitida." << endl;
			return 0;
		}

		cout << "Introduzca el número de cuenta del cliente: ";
		cin >> clientes[i].NumCuenta;
		cout << "Introduzca el saldo en la cuenta del cliente: ";
		cin >> clientes[i].Saldo;
		cout << endl
			 << endl;
	}

	bool operacion = true;

	do
	{
		cout << "Bienvenido, ¿en qué le servimos?" << endl;
		int eleccion;
		int ne;
		Cliente Nuevocliente;
		int deposito, cuenta, retiro;
		float totalretiro = 0, totaldeposito = 0;

		cout << "Eliga las opciones que quiere realizar:" << endl;
		cout << "Ingrese [1] para generar un nuevo cliente" << endl;
		cout << "Ingrese [2] para hacer un depósito" << endl;
		cout << "Ingrese [3] para retirar dinero" << endl;
		cout << "Ingrese [4] para ver su saldo actual" << endl;
		cout << "Ingrese [5] para ver los clientes" << endl;
		cout << "Ingrese [6] para ver los registros con los meses" << endl;

		cin >> eleccion;

		if (eleccion == 1)
		{
			cout << "Gracias por tomar nuestros servicios, por favor llene los datos:" << endl;
			cout << "Cuantos clientes quiere ingresar: ";
			cin >> ne;

			for (int mas = 0; mas < ne; mas++)
			{
				cout << "CEDULA: " << clientes[mas].cedula << endl;
				cout << "NOMBRE: " << clientes[mas].nombre << endl;
				cout << "SEXO: " << clientes[mas].sexo << endl;
				cout << "EDAD: " << clientes[mas].edad << endl;
				cout << "NUMERO DE CUENTA: " << clientes[mas].NumCuenta << endl;
				cout << "SALDO: " << clientes[mas].Saldo << endl;
				cout << endl
					 << endl;
			}
		}
		else if (eleccion == 2)
		{
			cout << "Ingrese el número de cuenta: ";
			cin >> cuenta;
			cout << "Ingrese la cantidad que quiere depositar: ";
			cin >> deposito;

			for (int i = 0; i < NumClientes; i++)
			{
				if (cuenta == clientes[i].NumCuenta)
				{
					totaldeposito = clientes[i].Saldo + deposito;
					cout << "Su saldo actual es de: " << totaldeposito << endl;
					cout << "Ingrese la hora y los minutos de su depósito: ";
					cin >> ant.hora >> ant.minuto;
					cout << "Ingrese la fecha de hoy (día mes año): ";
					cin >> ant.dia >> ant.mes >> ant.anyo;

					Operacion transaccion;
					transaccion.NumCuenta = to_string(cuenta);
					transaccion.TipoOperacion = 0; // 0 para depósito
					transaccion.FechaHora = ant;
					clientes[i].transacciones.push_back(transaccion);
				}
			}
		}
		else if (eleccion == 3)
		{
			cout << "Ingrese el número de la cuenta: ";
			cin >> cuenta;
			cout << "Ingrese la cantidad que quiere retirar: ";
			cin >> retiro;

			for (int i = 0; i < NumClientes; i++)
			{
				if (cuenta == clientes[i].NumCuenta)
				{
					if (retiro <= clientes[i].Saldo)
					{
						totalretiro = clientes[i].Saldo - retiro;
						cout << "Su saldo actual es de " << totalretiro << endl;
						cout << "Ingrese la hora y los minutos de su retiro: ";
						cin >> ant.hora >> ant.minuto;
						cout << "Ingrese la fecha de hoy (día mes año): ";
						cin >> ant.dia >> ant.mes >> ant.anyo;

						Operacion transaccion;
						transaccion.NumCuenta = to_string(cuenta);
						transaccion.TipoOperacion = 1; // 1 para retiro
						transaccion.FechaHora = ant;
						clientes[i].transacciones.push_back(transaccion);
					}
					else
					{
						cout << "Saldo insuficiente para realizar el retiro." << endl;
					}
				}
			}
		}
		else if (eleccion == 4)
		{
			cout << "Ingrese el número de cuenta: ";
			cin >> cuenta;

			for (int i = 0; i < NumClientes; i++)
			{
				if (cuenta == clientes[i].NumCuenta)
				{
					cout << "Su saldo actual es: " << clientes[i].Saldo << endl;
					cout << "Ingrese la hora y los minutos de su consulta: ";
					cin >> ant.hora >> ant.minuto;
					cout << "Ingrese la fecha de hoy (día mes año): ";
					cin >> ant.dia >> ant.mes >> ant.anyo;
					break;
				}
			}
		}
		else if (eleccion == 5)
		{
			cout << "REGISTRO." << endl;
			for (int i = 0; i < NumClientes; i++)
			{
				cout << "CEDULA: " << clientes[i].cedula << endl;
				cout << "NOMBRE: " << clientes[i].nombre << endl;
				cout << "SEXO: " << clientes[i].sexo << endl;
				cout << "EDAD: " << clientes[i].edad << endl;
				cout << "NUMERO DE CUENTA: " << clientes[i].NumCuenta << endl;
				cout << "SALDO: " << clientes[i].Saldo << endl;
				cout << endl
					 << endl;
			}
		}
		else if (eleccion == 6)
		{
			// Mostrar registros con los meses
			cout << "Ingrese el número de cuenta del cliente: ";
			cin >> cuenta;
			cout << "Ingrese el mes que desea consultar (1-12): ";
			int mesConsulta;
			cin >> mesConsulta;

			for (const Cliente &cliente : clientes)
			{
				if (to_string(cuenta) == to_string(cliente.NumCuenta))
				{
					cout << "Registros de transacciones para el cliente " << cliente.nombre << " en el mes " << mesConsulta << ":" << endl;
					for (const Operacion &transaccion : cliente.transacciones)
					{
						if (transaccion.FechaHora.mes == mesConsulta)
						{
							cout << "Fecha: " << transaccion.FechaHora.dia << "/" << transaccion.FechaHora.mes << "/" << transaccion.FechaHora.anyo << " ";
							cout << "Hora: " << transaccion.FechaHora.hora << ":" << transaccion.FechaHora.minuto << " ";
							cout << "Tipo de Operación: ";
							if (transaccion.TipoOperacion == 0)
							{
								cout << "Depósito" << endl;
							}
							else if (transaccion.TipoOperacion == 1)
							{
								cout << "Retiro" << endl;
							}
							else if (transaccion.TipoOperacion == 2)
							{
								cout << "Consulta de Saldo" << endl;
							}
						}
					}
					break;
				}
			}
		}
		cout << "¿Deseas realizar otra operación? (1 para sí, 0 para no): ";
		cin >> operacion;
	} while (operacion);

	return 0;
}
