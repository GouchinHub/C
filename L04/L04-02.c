/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04-02
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 22.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#define KOKO 50

int fibonacci(int luku) {
	if (luku == 0)
		return 0;
	else if (luku == 1)
		return 1;
	else
		return (fibonacci(luku-1) + fibonacci(luku-2) );
}

int main(void) {
	int luku, tulos;
	printf("Anna luku, jolle lasketaan Fibonaccin luku: ");
	if(scanf("%d", &luku) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	tulos = fibonacci(luku);
	printf("Luvun %d Fibonaccin luku on %d.\n",luku,tulos);
	return(0);
	
}
/*******************************************************************/
/* eof */
