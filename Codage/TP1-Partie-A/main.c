#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hadamard.h"

int main(int argc, char * argv[]){
	int nbUtil;
	bool verbose;

	if(argc != 3){
		printf("%s : <Nombre utilisateur> <verbose (0/1)>\n", argv[0]);
		exit(-1);
	}

	nbUtil = atoi(argv[1]);
	if(nbUtil <= 0) {
		printf("Nombre utilisateur <= 0\n");
		exit(-1);
	}
	verbose = atoi(argv[2]);


	printf("==> Génération du signal pour les %d utilisateurs\n\n", nbUtil);
	ptrVecteur_t code = codage(nbUtil, verbose);


	printf("==> Un petit tour par le canal idéal\n\n");
	canalIdeal(code);


	printf("==> Décodage du signal\n");
	decodage(code);


	detruireVecteur(&code);
}
