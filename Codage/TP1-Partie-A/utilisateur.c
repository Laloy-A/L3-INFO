#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

int main(int argc, char * argv[]){
	int nbUtil;

	if(argc != 2){
		printf("%s : <Nombre utilisateur>\n", argv[0]);
		exit(-1);
	}

	nbUtil = atoi(argv[1]);

	ptrVecteur_t code = codage(nbUtil);

	printf("Code d'étalement :\n");
	printVecteur(code);
	printf("\n");



	canalIdeal(code);


	decodage(code);


	detruireVecteur(&code);
}
