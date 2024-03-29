/**************************************
*
*	@Proposits: Exercici 1: Llista bidireccional ordenada amb Git
* 	@Autors: Bernat Catala i Ulied 
* 	@Data creacio: 4/10/2018
* 	@Data ultima modificacio:14/06/2019
*
****************************************/

//Les llibraries
#include <stdio.h>
#include <string.h>
#include "listbd.h"

void main(){
	
	int opcio = 0;
	ListaBid l;
	int e;
	
	//Crea la Llista
	l=LISTABID_crea (); 
	
	do{
		do {
		
			//El menu amb les opcions possibles
			printf ("\nMenu:\n");
			printf ("	1- Introdueix un altre valor \n");
			printf ("	2- Consultar \n");
			printf ("	3- Avançar \n");
			printf ("	4- Retrocedir \n");
			printf ("	5- Anar Principi \n");
			printf ("	6- Anar final \n");
			printf ("	7- Eliminar element llista \n");
			printf ("	8- Buidar la llista \n");
			printf ("	9- Eliminar Llista i sortir\n");
			printf ("Opcio: ");
			scanf ("%d", &opcio);	
			
			if ( opcio < 1  || opcio > 9 ) {					 
				 
					printf ("Opcio incorrecta! \n");
				
			}
		}while ( opcio < 1 || opcio > 9 );		
		

	switch ( opcio ) {
			
			case 1: 
	         
				//Introdueir valor a la llista
				printf("Introdueix un altre valor: ");
				scanf("\n%d", &e);
				l=LISTABID_anadirOrdenado (l,e);
				
				break; 
				
			
			case 2:
				
				//Consultar valor de la llista
				e=LISTABID_consultar (l);
				
				break; 
				
			case 3: 
			
				//Avançar dins llista
				l=LISTABID_avanzar (l);
	
				break; 
				
			case 4: 
			
				//Retrocedir dins llista
				l=LISTABID_retroceder (l);
				
				break; 
				
			case 5: 
				
				//Retrocedir fins el inici de la llista
				l=LISTABID_irPrincipio (l);
				
				break; 
				
			case 6: 
			
				//Avançar fins el final de la llista
				l=LISTABID_irFinal (l);
			
				break; 
				
			case 7: 
			
				//Eliminar node de la llista
				l=LISTABID_eliminar (l);
				
				break; 
				
			case 8: 
				
				//Eliminar tots els nodes de la llista excepte fantasmes,(buidar)
				l=LISTABID_vaciar (l);
				
				break;
				
			case 9: 
				
				//Elimina la Llista
				l=LISTABID_destruye (l);
				
				break;
				
			default: 
			
				break; 
			
		}

	}while(opcio!=9);
}
