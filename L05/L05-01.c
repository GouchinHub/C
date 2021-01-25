/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L05-01
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 25.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int lasku(int luku) {
	int nelio;
	nelio = luku * luku;
	return nelio;
}
int main(int argc, char *argv[]) {
	int luku,nelio,i;
	for (i = 0; i < argc; i++)
		i = argc;
	if (i < 3) {
		printf("Et antanut lukua!\n");
		return(0);
	}
	luku = atoi(argv[1]);
	printf("Luku on %d.\n", luku);
	nelio = lasku(luku);
	printf("Luvun neliö on %d.\n",nelio);
	return (0);
}
/*******************************************************************/
/* eof */
