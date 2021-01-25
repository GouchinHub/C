/*third*/
/****************/

#include <stdio.h>
#include <stdlib.h>

struct lista {
	int luku;
	struct lista *seuraava;
};
typedef struct lista Lista;

void tulosta(Lista *pAlku){
	Lista *ptr = pAlku;
	printf("Listassa on seuraavat luvut: ");
	while(ptr != NULL){
		printf("%d ",ptr->luku);
		ptr = ptr->seuraava;
	}
	printf("\n");
}

Lista *lisaus(Lista *pAlku, int i){
	Lista *ptr, *uusi;
	if ((uusi = (Lista*)malloc(sizeof(Lista))) == NULL){
		perror("Muistinvaraus epäonnistui");
		exit(1);
	}
	uusi->luku = i;
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

Lista *vapauta(Lista *pAlku){
	Lista *ptr = pAlku;
	while(ptr != NULL){
		pAlku = ptr;
		free(ptr);
		ptr = ptr->seuraava;
	}
	return pAlku;
}
		

int main(void){
	int valinta,koko,i;
	Lista *pAlku = NULL;
	while(1){
		printf("1) Tulosta listan alkiot\n");
		printf("2) Muuta listan pituutta\n");
		printf("0) Lopeta\n");
		printf("Anna valintasi: ");
		if (scanf("%d",&valinta) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			exit(1);
		}
		switch(valinta){
			case 1:
				tulosta(pAlku);
				break;
			case 2:
				pAlku = vapauta(pAlku);
				pAlku = NULL;
				printf("Anna listan uusi pituus: ");
				if (scanf("%d",&koko) != 1){
					fprintf(stderr,"Virheellinen syöte\n");
					exit(1);
				}
				for(i=0;i<koko;i++){
					pAlku = lisaus(pAlku,i);
				}
				break;
			case 0:
				vapauta(pAlku);
				exit (1);
			default:
				printf("Virheellinen valinta\n");
				break;
		}
	}
	return(0);	
}
