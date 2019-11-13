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

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

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
    printf(ANSI_COLOR_YELLOW "FIND: Finding key [%s]\n" ANSI_COLOR_RESET, k);
    Node N = D->head;
    //printf("LOG: NumItems: %d\n", (D->numItems));
    int numItems = (D->numItems);
//    if(numItems == 0){
//        printf("LOG: 0 items, so return NULL\n");
//        return NULL;
//    }
    
    for(int i = 0; i<numItems; i++){
        //printf("LOG: In the loop\n");
        //printf("LOG: Next Node (%s)\n", k_index);
        if(N != NULL){
            if(strcmp(k, N->key) == 0){
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
    Node N = D->head;
    if( D==NULL ){
       exit(EXIT_FAILURE);
    }
    
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
    printf(ANSI_COLOR_GREEN "INSERT: Inserting (%s, %s)\n" ANSI_COLOR_RESET, k, v);
    Node N = NULL, P = NULL, C = NULL;
    P = find(D,k);

    if(P != NULL){
        exit(EXIT_FAILURE);
    }
    
//    printf("\x1b[31m" "LOG: Key does not exist, creating new Node of (%s, %s)" "\x1b[0m" "\n", k, v);
//    if(D->head == NULL){
//        printf("\x1b[33m" "Head is empty, so create one" "\x1b[0m" "\n");
//        N = newNode(k, v);
//        D->head = N;
//        (D->numItems++);
//    }else{
//        printf("\x1b[32m" "Head is NOT empty, adding entry" "\x1b[0m" "\n");
//        N = D->head;
//        while(N != NULL){
//            N = N->next;
//        }
//        N = newNode(k, v);
//        (D->numItems++);
//    }
    
    
    
    N = newNode(k, v);
    N->next = D->head;
    D->head = N;
    (D->numItems)++;
    
    
//    else{  //if key does exist
//        printf("\x1b[31m" "LOG: Key does exist, creating new link (%s, %s)" "\x1b[0m" "\n", k, v);
//        C = P->next;
//        P->next = newNode(k, v);
//        P = P->next;
//        P->next = C;
//    }
}

// delete()
// Remove pair whose first member is the argument k from D.
// Pre: lookup(D,k)!=NULL (D contains a pair whose first member is k.)
void delete(Dictionary D, char* k){
    Node N=NULL, P=NULL;
    
    P = find(D,k);
    //if key is does not exist
    if(P == NULL){
        //do nothing
    }else{  //if key does exist
        N = P->next;
        P->next = N->next;
        N->next = NULL;
        freeNode(&N);
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
    int output_len = countChars(D);
    printf(ANSI_COLOR_CYAN "Making array size of %d\n" ANSI_COLOR_RESET, output_len);
    char* str = calloc(output_len+1, sizeof(char));
    Node N;
    N = D->head;
    int i = 0;
    while(N != NULL){
        strcpy(str+i, N->key);
        i += strlen(N->key);
        str[i] = ' ';
        strcpy(str+i, N->value);
        i += strlen(N->value);
        str[i] = '\n';
        i += 2;
        N = N->next;
    }
    
    str[i] = '\0';  // overwrite last space with terminating null '\0'
  //  for(int i = 0; i < (D->numItems); i++){
  //      return
  //  }
    return str;
}




