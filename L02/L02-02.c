/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02-02
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 3.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>

int main(void) {
	 int luku1, luku2, valinta, tulos;
	 
	 printf("Anna kaksi kokonaislukua: ");
	 scanf("%d%d", &luku1,&luku2); 
	 printf("\nValikko\n");
	 printf("1) Summaa luvut yhteen.\n");
	 printf("2) Kerro luvut keskenään.\n");
	 printf("Valitse: ");
	 scanf("%d",&valinta);
	 if (valinta == 1) {
	 	tulos = luku1 + luku2;
	 	printf("\nLuvut laskettiin yhteen. Tulos = %d.\n",tulos); }
	 else if (valinta == 2) {
	 	tulos = luku1 * luku2;
	 	printf("\nLuvut kerrottiin yhteen. Tulos = %d.\n",tulos); }
	 else
	 	printf("\nTuntematon valinta.\n");
	 return 0;
}
/*******************************************************************/
/* eof */
