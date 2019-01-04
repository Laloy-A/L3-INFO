#ifndef LONGMAX_H
#define  LONGMAX_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "outils.h"



struct codeLongueurMax {
	ptrVecteur_t registres;
	ptrVecteur_t polynome;
};
typedef struct codeLongueurMax * ptrCodeLongMax_t;


/*
	Créé/Alloue, initialise et retourne un codeur à longueur maximale

	Il faut pour cela spécifier le polynome générateur (chaine de caracteres)
	Le polynome générateur sera de la forme : [5, 3, 2], par exemple
	==> les nombres doivent etre differenciable : usage de séparateurs " "  ","  ";"  ...

	init est la sequence d'initialisation du codeur, les chiffres doivent etre différenciable
	Il est préférable d'utilisée d'initialiser le codeur avec des 0 et 1.
	exemple :
		init = "1" ou "1 1 1 1 1"	==> les registres seront tous initialisés à 1
		==> si la sequence est un pattern qui se repete, pas besoin de la décrire entierement (càd : de la taille des registres)
*/
ptrCodeLongMax_t creerCodeLongMax(char * poly, char * init);


/*
	Libère la mémoire utilisée pour le code a long max
*/
void detruireCodeLongMax(ptrCodeLongMax_t *);


/*
	Genere une sequence pseudo aléatoire de longueur donnée (en octet)

	Résultat dans var
*/
ptrVecteur_t genererSequence(ptrCodeLongMax_t lm, size_t longeur);


/*
	Affiche le polynome générateur et les registres du codeur
*/
void printCodeLongMax(ptrCodeLongMax_t lm);


/*
	printCodeLongMax avec retoure à la ligne
*/
void printlnCodeLongMax(ptrCodeLongMax_t lm);


/*
	Tick d'horloge, decale les registres du codeur
	La nouvelle valeur entrante est le XOR des registrer spédifiés dans le polynome
*/
void tick(ptrCodeLongMax_t lm);

#endif
