#ifndef LONGMAX_H
#define  LONGMAX_H

#include <stdlib.h>
#include <stdio.h>
#include "outils.h"



struct codeLongueurMax {
	char * registres;
	ptrVecteur_t polynome;
};



ptrVecteur_t creerCodeLongMax(ptrVecteur_t);

#endif
