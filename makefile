CC = g++
CXXFLAGS = -std=c++11 -g

run: bst
	./bst.exe

debug: bst
	gdb bst.exe

memcheck: bst
	valgrind --leak-check=full ./bst.exe

bst: main node tree
	${CC} main.o node.o tree.o ${CXXFLAGS} -o bst.exe

main: main.cpp
	${CC} ${CXXFLAGS} -c main.cpp

tree: Tree.h Tree.cpp
	${CC} ${CXXFLAGS} -c Tree.cpp

node: Node.h Node.cpp
	${CC} ${CXXFLAGS} -c Node.cpp

clean:
	rm *.exe
	rm *.o