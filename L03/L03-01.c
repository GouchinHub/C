/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03-01
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 5.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: stackofveflow: stderr ja strncat käyttö
 */
/*******************************************************************/

#include <stdio.h>

int laskuri(int luku,int potenssi) {
	int tulos = 1, i;
	for (i = 1; i <= potenssi; i++) {
		tulos *= luku;
	}
	return tulos;
}
	

int main(void) {
	int luku, potenssi,vastaus;
	printf("Ohjelma laskee luvun potenssin.\n");
	printf("Anna kokonaisluku, jonka haluat korottaa potenssiin: ");
	if(scanf("%d", &luku) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
			}
	printf("Anna potenssi, jonka haluat laskea: ");
	if(scanf("%d", &potenssi) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
			}
	vastaus = laskuri(luku, potenssi);
	printf("%d ^ %d = %d.\n",luku,potenssi,vastaus);
	return 0;
}
/*******************************************************************/
/* eof */
