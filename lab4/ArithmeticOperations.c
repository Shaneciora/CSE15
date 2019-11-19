//
//  ArithmeticOperations.c
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

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


void print_line(int* A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(int argc, char* argv[]){
    FILE *in;                   //input file var
    in = fopen(argv[1], "r");   //open input file
    int line_num = 1, n = 0;
    char line[MAX_STRING_LENGTH+1];
    char in_line1[MAX_STRING_LENGTH+1];
    char in_line2[MAX_STRING_LENGTH+1];
    char in_line3[MAX_STRING_LENGTH+1];
    
    
    memset(in_line1, '\0', sizeof(in_line1));
    memset(in_line2, '\0', sizeof(in_line2));
    memset(in_line3, '\0', sizeof(in_line3));
    
    
    while(fgets(line, sizeof(line), in) != NULL){
        if(line_num == 1){
            strcpy(in_line1, line);
            line_num++;
        }else if(line_num == 2){
            strcpy(in_line2, line);
            line_num++;
        }else if(line_num == 3){
            strcpy(in_line3, line);
            line_num++;
        }
    }
    
    n = atoi(in_line1);
    //printf("n is %s\n", in_line1);
    
    int* line1 = calloc(1, sizeof(int) );
    int* line2 = calloc(n, sizeof(int) );
    int* line3 = calloc(n+1, sizeof(int) );
    line1[0] = n;
    
    int j = 0;
    for(int i = 0; i < n*2; i++){
        if(in_line2[i] != ' '){
            line2[j] = in_line2[i] - '0';
            j++;
        }
    }
    j = 0;
    for(int i = 0; i < (n*2)+1; i++){
        if(in_line3[i] != ' '){
            line3[j] = in_line3[i] - '0';
            j++;
        }
    }
    fptr_t op[]  = {sum, diff, prod, quot, rem};
    printf("%d\n", compute(op, line3, line2, n));
//    printf("n = %d\n", n);
//    fputs(in_line1, stdout);
//    fputs(in_line2, stdout);
//    fputs(in_line3, stdout);
//    printf("-------------------\n");
//    print_line(line1, 1);
//    print_line(line2, n);
//    print_line(line3, n+1);

    return EXIT_SUCCESS;
}
