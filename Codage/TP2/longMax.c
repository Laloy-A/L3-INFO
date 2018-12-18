#include "longMax.h"



/*
	Convertie la chaine de caracteres en un vecteur

	Seul les nombres sont pris en compte.
	Les nombres doivent etre différenciable : usage d'un séparateur " " "," ";"...
*/
ptrVecteur_t charVersVecteur(char * str) {
	//on ne sait pas à l'avance le nombre d'element que va contenir le vecteur, donc creer vecteur de meme taille que str
	ptrVecteur_t vecteur = allouerVecteur(strlen(str));

	int var;
	int indiceVecteur = 0;
	while(*str) {
		if( *str >= '0' && *str <= '9' ) {
			sscanf(str, "%d", &var);
			vecteur->tab[indiceVecteur] = var;
			indiceVecteur++;
			while( *str >= '0' && *str <= '9' )	str++;
			str--;
		}

		str++;
	}

	//on sait maintenant quel est la taille qu'il nous faut pour le vecteur (info stockée dans indiceVecteur)
	ptrVecteur_t nouveauVec = allouerVecteur(indiceVecteur);
	int indiceNouvVect = 0;
	for(int i = 0; i < indiceVecteur; i++, indiceNouvVect++)
		nouveauVec->tab[indiceNouvVect] = vecteur->tab[i];

	detruireVecteur(&vecteur);

	return nouveauVec;
}


ptrCodeLongMax_t creerCodeLongMax(char * polynomeGenerateur, char * initialisation) {
	ptrVecteur_t seqInit = charVersVecteur(initialisation);
	ptrCodeLongMax_t lm;

	if( !(lm = malloc(sizeof(*lm))) ) {
		printf("ERREUR allocation code longueur max\n");
		return NULL;
	}

	lm->polynome = charVersVecteur(polynomeGenerateur);
	lm->registres = allouerVecteur(lm->polynome->tab[0]);	//le 1er element du polynome generateur renseigne sur la taille des registres

	//affectue la valeur d'initialisation aux registres
	for(int i = 0; i < lm->registres->taille; i++)	//parcours registres
		lm->registres->tab[i] = seqInit->tab[i % seqInit->taille];	//modulo s'explique car il se peut que la sequence d'init soit de longeur < aux registres

	detruireVecteur(&seqInit);

	return lm;
}


void detruireCodeLongMax(ptrCodeLongMax_t * lm) {
	detruireVecteur(&(*lm)->polynome);
	detruireVecteur(&(*lm)->registres);
	free(*lm);
}


void genererSequence(ptrCodeLongMax_t lm, void * var, size_t longeur) {
	char * c = var;
	for(size_t i = 0; i < longeur; i++) {
		for(int j = 0; j < 8; j++) {
			*c = (*c << i) + lm->registres->tab[0];
			tick(lm);
		}
		c++;
	}
}


void tick(ptrCodeLongMax_t lm) {
	//calcul la prochaine valeur à entrer, initialiser à la valeur de sortie
	int var = lm->registres->tab[lm->polynome->tab[0] -1];

	//parcours le polynome et calcul la prochaine valeur à entrer
	//XOR sur valeurs indiquées par celui ci
	//la 1ere valeur indiquée par le polynome n'est pas pris en compte dans la boucle, car valeur d'initialisation
	for(int i = 1; i < lm->polynome->taille; i++) {
		var = var ^ lm->registres->tab[lm->polynome->tab[i] -1];
	}

	//decale les registres
	for(int i = lm->registres->taille -1; i > 0; i--) {
		lm->registres->tab[i] = lm->registres->tab[i-1];
	}

	//fait entrer la nouvelle valeur qui a été calculée
	lm->registres->tab[0] = var;
}



/*
	Affichage formaté d'un polynome générateur
*/
void printPolynome(ptrVecteur_t poly) {
	printf("[");
	for(int i = 0; i < poly->taille; i++) {
		printf(i+1 < poly->taille ? "%d, " : "%d", poly->tab[i]);
	}
	printf("]");
}


void printCodeLongMax(ptrCodeLongMax_t lm) {
	printf("Polynome : ");	printPolynome(lm->polynome);
	printf("\n");
	for(int i = 0; i < lm->registres->taille; i++)
		printf("|%d", lm->registres->tab[i]);
	printf("|");
}


void printlnCodeLongMax(ptrCodeLongMax_t lm) {
	printCodeLongMax(lm);
	printf("\n");
}
