/*
 * Azhar-Ahmed-260733580-Q2.c
 *
 *  Created on: Sep 22, 2016
 *      Author: Ahmed Azhar
 */

#include <stdio.h>
#include <stdlib.h>

int doHist(char buffer[], char hist[]) {
int i, a;
a=0;

for (i=0; i<256; i++)
hist[i]=0;
i=0;

while(buffer[i]!='\0')
hist[(int)buffer[i++]]++;

for (i=0; i<256; i++)
if (hist[i]!=0)
a++;

printf("%d distinct characters retrieved\n", a);
return a;

}

