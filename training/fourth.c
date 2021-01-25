/*Fourth*/
/**********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subfourth.h"
#define koko 256

struct lista {
	int vuosi;
	char merkki[koko];
	struct lista *seuraava;
};

int main(void){
	FILE *tiedosto;
	Lista *pAlku = NULL;
	char tiedot[koko];
	if ((tiedosto = fopen("tiedot.txt","r")) == NULL){
		fprintf(stderr,"Virhe avattaessa tiedosta\n");
		exit(1);
	}
	while(fgets(tiedot,koko+1,tiedosto) != NULL){
		for(int i = 0;tiedot[i]!='\0';i++){
			if(tiedot[i]=='\n')
				tiedot[i]='\0';
		}
		pAlku = lisaus(pAlku,tiedot);
	}
	fclose(tiedosto);
	tulostus(pAlku);
	pAlku = vapautus(pAlku);
	return(0);
}

