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
		float borneInf;
		float borneSup;
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
	float borne = 0;
	float facteur = 1/(inv->nbLettre+0.0);
	letInt->tailleInt = inv->tailleInv;

	for(i = 0; i < letInt->tailleInt; i++) {
		letInt->caractere = inv->tab[i].caractere;
		letInt->inter.borneInf = borne;
		borne += facteur*(inv->tab[i].occurence+0.0);
		letInt->inter.borneSup = borne;
	}
}

void printIntervalle(struct lettreIntervalle * letInt){

	int i;
	for(i = 0; i < inv->tailleInv; i++) {
		printf("Caractere %c [%f ; %f[\n", letInt->caractere, letInt->inter.borneInf, letInt->inter.borneSup);
	}
}



void calcul(struct lettreIntervalle * letInt){

}


long double code_art(char * seq) {

	struct inventaire inventaire;
	struct lettreIntervalle letInt;
	initInventaire(&inventaire);
	inventorier(seq, &inventaire);

	printInventaire(&inventaire);

	init_intervalle(&inventaire, &letInt);
	printIntervalle(&letInt);

	return 0;
}
