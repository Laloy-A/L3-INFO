#include "longMax.h"


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
	for(int i = 0; i < lm->taille; i++)
		printf("|%d", lm->registres[i]);
	printf("|");
}

void printlnCodeLongMax(ptrCodeLongMax_t lm) {
	printCodeLongMax(lm);
	printf("\n");
}


/*
	Convertie la chaine de caracteres decrivant un polynome générateur en un vecteur contenant ce meme polynome
*/
ptrVecteur_t charVersVecteur(char * str) {
	//on ne sait pas à l'avance le nombre d'element que va contenir le vecteur, donc creer vecteur de meme taille que str
	ptrVecteur_t polynome = allouerVecteur(strlen(str));

	int var;
	int indiceVecteur = 0;
	while(*str) {
		if( *str >= '0' && *str <= '9' ) {
			sscanf(str, "%d", &var);
			// printf("Entier = %d\n", var);
			polynome->tab[indiceVecteur] = var;
			indiceVecteur++;
			while( *str >= '0' && *str <= '9' )	str++;
		}

		str++;
	}

	//on sait maintenant quel est la taille qu'il nous faut pour le vecteur (info stockée dans indiceVecteur)
	ptrVecteur_t nouveauPoly = allouerVecteur(indiceVecteur);
	int indiceNouvVect = 0;
	for(int i = 0; i < indiceVecteur; i++, indiceNouvVect++)
		nouveauPoly->tab[indiceNouvVect] = polynome->tab[i];

	detruireVecteur(&polynome);

	return nouveauPoly;
}

ptrCodeLongMax_t creerCodeLongMax(char * polynomeGenerateur) {
	ptrVecteur_t generateur = charVersVecteur(polynomeGenerateur);

	ptrCodeLongMax_t lm;
	if( !(lm = malloc(sizeof(*lm))) ) {
		printf("ERREUR allocation code longueur max\n");
		return NULL;
	}
	lm->taille = generateur->tab[0];	//le 1er element du polynome generateur renseigne sur la taille des registres
	lm->polynome = generateur;
	// printf("lm->polynome = *generateur;  ==> ");	printPolynome(&lm->polynome);	printf("\n");
	if( !(lm->registres = malloc(sizeof(*lm->registres) * lm->taille)) ) {
		printf("ERREUR allocation code longueur max registres\n");
		return lm;
	}
	for(int i = 0; i < lm->taille; i++)
		lm->registres[i] = 1;

	return lm;
}

void tick(ptrCodeLongMax_t lm) {
	int var = lm->registres[lm->polynome->tab[0] -1];
	//parcours le polynome et calcul la prochaine valeur à entrer
	//XOR sur valeurs indiquées par celui ci
	for(int i = 1; i < lm->polynome->taille; i++) {
		var = var ^ lm->registres[lm->polynome->tab[i] -1];
	}

	for(int i = lm->taille -1; i > 0; i--) {
		lm->registres[i] = lm->registres[i-1];
	}
	lm->registres[0] = var;	//nouvelle valeur entrante
}

void detruireCodeLongMax(ptrCodeLongMax_t * lm) {
	detruireVecteur(&(*lm)->polynome);
	free((*lm)->registres);
	free(*lm);
}
