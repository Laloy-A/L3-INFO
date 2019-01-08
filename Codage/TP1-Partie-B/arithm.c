#include <stdio.h>
#include <stdlib.h>
#include "arithm.h"

#define N	64	//nombre de valeurs dans le tableau d'inventaire


struct inventaire {
	int tailleInv;		// nombre de lettre unique
	int nbLettre;			// nombre de lettre au total
	struct corps {		// contient un tableau qui associe chaque lettre unique avec son nombre d'apparition
		char caractere;
		int occurence;
	} tab[N];
};

struct lettreIntervalle {
	int tailleInt;						// nombre de lettre unique
	struct intervalle {				// contient un tableau associant pour chaque caractère sa borne inférieure et supérieure
		char caractere;
		long double borneInf;
		long double borneSup;
	} inter[N];
};

struct messageIntervalle {	// contient la borne inférieure et supérieure du message codé
	long double borneInf;
	long double borneSup;
};

/* Permet d'initialiser la taille de l'inventaire à 0 */
void initInventaire(struct inventaire * inv) {
	inv->tailleInv = 0;
}

/* Permet d'ajouter un caractère à l'inventaire en gérant les occurences */
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

/* Permet d'afficher l'inventaire */
void printInventaire(struct inventaire * inv) {
	printf("Inventaire (%d) : \n", inv->tailleInv);
	for(int i = 0; i < inv->tailleInv; i++) {
		printf("\t%c | %d\n", inv->tab[i].caractere, inv->tab[i].occurence);
	}
}

/* Permet d'ajouter une chaine de caractère à l'inventaire en utilisant ajouterInventaire(char, struct inventaire *) */
void inventorier(char * seq, struct inventaire * inv) {
	int longSeq = strlen(seq);

	for(int i = 0; i < longSeq; i++) {
		ajouterInventaire(seq[i], inv);
	}
}


/* Permet d'associer l'intervalle qui correspond à chacune des lettres */
void initIntervalle(struct inventaire * inv, struct lettreIntervalle * letInt){

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

/* Permet d'afficher l'intervalle pour chaque lettre unique */
void printIntervalle(struct lettreIntervalle * letInt){

	int i;

	for(i = 0; i < letInt->tailleInt; i++) {
		printf("Caractere %c [%.12Lf ; %.12Lf[\n", letInt->inter[i].caractere, letInt->inter[i].borneInf, letInt->inter[i].borneSup);
	}
}

/* Permet de coder la chaine de caractère gràce aux intervalles */
void codage(struct lettreIntervalle * letInt, struct inventaire * inv, struct messageIntervalle * msg, char * seq){

	int i, j;
	char lettre;

	msg->borneInf = letInt->inter[0].borneInf;
	msg->borneSup = letInt->inter[0].borneSup;

	long double tampon;
	printf("caractere %c\n", inv->tab[0].caractere);
	printf("Valeur borne inf = %.12Lf, borne supp = %.12Lf\n", msg->borneInf, msg->borneSup);

	for(i = 1; i < inv->nbLettre; i++) {

		lettre = seq[i];
		for(j = 0; j < inv->tailleInv; j++){
			if(lettre == letInt->inter[j].caractere){
				break;
			}
		}

		printf("caractere %c\n", inv->tab[j].caractere);

		tampon = msg->borneInf;
		msg->borneInf = tampon + ( (msg->borneSup - tampon) * letInt->inter[j].borneInf );
		msg->borneSup = tampon + ( (msg->borneSup - tampon) * letInt->inter[j].borneSup );

		printf("Valeur borne inf = %.12Lf, borne supp = %.12Lf\n", msg->borneInf, msg->borneSup);

	}
	printf("%s [%.*4$Lf ; %.*4$Lf[\n", seq, msg->borneInf, msg->borneSup,  inv->nbLettre);
}

/* Permet de décoder le message coder précédemment */
void decodage(struct lettreIntervalle * letInt, struct messageIntervalle * msg, struct inventaire * inv){

	int i, j;

	printf("\n\n");

	for(j = 0; j < inv->nbLettre; j++){ // On parcourt autant que le nombre de lettre dans la chaine
		for(i = 0; i < inv->tailleInv; i++){ // On parcourt l'ensemble des lettres de l'inventaire
			if( (msg->borneInf >= letInt->inter[i].borneInf) && (msg->borneInf < letInt->inter[i].borneSup) ){
				printf("%c - valeur borne inf %.*5$Lf - borne inf lettre %.*5$Lf - borne sup lettre %.*5$Lf\n", letInt->inter[i].caractere, msg->borneInf, letInt->inter[i].borneInf, letInt->inter[i].borneSup, inv->nbLettre);
				msg->borneInf = (msg->borneInf - letInt->inter[i].borneInf)/(letInt->inter[i].borneSup - letInt->inter[i].borneInf);
				break;
			}
		}
	}
}

/* Fonction mère (celle qui gère les autres) */
long double code_art(char * seq) {

	struct inventaire inventaire;
	struct lettreIntervalle letInt;
	struct messageIntervalle msg;
	initInventaire(&inventaire);
	inventorier(seq, &inventaire);

	printInventaire(&inventaire);

	initIntervalle(&inventaire, &letInt);
	printIntervalle(&letInt);
	printf("\n\t--- Codage ---\n\n");
	codage(&letInt, &inventaire, &msg, seq);
	printf("\n\t--- Décodage ---");
	decodage(&letInt, &msg, &inventaire);

	return 0;
}
