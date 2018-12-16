#ifndef _HADAMARD_H_
#define _HADAMARD_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "outils.h"


/*
	Canal idéal : ne fait rien de plus que rien...
*/
ptrVecteur_t canalIdeal(ptrVecteur_t);


/*
	Simule l'envoie de messages par n utilisateurs

	Les n utilisateurs utiliseront les n 1ers canaux disponible

	Le signal envoyé est contenu dans le retoure de la fonction dans une structure de type vecteur
*/
ptrVecteur_t codage(int n);


/*
	Recoie un signal contenu dans une structure de type vecteur.

	Recherche le nombre d'utilisateur sur le signal.
	Decode et affiche le message pour chaque utilisateur possible.
	Il se peut (pour un nombre d'utilisateurs différents d'une puissance de 2) que les messages de certains utilisateurs soient vides,
	il s'agit en fait de canaux non utilisés.
*/
void decodage(ptrVecteur_t);


/*
	Genere un code d'étalement associé à la chaîne de caractères.
	Le résultat est contenue dans un vecteur.
	La matrice est une matrice de Hadamard et l'entier, le canal (ligne de la matrice) à utiliser pour coder la chaine

	Alloue l'espace mémoire pour stocker le code

	Retourne un pointeur sur le vecteur
*/
ptrVecteur_t etalement(char *, const int, const ptrMatrice_t);


/*
	Génére une matrice de Hadamrd
	La taille de la matrice sera la premiere puissance de 2 >= rang

	Retourne pointeur sur matrice

	exemple : genererHadamard(3)
		la 1ere puissance de 2 >= 3 ==> 4,
		donc la matrice  de H sera de taille 4
		retournera pointeur sur matrice contenant :
			| 1| 1| 1| 1|
			| 1|-1| 1|-1|
			| 1| 1|-1|-1|
			| 1|-1|-1| 1|
*/
ptrMatrice_t genererHadamard(int rang);


/*
	Convertie une chaine de caractere en tableau d'elements binaires
	Chaque bit du mot est isolé dans une case du tableau

	Par exemple le caractere 'a', code ASCII 97, est associé à l'octet : 0110 0001
	La fonction retournera : 										|0|1|1|0|0|0|0|1|
*/
ptrVecteur_t strToTabBin(char *);


/*
	Convertie un vecteur en une chaine de caracteres :

	==> Concatene les elements du vecteurs : |0|1|1|0|0|0|0|1| ==> donnera l'octet 0110 0001
	La fonction ne garantie pas le résultat pour des valeurs du vecteur différentes de 0 et 1
*/
char * tabBinToStr(char *, ptrVecteur_t);

#endif
