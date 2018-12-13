#include <stdio.h>
#include <stdlib.h>
#include "hdbn.h"

#define N 23

/* Permet d'afficher le message binaire */
void printMsgBinaire(int tableau[N]){

	printf("\n");
	for(int i=0; i<N; i++){
		printf("%i ", tableau[i]);
	}
}

/* Permet de coder le message binaire à la manière HDBn */
int codage_hdb(int tableau[N]){

	int dernierViol = -1;
	int dernierUn = -1;
	int i, premier, deuxieme, troisieme;
	int newTab[N];

	/* On parcourt tout le msg binaire */
	for(i=0; i<N; i++){
		/* On regarde les 3 premières valeurs */
		premier = tableau[i];
		deuxieme = tableau[i+1];
		troisieme = tableau[i+2];

		/* Si on tombe sur une suite de 0 */
		if(premier == 0 && deuxieme == 0 && troisieme == 0){
			/* On regarde l'état du dernier viol */
			/* S'il est négatif */
			if(dernierViol == -1){
				/* On regarde la valeur de dernier 1 */
				if(dernierUn == -1){
					newTab[i] = 1;
					newTab[i+1] = 0;
					newTab[i+2] = 1;
					dernierUn = 1;
					i += 2;
				}
				else{
					newTab[i] = 0;
					newTab[i+1] = 0;
					newTab[i+2] = 1;
					dernierUn = 1;
					i += 2;
				}
				dernierViol = 1;
			}
			/* S'il est positif */
			else if(dernierViol == 1){
				/* On regarde la valeur de dernier 1 */
				if(dernierUn == -1){
					newTab[i] = 0;
					newTab[i+1] = 0;
					newTab[i+2] = -1;
					dernierUn = -1;
					i += 2;
				}
				else{
					newTab[i] = -1;
					newTab[i+1] = 0;
					newTab[i+2] = -1;
					dernierUn = -1;
					i += 2;
				}
				dernierViol = -1;
			}
		}//fin if
		else{ //Sinon on est dans le cas habituel
			/* Et on ne se préoccupe que de la valeur du dernier 1 */
			/* Si la première valeur est un 1 */
			if(dernierUn == 1 && premier == 1){
				newTab[i] = -premier;
				dernierUn = -1;
			}
			else if(dernierUn == -1 && premier == 1){
				newTab[i] = premier;
				dernierUn = 1;
			}
			else{ /* Sinon il s'agit d'un 0 et on ne fait rien de spécial */
				newTab[i] = premier;
			}
		}//fin else
	}//fin for

	printf("\nMsg après hdb2");
	printMsgBinaire(newTab);

	return 0;
}

/* Fonction mère (celle qui gère les autres) */
int code_hdbn(int tableau[N]){

	printMsgBinaire(tableau);
	codage_hdb(tableau);
	printMsgBinaire(tableau);

	return 0;
}
