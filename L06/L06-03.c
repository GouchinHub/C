/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06-03
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


Solmu *lisaus(Solmu *Alku, int i) {
	Solmu *ptr, *uusi;
	if ((uusi = (Solmu*)malloc(sizeof(Solmu))) == NULL ) {
		perror("Muistin varaus epäonnistui.\n");
		exit(0);
	}
	uusi->luku = i;
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

void tulostus(Solmu *Alku) {
	Solmu *lista = Alku;
	if(Alku == NULL) {
		printf("Lista on tyhjä.\n");
	}
	else {
		printf("Listassa on seuraavat luvut: \n");
		while(lista != NULL) {
			printf("%d ", lista->luku);
			lista = lista->seuraava;
		}
		printf("\n");
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
	int  valinta, i;
	while (TRUE) {
		printf("1) Tulosta listan alkiot\n");
		printf("2) Muuta listan pituutta\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		if (scanf("%d", &valinta) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			exit(0);
		}
		switch (valinta) {
			case 1:
				tulostus(Alku);
				break;
			case 2:
				printf("Anna listan uusi pituus: ");
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
						if (Alku != NULL) {
							Alku = NULL;
						}	
						for( i = 0; i < valinta; i++)
							Alku = lisaus(Alku, i);
					}
				}		
				
				break;
			case 0:
				vapautus(Alku);
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
