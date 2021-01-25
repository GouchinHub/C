/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot:
 * Tekijä:
 * Opiskelijanumero:
 * Päivämäärä:
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

int valikko(void) {
	int valinta;
	printf("\nValitse haluamasi toiminto alla olveasta valikosta:\n");
	printf("1) Lue lämpötilatiedosto\n");
	printf("2) Tallenna listan tiedot\n");
	printf("3) Analysoi tiedot\n");
	printf("0) Lopeta\n");
	printf("Anna valintasi: ");
	if (scanf("%d", &valinta) != 1) {
		fprintf(stderr,"Virheellinen syöte\n");
		exit(0);
	}
	return(valinta);
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

int tulostus(Solmu *Alku) {
	FILE * tiedosto;
	Solmu *lst = Alku;
	if ((tiedosto = fopen("tulostiedot.txt","w")) == NULL) {
		printf("Tiedoston avaus epäonnistui.\n");			
		exit(0);
	}
	if(Alku == NULL) {
	    printf("Lämpötilalista on tyhjä.\n");
	    fclose(tiedosto);
		return(0);
	}
	else {
		while(lst != NULL) {
			fprintf(tiedosto, "%d.%d.%d %d C\n",
	            lst->paiva,lst->kuu,lst->vuosi,lst->lampo);
			lst = lst->seuraava;
		}
		fclose(tiedosto);
		printf("Lämpötiladata tallennetuu.\n");
		return(0);
	}
	
}

int analyysi(Solmu *Alku) {
    int i = 0, KA;
	Solmu *lst = Alku;
	 int summa = 0,min = lst->lampo, max = lst->lampo;
	if(Alku == NULL) {
		printf("\n");
		return(0);
	}
	else {
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

int main(void) {
	Solmu *Alku = NULL;
	int  valinta, i,count;
	char muisti[KOKO],tnimi[KOKO];
	FILE *tiedosto;
	while (TRUE) {
		valinta = valikko();
		switch (valinta) {
			case 1:
				tiedosto = kysyminen(tnimi,tiedosto);
				fgets(muisti, KOKO, tiedosto);
				Alku = vapautus(Alku);
				count = 0;
				while(fgets(muisti, KOKO, tiedosto) != NULL) {
					count ++;
					for(i = 0; muisti[i]!='\0';i++) {
						if(muisti[i] == '\n'){
					  		muisti[i] = '\0';
					  	}
					}	
				    Alku = lisaus(Alku,muisti);
				}
				printf("Tiedosto '%s' luettu, %d datariviä.\n",tnimi,count);
				fclose(tiedosto);
				break;
			case 2:
			    tulostus(Alku);
				break;
			case 3:
				analyysi(Alku);
				break;
			case 0:
				printf("Kiitos ohjelman käytöstä.\n");
				return(0);
			default:
				printf("\nTuntematon valinta, yritä uudestaan.\n");
				break;
			}
		}
	return(0);
}

/*******************************************************************/
/* eof */
