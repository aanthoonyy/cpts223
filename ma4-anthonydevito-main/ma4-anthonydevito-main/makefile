# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o BankData.o
	g++ main.o BankData.o -o ourProg

main.o: main.cpp 
	g++ -c main.cpp 

BankData.o: BankData.cpp BankData.hpp
	g++ -c BankData.cpp 

clean: 
	-rm *.o

run:
	@./ourProg