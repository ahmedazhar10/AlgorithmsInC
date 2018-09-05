/*
 * Azhar-Ahmed-260733580-Q1.c
 *
 *  Created on: Sep 22, 2016
 *      Author: Ahmed
 */

#include <stdio.h>
#include <stdlib.h>

void toString(int argc, char *argv[], char buffer[]){
	int i;
	for (i = 1; i < argc ; i++) {
		append(buffer, argv[i]);
    }
	printf("%s\n", buffer);

}

void append(char out[], char in[]){
	int i, end;

	end = 0;
	while (out[end] != '\0') {
		end++;
	}

	i = 0;
	while (in[i] != '\0') {
		out[end+i]=in[i];
		i++;
	}
	 out[end+i]='\0';
}
