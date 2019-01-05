#include <stdio.h>
#include <stdlib.h>

#include "outils.h"
#include "longMax.h"
#include "gold.h"
#include "jpl.h"

void poly(char *);

int main(/*int argc, char const *argv[]*/) {

	// ptrCodeLongMax_t lm = creerCodeLongMax("[5, 2]", "1");
	//
	// printlnCodeLongMax(lm);
	//
	// ptrVecteur_t vec;
	// for(int i = 0; i < 1; i++) {
	// 	vec = genererSequence(lm, 10);
	// 	printVecteur(vec);
	// 	printf("\n");
	// 	detruireVecteur(&vec);
	// }
	//
	// detruireCodeLongMax(&lm);


	struct gold gold;
	struct jpl jpl;
	initialiserGold(&gold, "[16, 14, 13, 11]");
	initialiserJpl(&jpl, 3, "[2, 1]", "[3, 1]", "[5, 1]");

	ptrVecteur_t vec, vec2;

	printf("\nCodeur Gold :\n");

	for(int i = 0; i < 8; i++) {
		vec = genererGold(gold, 16);
		// printVecteur(vec);
		// printf("\n");
		detruireVecteur(&vec);
	}

	printf("\nOn passe au codeur JPL :\n");

	for(int i = 0; i < 8; i++) {
		vec2 = genererJpl(jpl, 651);
		printVecteur(vec2);
		printf("\n");
		detruireVecteur(&vec2);
	}


	return 0;
}
