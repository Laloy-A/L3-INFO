#ifndef _HADAMARD_H_
#define _HADAMARD_H_


/*
	Structure de la matrice de hadamard / matrice carrée
*/
struct matrice {
	int taille;
	char ** tab;
};
typedef struct matrice * ptrMatrice_t;


/*
	Structure contenant un tableau de caracteres
*/
struct tableauChar {
	int taille;
	char * str;
};
typedef struct tableauChar * ptrTabChar_t;



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




ptrTabChar_t etalement(char * str, int nbUtil);





/*
	Alloue une structure tableauChar de la taille du nombre de caracteres passé en parametre
*/
ptrTabChar_t allouerTabChar(int);

/*
	Convertie une chaine de caractere en tableau d'elements binaires
	Chaque bit du mot est isolé dans une case du tableau

	Par exemple le caractere 'a', code ASCII 97 et est associé à l'octet : 0110 0001
	tabBin contiendra le tableau suivant : 								|0|1|1|0|0|0|0|1|
*/
ptrTabChar_t strToTabBin(char *);

void printTabChar(ptrTabChar_t);

#endif
