/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05-04
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 27.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

int *muisti(int *taulukko,int koko) {
	taulukko = (int *)malloc((koko + 1) * sizeof(int));
	if (taulukko == NULL) {
		perror("Muistin varaus epäonnistui.\n");
		return(0);
	}
	for(int i = 0; i < koko; i++) {
		taulukko[i] = i;
	}
	return(taulukko);
}

int tulostus(int *taulukko,int koko) {
	if (koko == 0) {
		printf("Taulukko on tyhjä.\n");
		return(0);
	}
	else {
		printf("Taulukon alkiot ovat: ");
		for(int i = 0; i < koko;i++) {
		printf("%d ",taulukko[i]);
		}
		printf("\n");
		return(0);
	}
}

int main(void) {
	int  valinta, *taulukko, koko = 0;
	while (TRUE) {
		printf("1) Tulosta taulukon alkiot\n");
		printf("2) Muuta taulukon kokoa\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		if (scanf("%d", &valinta) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			exit(0);
		}
		switch (valinta) {
			case 1:
				tulostus(taulukko, koko);
				break;
			case 2:
				printf("Anna taulukon uusi koko: ");
				if (scanf("%d",&valinta) != 1) {
					fprintf(stderr,"Virheellinen syöte\n");
					return(0);
				}
				else if (valinta < 0) {
					printf("Taulukon koko ei voi olla negatiivinen.\n");
					break;
				}
				else
					koko = valinta;
				taulukko = muisti(taulukko,koko);
				break;
			case 0:
				free(taulukko);
				taulukko = NULL;
				printf("Kiitos ohjelman käytöstä.\n");
				return(0);
			default:
				printf("\nTuntematon valinta, yritä uudestaan.\n");
				break;
			}
		}
	return(0);
}
/*******************************************************************/
/* eof */
