/*fifth*/
/************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 256

struct lista{
	int vuosi;
	char malli[koko];
	struct lista *seuraava;
};
typedef struct lista Lista;

char *tiednimi(char nimi[koko]){
	printf("Anna luettavan tiedoston nimi: ");
	if(scanf("%s", nimi) != 1){
		fprintf(stderr,"Error!\n");
		exit(1);
	}
	return nimi;
}

Lista *lisaus(Lista *pAlku, char *tiedot){
	Lista *ptr, *uusi;
	int count = 0;
	if ((uusi = (Lista*)malloc(sizeof(Lista)))==NULL){
		perror("Muistinvaraus epäonnistui");
		exit(1);
	}
	char *token = strtok(tiedot," ");
	while(token != NULL){
		if (count == 0)
			strcpy(uusi->malli,token);
		if (count == 1)
			uusi->vuosi = atoi(token);
		token = strtok(NULL," ");
		count++;
	}
	uusi->seuraava = NULL;
	if (pAlku==NULL){
		pAlku = uusi;
	}else{
		ptr = pAlku;
		while(ptr->seuraava != NULL)
			ptr = ptr->seuraava;
		ptr->seuraava = uusi;
	}
	return pAlku;
}
		
void tulostus(Lista *pAlku,char nimi[koko]){
	Lista *ptr = pAlku;
	int i=0;
	printf("Tiedoston '%s' ajoneuvot ovat: \n",nimi);
	while(ptr != NULL){
		printf("%d. ajoneuvo: %s vuosimalli %d.\n",i,ptr->malli,ptr->vuosi);
		ptr = ptr->seuraava;
		i++;
	}
}

Lista *puhdistus(Lista *pAlku){
	Lista *ptr = pAlku;
	while(ptr!=NULL){
		pAlku = ptr;
		free(ptr);
		ptr = ptr->seuraava;
	}
	return pAlku;
}


/************************************************/
/*EOF*/
