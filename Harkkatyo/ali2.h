/*******************************************************************/
/* CT60A2500 C-ohjelmoinnin perusteet
 * Otsikkotiedot: ali2.h
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


Solmu2 *kuulisaus(Solmu2 *Alku,int min,int max,int KA,int vuosi,char nimi[KOKO],int kuu);

Solmu2 *kuuanalyysi(Solmu *Alku);

int tulokset(Solmu2 *Alku2,int luku);

int analyysi(Solmu *Alku);

Solmu *vapautus(Solmu *Alku);

Solmu2 *puhdistus(Solmu2 *Alku);



/*******************************************************************/
/* eof */
