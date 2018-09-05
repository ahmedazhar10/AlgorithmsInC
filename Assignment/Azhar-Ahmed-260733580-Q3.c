/*
 * Azhar-Ahmed-260733580-Q3.c
 *
 *  Created on: Sep 24, 2016
 *      Author: Ahmed Azhar
 */

#include <stdio.h>
#include <stdlib.h>

void displayHist(char hist[], int distinct_chars) {
	int i, barlength, q;
	int z = '*';
    int MAXLENGTH = 25;
	int max=0;

	for (i=0; i<256; i++){
	if (hist[i]>max)
	max = hist[i];
	}
	for (i=0; i<256; i++){
		if (hist[i]!=0){
		barlength = (int)(((double)hist[i])/((double)max)*((double)MAXLENGTH));
		printf("\n%c [%d] ", i, hist[i]);
		}
	for (q=0; q<barlength;q++){
		if (hist[i]!=0)
		printf("%c",z);
		}
	  }
	}

