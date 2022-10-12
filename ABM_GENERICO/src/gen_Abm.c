#include "gen_Abm.h"

int abm_ObtenerIdGenerico(void) {
	static int idIncrementalGenerico = 0;
	return idIncrementalGenerico++;
}

int abm_InicializarGenerico(eGenerico *lista, int tam) {
	int i;
	int rtn = 0;

	if (lista != NULL && tam > 0) {
		rtn = 1;
		for (i = 0; i < tam; i++) {
			lista[i].isEmpty = LIBRE;
		}
	}

	return rtn;
}

int abm_ObtenerIndiceLibreGenerico(eGenerico *lista, int tam) {
	int rtn = -1;

	if (lista != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			if (lista[i].isEmpty == LIBRE) {
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

int abm_EncontrarGenericoPorId(eGenerico *lista, int tam, int id) {
	int rtn = -1;
	int i;

	if (lista != NULL && tam > 0) {
		for (i = 0; i < tam; i++) {
			if (lista[i].id == id && lista[i].isEmpty == OCUPADO) {
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
	printf("\n\t> %d       %s       %s", Generico.id, Generico.name,
			Generico.lastName);
}

int abm_MostrarTodosGenerico(eGenerico *lista, int tam) {
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && tam > 0) {
		printf("\n\t> ID       NOMBRE       APELLIDO");
		for (i = 0; i < tam; i++) {
			if (lista[i].isEmpty == OCUPADO) {
				abm_MostrarUnGenerico(lista[i]);
				cantidad++;
			}
		}
	}

	if (cantidad > 0) {
		rtn = 1;
	}

	return rtn;
}

int abm_AltaGenerico(eGenerico *lista, int tam, int id, char name[],
		char lastName[]) {
	int rtn = 0;

	eGenerico auxGenerico;

	int index = abm_ObtenerIndiceLibreGenerico(lista, tam);
	//SI INDEX == -1 ARRAY LLENO
	//SI INDEX != -1 TENGO EN INDEX POSICION DE ARRAY LIBRE
	if (index != -1 && lista != NULL) {

		// Aca deberia recibir los datos ya cargados y asignarlos al id libre que recibo por params
		strcpy(auxGenerico.name, name);
		strcpy(auxGenerico.lastName, lastName);

		auxGenerico.id = id;
		auxGenerico.isEmpty = OCUPADO;
		lista[index] = auxGenerico;

		rtn = 1;
	}
	return rtn;
}

int abm_ListadoBajaGenerico(eGenerico *lista, int tam) {
	int rtn = -1;
	int idGenerico;
	int flag = 0;
	int confirmar = 0;

	if (abm_MostrarTodosGenerico(lista, tam)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idGenerico, "\nIngrese ID a dar de baja",
				"Valor incorrecto", 0, tam, 9999);

		while (abm_EncontrarGenericoPorId(lista, tam, idGenerico) == -1) {
			puts("\n --- ID INEXISTENTE ---");

			utn_getNumero(&idGenerico, "\nIngrese ID a dar de baja: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		utn_getNumero(&confirmar,
				"\nEsta seguro que desea dar de baja? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			abm_BajaGenerico(lista, tam, idGenerico);
		}
	}

	return rtn;
}

int abm_BajaGenerico(eGenerico *lista, int tam, int id) {
	int rtn = 0;
	int index;

	index = abm_EncontrarGenericoPorId(lista, tam, id);
	if (index != -1) {
		lista[index].isEmpty = BAJA;
		printf("\n ---- Usuario: %s %s dado de baja exitosamente ---- \n",
				lista[index].name, lista[index].lastName);
		rtn = 1;
	}

	return rtn;
}

eGenerico abm_ModificacionGenerico(eGenerico Generico) {
	eGenerico auxiliar = Generico;

	utn_getString("Nuevo nombre: ", "Error, de nuevo", 9999, MAX_CHARS_NAME,
			auxiliar.name);
	utn_getString("Nuevo apellido: ", "Error, de nuevo", 9999, MAX_CHARS_NAME,
			auxiliar.lastName);

	return auxiliar;
}

int abm_ListadoModificacionGenerico(eGenerico *lista, int tam) {
	int rtn = 0;
	int idGenerico;
	int index;
	int flag = 0;
	eGenerico auxiliar;
	int confirmar = 0;

	if (abm_MostrarTodosGenerico(lista, tam)) {
		flag = 1;
	}

	if (flag) {
		utn_getNumero(&idGenerico, "\nIngrese ID a modificar: ",
				"Valor incorrecto", 0, tam, 99999);

		while (abm_EncontrarGenericoPorId(lista, tam, idGenerico) == -1) {
			puts("NO EXISTE ID.");

			utn_getNumero(&idGenerico, "\nIngrese ID a modificar: ",
					"Valor incorrecto", 0, tam, 99999);
		}

		index = abm_EncontrarGenericoPorId(lista, tam, idGenerico);
		auxiliar = abm_ModificacionGenerico(lista[index]);

		utn_getNumero(&confirmar,
				"\nEsta seguro que modificar el usuario? (1. SI - 0. NO)",
				"Opcion incorrecta", 0, 1, 9999);
		if (confirmar) {
			lista[index] = auxiliar;
			rtn = 1;
		}
	}

	return rtn;
}
