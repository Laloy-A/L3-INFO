#include <stdio.h>
#include <stdlib.h>
#include "hdbn.h"

#define N 23

struct hdbn {
	int dernierViol; // dernier viol (positif ou négatif)
	int dernierUn;	// dernier "1" (positif ou négatif)
	int codePositif[N];	// représente le msg codé positif
	int codeNegatif[N];	// représente le msg codé négatif
	int n;				// valeur du HDBn -> ex: HDB2 ; HDB3 ; etc
};

/* Permet d'initialiser la valeur de n */
void initN(struct hdbn * hdb, int n){
	hdb->n = n;
}

/* Permet de passer du message codé (ternaire) à deux messages codés Positif et Négatif (binaire) */
void initCodePN(struct hdbn * hdb, int msgCode[N]){

	int i;

	for(i=0; i<N; i++){
		if(msgCode[i] == 1){
			hdb->codePositif[i] = 1;
			hdb->codeNegatif[i] = 0;
		}
		else if(msgCode[i] == -1){
			hdb->codePositif[i] = 0;
			hdb->codeNegatif[i] = 1;
		}
		else{
			hdb->codePositif[i] = 0;
			hdb->codeNegatif[i] = 0;
		}
	}
}


/* Permet d'afficher le message */
void printMsgBinaire(int code[N]){

	printf("\n");
	for(int i=0; i<N; i++){
		if(code[i] == -1){
			printf("%i ", code[i]);
		}
		else{
			printf(" %i ", code[i]);
		}
	}
}

/* Calcul permettant de déterminé la valeur du message code par rapport au dernier viol et au dernier "un" */
void calcul(struct hdbn * hdb, int i, int msgCode[N]){

	int j;

	for(j=i; j<hdb->n+i+1; j++){
		if(j == i){
			if( (hdb->dernierUn == 1 && hdb->dernierViol == -1) || (hdb->dernierUn == -1 && hdb->dernierViol == 1) ){
				msgCode[j] = 0;
			}
			else{
				msgCode[j] = -hdb->dernierViol;
			}
		}
		else if(j == hdb->n+i){
			msgCode[j] = -hdb->dernierViol;
		}
		else{
			msgCode[j] = 0;
		}
	}
}



/* Permet de coder le message binaire à la manière HDBn */
int codage_hdb(struct hdbn * hdb, int code[N]){

	hdb->dernierViol = -1;
	hdb->dernierUn = -1;
	int i, j, premier;
	int msgCode[N];
	int suiteZero;

	/* On parcourt tout le msg binaire */
	for(i=0; i<N; i++){
		/* On regarde les 3 premières valeurs */
		premier = code[i];
		suiteZero = 0;

		for(j=i; j<hdb->n+i+1; j++){
			if(code[j] != 0){
				suiteZero = 1;
			}
		}
		/* Si on tombe sur une suite de 0 */
		if(suiteZero == 0){
			/* On regarde l'état du dernier viol */
			/* S'il est négatif */
			if(hdb->dernierViol == -1){
				/* On regarde la valeur de dernier 1 */
				if(hdb->dernierUn == -1){
					calcul(hdb, i, msgCode);
					hdb->dernierUn = 1;
					i += hdb->n;
				}
				else{
					calcul(hdb, i, msgCode);
					hdb->dernierUn = 1;
					i += hdb->n;
				}
				hdb->dernierViol = 1;
			}
			/* S'il est positif */
			else if(hdb->dernierViol == 1){
				/* On regarde la valeur de dernier 1 */
				if(hdb->dernierUn == -1){
					calcul(hdb, i, msgCode);
					hdb->dernierUn = -1;
					i += hdb->n;
				}
				else{
					calcul(hdb, i, msgCode);
					hdb->dernierUn = -1;
					i += hdb->n;
				}
				hdb->dernierViol = -1;
			}
		}//fin if
		else{ //Sinon on est dans le cas habituel
			/* Et on ne se préoccupe que de la valeur du dernier 1 */
			/* Si la première valeur est un 1 */
			if(hdb->dernierUn == 1 && premier == 1){
				msgCode[i] = -premier;
				hdb->dernierUn = -1;
			}
			else if(hdb->dernierUn == -1 && premier == 1){
				msgCode[i] = premier;
				hdb->dernierUn = 1;
			}
			else{ /* Sinon il s'agit d'un 0 et on ne fait rien de spécial */
				msgCode[i] = premier;
			}
		}//fin else
	}//fin for

	printf("\nMsg codé après hdb%i", hdb->n);
	printMsgBinaire(msgCode);

	initCodePN(hdb, msgCode);

	printf("\n\ncode Positif");
	printMsgBinaire(hdb->codePositif);
	printf("\ncode Négatif");
	printMsgBinaire(hdb->codeNegatif);

	return 0;
}

/* Permet de décoder le message à partir du code Positif et Négatif */
int decodage_hdb(struct hdbn * hdb){

	int i;
	int msgDecode[N];
	int code[N];
	hdb->dernierUn = -1;

	/* On passe de deux codes binaires à un seul code ternaire */
	for(i=0; i<N; i++){
		if(hdb->codePositif[i] == 1){
			code[i] = 1;
		}
		else if(hdb->codeNegatif[i] == 1){
			code[i] = -1;
		}
		else{
			code[i] = 0;
		}
	}

	printf("\n\nPassage de P et N au msg codé");
	printMsgBinaire(code);

	for(i=0; i<N; i++){
		if(code[i] != hdb->dernierUn && code[i] != 0){	// si code[i] et dernierUn ont une polarité différente
			msgDecode[i] = 1;
			hdb->dernierUn = -hdb->dernierUn;
		}
		else if(code[i] == hdb->dernierUn && code[i] != 0){	// si code[i] et dernierUn ont la même polarité
			msgDecode[i] = 0;
			msgDecode[i-hdb->n] = 0;
		}
		else{	// si code[i] = 0
			msgDecode[i] = 0;
		}

	}

	printf("\n\nMsg décodé\n\n");
	printMsgBinaire(msgDecode);

	return 0;
}



/* Fonction mère (celle qui gère les autres) */
int code_hdbn(int code[N], int n){

	struct hdbn hdb;

	initN(&hdb, n);

	printf("\nMsg non codé");
	printMsgBinaire(code);
	codage_hdb(&hdb, code);
	decodage_hdb(&hdb);

	return 0;
}
