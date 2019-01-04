#include "jpl.h"

void initialiserJpl(struct jpl * jpl) {

	jpl->lm1 = creerCodeLongMax("[2, 1]", "1");
	jpl->lm2 = creerCodeLongMax("[3, 1]", "1");
	jpl->lm3 = creerCodeLongMax("[5, 1]", "1");

}

int genererJpl(struct jpl jpl, size_t longueur) {
	ptrVecteur_t res, res2, v1, v2, v3;

	v1 = genererSequence(jpl.lm1, 3);
	v2 = genererSequence(jpl.lm2, 7);
	v3 = genererSequence(jpl.lm3, 31);

	printf("\ntest1\n");

	res = allouerVecteur(21);
	res2 = allouerVecteur(longueur);

	printf("\ntest2\n");

	//res = v1 XOR v2
	for(size_t i = 0; i < 21; i++)
		res->tab[i] = v1->tab[i] ^v2->tab[i];

	printf("\ntest3\n");

	for(size_t i = 0; i < longueur; i++)
		res2->tab[i] = res->tab[i] ^v3->tab[i];

	printf("\ntest4\n");

	detruireVecteur(&v1);
	detruireVecteur(&v2);
	detruireVecteur(&v3);

	printf("\ntest5\n");

	printf("\nValeur taille %i\n", res2->taille);
	for(int i = 0; i < res2->taille; i++) {
		printf(" %2d ", res2->tab[i]);
	}

	return res2;
}
