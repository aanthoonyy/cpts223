prog: main.o
	g++ -g -fopenmp main.o -o ourProg

main.o: main.cpp ProbingHash.h ParallelProbingHash.h ChainingHash.h enum.hpp
	g++ -fopenmp -c -g -Wall -std=c++11  main.cpp 

clean: 
	-rm *.o

run:
	@./ourProg
