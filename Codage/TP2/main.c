#include <stdlib.h>
#include <stdio.h>
#include "outils.h"
#include "longMax.h"


int main(/*int argc, char const *argv[]*/) {

	ptrVecteur_t polynomeGenerateur = allouerVecteur(2);
	polynomeGenerateur->tab[0] = 5;
	polynomeGenerateur->tab[1] = 2;

	creerCodeLongMax(polynomeGenerateur);

	return 0;
}
