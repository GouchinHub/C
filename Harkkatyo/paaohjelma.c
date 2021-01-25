/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: paaohjelma.c
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämäärä: 7.7.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ali1.h"
#include "ali2.h"
#define TRUE 1
#define KOKO 100

struct solmu {
	int vuosi,kuu,paiva,klo,lampo;
	struct solmu *seuraava;
};

struct solmu2 {
	char setnimi[KOKO];
	int vuosi,min,max,karvo;
	struct solmu2 *seuraava;
};

int subvalikko(void) {
	int valinta;
	printf("\nMikä kuukausianalyysi tallennetaan?\n");
	printf("1) Keskilämpötila\n");
	printf("2) Minimilämpötila\n");
	printf("3) Maksimilämpötila\n");
	printf("Valintasi: ");
	if (scanf("%d", &valinta) != 1) {
		fprintf(stderr,"Virheellinen syöte\n");
		exit(0);
	}
	return(valinta);
}

int valikko(void) {
	int valinta;
	printf("\nValitse haluamasi toiminto alla olevasta valikosta:\n");
	printf("1) Lue lämpötilatiedosto\n");
	printf("2) Tallenna listan tiedot\n");
	printf("3) Analysoi tiedot\n");
	printf("4) Suorita kuukausianalyysi\n");
	printf("5) Tulosta kaikki tulokset\n");
	printf("6) Tallenna tulokset tiedostoon\n");
	printf("7) Tyhjennä analyysilista\n");
	printf("0) Lopeta\n");
	printf("Valintasi: ");
	if (scanf("%d", &valinta) != 1) {
		fprintf(stderr,"Virheellinen syöte\n");
		exit(0);
	}
	return(valinta);
}

int main(void) {
	Solmu *Alku = NULL;
	Solmu2 *Alku2 = NULL;
	Solmu2 *kuuAlku[KOKO];
	int  valinta,valinta2, i,count,flag = 0,asema = 0;
	char muisti[KOKO],tnimi[KOKO];
	FILE *tiedosto;
	kuuAlku[0] = NULL;
	printf("Tämä ohjelma analysoi lämpötilatiedostoja.\n");
	while (TRUE) {
		valinta = valikko();
		switch (valinta) {
			case 1:
				tiedosto = kysyminen(tnimi,tiedosto);
				fgets(muisti, KOKO, tiedosto);
				Alku = vapautus(Alku);
				count = 0;
				while(fgets(muisti, KOKO, tiedosto) != NULL) {
					count ++;
					for(i = 0; muisti[i]!='\0';i++) {
						if(muisti[i] == '\n'){
					  		muisti[i] = '\0';
					  	}
					}	
				    Alku = lisaus(Alku,muisti);
				}
				printf("Tiedosto '%s' luettu, %d datariviä.\n",tnimi,count);
				fclose(tiedosto);
				break;
			case 2:
			    tallennus(Alku);
				break;
			case 3:
				analyysi(Alku);
				break;
			case 4:
				kuuAlku[asema] = kuuanalyysi(Alku);
				asema++;
				break;
			case 5:
				for(i = 0; i < asema;i++)
					tulokset(kuuAlku[i],i);
				break;
			case 6:
				if(asema == 0) {
					printf("Tuloslista on tyhjä.\n");
					break;
				}
				valinta2 = subvalikko();
				if (valinta2 < 1) {
					printf("\nTuntematon valinta, yritä uudestaan.\n");
				break;
				}
				if (valinta2 > 3) {
					printf("\nTuntematon valinta, yritä uudestaan.\n");
				break;
				}
				for(i = 0; i < asema;i++)
					flag = tulostallennus(kuuAlku[i],flag,valinta2,asema);
				printf("Tiedot tallennettu tiedostoon: 'tulostiedot.csv'\n");
				break;
			case 7:
				for(i = 0; i < asema;i++)
					kuuAlku[i] = puhdistus(kuuAlku[i]);
				asema = 0;
				printf("Tuloslista tyhjennetty.\n");
				break;
			case 0:
				printf("Kiitos ohjelman käytöstä.\n");
				Alku2 = puhdistus(Alku2);
				Alku = vapautus(Alku);
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
