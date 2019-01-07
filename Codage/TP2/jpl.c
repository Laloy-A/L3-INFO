#include "jpl.h"
#include "stdarg.h"

void initialiserJpl(struct jpl * jpl, int nb, ...) {
	int i=0;
	int premierElt, taillePoly;
	va_list ap;
	va_start(ap, nb);
	jpl->nombrePolynome = nb;
	// printf("\n nombre de polynome = %i\n", jpl->nombrePolynome);
	while(nb > 0){
		char * polynome;
		taillePoly = 1;
		polynome = va_arg(ap, char *);
		jpl->tab[i].lm = creerCodeLongMax(polynome, "1");

		/* Sert à obtenir la longueur générée par le polynome */
		premierElt = jpl->tab[i].lm->registres->taille;
		for(int j=0; j<premierElt; j++){
			taillePoly = taillePoly*2;
		}
		taillePoly--;


		jpl->tab[i].longueur = taillePoly;
		//printf("\nLongueur polynome = %i\n", jpl->tab[i].longueur);
		nb--;
		i++;
	}

	va_end(ap);
}

ptrVecteur_t genererJpl(struct jpl jpl, size_t longueur) {
	ptrVecteur_t res, res2;
	size_t j, k;

	// v1 = genererSequence(jpl.tab[0].lm, 3);
	// v2 = genererSequence(jpl.tab[1].lm, 7);
	// v3 = genererSequence(jpl.tab[2].lm, 31);

	// printf("\n--- DEBUT AFFICHAGE VECTEUR ---\n");
	//
	// for(int i=0; i<jpl.nombrePolynome; i++){
	// 	jpl.tab[i].vec = genererSequence(jpl.tab[i].lm, jpl.tab[i].longueur);
	// 	printVecteur(jpl.tab[i].vec);
	// 	printf("\n");
	// }
	//
	// printf("\n--- FIN AFFICHAGE VECTEUR ---\n");



	res = allouerVecteur(21);
	res2 = allouerVecteur(longueur);


	j = 0;
	k = 0;
	for(size_t i = 0; i < 21; i++){

		if(i%3 == 0){
			j = 0;
		}
		if(i%7 == 0){
			k = 0;
		}
		//printf("\n--- j = %li & k = %li\n", j, k);
		res->tab[i] = jpl.tab[0].vec->tab[j] ^ jpl.tab[1].vec->tab[k];
		//printf("\n%i XOR %i = %i\n", v1->tab[j], v2->tab[k], res->tab[i]);
		j++;
		k++;
	}

	j = 0;
	k = 0;
	for(size_t i = 0; i < longueur; i++){

		if(i%21 == 0){
			j = 0;
		}
		if(i%31 == 0){
			k = 0;
		}
		//printf("\n--- j = %li & k = %li\n", j, k);
		res2->tab[i] = res->tab[j] ^ jpl.tab[2].vec->tab[k];
		//printf("\n%i XOR %i = %i\n", res->tab[j], v3->tab[k], res2->tab[i]);
		j++;
		k++;
	}


	detruireVecteur(&jpl.tab[0].vec);
	detruireVecteur(&jpl.tab[1].vec);
	detruireVecteur(&jpl.tab[2].vec);

	return res2;
}
