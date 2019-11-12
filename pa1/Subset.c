//-----------------------------------
//	Subset.c	
//
//	Shane Ciora
//	1449570
//
//	COMPILE:
//	gcc -std=c99 -o Subset Subset.c
//
//	RUN:
//	./Subset 4 2
//
//
//
//	Code Credit:
//	-Bulk of code was written by me (Shane Ciora).
//	-Parts of code were used from Professor Tantalo's examples for PA1 (on the calss website).
//----------------------------------

//libraries
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define MAX_SIZE 100

void printSet (int B[], int n){
	int commaCount = 0;
	for(int i = 0; i < n +1; i++){
		if(B[i+1] == 1){
			commaCount++;
		}
	}

	commaCount--;
//	printf("\n");
//	printf("====OUTPUT=====\n");
	printf("{");

	for(int i = 0; i < n +1; i++){
		if(B[i+1] == 1){
			printf("%d", i+1);
			if(commaCount > 0){
				printf(", ");
				commaCount--;
			}
		}
	}

	printf("}\n");
//	printf("==============\n");
//	printf("\n");
//	printf("====PRINTED ARRAY=====\n");
//	for(int i = 0; i < n + 2; i++){
  // 		printf("B[%d]: %d\n", i, B[i]);
//	}
//	printf("\n");
	
}







void printSubsets(int B[], int n, int k, int i){
//	printf("=======START=======\n");
//	printf("k = %d   i = %d\n", k, i);
//	printf("=================\n");
	if(i > n + 1){
		
//		printf("=======END=======\n");
//		printf("k = %d   i = %d\n", k, i);
//		printf("=================\n");
		
	}
	else{
		if(k > 0){

			B[i] = 1;
			printSubsets(B, n, k-1, i+1);
//			printf("k = %d   i = %d\n", k, i);
			if(i <= k){
				if(k == (n-k+1)){
//					printf("HERE1\n");
					for(int l = 1; l < MAX_SIZE; l++){
						B[l] = 0;
					}
					printSubsets(B, n, k, i+1);
				}else{
//					printf("HERE2\n");
					for(int l = i; l < MAX_SIZE; l++){
						B[l] = 0;
					}
					printSubsets(B, n, k, i+1);
				}
				
			}
		}else{
//			printf("k1 = %d   i1 = %d\n", k, i);
			printSet(B, n);
			B[i-1]=0;
			printSubsets(B, n, k+1, i);
		}
	}
}








//main(with args)
int main(int argc, char* argv[]) {
	
	//array to hold command line arguments
	int CLE[] = {0,0};

	//If more than 3 arguments or less than 2 arguments, throw error
	if(argc == 1 || argc > 3){
		printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
   		return EXIT_SUCCESS;
	}
	//Code Provided by the Professor to check if the inputs are integers, strings, or doubles
	int i, q, status;
	double x;
	char ch;
	   
   	for( i=1; i<argc; i++){
      	// try to parse argv[i] as int
     	status = sscanf(argv[i], "%d%c", &q, &ch);  // why is ch needed?
     	if(status==1){
     		CLE[i - 1] = q;
       	  	continue; // skip rest of this iteration
     	}
      	// try to parse argv[i] as double
      	status = sscanf(argv[i], "%lf", &x);
      	if(status==1){
        	printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
   			return EXIT_SUCCESS;
      	}
    	// at this point, argv[i] must be a non-numeric string
    		printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
   			return EXIT_SUCCESS;
   	}
   	//if n < k, throw error
   	if(CLE[0] < CLE[1]){
   		printf("Usage: Subset n k (n and k are ints satisfying 0<=k<=n<=100)\n");
   		return EXIT_SUCCESS;
   	}


   	int n = CLE[0];
   	int k = CLE[1];
	//Display Numbers
//   	printf("Entered Numbers: {%d,%d}\n", n, k);

   	//Initializing B[]
	int B[MAX_SIZE];
	for(int i = 0; i < MAX_SIZE; i++){
		B[i] = 0;
	}

   	printSubsets(B, n, k, 1);

   	return EXIT_SUCCESS;
	

}
