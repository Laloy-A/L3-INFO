#include <stdio.h>
#include <stdlib.h>
#include "arithm.h"

#define N	64	//nombre de valeurs dans le tableau d'inventaire
struct inventaire {
	int tailleInv;
	int nbLettre;
	struct coprs {
		char caractere;
		int occurence;
	} tab[N];
};

struct lettreIntervalle {
	int tailleInt;
	struct intervalle {
		char caractere;
		long double borneInf;
		long double borneSup;
	} inter[N];
};

void initInventaire(struct inventaire * inv) {
	inv->tailleInv = 0;
}

void ajouterInventaire(char c, struct inventaire * inv) {
	int i;
	for(i = 0; i < inv->tailleInv; i++) {
		if(inv->tab[i].caractere == c) {
			inv->tab[i].occurence++;
			inv->nbLettre++;
			return;
		}
	}

	inv->tailleInv++;
	inv->tab[i].caractere = c;
	inv->tab[i].occurence = 1;
	inv->nbLettre++;
}

void printInventaire(struct inventaire * inv) {
	printf("Inventaire (%d) : \n", inv->tailleInv);
	for(int i = 0; i < inv->tailleInv; i++) {
		printf("\t%c | %d\n", inv->tab[i].caractere, inv->tab[i].occurence);
	}
}

void inventorier(char * seq, struct inventaire * inventaire) {
	int longSeq = strlen(seq);

	for(int i = 0; i < longSeq; i++) {
		ajouterInventaire(seq[i], inventaire);
	}
}


/* Permet d'associer l'intervalle qui correspond à chacune des lettres */
void init_intervalle(struct inventaire * inv, struct lettreIntervalle * letInt){

	int i;
	long double borne = 0;
	long double facteur = 1/(inv->nbLettre+0.0);
	letInt->tailleInt = inv->tailleInv;

	for(i = 0; i < letInt->tailleInt; i++) {
		letInt->inter[i].caractere = inv->tab[i].caractere;
		letInt->inter[i].borneInf = borne;
		borne += facteur*(inv->tab[i].occurence+0.0);
		letInt->inter[i].borneSup = borne;
	}
}

void printIntervalle(struct lettreIntervalle * letInt){

	int i;
	for(i = 0; i < letInt->tailleInt; i++) {
		printf("Caractere %c [%.12Lf ; %.12Lf[\n", letInt->inter[i].caractere, letInt->inter[i].borneInf, letInt->inter[i].borneSup);
	}
}



void calcul(struct lettreIntervalle * letInt, struct inventaire * inv){

	int i, j;

	long double NewBorneInf = letInt->inter[0].borneInf;
	long double NewBorneSup = letInt->inter[0].borneSup;
	long double tampon;
	printf("caractere %c\n", inv->tab[0].caractere);
	printf("Valeur borne inf = %.12Lf, borne supp = %.12Lf\n", NewBorneInf, NewBorneSup);

	for(i = 1; i < inv->tailleInv; i++) {
		for(j = 0; j < inv->tab[i].occurence; j++) {
			printf("caractere %c\n", inv->tab[i].caractere);

			tampon = NewBorneInf;
			NewBorneInf = tampon + ( (NewBorneSup - tampon) * letInt->inter[i].borneInf );
			NewBorneSup = tampon + ( (NewBorneSup - tampon) * letInt->inter[i].borneSup );


			printf("Valeur borne inf = %.12Lf, borne supp = %.12Lf\n", NewBorneInf, NewBorneSup);
		}
	}

	printf("BILL GATES [%.12Lf ; %.12Lf[\n", NewBorneInf, NewBorneSup);

}


long double code_art(char * seq) {

	struct inventaire inventaire;
	struct lettreIntervalle letInt;
	initInventaire(&inventaire);
	inventorier(seq, &inventaire);

	printInventaire(&inventaire);

	init_intervalle(&inventaire, &letInt);
	printIntervalle(&letInt);
	calcul(&letInt, &inventaire);

	return 0;
}
