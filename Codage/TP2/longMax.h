#ifndef LONGMAX_H
#define  LONGMAX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "outils.h"



struct codeLongueurMax {
	int taille;	//nb de registres
	char * registres;
	ptrVecteur_t polynome;
};
typedef struct codeLongueurMax * ptrCodeLongMax_t;


/*
	Créé/Alloue et retourne un code à longueur maximale

	Il faut pour cela spécifier le polynome générateur (chaine de caracteres)
	Le polynome générateur sera de la forme : [5, 3, 2], par exemple

	init sera la sequence utilisée pout initialiser le codeur : les valeurs présentes dans les registres
	init = "1"	==> la sequence d'initialisation sera une suite de 1
	init = "0 1"==> 									  suite de 0 1
*/
ptrCodeLongMax_t creerCodeLongMax(char * poly, char * init);


/*
	Libère la mémoire utilisée pour le code a long max
*/
void detruireCodeLongMax(ptrCodeLongMax_t *);


/*
	Affiche le polynome générateur et les registres du code
*/
void printCodeLongMax(ptrCodeLongMax_t lm);


/*
	Meme chose que printCodeLongMax mais retoure à la ligne
*/
void printlnCodeLongMax(ptrCodeLongMax_t lm);


/*
	Tick d'horloge, decale les registres
	La nouvelle valeur entrante est le XOR des registrer spédifiés dans le polynome
*/
void tick(ptrCodeLongMax_t lm);

#endif
