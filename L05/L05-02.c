/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05-02
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 25.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int tarkistaSyote(char *syote) {
	int tarkistus;
	tarkistus = isdigit(*syote);
	if (tarkistus == 0) {
		printf("Parametri ei ollut positiivinen kokonaisluku.\n");
		return(0);
	}
	else if (atoi(syote) <= 0) {
		printf("Parametri ei ollut positiivinen kokonaisluku.\n");
		return(0);
	}
	else {
		tarkistus = atoi(syote); 
		return tarkistus;
	}	
}	
	
int* varaaMuisti(int tila) {
	int *muisti;
	muisti = (int*)malloc((tila +1) * sizeof(int));
	if (muisti == NULL) {
		perror("Muistin varaus epäonnistui.\n");
		return(0);
	}
	return muisti;
}

void taytaTaulukko(int *muisti, int tila) {
	printf("Taulukossa on tilaa %d alkiolle.\n", tila);
	for (int i = 0;i < tila;i++) {
		printf("Anna %d. luku: ",i+1);
		if (scanf("%d",&muisti[i]) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			exit(0);
		}
	}
}

void tulostaTaulukko(int *muisti, int tila) {
	printf("Taulukossa on luvut: ");
	for (int i = 0;i < tila;i++) {
		printf("%d ",muisti[i]);
	}
	printf("\n");
}

void vapautaMuisti(int *muisti) {
	free(muisti);
	muisti = NULL;
}

int main(int argc, char *argv[]) {
	int tila,*muisti,i;
	for (i = 0; i < argc; i++)
		i = argc;
	if (i < 3) {
		printf("Et antanut taulukon kokoa.\n");
		return(0);
	}
	tila = tarkistaSyote(argv[1]);
	if (tila == 0)
		return(0);
	muisti = varaaMuisti(tila);
	if (muisti == 0)
		return(0);
	taytaTaulukko(muisti,tila);
	tulostaTaulukko(muisti,tila);
	vapautaMuisti(muisti);
	return(0);
}
/*******************************************************************/
/* eof */
