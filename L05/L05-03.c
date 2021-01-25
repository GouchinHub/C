/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05-03
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 27.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define KOKO 30
#define koko 2

typedef struct Henkilo {
		char nimi[KOKO];
		int ika;
	} Henkilo;
	
int vertailu(struct Henkilo hlo[koko]) {
	if (strcmp(hlo[0].nimi,hlo[1].nimi) == 0) {
		if (hlo[0].ika == hlo[1].ika)
			printf("Annetut tiedot ovat samoja.\n");
		else
			printf("Annetut tiedot eivät ole samoja.\n");
	}
	else
		printf("Annetut tiedot eivät ole samoja.\n");
	return(0);
}

int kopiointi(struct Henkilo hlo[koko],struct Henkilo *hlo3) {
	strcpy(hlo3->nimi,hlo[0].nimi);
	hlo3->ika = hlo[0].ika;
	return(0);
}

int vertailu2(struct Henkilo hlo[koko],struct Henkilo *hlo3) {
	if (strcmp(hlo[0].nimi,hlo3->nimi) == 0) {
		if (hlo[0].ika == hlo3->ika)
			printf("Kopioinnin jälkeen tietueiden tiedot ovat samoja.\n");
	}
	else
		printf("Kopioinnin jälkeen tietueiden tiedot eivät ole samoja.\n");
	if (sizeof(hlo[koko]) == sizeof(hlo3)) {
		printf("Kopioinnin jälkeen tietueiden osoitteet ovat samoja.\n");
	}
	else
		printf("Kopioinnin jälkeen tietueiden osoitteet eivät ole samoja.\n");
	return(0);
	
}
	
int main(void) {
	struct Henkilo hlo[koko];
	printf("Anna ensimmäisen henkilön etunimi: ");
	scanf("%s",hlo[0].nimi);
	printf("Anna ensimmäisen henkilön ikä: ");
	if (scanf("%d",&hlo[0].ika) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
	}
	printf("Anna toisen henkilön etunimi: ");
	scanf("%s",hlo[1].nimi);
	printf("Anna toisen henkilön ikä: ");
	if (scanf("%d",&hlo[1].ika) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
	}
	vertailu(hlo);
	struct Henkilo *hlo3;
	hlo3 = (struct Henkilo *)malloc(1 + sizeof(struct Henkilo));
	if (hlo3 == NULL) {
		perror("Muistin varaus epäonnistui.\n");
		return(0);
	}
	kopiointi(hlo,hlo3);
	vertailu2(hlo,hlo3);
	free(hlo3);
	hlo3 == NULL;
	printf("Kiitos ohjelman käytöstä.\n");
	return(0);
}
/*******************************************************************/
/* eof */
