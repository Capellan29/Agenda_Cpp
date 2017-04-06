/*
 * Agenda.cpp
 *
 *  Created on: Mar 4, 2017
 *      Author: Capellán
 */

#include "Agenda.h"

Agenda::Agenda() : _clave(0), _auxClave(0), _coincidencias(false)
{

}

void Agenda::agregarContactos()
{
	ofstream escritura;
	escritura.open("datos.txt",ios::out|ios::app);
	ifstream _lectura("datos.txt",ios::in);
	if (escritura.is_open() && _lectura.is_open()) {
		//Solicitar Datos
		cout << "Ingresa la clave del contacto: ";
		cin >> _clave;
		//Conprobar si la clave esta ocupada
		_lectura >> _auxClave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido;
			if (_auxClave == _clave) {
				cout << "Existe un contacto con esta clave" << endl;
				_coincidencias = true;
				break;
			}
			_lectura >> _auxClave;
		}
		if (_coincidencias == false) {
			cout << "-----Ingresa los datos de contacto-----" << endl << endl;
			cout << "Nombre: ";
			cin >> _nombre;
			cout << "Apellido: ";
			cin >> _apellido;
			cout << "Telefono: ";
			cin >> _telefono;
			cout << "Correo: ";
			cin >> _correo;
			cout << "Dirección: ";
			cin >> _direccion;
			//Almmacenar los datos
			escritura << _clave << " " << _nombre << " " << _apellido << " " << _telefono << " " << _correo << " " << _direccion << endl;
			system("cls");
			cout << "Contacto agregado correctamente" << endl;
		}
	} else {
		cout << "No se pudo abrir el archivo, es posible que no este creado." << endl;
	}
	_lectura.close();
	escritura.close();
}

void Agenda::listarContactos()
{
	ifstream _lectura("datos.txt",ios::in);
	if (_lectura.is_open()) {
		_lectura >> _clave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido >> _telefono >> _correo >> _direccion ;
			cout << "________________________________________________" << endl
					<< endl;
			cout << "Clave: " << _clave << endl;
			cout << "Nombre: " << _nombre << endl;
			cout << "Apellido: " << _apellido << endl;
			cout << "Telefono: " << _telefono << endl;
			cout << "Correo: " << _correo << endl;
			cout << "Dirección: " << _direccion << endl;
			cout << "________________________________________________" << endl << endl;
			_lectura >> _clave;
		}
	} else {
		cout << "No se pudo abrir el archivo";
	}
	_lectura.close();
}

void Agenda::buscarPorNombre()
{
	ifstream _lectura("datos.txt",ios::in);
	if (_lectura.is_open()) {
		char busqueda[20];
		cout << "Introduzca el nombre que desea buscar" << endl;
		cin >> busqueda;
		_lectura >> _clave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido >> _telefono >> _correo >> _direccion;
			if (strcmp(busqueda, _nombre) == 0) {
				cout << "________________________________________________" << endl << endl;
				cout << "Clave: " << _clave << endl;
				cout << "Nombre: " << _nombre << endl;
				cout << "Apellido: " << _apellido << endl;
				cout << "Telefono: " << _telefono << endl;
				cout << "Correo: " << _correo << endl;
				cout << "Dirección: " << _direccion << endl;
				cout << "________________________________________________" << endl << endl;
				_coincidencias = true;
			}
			_lectura >> _clave;
		}
		_lectura.close();
		if (_coincidencias == false) {
			cout << "No se encontró ninguna coincidencia con el critero de busqueda!!!" << endl;
		}
	} else {
		cout << "No se pudo abrir el archivo";
	}
	_lectura.close();
}

void Agenda::buscarPorClave()
{
	ifstream _lectura("datos.txt",ios::in);
	if (_lectura.is_open()) {
		int busqueda = 0;
		cout << "Introduzca la clave del contacto que desea buscar" << endl;
		cin >> busqueda;
		_lectura >> _clave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido >> _telefono >> _correo >> _direccion;
			if (busqueda == _clave) {
				cout << "________________________________________________" << endl << endl;
				cout << "Clave: " << _clave << endl;
				cout << "Nombre: " << _nombre << endl;
				cout << "Apellido: " << _apellido << endl;
				cout << "Telefono: " << _telefono << endl;
				cout << "Correo: " << _correo << endl;
				cout << "Dirección: " << _direccion << endl;
				cout << "________________________________________________" << endl << endl;
				_coincidencias = true;
			}
			_lectura >> _clave;
		}
		_lectura.close();
		if (_coincidencias == false) {
			cout << "No se encontró ninguna coincidencia con el critero de busqueda!!!" << endl;
		}
	}
	_lectura.close();
}

