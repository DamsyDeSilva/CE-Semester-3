# CO222 - 2019 Assignment 1
# Include your binary named 'clc' into this directory and run 'make' command

# List of test input files
TESTS	:=	$(wildcard *.inp)

.SUFFIXES : .inp .out

test : $(TESTS:.inp=.out)

%.out : %.inp %.exp
	@`cat $<` >> $@ 2>&1 || printf ""
	@sdiff -Wib $(<:.inp=.exp) $@ || printf "ERROR: input $< failed \n"

.PHONY clean :
	-rm -f *.out *.o *.d core
-include $(SRCS:.c=.d)
