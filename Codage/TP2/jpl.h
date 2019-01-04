#ifndef JPL_H
#define JPL_H

#include "longMax.h"


struct jpl {
	ptrCodeLongMax_t lm1;
	ptrCodeLongMax_t lm2;
	ptrCodeLongMax_t lm3;
};


/*
	initialise les codeurs à longeur maximale
*/
void initialiserJpl(struct jpl * jpl);


/*
	Genere une sequence aléatoire selon la méthode de Jpl

	Retourne nombre le nombre
*/
int genererJpl(struct jpl, size_t);

#endif
