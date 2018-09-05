/*
 * Name: Ahmad Azhar Student ID: 260733580
 Assignment 2 ECSE202
 This program assumes that
 a names and IDs data file (location and name) is passed as the first argument
 a marks data files is passed as the second argument
 an ID number is passed as the third argument
 */

#include <stdio.h>
#include <stdlib.h>


#define NUMRECORDS 50
#define MAXNAMELENGTH 30

//Define structure to hold student data
struct StudentRecord
{
	char FirstNames[MAXNAMELENGTH];
	char LastNames[MAXNAMELENGTH]; /*These are the 4 instances of the declared structure*/
	int IDNums;
	int Marks;
};

void swap_it( struct StudentRecord SRecords[], int a, int b){  /*this function is to be used in the following partition function for Quicksort*/
	struct StudentRecord temp=SRecords[a];  /*temp was used to store data of index_a to add it to index_b and index_a gets the original data of index_b*/
	SRecords [a]=SRecords [b];
	SRecords [b]= temp;  			 /*data in indexes have been swapped successfully*/
}

int partition(struct StudentRecord SRecords[], int first, int last){ /*this function will be used in the QuickSort algorithm*/
	int pivot=SRecords[last].IDNums;          				/*the "." operator is used to select IDNums from the declared structure*/
	int part_Index=first;      		/* the partition index has been set to first*/
	for(int i=first; i<last; i++){
		if(SRecords[i].IDNums<=pivot){  /*a logical decision is being made here*/
			swap_it(SRecords,i, part_Index);  		 /*performs swap  if the condition is true(i.e. element less than pivot)*/
			part_Index ++;
		}
	}
	swap_it(SRecords,last,part_Index);       /*this will swap the pivot with the element at partition index*/
	return part_Index;

}

void Quick_Sort(struct StudentRecord SRecords[],int first, int last){
	if(first<last){
		int	part_Index=partition(SRecords, first, last );   /*the partition function has been called here*/
		Quick_Sort(SRecords, first, part_Index-1);    /*this step will sort the left portion of the partition index*/
		Quick_Sort(SRecords,part_Index+1, last);   /*this step will sort the right portion of the partition index*/
	}
}

int binary_search(struct StudentRecord SRecords[], int ID_Num){  /*This function is used to search for a record using the ID number, in the sorted array*/
	int min=0;
	int max=NUMRECORDS;
	while(min<=max){                       /*An iterative loop is required to carry on the binary search*/
		int mid=(min+(max-1))/2;
		if(SRecords[mid].IDNums==ID_Num){
			return mid;
		}
		else if(SRecords[mid].IDNums>ID_Num){
			 max=mid-1;          					/*The ID number searched for is before the midpoint*/
		}
		else if(SRecords[mid].IDNums<ID_Num)
			min=mid+1;                         /*The ID number searched for is after the midpoint*/
		}
	  return 0;
	}




int main(int argc, char * argv[]) {

	struct StudentRecord SRecords[NUMRECORDS];
	int recordnum;

	//Read in Names and ID data
	FILE * NamesIDsDataFile;
	if((NamesIDsDataFile = fopen(argv[1], "r")) == NULL){
		printf("Can't read from file %s\n", argv[1]);
		exit(1);
	}
	for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
		fscanf (NamesIDsDataFile, "%s%s%d", &(SRecords[recordnum].FirstNames[0]),&(SRecords[recordnum].LastNames[0]),&(SRecords[recordnum].IDNums));
	}
	fclose(NamesIDsDataFile);

	//Read in marks data
	FILE * MarksDataFile;
	if((MarksDataFile = fopen(argv[2], "r")) == NULL){
		printf("Can't read from file %s\n", argv[2]);
		exit(1);
	}
	for (recordnum=0;recordnum<NUMRECORDS;recordnum++){
		fscanf (MarksDataFile, "%d", &(SRecords[recordnum].Marks));
	}
	fclose(MarksDataFile);

	//Print out data as read in
	for(recordnum=0;recordnum<NUMRECORDS;recordnum++){
		printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
	}

Quick_Sort( SRecords,0,NUMRECORDS);   		/*records being sorted using Quicksort*/
	printf("\n\n");
	printf("Records sorted by ID \n");
	/*to print the sorted records*/
	for(recordnum=0;recordnum<NUMRECORDS;recordnum++){
		printf("%s %s %d %d\n",SRecords[recordnum].FirstNames,SRecords[recordnum].LastNames,SRecords[recordnum].IDNums, SRecords[recordnum].Marks);
	}
	int indexSearch=binary_search(SRecords,atoi(argv[3])); /*to find a record, given the ID number as input*/

		printf("\n\n");

		/*to print the whole record of that particular ID number*/
		if(indexSearch){
			struct StudentRecord SRecords[indexSearch];
			printf("ID:%i Student: %s,%s Mark: %i \n",SRecords[indexSearch].IDNums,SRecords[indexSearch].LastNames,SRecords[indexSearch].FirstNames,SRecords[indexSearch].Marks);
		}
		else{
			printf("ID:%i does not exist\n",atoi(argv[3]));
	}

	return EXIT_SUCCESS;
}



