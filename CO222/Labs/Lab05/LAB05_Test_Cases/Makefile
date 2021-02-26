# Based on the following sources:
# http://babbage.cs.qc.edu/courses/cs701/Handouts/using_make.html
# http://www.cs.toronto.edu/~penny/teaching/csc444-05f/maketutorial.html

#List of test input files
TESTS	:=	$(wildcard *.inp)

#the name of your program
BINARY	:=	TicTacToe

.SUFFIXES : .inp .out
#.PHONY all : $(BINARY) 

test : $(TESTS:.inp=.out)

%.out : %.inp %.exp $(BINARY) 
	@./$(BINARY) < $< > $@ || printf "ERROR: cannot test with input $< \n"
	@sdiff -Wib $(<:.inp=.exp) $@ || printf "ERROR: input $< failed \n"

.PHONY clean :
	-rm -f *.out *.o *.d core $(BINARY)

-include $(SRCS:.c=.d)
