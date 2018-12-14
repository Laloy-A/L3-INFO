#ifndef OUTILS_H
#define OUTILS_H


/*
	Booléens
*/
typedef enum {FAUX, VRAI} bool;



/*
	Structure contenant un tableau de caracteres
*/
struct tableauChar {
	int taille;
	char * tab;
};
typedef struct tableauChar * ptrTabChar_t;




/*
	Alloue une structure tableauChar de la taille du nombre de caracteres passé en parametre
*/
ptrTabChar_t allouerTabChar(int);


/*
	Libere l'espace mémoire du tableau de char
*/
void detruireTabChar(ptrTabChar_t *);


/*
	Affiche un tableau de char
*/
void printTabChar(ptrTabChar_t);




#endif
