#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

// #define N 22

void afficher_hadamard(int mat_hadamard[1][1]){

  int lig, col;								/** Declaration des variables a incrementer	**/


	for(lig=0;lig<1;lig++){						/** Incrementation de ligne	**/


		for(col=0;col<1;col++){
			printf(" %i |", mat_hadamard[lig][col]);		/** Affichage de la matrice **/
		}
	}
	printf("\n\n");

}



/* Fonctionne */
// void creer_hadamard(int mat_had[][]){
//
//   int mat_had2[][] = {{0}}
//
//   for(int i=0; i<N; i++){
//     for(int j=0; j<N; j++){
//
//       if(i<(N/2) && j<(N/2){  /* NORD OUEST */
//         mat_had2[i][j] = mat_had[i][j];
//       }
//       if(i<(N/2) && j>=(N/2){ /* NORD EST */
//         mat_had2[i][j] = mat_had[i][j-(N/2)];
//       }
//       if(i>=(N/2) && j<(N/2){ /* SUD OUEST */
//         mat_had2[i][j] = mat_had[i-(N/2)][j];
//       }
//       else{ /* SUD EST */
//         mat_had2[i][j] = ( (mat_had[i-(N/2)][j-(N/2)])*(-1) );
//       }
//
//     }
//   }
//
// }


// void bidule_truc(){
//
//   int tab[N*N] = bidule_truc(tab[(N/2)*(N/2)]);
//
// }



// void copie(int mat[N][N], int mat2[N][N]){
//
// 	int lig, col;									/** Déclaration des variables **/
//
// 	for(lig=0;lig<N;lig++){							/** Incrémentation de ligne	**/
// 		for(col=0;col<N;col++){						/** Incrémentation de colonne **/
// 			mat2[lig][col] = mat[lig][col];			/** On copie le contenue de la première matrice dans la seconde	**/
// 		}
// 	}
// }





struct matrice {
	int taille;
	int * tab;
};


//Alloue l'espace memoire pour une matrice carrée de dimension n
struct matrice * allouerMatrice(int n) {
	struct matrice * mat = malloc(sizeof(*mat));

	mat->taille = n;

	printf("sizeof(int) : %lu\n", sizeof(int));
	printf("sizeof(tab) : %lu\n", sizeof(*(mat->tab)));
	mat->tab = malloc(sizeof(*(mat->tab))*n*n);

	return mat;
}

void detruireMatrice(struct matrice ** mat) {
	free((*mat)->tab);
	free(*mat);
	*mat = NULL;
}

//rempli hn selon l'algo de hadamard
//Hn = 	[ Hn-1	Hn-1 ]
//		[ Hn-1 -Hn-1 ]
void remplirH(int * hn, int tailleHn, int * hn1, int tailleHn1) {

}


void genererHadamard(int rang) {
	// int hn1 = 1;			//matrice Hn-1
	printf("Création matrice taille 1\n");
	struct matrice * hn1 = allouerMatrice(1);		//matrice Hn
	printf("Destruction matrice taille 1\n");
	detruireMatrice(&hn1);
	printf("Fin\n");

	// for(int i = 1; i <= nb_utilisateur; i *= 2) {
	// 	hn = allouerMatrice(i+1);
	// 	remplirH(hn, i+1, hn1, i);
	// }
}
