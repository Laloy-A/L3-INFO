#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

int main(int argc, char * argv[]){
	ptrMatrice_t matriceH;

	if(argc != 2){
		printf("%s : <Nombre utilisateur>\n", argv[0]);
		exit(-1);
	}

	int nb_utilisateur = atoi(argv[1]);

	matriceH = genererHadamard(nb_utilisateur);

	printf("La matrice de Hadamard est :\n");
	//afficherMatrice(matriceH);
	printMatrice(matriceH);
}
