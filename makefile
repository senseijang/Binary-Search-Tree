CC = g++
CXXFLAGS = -std=c++11 -g

run: bst
	./bst.exe

debug: bst
	gdb bst.exe

memcheck: bst
	valgrind --leak-check=full ./bst.exe

bst: main node
	${CC} main.o node.o ${CXXFLAGS} -o bst.exe

main: main.cpp
	${CC} ${CXXFLAGS} -c main.cpp

node: Node.h Node.cpp
	${CC} ${CXXFLAGS} -c Node.cpp

clean:
	rm *.exe
	rm *.o