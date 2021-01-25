/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L02-05
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 5.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto: stackofveflow: stderr ja strncat käyttö
 */
/*******************************************************************/

#include <stdio.h>
#include <string.h> 
#define true 1
#define KOKO 200

int main(void) {
	
	char merkkijono[200] = "";
	char merkki;
	char *osoitin;
	int valinta;
	int pituus = 0;
	
	while (true) {
		printf("\nValikko\n");
		printf("1) Lisää uusi merkki\n");
		printf("2) Tyhjennä merkkijono\n");
		printf("3) Tulosta merkkijono\n");
		printf("0) Lopeta\n");
		printf("Valintasi: ");
		if(scanf("%d", &valinta) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
			}
		else {
		switch (valinta) {
			case 1:
				getchar();
				printf("\nAnna jokin merkki: ");
				scanf("%c", &merkki);
				osoitin = merkkijono;
				pituus = 1;
				while (*osoitin != '\0'){
					pituus++;
					osoitin++;
					}
				if (pituus > 200) {
					printf("\nMerkkijonoon ei mahdu enempää merkkejä.\n");
					}
				else {	
					strncat(merkkijono, &merkki, 1);
					}
				break;
			case 2:
				pituus = 0;
				osoitin = merkkijono;
				while (*osoitin != '\0'){
					merkkijono[pituus] = '\0';
					pituus++;
					osoitin++;
				}
				pituus = 0;
				printf("\nMerkkijono on tyhjennetty.\n");
				break;
			case 3:
				if (pituus == 0) {
					printf("\nMerkkijono on tyhjä.\n");
					}
				else {
					printf("\nMerkkijono: %s\n",merkkijono);
				}
				break;
			case 0:
				printf("\nOhjelman lopetus.\n");
				return(0);
			default:
				getchar();
				printf("\nTuntematon valinta.\n");
				break;
			}
		}
	}
	return 0;
}
/*******************************************************************/
/* eof */
