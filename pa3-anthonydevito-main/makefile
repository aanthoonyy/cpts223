prog: main.o
	g++ -g main.o -o ourProg

main.o: main.cpp
	g++ -c -g -Wall -std=c++11  main.cpp 

clean: 
	-rm *.o

run:
	@./ourProg