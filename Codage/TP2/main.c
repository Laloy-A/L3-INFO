#include <stdio.h>
#include <stdlib.h>

#include "outils.h"
#include "longMax.h"
#include "gold.h"

void poly(char *);

int main(/*int argc, char const *argv[]*/) {

	// ptrCodeLongMax_t lm = creerCodeLongMax("[16, 14, 13, 11]", "1 0 1");
	//
	// printlnCodeLongMax(lm);
	//
	// int val;
	// for(int i = 0; i < 20; i++) {
	// 	genererSequence(lm, &val, sizeof(val));
	// 	printf("%d\n", val);
	// }
	//
	// detruireCodeLongMax(&lm);


	struct gold gold;
	initialiserGold(&gold);

	for(int i = 0; i < 10; i++) {
		int n = genererGold(gold);
		printf("n = %d\n", n);
	}




	return 0;
}
