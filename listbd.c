#include <stdio.h>
#include <string.h>
#include "listbd.h"


/***********************************************
*
* @Finalitat:Crear la llita
* @Parametres:void
* @Retorn:ListaBid
*
************************************************/
ListaBid LISTABID_crea () {
	
	ListaBid l;

	l.pri = NULL;
	l.pri = (Nodo*) malloc (sizeof(Nodo));
	
	if (l.pri == NULL) {
		printf("Error al pedir memoria para el primer fantasma.\n");
	}
	else {
		l.ult = NULL;
		l.ult = (Nodo*) malloc (sizeof(Nodo));
		if (l.ult == NULL) {
			printf("Error al pedir memoria para el segundo fantasma.\n");
			free(l.pri);
		}
		else {
			l.pri->sig = l.ult;
			l.pri->ant = NULL;
			
			l.ult->sig = NULL;
			l.ult->ant = l.pri;

			l.pdi = l.ult;
		}
	}
	
	
	return l;
}


/***********************************************
*
* @Finalitat:Afagir node a la llista per la dreta
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista
*			  in:e- el nombre a afegir a la llista 
* @Retorn:ListaBid
*
************************************************/
ListaBid LISTABID_anadirDerecha (ListaBid l, int e) {
	Nodo * aux;
	
	if (l.pdi->sig == NULL) {
		printf("Error estoy en el ultimo fantasma.\n");
	}
	else {
		aux = (Nodo*) malloc (sizeof(Nodo));
		if (aux == NULL) {
			printf("Error al pedir memoria.\n");
		}
		else {
			aux->e = e;
			aux->sig = l.pdi->sig;
			aux->ant = l.pdi;
			
			aux->sig->ant = aux;
			l.pdi->sig = aux;
		}
	}


	return l;
}


/***********************************************
*
* @Finalitat:Afagir node a la llista per la esquerra
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista
*			  in:e- el nombre a afegir a la llista 
* @Retorn:ListaBid
*
************************************************/
ListaBid LISTABID_anadirIzquierda (ListaBid l, int e) {
	Nodo * aux;

	if (l.pdi->ant == NULL) {
		printf("Error, no puedo añadir a la izquierda del primer fantasma.\n");
	}
	else {
		aux = (Nodo*) malloc (sizeof(Nodo));
		if (aux == NULL) {
			printf("Error al pedir memoria.\n");
		}
		else {
			aux->e = e;
			aux->sig = l.pdi;
			aux->ant = l.pdi->ant;

			aux->ant->sig = aux;
			

			l.pdi->ant = aux;
		}
	}
	return l;
}


/***********************************************
*
* @Finalitat:Afagir node a la llista de forma ordenada
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista
*			  in:e- el nombre a afegir a la llista 
* @Retorn:ListaBid
*
************************************************/
ListaBid LISTABID_anadirOrdenado (ListaBid l, int e) {


	int trobat =0;
	int primer=0;
	
	if(LISTABID_vacia (l)){
		l=LISTABID_anadirIzquierda(l,e);
		
	}else{
	l=LISTABID_irPrincipio (l);

	while (trobat==0){
			if (l.pdi->e <e && l.pdi->sig!= NULL){
					l.pdi=l.pdi->sig;
					primer=1;
				
			}else{
				l=LISTABID_anadirIzquierda(l,e);
				trobat=1;
			}
	
	}
	}
	l=LISTABID_irPrincipio (l);
	
	
	return l;
	
	
}


/***********************************************
*
* @Finalitat:Eliminar node de la llista 
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid
*
************************************************/
ListaBid LISTABID_eliminar (ListaBid l) {
	Nodo * aux;
	if(LISTABID_vacia (l)){
	
		printf("Esta vacia la lista.\n");
		
	}else{
		if (l.pdi == l.pri || l.pdi == l.ult) {
			printf("Error, estoy apuntando a un fantasma.\n");
		}
		else {
			aux = l.pdi;

			l.pdi->ant->sig = l.pdi->sig;
			l.pdi->sig->ant = l.pdi->ant;
			l.pdi = l.pdi->sig;

			free(aux);
		}
	}
	return l;
}


