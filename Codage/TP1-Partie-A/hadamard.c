#include "hadamard.h"


/*
	Remplis la matrice hn selon l'algo de Hadamard
	hn = 	[ hn1	hn1 ]
			[ hn1  -hn1 ]

	hn doit etre une matrice carrée de taille 2 fois supérieur à hn1
	Les espaces mémoire de hn et hn1 doivent exister

	Le résultat de la fonction se trouve dans la matrice hn
*/
void remplirH(ptrMatrice_t hn, ptrMatrice_t hn1);


/*
	Recherche la maximum (positif pu négatif) d'un vecteur

	Le résultat de la fonction est la valeur abcolue de ce max
*/
int rechercherMaxSignal(ptrVecteur_t signal);



ptrVecteur_t canalIdeal(ptrVecteur_t signal) {
	return signal;
}


ptrVecteur_t codage(int nbUtilisateurs) {
	if(nbUtilisateurs <= 0) {
		printf("ERREUR : Nombre d'utilisateur <= 0 (%d) ! Nombre positif non nul exigé.\n", nbUtilisateurs);
		return NULL;
	}

	ptrMatrice_t matrice = genererHadamard(nbUtilisateurs);
	ptrVecteur_t a, b, codeEtalement;

	char str[128];
	sprintf(str, "Je suis l'utilisateur %d !", nbUtilisateurs);

	//si 3 utilisatateur : utilisateur 3 envoie le message "3" et est associé au 3eme code d'étalement (canal) de la matrice de H (ligne d'indice 2)
	codeEtalement = etalement(str, nbUtilisateurs-1, matrice);

	while(--nbUtilisateurs) {
		sprintf(str, "Je suis l'utilisateur %d !", nbUtilisateurs);

		a = etalement(str, nbUtilisateurs-1, matrice);
		b = codeEtalement;
		codeEtalement = sommerVecteur(a, b);

		detruireVecteur(&a);
		detruireVecteur(&b);
	}

	detruireMatrice(&matrice);

	return codeEtalement;
}


void decodage(ptrVecteur_t signal) {
	int max = rechercherMaxSignal(signal);

	ptrMatrice_t matrice = genererHadamard(max);

	ptrVecteur_t tabBin = allouerVecteur(signal->taille / matrice->taille);

	int codeEtal = matrice->taille-1;
	while(codeEtal >= 0) {

			int bit = 0;
			int indiceSignal = 0, indiceTabBin = 0;
			while(indiceSignal < signal->taille) {
				for(int indiceH = 0; indiceH < matrice->taille; indiceH++, indiceSignal++) {
					bit += signal->tab[indiceSignal] * matrice->tab[codeEtal][indiceH];
				}
				bit /= matrice->taille;
				tabBin->tab[indiceTabBin] = (bit +1) / 2;	//Convertie -1 / 1 => 0 / 1		affecte dans tabBin
				indiceTabBin++;
				bit = 0;
			}

			char str[128];
			tabBinToStr(str, tabBin);
			printf("Chaîne associée à l'utilisateur %d : \"%s\"\n", codeEtal+1, str);

		codeEtal--;
	}

	detruireVecteur(&tabBin);
	detruireMatrice(&matrice);
}


ptrVecteur_t etalement(char * str, const int numUtilisateur, const ptrMatrice_t matrice) {
	if(numUtilisateur > matrice->taille && numUtilisateur >= 0) {
		printf("ERREUR, le canal (%d) pour la génération du code d'étalement n'est pas correcte [0;%d]\n !", numUtilisateur, matrice->taille);
		return NULL;
	}

	ptrVecteur_t tabBin = strToTabBin(str);

	ptrVecteur_t codeEtal = allouerVecteur(tabBin->taille * matrice->taille);

	int indiceCode = 0;
	for(int indiceTabBin = 0; indiceTabBin < tabBin->taille; indiceTabBin++) {	//parcours le tableau des elements binaires associés à la chaine str
		for(int m = 0; m < matrice->taille; m++) {
			//calcul le code d'etalement de l'element binaire
			codeEtal->tab[indiceCode] = tabBin->tab[indiceTabBin] ? matrice->tab[numUtilisateur][m] : matrice->tab[numUtilisateur][m] * -1;
			indiceCode++;
		}
	}


/*
	Visualisation de la génération du code détalement
	Le caractere est associé à son code binaire (de haut en bas : MSB vers LSB)
	Chaque bit du caractere est associé à son code d'étalement
*/
// printf("Le code associé à l'utilisateur %d est :", numUtilisateur);
// for(int i = 0; i < matrice->taille; i++)	printf(" %2d", matrice->tab[numUtilisateur][i]);
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

	return codeEtal;
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


char * tabBinToStr(char * dest, ptrVecteur_t tabBin) {
	int indiceStr = 0;

	int indiceTabBin = 0;
	while(indiceTabBin < tabBin->taille) {
		char c = 0;
		for(int i = 0; i < 8; i++, indiceTabBin++) {
			c = (c << 1) + tabBin->tab[indiceTabBin];
		}
		dest[indiceStr] = c;
		indiceStr++;
	}
	dest[indiceStr] = '\0';

	return dest;
}
