#include <stdio.h>
#include <stdlib.h>
#include "outils.h"



ptrVecteur_t allouerVecteur(int taille) {
	ptrVecteur_t tab = malloc(sizeof(*tab));
	tab->taille = taille;
	tab->tab = malloc(sizeof(*tab->tab)*taille);

	return tab;
}



void detruireVecteur(ptrVecteur_t * tab) {
	free((*tab)->tab);
	free(*tab);
}



void printVecteur(ptrVecteur_t tab) {
	for(int i = 0; i < tab->taille; i++) {
		printf(" %2d ", tab->tab[i]);
	}
}
