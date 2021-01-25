/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03-04
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 10.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>

char *Kopiointi(char mjono[30], char kopio[30]) {
	int i;
	for(i=0; mjono[i]!='\0';i++) {
	      	kopio[i] = mjono[i];
	      	}
	kopio[i] = '\0';
	return(kopio);
}


int main(void) {

	char mjono[30];
	char kopio[30];
	printf("Anna ensimmäinen merkkijono: ");
	fgets(mjono, 30,stdin);
	
	for(int i=0; mjono[i]!='\0';i++) {
		if(mjono[i] == '\n'){
	      	mjono[i] = '\0';
	      	}
	}
	char *kopioitu = Kopiointi(mjono, kopio);
	printf("Merkkijono 1 on '%s'.\n",mjono);
	printf("Merkkijono 2 on '%s'.\n", kopioitu);
	return 0;
}
/*******************************************************************/
/* eof */
