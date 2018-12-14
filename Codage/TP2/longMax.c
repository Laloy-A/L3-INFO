#include "longMax.h"


void printPolynome(ptrVecteur_t poly) {
	printf("[");
	for(int i = 0; i < poly->taille; i++) {
		printf(i+1 < poly->taille ? "%d, " : "%d", poly->tab[i]);
	}
	printf("]");
}

ptrVecteur_t creerCodeLongMax(ptrVecteur_t Generateur) {
	printPolynome(Generateur);	printf("\n");

	

	return 0;
}
