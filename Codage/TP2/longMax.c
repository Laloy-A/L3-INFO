#include "longMax.h"


void printPolynome(ptrVecteur_t poly) {
	printf("[");
	for(int i = 0; i < poly->taille; i++) {
		printf(i+1 < poly->taille ? "%d, " : "%d", poly->tab[i]);
	}
	printf("]");
}

void printCodeLongMax(ptrCodeLongMax_t lm) {
	printPolynome(&lm->polynome);
	printf("\n");
	for(int i = 0; i < lm->taille; i++)
		printf("|%d", lm->registres[i]);
	printf("|");
}

void printlnCodeLongMax(ptrCodeLongMax_t lm) {
	printCodeLongMax(lm);
	printf("\n");
}

ptrCodeLongMax_t creerCodeLongMax(ptrVecteur_t generateur) {
	// printPolynome(generateur);	printf("\n");

	ptrCodeLongMax_t lm;
	if( !(lm = malloc(sizeof(*lm))) ) {
		printf("ERREUR allocation code longueur max\n");
		return NULL;
	}
	lm->taille = generateur->tab[0];
	lm->polynome = *generateur;
	if( !(lm->registres = malloc(sizeof(*lm->registres) * lm->taille)) ) {
		printf("ERREUR allocation code longueur max registres\n");
		return lm;
	}
	for(int i = 0; i < lm->taille; i++)
		lm->registres[i] = 1;

	return lm;
}

void tick(ptrCodeLongMax_t lm) {
	int var = lm->registres[lm->polynome.tab[0] -1];
	//parcours le polynome
	//XOR sur valeurs indiquées par celui ci
	for(int i = 1; i < lm->polynome.taille; i++) {
		var = var ^ lm->registres[lm->polynome.tab[i] -1];
	}

	// printf("Valeur de sortie du XOR = %d\n", var);

	for(int i = lm->taille -1; i > 0; i--) {
		lm->registres[i] = lm->registres[i-1];
	}
	lm->registres[0] = var;
}
