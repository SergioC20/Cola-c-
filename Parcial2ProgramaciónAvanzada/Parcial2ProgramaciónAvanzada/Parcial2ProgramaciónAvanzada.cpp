// Parcial2ProgramaciónAvanzada.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
using namespace std;

void mostrar();
void ingreso();
void eliminar();

struct datos
{
	int dato;
	datos* direccionSiguiente;
}*primero, * cola, * ultimo = NULL;

int main()
{
	int opciones;
	while (true)
	{
		cout << "1.Ingresar datos a la cola  2.Mostrar datos de la cola  3.Eliminar datos de la cola" << endl;
		cin >> opciones;
		switch (opciones)
		{
		case 1: {
			ingreso();
			break;
		}

		case 2: {
			mostrar();
			break;
		}

		case 3: {
			eliminar();
			break;
		}
		}
	}
}
void ingreso()
{
	cola = new(datos);
	cout << "Ingrese dato a la cola" << endl;
	cin >> cola->dato;
	if (ultimo != NULL) {
		ultimo->direccionSiguiente = cola;
		cola->direccionSiguiente = NULL;
		ultimo = cola;
		cout << "Dato ingresado: " << endl;
		cout << ultimo->direccionSiguiente << " " << cola->direccionSiguiente << endl;
	}
	else
	{
		primero = ultimo = cola;
		cout << "Primer dato ingresado" << endl;
		cout << primero << " " << ultimo << " " << cola << endl;
	}
}

void mostrar()
{
	if (ultimo == NULL) {
		cout << "La cola no tiene elementos" << endl;
		return;
	}
	cola = primero;
	cout << "Los datos de la cola son: " << endl;
	while (cola != NULL)
	{
		cout << cola->dato << endl;
		cola = cola->direccionSiguiente;
	}
}

void eliminar()
{
	if (primero != NULL) {
		cola = primero;
		cout << "Eliminado: " << primero->dato << endl;
		primero = cola->direccionSiguiente;
		delete(cola);
		if (primero == NULL) {
			cola = NULL;
			ultimo = NULL;
		}
	}
	else
	{
		cout << "La cola no tiene elementos" << endl;
	}
}
