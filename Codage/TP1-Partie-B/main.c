#include <stdio.h>
#include "arithm.h"
#include "hdbn.h"

int main() {

	int choix;	/* Choix de l'utilisateur */

	int code[23] = { 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1 ,1 ,0, 0 };

	do{
		/* Affichage du menu */
		printf("\nMenu :\n");
		printf(" 1 - Code Arithmétique\n");
		printf(" 2 - HDB2\n");
		printf(" 3 - HDB3\n");
		printf(" 4 - HDB4\n");
		printf(" 5 - Quitter\n");
		printf("Votre choix : ");
		scanf("%i",&choix);

		/* Traitement du choix de l'utilisateur */
		switch(choix){
			case 1 : code_art("BILL GATES"); break;
			case 2:  code_hdbn(code, choix); break;
			case 3:  code_hdbn(code, choix); break;
			case 4:  code_hdbn(code, choix); break;
			case 5:  break;
			default: printf("En cours de traitement HDB3 ...");
		}
	}
	while(choix!=5);
	printf("Au revoir !\n");
return EXIT_SUCCESS;

}
