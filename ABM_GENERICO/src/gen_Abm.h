#ifndef GEN_ABM_H_
#define GEN_ABM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"

#define MAX_CHARS_NAME 51
#define MAX_CHARS_CODE 10
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1

typedef struct {
	char name[MAX_CHARS_NAME];
	char lastName[MAX_CHARS_NAME];

	int id;
	int isEmpty;
} eGenerico;

int abm_ObtenerIdGenerico(void);
int abm_InicializarGenerico(eGenerico *list, int len);
int abm_ObtenerIndiceLibreGenerico(eGenerico array[], int TAM);
int abm_EncontrarGenericoPorId(eGenerico *list, int len, int id);
void abm_MostrarUnGenerico(eGenerico Generico);
int abm_MostrarTodosGenerico(eGenerico array[], int TAM);
int abm_AltaGenerico(eGenerico *list, int len, int id, char name[],
		char lastName[]);
int abm_ListadoBajaGenerico(eGenerico list[], int len);
int abm_BajaGenerico(eGenerico *list, int len, int id);
eGenerico abm_ModificacionGenerico(eGenerico Generico);
int abm_ListadoModificacionGenerico(eGenerico array[], int TAM);

#endif /* GEN_ABM_H_ */
