/*fifth*/
/************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subfifth.h"
#define koko 256

struct lista{
	int vuosi;
	char malli[koko];
	struct lista *seuraava;
};


int main(void){
	char nimi[koko],*tiedot;
	Lista *pAlku = NULL;
	FILE *tiedosto;
	strcpy(nimi,tiednimi(nimi));
	if ((tiedosto = fopen(nimi,"r")) == NULL){
		fprintf(stderr,"Virhe avatessa tiedostoa\n");
		exit(1);
	}
	fseek(tiedosto,0L,SEEK_END);
	size_t fsize = ftell(tiedosto);
	fseek(tiedosto,0L,SEEK_SET);
	while(1){
		if ((tiedot = (char*)malloc(sizeof(char)))==NULL){
			perror("Muistinvaraus epäonnistui");
			exit (1);
		}
		if(fgets(tiedot,fsize,tiedosto)==NULL)
			break;
		for(int i=0;tiedot[i]!='\0';i++){
			if(tiedot[i] == '\n')
				tiedot[i]='\0';
		}
		pAlku = lisaus(pAlku,tiedot);
		free(tiedot);
	}
	fclose(tiedosto);
	tulostus(pAlku,nimi);
	pAlku = puhdistus(pAlku);
	free(tiedot);
	return(0);
}

/************************************************/
/*EOF*/
