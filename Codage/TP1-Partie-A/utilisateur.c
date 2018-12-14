#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hadamard.h"

int main(int argc, char * argv[]){
	// ptrMatrice_t matriceH;
	char * str = "Hello World !";

	// if(argc != 2){
	// 	printf("%s : <Nombre utilisateur>\n", argv[0]);
	// 	exit(-1);
	// }

	// int nb_utilisateur = atoi(argv[1]);
	//
	// matriceH = genererHadamard(nb_utilisateur);
	//
	// printf("La matrice de Hadamard est :\n");
	// printMatrice(matriceH);




	// for(int i = 0; i < 13; i++) {
	// 	printf("%c : %d\n", str[i], str[i]);
	// }
	//
	// ptrTabChar_t tabBin = strToTabBin(str);
	//
	// printTabChar(tabBin);



	ptrTabChar_t code = etalement(str, 4, 1);

	// printf("\n\nCode d'étalement :\n");
	// printTabChar(code);


	detruireTabChar(&code);
}
