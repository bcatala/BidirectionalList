#include <stdio.h>
#include <string.h>
#include "listbd.h"

void main(){
	
	do{
		do {
		
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
	         
			
				break; 
				
			
			case 2:

				
				
				break; 
				
			case 3: 
			
				
	
				break; 
				
			case 4: 
			
			
				break; 
				
			case 5: 
				
				
				break; 
				
			case 6: 
			
				break; 
				
			case 7: 
			
			
				break; 
				
			case 8: 
			
				
				
			
					
				 break;
				
			case 9: 
				
				
				break;
				
			default: 
			
				break; 
			
		}

	}while(opcio!=9);
}
