//Shane Ciora
//CSE 15 Fall 2019
//ID: 1449570
//Lab 2

#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>


#define MAX_STRING_LENGTH 100

//Handles moving the charactrs into their corresponding allocated arrays
//s = input string
//a = alphabetic (abcd)
//d = digits (1234)
//p = punctuation (!@#$%^&)
//w = whitespace (   )
void extract_chars(char* s, char* a, char* d, char* p, char* w){
  int i = 0;
  int alpha_index = 0;
  int digit_index = 0;
  int punct_index = 0;
  int white_index = 0;

  //itterate thru the line
  while(s[i] != '\0'){
    //if character is alphabetic
    if(isalpha(s[i])){
      a[alpha_index++] = s[i];
    }
    //if character is a digit
    else if(isdigit(s[i])){
      d[digit_index++] = s[i];
    }
    //if character is punctuation
    else if(ispunct(s[i])){
      p[punct_index++] = s[i];
    }
    //if character is whitespace
    else if(isspace(s[i])){
      w[white_index++] = s[i];
    }

    //iterate to next part of the array
    i++;
  }

}


//Takes in 2 command line inputs
//		-infile, "in"
//		-outfile, "out"
//Creates the allocated arrays above (s,a,d,p,w) and initilizes them.
//Sends arrays to extract_chars(...)
int main(int argc, char* argv[]){
	FILE* in;		//in file
	FILE* out;		//out file
	char* line;
  char* a;
  char* d;
  char* p;
  char* w;

  int line_num = 1;

	// check command line for correct number of arguments 
 	if( argc != 3 ){
    	printf("Usage: %s input-file output-file\n", argv[0]);
    	exit(EXIT_FAILURE);
	}

	  // open input file for reading 
  if( (in=fopen(argv[1], "r"))==NULL ){
      printf("Unable to read from file %s\n", argv[1]);
      exit(EXIT_FAILURE);
  }

  // open output file for writing 
  if( (out=fopen(argv[2], "w"))==NULL ){
      printf("Unable to write to file %s\n", argv[2]);
      exit(EXIT_FAILURE);
  }


  //allocate memory for each string
  line = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
  assert(line!=NULL);

  // read each line in input file, extract alpha-numeric characters 
  while( fgets(line, MAX_STRING_LENGTH, in) != NULL ){
      a = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
      d = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
      p = calloc(MAX_STRING_LENGTH+1, sizeof(char) );
      w = calloc(MAX_STRING_LENGTH+1, sizeof(char) );

      assert(a!=NULL && d!=NULL && p!=NULL && w!=NULL);

      extract_chars(line, a, d, p, w);
      
      int count_alpha = 0;
      int count_digit = 0;
      int count_punct = 0;
      int count_space = 0;
      int i = 0;

      while(a[i] != '\0'){
        count_alpha++;
        i++;
      }

      i = 0;
      while(d[i] != '\0'){
        count_digit++;
        i++;
      }

      i = 0;
      while(p[i] != '\0'){
        count_punct++;
        i++;
      }

      i = 0;
      while(w[i] != '\0'){
        count_space++;
        i++;
      }

      fprintf(out, "line %d contains:\n", line_num);

      //print alphabetical chars to out
      if(count_alpha == 1){
        fprintf(out, "%d alphabetic character: ", count_alpha);
      }else{
        fprintf(out, "%d alphabetic characters: ", count_alpha);
      }
      
      i = 0;
      while(a[i] != '\0'){
        fprintf(out, "%c", a[i]);
        i++;
      }
      fprintf(out, "\n");

      //print digit chars to out
      if(count_digit == 1){
        fprintf(out, "%d numeric character: ", count_digit);
      }else{
        fprintf(out, "%d numeric characters: ", count_digit);
      }
      i = 0;
      while(d[i] != '\0'){
        fprintf(out, "%c", d[i]);
        i++;
      }
      fprintf(out, "\n");

      //print punct chars to out
      if(count_punct == 1){
        fprintf(out, "%d punctuation character: ", count_punct);
      }else{
        fprintf(out, "%d punctuation characters: ", count_punct);
      }
      i = 0;
      while(p[i] != '\0'){
        fprintf(out, "%c", p[i]);
        i++;
      }
      fprintf(out, "\n");

      //print whitespace chars to out
      if(count_space == 1){
        fprintf(out, "%d whitespace character: ", count_space);
      }else{
        fprintf(out, "%d whitespace characters: ", count_space);
      }
      i = 0;
      while(w[i] != '\0'){
        fprintf(out, "%c", w[i]);
        i++;
      }
      fprintf(out, "\n");

      line_num++;

    free(a);
    a = NULL;
    free(d);
    d = NULL;
    free(p);
    p = NULL;
    free(w);
    w = NULL;
  }

  //Free allocated memory
  free(line);



	return EXIT_SUCCESS;
}
