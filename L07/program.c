/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: program.c
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 14.8.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IO.h"
#define BUFSIZE 30


int main(void) {
	int *lista;
	int amount=10,summa=0;
	printf("Askelanalyysi\n");
	lista = (int *)malloc(10 * sizeof(int));
	summa = lue_askeleet_listaan(lista,amount);
	printf("listan askeleet:");
	tulosta_lista(lista, amount);
	printf("\nAskelia yhteensä: %d\n",summa);
	free(lista);
	return(0);
}

/*******************************************************************/
/* eof */
