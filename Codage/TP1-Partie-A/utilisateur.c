#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

int main(int argc, char * argv[]){

	if(argc != 2){
		printf("%s : <Nombre utilisateur>\n", argv[0]);
		exit(-1);
	}

	int nb_utilisateur = atoi(argv[1]);

  //arrondir au multiple de 2 superieur
  // if(nb_utilisateur){
  //
  // }

  // int mat_hadamard_0[1][1] = {{1}};
  // afficher_hadamard(mat_hadamard_0);


	genererHadamard(nb_utilisateur);
}
