//  CSE-15-Fall19
//  IntegerStack.c
//  Lab 3
//  Shane Ciora
//  1449570

#include<stdio.h>
#include<stdlib.h>
#include"IntegerStack.h"

//  Private Types and Funcitons -----------------------------------------------
// InitialSize
static const int InitialSize = 1;

typedef struct IntegerStackObj{
    int* item;          // array of IntegerStack items
    int numItems;       // number of items in this IntegerStack
    int physicalSize;   // current length of underlying array
} IntegerStackObj;

// doubleItemArray
// Doubles the physical size of the underlying array L->item.
void doubleItemArray(IntegerStack S){
   int i;
   int* newArray;
   int* oldArray = S->item;
   S->physicalSize *= 2;
   newArray = calloc(S->physicalSize, sizeof(int));
   for( i=0; i<(S->numItems); i++){
      newArray[i] = oldArray[i];
   }
   S->item = newArray;
   free(oldArray);
}

//  Constructors Destructors --------------------------------------------------

// newIntegerStack()
// Constructor for the IntegerStack ADT
IntegerStack newIntegerStack(){
    IntegerStack S = malloc(sizeof(IntegerStack));
    S->item = calloc(InitialSize, sizeof(int));
    S->numItems = 0;
    S->physicalSize = InitialSize;
    return S;
}

// freeIntegerStack()
// Destructor for the Stack ADT
void freeIntegerStack(IntegerStack* pS){
    if( pS!=NULL && *pS!=NULL ){
       free((*pS)->item);
       free(*pS);
       *pS = NULL;
    }
}

// ADT operations -------------------------------------------------------------
// isEmpty()
// Returns true (1) if S is empty, false (0) otherwise.
int isEmpty(IntegerStack S){
    if( S==NULL ){
       fprintf(stderr, "IntegerStack Error: isEmpty() called on NULL IntegerStack reference");
       exit(EXIT_FAILURE);
    }

    return (S->numItems == 0);
}

// push()
// Pushes x on top of S.
void push(IntegerStack S, int x){
    if( S==NULL ){
       fprintf(stderr, "IntegerStack Error: push() called on NULL IntegerStack reference");
       exit(EXIT_FAILURE);
    }
    if((S->numItems)==(S->physicalSize) ){
       doubleItemArray(S);
    }
    S->item[S->numItems] = x;
    S->numItems++;
}

// pop()
// Deletes and returns integer at top of S.
// Pre: !isEmpty(S)
int pop(IntegerStack S){
    if( S==NULL ){
       fprintf(stderr, "IntegerStack Error: pop() called on NULL IntegerStack reference");
       exit(EXIT_FAILURE);
    }
    if(isEmpty(S) == 1){
        fprintf(stderr, "IntegerStack Error: pop() called on an empty IntegerStack reference");
        exit(EXIT_FAILURE);
    }
    S->numItems--;
    return(S->item[S->numItems]);
}

// peek()
// Returns integer at top of S.
// Pre: !isEmpty(S)
int peek(IntegerStack S){
    return(S->item[(S->numItems) - 1]);
}

// popAll()
// Resets S to the empty state.
void popAll(IntegerStack S){
    while((S->numItems) > 0){
        pop(S);
    }
}


// Other Operations -----------------------------------------------------------

// printIntegerStack()
// Prints a space separated list of integers in S, from top to bottom, to the
// filestream out.
void printIntegerStack(FILE* out, IntegerStack S){
    for(int i = (S->numItems) - 1; i >= 0; i--){
        fprintf(out, "%d ", (S->item[i]));
    }
    fprintf(out, "\n");
}

// equals()
// Returns true (1) if S and T are matching sequences of integers, false (0)
// otherwise.
int equals(IntegerStack S, IntegerStack T){
    //check if sizes are equal
    if((S->numItems) != (T->numItems)){
        return 0;
    }else{
        //if the sizes are equal, check contents
        for(int i = 0; i < (S->numItems); i++){
            //if two items are not equal
            if( (S->item[i]) != (T->item[i])){
                return 0;
                break;
            }
        }
        return 1;
    }
}
