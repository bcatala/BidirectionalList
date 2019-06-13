#ifndef _LISTA_BID_H
#define _LISTA_BID_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo {
	int e;
	struct _nodo * sig;
	struct _nodo * ant;
} Nodo;

typedef struct {
	Nodo * pri;
	Nodo * ult;
	Nodo * pdi;
} ListaBid;


ListaBid LISTABID_crea ();
ListaBid LISTABID_anadirDerecha (ListaBid l, int e);
ListaBid LISTABID_anadirIzquierda (ListaBid l, int e);
ListaBid LISTABID_anadirOrdenado (ListaBid l, int e);
ListaBid LISTABID_eliminar (ListaBid l);
int      LISTABID_consultar (ListaBid l);
int      LISTABID_vacia (ListaBid l);
int      LISTABID_final (ListaBid l);
int      LISTABID_principio (ListaBid l);
ListaBid LISTABID_irPrincipio (ListaBid l);
ListaBid LISTABID_irFinal (ListaBid l);
ListaBid LISTABID_avanzar (ListaBid l);
ListaBid LISTABID_retroceder (ListaBid l);
ListaBid LISTABID_destruye (ListaBid l);
ListaBid LISTABID_vaciar (ListaBid l) ;

#endif