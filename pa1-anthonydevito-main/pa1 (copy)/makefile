# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o message.o factorial.o
	g++ main.o message.o factorial.o -o ourProg

main.o: main.cpp functions.h
	g++ -c main.cpp 

message.o: message.cpp functions.h
	g++ -c message.cpp 

factorial.o: factorial.cpp functions.h
	g++ -c factorial.cpp 

clean: 
	-rm *.o

run:
	@./ourProg