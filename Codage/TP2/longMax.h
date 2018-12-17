#ifndef LONGMAX_H
#define  LONGMAX_H

#include <stdlib.h>
#include <stdio.h>
#include "outils.h"



struct codeLongueurMax {
	int taille;	//nb de registres
	char * registres;
	struct vecteur polynome;
};
typedef struct codeLongueurMax * ptrCodeLongMax_t;


ptrCodeLongMax_t creerCodeLongMax(ptrVecteur_t);

void printCodeLongMax(ptrCodeLongMax_t lm);

void printlnCodeLongMax(ptrCodeLongMax_t lm);

/*
	Tick d'horloge, decale les registres
*/
void tick(ptrCodeLongMax_t lm);

#endif
