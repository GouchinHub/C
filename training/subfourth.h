/*subfourth.c*/
/*********************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define koko 256

typedef struct lista Lista;

Lista *lisaus(Lista *pAlku, char tiedot[koko]);

void tulostus(Lista *pAlku);

Lista *vapautus(Lista *pAlku);
