#include "gen_Abm.h"

int abm_ObtenerIdGenerico(void) {
	static int idIncrementalGenerico = 0;
	return idIncrementalGenerico++;
}

int abm_InicializarGenerico(eGenerico *list, int len) {
	int i;
	int rtn = 0;

	if (list != NULL && len > 0) {
		rtn = 1;
		for (i = 0; i < len; i++) {
			list[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

int abm_ObtenerIndiceLibreGenerico(eGenerico array[], int TAM) {
	int rtn = -1;

	if (array != NULL && TAM > 0) {
		for (int i = 0; i < TAM; i++) {
			if (array[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_EncontrarGenericoPorId(eGenerico *list, int len, int id) {
	int rtn = -1;
	int i;

	if (list != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (list[i].id == id && list[i].isEmpty == OCUPADO) {
				// Retorno indice de Generico ocupado
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

void abm_MostrarUnGenerico(eGenerico Generico) {
	// Modificar esto para que muestre data generica siempre
	/*printf("\n\t> %d %s %s %f %d %s\n", Generico.id, Generico.name,
	 Generico.lastName, Generico.price, Generico.typeGenerico,
	 Generico.flycode);*/
}

int abm_MostrarTodosGenerico(eGenerico array[], int TAM) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (array != NULL && TAM > 0) {
		printf("\n\t> ID NOMBRE APELLIDO PRECIO TIPO CODIGO");
		for (i = 0; i < TAM; i++) {
			if (array[i].isEmpty == OCUPADO) {
				abm_MostrarUnGenerico(array[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int abm_AltaGenerico(eGenerico *list, int len, int id, char name[],
		char lastName[]) {
	int rtn = 0;

	eGenerico auxGenerico;

	int index = abm_ObtenerIndiceLibreGenerico(list, len);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1 && list != NULL) {

		// Aca deberia recibir los datos ya cargados y asignarlos al id libre que recibo por params

		auxGenerico.isEmpty = OCUPADO;
		list[index] = auxGenerico;

		rtn = 1;
	}
	return rtn;
}

/**
 * \brief Permite al usuario la carga de datos inicialers
 * \param Generico array de Generico
 * \param len tam del array
 * Return 1 si encontro el Generico y -1 si no
 *  */
int abm_ListadoBajaGenerico(eGenerico list[], int len) {
	int rtn = -1;
	int idGenerico;
	int flag = 0;
	int confirm = -1;

	if (abm_MostrarTodosGenerico(list, len)) {
		//BANDERA EN 1 SI HAY Generico DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idGenerico, "Ingrese ID a dar de baja",
				"Valor incorrecto", 0, len, 9999);

		while (abm_EncontrarGenericoPorId(list, len, idGenerico) == -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idGenerico, "Ingrese ID a dar de baja: ",
					"Valor incorrecto", 0, len, 99999);
		}

		utn_getNumero(&confirm,
				"\nEsta seguro que desea dar de baja? (1. SI - 2. NO)",
				"Opcion incorrecta", 1, 2, 9999);
		if (confirm == 1) {
			abm_BajaGenerico(list, len, idGenerico);
		} else {
			rtn = -1;
		}
	}

	return rtn;
}

int abm_BajaGenerico(eGenerico *list, int len, int id) {
	int rtn = 0;
	int index;

	index = abm_EncontrarGenericoPorId(list, len, id);
	if (index != -1) {
		list[index].isEmpty = BAJA;
		printf("\n ---- Usuario: %s %s dado de baja exitosamente ---- \n",
				list[index].name, list[index].lastName);
		rtn = 1;
	}

	return rtn;
}

eGenerico abm_ModificacionGenerico(eGenerico Generico) {
	//int opc;
	eGenerico auxiliar = Generico;

	/*
	 do {
	 printf("\n--- Modificación de usuario ---\n");
	 printf("\n1. Nombre"
	 "\n2. Apellido"
	 "\n3. Precio"
	 "\n4. Tipo de pasajero"
	 "\n5. Codigo de vuelo"
	 "\n6. ESTADO DE VUELO"
	 "\n7. Volver al menú principal");
	 utn_getNumero(&opc, "\nIngrese la opcion: ", "\nOpcion erronea", 1, 6,
	 99999);

	 fflush(stdin);
	 switch (opc) {
	 case 1:
	 utn_getString("\nIngrese nombre de pasajero: ", "Nombre erroneo",
	 9999,
	 MAX_CHARS_NAME, auxiliar.name);
	 break;
	 case 2:
	 utn_getString("\nIngrese apellido de pasajero: ",
	 "Apellido erroneo", 9999,
	 MAX_CHARS_NAME, auxiliar.lastName);
	 break;
	 case 3:
	 utn_getNumeroDecimal(&auxiliar.price,
	 "\nIngresa el precio del vuelo: ",
	 "\nEl valor ingresado no es valido", 0, 10000000, 500);
	 break;
	 case 4:
	 utn_getNumero(&auxiliar.typeGenerico,
	 "\nIngrese el tipo de pasajero: ",
	 "Tipo ingresado invalido.", 1, 3, 5000);
	 break;
	 case 5:
	 utn_getString("\nIngrese el codigo de vuelo: ",
	 "Error en el codigo", 99999,
	 MAX_CHARS_CODE, auxiliar.flycode);
	 break;
	 case 6:
	 utn_getNumero(&auxiliar.typeGenerico,
	 "\nIngrese el tipo de pasajero: (1. ACTIVO / 2. INACTIVO)",
	 "Tipo ingresado invalido.", 1, 2, 5000);
	 break;
	 }

	 } while (opc != 7);
	 */

	return auxiliar;
}

int abm_ListadoModificacionGenerico(eGenerico array[], int TAM) {
	int rtn = 0;
	int idGenerico;
	int index;
	int flag = 0;
	eGenerico auxiliar;

	if (abm_MostrarTodosGenerico(array, TAM)) {
		// 1 si hay Generico para mostrar
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idGenerico, "Ingrese ID a modificar: ",
				"Valor incorrecto", 0, TAM, 99999);

		//BUSCO INDEX POR ID EN ARRAY
		while (abm_EncontrarGenericoPorId(array, TAM, idGenerico) == -1) {
			puts("NO EXISTE ID.");

			utn_getNumero(&idGenerico, "Ingrese ID a modificar: ",
					"Valor incorrecto", 0, TAM, 99999);
		}

		//OBTENGO INDEX DEL ARRAY DE Generico A MODIFICAR
		index = abm_EncontrarGenericoPorId(array, TAM, idGenerico);

		//LLAMO A FUNCION QUE MODIFICA Generico
		auxiliar = abm_ModificacionGenerico(array[index]);

		/**PREGUNTAR SI DESEA CONTINUAR*/
		//MODIFICACION ACEPTADA
		array[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}
