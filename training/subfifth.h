/*fifth*/
/************************************************/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 256

typedef struct lista Lista;

char *tiednimi(char nimi[koko]);

Lista *lisaus(Lista *pAlku, char *tiedot);

void tulostus(Lista *pAlku,char nimi[koko]);

Lista *puhdistus(Lista *pAlku);

/************************************************/
/*EOF*/
