# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o testqueue.o queue.o
	g++ main.o testqueue.o queue.o -o ourProg

main.o: main.cpp 
	g++ -c main.cpp 

testqueue.o: testqueue.cpp testqueue.hpp
	g++ -c testqueue.cpp 

queue.o: queue.cpp queue.hpp
	g++ -c queue.cpp 

clean: 
	-rm *.o

run:
	@./ourProg