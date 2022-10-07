CC = g++
CXXFLAGS = -std=c++11 -g

run: bst
	./bst.exe

bst: main node
	${CC} main.o node.o ${CXXFLAGS} -o bst

main: main.cpp
	${CC} ${CXXFLAGS} -c main.cpp

node: node.cpp
	${CC} ${CXXFLAGS} -c Node.cpp

clean:
	rm *.exe
	rm *.o