vector_app: main.o vector3.o
	g++ -std=c++11 main.o vector3.o -o vector_app

main.o: main.cc
	g++ -std=c++11 -c main.cc -o main.o

vector3.o: vector3.cc vector3.h
	g++ -std=c++11 -c vector3.cc -o vector3.o

clean:
	rm -f *.o vector_app

