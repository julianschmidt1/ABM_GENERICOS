#ifndef GEN_ABM_H_
#define GEN_ABM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Inputs.h"
#include "menu.h"

#define MAX_CHARS_NAME 51
#define MAX_CHARS_CODE 10
#define LIBRE 0
#define BAJA 1
#define OCUPADO -1

typedef struct {
	char name[MAX_CHARS_NAME];
	char lastName[MAX_CHARS_NAME];
	int age;

	int id;
	int isEmpty;
} eGenerico;

// ALTA
int abm_altaGenerico(eGenerico *lista, int tam, int id, eGenerico generico);
int abm_inicializarGenerico(eGenerico *lista, int tam);
int abm_obtenerIdGenerico(void);
int abm_obtenerIndiceLibreGenerico(eGenerico *lista, int tam);
// ENCONTRAR INDICE
int abm_encontrarGenericoPorId(eGenerico *lista, int tam, int id);
// MODIFICACION
eGenerico abm_modificacionGenerico(eGenerico Generico);
int abm_listadoModificacionGenerico(eGenerico lista[], int tam);
// BAJA
int abm_listadoBajaGenerico(eGenerico *lista, int tam);
int abm_bajaGenerico(eGenerico *lista, int tam, int id);
// INFORMES
void abm_mostrarUnGenerico(eGenerico Generico);
int abm_mostrarTodosGenerico(eGenerico *lista, int tam);
// VALIDACION
int validarIngresoOpciones(int contadorAltas, int contadorBajas);

#endif /* GEN_ABM_H_ */
