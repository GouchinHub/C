/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03-02
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 5.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: stackofveflow: stderr ja strncat käyttö
 */
/*******************************************************************/

#include <stdio.h>
#define true 1

void tallennus(char *tnimi) {
	char nimi[50];
	FILE *tiedosto = fopen(tnimi, "a");
	scanf("%50s", nimi);
	fprintf(tiedosto,"%s\n",nimi);
	fclose(tiedosto);
	getchar();
	return;
}

void tulostus(char *tnimi){
	char nimet[50];
	FILE *tiedosto = fopen(tnimi, "r");
	while (fgets(nimet,199 ,tiedosto) != NULL) {
		printf("%s",nimet);
	}
	fclose(tiedosto);
	getchar();
	}

int main(void) {
	
	char tnimi[] = "nimet.txt";
	int valinta;
	printf("Ohjelma tallentaa nimiä tiedostoon.\n");
	while (true) {
		printf("\n1) Tallenna uusi nimi\n");
		printf("2) Tulosta nimet\n");
		printf("0) Lopeta\n");
		printf("Valitse: ");
		if(scanf("%d", &valinta) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
			}
		if (valinta == 1) {
			printf("\nAnna tallennettava nimi: ");
			tallennus(tnimi);
			printf("Nimi on tallennettu tiedostoon.\n");
			}
		else if (valinta == 2) {
			printf("\nTiedostossa olevat nimet:\n");
			tulostus(tnimi);
			}
		else if (valinta == 0) {
			printf("\n");
			return(0);
			}
		else {
			getchar();
			printf("\nTuntematon valinta.\n");
			}
	}
	return 0;
}
/*******************************************************************/
/* eof */
