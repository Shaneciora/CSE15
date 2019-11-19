#------------------------------------------------------------------------------
# Makefile for any C program
#------------------------------------------------------------------------------

ASSIGNMENT   = lab4
PROGRAM_NAME = ArithmeticOperations
FLAGS        = -std=c99 -Wall
SOURCE       = $(PROGRAM_NAME).c
OBJECT       = $(PROGRAM_NAME).o
EXEBIN       = $(PROGRAM_NAME)
SUBMIT	     = submit cse015-pt.f19 $(ASSIGNMENT)

$(EXEBIN) : $(OBJECT)
	gcc -o $(EXEBIN) $(OBJECT)

$(OBJECT) : $(SOURCE)
	gcc -c $(FLAGS) $(SOURCE)

clean :
	rm $(EXEBIN) $(OBJECT)

memcheck : $(EXEBIN)
	valgrind --leak-check=full $(EXEBIN) in1

submit :
	$(SUBMIT) ArithmeticOperations.c README Makefile
