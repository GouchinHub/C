/*second.c*/
/********************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 256

struct lista{
	int vuosi;
	char merkki[koko];
	struct lista *seuraava;
};
typedef struct lista Lista;

Lista *lisaus(Lista *pAlku, char *tiedot){
	Lista *ptr, *uusi;
	int count=0;
	if ((uusi = (Lista*)malloc(sizeof(Lista)))==NULL){
		perror("Muistinvaraus epäonnistui");
		exit(1);
	}
	char *token = strtok(tiedot," ");
	while(token != NULL){
		if(count == 0)
			strcpy(uusi->merkki,token);
		if(count == 1)
			uusi->vuosi = atoi(token);
		token = strtok(NULL," ");
		count++;
	}
	uusi->seuraava = NULL;
	if(pAlku == NULL){
		pAlku = uusi;
	}else{
		ptr = pAlku;
		while(ptr->seuraava != NULL)
			ptr = ptr->seuraava;
		ptr->seuraava = uusi;
	}
	return pAlku;
}

void tulostus(Lista *pAlku){
	int i = 1;
	Lista *ptr = pAlku;
	while (ptr != NULL){
		printf("%d. ajoneuvo: %s vuosimalli %d.\n",i,ptr->merkki,ptr->vuosi);
		ptr = ptr->seuraava;
		i++;
	}
}

Lista *vapauta(Lista *pAlku){
	Lista *ptr = pAlku;
	while(ptr != NULL) {
		pAlku = ptr->seuraava;
		free(ptr);
		ptr = pAlku;
	}
	return pAlku;
}
		

int main(int argc, char *argv[]){
	Lista *pAlku = NULL;
	FILE *tiedosto;
	char tiedot[koko];
	if (argc != 2){
		printf("Väärä määrä argumentteja '%d'\n",argc);
		exit(0);
	}
	if((tiedosto = fopen(argv[1],"r")) == NULL){
		fprintf(stderr,"Tiedoston avaus epäonnistui\n");
		exit(1);
	}
	while(fgets(tiedot,koko+1,tiedosto) != NULL){
		for(int i=0;tiedot[i]!='\0';i++){
			if (tiedot[i]=='\n')
				tiedot[i]='\0';
		}
		pAlku = lisaus(pAlku,tiedot);
	}
	fclose(tiedosto);
	tulostus(pAlku);
	pAlku = vapauta(pAlku);
	return(0);
}
