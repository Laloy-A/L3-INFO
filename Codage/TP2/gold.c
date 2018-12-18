#include "gold.h"

void initialiserGold(struct gold * g) {
	g->lm1 = creerCodeLongMax("[16, 14, 13, 11]", "1");
	g->lm2 = creerCodeLongMax("[16, 14, 13, 11]", "1 0 1");
}

int genererGold(struct gold g) {
	int res = 0, var1, var2;
	genererSequence(g.lm1, &var1, sizeof(var1));
	genererSequence(g.lm2, &var2, sizeof(var2));

	for(size_t i = 0; i < sizeof(res)*8; i++)
		res = res + ( ( ((var1 >> i) & 0b1) ^ ((var2 >> i) & 0b1) ) << i );

	return res;
}
