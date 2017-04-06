//============================================================================
// Name        : Agenda.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Agenda.h";

int main() {
	int op = 0;
	do{
		Agenda* agd = new Agenda();
		cout << "Agenda de contactos --- Menu principal\n\n";
		cout
				<< "1 - Agregar contactos.\n2 - Listar contactos.\n3 - Buscar contactos por nombre.\n";
		cout
				<< "4 - Buscar contacto por clave.\n5 - Editar contacto.\n6 - Eliminar contacto.\n7 - Salir.\n";
		cin >> op;
		switch (op) {
			case 1:
				agd -> agregarContactos();
				break;
			case 2:
				agd -> listarContactos();
				break;
			case 3:
				agd -> buscarPorNombre();
				break;
			case 4:
				agd -> buscarPorClave();
				break;
			case 5:
				agd -> editar();
				break;
			case 6:
				agd -> eliminar();
				break;
			default:
				cout << "Opción no disponible\n";
				break;
		}
	}
	while(op != 7);

	return 0;
}

