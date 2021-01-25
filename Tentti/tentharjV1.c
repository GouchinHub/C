/* testprogram for tent purpose */
/* Aatu Laitinen */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#define koko 100

int main(void){
	int i,luku;
	float liuku,summa=0,max=0;
	char nimi[koko];
	printf("Anna nimesi: ");
	fgets(nimi, koko+1, stdin);
	for(i = 0;nimi[i] != '\0';i++){
		if (nimi[i] == '\n')
			nimi[i] = '\0';
	}
	printf("Anna annettavien liukulukujen määrä: ");
	if (scanf("%d",&luku) == 0){
		fprintf(stderr, "Virheellinen syöte\n");
		exit(1);
	}
	float lista[luku];
	for(i = 0;i<luku;i++){
		printf("Anna liukuluku: ");
		if (scanf("%f",&liuku) == 0){
			fprintf(stderr, "Virheellinen syöte\n");
			exit(1);
		}
		lista[i] = liuku;
		summa += liuku;
		if(i==0)
			max = liuku;
		if(max<liuku)
			max = liuku;
	}
	float ka = summa/luku;
	printf("Nimesi: %s Summa: %.2f KA: %.2f Suurin: %.2f\n",nimi,summa,ka,max);
	printf("Kaikki annetut luvut:\n");
	for(i=0;i<luku;i++){
		printf("%d. luku = %.2f\n",i+1,lista[i]);
	}
	return(0);
}
/**********************************************************************/
/*EOF*/
