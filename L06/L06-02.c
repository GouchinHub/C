/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: L06-02
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämärä: 2.7.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define KOKO 50
#define TRUE 1


struct solmu {
	char ajoneuvo[30];
	int vuosimalli;
	struct solmu *seuraava;
};

typedef struct solmu Solmu;

Solmu *lisaus(Solmu *Alku, char malli[KOKO],int vuosi) {
	Solmu *ptr, *uusi;
	if ((uusi = (Solmu*)malloc(sizeof(Solmu))) == NULL ) {
		perror("Muistin varaus epäonnistui.\n");
		exit(0);
	}
	strcpy(uusi->ajoneuvo,malli);
	uusi->vuosimalli = vuosi;
	uusi->seuraava = NULL;
	if (Alku == NULL) {
		Alku = uusi;
	} else {
		ptr = Alku;
		while (ptr->seuraava != NULL)
			ptr = ptr->seuraava;
		ptr->seuraava = uusi;
	}
	return Alku;	
}

void tulostus(Solmu *Alku) {
	int i = 1;
	Solmu *lista = Alku;
	while(lista != NULL) {
		printf("%d. ajoneuvo: %s vuosimalli %d.\n",i,lista->ajoneuvo,lista->vuosimalli);
		lista = lista->seuraava;
		i++;
	}
}

Solmu *vapautus(Solmu *Alku) {
	Solmu *lista = Alku;
	while(lista != NULL) {
		Alku = lista->seuraava;
		free(lista);
		lista = Alku;
	}
	printf("Muisti vapautettu.\n");
	return Alku;
}


int main(int argc, char *argv[]) {
	Solmu *Alku = NULL;
	char muisti[KOKO],malli[KOKO];
	int vuosi, count = 0,i,i2,i3;
	for (i = 0; i < argc; i++)
		i = argc;
	if (i < 3) {
		printf("Et antanut tiedoston nimeä.\n");
		return(0);
	}
	FILE *tiedosto;
	printf("Luetaan tiedot tiedostosta %s.\n",argv[1]);
	if ((tiedosto = fopen(argv[1],"r")) == NULL) {
		printf("Tiedoston avaus epäonnistui.\n");
		
		exit(0);
	}
	while(fgets(muisti, KOKO, tiedosto) != NULL) {
		if (muisti[0] != '\n')
			count ++;
	}
	if (count < 1){
		printf("Ajoneuvoja ei löytynyt.\n");
		return(0);
	}
	rewind(tiedosto);
	for(i2 = 0;i2 < count;i2++) {
		fgets(muisti, KOKO, tiedosto);
		for(i3 = 0; muisti[i3]!='\0';i3++) {
			if(muisti[i3] == '\n'){
	      		muisti[i3] = '\0';
	      	}
		}	
		char *jako = strtok(muisti, " ");
		while( jako != NULL ) {
			if (isdigit(*jako) == 0) {
	  			strcpy(malli,jako);
	  		}
	  		if (isalpha(*jako) == 0) {
	  			vuosi = atoi(jako);
	  		}
	  		jako = strtok(NULL, " ");
	  	}
		Alku = lisaus(Alku,malli,vuosi);
 	}
 	printf("Tiedot luettu linkitettyyn listaan.\n");
 	fclose(tiedosto);
 	tulostus(Alku);
 	Alku = vapautus(Alku);
	return(0);
}
/*******************************************************************/
/* eof */
