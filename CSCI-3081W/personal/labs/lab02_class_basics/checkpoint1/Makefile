DEPENDENCY_DIR = /project/grades/Fall-2021/csci3081/dependencies
INCLUDE_DIRS = -I$(DEPENDENCY_DIR)/include
LIB_DIRS = -L$(DEPENDENCY_DIR)/lib
LIBS = -lCppWebServer -lwebsockets -lssl -lcrypto -lz

drone_app: main.o vector3.o drone.o drone_app.o
	g++ -std=c++11 $(LIB_DIRS) main.o vector3.o drone.o drone_app.o $(LIBS) -o drone_app

main.o: main.cc
	g++ -std=c++11 $(INCLUDE_DIRS) -c main.cc -o main.o

vector3.o: vector3.cc vector3.h
	g++ -std=c++11 -c vector3.cc -o vector3.o

drone.o: drone.cc drone.h
	g++ -std=c++11 -c drone.cc -o drone.o

drone_app.o: drone_app.cc drone_app.h
	g++ -std=c++11 $(INCLUDE_DIRS) -c drone_app.cc -o drone_app.o

clean:
	rm -f *.o drone_app

