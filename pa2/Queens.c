#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


int can_place(int** B, int n, int i, int j){
	int l, k;
	int attack_condition1 = i - j;
	int attack_condition2 = i + j;
	for(l = 1; l < n; l++){
		for(k = 1; k < n; k++){
			//Found a queen
			if(B[l][k] == 1){
				if(
                   //Check Diagnals
                   ((l-k) == attack_condition1) ||
                   ((l+k) == attack_condition2) ||
                   
                   //Check row and collum
                   (l == i) ||
                   (k == j)
                   ){
					return 0;
				}
			}
		}
	}
	return 1;
}



void placeQueen(int** B, int n, int i, int j){
    B[i][j] = 1;
	B[i][0] = j;
}

void removeQueen(int** B, int n, int i, int j){
	B[i][j] = 0;
	B[i][0] = 0;
}


void printBoard(int** B, int n){
    printf("(");
    for(int i = 1; i < n; i++){
        printf("%d", B[i][0]);
        if(i==n-1){
            printf(")");
        }else{
            printf(", ");
        }
    }
    printf("\n");
}

int findSolutions(int** B, int n, int i, char* mode){
	if(i >= n){
		return B[0][0];
	}
	else{
		for(int j = 1; j < n; j++){
			if(can_place(B, n, i, j) == 1){
				placeQueen(B, n, i, j);
				findSolutions(B, n, i + 1, mode);
                if(B[n-1][0] != 0){
                    B[0][0]++;
                    if(strcmp(mode, "-v") == 0){
                        printBoard(B, n);
                    }
                }
				removeQueen(B, n, i, j);
            }
		}
	}
	return B[0][0];
}




void intialize_array(int** B, int n){
	for(int i = 0;i < n; i++){
		for(int j = 0; j < n; j++){
			B[i][j] = 0;
		}
	}
}

void print_usage(){
    printf("Usage: Queens [-v] number\n");
    printf("Option: -v verbose output, print all solutions\n");
    exit(0);
}

int main(int argc, char* argv[]){
    
    //Check for correct amount of arguments
    if(argc < 2 || argc > 3){
        print_usage();
    }
    
    //delcarations
    char *mode = "";
    int n = 0;
	int **B;
    char* cma_1 = argv[1];
    
    //handling command line arguments
    if(isdigit(cma_1[0])){
        n = atoi(cma_1) + 1;
    }else if(argv[1][0] == '-' && argv[1][1] == 'v'){
        mode = "-v";
        char* cma_2 = argv[2];
        if(isdigit(cma_2[0])){
            n = atoi(cma_2) + 1;
        }else{
            print_usage();
        }
    }else{
        print_usage();
    }
    
    
	B = (int **)calloc(n, sizeof(int*));
	for(int i = 0; i < n; i++){
		B[i] = (int *)calloc(n, sizeof(int));
	}

	intialize_array(B, n);
	int num_sol = findSolutions(B, n, 1, mode);
	printf("%d-Queens has %d solutions\n", n-1, num_sol);
    
    for(int i = 0; i < n; i++){
        free(B[i]);
    }
    free(B);

}
