/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02-03
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 3.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#

int main(void) {
	 int luku, kierros = 0;
	 
	 printf("Anna jokin kokonaisluku väliltä 1-10: ");
	 scanf("%d", &luku); 
	 if (luku < 1) {
	 	printf("Antamasi luku ei ole välillä 1-10.\n"); }
	 else if (luku > 10) {
	 	printf("Antamasi luku ei ole välillä 1-10.\n"); }
	 else
	 	while (luku > kierros) {
	 	printf("%d kierros.\n",kierros +1);
	 	kierros++; }
	 return 0;
}
/*******************************************************************/
/* eof */
