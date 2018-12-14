#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "hadamard.h"

#define valeurAbsolue(x) fabs((double)x)












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
	if(rang == 1)
		return hn;	//Retourne H0 si 1 seul utilisateur

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







ptrVecteur_t codage(char * str, int nbUtil, int utilisateur) {
	ptrVecteur_t tabBin = strToTabBin(str);
	ptrMatrice_t matrice = genererHadamard(nbUtil);
	ptrVecteur_t codeEtal = allouerVecteur(tabBin->taille * matrice->taille);

	int indiceCode = 0;
	for(int indiceTabBin = 0; indiceTabBin < tabBin->taille; indiceTabBin++) {	//parcours le tableau des elements binaires associés à la chaine str
		for(int m = 0; m < matrice->taille; m++) {
			codeEtal->tab[indiceCode] = tabBin->tab[indiceTabBin] ? matrice->tab[utilisateur][m] : matrice->tab[utilisateur][m] * -1;
			indiceCode++;
		}
	}


/*
	Visualisation de la génération du code détalement
	Le caractere est associé à son code binaire (de haut en bas : MSB vers LSB)
	Chaque bit du caractere est associé à son code d'étalement
*/
// printf("Le code associé à l'utilisateur %d est :", utilisateur);
// for(int i = 0; i < matrice->taille; i++)	printf(" %2d", matrice->tab[utilisateur][i]);
//
// printf("\nLettre du message, code binaire et séquence d'étalement associée :\n\n");
//
// for(int i = 0; i < (int)strlen(str); i++) {
// 	printf("caractère \"%c\"\n", str[i]);
// 	for(int j = 0; j < 8; j++) {
// 		printf("%d =>", tabBin->tab[i*8+j]);
// 		for(int k = 0; k < matrice->taille; k++)
// 			printf(" %2d", codeEtal->tab[(i*8+j)*matrice->taille+k]);
// 		printf("\n");
// 	}
// 	printf("\n");
// }

	detruireVecteur(&tabBin);
	detruireMatrice(&matrice);

	return codeEtal;
}





void canalIdeal(ptrVecteur_t signal) {
	return;
}




int rechercherMaxSignal(ptrVecteur_t signal) {
	int max = 0;
	int abs;
	for(int i = 0; i < signal->taille; i++) {
		abs = valeurAbsolue(signal->tab[i]);
		if(abs > max)
			max = abs;
	}
	return max;
}

void decodage(ptrVecteur_t signal) {
	int max = rechercherMaxSignal(signal);
	printf("%d utilisateurs\n", max);

	ptrMatrice_t matrice = genererHadamard(max);

	
}





ptrVecteur_t strToTabBin(char * str) {
	ptrVecteur_t tabBin = allouerVecteur(strlen(str)*8);
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
