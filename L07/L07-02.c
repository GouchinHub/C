/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06-04
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 5.7.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1

struct solmu {
	int luku;
	struct solmu *seuraava;
};

typedef struct solmu Solmu;

int valikko(void) {
	int valinta;
	printf("1) Luo lista\n");
	printf("2) Lisää alkio listan loppuun\n");
	printf("3) Lisää alkio listan keskelle\n");
	printf("4) Tyhjennä lista\n");
	printf("5) Poista alkio listasta\n");
	printf("6) Tulosta lista\n");
	printf("0) Lopeta\n");
	printf("Anna valintasi: ");
	if (scanf("%d", &valinta) != 1) {
		fprintf(stderr,"Virheellinen syöte\n");
		exit(0);
	}
	return(valinta);
}

Solmu *lisaus(Solmu *Alku, int i) {
	Solmu *ptr, *uusi;
	if ((uusi = (Solmu*)malloc(sizeof(Solmu))) == NULL ) {
		perror("Muistin varaus epäonnistui.\n");
		exit(0);
	}
	uusi->luku = i+1;
	uusi->seuraava = NULL;
	if (Alku == NULL) {
		Alku = uusi;
	} else {
		ptr = Alku;
		while (ptr->seuraava != NULL)
			ptr = ptr->seuraava;
		ptr->seuraava = uusi;
	}
	return Alku;	
}

int tulostus(Solmu *Alku) {
	int koko = 0;
	Solmu *lista = Alku;
	if(Alku == NULL) {
		printf("\n");
		return(koko);
	}
	else {
		while(lista != NULL) {
			printf("%d ", lista->luku);
			koko = lista->luku;
			lista = lista->seuraava;
		}
		printf("\n");
		return(koko);
	}
	
}	

Solmu *vapautus(Solmu *Alku) {
	Solmu *lista = Alku;
	while(lista != NULL) {
		Alku = lista->seuraava;
		free(lista);
		lista = Alku;
	}
	return Alku;
}

int main(void) {
	Solmu *Alku = NULL;
	int  valinta, koko = 0, i;
	printf("Tämä ohjelma hallitsee listaa ja sen alkioita.\n");
	while (TRUE) {
		valinta = valikko();
		switch (valinta) {
			case 1:
				printf("Anna listan pituus: ");
				if (scanf("%d",&valinta) != 1) {
					fprintf(stderr,"Virheellinen syöte\n");
					return(0);
				}
				else if (valinta < 0) {
					printf("Listan pituus ei voi olla negatiivinen.\n");
					break;
				}
				else {
					if (valinta == 0) {
						Alku = NULL;
					}
					else {	
						for( i = 0; i < valinta; i++) {
							Alku = lisaus(Alku, koko);
							koko++;
						}
						koko = tulostus(Alku);
					}
				}		
				break;
			case 2:
				Alku = lisaus(Alku, koko);
				koko++;
				koko = tulostus(Alku);
				break;
			case 4:
				Alku = vapautus(Alku);
				break;
			case 6:
				tulostus(Alku);
				break;
			case 0:
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