/***********************************************
*
* @Finalitat:Consultar valor del node de la llista 
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:int, el valor del element a consultar
*
************************************************/
int      LISTABID_consultar (ListaBid l) {
	int e = -1;

	if(LISTABID_vacia (l)){
		printf("Esta vacia la lista.\n");
		
	}else{
	
		if (l.pdi == l.pri->ant || l.pdi == l.ult->sig) {
			printf("Error, estoy apuntando a un fantasma.\n ");
		}
		else {
			e = l.pdi->e;
			printf("%d el numero a consultar\n",e);
		}
	}
	return e;
}

/***********************************************
*
* @Finalitat:Comprobar si la llista esta buida 
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:int, 1 si esta buida, 0 si no
*
************************************************/
int      LISTABID_vacia (ListaBid l) {
	return l.pri->sig == l.ult;	
}

/***********************************************
*
* @Finalitat:Comprobar si estem al final de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:int, 1 si esta al final, 0 si no
*
************************************************/
int      LISTABID_final (ListaBid l) {
	return l.pdi == l.ult;
}

/***********************************************
*
* @Finalitat:Comprobar si estem al inici de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:int, 1 si esta al inici, 0 si no
*
************************************************/
int      LISTABID_principio (ListaBid l) {
	return l.pdi == l.pri;
}

/***********************************************
*
* @Finalitat:Et mou fins l'inici de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_irPrincipio (ListaBid l) {
	
	if(!LISTABID_vacia (l)){
	l.pdi = l.pri->sig;
	}
	return l;
	
}

/***********************************************
*
* @Finalitat:Et mou fins el final de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_irFinal (ListaBid l) {
	
	if(!LISTABID_vacia (l)){
		l.pdi = l.ult->ant;
	}
	return l;
}

/***********************************************
*
* @Finalitat:Et mou un element cap a la dreta dins 
				de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_avanzar (ListaBid l) {
	
		if(!LISTABID_vacia (l)){
		if (l.pdi->sig->sig == NULL) {
			printf("Error, estoy en el ultimo fantasma.\n");
		}
		else {
			l.pdi = l.pdi->sig;
			printf("Avanzamos.\n");
		}
	}else{
		printf("Esta vacia la lista.\n");
		
	}
	return l;
	
}

/***********************************************
*
* @Finalitat:Et mou un element cap a l'esquerra dins 
				de la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_retroceder (ListaBid l) {
	
	if(!LISTABID_vacia (l)){
		if (l.pdi->ant->ant == NULL) {
			printf("Error, estoy en el primer fantasma.\n");
		}
		else {
			l.pdi = l.pdi->ant;
			printf("Retrocedemos.\n");
		}
	
	}else{
		printf("Esta vacia la lista.\n");
		
	}
	return l;
}

/***********************************************
*
* @Finalitat:Elimina la llista
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_destruye (ListaBid l) {
	Nodo * aux;

		while (l.pri != NULL) {
			aux = l.pri;
			l.pri = l.pri->sig;
			free(aux);
		}

		l.pri = NULL;
		l.ult = NULL;
		l.pdi = NULL;

		return l;

}

/***********************************************
*
* @Finalitat:Buida tots els elements de la llista excepte els fantasmes
* @Parametres:in:struct ListaBid, estructura on es
*					  guarda la llista 
* @Retorn:ListaBid, la llista actualitzada
*
************************************************/
ListaBid LISTABID_vaciar (ListaBid l) {

	l=LISTABID_irPrincipio (l);
				
	while(!LISTABID_vacia (l)){
					
		l=LISTABID_eliminar (l);
	
	}
							 
	
	return l;
}




 
