/*
 ============================================================================
 Name        : Azhar-Ahmed-260733580-Q4.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>



int doHist(char buffer[], char hist[]);
void append (char buffer[], char in[]);
void toString(int argc, char *argv[], char buffer[]);
void displayHist(char hist[],int distinct_chars);

int main(int argc, char *argv[]){
char buffer[100]="";
toString(argc,argv,buffer);
char hist[256];
doHist(buffer, hist);
int distinct_chars;
distinct_chars = (int)doHist;
displayHist(hist, distinct_chars);

return 0;

}

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





