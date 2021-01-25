/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06-01
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 2.7.2020
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

int main(void) {
	Solmu *Alku = NULL, *Loppu = NULL, *lista;
	printf("Anna listan luvut.\n");
	while (TRUE) {
		if ((lista = (Solmu*)malloc(sizeof(Solmu))) == NULL ) {
			perror("Muistin varaus epäonnistui.\n");
			exit(0);
		}
		printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
		if (scanf("%d", &lista->luku) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			exit(0);
		}
		if (lista->luku == 0)
			break;
		lista->seuraava = NULL;
		if (Alku == NULL) {
			Alku = lista;
			Loppu = lista;
		}
		else {
			Loppu->seuraava = lista;
			Loppu = lista;
		}	
	}
	printf("Listassa on seuraavat luvut: ");
	lista = Alku;
	while(lista != NULL) {
		printf("%d ",lista->luku);
		lista = lista->seuraava;
	}
	free(lista);
	lista = NULL;
	printf("\nKiitos ohjelman käytöstä.\n");
	return(0);
}
/*******************************************************************/
/* eof */
