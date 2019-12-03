//
//  IntegerQueue.c
//  
//
//  Created by Shane Ciora on 11/20/19.
//

#include <stdio.h>
#include <stdlib.h>
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
        //deleteAll(*pD);
        free(*pQ);
        *pQ = NULL;
    }
}

// ADT operations -------------------------------------------------------------

// isEmpty()
// Returns 1 (true) if Queue Q is empty, 0 (false) otherwise.=
int isEmpty(IntegerQueue Q){
    if(Q->numItems == 0){
        return 1;
    }else{
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
        Q->front = N;
        Q->back = N;
    }else{  //If Queue is NOT empty
        Q->back->next = NULL;
        Q->back = N;
    }
    Q->numItems++;
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
        Q->front = Q->front->next;
        freeNode(&N);
        Q->numItems--;
    }
    return item;
}

// peek()
// Returns the item at front of Q.
// Pre: !isEmpty()
int peek(IntegerQueue Q){
    return Q->front->key;
}

// dequeueAll()
// Resets Q to the empty state.
void dequeueAll(IntegerQueue Q){
    
}

// Other Operations -----------------------------------------------------------

// IntegerQueueToString()
// Determines a text representation of IntegerQueue Q. Returns a pointer to a
// char array, allocated from heap memory, containing the integer sequence
// represented by Q. The sequence is traversed from front to back, each integer
// is added to the string followed by a single space. The array is terminated
// by a NUL '\n' character. It is the responsibility of the calling function to
// free this heap memory.
char* IntegerQueueToString(IntegerQueue Q){
    return "test\n";
}

// equals()
// Returns true (1) if Q and R are matching sequences of integers, false (0)
// otherwise.
int equals(IntegerQueue Q, IntegerQueue R){
    return 0;
}
