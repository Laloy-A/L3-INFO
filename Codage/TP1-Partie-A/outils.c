#include <stdio.h>
#include <stdlib.h>
#include "outils.h"



ptrMatrice_t allouerMatrice(int n) {
	ptrMatrice_t mat = malloc(sizeof(*mat));

	mat->taille = n;

	mat->tab = malloc(sizeof(*mat->tab) * n);
	for(int i = 0; i < mat->taille; i++)
		mat->tab[i] = calloc(n,  sizeof(**(mat->tab)));

	return mat;
}

ptrVecteur_t allouerVecteur(int taille) {
	ptrVecteur_t tab = malloc(sizeof(*tab));
	tab->taille = taille;
	tab->tab = calloc(taille, sizeof(*tab->tab));

	return tab;
}




void detruireVecteur(ptrVecteur_t * tab) {
	free((*tab)->tab);
	free(*tab);
}



void printMatrice(ptrMatrice_t mat){
	for(int i = 0; i < mat->taille; i++) {
		for(int j = 0; j < mat->taille; j++) {
				printf("| %2d ", mat->tab[i][j]);
		}
		printf("|\n");
	}
}

void printVecteur(ptrVecteur_t tab) {
	for(int i = 0; i < tab->taille; i++) {
		printf(" %2d ", tab->tab[i]);
	}
}
