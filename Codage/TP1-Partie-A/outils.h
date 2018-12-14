#ifndef OUTILS_H
#define OUTILS_H


/*
	Booléens
*/
typedef enum {FAUX, VRAI} bool;


/*
	Structure de matrice carrée
*/
struct matrice {
	int taille;
	char ** tab;
};
typedef struct matrice * ptrMatrice_t;


/*
	Structure contenant un tableau de caracteres
*/
struct vecteur {
	int taille;
	char * tab;
};
typedef struct vecteur * ptrVecteur_t;



/*
	Alloue l'espace memoire pour une matrice carrée de taille n
	Les chanmps de la matrice sont initialisés à 0

	Retourne un pointeur sur la matrice
*/
ptrMatrice_t allouerMatrice(int);

/*
	Alloue une structure vecteur de la taille passée en parametre
	Les champs du vecteur sont initialisés à 0

	Retourne pointeur sur le vecteur
*/
ptrVecteur_t allouerVecteur(int);



/*
	L'espace mémoire réservé pour la matrice est supprimé

	Le pointeur passé en parametre est remis à NULL
*/
void detruireMatrice(ptrMatrice_t *);

/*
	Libere l'espace mémoire du vecteur
*/
void detruireVecteur(ptrVecteur_t *);



/*
	Fonction d'affichage d'une matrice
*/
void printMatrice(ptrMatrice_t);

/*
	Affiche un vecteur
*/
void printVecteur(ptrVecteur_t);






#endif
