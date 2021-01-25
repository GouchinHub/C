/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03-05
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 10.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

void tallennus(char *tnimi) {
	char nimi[50];
	int luku;
	FILE *tiedosto = fopen(tnimi, "wb");
	srand(1);
	for(int i = 0; i<20; i++) {
		luku = ("%d", rand() %1000);
		fwrite(&luku, sizeof(luku), 1, tiedosto); 
	}
	fclose(tiedosto);
	printf("Lukujen tallennus onnistui.\n");
	return;
}

void tulostus(char *tnimi){
	int luku;
	printf("Tiedostossa on seuraavat luvut: \n");
	FILE *tiedosto = fopen(tnimi, "rb");
	for (int i= 1; i < 21; i++) {
		fread(&luku, sizeof(luku), 1, tiedosto);
		printf("%d ", luku);
	}
	printf("\n");
	fclose(tiedosto);
	return;
}

int main(void) {
	int luku;
	int x = 1;
	char tnimi[] = "luvut.bin";
	tallennus(tnimi);
	tulostus(tnimi);
	
	return(0);
}
/*******************************************************************/
/* eof */
