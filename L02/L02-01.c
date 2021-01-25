/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02-01
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 3.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#define true 1

int main(void) {

	int luku, tulos, i;
	tulos = 0;

	printf("Anna jokin luku väliltä 10 - 200: ");
	scanf("%d", &luku);
	if (luku < 10) {
		printf("Antamasi luku ei ole annetulla välillä.\n");
		return(0); }
	else if (luku > 200) {
		printf("Antamasi luku ei ole annetulla välillä.\n");
		return(0); }
		
	for (i=1; i < luku+1; i++) {
		tulos += i;
		}
	printf("Lukujen 0 - %d summa on %d.\n", luku ,tulos);
	

	return (0);
}
/*******************************************************************/
/* eof */
