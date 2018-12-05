#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

#define CARRE(n)	n*n

struct matrice {
	int taille;
	int ** tab;
};
typedef struct matrice * ptrMatrice_t;



void printMatrice(ptrMatrice_t mat){
	for(int i = 0; i < mat->taille; i++) {
		for(int j = 0; j < mat->taille; j++) {
				printf("%2d ", mat->tab[i][j]);
		}
		printf("\n");
	}
}



//Alloue l'espace memoire pour une matrice carrée de dimension n
ptrMatrice_t allouerMatrice(int n) {
	ptrMatrice_t mat = malloc(sizeof(*mat));

	mat->taille = n;

	mat->tab = malloc(sizeof(*mat->tab) * n);
	for(int i = 0; i < mat->taille; i++)
		mat->tab[i] = malloc(sizeof(**(mat->tab)) * n);

	return mat;
}

void detruireMatrice(ptrMatrice_t * mat) {
	for(int i = 0; i < (*mat)->taille; i++)
		free((*mat)->tab[i]);
	free((*mat)->tab);
	free(*mat);
	*mat = NULL;
}

//rempli hn selon l'algo de hadamard
//Hn = 	[ Hn-1	Hn-1 ]
//		[ Hn-1 -Hn-1 ]
void remplirH(ptrMatrice_t hn, ptrMatrice_t hn1) {
	int hnT = hn->taille;
	int hn1T = hn1->taille;

	//Remplissage NORD-OUEST
	for(int i = 0; i < hn1T; i++) {
		for(int j = 0; j < hn1T; j++) {
			hn->tab[i][j] = hn1->tab[i][j];
		}
	}
	//SUD-OUEST
	for(int i = hn1T; i < hnT; i++) {
		for(int j = 0; j < hn1T; j++) {
			hn->tab[i][j] = hn1->tab[i-hn1T][j];
		}
	}
	//NORD-EST
	for(int i = 0; i < hn1T; i++) {
		for(int j = hn1T; j < hnT; j++) {
			hn->tab[i][j] = hn1->tab[i][j-hn1T];
		}
	}


	// Hn-1 = -(Hn-1)
	for(int i = 0; i < hn1T; i++)
		for(int j = 0; j < hn1T; j++)
			hn1->tab[i][j] *= -1;


	for(int i = hn1T; i < hnT; i++) {
		for(int j = hn1T; j < hnT; j++) {
			hn->tab[i][j] = hn1->tab[i-hn1T][j-hn1T];
		}
	}
}


void genererHadamard(int rang) {
	ptrMatrice_t hn = allouerMatrice(1);	hn->tab[0][0] = 1;	//matrice de hadamar Hn, Hn = H1
	ptrMatrice_t hn1;	//matrice de hadamar de rang Hn+1

	int i = 1;
	do {
		i *= 2;
		hn1 = allouerMatrice(i);
		remplirH(hn1, hn);		//genere matrice de hadamar de rang Hn+1,
		detruireMatrice(&hn);
		hn = hn1;				//Hn = Hn+1
		// printMatrice(hn1);	printf("\n");
	} while( i < rang );

	// printf("Matrice de Hadamar de taille %d (arrondie à %d) :\n", rang, hn->taille);	printMatrice(hn);

	detruireMatrice(&hn1);
	// return hn;
}
