//
//  IntegerQueue.c
//  
//
//  Created by Shane Ciora on 11/20/19.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "IntegerQueue.h"

// Private Types and Functions ------------------------------------------------

//NodeObj
typedef struct NodeObj{
    int key;
    struct NodeObj* next;
} NodeObj;

typedef NodeObj* Node;

//IntegerQueueObj
typedef struct IntegerQueueObj{
    Node front;
    Node back;
    int numItems;
} IntegerQueueObj;


//newNode(int k) Creates new nodes
Node newNode(int k){
    Node N = malloc(sizeof(NodeObj));
    N->key = k;
    N->next = NULL;
    return N;
}

//Free existing Node
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// Constructors-Destructors ---------------------------------------------------

void deleteAll(IntegerQueue Q){
   Node N = NULL;
   if( Q == NULL ){
      exit(EXIT_FAILURE);
   }

   while( Q->numItems > 0 ){
      N = Q->front;
      Q->front = Q->front->next;
      N->next = NULL;
      freeNode(&N);
      Q->numItems--;
   }
}

IntegerQueue newIntegerQueue(){
    IntegerQueue Q = malloc(sizeof(IntegerQueue));
    Q->numItems = 0;
    Q->front = NULL;
    Q->back = NULL;
    return Q;
}

// freeIntegerQueue()
// Destructor for the Queue ADT
void freeIntegerQueue(IntegerQueue* pQ){
    if( pQ!=NULL && *pQ!=NULL ){
        //printf("[LOG]: Freeing Integer Queue\n");
        deleteAll(*pQ);
        free(*pQ);
        *pQ = NULL;
    }
}

// ADT operations -------------------------------------------------------------

// isEmpty()
// Returns 1 (true) if Queue Q is empty, 0 (false) otherwise.=
int isEmpty(IntegerQueue Q){
    if(Q->numItems == 0){
        //printf("[LOG]: isEmpty = EMPTY\n");
        return 1;
    }else{
        //printf("[LOG]: isEmpty = NOT EMPTY\n");
        return 0;
    }
}

// length()
// Returns the number of elements in Q
int length(IntegerQueue Q){
    return Q->numItems;
}

// enqueue()
// Inserts x at back of Q.
void enqueue(IntegerQueue Q, int x){
    Node N = newNode(x);
    
    //If Queue is empty
    if(isEmpty(Q) == 1){
        //printf("[LOG]: enqueue(%d) to EMPTY queue\n", x);
        Q->front = N;
        Q->back = N;
        //printf("[LOG]: Front = %d         Back = %d\n", Q->front->key, Q->back->key);
    }else{  //If Queue is NOT empty
        //printf("[LOG]: enqueue(%d) to NON-EMPTY queue\n", x);
        Q->back->next = N;
        Q->back = N;
        //printf("[LOG]: Front = %d         Back = %d\n", Q->front->key, Q->back->key);
    }
    Q->numItems++;
    //printf("[LOG]: numItems = %d\n", Q->numItems);
    //printf("----------------------------------------------\n");
}

// dequeue()
// Deletes and returns the item at front of Q.
// Pre: !isEmpty()
int dequeue(IntegerQueue Q){
    int item = 0;
    //Check if Empty
    if(isEmpty(Q) == 1){
        exit(EXIT_FAILURE);
    }else{
        Node N = Q->front;
        item = N->key;
        //printf("[LOG]: dequeue(%d) from queue\n", item);
        Q->front = Q->front->next;
        freeNode(&N);
        Q->numItems--;
        
        //printf("[LOG]: Front = %d         Back = %d\n", Q->front->key, Q->back->key);
    }
    //printf("[LOG]: numItems = %d\n", Q->numItems);
    //printf("----------------------------------------------\n");
    return item;
}

// peek()
// Returns the item at front of Q.
// Pre: !isEmpty()
int peek(IntegerQueue Q){
    if(isEmpty(Q) == 1){
        exit(EXIT_FAILURE);
    }else{
        return Q->front->key;
    }
    
}

// dequeueAll()
// Resets Q to the empty state.
void dequeueAll(IntegerQueue Q){
    while(Q->numItems > 0){
        dequeue(Q);
    }
}

// Other Operations -----------------------------------------------------------

int digitCount(int x){
    int digits = 0;
    while(x != 0){
        x /= 10;
        digits++;
    }
    return digits;
}

int scanStringQueue(IntegerQueue Q){
    Node N = Q->front;
    int str_len = 0;
    while(N != NULL){
        int key = N->key;
        while(key != 0){
            key /= 10;
            str_len++;
        }
        //printf("Key: %d\n", N->key);
        N = N->next;
        str_len++; //add index for spaces
    }
    return str_len;
}


// IntegerQueueToString()
// Determines a text representation of IntegerQueue Q. Returns a pointer to a
// char array, allocated from heap memory, containing the integer sequence
// represented by Q. The sequence is traversed from front to back, each integer
// is added to the string followed by a single space. The array is terminated
// by a NUL '\0' character. It is the responsibility of the calling function to
// free this heap memory.
char* IntegerQueueToString(IntegerQueue Q){
    int str_len = scanStringQueue(Q);
    char* str = calloc((str_len + 1), sizeof(char));
    Node N = Q->front;
    while(N != NULL){
        char str_key[digitCount(N->key)];
        sprintf(str_key, "%d ", N->key);
        strcat(str, str_key);
        N = N->next;
    }
    str[str_len] = '\0';
    return str;
}

// equals()
// Returns true (1) if Q and R are matching sequences of integers, false (0)
// otherwise.
int equals(IntegerQueue Q, IntegerQueue R){
    
    //check if same length
    if(Q->numItems != R->numItems){
        return 0;
    }else{ //if same length, check contents
        Node N = Q->front;
        Node M = R->front;
        while(N != NULL){
            if(N->key != M->key){
                return 0;
            }
            N = N->next;
            M = M->next;
        }
        return 1;
    }
}


/* Output of this program: ****************************************************
true
true
false
5 3 9 7 8
5
7
7 8
7 8
true
7 8 12
7 8 13
false
true
true
A: 0 1 2 3 4 5 6 7 8 9
B:
A: 1 2 3 4 5 6 7 8 9 0
B:
A: 2 3 4 5 6 7 8 9 0
B: 1
A: 3 4 5 6 7 8 9 0
B: 1 2
A: 4 5 6 7 8 9 0 1
B: 2 3
A: 5 6 7 8 9 0 1
B: 2 3 4
A: 6 7 8 9 0 1
B: 2 3 4 5
A: 7 8 9 0 1 2
B: 3 4 5 6
A: 8 9 0 1 2
B: 3 4 5 6 7
A: 9 0 1 2
B: 3 4 5 6 7 8
A: 0 1 2 3
B: 4 5 6 7 8 9
A: 1 2 3 4
B: 5 6 7 8 9 0
A: 2 3 4
B: 5 6 7 8 9 0 1
A: 3 4
B: 5 6 7 8 9 0 1 2
A: 4 5
B: 6 7 8 9 0 1 2 3
A: 5
B: 6 7 8 9 0 1 2 3 4
A:
B: 6 7 8 9 0 1 2 3 4 5
******************************************************************************/

