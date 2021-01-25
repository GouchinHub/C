/* testprogram for tent purpose */
/* Aatu Laitinen */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 100

char *kayttajan_nimi(char nimi[koko]);

float *lukujen_listaus(int luku);

int tulostus(char nimi[koko], float *lista,int luku);

int main(void){
	int luku;
	float *lista;
	char nimi[koko];
	strcpy(nimi,kayttajan_nimi(nimi));
	printf("Anna annettavien liukulukujen määrä: ");
	if (scanf("%d",&luku) == 0){
		fprintf(stderr, "Virheellinen syöte\n");
		exit(1);
	}
	lista = lukujen_listaus(luku);
	tulostus(nimi,lista,luku);
	return(0);
}
char *kayttajan_nimi(char nimi[koko]){
	printf("Anna nimesi: ");
	fgets(nimi, koko+1, stdin);
	for(int i = 0;nimi[i] != '\0';i++){
		if (nimi[i] == '\n')
			nimi[i] = '\0';
	}
	return nimi;
}

float *lukujen_listaus(int luku){
	float liuku;
	float *lista = (float*)malloc(luku*sizeof(float));
	for(int i = 0;i<luku;i++){
		printf("Anna liukuluku: ");
		if (scanf("%f",&liuku) == 0){
			fprintf(stderr, "Virheellinen syöte\n");
			exit(1);
		}
		lista[i] = liuku;
	}
	return (lista);
}

int tulostus(char nimi[koko], float *lista, int luku){
	int i;
	float max,summa=0;	
	for(i=0;i<luku;i++){
		summa += lista[i];
		if (i==0)
			max = lista[i];
		if (max < lista[i])
			max = lista[i];
	}
	float ka = summa/luku;
	printf("Nimesi: %s Summa: %.2f KA: %.2f Suurin: %.2f\n",nimi,summa,ka,max);
	printf("Kaikki annetut luvut:\n");
	for(i=0;i<luku;i++){
		printf("%d. luku = %.2f\n",i+1,lista[i]);
	}
	return 0;
}
	

/**********************************************************************/
/*EOF*/

