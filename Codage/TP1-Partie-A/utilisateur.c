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


	genererHadamard(nb_utilisateur);
}
