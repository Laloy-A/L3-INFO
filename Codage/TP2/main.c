#include <stdio.h>
#include <stdlib.h>

#include "outils.h"
#include "longMax.h"
#include "gold.h"
#include "jpl.h"



int main(/*int argc, char const *argv[]*/) {
	ptrVecteur_t vec;




	printf("\n---- Codeur à longeur maximale ----\n\nGénération de 10 nombres pseudo-aléatoires :\n");

	ptrCodeLongMax_t lm = creerCodeLongMax("[16, 14, 13, 11]", "1");
	for(int i = 0; i < 10; i++) {
		vec = genererSequence(lm, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireCodeLongMax(&lm);




	printf("\n\n\n---- Codeur de Gold ----\n\nGénération de 10 nombres pseudo-aléatoires :\n");

	struct gold gold;
	initialiserGold(&gold, "[16, 14, 13, 11]");
	for(int i = 0; i < 10; i++) {
		vec = genererGold(gold, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireGold(&gold);



	printf("\n\n\n---- Codeur JPL ----\n\nGénération de 10 nombres pseudo-aléatoires :\n");

	struct jpl jpl;

	initialiserJpl(&jpl, 3, "[2, 1]", "[3, 1]", "[5, 1]");

	for(int i = 0; i < 10; i++) {
		vec = genererJpl(jpl, 8*sizeof(int));
		printf("\n\t%d\n", vecToInt(vec));
		detruireVecteur(&vec);
	}
	detruireJpl(&jpl);



	return 0;
}
