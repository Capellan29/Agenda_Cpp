/*
 * Agenda.h
 *
 *  Created on: Mar 4, 2017
 *      Author: Capellán
 */

#ifndef AGENDA_H_
#define AGENDA_H_

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>
#include "Agenda.h"
using namespace std;

class Agenda
{
	private:
		char _nombre[30],_apellido[30],_telefono[12],_correo[40],_direccion[60];
		bool _coincidencias;
		int _clave,_auxClave;

	public:
		Agenda();
		void agregarContactos();
		void listarContactos();
		void buscarPorNombre();
		void buscarPorClave();
		void editar();
		void eliminar();
		virtual ~Agenda();
};

#endif
