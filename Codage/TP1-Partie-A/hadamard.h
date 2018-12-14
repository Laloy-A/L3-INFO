#ifndef _HADAMARD_H_
#define _HADAMARD_H_

#include "outils.h"


/*
	Structure de la matrice de hadamard / matrice carrée
*/
struct matrice {
	int taille;
	char ** tab;
};
typedef struct matrice * ptrMatrice_t;



/*
	Fonction d'affichage d'une matrice
*/
void printMatrice(ptrMatrice_t);


/*
	Génére une matrice de Hadamrd
	La taille de la matrice sera la premiere puissance de 2 >= rang

	Retourne un ptrMatrice_t : addresse d'une structure matrice
*/
ptrMatrice_t genererHadamard(int rang);


/*
	L'espace mémoire réservé pour la matrice est supprimé

	Le pointeur passé en parametre est remis à NULL
*/
void detruireMatrice(ptrMatrice_t *);



/*
	Genere le code d'étalement associé à la chaine str pour le nombre d'utilisateurs donné
	Alloue l'espace mémoire pour stocker le code

	Retourne un pointeur sur la zone mémoire

	visualisation : booléen qui permet de visualiser la génération du code d'étalement.
	A chaque lettre est associé sont code binaire et pour chaque bit sa séquence d'étalement.
*/
ptrTabChar_t etalement(char * str, int nbUtil, bool visualisation);






/*
	Convertie une chaine de caractere en tableau d'elements binaires
	Chaque bit du mot est isolé dans une case du tableau

	Par exemple le caractere 'a', code ASCII 97 et est associé à l'octet : 0110 0001
	tabBin contiendra le tableau suivant : 								|0|1|1|0|0|0|0|1|
*/
ptrTabChar_t strToTabBin(char *);

#endif
