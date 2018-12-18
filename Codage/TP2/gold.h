#ifndef GOLD_H
#define GOLD_H

#include "longMax.h"


struct gold {
	ptrCodeLongMax_t lm1;
	ptrCodeLongMax_t lm2;
};


/*
	initialise les codeurs à longeur maximale
*/
void initialiserGold(struct gold *);


/*
	Genere une sequence aléatoire selon la méthode de Gold

	Retourne nombre le nombre
*/
int genererGold(struct gold);

#endif
