/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: ali1.c
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

int tulostallennus(Solmu2 *Alku2,int flag,int valinta,int asema) {
	FILE * tiedosto;
	Solmu2 *lst = Alku2;
	if ((tiedosto = fopen("tulostiedot.csv","a")) == NULL) {
		printf("Tiedoston avaus epäonnistui.\n");			
		exit(0);
	}
	else {
		if (flag == 0) {
			fprintf(tiedosto,";Tammi;Helmi;Maalis;Huhti;Touko;Kesä;Heinä;Elo;Syys;Loka;Marras;Joulu\n");
			flag = 1;
		}
	    fprintf(tiedosto,"%s - %d",lst->setnimi,lst->vuosi);
		while(lst != NULL) {
			if (valinta == 1)
				fprintf(tiedosto,";%d", lst->karvo);
			if (valinta == 2)
				fprintf(tiedosto,";%d", lst->min);
			if (valinta == 3)
				fprintf(tiedosto,";%d", lst->max);
			lst = lst->seuraava;
		}
		fprintf(tiedosto,"\n");
		fclose(tiedosto);
		return(flag);
	}
	
}

FILE *kysyminen(char tnimi[KOKO],FILE *tiedosto) {
	printf("Anna luettavan tiedoston nimi: ");
	scanf("%s",tnimi);
	printf("Luetaan tiedosto '%s'\n",tnimi);
	if ((tiedosto = fopen(tnimi,"r")) == NULL) {
		printf("Tiedoston avaus epäonnistui.\n");				
		exit(0);
	}
	return(tiedosto);
}

Solmu *parsinta(Solmu *uusi, char *jako) {
    int count = 1;
    while( jako != NULL ) {
	        if (count == 1) {
	            if (isdigit(*jako) == 0) {
	                printf("Virhe parsittaessa vuotta.\n");
	                exit(0); 
	            }
	            else 
			        uusi->vuosi = atoi(jako);
			}
			if (count == 2) {
			    if (isdigit(*jako) == 0) {
	                printf("Virhe parsittaessa kuukautta.\n");
	                exit(0);
	            }
	            else 
			        uusi->kuu = atoi(jako);
			}
			if (count == 3) {
			    if (isdigit(*jako) == 0) {
	                printf("Virhe parsittaessa paivaa.\n");
	                exit(0); 
	            }
	            else 
			        uusi->paiva = atoi(jako);
			}
			if (count == 4) {
			    if (isdigit(*jako) == 0) {
	                printf("Virhe parsittaessa aikaa.\n");
	                exit(0); 
	            }
	            else 
			        uusi->klo = atoi(jako);
			}
			if (count == 5) {
			    if (*jako == '0') {
			        uusi->lampo = atoi(jako);
			    }
			    else if (atoi(jako) == 0) {
	                printf("Virhe parsittaessa %s lämpötilaa.\n",jako);
	                exit(0); 
	            }
	            else 
			        uusi->lampo = atoi(jako);
			}
			    
	  		jako = strtok(NULL, ";");
	  		count ++;
	  	}
    return(uusi);
}


Solmu *lisaus(Solmu *Alku, char muisti[KOKO]) {
	Solmu *ptr, *uusi;
	if ((uusi = (Solmu*)malloc(sizeof(Solmu))) == NULL ) {
		perror("Muistin varaus epäonnistui.\n");
		exit(0);
	}
	char *jako = strtok(muisti, ";");
	uusi = parsinta(uusi,jako);
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

int tallennus(Solmu *Alku) {
	FILE * tiedosto;
	Solmu *lst = Alku;
	if ((tiedosto = fopen("lampotiladata.txt","w")) == NULL) {
		printf("Tiedoston avaus epäonnistui.\n");			
		exit(0);
	}
	if(Alku == NULL) {
	    printf("Lämpötilalista on tyhjä.\n");
	    fclose(tiedosto);
		return(0);
	}
	else {
	    fprintf(tiedosto,"pvm lämpötila\n");
		while(lst != NULL) {
			fprintf(tiedosto, "%d.%d.%d %d C\n",
	            lst->paiva,lst->kuu,lst->vuosi,lst->lampo);
			lst = lst->seuraava;
		}
		fclose(tiedosto);
		printf("Lämpötiladata tallennettu.\n");
		return(0);
	}
	
}

/*******************************************************************/
/* eof */
