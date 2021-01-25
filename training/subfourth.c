/*subfourth.c*/
/*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 256

struct lista {
	int vuosi;
	char merkki[koko];
	struct lista *seuraava;
};
typedef struct lista Lista;

Lista *lisaus(Lista *pAlku, char tiedot[koko]){
	Lista *ptr, *uusi;
	if ((uusi = (Lista*)malloc(sizeof(Lista)))==NULL){
		perror("Muistinvaraus epäonnistui");
		exit(1);
	}
	int count = 0;
	char*token = strtok(tiedot, " ");
	while(token!=NULL){
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
	Lista *ptr = pAlku;
	int i = 1;
	printf("Listan ajoneuvot: \n");
	while(ptr != NULL){
		printf("%d. ajoneuvo: %s vuosimalli %d.\n",i,ptr->merkki,ptr->vuosi);
		ptr = ptr->seuraava;
		i++;
	}
}

Lista *vapautus(Lista *pAlku){
	Lista *ptr = pAlku;
	while(ptr!=NULL){
		pAlku=ptr;
		free(ptr);
		ptr = ptr->seuraava;
	}
	return pAlku;
}	
	
	
	
	

