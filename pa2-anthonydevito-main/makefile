prog: main.o message.o factorial.o
	g++ -g main.o message.o factorial.o -o ourProg

main.o: main.cpp functions.h
	g++ -c -g -Wall -std=c++11  main.cpp 

message.o: message.cpp functions.h
	g++ -c -g -Wall -std=c++11 message.cpp 

factorial.o: factorial.cpp functions.h
	g++ -c -g -Wall -std=c++11 factorial.cpp 

TestVector.o: TestVectorJosephus.cpp VectorJosephus.hpp
	g++ -c -g -Wall -std=c++11 TestVectorJosephus.cpp 

TestList.o: TestListMyJosephus.cpp ListMyJoesph.hpp
	g++ -c -g -Wall -std=c++11 TestListMyJosephus.cpp 

clean: 
	-rm *.o

run:
	@./ourProg