#include <stdio.h>
#include <stdlib.h>

#include "outils.h"
#include "longMax.h"
#include "gold.h"
#include "jpl.h"



int main(/*int argc, char const *argv[]*/) {
	int nbNombre = 0;
	ptrVecteur_t vec;


	do {
		printf("Combien de nombres souhaitez-vous générer ? ");
		scanf("%d", &nbNombre);
		if(nbNombre <= 0)
			printf("Oups, la valeur est <= à 0 !\n");
	} while(nbNombre <= 0);




	printf("\n---- Codeur à longueur maximale ----\n\nGénération de %d nombres pseudo-aléatoires :\n", nbNombre);

	ptrCodeLongMax_t lm = creerCodeLongMax("[16, 14, 13, 11]", "1");
	for(int i = 0; i < nbNombre; i++) {
		vec = genererSequence(lm, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireCodeLongMax(&lm);




	printf("\n\n\n---- Codeur de Gold ----\n\nGénération de %d nombres pseudo-aléatoires :\n", nbNombre);

	struct gold gold;
	initialiserGold(&gold, "[16, 14, 13, 11]");
	for(int i = 0; i < nbNombre; i++) {
		vec = genererGold(gold, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireGold(&gold);



	printf("\n\n\n---- Codeur JPL ----\n\nGénération de %d nombres pseudo-aléatoires :\n", nbNombre);

	struct jpl jpl;

	initialiserJpl(&jpl, 3, "[2, 1]", "[3, 1]", "[5, 1]");

	for(int i = 0; i < nbNombre; i++) {
		vec = genererJpl(jpl, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireJpl(&jpl);



	return 0;
}
