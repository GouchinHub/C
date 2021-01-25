/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L04-01
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 22.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#define KOKO 50

int main(void) {
	struct kirja {
		char nimi[KOKO];
		int painovuosi;
		int hyllypaikka;
	};
	struct kirja Kirja;
	printf("Anna kirjan nimi: ");
	fgets(Kirja.nimi, 50,stdin);
	for(int i=0; Kirja.nimi[i]!='\0';i++) {
		if(Kirja.nimi[i] == '\n'){
	      	Kirja.nimi[i] = '\0';
	      	}
	}
	printf("Anna kirjan painovuosi: ");
	if(scanf("%d", &Kirja.painovuosi) != 1) {
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
		
	printf("Anna kirjan hyllypaikka: ");
	if(scanf("%d", &Kirja.hyllypaikka) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	printf("Kirjan nimi on '%s', painovuosi %d ja hyllypaikka %d.\n",
		Kirja.nimi, Kirja.painovuosi, Kirja.hyllypaikka);
	return(0);
}
/*******************************************************************/
/* eof */
