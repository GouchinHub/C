/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L03-03
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 10.6.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <string.h>

void Lasku(int L1, int L2) {
	if (L1 > L2) {
		printf("Luku %d on suurempi ja %d pienempi.\n", L1, L2);
		}
	else if (L1 < L2) {
		printf("Luku %d on suurempi ja %d pienempi.\n", L2, L1);
		}
	else
		printf("Luvut %d ja %d ovat yhtä suuria.\n", L1, L2);
}

void DesiLasku(float L1, float L2) {
	if (L1 > L2) {
		printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", L1, L2);
		}
	else if (L1 < L2) {
		printf("Luku %5.2f on suurempi ja %5.2f pienempi.\n", L2, L1);
		}
	else
		printf("Luvut %5.2f ja %5.2f ovat yhtä suuria.\n", L1, L2);
}
int main(void) {

	int KL1, KL2;
	float DL1, DL2;
	char Nimi1[50], Nimi2[50];
	printf("Anna kaksi kokonaislukua:\nLuku 1: ");
	if(scanf("%d", &KL1) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	printf("Luku 2: ");
	if(scanf("%d", &KL2) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	Lasku(KL1, KL2);
	printf("Anna kaksi desimaalilukua:\nLuku 1: ");
	if(scanf("%f", &DL1) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	printf("Luku 2: ");
	if(scanf("%f", &DL2) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			return(0);
		}
	DesiLasku(DL1, DL2);
	printf("Anna kaksi nimeä:\nNimi 1: ");
	scanf("%s", Nimi1);
	printf("Nimi 2: ");
	scanf("%s", Nimi2);
	int tulos = strcmp(Nimi1, Nimi2);
	if (tulos == 0) {
		printf("Merkkijonona '%s' ja '%s' ovat yhtä suuria.\n",Nimi1 ,Nimi2);
		}
	if (tulos > 0) {
		printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n",Nimi1 ,Nimi2);
		}
	if (tulos < 0) {
		printf("Merkkijonona '%s' on suurempi ja '%s' pienempi.\n",Nimi2 ,Nimi1);
		}
	return 0;
}
/*******************************************************************/
/* eof */
