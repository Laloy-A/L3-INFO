#ifndef JPL_H
#define JPL_H

#include "longMax.h"
#define N	64

struct premier {
	int taille;
	struct nombrePremier {
		int nombre;
	} nbPremier[N];
};

struct jpl {
	int nombrePolynome;
	struct corps {
		ptrCodeLongMax_t lm;
		int longueur;
		int resLong;
		ptrVecteur_t vec;
	} tab[N];
	struct vec {
		ptrVecteur_t res;
	} vec[N];
};

/*
	initialise le tableau de nombres premiers
*/
void initialiserPremier(struct premier * nbPrem);

/*
	détermine si le chiffre est premier par rapport aux autres
*/
int estChiffrePremier(struct premier * nbPrem, int polynome);

/*
	initialise les codeurs à longueur maximale

	jpl ==> la structure à initialiser
	premier ==> la structure contenant les nombres premiers
	nb ==> le nombre de polynomes primitif pour l'initialisation des codeur a longueur max
*/
int initialiserJpl(struct jpl * jpl, struct premier * nbPrem, int nb, ...);


/*
	Genere une sequence aléatoire selon la méthode de Jpl
*/
ptrVecteur_t genererJpl(struct jpl);


/*
	Libere les champs de la structure jpl
*/
void detruireJpl(struct jpl *);

#endif
