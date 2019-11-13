#------------------------------------------------------------------------------
# Makefile for any client of any ADT in C
#------------------------------------------------------------------------------

ASSIGNMENT     = pa3
CLIENT         = DictionaryTest
ADT            = Dictionary
SOURCE         = $(CLIENT).c
OBJECT         = $(CLIENT).o
ADT_SOURCE     = $(ADT).c
ADT_OBJECT     = $(ADT).o
ADT_HEADER     = $(ADT).h
COMPILE        = gcc -g -c -std=c99 -Wall
FILES          = Dictionary.h Dictionary.c DictionaryTest.c Makefile README
LINK           = gcc -o
REMOVE         = rm -f
MEMCHECK       = valgrind --leak-check=full
SUBMIT	       = submit cse015-pt.f19 $(ASSIGNMENT)


$(CLIENT) : $(OBJECT) $(ADT_OBJECT) 
	$(LINK) $(CLIENT) $(OBJECT) $(ADT_OBJECT) 

$(OBJECT) : $(SOURCE) $(ADT_HEADER) 
	$(COMPILE) $(SOURCE)

$(ADT_OBJECT) : $(ADT_SOURCE) $(ADT_HEADER)
	$(COMPILE) $(ADT_SOURCE)

submit :
	$(SUBMIT) $(FILES)

clean :
	$(REMOVE) $(CLIENT) $(OBJECT) $(ADT_OBJECT) 

memcheck : $(CLIENT)
	$(MEMCHECK) $(CLIENT)

send :
	git add Dictionary.c  Makefile
	git commit -m 'sending from local'
	git push
