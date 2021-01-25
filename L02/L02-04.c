/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02-04
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 3.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#define pii 3.141

int main(void) {
	
	float luku, tulos;
	int valinta;
	 
	printf("Anna liukuluku: ");
	scanf("%f", &luku);
	 
	printf("\nValikko\n");
	printf("1) Kerro piin arvo luvulla %.3f.\n",luku);
	printf("2) Jaa piin arvo luvulla %.3f.\n",luku);
	printf("Valitse: ");
	scanf("%d",&valinta);
	switch (valinta) {
		case 1:
			tulos = pii * luku;
			printf("\nPii * %.3f = %.3f.\n",luku,tulos);
			break;
		case 2:
			tulos = pii / luku;
			printf("\nPii / %.3f = %.3f.\n",luku,tulos);
			break;
		default:
			printf("\nTuntematon valinta.\n");
			break;
	}
	return 0;
}
/*******************************************************************/
/* eof */
