#ifndef OUTILS_H
#define OUTILS_H


/*
	Booléens
*/
typedef enum {FAUX, VRAI} bool;


/*
	Structure contenant un tableau de caracteres
*/
struct vecteur {
	int taille;
	int * tab;
};
typedef struct vecteur * ptrVecteur_t;


/*
	Alloue une structure vecteur de la taille passée en parametre

	Retourne pointeur sur le vecteur
*/
ptrVecteur_t allouerVecteur(int);


/*
	Libere l'espace mémoire du vecteur
*/
void detruireVecteur(ptrVecteur_t *);


/*
	Affiche un vecteur
*/
void printVecteur(ptrVecteur_t);


/*
	Convertie un vecteur en entier
*/
int vecToInt(ptrVecteur_t);




#endif
