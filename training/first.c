/*testing l6-01*/
/****************************************************/

#include <stdio.h>
#include <stdlib.h>

struct lista {
	int luku;
	struct lista *seuraava;
};
typedef struct lista Lista;	
	
int main(void) {
	int num;
	Lista *pAlku = NULL, *pLoppu = NULL, *ptr;
	printf("Anna listan luvut.\n");
	while (1){
		printf("Anna positiivinen kokonaisluku, 0 lopettaa: ");
		if (scanf("%d",&num) != 1){
			fprintf(stderr,"Virheellinen syöte\n");
			exit (1);
		}
		if(num==0)
			break;
		if ((ptr = (Lista*)malloc(sizeof(Lista))) == NULL){
			perror("Muistin varaus epäonnistui");
			exit (1);
		}
		ptr->luku = num;
		ptr->seuraava = NULL;
		
		if(pAlku == NULL){
			pAlku = ptr;
			pLoppu = ptr;
		}else{
			pLoppu->seuraava = ptr;
			pLoppu = ptr;
		}
	}
	printf("Listassa on seuraavat luvut:");
	ptr = pAlku;
	while (ptr != NULL){
		printf(" %d",ptr->luku);
		ptr = ptr->seuraava;
	}
	printf("\n");
	ptr = pAlku;
	while(ptr != NULL){
		pAlku = ptr->seuraava;
		free(ptr);
		ptr = pAlku;
	}
	return (0);
}
