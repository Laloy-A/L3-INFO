#include "gold.h"

void initialiserGold(struct gold * g, char * polynome) {
	g->lm1 = creerCodeLongMax(polynome, "1");
	g->lm2 = creerCodeLongMax(polynome, "1 0 1");
}

ptrVecteur_t genererGold(struct gold g, size_t longeur) {
	ptrVecteur_t res, v1, v2;

	v1 = genererSequence(g.lm1, longeur);
	v2 = genererSequence(g.lm2, longeur);

	res = allouerVecteur(longeur);

	//res = v1 XOR v2
	for(size_t i = 0; i < longeur; i++)
		res->tab[i] = v1->tab[i] ^v2->tab[i];

	detruireVecteur(&v1);
	detruireVecteur(&v2);

	printf("\nValeur taille %i\n", res->taille);

	return res;
}
