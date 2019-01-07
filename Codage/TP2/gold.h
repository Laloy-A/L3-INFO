#ifndef GOLD_H
#define GOLD_H

#include "longMax.h"


struct gold {
	ptrCodeLongMax_t lm1;
	ptrCodeLongMax_t lm2;
};


/*
	Initialise les codeurs à longeur maximale

	gold ==> la structure à initialiser
	polynome ==> le polynome primitif pour l'initialisation des codeur a longeur max
*/
void initialiserGold(struct gold * gold, char * polynome);


/*
	Genere une sequence aléatoire selon la méthode de Gold

	Retourne nombre le nombre
*/
ptrVecteur_t genererGold(struct gold, size_t);


/*
	Libere l'espace memoire utilisé par les champs de la structure
*/
void detruireGold(struct gold *);

#endif