void Agenda::editar()
{
	ofstream aux;
	aux.open("auxiliar.txt", ios::out);
	ifstream _lectura;
	_lectura.open("datos.txt", ios::in);
	if (aux.is_open() && _lectura.is_open()) {
		cout << "Ingresa la clave del contacto que deseas modificar: " << endl;
		cin >> _auxClave;
		_lectura >> _clave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido >> _telefono >> _correo >> _direccion;
			if (_auxClave == _clave) {
				_coincidencias = true;
				cout << "________________________________________________" << endl << endl;
				cout << "Clave: " << _clave << endl;
				cout << "Nombre: " << _nombre << endl;
				cout << "Apellido: " << _apellido << endl;
				cout << "Telefono: " << _telefono << endl;
				cout << "Correo: " << _correo << endl;
				cout << "Dirección: " << _direccion << endl;
				cout << "________________________________________________" << endl << endl;
				cout << "------Introduce los nuevos datos del contacto------" << endl << endl;
				cout << "Nombre: ";
				cin >> _nombre;
				cout << "Apellido: ";
				cin >> _apellido;
				cout << "Telefono: ";
				cin >> _telefono;
				cout << "Correo: ";
				cin >> _correo;
				cout << "Dirección: ";
				cin >> _direccion;
				cout << "El contacto ha sido modificado" << endl << endl;
			}
			aux << _clave << " " << _nombre << " " << _apellido << " " << _telefono  << " " << _correo << " " << _direccion << endl;
			_lectura >> _clave;
		}
		if (_coincidencias == false) {
			cout << "No se encontraron coincidencias con esta clave" << endl;
		}
	} else {
		cout << "No se pudo abrir el archivo" << endl;
	}
	aux.close();
	_lectura.close();
	remove("datos.txt");
	rename("auxiliar.txt", "datos.txt");
}

void Agenda::eliminar()
{
	ifstream _lectura;
	ofstream aux;
	bool eliminar = false;
	_lectura.open("datos.txt",ios::in);
	aux.open("auxiliar.txt", ios::out);
	_lectura.open("datos.txt", ios::in);
	if (aux.is_open() && _lectura.is_open()) {
		cout << "Ingresa la clave del contacto que deseas eliminar: " << endl;
		cin >> _auxClave;
		_lectura >> _clave;
		while (!_lectura.eof()) {
			_lectura >> _nombre >> _apellido >> _telefono >> _correo >> _direccion;
			if (_auxClave == _clave) {
				_coincidencias = true;
				cout << "________________________________________________" << endl << endl;
				cout << "Clave: " << _clave << endl;
				cout << "Nombre: " << _nombre << endl;
				cout << "Apellido: " << _apellido << endl;
				cout << "Telefono: " << _telefono << endl;
				cout << "Correo: " << _correo << endl;
				cout << "Dirección: " << _direccion << endl;
				cout << "________________________________________________" << endl << endl;
				char op;
				cout << "Seguro que deseas eliminnar este contacto (S/N)?" << endl;
				cin >> op;
				if (op == 's' || op == 'S') {
					cout << "El contacto ha sido eliminado" << endl << endl;
					eliminar = true;
				}
			}
			if (eliminar == false) {
				aux << _clave << " " << _nombre << " " << _apellido << " " << _telefono << " " << _correo << " " << _direccion << endl;
				eliminar = false;
			}
			_lectura >> _clave;
		}
		if (_coincidencias == false) {
			cout << "No se encontraron coincidencias con esta clave" << endl;
		}
	} else {
		cout << "No se pudo abrir el archivo" << endl;
	}
	aux.close();
	_lectura.close();
	remove("datos.txt");
	rename("auxiliar.txt", "datos.txt");
}

Agenda::~Agenda()
{

}

