#include <stdio.h>
#include <stdlib.h>
#include "outils.h"

ptrTabChar_t allouerTabChar(int taille) {
	ptrTabChar_t tab = malloc(sizeof(*tab));
	tab->taille = taille;
	tab->tab = malloc(taille);

	return tab;
}


void detruireTabChar(ptrTabChar_t * tab) {
	free((*tab)->tab);
	free(*tab);
}


void printTabChar(ptrTabChar_t tab) {
	for(int i = 0; i < tab->taille; i++) {
		printf(" %2d ", tab->tab[i]);
	}
}
