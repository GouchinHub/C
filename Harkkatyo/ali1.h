/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: ali1.h
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
#define KOKO 100

typedef struct solmu Solmu;

typedef struct solmu2 Solmu2;

int tulostallennus(Solmu2 *Alku2,int flag,int valinta,int asema);

FILE *kysyminen(char tnimi[KOKO],FILE *tiedosto);

Solmu *parsinta(Solmu *uusi, char *jako);

Solmu *lisaus(Solmu *Alku, char muisti[KOKO]);

int tallennus(Solmu *Alku);


/*******************************************************************/
/* eof */
