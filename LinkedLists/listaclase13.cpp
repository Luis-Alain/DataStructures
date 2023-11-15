#include <iostream>
#include <stdio.h>

using namespace std;

struct nodo
{
  int numero;
  nodo *sgte;
};

typedef struct nodo *listaEnlazada;

void insertarDato(listaEnlazada &lista, int valor)
{
  listaEnlazada q = new nodo;
  q->numero = valor;
  q->sgte = lista;
  lista = q;
}

void imprimirLista(listaEnlazada lista)
{
  cout << "Lista:" << endl;
  while (lista != NULL)
  {
    cout << lista->numero << endl;
    lista = lista->sgte;
  }
  cout << endl;
}

int sumaLista(listaEnlazada lista)
{
  int suma = 0;
  while (lista != NULL)
  {
    suma += lista->numero;
    lista = lista->sgte;
  }
  return suma;
}

void obtenerMinimoMaximo(listaEnlazada lista, int &minimo, int &maximo)
{
  if (lista == NULL)
  {
    minimo = maximo = 0;
    return;
  }

  minimo = maximo = lista->numero;

  while (lista != NULL)
  {
    if (lista->numero < minimo)
      minimo = lista->numero;
    if (lista->numero > maximo)
      maximo = lista->numero;

    lista = lista->sgte;
  }
}

int main()
{
  listaEnlazada lista = NULL;
  int op = 0;
  int dato;

  while (op != 5)
  {
    cout << "\nMenu:" << endl;
    cout << "1. Insertar en la lista " << endl;
    cout << "2. Imprimir la lista    " << endl;
    cout << "3. Sumar elementos       " << endl;
    cout << "4. Obtener minimo y maximo" << endl;
    cout << "5. Salir                 " << endl;

    cout << "Escoja la opcion deseada: ";
    cin >> op;

    switch (op)
    {
    case 1:
      cout << "Introduzca un valor: ";
      cin >> dato;
      insertarDato(lista, dato);
      cout << "\nDato insertado correctamente." << endl;
      break;
    case 2:
      imprimirLista(lista);
      break;
    case 3:
      cout << "\nLa suma de los elementos es : " << sumaLista(lista) << endl;
      break;
    case 4:
      int minimo, maximo;
      obtenerMinimoMaximo(lista, minimo, maximo);
      cout << "\nEl minimo de la lista es: " << minimo << endl;
      cout << "El maximo de la lista es: " << maximo << endl;
      break;
    case 5:
      cout << "\nListo hasta pronto " << endl;
      break;
    default:
      cout << "\nOpción no válida. Por favor, elija nuevamente." << endl;
      break;
    }
  }

  return 0;
}
