CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJS = main.o ./data/stream.o ./data/stream-operator.o ./data/stream-operand.o ./data/term.o

cffinder : ${OBJS}
	${CXX} $(CXXFLAGS) -o $@ ${OBJS}
	./cffinder

clean :
	rm ${OBJS} cffinder
