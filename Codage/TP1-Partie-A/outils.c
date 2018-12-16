#include <stdio.h>
#include <stdlib.h>
#include "outils.h"


ptrMatrice_t allouerMatrice(int n) {
	ptrMatrice_t m = malloc(sizeof(*m));

	m->taille = n;

	m->tab = malloc(sizeof(*m->tab) * n);
	for(int i = 0; i < m->taille; i++)
		m->tab[i] = calloc(n,  sizeof(**(m->tab)));

	return m;
}


ptrVecteur_t allouerVecteur(int taille) {
	ptrVecteur_t v = malloc(sizeof(*v));
	v->taille = taille;
	v->tab = calloc(taille, sizeof(*v->tab));

	return v;
}


void detruireMatrice(ptrMatrice_t * m) {
	for(int i = 0; i < (*m)->taille; i++)
		free((*m)->tab[i]);
 	free((*m)->tab);
 	free(*m);
	*m = NULL;
}


void detruireVecteur(ptrVecteur_t * v) {
	free((*v)->tab);
	free(*v);
}


void printMatrice(ptrMatrice_t m){
	for(int i = 0; i < m->taille; i++) {
		for(int j = 0; j < m->taille; j++) {
			printf("| %2d ", m->tab[i][j]);
		}
		printf("|\n");
	}
}


void printVecteur(ptrVecteur_t v) {
	printf("Vecteur (taille = %d) : ", v->taille);
	for(int i = 0; i < v->taille; i++) {
		printf(" %2d ", v->tab[i]);
	}
}


ptrVecteur_t sommerVecteur(ptrVecteur_t a, ptrVecteur_t b) {
	ptrVecteur_t rtn = allouerVecteur(MAX(a->taille, b->taille));	//nouveau vecteur

	//parcours le nouveau vecteur
	for(int i = 0; i < rtn->taille; i++) {
		//Affecte ses nouvelles valeurs au nouveau vecteur
		//Verifier si les vecteurs ont des tailles différentes : ne pas additionner des elements hors des bornes des 2 vecteurs sources
		rtn->tab[i] = (i < a->taille ? a->tab[i] : 0) + (i < b->taille ? b->tab[i] : 0);
	}

	return rtn;
}
