#ifndef JPL_H
#define JPL_H

#include "longMax.h"
#define N	64

struct jpl {
	int nombrePolynome;
	struct corps {
		ptrCodeLongMax_t lm;
		int longueur;
		ptrVecteur_t vec;
	} tab[N];
};


/*
	initialise les codeurs à longeur maximale
*/
void initialiserJpl(struct jpl * jpl, int nb, ...);


/*
	Genere une sequence aléatoire selon la méthode de Jpl

	Retourne nombre le nombre
*/
ptrVecteur_t genererJpl(struct jpl, size_t);

#endif
