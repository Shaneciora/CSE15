//
//  DictionaryTest.c
//  Testing Dictionary ADT
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"Dictionary.h"

int main(){
    
    //--Constructor/Destructor Testing--
    Dictionary A = newDictionary();
    //deleteall(A);
    //freeDictionary(A);
    
    //--ADT Operations Testing--
    
    //add elements
    insert(A, "first_key", "first_value");
    insert(A, "second_key", "second_value");
    //insert(A, "second_key", "third_value");  //<--should break the program
    
//    printf("Size: %d\n", size(A));

//    printf("%s\n",lookup(A, "first_key"));

//    delete(A, "first_key");
//    printf("Size: %d\n", size(A));
//    printf("%s\n",lookup(A, "first_key"));

    insert(A, "test1", "test1");
    insert(A, "test2", "test2");
    insert(A, "test3", "test3");
//    printf("%s\n", DictionaryToString(A));
//    printf("Size: %d\n", size(A));

    delete(A, "test2");
    printf("%s\n", DictionaryToString(A));
    printf("Size: %d\n", size(A));
//
//    makeEmpty(A);
//    printf("%s\n", DictionaryToString(A));
//    printf("Size: %d\n", size(A));
    
    freeDictionary(&A);
    //printf("%s\n", DictionaryToString(A));
    //printf("Size: %d\n", size(A));
    
    return 0;
}
