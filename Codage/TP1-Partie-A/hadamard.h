#ifndef _HADAMARD_H_
#define _HADAMARD_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outils.h"



/*
	Génére une matrice de Hadamrd
	La taille de la matrice sera la premiere puissance de 2 >= rang

	Retourne un ptrMatrice_t : addresse d'une structure matrice
*/
ptrMatrice_t genererHadamard(int rang);


/*
	Genere le code d'étalement associé à la chaine str pour le nombre d'utilisateurs donné
	Alloue l'espace mémoire pour stocker le code

	Retourne un pointeur sur la zone mémoire
*/
ptrVecteur_t etalement(char * str, const int numUtilisateur, const ptrMatrice_t);



/*
	Simule l'envoie de messages par n utilisateurs

	Le signal envoyé est contenu dans le retoure de la fonction
*/
ptrVecteur_t codage(int n);



/*
	Canal idéal : ne fait rien...
*/
ptrVecteur_t canalIdeal(ptrVecteur_t);



void decodage(ptrVecteur_t);



/*
	Convertie une chaine de caractere en tableau d'elements binaires
	Chaque bit du mot est isolé dans une case du tableau

	Par exemple le caractere 'a', code ASCII 97, est associé à l'octet : 0110 0001
	La fonction retournera : 										|0|1|1|0|0|0|0|1|
*/
ptrVecteur_t strToTabBin(char *);

char * tabBinToStr(char *, ptrVecteur_t);

#endif
