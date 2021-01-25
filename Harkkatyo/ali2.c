/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: ali2.c
 * Tekijä: Aatu Laitinen
 * Opiskelijanumero: 0501379
 * Päivämäärä: 7.7.2020
 * Yhteistyö ja lähteet, nimi ja yhteistyön muoto:
 */
/*******************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TRUE 1
#define KOKO 100

struct solmu {
	int vuosi,kuu,paiva,klo,lampo;
	struct solmu *seuraava;
};

typedef struct solmu Solmu;

struct solmu2 {
	char setnimi[KOKO];
	int vuosi,min,max,karvo;
	struct solmu2 *seuraava;
};

typedef struct solmu2 Solmu2;

Solmu2 *kuulisaus(Solmu2 *Alku,int min,int max,int KA,int vuosi,char nimi[KOKO],int kuu) {
	Solmu2 *ptr, *uusi;
	if ((uusi = (Solmu2*)malloc(sizeof(Solmu2))) == NULL ) {
		perror("Muistin varaus epäonnistui.\n");
		exit(0);
	}
	uusi->vuosi = vuosi;
	uusi->min = min;
	uusi->max = max;
	uusi->karvo = KA;
	strcpy(uusi->setnimi,nimi);
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

Solmu2 *kuuanalyysi(Solmu *Alku) {
	if(Alku == NULL) {
		printf("Ei analysoitavaa, lue ensin lämpötilatiedosto.\n");
		return(0);
	}
    int i = 0, KA;
	Solmu *lst = Alku;
	Solmu2 *Alku2 = NULL;
	int summa = 0,min ,max ,kuu = 2,vuosi = lst->vuosi;
	char nimi[KOKO];
	printf("Anna analysoitavalle datasetille nimi: ");
	scanf("%s",nimi);
	while(lst != NULL) {
		min = lst->lampo;
		max = lst->lampo;
		summa = 0;
		KA = 0;
		i = 0;
		if (kuu == lst->kuu) {
			kuu++;
			summa += lst->lampo;
			if (min > lst->lampo)
				min = lst->lampo;
			if (max < lst->lampo)
				max = lst->lampo;
			lst = lst->seuraava;
			i++;
		} else {
			do {
				summa += lst->lampo;
				if (min > lst->lampo)
					min = lst->lampo;
				if (max < lst->lampo)
					max = lst->lampo;
				lst = lst->seuraava;
				i++;
			} while (lst != NULL && lst->kuu < kuu);
			KA = summa / i;
			Alku2 = kuulisaus(Alku2, min, max, KA ,vuosi,nimi,kuu);
		}
	}
	printf("Kuukausianalyysi valmis.\n");
	return(Alku2);
}

int tulokset(Solmu2 *Alku2, int luku) {
	Solmu2 *lst = Alku2;
	if(Alku2 == NULL) {
	    printf("Lämpötilalista on tyhjä.\n");
		return(0);
	}
	else {
		if (luku == 0)
			printf("Analyysilistan tulokset:\n");
		printf("\n%s\n",lst->setnimi);
	   	printf("%d\tTammi\tHelmi\tMaalis\tHuhti\tTouko\tKesä\tHeinä\tElo\tSyys\tLoka\tMarras\tJoulu\n",lst->vuosi);
	   	printf("avg:");
		while(lst != NULL) {
			printf("\t%d", lst->karvo);
			lst = lst->seuraava;
		}
		lst = Alku2;
		printf("\nmin:");
		while(lst != NULL) {
			printf("\t%d", lst->min);
			lst = lst->seuraava;
		}
		lst = Alku2;
		printf("\nmax:");
		while(lst != NULL) {
			printf("\t%d", lst->max);
			lst = lst->seuraava;
		}
		printf("\n");
		return(0);
	}
	
}

int analyysi(Solmu *Alku) {
	if(Alku == NULL) {
		printf("Ei analysoitavaa, lue ensin lämpötilatiedosto.\n");
		return(0);
	}
    int i = 0, KA;
	Solmu *lst = Alku;
	int summa = 0, min = lst->lampo, max = lst->lampo;
	while(lst != NULL) {
		summa += lst->lampo;
		if (min > lst->lampo)
		    min = lst->lampo;
		if (max < lst->lampo)
		    max = lst->lampo;
		lst = lst->seuraava;
		i++;
	}
	KA = summa / i;
	printf("Lämpötila-analyysi, %d alkiota:\n",i);
	printf("  Avg  Min  Max\n");
	printf("  %3d  %3d  %3d\n",KA,min,max);
	return(0);
}

Solmu *vapautus(Solmu *Alku) {
	Solmu *lista = Alku;
	while(lista != NULL) {
		Alku = lista->seuraava;
		free(lista);
		lista = Alku;
	}
	return Alku;
}

Solmu2 *puhdistus(Solmu2 *Alku) {
	Solmu2 *lista = Alku;
	while(lista != NULL) {
		Alku = lista->seuraava;
		free(lista);
		lista = Alku;
	}
	return Alku;
}

/*******************************************************************/
/* eof */
