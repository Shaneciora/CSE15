//
//  Dictionary.c
//
//

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include"Dictionary.h"


// Private Types and Functions ------------------------------------------------

// NodeObj
typedef struct NodeObj{
    char* key;
    char* value;
    struct NodeObj* next;
} NodeObj;

// Node
typedef NodeObj* Node;

// newNode()
// Constructor for private Node type.
Node newNode(char* k, char* v) {
    Node N = malloc(sizeof(NodeObj));
    N->key = k;
    N->value = v;
    N->next = NULL;
    return N;
}

// freeNode()
// Destructor for private Node type
void freeNode(Node* pN){
   if( pN!=NULL && *pN!=NULL ){
      free(*pN);
      *pN = NULL;
   }
}

// DictionaryObj
typedef struct DictionaryObj{
    Node head;
    int numItems;
} DictionaryObj;

Node find(Dictionary D, char* k){
    //printf("LOG: Entered Find\n");
    Node N = D->head;
    //printf("LOG: NumItems: %d\n", (D->numItems));
    int numItems = (D->numItems);
    if(numItems == 0){
        //printf("LOG: 0 items, so return NULL\n");
        return N;
    }
    //for(int i = 0; i<numItems; i++){
    while(N != NULL){
        //printf("LOG: In the loop\n");
        char* k_index;
        if((N->key) != NULL){
            k_index = N->key;
        }
        //printf("LOG: Next Node (%s)\n", k_index);
        if(N != NULL){
            if(strcmp(k_index, k) == 0){
                //printf("LOG: Looking for Node\n");
                return N;
                break;
            }
            N = N->next;
        }
    }
    return NULL;
}

// Constructors-Destructors ---------------------------------------------------

// newDictionary()
// Constructor for the Dictionary ADT.
Dictionary newDictionary(){
    Dictionary D = malloc(sizeof(Dictionary));
    D->head = NULL;
    D->numItems = 0;
    //printf("LOG: Created Dictionary\n");
    return D;
}

// deleteAll()
// Reset D to the empty state.
void deleteAll(Dictionary D){
   Node N=NULL;
   if( D==NULL ){
   //   fprintf(stderr,
     //    "Dictionary Error: calling deleteAll() on NULL Dictionary reference\n");
      exit(EXIT_FAILURE);
   }

   while( D->numItems > 0 ){
      N = D->head;
      D->head = D->head->next;
      N->next = NULL;
      freeNode(&N);
      D->numItems--;
   }
}

// freeDictionary()
// Destructor for the Dictionary ADT.
void freeDictionary(Dictionary* pD){
    if( pD!=NULL && *pD!=NULL ){
        deleteAll(*pD);
        free(*pD);
        *pD = NULL;
    }
}


// ADT operations -------------------------------------------------------------

// size()
// Return the number of (key, value) pairs in Dictionary D.
int size(Dictionary D){
    return (D->numItems);
}

// lookup()
// If D contains a pair whose key matches argument k, then return the
// corresponding value, otherwise return NULL.
char* lookup(Dictionary D, char* k){
    //printf("LOG: Looking up node\n");
    Node N = D->head;
    if( D==NULL ){
      // fprintf(stderr,
        //  "Dictionary Error: calling get() on NULL Dictionary reference\n");
       exit(EXIT_FAILURE);
    }
    //printf("LOG: Lookup -> find\n");
    N = find(D, k);
    if(N == NULL){
        return NULL;
    }else{
        return N->value;
    }
    
}

// insert()
// Insert the pair (k,v) into D.
// Pre: lookup(D, k)==NULL (D does not contain a pair whose first member is k.)
void insert(Dictionary D, char* k, char* v){
    Node N = NULL, P = NULL, C = NULL;

    C = find(D,k);
    
    if(C != NULL){
        exit(EXIT_FAILURE);
    }
    
    //not at head
    if((D->numItems) != 0){
        N = D->head;
        P = newNode(k,v);
        for(int i = 0; i<(D->numItems); i++){
            if(N->next != NULL){
                N = N->next;
            }else{
                N->next = P;
            }
        }
        P = NULL;
        freeNode(&P);
    }else{//insert at head
        N = newNode(k, v);
        N->next = D->head;
        D->head = N;
        N = NULL;
        freeNode(&N);
    }
    (D->numItems)++;
}

// delete()
// Remove pair whose first member is the argument k from D.
// Pre: lookup(D,k)!=NULL (D contains a pair whose first member is k.)
void delete(Dictionary D, char* k){
    Node N=NULL;
    Node P=NULL;
    Node C=NULL;
    
    P = find(D,k);

    //if key is does not exist
    if(P == NULL){
        //do nothing
    }else{  //if key does exist
        N = D->head;
        //if its at the head
        if(P == N){
            C = N->next;
            D->head = C;
            N = NULL;
            freeNode(&N);
        }else{//if its not at the head
            //find node before the one being deleted
            while(N->next != P){
                N = N->next;
            }
            C = N; //Node before the node being deleted
            N = N->next; //Node that is being deleted
            C->next = N->next;
            N = NULL;
            freeNode(&N);
        }
        
    }
    (D->numItems)--;
}

// makeEmpty()
// Reset D to the empty state, the empty set of pairs.
void makeEmpty(Dictionary D){
    Node N=NULL;
    while( D->numItems > 0 ){
       N = D->head;
       D->head = D->head->next;
       N->next = NULL;
       freeNode(&N);
       D->numItems--;
    }
}

int countChars(Dictionary D){
    Node N;
     N = D->head;
     int output_len = 0;
     while(N != NULL){
         int k_len = strlen(N->key);
         int v_len = strlen(N->value);
         output_len += k_len;
         output_len += v_len;
         output_len += 3;
         N = N->next;
     }
    //for newline char
    output_len++;
    
    return output_len;
}

// Other Operations -----------------------------------------------------------

// DictionaryToString()
// Determines a text representation of the current state of Dictionary D. Each
// (key, value) pair is represented as the chars in key, followed by a space,
// followed by the chars in value, followed by a newline '\n' char. The pairs
// occur in the same order they were inserted into D. The function returns a
// pointer to a char array, allocated from heap memory, containing the text
// representation described above, followed by a terminating null '\0' char.
// It is the responsibility of the calling function to free this memory.
char* DictionaryToString(Dictionary D){
    //printf("LOG: Printing\n");
    int output_len = countChars(D);
    char* str = calloc(output_len+1, sizeof(char));
    Node N = D->head;
    int i = 0;
    while(N != NULL){
        strcpy(str+i, N->key);
        i += strlen(N->key);
        str[i] = ' ';
        i++;
        strcpy(str+i, N->value);
        i += strlen(N->value);
        str[i] = '\n';
        i++;
        N = N->next;
    }
    if( (D->numItems)>0 ) i--;
    str[i] = '\n';
    str[i+1] = '\0';  // overwrite last space with terminating null '\0'

    return str;
}
