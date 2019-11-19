//
//  ArithmeticOperations.c
//  
//

#include <stdio.h>
#include <stdlib.h>


//  Define fptr_t type using typedef statement
typedef int (*fptr_t)(int, int);

//define operations
int sum(int x, int y){
    //printf("SUM:    %d + %d = %d\n", x, y, x+y);
    return x+y;
}
 
int diff(int x, int y){
    //printf("DIFF:   %d - %d = %d\n", x, y, x-y);
    return x-y;
}

int prod(int x, int y){
    //printf("PROD:   %d * %d = %d\n", x, y, x*y);
    return x*y;
}

int quot(int x, int y){
    //printf("QUOT:   %d / %d = %d\n", x, y, x/y);
    return x/y;
}

int rem(int x, int y){
    //printf("REM:    %d rem %d = %d\n", x, y, x%y);
    return x%y;
}

int apply( fptr_t fp, int x, int y){
    return fp(x, y);
}

int compute(fptr_t fcn[5], int* A, int* idx, int n){
    int result = 0;
    int j = 0;
    for(int i = 0; i < n; i++){

        //first iteration
        if(i == 0){
            result = apply(fcn[idx[i]], A[j], A[j+1]);
            j += 2;
        }

        //not first iteration
        else{
            result = apply(fcn[idx[i]], result, A[j]);
            j++;
        }
    }
    return result;
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
