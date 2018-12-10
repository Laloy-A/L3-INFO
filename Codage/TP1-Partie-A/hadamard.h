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


void afficherMatrice(ptrMatrice_t);

ptrMatrice_t genererHadamard(int rang);

void detruireMatrice(ptrMatrice_t *);

#endif
