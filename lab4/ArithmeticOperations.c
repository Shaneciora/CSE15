//
//  ArithmeticOperations.c
//  
//

#include <stdio.h>
#include <stdlib.h>

//  Define fptr_t type using typedef statement


//  Define functions
int sum(int x, int y){
    
}

int diff(int x, int y){
    
}

int prod(int x, int y){
    
}

int rem(int x, int y){
    
}

int apply(fptr_t fp, int x, int y){
    
}

int compute(fptr_t fcn[5], int* A, int* idx, int n){
    
}

void testCompute(){
   fptr_t op[]  = {sum, diff, prod, quot, rem};
   int A[]      = {3, 2, 5, 4, 6, 7, 9, 2, 8};
   int opCode[] = {0, 2, 1, 4, 2, 2, 3, 1};
   int n = 8;

   //--------------------------------------------------------------------------
   // prints 86, which is the value of the value of the expression:
   //
   //               (((((((3+2)*5)-4)%6)*7)*9)/2)-8
   //
   //--------------------------------------------------------------------------
   printf("%d\n", compute(op, A, opCode, n));
}

int main(){

   testCompute();  // output should be 86

   return EXIT_SUCCESS;
}
