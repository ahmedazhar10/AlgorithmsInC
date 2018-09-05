/*
 ============================================================================
 Name        : SwapExample.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void swap(int*x, int*y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main(int agrc, char *argv[]){
	int a=10;
	int b=50;
	int* pa=&a;
	int* pb=&b;
	printf("a= %d \t b= %d\n",*pa,*pb);
	printf("swapping\n");
	swap(pa,pb);
	printf("a= %d \t b= %d\n",*pa,*pb);
}
