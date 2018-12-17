#include <stdio.h>
#include <stdlib.h>

#include "outils.h"
#include "longMax.h"

void poly(char *);

int main(/*int argc, char const *argv[]*/) {

	ptrCodeLongMax_t lm = creerCodeLongMax("[5, 2]");

	printlnCodeLongMax(lm);
	
	for(int i = 0; i < 10; i++) {

		tick(lm);

		printlnCodeLongMax(lm);
	}

	detruireCodeLongMax(&lm);

	return 0;
}
