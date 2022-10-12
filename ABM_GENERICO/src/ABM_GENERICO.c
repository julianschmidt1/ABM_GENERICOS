/*
 ============================================================================
 Name        : ABM_GENERICO.c
 Author      : Juli�n Schmidt
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "gen_Abm.h"
#define MAX_GENERICOS 20

int main(void) {
	setbuf(stdout, NULL);
	int opcion;
	eGenerico genericos[MAX_GENERICOS];
	char nombre[20];
	char apellido[20];
	int idUser;

	abm_InicializarGenerico(genericos, MAX_GENERICOS);

	do {
		printf("\n 1. ALTAS \n"
				"2. MODIFICAR \n"
				"3. BAJA \n"
				"4. INFORMAR \n"
				"0. SALIR \n");
		utn_getNumero(&opcion, "\nIngrese la opcion: ",
				"La opcion ingresada no es valida", 0, 4, 99999);
		switch (opcion) {
		case 1:
			utn_getString("\nIngresa nombre: ",
					"\nNombre invalido, ingresalo de vuelta", 99999, 20,
					nombre);
			utn_getString("\nIngresa apellido: ",
					"\nApellido invalido, ingresalo de vuelta", 99999, 20,
					apellido);
			idUser = abm_ObtenerIdGenerico();
			printf("%d", idUser);
			abm_AltaGenerico(genericos, MAX_GENERICOS, idUser, nombre,
					apellido);
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			abm_MostrarTodosGenerico(genericos, MAX_GENERICOS);
			break;
		}
	} while (opcion != 0);

	return 0;
}
