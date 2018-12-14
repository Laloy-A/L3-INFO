#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hadamard.h"







/*
	Affiche la matrice
*/
void printMatrice(ptrMatrice_t mat){
	for(int i = 0; i < mat->taille; i++) {
		for(int j = 0; j < mat->taille; j++) {
				printf("| %2d ", mat->tab[i][j]);
		}
		printf("|\n");
	}
}



/*
	Alloue l'espace memoire pour une matrice carrée de taille n

	Retourne un pointeur sur l'espace alloué
*/
ptrMatrice_t allouerMatrice(int n) {
	ptrMatrice_t mat = malloc(sizeof(*mat));

	mat->taille = n;

	mat->tab = malloc(sizeof(*mat->tab) * n);
	for(int i = 0; i < mat->taille; i++)
		mat->tab[i] = malloc(sizeof(**(mat->tab)) * n);

	return mat;
}

/*
	Libère l'espace mémoire alloué pour la matrice

	Le pointeur passé en parametre est initialisé à NULL
*/
void detruireMatrice(ptrMatrice_t * mat) {
	for(int i = 0; i < (*mat)->taille; i++)
		free((*mat)->tab[i]);
	free((*mat)->tab);
	free(*mat);
	*mat = NULL;
}

/*
	Remplis la matrice hn selon l'algo de hadamard
	hn = 	[ hn1	hn1 ]
			[ hn1  -hn1 ]

	hn doit etre une matrice carrée de taille 2 fois supérieur à hn1
	Les espaces mémoire de hn et hn1 doivent exister

	Le résultat de la fonction se trouve dans la valeur pointée par hn
*/
void remplirH(ptrMatrice_t hn, ptrMatrice_t hn1) {
	int hnT = hn->taille;
	int hn1T = hn1->taille;

	// Copie hn1 au NORD-OUEST de hn
	for(int i = 0; i < hn1T; i++) {
		for(int j = 0; j < hn1T; j++) {
			hn->tab[i][j] = hn1->tab[i][j];
		}
	}
	// SUD-OUEST
	for(int i = hn1T; i < hnT; i++) {
		for(int j = 0; j < hn1T; j++) {
			hn->tab[i][j] = hn1->tab[i-hn1T][j];
		}
	}
	// NORD-EST
	for(int i = 0; i < hn1T; i++) {
		for(int j = hn1T; j < hnT; j++) {
			hn->tab[i][j] = hn1->tab[i][j-hn1T];
		}
	}


	// Écrase hn1 par -hn1		==> hn1 = -hn1
	for(int i = 0; i < hn1T; i++)
		for(int j = 0; j < hn1T; j++)
			hn1->tab[i][j] *= -1;


	// Copie au SUD-EST de hn hn1 (qui est devenue -hn1)
	for(int i = hn1T; i < hnT; i++) {
		for(int j = hn1T; j < hnT; j++) {
			hn->tab[i][j] = hn1->tab[i-hn1T][j-hn1T];
		}
	}
}


ptrMatrice_t genererHadamard(int rang) {
	ptrMatrice_t hn;

	// Initialise hn à [1] : matrice de Hadamard de rang 0
	hn = allouerMatrice(1);
	hn->tab[0][0] = 1;

	// Matrice de Hadamard de rang n+1
	ptrMatrice_t hn1;


	// Générer les matrices successives de 1 à n	;	 n étant la premiere puissance de 2 >= rang
	int i = 1;
	do {
		i *= 2;

		// Créé un matrice de rang n+1
		hn1 = allouerMatrice(i);
		// Remplie matrice de Hadamard de rang n+1 avec matrice de rang n,
		remplirH(hn1, hn);

		// Matrice Hn devient Hn+1
		detruireMatrice(&hn);
		hn = hn1;
	} while( i < rang );

	return hn1;
}







ptrTabChar_t etalement(char * str, int nbUtil, bool visualisation) {
	ptrTabChar_t tabBin = strToTabBin(str);
	ptrMatrice_t matrice = genererHadamard(nbUtil);
	ptrTabChar_t codeEtal = allouerTabChar(tabBin->taille * matrice->taille);
	int utilisateur = 1;	//quelle ligne de la matrice de H sera utilisée pour le code d'étalement

	int indiceCode = 0;
	for(int indiceTabBin = 0; indiceTabBin < tabBin->taille; indiceTabBin++) {	//parcours le tableau des elements binaires associés à la chaine str
		for(int m = 0; m < matrice->taille; m++) {
			codeEtal->tab[indiceCode] = tabBin->tab[indiceTabBin] ? matrice->tab[utilisateur][m] : matrice->tab[utilisateur][m] * -1;
			indiceCode++;
		}
	}



/*
	Visualisation de la génération du code détalement
*/
if(visualisation) {
	printf("Le code associé à l'utilisateur %d est :", utilisateur);
	for(int i = 0; i < matrice->taille; i++)	printf(" %2d", matrice->tab[utilisateur][i]);

	printf("\nLettre du message, code binaire et séquence d'étalement associée :\n\n");

	for(int i = 0; i < (int)strlen(str); i++) {
		printf("%c\n", str[i]);
		for(int j = 0; j < 8; j++) {
			printf("%d =>", tabBin->tab[i*8+j]);
			for(int k = 0; k < matrice->taille; k++)
				printf(" %2d", codeEtal->tab[(i*8+j)*matrice->taille+k]);
			printf("\n");
		}
		printf("\n");
	}
}

	detruireTabChar(&tabBin);
	detruireMatrice(&matrice);

	return codeEtal;
}












ptrTabChar_t strToTabBin(char * str) {
	ptrTabChar_t tabBin = allouerTabChar(strlen(str)*8);
	int indice = 0;

	while(*str) {
		for(int i = 0; i < 8; i++) {
			tabBin->tab[indice] = ( (*str << i) & 0b10000000 ) >> 7;
			indice++;
		}
		str++;
	}

	return tabBin;
}
