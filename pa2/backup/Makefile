#------------------------------------------------------------------------------
#  Makefile with macros, clean.
#------------------------------------------------------------------------------

ASSIGNMENT = pa2
EXEBIN     = Queens
SOURCES    = $(EXEBIN).c
OBJECTS    = $(EXEBIN).o
FLAGS      = -std=c99 -Wall
FILES      = $(SOURCES) Makefile README
SUBMIT	   = submit cse015-pt.f19 $(ASSIGNMENT)

$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)

$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)

clean :
	rm -f $(EXEBIN) $(OBJECTS)
submit :
	$(SUBMIT) $(FILES)
memcheck :
	valgrind --leak-check=full $(EXEBIN) 5
