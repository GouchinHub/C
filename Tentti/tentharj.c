/* testprogram for tent purpose */
/* Aatu Laitinen */
/*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define koko 100

char *kayttajan_nimi(char nimi[koko]){
	printf("Anna nimesi: ");
	fgets(nimi, koko+1, stdin);
	for(int i = 0;nimi[i] != '\0';i++){
		if (nimi[i] == '\n')
			nimi[i] = '\0';
	}
	return nimi;
}



void tiedoston_kirjoitus(int luku,char nimi[koko]){
	float liuku;
	FILE *tiedosto;
	if ((tiedosto = fopen("file.txt","w")) == NULL ) {
		fprintf(stderr, "Virhe avatessa tiedostoa");
		exit(1);
	}
	for(int i = 0;i<luku;i++){
		printf("Anna liukuluku: ");
		scanf("%f",&liuku);
		fprintf(tiedosto,"%s;%.2f",nimi,liuku);
	}
	printf("tiedosto kirjotettu\n");
	printf("tiedosto kirjotettu\n");
	printf("tiedosto kirjotettu\n");
	printf("tiedosto kirjotettu\n");
	fclose(tiedosto);
	printf("\ntiedosto");
}


int tulostus(char nimi[koko]){
	int a=0,count=0;
	float max,summa=0,liuku;
	char str[koko];
	FILE *tiedosto;
	if ((tiedosto = fopen("file.txt","r")) == NULL){
		fprintf(stderr,"Tiedoston avaus epäonnistui");
		exit(1);
	}
	printf("****%d*****",count);
	rewind(tiedosto);
	float *lista = (float*)malloc(count*sizeof(float));
	count = 0;
	while(feof(tiedosto) == 0){
		if(fscanf(tiedosto,"%s:",str) == 0){
			fprintf(stderr,"Virhe lukiessa tiedostoa");
			exit(1);
		}
		lista = (float*)malloc((a+1)*sizeof(float));
		char *token = strtok(str,";");
		count = 0;
		while(token != NULL){
			if (count == 1)
				liuku = atof(token);
			count++;
		}
		lista[a]=liuku;
		summa += liuku;
		if (a==0)
			max = liuku;
		if (max < liuku)
			max = liuku;
		a++;
	}
	printf("%d",count);
	fclose(tiedosto);
	/*float ka = summa/luku;
	printf("Nimesi: %s Summa: %.2f KA: %.2f Suurin: %.2f\n",nimi,summa,ka,max);
	printf("Kaikki annetut luvut:\n");
	for(i=0;i<luku;i++)
		printf("%d. luku = %.2f\n",i+1,lista[i]);*/
	return 0;
}
	
int main(void) {
	printf("FUCK");
	int luku;
	char nimi[koko];
	strcpy(nimi,kayttajan_nimi(nimi));
	printf("Anna annettavien liukulukujen määrä: ");
	if (scanf("%d", &luku) != 1) {
		fprintf(stderr,"Virheellinen syöte\n");
		exit(0);
	}
	printf("ÖÖ??");
	tiedoston_kirjoitus(luku,nimi);
	printf("vittu");
	tulostus(nimi);
	return(0);
}

/**********************************************************************/
/*EOF*/

