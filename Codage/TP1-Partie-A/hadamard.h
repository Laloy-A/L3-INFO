#ifndef _HADAMARD_H_
#define _HADAMARD_H_


/*
	Structure de la matrice de hadamard / matrice carrée
*/
struct matrice {
	int taille;
	int ** tab;
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

#endif
