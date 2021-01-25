/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: IO.c
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 14.8.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 30

int lue_askeleet_listaan(int *lista, int amount){
	FILE *tiedosto;
	int i,count = 0,summa=0;
	char buffer[BUFSIZE];
	if ((tiedosto = fopen("askeldata.txt","r"))== NULL) {
		perror("Tiedoston avaus epäonnistui.");
		exit(1);
	}
	while(fgets(buffer, BUFSIZE+1, tiedosto) != NULL) {
		for(i = 0; buffer[i] != '\0';i++) {
			if(buffer[i] == '\n')
		  		buffer[i] = '\0';
		}
		char *token = strtok(buffer, ":");
		i = 0;
		
		while(token != NULL){
			if (i == 1){
				lista[count] = atoi(token);
				count++;
				summa += atoi(token);
			}
			i++;
			token = strtok(NULL, ":");
		}	
	}
	fclose(tiedosto);
	return(summa);
}

void tulosta_lista(int *lista, int amount){
	int i;
	for(i=0;i<amount;i++){
		printf("%d ",lista[i]);
	}
}
	

/*******************************************************************/
/* eof */
