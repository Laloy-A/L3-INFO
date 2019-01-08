#include "jpl.h"
#include "stdarg.h"


/* Permet d'initialiser la taille du tableau de la structure à 0 */
void initialiserPremier(struct premier * nbPrem){
	nbPrem->taille = 0;
}

/* Renvoie vrai si le polynome est premier avec les autres nombres */
int estChiffrePremier(struct premier * nbPrem, int polynome){

	/* On test si le polynome est premier avec les autres nombres dans le tableau */
	for(int i=0; i<nbPrem->taille; i++){
		if(nbPrem->nbPremier[i].nombre > polynome){
			if(nbPrem->nbPremier[i].nombre%polynome == 0){
				return 0;
			}
		}
		else if(nbPrem->nbPremier[i].nombre < polynome){
			if(polynome%nbPrem->nbPremier[i].nombre == 0){
				return 0;
			}
		}
		else{
			return 0;
		}
	}

	/* Si on arrive ici, c'est qu'il est premier avec les autres nombres */
	nbPrem->nbPremier[nbPrem->taille].nombre = polynome;
	nbPrem->taille++;

	return 1;
}


/* Cette fonction est à arguments variables permettant de mettre autant de polynomes que voulue (3 minimums) */
int initialiserJpl(struct jpl * jpl, struct premier * nbPrem, int nb, ...) {
	int i=0;
	int premierElt, taillePoly;
	va_list ap;
	va_start(ap, nb);
	jpl->nombrePolynome = nb;

	while(nb > 0){
		char * polynome;
		taillePoly = 1;
		polynome = va_arg(ap, char *);

		jpl->tab[i].lm = creerCodeLongMax(polynome, "1");

		/* Sert à obtenir la longueur générée par le polynome */
		premierElt = jpl->tab[i].lm->registres->taille;
		/* On est test s'il est premier */
		if(!estChiffrePremier(nbPrem, premierElt)){
			return 0;
		}

		for(int j=0; j<premierElt; j++){
			taillePoly = taillePoly*2;
		}
		taillePoly--;

		jpl->tab[i].longueur = taillePoly;
		nb--;
		i++;
	}

	va_end(ap);
	return 1;
}

ptrVecteur_t genererJpl(struct jpl jpl) {

	size_t j, k;

	/* On génère pour chaque vecteur la sequence pour associée aux polynomes */
	for(int i=0; i<jpl.nombrePolynome; i++){
		jpl.tab[i].vec = genererSequence(jpl.tab[i].lm, jpl.tab[i].longueur);
		if(i==0){
			jpl.vec[i].res = genererSequence(jpl.tab[i].lm, jpl.tab[i].longueur);
		}
	}

	/* On alloue la memoire aux vecteurs */
	jpl.tab[0].resLong = jpl.tab[0].longueur;
	for(int i=0; i<(jpl.nombrePolynome -1); i++){
		jpl.tab[i+1].resLong = jpl.tab[i].resLong * jpl.tab[i+1].longueur;
		jpl.vec[i+1].res = allouerVecteur(jpl.tab[i+1].resLong);
	}


	/* On effectue le XOR avec les vecteurs de longueurs différentes */
	for(int i=0; i<jpl.nombrePolynome -1; i++){
		j = 0;
		k = 0;
		for(size_t i2 = 0; i2 < jpl.tab[i+1].resLong; i2++){

			if(i2%jpl.tab[i].longueur == 0){
				j = 0;
			}
			if(i2%jpl.tab[i+1].longueur == 0){
				k = 0;
			}
			jpl.vec[i+1].res->tab[i2] = jpl.vec[i].res->tab[j] ^ jpl.tab[i+1].vec->tab[k];
			j++;
			k++;
		}
		jpl.tab[i+1].longueur = jpl.tab[i].longueur * jpl.tab[i+1].longueur;
	}

	/* On libère l'espace mémoire */
	for(int i=0; i<jpl.nombrePolynome; i++){
		detruireVecteur(&jpl.tab[i].vec);
	}

	/* On renvoie le vecteur contenant le résultat total */
	return jpl.vec[jpl.nombrePolynome-1].res;
}

/* Permet de libérer l'espace mémoire */
void detruireJpl(struct jpl * jpl) {
	for(int i = 0; i < jpl->nombrePolynome; i++)
		detruireCodeLongMax(&jpl->tab[i].lm);
}
