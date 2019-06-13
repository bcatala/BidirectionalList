#include <stdio.h>
#include <string.h>
#include "listbd.h"

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

int      LISTABID_vacia (ListaBid l) {
	return l.pri->sig == l.ult;	
}

int      LISTABID_final (ListaBid l) {
	return l.pdi == l.ult;
}

int      LISTABID_principio (ListaBid l) {
	return l.pdi == l.pri;
}

ListaBid LISTABID_irPrincipio (ListaBid l) {
	
	if(!LISTABID_vacia (l)){
	l.pdi = l.pri->sig;
	}
	return l;
	
}

ListaBid LISTABID_irFinal (ListaBid l) {
	
	if(!LISTABID_vacia (l)){
		l.pdi = l.ult->ant;
	}
	return l;
}

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

ListaBid LISTABID_vaciar (ListaBid l) {

	
	
	return l;
}




 
